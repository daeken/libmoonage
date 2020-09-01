#pragma once
#include "common.h"

#ifdef DEFHELPER
#define HELPER(name, type, op) void name(type* values) { values[1] = values[0] op values[1]; }
#else
#define HELPER(name, type, op) void name(type* values);
#endif

HELPER(mul_u8_vector , Vector128<uint8_t >, *)
HELPER(mul_u16_vector, Vector128<uint16_t>, *)
HELPER(mul_u32_vector, Vector128<uint32_t>, *)
HELPER(mul_u64_vector, Vector128<uint64_t>, *)
HELPER(mul_i8_vector , Vector128<int8_t  >, *)
HELPER(mul_i16_vector, Vector128<int16_t >, *)
HELPER(mul_i32_vector, Vector128<int32_t >, *)
HELPER(mul_i64_vector, Vector128<int64_t >, *)

HELPER(div_u8_vector , Vector128<uint8_t >, /)
HELPER(div_u16_vector, Vector128<uint16_t>, /)
HELPER(div_u32_vector, Vector128<uint32_t>, /)
HELPER(div_u64_vector, Vector128<uint64_t>, /)
HELPER(div_i8_vector , Vector128<int8_t  >, /)
HELPER(div_i16_vector, Vector128<int16_t >, /)
HELPER(div_i32_vector, Vector128<int32_t >, /)
HELPER(div_i64_vector, Vector128<int64_t >, /)

HELPER(mul_u128, __uint128_t, *)
HELPER(mul_i128, __int128_t, *)

HELPER(shr_u128, __uint128_t, >>)
HELPER(shr_i128, __int128_t, >>)
