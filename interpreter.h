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
    bool bailOut = false;
    CpuState* state;
    Property<ulong> NZCV{
        [=]() { return (state->NZCV_N << 31) | (state->NZCV_Z << 30) | (state->NZCV_C << 29) | (state->NZCV_V << 28); },
        [=](auto value) {
            state->NZCV_N = (value >> 31) & 1;
            state->NZCV_Z = (value >> 30) & 1;
            state->NZCV_C = (value >> 29) & 1;
            state->NZCV_V = (value >> 28) & 1;
        }
    };
};
