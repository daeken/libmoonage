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
    memset(&state, 0, sizeof(CpuState));
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
    assert(globalInterface != nullptr);
    state.SP = sp;
    while(true) {
        auto block = Cache.GetBlock(pc);
        if(block->func == nullptr) {
            if(!globalInterface->isValidCodePointer(pc, &state))
                return;
            block->mutex.lock();
            if(block->func == nullptr)
                recompileMultiple(block);
            block->mutex.unlock();
        }
        assert(block->func != nullptr);

        state.BranchTo = -1UL;
        cout << "Running block at " << hex << pc << endl;
        block->func(&state);
        state.PC = pc = state.BranchTo;
        assert((pc & 3) == 0);
    }
}

#include <sys/mman.h>

void Recompiler::recompileMultiple(Block *block) {
    initialize();

    auto name = (boost::format("_%1$#x") % block->addr).str();
    module = std::make_unique<llvm::Module>("moonage", Builder.getContext());
    function = llvm::Function::Create((llvm::FunctionType*) LlvmType<std::function<void(ulong)>>(), llvm::Function::ExternalLinkage, name, module.get());
    CpuStateRef = RuntimeValue<ulong>(function->arg_begin());

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
    pm.doInitialization();

    usedLabels.clear();
    blockLabels.clear();

    Builder.SetInsertPoint(llvm::BasicBlock::Create(Builder.getContext(), "", function));

    memset(registersUsed, 0, sizeof(registersUsed));
    for(auto & registerLocal : registerLocals)
        registerLocal = new Local<ulong>();

    auto preRegisterLoad = DefineLabel(), postRegisterLoad = DefineLabel(), retLabel = DefineLabel();
    Branch(preRegisterLoad);
    Label(postRegisterLoad);

    auto preRegisterStore = DefineLabel();
    preStoreRegistersLabel = &preRegisterStore;

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
            if(!globalInterface->isValidCodePointer(pc, nullptr)) {
                BranchToR = pc;
                Branch(preRegisterStore);
                break;
            }

            cout << "Recompiling instruction at 0x" << hex << pc << endl;
            PCR = pc;
            if(!recompile(*(uint*) pc, pc)) {
                cout << "Instruction at 0x" << hex << pc << " failed to recompile" << endl;
                assert(false);
            }
            pc += 4;
        }
    }

    Label(preRegisterLoad);
    for(auto i = 0; i < 31; ++i)
        if(registersUsed[i])
            registerLocals[i]->value = Field<ulong>(offsetof(CpuState, X0) + 8 * i);
    Branch(postRegisterLoad);

    Label(preRegisterStore);
    for(auto i = 0; i < 31; ++i)
        if(registersUsed[i])
            Field<ulong>(offsetof(CpuState, X0) + 8 * i, registerLocals[i]->value);
    Builder.CreateRetVoid();

    //function->dump();
    llvm::verifyFunction(*function, &llvm::outs());
    assert(!llvm::verifyFunction(*function));
    pm.run(*function);
    //function->dump();
    llvm::verifyFunction(*function, &llvm::outs());
    assert(!llvm::verifyFunction(*function));

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

    for(auto & registerLocal : registerLocals)
        delete registerLocal;
}

ulong SR(uint op0, uint op1, uint crn, uint crm, uint op2) {
    assert(false);
}

void SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value) {
    assert(false);
}

void Svc(uint svc) {
    assert(false);
}
