#pragma once

#include <cstdint>
#include "common.h"
#include "state.h"
#include "interface.h"

inline void StoreVector(ulong addr, Vector128<float> vec) {
    if(addr & 0xF)
        memcpy((void*) addr, &vec, 16);
    else
        *(Vector128<float>*) addr = vec;
}

class EXPORTED Interpreter {
public:
    Interpreter(CpuInterface* interface, CpuState* state = nullptr);
    void run(ulong pc, ulong sp);
    void runBlock(ulong pc);
    void runOne();
    bool interpret(uint inst, ulong pc);
    void Branch(ulong addr);
    void BranchRegister(int reg);
    void BranchLinked(ulong addr);
    void BranchLinkedRegister(int reg);
    void Svc(uint svc);
    ulong SR(uint op0, uint op1, uint crn, uint crm, uint op2);
    void SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value);

    template<typename T>
    inline T ReadMemory(uint64_t addr) {
        if constexpr(sizeof(T) == 16) {
            T value;
            if(addr & 0xF)
                memcpy(&value, (void*) addr, 16);
            else
                value = *(T*) addr;
            interface->Log((boost::format("@%1$#x Read %2% bytes from %3$#x") % state->PC % sizeof(T) % addr).str());
            return value;
        } else {
            auto value = *(T*) addr;
            interface->Log((boost::format("@%1$#x Read %2% bytes from %3$#x -- %4$#x") % state->PC % sizeof(T) % addr % (uint64_t) value).str());
            return value;
        }
    }

    template<typename T>
    inline void WriteMemory(uint64_t addr, const T value) {
        if constexpr(sizeof(T) == 16) {
            interface->Log((boost::format("@%1$#x Writing %2% bytes to %3$#x") % state->PC % sizeof(T) % addr).str());
            if(addr & 0xF)
                memcpy((void*) addr, &value, 16);
            else
                *(T*) addr = value;
        } else {
            interface->Log((boost::format("@%1$#x Writing %2% bytes to %3$#x --- %4$#x") % state->PC % sizeof(T) % addr % (uint64_t) value).str());
            *(T*) addr = value;
        }
    }

    bool bailOut = false;
    bool logInstructions = false;
    CpuInterface* interface;
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
