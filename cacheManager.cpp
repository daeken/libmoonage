#include "cacheManager.h"

CacheManager Cache;

Block* CacheManager::GetBlock(ulong addr) {
    mutex.lock();
    auto block = blocks.count(addr) == 0 ? (blocks[addr] = new Block(addr)) : blocks[addr];
    mutex.unlock();
    return block;
}
