#include "interpreter.h"
#include <iostream>
#include <ios>
#include "interface.h"
using namespace std;

Interpreter::Interpreter() {
    assert(globalInterface != nullptr);
    state = new CpuState;
    memset(state, 0, sizeof(CpuState));
}

void Interpreter::run(ulong pc, ulong sp) {
    state->PC = pc;
    state->SP = sp;
    bailOut = false;
    while(!bailOut) {
        if(!globalInterface->isValidCodePointer(state->PC, state))
            break;
        runOne();
    }
}

void Interpreter::runOne() {
    /*cout << "-----" << endl;
    for(auto i = 0; i < 32; ++i) {
        cout << "X" << dec << i << "=" << hex << state->X[i] << "  ";
        if((i & 1) == 1) cout << endl;
    }
    cout << "PC=" << hex << state->PC << "  " << "SP=" << state->SP << endl;
    cout << "-----" << dec << endl;*/
    auto inst = *(uint*) state->PC;
    auto _asm = disassemble(inst, state->PC);
    if(_asm == "") {
        cout << "Disassembly failed at " << hex << state->PC << " --- " << inst << endl;
        exit(1);
    }
    //cout << "Running instruction for 0x" << hex << state->PC << " (" << inst << ") - " << _asm << endl;
    state->BranchTo = (ulong) -3L;
    if(!interpret(inst, state->PC))
        throw "Interpretation failed";
    if(state->BranchTo != (ulong) -3L) {
        state->PC = state->BranchTo;
        state->BranchTo = (ulong) -3L;
    } else
        state->PC += 4;
}

void Interpreter::Branch(ulong addr) {
    state->BranchTo = addr;
}
void Interpreter::BranchRegister(int reg) {
    state->BranchTo = state->X[reg];
}
void Interpreter::BranchLinked(ulong addr) {
    state->X30 = state->PC + 4;
    state->BranchTo = addr;
}
void Interpreter::BranchLinkedRegister(int reg) {
    state->X30 = state->PC + 4;
    state->BranchTo = state->X[reg];
}

void Interpreter::Svc(uint svc) {
    bailOut = globalInterface->Svc(svc, state);
}

ulong Interpreter::SR(uint op0, uint op1, uint crn, uint crm, uint op2) {
    return globalInterface->SR(op0, op1, crn, crm, op2);
}
void Interpreter::SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value) {
    globalInterface->SR(op0, op1, crn, crm, op2, value);
}
