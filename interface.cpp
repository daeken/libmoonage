#include <cassert>
#include "interface.h"

CpuInterface* globalInterface = nullptr;

void registerCpuInterface(CpuInterface* interface) {
    assert(globalInterface == nullptr);
    globalInterface = interface;
}