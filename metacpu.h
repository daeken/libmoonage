#pragma once

#include <cstdint>
#include "common.h"
#include "state.h"
#include "interface.h"
#include "interpreter.h"
#include "recompiler.h"

enum MetaMode {
    Interpreting,
    Recompiling,
    Optimizing
};

class EXPORTED MetaCpu {
public:
    MetaCpu(CpuInterface* interface, MetaMode mode = MetaMode::Optimizing, int optimizationThreshold = 500);
    void run(uint64_t pc, uint64_t sp);
    CpuInterface* interface;
    CpuState* state;
    Interpreter* interpreter;
    MetaMode mode;
    int optimizationThreshold;
};
