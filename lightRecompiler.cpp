#include "lightRecompiler.h"
#include <set>
using std::set;

thread_local int LightLocalOffset;
thread_local LightRecompiler LightRecompilerInstance;
thread_local LightCode* LC;

LightRecompiler::LightRecompiler() {
}

void LightRecompiler::runOne(Block* block) {
    block->func((CpuState*) &state);
    state.PC = state.BranchTo;
}

void LightRecompiler::recompileMultiple(Block* block) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);
    LC = new LightCode();

    prologue = DefineLabel();
    epilogue = DefineLabel();

    LC->setDefaultJmpNEAR(true);
    LC->jmp(prologue->label); // TODO: Just get the address here
    LC->L(epilogue->label);
    LC->mov(rsp, rbp);
    LC->pop(rbx);
    LC->pop(rbp);
    LC->ret();

    Xbyak::Label start;
    LC->L(start);

    blocksNeeded.push({BlockContext(), block->addr});
    blockLabels.clear();
    LightLocalOffset = 0;

    set<ulong> recompiled;
    while(!blocksNeeded.empty()) {
        auto [context, pc] = blocksNeeded.front();
        blocksNeeded.pop();
        if(recompiled.count(pc))
            continue;

        branched = false;
        this->context = context;

        while(!branched) {
            currentPC = pc;
            auto label = blockLabels.count(pc) ? blockLabels[pc] : blockLabels[pc] = DefineLabel();
            if(recompiled.count(pc)) {
                Branch(label);
                break;
            }
            recompiled.insert(pc);
            Label(label);
            if(!interface->isValidCodePointer(isOptimizer ? CodeSource::LightOptimizer : CodeSource::Execution, pc, nullptr)) {
                BranchToR = pc;
                Branch(epilogue);
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

    LC->L(prologue->label);
    LC->push(rbp);
    LC->push(rbx);
    LC->mov(rbp, rsp);
    LC->mov(rbx, rdi); // RBX is CpuState*
    while(LightLocalOffset % 16) LightLocalOffset++;
    LC->sub(rsp, LightLocalOffset + 16);
    LC->jmp(start);

    LC->ready();
    block->func = LC->getCode<BlockFunc>();
    gettimeofday(&etv, NULL);
    auto sms = 1000000UL * stv.tv_sec + stv.tv_usec;
    auto ems = 1000000UL * etv.tv_sec + etv.tv_usec;
    interface->Log((boost::format("Recompiled (lightly) block at %1$#x --- %2$#x -- %3% usec") % block->addr % (uint64_t) block->func % (ems - sms)).str());
}
