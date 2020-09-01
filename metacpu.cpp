#include "metacpu.h"
#include "interface.h"
#include <thread>
using namespace std;

bool runningLightOptimizer = false;
bool runningLlvmOptimizer = false;

[[noreturn]] void llvmOptimizer(CpuInterface* interface, int threshold, int lightThreshold) {
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
                if(block->hitCount.load() > lightThreshold)
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

        cout << "Llvm optimizing block at 0x" << hex << candidate->addr << " with " << dec << bestHit << " hits" << endl;
        candidate->mutex.lock();
        RecompilerInstance.recompileMultiple(candidate);
        candidate->mutex.unlock();
        cout << "Llvm optimized" << endl;
        //resetCounters = true;
    }
}

[[noreturn]] void lightOptimizer(CpuInterface* interface, int threshold) {
    LightRecompilerInstance.interface = interface;
    LightRecompilerInstance.isOptimizer = true;
    while(true) {
        Block* candidate = nullptr;
        int bestHit = 0;
        Cache.mutex.lock();
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

        cout << "Light optimizing block at 0x" << hex << candidate->addr << " with " << dec << bestHit << " hits" << endl;
        candidate->mutex.lock();
        LightRecompilerInstance.recompileMultiple(candidate);
        candidate->mutex.unlock();
        cout << "Light optimized" << endl;
    }
}

MetaCpu::MetaCpu(CpuInterface* interface) : interface(interface), initialized(false), baseline(MetaMode::Undefined), lightOptimizerThreshold(-1), llvmOptimizerThreshold(-1) {
}

void MetaCpu::setBaseline(MetaMode mode) {
    baseline = mode;
}

void MetaCpu::enableOptimizer(MetaMode mode, int threshold) {
    switch(mode) {
        case MetaMode::LightRecompiling:
            lightOptimizerThreshold = threshold;
            break;
        case MetaMode::LlvmRecompiling:
            llvmOptimizerThreshold = threshold;
            break;
        default:
            interface->Error("Unsupported optimizer mode");
            break;
    }
}

void MetaCpu::initialize() {
    if(!initialized) {
        initialized = true;
        switch(baseline) {
            case MetaMode::Undefined:
                throw "Undefined mode for baseline metacpu";
            case MetaMode::Interpreting:
                interpreter = new Interpreter(interface);
                state = interpreter->state;
                break;
            case MetaMode::LightRecompiling:
                LightRecompilerInstance.interface = interface;
                state = (CpuState*) &LightRecompilerInstance.state;
                break;
            case MetaMode::LlvmRecompiling:
                state = (CpuState*) &RecompilerInstance.state;
                RecompilerInstance.interface = interface;
                break;
        }
        if(!runningLlvmOptimizer && llvmOptimizerThreshold != -1) {
            runningLlvmOptimizer = true;
            thread ot(llvmOptimizer, interface, llvmOptimizerThreshold, lightOptimizerThreshold != -1 ? lightOptimizerThreshold : 0);
            ot.detach();
        }
        if(!runningLightOptimizer && lightOptimizerThreshold != -1) {
            runningLightOptimizer = true;
            thread ot(lightOptimizer, interface, lightOptimizerThreshold);
            ot.detach();
        }
    }
}

void MetaCpu::run(uint64_t pc, uint64_t sp) {
    if(!initialized)
        initialize();

    state->PC = pc;
    state->SP = sp;
    while(true) {
        if(!interface->isValidCodePointer(CodeSource::Execution, state->PC, (CpuState*) &state))
            break;
        auto block = Cache.GetBlock(state->PC);
        if(block->func == nullptr)
            switch(baseline) {
                case MetaMode::Undefined:
                case MetaMode::Interpreting:
                    interpreter->runBlock(state->PC);
                    break;
                case MetaMode::LightRecompiling:
                    block->mutex.lock();
                    LightRecompilerInstance.recompileMultiple(block);
                    block->mutex.unlock();
                    LightRecompilerInstance.runOne(block);
                    break;
                case MetaMode::LlvmRecompiling:
                    block->mutex.lock();
                    LightRecompilerInstance.recompileMultiple(block);
                    block->mutex.unlock();
                    RecompilerInstance.runOne(block);
                    break;
            }
        else {
            block->func(state);
            state->PC = state->BranchTo;
        }
        block->hitCount++;
        break;
    }
}
