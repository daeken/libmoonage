#pragma once

#include <cstdint>
#include "common.h"
#include "state.h"
#include "interface.h"
#include "interpreter.h"
#include "recompiler.h"
#include "lightRecompiler.h"

enum MetaMode {
    Undefined,
    Interpreting,
    LightRecompiling,
    LlvmRecompiling
};

class EXPORTED MetaCpu {
public:
    MetaCpu(CpuInterface* interface);
    void setBaseline(MetaMode mode);
    void enableOptimizer(MetaMode mode, int threshold);
    void initialize();
    void run(uint64_t pc, uint64_t sp);
    CpuInterface* interface;
    CpuState* state;
    Interpreter* interpreter;
    bool initialized;
    MetaMode baseline;
    int llvmOptimizerThreshold, lightOptimizerThreshold;
};
