#include <string>
#include <cstdint>
#include <boost/format.hpp>
#include "common.h"
using std::string;
typedef uint64_t ulong;
typedef uint32_t uint;
typedef uint16_t ushort;
typedef uint8_t byte;

const int instructionClassCount = /*%IC_COUNT%*/+0;

const char* getInstructionClass(uint inst) {
/*%IC_CODE%*/
    return nullptr;
}

const char* disassemble(uint inst, ulong pc) {
/*%D_CODE%*/
    return nullptr;
}