#pragma once

#include <cstdint>

typedef float __attribute__((ext_vector_type(4))) vector128_float;
typedef double __attribute__((ext_vector_type(2))) vector128_double;

// These DO NOT INCLUDE X31 or BranchTo!
// X31 is undefined and BranchTo is implementation-specific

#define STATE_MEMBERS(v) \
    v(PC), v(SP), \
    v(X0 ), v(X1 ), v(X2 ), v(X3 ), v(X4 ), v(X5 ), v(X6 ), v(X7 ), \
    v(X8 ), v(X9 ), v(X10), v(X11), v(X12), v(X13), v(X14), v(X15), \
    v(X16), v(X17), v(X18), v(X19), v(X20), v(X21), v(X22), v(X23), \
    v(X24), v(X25), v(X26), v(X27), v(X28), v(X29), v(X30),         \
    v(V0 ), v(V1 ), v(V2 ), v(V3 ), v(V4 ), v(V5 ), v(V6 ), v(V7 ), \
    v(V8 ), v(V9 ), v(V10), v(V11), v(V12), v(V13), v(V14), v(V15), \
    v(V16), v(V17), v(V18), v(V19), v(V20), v(V21), v(V22), v(V23), \
    v(V24), v(V25), v(V26), v(V27), v(V28), v(V29), v(V30), v(V31), \
    v(Exclusive8 ), v(Exclusive16), v(Exclusive32), v(Exclusive64), \
    v(NZCV_N     ), v(NZCV_Z     ), v(NZCV_C     ), v(NZCV_V     )

#define STATE_MEMBER_DEFS(v) \
do { \
    v(PC); v(SP); \
    v(X0 ); v(X1 ); v(X2 ); v(X3 ); v(X4 ); v(X5 ); v(X6 ); v(X7 ); \
    v(X8 ); v(X9 ); v(X10); v(X11); v(X12); v(X13); v(X14); v(X15); \
    v(X16); v(X17); v(X18); v(X19); v(X20); v(X21); v(X22); v(X23); \
    v(X24); v(X25); v(X26); v(X27); v(X28); v(X29); v(X30);         \
    v(V0 ); v(V1 ); v(V2 ); v(V3 ); v(V4 ); v(V5 ); v(V6 ); v(V7 ); \
    v(V8 ); v(V9 ); v(V10); v(V11); v(V12); v(V13); v(V14); v(V15); \
    v(V16); v(V17); v(V18); v(V19); v(V20); v(V21); v(V22); v(V23); \
    v(V24); v(V25); v(V26); v(V27); v(V28); v(V29); v(V30); v(V31); \
    v(Exclusive8 ); v(Exclusive16); v(Exclusive32); v(Exclusive64); \
    v(NZCV_N     ); v(NZCV_Z     ); v(NZCV_C     ); v(NZCV_V     ); \
} while(0)

#pragma pack(push, 8)
struct CpuState {
    uint64_t PC, SP;

    union {
        uint64_t X[32];
        struct {
            uint64_t X0 , X1 , X2 , X3 , X4 , X5 , X6 , X7 ,
                     X8 , X9 , X10, X11, X12, X13, X14, X15,
                     X16, X17, X18, X19, X20, X21, X22, X23,
                     X24, X25, X26, X27, X28, X29, X30, X31;
        };
    };

    union {
        vector128_float V[32];
        struct {
            vector128_float V0 , V1 , V2 , V3 , V4 , V5 , V6 , V7 ,
                            V8 , V9 , V10, V11, V12, V13, V14, V15,
                            V16, V17, V18, V19, V20, V21, V22, V23,
                            V24, V25, V26, V27, V28, V29, V30, V31;
        };
    };

    uint8_t Exclusive8;
    uint16_t Exclusive16;
    uint32_t Exclusive32;
    uint64_t Exclusive64;

    uint64_t NZCV_N, NZCV_Z, NZCV_C, NZCV_V;

    uint64_t BranchTo;
};
#pragma pack(pop)
