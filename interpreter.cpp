#include "interpreter.h"
#include <iostream>
#include <ios>
#include "interface.h"
using namespace std;

Interpreter::Interpreter() {
    assert(globalInterface != nullptr);
    State = new CpuState;
    memset(State, 0, sizeof(CpuState));
}

void Interpreter::run(ulong pc, ulong sp) {
    State->PC = pc;
    State->SP = sp;
    while(true) {
        if(!globalInterface->isValidCodePointer(State->PC, State))
            break;
        runOne();
    }
}

void Interpreter::runOne() {
    auto inst = *(uint*) State->PC;
    auto _asm = disassemble(inst, State->PC);
    if(_asm == nullptr) {
        cout << "Disassembly failed at " << hex << State->PC << " --- " << inst << endl;
        exit(1);
    }
    State->BranchTo = (ulong) -1L;
    interpret(inst, State->PC);
    if(State->BranchTo != (ulong) -1L) {
        State->PC = State->BranchTo;
        State->BranchTo = (ulong) -1L;
    } else
        State->PC += 4;
}

void Interpreter::Branch(ulong addr) {
    State->BranchTo = addr;
}
void Interpreter::BranchRegister(int reg) {
    State->BranchTo = State->X[reg];
}
void Interpreter::BranchLinked(ulong addr) {
    State->X30 = State->PC + 4;
    State->BranchTo = addr;
}
void Interpreter::BranchLinkedRegister(int reg) {
    State->X30 = State->PC + 4;
    State->BranchTo = State->X[reg];
}

void Interpreter::Svc(uint svc) {
}

ulong Interpreter::SR(uint op0, uint op1, uint crn, uint crm, uint op2) {
    return 0;
}
void Interpreter::SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value) {
}
