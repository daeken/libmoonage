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
    ulong NZCV;
};
