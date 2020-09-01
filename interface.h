#pragma once

#include <cstdint>

#define EXPORTED __attribute__ ((visibility ("default")))

struct CpuState;

enum CodeSource {
    Execution,
    Speculation,
    LlvmOptimizer,
    LightOptimizer,
    END
};

const int CodeSourceCount = (int) CodeSource::END;

// NOTE: All methods could be accessed from any thread, as there's one CPU per thread.
// Ensure that your methods are concurrency-safe
class CpuInterface {
public:
    // This will get hit before each instruction fetch; keep it lightweight
    // When fetching a new block, state will be valid; otherwise, nullptr
    virtual bool isValidCodePointer(CodeSource codeSource, uint64_t addr, CpuState* state) = 0;

    // Called when a svc occurs. Returning false will halt emulation, true will continue
    virtual bool Svc(uint32_t svc, CpuState* state) = 0;

    // Called to read or write system registers, respectively
    virtual uint64_t SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2) = 0;
    virtual void SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2, uint64_t value) = 0;

    virtual void Log(const std::string& message) = 0;
    virtual void Error(const std::string& message) = 0;
};
