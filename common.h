#pragma once
#include <cmath>
#include <cstdint>
#include <tuple>
#include <boost/format.hpp>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "property.h"

#define EXPORTED __attribute__ ((visibility ("default")))
using std::tuple;
using std::get;

typedef uint64_t ulong;
typedef uint32_t uint;
typedef uint16_t ushort;

template<typename T> using Vector128 = T __attribute__((ext_vector_type(16 / sizeof(T)), unaligned));
template<typename T> constexpr bool is_vector_t() { return sizeof(T) == 16 && !(std::is_same<T, __uint128_t>() || std::is_same<T, __int128_t>()); }
template<typename T> using element_t = typeof(((T) {})[0]);
template<typename T> constexpr bool is_int_ptr_vec_t() {
    if constexpr(std::is_integral<T>() || std::is_pointer<T>())
        return true;
    else if constexpr(is_vector_t<T>())
        return std::is_integral<element_t<T>>();
    else
        return false;
}
template<typename T> constexpr bool is_signed() {
    if constexpr(is_vector_t<T>())
        return std::is_signed<element_t<T>>();
    else
        return std::is_signed<T>();
}
template<typename T> constexpr bool is_floating_point() {
    if constexpr(is_vector_t<T>())
        return std::is_floating_point<element_t<T>>();
    else
        return std::is_floating_point<T>();
}
template<typename T> constexpr int element_count() { return 16 / sizeof(element_t<T>); }
#include "vectorHelpers.h"

template<template<typename...> class Template, typename T>
struct is_instantiation_of : std::false_type {};
template<template<typename...> class Template, typename... Args>
struct is_instantiation_of< Template, Template<Args...> > : std::true_type {};

template<typename T>
using is_std_function = is_instantiation_of<std::function, T>;

extern EXPORTED thread_local llvm::LLVMContext Context;
extern EXPORTED thread_local llvm::IRBuilder<> Builder;

#include "xbyak/xbyak.h"
using namespace Xbyak::util;

struct LightCode : Xbyak::CodeGenerator {
public:
    inline LightCode() : CodeGenerator(Xbyak::DEFAULT_MAX_CODE_SIZE, Xbyak::AutoGrow) {}
};

class _LightLabel {
public:
    Xbyak::Label label;
};
using LightLabel = std::shared_ptr<_LightLabel>;

struct BlockContext {
    ulong LR = -1UL;
};

extern EXPORTED thread_local int LightLocalOffset;
extern EXPORTED thread_local LightCode* LC;
class LightRecompiler;
extern EXPORTED thread_local LightRecompiler LightRecompilerInstance;
class Recompiler;
extern EXPORTED thread_local Recompiler RecompilerInstance;
llvm::Module* getModule();
void emitted();
void lightEmitted();

extern const int instructionClassCount;
const char* getInstructionClass(uint inst);
std::string disassemble(uint inst, ulong pc);

template<class T>
inline T SignExt(ulong value, const int size) {
    return ((value & (1UL << (size - 1))) != 0 ? (T) value - (1L << size) : (T) value);
}

template <class Source, class Dest>
inline Dest Bitcast(const Source& source) {
    static_assert(sizeof(Dest) == sizeof(Source), "Source and destination sizes must be equal");
    Dest dest;
    memcpy(&dest, &source, sizeof(dest));
    return dest;
}

inline ulong Ones(uint bits) {
    return bits == 64 ? (ulong) -1LL : (1ULL << bits) - 1;
}

inline ulong ZeroExtend(ulong v, int bits) {
    return v & Ones(bits);
}

inline int HighestSetBit(ulong v, int bits) {
    for(auto i = bits - 1; i >= 0; --i)
        if((v & (1UL << i)) != 0)
            return i;
    return -1;
}

inline ulong Replicate(ulong v, int bits, int start, int rep, int ext) {
    auto repval = (v >> start) & Ones(rep);
    auto times = ext / rep;
    auto val = 0UL;
    for(auto i = 0; i < times; ++i)
        val = (val << rep) | repval;
    return v | (val << start);
}

inline ulong RollRight(ulong v, int size, int rotate) {
    return ((v << (size - rotate)) | (v >> rotate)) & Ones(size);
}

inline tuple<ulong, ulong> MakeMasks(uint n, uint imms, uint immr, int m, bool immediate) {
    auto len = HighestSetBit((n << 6) | (imms ^ 0b111111U), 7);
    auto levels = ZeroExtend(Ones(len), 6);

    auto S = imms & levels;
    auto R = immr & levels;

    auto diff = (S - R) & 0b111111;
    auto esize = 1 << len;
    auto d = diff & Ones(len);

    auto welem = ZeroExtend(Ones((int) (S + 1)), esize);
    auto telem = ZeroExtend(Ones((int) (d + 1)), esize);

    auto wmask = Replicate(RollRight(welem, esize, (int) R), esize, 0, esize, m);
    auto tmask = Replicate(telem, esize, 0, esize, m);
    return { wmask, tmask };
}

inline ulong MakeWMask(uint n, uint imms, uint immr, long m, int immediate) {
    return get<0>(MakeMasks(n, imms, immr, (int) m, immediate != 0));
}
inline ulong MakeTMask(uint n, uint imms, uint immr, long m, int immediate) {
    return get<1>(MakeMasks(n, imms, immr, (int) m, immediate != 0));
}

inline float FastInvsqrt(float number) {
    auto i = *(uint*) &number;
    i = 0x5f3759df - (i >> 1);
    auto f = *(float*) &i;
    f *= 1.5f - 0.5f * f * f;
    return f;
}

inline double FastInvsqrt(double number) {
    auto x2 = number * 0.5;
    auto i = *(long*) &number;
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    auto y = *(double*) &i;
    y *= 1.5 - x2 * y * y;
    return y;
}

inline uint ReverseBits(uint v) {
    auto x = 0U;
    for(auto i = 0; i < 32; ++i)
        x |= ((v >> i) & 1) << (31 - i);
    return x;
}
inline ulong ReverseBits(ulong v) {
    auto x = 0UL;
    for(auto i = 0; i < 64; ++i)
        x |= ((v >> i) & 1) << (63 - i);
    return x;
}

inline uint CountLeadingZeros(uint v) {
    for(auto i = 0; i < 32; ++i)
        if(((v >> (31 - i)) & 1) == 1)
            return (uint) i;
    return 32;
}
inline ulong CountLeadingZeros(ulong v) {
    for(auto i = 0; i < 64; ++i)
        if(((v >> (63 - i)) & 1) == 1)
            return (uint) i;
    return 64;
}

inline Vector128<float> VectorCountBits(Vector128<float> vec, long elems) {
    auto ret = (Vector128<uint8_t>) {};
    auto ivec = reinterpret_cast<Vector128<uint8_t>>(vec);
    for(auto i = 0; i < elems; ++i)
        ret[i] = __builtin_popcount(ivec[i]);
    return reinterpret_cast<Vector128<float>>(ret);
}

inline Vector128<float> VectorExtract(Vector128<float> _a, Vector128<float> _b, uint Q, uint _index) {
    auto index = (int) _index;
    auto a = reinterpret_cast<Vector128<uint8_t>>(_a);
    auto b = reinterpret_cast<Vector128<uint8_t>>(_b);

    auto r = (Vector128<uint8_t>) {};
    auto count = Q == 0 ? 8 : 16;

    if(count == 8) {
        for(auto i = index; i < 8; ++i)
            r[i - index] = a[i];
        auto offset = 8 - index;
        for(auto i = offset; i < 8; ++i)
            r[i] = b[i - offset];
    } else {
        for(auto i = index; i < 16; ++i)
            r[i - index] = a[i];
        auto offset = 16 - index;
        for(auto i = offset; i < 16; ++i)
            r[i] = b[i - offset];
    }

    return reinterpret_cast<Vector128<float>>(r);
}

inline Vector128<float> VectorFrsqrte(Vector128<float> input, int bits, int elements) {
    if(bits == 64) {
        auto vec = reinterpret_cast<Vector128<double>>(input);
        vec[0] = FastInvsqrt(vec[0]);
        vec[1] = FastInvsqrt(vec[1]);
        return reinterpret_cast<Vector128<float>>(vec);
    }
    for(auto i = 0; i < elements; ++i)
        input[i] = FastInvsqrt(input[i]);
    return input;
}

inline ulong VectorSumUnsigned(Vector128<float> vec, long esize, long count) {
    switch(esize) {
        case 8: {
            auto bvec = reinterpret_cast<Vector128<uint8_t>>(vec);
            auto sum = 0UL;
            for(auto i = 0; i < count; ++i)
                sum += bvec[i];
            return sum;
        }
        default: throw (boost::format("Unknown size for VectorSumUnsigned: %1%") % esize).str().c_str();
    }
}

inline uint FloatToFixed32(float fvalue, int fbits) {
    return (uint) (int) roundf(fvalue * (1 << fbits));
}
inline ulong FloatToFixed64(float fvalue, int fbits) {
    return (ulong) (long) roundf(fvalue * (1 << fbits));
}
inline uint FloatToFixed32(double fvalue, int fbits) {
    return (uint) (int) round(fvalue * (1 << fbits));
}
inline ulong FloatToFixed64(double fvalue, int fbits) {
    return (ulong) (long) round(fvalue * (1 << fbits));
}

template <class T>
inline uint8_t CompareAndSwap(T* ptr, T value, T comparand) {
    return __atomic_compare_exchange_n(ptr, &comparand, value, false, __ATOMIC_RELAXED, __ATOMIC_RELAXED) ? 0 : 1;
}
