#include "recompiler.h"
#include "interface.h"

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Utils.h>
#include <llvm/Transforms/Vectorize.h>

#include <set>
#include <iostream>
#include <ios>
using namespace std;

thread_local llvm::LLVMContext Context;
thread_local llvm::IRBuilder<> Builder(Context);
thread_local Recompiler RecompilerInstance;
long _LabelTag::inc;

Recompiler::Recompiler() {
    memset((void*) &state, 0, sizeof(CpuState));
    noLocalBranches = false;
    //noLocalBranches = true;
}

bool initialized = false;
void initialize() {
    if(initialized) return;
    initialized = true;
    LLVMLinkInMCJIT();
    LLVMInitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    auto target = llvm::EngineBuilder().selectTarget();
    assert(target != nullptr);

}

llvm::Module* getModule() { return RecompilerInstance.module.get(); }
void emitted() { RecompilerInstance.justBranched = false; }

void Recompiler::run(ulong pc, ulong sp) {
    assert(interface != nullptr);
    state.SP = sp;
    while(true) {
        auto block = Cache.GetBlock(pc);
        if(block->func == nullptr) {
            if(!interface->isValidCodePointer(isOptimizer ? CodeSource::LlvmOptimizer : CodeSource::Execution, pc, (CpuState*) &state))
                return;
            block->mutex.lock();
            if(block->func == nullptr)
                recompileMultiple(block);
            block->mutex.unlock();
        }
        assert(block->func != nullptr);

        state.BranchTo = -1UL;
        //cout << "Running block for " << hex << pc << endl;
        block->func((CpuState*) &state);
        //cout << "Finished block at " << hex << state.PC << endl;
        state.PC = pc = state.BranchTo;
        //assert(pc != -1UL);
        if((pc & 3) != 0) {
            cout << "Next block is supposed to be at unaligned " << hex << pc << endl;
            break;
        }
    }
}

void Recompiler::runOne(Block* block) {
    //assert(block->func != nullptr);
    //cout << "Running block for " << hex << pc << endl;
    block->func((CpuState*) &state);
    //cout << "Finished block at " << hex << state.PC << endl;
    state.PC = state.BranchTo;
}

void Recompiler::runOne() {
    auto pc = state.PC;
    auto block = Cache.GetBlock(pc);
    if(block->func == nullptr) {
        if(!interface->isValidCodePointer(isOptimizer ? CodeSource::LlvmOptimizer : CodeSource::Execution, pc, (CpuState*) &state))
            return;
        block->mutex.lock();
        if(block->func == nullptr)
            recompileMultiple(block);
        block->mutex.unlock();
    }
    assert(block->func != nullptr);

    state.BranchTo = -1UL;
    block->func((CpuState*) &state);
    state.PC = state.BranchTo;
}

void Recompiler::precompile(ulong pc) {
    assert(interface != nullptr);
    auto block = Cache.GetBlock(pc);
    if(block->func == nullptr) {
        if(!interface->isValidCodePointer(isOptimizer ? CodeSource::LlvmOptimizer : CodeSource::Execution, pc, (CpuState*) &state))
            return;
        block->mutex.lock();
        if(block->func == nullptr)
            recompileMultiple(block);
        block->mutex.unlock();
    }
    assert(block->func != nullptr);
}

void Recompiler::recompileMultiple(Block *block) {
    initialize();

    //cout << "Recompiling block at " << hex << block->addr << endl;

    auto name = (boost::format("_%1$#x") % block->addr).str();
    module = std::make_unique<llvm::Module>("moonage", Builder.getContext());
    function = llvm::Function::Create((llvm::FunctionType*) LlvmType<std::function<void(ulong)>>(), llvm::Function::ExternalLinkage, name, module.get());
    auto farg = function->arg_begin();
    CpuStateRef = LlvmRuntimeValue<ulong>([farg]() { return farg; });

    llvm::legacy::FunctionPassManager pm{module.get()};
    pm.add(llvm::createInstructionCombiningPass(true));
    pm.add(llvm::createReassociatePass());
    pm.add(llvm::createCFGSimplificationPass());
    pm.add(llvm::createNewGVNPass());
    pm.add(llvm::createPromoteMemoryToRegisterPass());
    //pm.add(llvm::createLoopVectorizePass());
    pm.add(llvm::createDeadStoreEliminationPass());
    pm.add(llvm::createDeadInstEliminationPass());
    pm.add(llvm::createAggressiveDCEPass());
    pm.add(llvm::createPartiallyInlineLibCallsPass());
    pm.add(llvm::createInstructionCombiningPass(true));
    pm.doInitialization();

    usedLabels.clear();
    blockLabels.clear();
    loadRegistersLabels.clear();
    storeRegistersLabels.clear();

    Builder.SetInsertPoint(llvm::BasicBlock::Create(Builder.getContext(), "", function));

#define LDEF(name) do { stateLocals[offsetof(CpuState, name)] = (void*) new Local<decltype(CpuState::name)>(); } while(0)
    STATE_MEMBER_DEFS(LDEF);
#undef LDEF

    auto preRegisterLoad = DefineLabel(), postRegisterLoad = DefineLabel(), retLabel = DefineLabel();
    Branch(preRegisterLoad);
    Label(postRegisterLoad);

    storeRegistersLabels.emplace_back(DefineLabel(), retLabel);
    loadRegistersLabels.emplace_back(preRegisterLoad, postRegisterLoad);

    blocksNeeded.push({BlockContext(), block->addr});

    set<ulong> recompiled;
    auto topFirst = true;
    while(!blocksNeeded.empty()) {
        auto [context, pc] = blocksNeeded.front();
        blocksNeeded.pop();
        if(recompiled.count(pc))
            continue;

        auto first = true;
        branched = false;
        this->context = context;

        while(!branched) {
            currentPC = pc;
            auto label = blockLabels.count(pc) ? blockLabels[pc] : blockLabels[pc] = DefineLabel();
            if(!first || topFirst)
                Branch(label);
            first = topFirst = false;
            if(recompiled.count(pc)) break;
            recompiled.insert(pc);
            Label(label);
            if(!interface->isValidCodePointer(isOptimizer ? CodeSource::LlvmOptimizer : CodeSource::Execution, pc, nullptr)) {
                BranchToR = pc;
                Branch(std::get<0>(storeRegistersLabels[0]));
                break;
            }

            //cout << "Recompiling instruction at 0x" << hex << pc << " with contents 0x" << hex << *((uint*) pc) << endl;
            //cout << "Disassembly: " << disassemble(*(uint*) pc, pc) << endl;
            PCR = pc;
            if(!recompile(*(uint*) pc, pc)) {
                if(noLocalBranches)
                    throw "Recompilation failed";
                else
                    interface->Error((boost::format("Recompilation failed at %1$#x --- %2$#x") % pc % *((uint*) pc)).str());
            }
            pc += 4;
        }
    }

    for(auto& [pre, post] : loadRegistersLabels) {
        Label(pre);
#define LOAD(name) do { auto __temp = (Local<decltype(CpuState::name)>*) stateLocals[offsetof(CpuState, name)]; if(__temp->used) __temp->value = Field<decltype(CpuState::name)>(offsetof(CpuState, name)); } while(0)
        STATE_MEMBER_DEFS(LOAD);
#undef LOAD
        Branch(post);
    }

    for(auto& [pre, post] : storeRegistersLabels) {
        Label(pre);
#define STORE(name) do { auto __temp = (Local<decltype(CpuState::name)>*) stateLocals[offsetof(CpuState, name)]; if(__temp->used) Field<decltype(CpuState::name)>(offsetof(CpuState, name), __temp->value); } while(0)
        STATE_MEMBER_DEFS(STORE);
#undef STORE
        Branch(post);
    }

    Label(retLabel);
    Builder.CreateRetVoid();

    //function->dump();
    llvm::verifyFunction(*function, &llvm::outs());
    assert(!llvm::verifyFunction(*function));
    /*pm.run(*function);
    //function->dump();
    llvm::verifyFunction(*function, &llvm::outs());
    assert(!llvm::verifyFunction(*function));*/

    string error;
    llvm::EngineBuilder eb(std::move(module));
    eb.setEngineKind(llvm::EngineKind::JIT);
    eb.setErrorStr(&error);
    auto ee = eb.create();
    if(ee == nullptr)
        cout << error << endl;
    assert(ee != nullptr);
    auto fptr = (void*) ee->getFunctionAddress(name);
    assert(fptr != nullptr);
    block->func = (BlockFunc) fptr;

#define UNDEF(name) do { delete (Local<decltype(CpuState::name)>*) stateLocals[offsetof(CpuState, name)]; } while(0)
    STATE_MEMBER_DEFS(UNDEF);
#undef STORE
}

int Svc(ulong recompilerPtr, uint svc, ulong state) {
    auto recompiler = (Recompiler*) recompilerPtr;
    return recompiler->interface->Svc(svc, (CpuState*) state);
}

ulong SR(ulong recompilerPtr, uint op0, uint op1, uint crn, uint crm, uint op2) {
    auto recompiler = (Recompiler*) recompilerPtr;
    return recompiler->interface->SR(op0, op1, crn, crm, op2);
}

void SR(ulong recompilerPtr, uint op0, uint op1, uint crn, uint crm, uint op2, ulong value) {
    auto recompiler = (Recompiler*) recompilerPtr;
    recompiler->interface->SR(op0, op1, crn, crm, op2, value);
}
