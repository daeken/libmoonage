#include "metacpu.h"
#include "interface.h"
#include <thread>
using namespace std;

bool runningOptimizer = false;

#pragma clang diagnostic ignored "-Wmissing-noreturn"
void optimizer(CpuInterface* interface, int threshold) {
    RecompilerInstance.interface = interface;
    RecompilerInstance.isOptimizer = true;
    auto resetCounters = false;
    while(true) {
        Block* candidate = nullptr;
        int bestHit = 0;
        Cache.mutex.lock();
        if(resetCounters) {
            resetCounters = false;
            for(auto &[_, block] : Cache.blocks)
                block->hitCount.store(0);
        } else
            for(auto [_, block] : Cache.blocks) {
                if(block->func != nullptr) continue;
                auto hc = block->hitCount.load();
                if(hc >= threshold && hc > bestHit) {
                    candidate = block;
                    bestHit = hc;
                }
            }
        Cache.mutex.unlock();
        if(bestHit == 0) {
            usleep(10000);
            continue;
        }

        cout << "Optimizing block at 0x" << hex << candidate->addr << " with " << dec << bestHit << " hits" << endl;
        candidate->mutex.lock();
        RecompilerInstance.recompileMultiple(candidate);
        candidate->mutex.unlock();
        cout << "Optimized" << endl;
        resetCounters = true;
    }
}

MetaCpu::MetaCpu(CpuInterface* interface, MetaMode mode, int optimizationThreshold) : interface(interface), mode(mode), optimizationThreshold(optimizationThreshold) {
    if(mode == MetaMode::Optimizing && !runningOptimizer) {
        runningOptimizer = true;
        thread ot(optimizer, interface, optimizationThreshold);
        ot.detach();
    }
    switch(mode) {
        case MetaMode::Interpreting:
            interpreter = new Interpreter(interface);
            state = interpreter->state;
            break;
        case MetaMode::Recompiling:
            RecompilerInstance.interface = interface;
            state = (CpuState*) &RecompilerInstance.state;
            break;
        case MetaMode::Optimizing:
            state = (CpuState*) &RecompilerInstance.state;
            RecompilerInstance.interface = interface;
            interpreter = new Interpreter(interface, state);
            break;
    }
}

void MetaCpu::run(uint64_t pc, uint64_t sp) {
    state->PC = pc;
    state->SP = sp;
    while(true) {
        if(!interface->isValidCodePointer(false, state->PC, (CpuState*) &state))
            break;
        auto block = Cache.GetBlock(state->PC);
        switch(mode) {
            case MetaMode::Interpreting:
                interpreter->runBlock(state->PC);
                break;
            case MetaMode::Recompiling:
                if(block->func == nullptr) {
                    block->mutex.lock();
                    RecompilerInstance.recompileMultiple(block);
                    block->mutex.unlock();
                }
                RecompilerInstance.runOne(block);
                break;
            case MetaMode::Optimizing:
                if(block->func != nullptr)
                    RecompilerInstance.runOne(block);
                else {
                    block->hitCount++;
                    interpreter->runBlock(state->PC);
                }
                break;
        }
    }
}
