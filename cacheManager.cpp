#include "cacheManager.h"

CacheManager Cache;

// This will leak a metric shittonne of memory
// ONLY use this for testing purposes
void CacheManager::Clear() {
    blocks.clear();
}

Block* CacheManager::GetBlock(ulong addr) {
    mutex.lock();
    auto block = blocks.count(addr) == 0 ? (blocks[addr] = new Block(addr)) : blocks[addr];
    mutex.unlock();
    return block;
}
