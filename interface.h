#pragma once

#include <cstdint>

struct CpuState;

// NOTE: All methods could be accessed from any thread, as there's one CPU per thread.
// Ensure that your methods are concurrency-safe
class CpuInterface {
public:
    // This will get hit before each instruction fetch; keep it lightweight
    // When fetching a new block, state will be valid; otherwise, nullptr
    virtual bool isValidCodePointer(uint64_t addr, CpuState* state) = 0;
};

extern CpuInterface* globalInterface;
void registerCpuInterface(CpuInterface* interface);
