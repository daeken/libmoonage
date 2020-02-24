#pragma once

#include <mutex>
#include <unordered_map>
#include "common.h"
#include "state.h"

using std::mutex;
using std::unordered_map;

using BlockFunc = void(*)(CpuState*);

class Block {
public:
    const ulong addr;
    mutex mutex;
    BlockFunc func;
    inline Block(ulong addr) : addr(addr), func(nullptr) { }
};

class CacheManager {
public:
    unordered_map<ulong, Block*> blocks;
    mutex mutex;

    void Clear();
    Block* GetBlock(ulong addr);
};

extern CacheManager Cache;
