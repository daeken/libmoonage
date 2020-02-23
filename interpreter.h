#pragma once

#include <cstdint>
#include "common.h"
#include "state.h"

class Interpreter {
public:
    Interpreter();
    void run(ulong pc, ulong sp);
    void runOne();
    bool interpret(uint inst, ulong pc);
    void Branch(ulong addr);
    void BranchRegister(int reg);
    void BranchLinked(ulong addr);
    void BranchLinkedRegister(int reg);
    void Svc(uint svc);
    ulong SR(uint op0, uint op1, uint crn, uint crm, uint op2);
    void SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value);
    CpuState* State;
    Property<ulong> NZCV{
        [=]() { return (State->NZCV_N << 31) | (State->NZCV_Z << 30) | (State->NZCV_C << 29) | (State->NZCV_V << 28); },
        [=](auto value) {
            State->NZCV_N = (value >> 31) & 1;
            State->NZCV_Z = (value >> 30) & 1;
            State->NZCV_C = (value >> 29) & 1;
            State->NZCV_V = (value >> 28) & 1;
        }
    };
};
