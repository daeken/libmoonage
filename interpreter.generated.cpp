#include <string>
#include <cstdint>
#include <cmath>
#include "common.h"
#include "interpreter.h"
using std::string;

bool Interpreter::interpret(uint inst, ulong pc) {
	/* ADCS */
	if((inst & 0x7FE0FC00U) == 0x3A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) ((bool) (state->NZCV_C)));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) ((bool) (state->NZCV_C)));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	insn_1:
	/* ADD-extended-register */
	if((inst & 0x7FE00000U) == 0x0B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_334) -> string { switch(temp_334) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_335) -> string { switch(temp_335) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (((uint) (([=](auto temp_336) -> uint { switch(temp_336) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (((uint) (([=](auto temp_337) -> uint { switch(temp_337) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_338) -> ulong { switch(temp_338) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>((uint) ((uint) (m)), 32)))); default: return m; } })(option))) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_339) -> ulong { switch(temp_339) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>((uint) ((uint) (m)), 32)))); default: return m; } })(option))) << (uint) (imm)))));
			}
		}
		return true;
	}
	insn_2:
	/* ADD-immediate */
	if((inst & 0x7F800000U) == 0x11000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (long) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint) (((uint) ((uint) (imm))) << (uint) (shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) (simm))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) (simm))));
		} else {
			if(rd == 31)
				state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (simm)));
			else
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (simm)));
		}
		return true;
	}
	insn_3:
	/* ADD-shifted-register */
	if((inst & 0x7F200000U) == 0x0B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_340) -> string { switch(temp_340) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (([=](auto temp_341) -> uint { switch(temp_341) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (int) (imm))); } })(shift))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) + ((uint) (uint) ((uint) (([=](auto temp_342) -> uint { switch(temp_342) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? state->SP : (state->X[(int) rm] & 0xFFFFFFFFUL))) >> (int) (imm))); } })(shift))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (([=](auto temp_343) -> ulong { switch(temp_343) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (int) (imm))); } })(shift)))));
			else
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) ((ulong) (([=](auto temp_344) -> ulong { switch(temp_344) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? state->SP : state->X[(int) rm])) >> (int) (imm))); } })(shift)))));
		}
		return true;
	}
	insn_4:
	/* ADD-vector */
	if((inst & 0xBF20FC00U) == 0x0E208400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_345) -> string { switch(temp_345) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto v = (Vector128<float>) (([=](auto temp_346) -> Vector128<float> { switch(temp_346) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm]))))); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rm]))))); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rm]))))); case 0x3: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rn])) + (reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rm]))))); default: throw "Not implemented"; } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	insn_5:
	/* ADDS-extended-register */
	if((inst & 0x7FE00000U) == 0x2B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_347) -> string { switch(temp_347) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_348) -> string { switch(temp_348) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL))));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) (((uint) (([=](auto temp_349) -> uint { switch(temp_349) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				state->X[(int) rd] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (((ulong) (([=](auto temp_350) -> ulong { switch(temp_350) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		}
		return true;
	}
	insn_6:
	/* ADDS-immediate */
	if((inst & 0x7F800000U) == 0x31000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (long) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint) (((uint) ((uint) (imm))) << (uint) (shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL))));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) (simm));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) (simm));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	insn_7:
	/* ADDS-shifted-register */
	if((inst & 0x7F200000U) == 0x2B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_351) -> string { switch(temp_351) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (([=](auto temp_352) -> uint { switch(temp_352) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (([=](auto temp_353) -> ulong { switch(temp_353) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	insn_8:
	/* ADR */
	if((inst & 0x9F000000U) == 0x10000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>((uint) ((uint) (((uint) (((uint) (immlo)) << 0)) | ((uint) (((uint) (immhi)) << 2)))), 21));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (imm)));
		state->X[(int) rd] = addr;
		return true;
	}
	insn_9:
	/* ADRP */
	if((inst & 0x9F000000U) == 0x90000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) (immlo)) << 12)))) | ((ulong) (((ulong) (immhi)) << 14)))), 33));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) ((ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) ((ulong) ((ulong) ((ulong) (((ulong) (pc)) >> (uint) (0xC)))))) << 12)))))) + ((ulong) (long) (imm)));
		state->X[(int) rd] = addr;
		return true;
	}
	insn_10:
	/* AND-immediate */
	if((inst & 0x7F800000U) == 0x12000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) ((uint) (imm)))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) (imm))));
			else
				state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) (imm))));
		}
		return true;
	}
	insn_11:
	/* AND-shifted-register */
	if((inst & 0x7F200000U) == 0x0A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_354) -> string { switch(temp_354) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (([=](auto temp_355) -> uint { switch(temp_355) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (([=](auto temp_356) -> ulong { switch(temp_356) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		}
		return true;
	}
	insn_12:
	/* AND-vector */
	if((inst & 0xBFE0FC00U) == 0x0E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		auto v = (Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) & reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm]))))));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	insn_13:
	/* ANDS-shifted-register */
	if((inst & 0x7F200000U) == 0x6A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_357) -> string { switch(temp_357) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto result = (uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (([=](auto temp_358) -> uint { switch(temp_358) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
			state->X[(int) rd] = (ulong) (uint) (result);
			state->NZCV_N = (uint) ((result) >> (uint) (0x1F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		} else {
			auto result = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (([=](auto temp_359) -> ulong { switch(temp_359) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
			state->X[(int) rd] = result;
			state->NZCV_N = (ulong) ((result) >> (uint) (0x3F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		}
		return true;
	}
	insn_14:
	/* ANDS-immediate */
	if((inst & 0x7F800000U) == 0x72000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto result = (uint) ((((ulong) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((ulong) (imm))));
			state->X[(int) rd] = (ulong) (uint) (result);
			state->NZCV_N = (uint) ((result) >> (uint) (0x1F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		} else {
			auto result = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) (imm))));
			state->X[(int) rd] = result;
			state->NZCV_N = (ulong) ((result) >> (uint) (0x3F));
			state->NZCV_Z = (bool) (((result) == (0x0)) ? 1U : 0U);
			state->NZCV_C = 0x0;
			state->NZCV_V = 0x0;
		}
		return true;
	}
	insn_15:
	/* ASRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])))) >> (uint) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20))))))));
		} else {
			state->X[(int) rd] = (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])))) >> (uint) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))))));
		}
		return true;
	}
	insn_16:
	/* B */
	if((inst & 0xFC000000U) == 0x14000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28)))));
		Branch(addr);
		return true;
	}
	insn_17:
	/* B.cond */
	if((inst & 0xFF000010U) == 0x54000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto cond = (inst >> 0) & 0xFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 21)))));
		auto condstr = (string) (([=](auto temp_360) -> string { switch(temp_360) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_361) -> bool { switch(temp_361) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			Branch(addr);
		} else {
			Branch(pc + 4);
		}
		return true;
	}
	insn_18:
	/* BFM */
	if((inst & 0x7F800000U) == 0x33000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto dst = (uint) ((rd) == 31 ? 0U : (uint) state->X[(int) rd]);
			auto src = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = (uint) ((((uint) ((uint) ((((uint) (dst)) & ((uint) ((uint) (~(wmask)))))))) | ((uint) ((uint) ((((uint) ((uint) (((src) << (32 - (int) (immr))) | ((src) >> (int) (immr))))) & ((uint) (wmask))))))));
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((((uint) (dst)) & ((uint) ((uint) (~(tmask)))))))) | ((uint) ((uint) ((((uint) (bot)) & ((uint) (tmask)))))))));
		} else {
			auto dst = (ulong) ((rd) == 31 ? 0UL : state->X[(int) rd]);
			auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = (ulong) ((((ulong) ((ulong) ((((ulong) (dst)) & ((ulong) ((ulong) (~(wmask)))))))) | ((ulong) ((ulong) ((((ulong) ((ulong) (((src) << (64 - (int) (immr))) | ((src) >> (int) (immr))))) & ((ulong) (wmask))))))));
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((((ulong) (dst)) & ((ulong) ((ulong) (~(tmask)))))))) | ((ulong) ((ulong) ((((ulong) (bot)) & ((ulong) (tmask))))))));
		}
		return true;
	}
	insn_19:
	/* BIC */
	if((inst & 0x7F200000U) == 0x0A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_362) -> string { switch(temp_362) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (~((uint) (([=](auto temp_363) -> uint { switch(temp_363) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (~((ulong) (([=](auto temp_364) -> ulong { switch(temp_364) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
		}
		return true;
	}
	insn_20:
	/* BIC-vector-register */
	if((inst & 0xBFE0FC00U) == 0x0E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto v = (Vector128<float>) (reinterpret_cast<Vector128<float>>(~(reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) & reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm])))));
		if(((bool) (((Q) == (0x1)) ? 1U : 0U)) != 0) {
			state->V[rd] = v;
		} else {
			state->V[rd] = (Vector128<float>) (v);
		}
		return true;
	}
	insn_21:
	/* BICS */
	if((inst & 0x7F200000U) == 0x6A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_365) -> string { switch(temp_365) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto val = (uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) & ((uint) ((uint) (~((uint) (([=](auto temp_366) -> uint { switch(temp_366) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
			state->X[(int) rd] = (ulong) (uint) (val);
			NZCV = (ulong) ((((ulong) ((ulong) (((ulong) ((ulong) ((uint) ((val) >> (uint) (0x1F))))) << (uint) (0x1F)))) | ((ulong) ((ulong) (((ulong) ((ulong) ((bool) (((val) == (0x0)) ? 1U : 0U)))) << (uint) (0x1E))))));
		} else {
			auto val = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) & ((ulong) ((ulong) (~((ulong) (([=](auto temp_367) -> ulong { switch(temp_367) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
			state->X[(int) rd] = val;
			NZCV = (ulong) ((((ulong) ((ulong) (((ulong) ((ulong) ((ulong) ((val) >> (uint) (0x3F))))) << (uint) (0x1F)))) | ((ulong) ((ulong) (((ulong) ((ulong) ((bool) (((val) == (0x0)) ? 1U : 0U)))) << (uint) (0x1E))))));
		}
		return true;
	}
	insn_22:
	/* BL */
	if((inst & 0xFC000000U) == 0x94000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto offset = (long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (offset)));
		BranchLinked(addr);
		return true;
	}
	insn_23:
	/* BLR */
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchLinkedRegister(rn);
		return true;
	}
	insn_24:
	/* BR */
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchRegister(rn);
		return true;
	}
	insn_25:
	/* BRK */
	if((inst & 0xFFE0001FU) == 0xD4200000U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		Branch(-0xE0E0E0E0D0D0D0E);
		return true;
	}
	insn_26:
	/* CASP */
	if((inst & 0xBFE0FC00U) == 0x08207C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		throw "Not implemented";
		return true;
	}
	insn_27:
	/* CASPA */
	if((inst & 0xBFE0FC00U) == 0x08607C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		throw "Not implemented";
		return true;
	}
	insn_28:
	/* CASPAL */
	if((inst & 0xBFE0FC00U) == 0x0860FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto cl = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
			auto ch = (uint) (((ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))) == 31 ? 0U : (uint) state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))]);
			auto nl = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
			auto nh = (uint) (((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))) == 31 ? 0U : (uint) state->X[(int) (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))]);
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			auto data = (ulong) (*(ulong*) (address));
			if(((bool) (((data) == ((ulong) ((((ulong) ((ulong) (((ulong) ((ulong) (ch))) << (uint) (0x20)))) | ((ulong) ((ulong) ((ulong) (cl)))))))) ? 1U : 0U)) != 0) {
				*(ulong*) (address) = (ulong) ((((ulong) ((ulong) (((ulong) ((ulong) (nh))) << (uint) (0x20)))) | ((ulong) ((ulong) ((ulong) (nl))))));
			} else {
			}
			state->X[(int) rs] = (ulong) (uint) ((uint) ((uint) (data)));
			state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))] = (ulong) (uint) ((uint) ((uint) ((ulong) ((data) >> (uint) (0x20)))));
		} else {
			auto cl = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
			auto ch = (ulong) (((ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))) == 31 ? 0UL : state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))]);
			auto nl = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
			auto nh = (ulong) (((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))) == 31 ? 0UL : state->X[(int) (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))]);
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			auto dl = (ulong) (*(ulong*) (address));
			auto dh = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
			if(((bool) ((((bool) ((bool) (((dl) == (cl)) ? 1U : 0U))) & ((bool) ((bool) (((dh) == (ch)) ? 1U : 0U)))))) != 0) {
				*(ulong*) (address) = nl;
				*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = nh;
			} else {
			}
			state->X[(int) rs] = dl;
			state->X[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))] = dh;
		}
		return true;
	}
	insn_29:
	/* CASPL */
	if((inst & 0xBFE0FC00U) == 0x0820FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)));
		auto rt2 = (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)));
		throw "Not implemented";
		return true;
	}
	insn_30:
	/* CBNZ */
	if((inst & 0x7F000000U) == 0x35000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(((bool) ((((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])) != ((uint) ((uint) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		} else {
			if(((bool) ((((ulong) ((rs) == 31 ? 0UL : state->X[(int) rs])) != ((ulong) ((ulong) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		}
		return true;
	}
	insn_31:
	/* CBZ */
	if((inst & 0x7F000000U) == 0x34000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(((bool) ((((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])) == ((uint) ((uint) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		} else {
			if(((bool) ((((ulong) ((rs) == 31 ? 0UL : state->X[(int) rs])) == ((ulong) ((ulong) (0x0)))) ? 1U : 0U)) != 0) {
				Branch(addr);
			} else {
				Branch(pc + 4);
			}
		}
		return true;
	}
	insn_32:
	/* CCMN-immediate */
	if((inst & 0x7FE00C10U) == 0x3A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_368) -> string { switch(temp_368) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_369) -> bool { switch(temp_369) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) 0x1F] = (ulong) (uint) ((uint) (([=]() -> uint {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) ((uint) (imm))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
						auto bits = (int) (32);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})()));
			} else {
				state->X[(int) 0x1F] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) ((ulong) (imm))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	insn_33:
	/* CCMP-immediate */
	if((inst & 0x7FE00C10U) == 0x7A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_370) -> string { switch(temp_370) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_371) -> bool { switch(temp_371) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) 0x1F] = (ulong) (uint) ((uint) (([=]() -> uint {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((uint) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
						auto bits = (int) (32);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})()));
			} else {
				state->X[(int) 0x1F] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((ulong) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	insn_34:
	/* CCMP-register */
	if((inst & 0x7FE00C10U) == 0x7A400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_372) -> string { switch(temp_372) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_373) -> bool { switch(temp_373) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) 0x1F] = (ulong) (uint) ((uint) (([=]() -> uint {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
						auto bits = (int) (32);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})()));
			} else {
				state->X[(int) 0x1F] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	insn_35:
	/* CLREX */
	if((inst & 0xFFFFF0FFU) == 0xD503305FU) {
		auto crm = (inst >> 8) & 0xFU;
		return true;
	}
	insn_36:
	/* CLZ */
	if((inst & 0x7FFFFC00U) == 0x5AC01000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (CountLeadingZeros((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))));
		} else {
			state->X[(int) rd] = (ulong) (CountLeadingZeros((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
		}
		return true;
	}
	insn_37:
	/* CMEQ-register-scalar */
	if((inst & 0xFF20FC00U) == 0x7E208C00U) {
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_374) -> string { switch(temp_374) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x3: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) == ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]))) ? 1U : 0U) != 0) ? ((ulong) ((ulong) (-0x1))) : ((ulong) ((ulong) (0x0)))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_38:
	/* CMEQ-register-vector */
	if((inst & 0xBF20FC00U) == 0x2E208C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_375) -> string { switch(temp_375) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto a = (Vector128<float>) (state->V[rn]);
		auto b = (Vector128<float>) (state->V[rm]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				auto one = (byte) ((byte) (0xFF));
				auto zero = (byte) ((byte) (0x0));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x0])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x1])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x2])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x3])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x4])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x5])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x6])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x7])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x8])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x9])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xA])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xB])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xC] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xC])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xD] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xD])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xE] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xE])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xF] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xF])) == ((byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
			case 0x1: {
				auto one = (ushort) ((ushort) (0xFFFF));
				auto zero = (ushort) ((ushort) (0x0));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7])) == ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
			case 0x2: {
				auto one = (uint) ((uint) (0xFFFFFFFF));
				auto zero = (uint) ((uint) (0x0));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((bool) ((((float) (reinterpret_cast<Vector128<float>>(a)[0x0])) == ((float) (reinterpret_cast<Vector128<float>>(b)[0x0]))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((bool) ((((float) (reinterpret_cast<Vector128<float>>(a)[0x1])) == ((float) (reinterpret_cast<Vector128<float>>(b)[0x1]))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((bool) ((((float) (reinterpret_cast<Vector128<float>>(a)[0x2])) == ((float) (reinterpret_cast<Vector128<float>>(b)[0x2]))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((bool) ((((float) (reinterpret_cast<Vector128<float>>(a)[0x3])) == ((float) (reinterpret_cast<Vector128<float>>(b)[0x3]))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
			default: {
				auto one = (ulong) ((ulong) (-0x1));
				auto zero = (ulong) ((ulong) (0x0));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(a)[0x0])) == ((double) (reinterpret_cast<Vector128<double>>(b)[0x0]))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(a)[0x1])) == ((double) (reinterpret_cast<Vector128<double>>(b)[0x1]))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
		}
		return true;
	}
	insn_39:
	/* CMEQ-zero-scalar */
	if((inst & 0xFF3FFC00U) == 0x5E209800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_376) -> string { switch(temp_376) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x3: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) (((bool) ((((long) (Bitcast<double, long>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))) == ((long) ((long) (0x0)))) ? 1U : 0U) != 0) ? ((ulong) ((ulong) (-0x1))) : ((ulong) ((ulong) (0x0)))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_40:
	/* CMEQ-zero-vector */
	if((inst & 0xBF3FFC00U) == 0x0E209800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_377) -> string { switch(temp_377) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto a = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				auto one = (byte) ((byte) (0xFF));
				auto zero = (byte) ((byte) (0x0));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x0])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x1])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x2])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x3])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x4])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x5])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x6])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x7])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x8])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0x9])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xA])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xB])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xC] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xC])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xD] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xD])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xE] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xE])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xF] = (byte) (((bool) ((((byte) (reinterpret_cast<Vector128<byte>>(a)[0xF])) == ((byte) ((byte) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
			case 0x1: {
				auto one = (ushort) ((ushort) (0xFFFF));
				auto zero = (ushort) ((ushort) (0x0));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((bool) ((((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7])) == ((ushort) ((ushort) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
			case 0x2: {
				auto one = (uint) ((uint) (0xFFFFFFFF));
				auto zero = (uint) ((uint) (0x0));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((bool) ((((uint) (reinterpret_cast<Vector128<uint>>(a)[0x0])) == ((uint) ((uint) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((bool) ((((uint) (reinterpret_cast<Vector128<uint>>(a)[0x1])) == ((uint) ((uint) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((bool) ((((uint) (reinterpret_cast<Vector128<uint>>(a)[0x2])) == ((uint) ((uint) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((bool) ((((uint) (reinterpret_cast<Vector128<uint>>(a)[0x3])) == ((uint) ((uint) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
			default: {
				auto one = (ulong) ((ulong) (-0x1));
				auto zero = (ulong) ((ulong) (0x0));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((bool) ((((ulong) (reinterpret_cast<Vector128<ulong>>(a)[0x0])) == ((ulong) ((ulong) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((bool) ((((ulong) (reinterpret_cast<Vector128<ulong>>(a)[0x1])) == ((ulong) ((ulong) (0x0)))) ? 1U : 0U) != 0) ? (one) : (zero));
				}
				break;
			}
		}
		return true;
	}
	insn_41:
	/* CNT */
	if((inst & 0xBF3FFC00U) == 0x0E205800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_378) -> string { switch(temp_378) { case 0x0: return string("8B"); case 0x1: return string("16B"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		state->V[rd] = (Vector128<float>) (VectorCountBits((Vector128<float>) (state->V[rn]), (long) (([=](auto temp_379) -> long { switch(temp_379) { case 0x0: return 0x8; default: return 0x10; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))))));
		return true;
	}
	insn_42:
	/* CSEL */
	if((inst & 0x7FE00C00U) == 0x1A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_380) -> string { switch(temp_380) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_381) -> bool { switch(temp_381) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]));
			} else {
				state->X[(int) rd] = (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]);
			}
		}
		return true;
	}
	insn_43:
	/* CSINC */
	if((inst & 0x7FE00C00U) == 0x1A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_382) -> string { switch(temp_382) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_383) -> bool { switch(temp_383) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) + ((uint) (uint) ((uint) ((uint) (0x1))))));
			} else {
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) + ((ulong) (long) (0x1)));
			}
		}
		return true;
	}
	insn_44:
	/* CSINV */
	if((inst & 0x7FE00C00U) == 0x5A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_384) -> string { switch(temp_384) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_385) -> bool { switch(temp_385) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) (~((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))));
			} else {
				state->X[(int) rd] = (ulong) (~((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])));
			}
		}
		return true;
	}
	insn_45:
	/* CSNEG */
	if((inst & 0x7FE00C00U) == 0x5A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_386) -> string { switch(temp_386) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_387) -> bool { switch(temp_387) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]));
			} else {
				state->X[(int) rd] = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			}
		} else {
			if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (-((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))))))));
			} else {
				state->X[(int) rd] = (ulong) ((ulong) ((long) (-((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))))));
			}
		}
		return true;
	}
	insn_46:
	/* DMB */
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU) {
		auto m = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_388) -> string { switch(temp_388) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(m));
		return true;
	}
	insn_47:
	/* DSB */
	if((inst & 0xFFFFF0FFU) == 0xD503309FU) {
		auto crm = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_389) -> string { switch(temp_389) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(crm));
		return true;
	}
	insn_48:
	/* DUP-element-scalar */
	if((inst & 0xFFE0FC00U) == 0x5E000400U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = string("");
		auto index = 0x0;
		auto size = 0x0;
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				T = string("B");
				index = (byte) ((imm) >> (uint) (0x1));
				size = 0x1;
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					T = string("H");
					index = (byte) ((imm) >> (uint) (0x2));
					size = 0x2;
				} else {
					if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						T = string("S");
						index = (byte) ((imm) >> (uint) (0x3));
						size = 0x4;
					} else {
						T = string("D");
						index = (byte) ((imm) >> (uint) (0x4));
						size = 0x8;
					}
				}
			}
		}
		auto sv = (Vector128<float>) (state->V[rn]);
		switch(size) {
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (reinterpret_cast<Vector128<byte>>(sv)[index]), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x2: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (reinterpret_cast<Vector128<ushort>>(sv)[index]), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (reinterpret_cast<Vector128<float>>(sv)[index]), 0, 0, 0 };
				break;
			}
			default: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (reinterpret_cast<Vector128<double>>(sv)[index]), 0 });
				break;
			}
		}
		return true;
	}
	insn_49:
	/* DUP-element-vector */
	if((inst & 0xBFE0FC00U) == 0x0E000400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ts = string("");
		auto T = string("");
		auto index = 0x0;
		auto size = 0x0;
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				Ts = string("B");
				T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
				index = (byte) ((imm) >> (uint) (0x1));
				size = 0x1;
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					Ts = string("H");
					T = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
					index = (byte) ((imm) >> (uint) (0x2));
					size = 0x2;
				} else {
					if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						Ts = string("S");
						T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
						index = (byte) ((imm) >> (uint) (0x3));
						size = 0x4;
					} else {
						Ts = string("D");
						T = (string) ((Q != 0) ? (string("2D")) : throw "Not implemented");
						index = (byte) ((imm) >> (uint) (0x4));
						size = 0x8;
					}
				}
			}
		}
		auto sv = (Vector128<float>) (state->V[rn]);
		auto tv = (Vector128<float>) (([=](auto temp_390) -> Vector128<float> { switch(temp_390) { case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) (reinterpret_cast<Vector128<byte>>(sv)[index])) - (Vector128<byte>) {})); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[index])) - (Vector128<ushort>) {})); case 0x4: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (reinterpret_cast<Vector128<float>>(sv)[index])) - (Vector128<float>) {})); default: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (reinterpret_cast<Vector128<double>>(sv)[index])) - (Vector128<double>) {})); } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (tv) : ((Vector128<float>) (tv)));
		return true;
	}
	insn_50:
	/* DUP-general */
	if((inst & 0xBFE0FC00U) == 0x0E000C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto size = ((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((long) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x8)) ? 1U : 0U) != 0) ? (0x40) : (0x20)));
		auto r = (string) (((bool) (((size) == (0x40)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto T = ((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("16B")) : (string("8B")))) : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("8H")) : (string("4H")))) : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("4S")) : (string("2S")))) : ((string) ((Q != 0) ? (string("2D")) : throw "Not implemented"))))))));
		auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
		state->V[rd] = (Vector128<float>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (src))) - (Vector128<byte>) {}))) : ((Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (src))) - (Vector128<byte>) {})))))) : ((Vector128<float>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) ((ushort) (src))) - (Vector128<ushort>) {}))) : ((Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) ((ushort) (src))) - (Vector128<ushort>) {})))))) : ((Vector128<float>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((uint) ((uint) (src))) - (Vector128<uint>) {}))) : ((Vector128<float>) ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((uint) ((uint) (src))) - (Vector128<uint>) {})))))) : ((Vector128<float>) ((Q != 0) ? ((Vector128<float>) (reinterpret_cast<Vector128<float>>((src) - (Vector128<ulong>) {}))) : throw "Not implemented")))))));
		return true;
	}
	insn_51:
	/* EON-shifted-register */
	if((inst & 0x7F200000U) == 0x4A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_391) -> string { switch(temp_391) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) (~((uint) (([=](auto temp_392) -> uint { switch(temp_392) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) ((ulong) (~((ulong) (([=](auto temp_393) -> ulong { switch(temp_393) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
		}
		return true;
	}
	insn_52:
	/* EOR-immediate */
	if((inst & 0x7F800000U) == 0x52000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) ((uint) (imm)))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) (imm))));
			else
				state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) (imm))));
		}
		return true;
	}
	insn_53:
	/* EOR-shifted-register */
	if((inst & 0x7F200000U) == 0x4A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_394) -> string { switch(temp_394) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) ^ ((uint) ((uint) (([=](auto temp_395) -> uint { switch(temp_395) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) ^ ((ulong) ((ulong) (([=](auto temp_396) -> ulong { switch(temp_396) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		}
		return true;
	}
	insn_54:
	/* EOR-vector */
	if((inst & 0xBFE0FC00U) == 0x2E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		auto v = (Vector128<float>) (reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) ^ reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm])))));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	insn_55:
	/* EXT */
	if((inst & 0xBFE08400U) == 0x2E000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto index = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		state->V[rd] = (Vector128<float>) (VectorExtract((Vector128<float>) (state->V[rn]), (Vector128<float>) (state->V[rm]), Q, index));
		return true;
	}
	insn_56:
	/* EXTR */
	if((inst & 0x7FA00000U) == 0x13800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto o = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto lsb = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) << (uint) ((ulong) (((ulong) (long) (0x20)) - ((ulong) (byte) (lsb))))))) | ((uint) ((uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (lsb)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) << (uint) ((ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (lsb))))))) | ((ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (lsb))))));
		}
		return true;
	}
	insn_57:
	/* FABD-scalar */
	if((inst & 0xFFA0FC00U) == 0x7EA0D400U) {
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_397) -> string { switch(temp_397) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (fabs((float) (((float) (float) ((float) (state->V[rn][0]))) - ((float) (float) ((float) (state->V[rm][0])))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (fabs((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) - ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_58:
	/* FABS-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E20C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_398) -> string { switch(temp_398) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (fabs((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (fabs((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_59:
	/* FABS-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_399) -> string { switch(temp_399) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (fabs(a));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (fabs(b));
				break;
			}
			case 0x1: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (fabs(a));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (fabs(b));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (fabs(c));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (fabs(d));
				break;
			}
			case 0x3: {
				auto a = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) ((double) (0x0))) - (Vector128<double>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (fabs(a));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (fabs(b));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_60:
	/* FADD-scalar */
	if((inst & 0xFF20FC00U) == 0x1E202800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_400) -> string { switch(temp_400) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x3: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))) + ((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rm])[0])))))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) + ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) + ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_61:
	/* FADD-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_401) -> string { switch(temp_401) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) + ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) + ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) + reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_62:
	/* FADDP-scalar */
	if((inst & 0xFFBFFC00U) == 0x7E30D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]))) + ((float) (float) ((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1])))), 0, 0, 0 };
		} else {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]))) + ((double) (double) ((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1])))), 0 });
		}
		return true;
	}
	insn_63:
	/* FADDP-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_402) -> string { switch(temp_402) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto d = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((float) (float) (a)) + ((float) (float) (b)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((float) (float) (c)) + ((float) (float) (d)));
				break;
			}
			case 0x1: {
				auto a = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				auto e = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto f = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				auto g = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x2]);
				auto h = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((float) (float) (a)) + ((float) (float) (b)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((float) (float) (c)) + ((float) (float) (d)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (((float) (float) (e)) + ((float) (float) (f)));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (((float) (float) (g)) + ((float) (float) (h)));
				break;
			}
			case 0x3: {
				auto a = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto d = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x0))) - (Vector128<float>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (((double) (double) (a)) + ((double) (double) (b)));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (((double) (double) (c)) + ((double) (double) (d)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_64:
	/* FCCMP */
	if((inst & 0xFF200C10U) == 0x1E200400U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (([=](auto temp_403) -> string { switch(temp_403) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_404) -> string { switch(temp_404) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_405) -> bool { switch(temp_405) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			switch(type) {
				case 0x0: {
					auto __macro_fcmp_a = (float) (state->V[rn][0]);
					auto __macro_fcmp_b = (float) (state->V[rm][0]);
					NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
					break;
				}
				case 0x1: {
					auto __macro_fcmp_a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
					auto __macro_fcmp_b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
					NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
					break;
				}
				default: {
					throw "Not implemented";
					break;
				}
			}
		} else {
			NZCV = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		}
		return true;
	}
	insn_65:
	/* FCMxx-register-vector */
	if((inst & 0x9F20F400U) == 0x0E20E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto E = (inst >> 23) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ac = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_406) -> string { switch(temp_406) { case 0x0: return string("EQ"); case 0x2: return string("GE"); case 0x3: return string("GE"); case 0x6: return string("GT"); case 0x7: return string("GT"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
		auto t = (string) (([=](auto temp_407) -> string { switch(temp_407) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto a2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto b1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto b2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_408) -> float { switch(temp_408) { case 0x0: return (float) (((bool) (((a1) == (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a1) >= (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a1))) >= ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a1) > (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a1))) > ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_409) -> float { switch(temp_409) { case 0x0: return (float) (((bool) (((a2) == (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a2) >= (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a2))) >= ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a2) > (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a2))) > ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				break;
			}
			case 0x1: {
				auto a1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto a2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto a3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto a4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				auto b1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto b2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x1]);
				auto b3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x2]);
				auto b4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_410) -> float { switch(temp_410) { case 0x0: return (float) (((bool) (((a1) == (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a1) >= (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a1))) >= ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a1) > (b1)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a1))) > ((float) (fabs(b1)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_411) -> float { switch(temp_411) { case 0x0: return (float) (((bool) (((a2) == (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a2) >= (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a2))) >= ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a2) > (b2)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a2))) > ((float) (fabs(b2)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (([=](auto temp_412) -> float { switch(temp_412) { case 0x0: return (float) (((bool) (((a3) == (b3)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a3) >= (b3)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a3))) >= ((float) (fabs(b3)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a3) > (b3)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a3))) > ((float) (fabs(b3)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (([=](auto temp_413) -> float { switch(temp_413) { case 0x0: return (float) (((bool) (((a4) == (b4)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((a4) >= (b4)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x3: return (float) (((bool) ((((float) (fabs(a4))) >= ((float) (fabs(b4)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x6: return (float) (((bool) (((a4) > (b4)) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x7: return (float) (((bool) ((((float) (fabs(a4))) > ((float) (fabs(b4)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				break;
			}
			case 0x3: {
				auto a1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto a2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto b1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x0]);
				auto b2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (([=](auto temp_414) -> double { switch(temp_414) { case 0x0: return (double) (((bool) (((a1) == (b1)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((a1) >= (b1)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x3: return (double) (((bool) ((((double) (fabs(a1))) >= ((double) (fabs(b1)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x6: return (double) (((bool) (((a1) > (b1)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x7: return (double) (((bool) ((((double) (fabs(a1))) > ((double) (fabs(b1)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (([=](auto temp_415) -> double { switch(temp_415) { case 0x0: return (double) (((bool) (((a2) == (b2)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((a2) >= (b2)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x3: return (double) (((bool) ((((double) (fabs(a2))) >= ((double) (fabs(b2)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x6: return (double) (((bool) (((a2) > (b2)) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x7: return (double) (((bool) ((((double) (fabs(a2))) > ((double) (fabs(b2)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_66:
	/* FCMxx-zero-vector */
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto op = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_416) -> string { switch(temp_416) { case 0x0: return string("GT"); case 0x1: return string("GE"); case 0x2: return string("EQ"); default: return string("LE"); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
		auto t = (string) (([=](auto temp_417) -> string { switch(temp_417) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_418) -> float { switch(temp_418) { case 0x0: return (float) (((bool) (((v1) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v1) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v1) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v1) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_419) -> float { switch(temp_419) { case 0x0: return (float) (((bool) (((v2) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v2) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v2) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v2) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				break;
			}
			case 0x1: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto v3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto v4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (([=](auto temp_420) -> float { switch(temp_420) { case 0x0: return (float) (((bool) (((v1) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v1) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v1) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v1) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (([=](auto temp_421) -> float { switch(temp_421) { case 0x0: return (float) (((bool) (((v2) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v2) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v2) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v2) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (([=](auto temp_422) -> float { switch(temp_422) { case 0x0: return (float) (((bool) (((v3) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v3) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v3) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v3) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (([=](auto temp_423) -> float { switch(temp_423) { case 0x0: return (float) (((bool) (((v4) > ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x1: return (float) (((bool) (((v4) >= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); case 0x2: return (float) (((bool) (((v4) == ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); default: return (float) (((bool) (((v4) <= ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				break;
			}
			case 0x3: {
				auto v1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (([=](auto temp_424) -> double { switch(temp_424) { case 0x0: return (double) (((bool) (((v1) > ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x1: return (double) (((bool) (((v1) >= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((v1) == ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: return (double) (((bool) (((v1) <= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (([=](auto temp_425) -> double { switch(temp_425) { case 0x0: return (double) (((bool) (((v2) > ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x1: return (double) (((bool) (((v2) >= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); case 0x2: return (double) (((bool) (((v2) == ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); default: return (double) (((bool) (((v2) <= ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_67:
	/* FCMLT-zero-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_426) -> string { switch(temp_426) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((bool) (((v1) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((bool) (((v2) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				break;
			}
			case 0x1: {
				auto v1 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto v3 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto v4 = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (((bool) (((v1) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (((bool) (((v2) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (((bool) (((v3) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (((bool) (((v4) < ((float) ((float) (0x0)))) ? 1U : 0U) != 0) ? ((float) (Bitcast<int, float>((int) ((int) (-0x1))))) : ((float) (Bitcast<int, float>((int) ((int) (0x0))))));
				break;
			}
			case 0x3: {
				auto v1 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto v2 = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((int) ((int) (0x0))) - (Vector128<int>) {}));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (((bool) (((v1) < ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (((bool) (((v2) < ((double) ((double) (0x0)))) ? 1U : 0U) != 0) ? ((double) (Bitcast<long, double>((long) ((long) (-0x1))))) : ((double) (Bitcast<long, double>((long) ((long) (0x0))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_68:
	/* FCMP */
	if((inst & 0xFF20FC17U) == 0x1E202000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto opc = (inst >> 3) & 0x1U;
		auto r = (string) (([=](auto temp_427) -> string { switch(temp_427) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto zero = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("/0")) : (string("")));
		switch(type) {
			case 0x0: {
				auto __macro_fcmp_a = (float) (state->V[rn][0]);
				auto __macro_fcmp_b = (float) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? ((float) ((float) (0x0))) : ((float) (state->V[rm][0])));
				NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
				break;
			}
			case 0x1: {
				auto __macro_fcmp_a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto __macro_fcmp_b = (double) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? ((double) ((double) (0x0))) : ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])));
				NZCV = (uint) ((uint) ((long) (((long) (((bool) ((((bool) ((bool) (isnan(__macro_fcmp_a) ? 1U : 0U))) | ((bool) ((bool) (isnan(__macro_fcmp_b) ? 1U : 0U))))) != 0) ? (0x3) : ((long) (((bool) (((__macro_fcmp_a) == (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x6) : ((long) (((bool) (((__macro_fcmp_a) < (__macro_fcmp_b)) ? 1U : 0U) != 0) ? (0x8) : (0x2))))))) << (uint) (0x1C))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_69:
	/* FCSEL */
	if((inst & 0xFF200C00U) == 0x1E200C00U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_428) -> string { switch(temp_428) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_429) -> string { switch(temp_429) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = (bool) (([=](auto temp_430) -> bool { switch(temp_430) { case 0x0: return (bool) (state->NZCV_Z); case 0x1: return (bool) (state->NZCV_C); case 0x2: return (bool) (state->NZCV_N); case 0x3: return (bool) (state->NZCV_V); case 0x4: return (bool) ((((bool) ((bool) (state->NZCV_C))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); case 0x5: return (bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U); case 0x6: return (bool) ((((bool) ((bool) ((((bool) (state->NZCV_N)) == ((bool) (state->NZCV_V))) ? 1U : 0U))) & ((bool) ((bool) (((bool) (state->NZCV_Z)) != 0 ? 0U : 1U))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))));
		if(((bool) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U))))) != 0) ? ((bool) ((result) != 0 ? 0U : 1U)) : (result))) != 0) {
			switch(type) {
				case 0x0: {
					state->V[(int) (rd)] = (Vector128<float>) { (float) (state->V[rn][0]), 0, 0, 0 };
					break;
				}
				case 0x1: {
					state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), 0 });
					break;
				}
				default: {
					throw "Not implemented";
					break;
				}
			}
		} else {
			switch(type) {
				case 0x0: {
					state->V[(int) (rd)] = (Vector128<float>) { (float) (state->V[rm][0]), 0, 0, 0 };
					break;
				}
				case 0x1: {
					state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]), 0 });
					break;
				}
				default: {
					throw "Not implemented";
					break;
				}
			}
		}
		return true;
	}
	insn_70:
	/* FCVT */
	if((inst & 0xFF3E7C00U) == 0x1E224000U) {
		auto type = (inst >> 22) & 0x3U;
		auto opc = (inst >> 15) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = string("");
		auto r2 = string("");
		auto tf = (byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (type)) << 2))));
		switch(tf) {
			case 0xC: {
				r1 = string("S");
				r2 = string("H");
				break;
			}
			case 0xD: {
				r1 = string("D");
				r2 = string("H");
				break;
			}
			case 0x3: {
				r1 = string("H");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("D");
				r2 = string("S");
				break;
			}
			case 0x7: {
				r1 = string("H");
				r2 = string("D");
				break;
			}
			case 0x4: {
				r1 = string("S");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(tf) {
			case 0xC: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))), 0, 0, 0 };
				break;
			}
			case 0xD: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))), 0 });
				break;
			}
			case 0x3: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((float) (state->V[rn][0]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((float) (state->V[rn][0]))), 0 });
				break;
			}
			case 0x7: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0, 0, 0 };
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_71:
	/* FCVTAS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E240000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (Bitcast<int, uint>((int) ((int) ((float) (((bool) ((((float) (state->V[rn][0])) >= (0x0)) ? 1U : 0U) != 0) ? ((float) (ceilf((float) (state->V[rn][0])))) : ((float) (floorf((float) (state->V[rn][0]))))))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) (Bitcast<long, ulong>((long) ((long) ((float) (((bool) ((((float) (state->V[rn][0])) >= (0x0)) ? 1U : 0U) != 0) ? ((float) (ceilf((float) (state->V[rn][0])))) : ((float) (floorf((float) (state->V[rn][0])))))))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (Bitcast<int, uint>((int) ((int) ((double) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) >= (0x0)) ? 1U : 0U) != 0) ? ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))) : ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) (Bitcast<long, ulong>((long) ((long) ((double) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) >= (0x0)) ? 1U : 0U) != 0) ? ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))) : ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_72:
	/* FCVTAU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E250000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((float) (((bool) ((((float) (state->V[rn][0])) >= (0x0)) ? 1U : 0U) != 0) ? ((float) (ceilf((float) (state->V[rn][0])))) : ((float) (floorf((float) (state->V[rn][0]))))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((float) (((bool) ((((float) (state->V[rn][0])) >= (0x0)) ? 1U : 0U) != 0) ? ((float) (ceilf((float) (state->V[rn][0])))) : ((float) (floorf((float) (state->V[rn][0])))))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((double) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) >= (0x0)) ? 1U : 0U) != 0) ? ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))) : ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((double) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) >= (0x0)) ? 1U : 0U) != 0) ? ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))) : ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_73:
	/* FCVTL[2] */
	if((inst & 0xBFBFFC00U) == 0x0E217800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto o2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = (string) ((size != 0) ? (string("2D")) : (string("4S")));
		auto tb = (string) (([=](auto temp_431) -> string { switch(temp_431) { case 0x0: return string("4H"); case 0x1: return string("8H"); case 0x2: return string("2S"); default: return string("4S"); } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x2: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x1])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x2])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((float) (reinterpret_cast<Vector128<float>>(n)[0x3])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_74:
	/* FCVTMS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E300000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (Bitcast<int, uint>((int) ((int) ((float) (floorf((float) (state->V[rn][0]))))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) (Bitcast<long, ulong>((long) ((long) ((float) (floorf((float) (state->V[rn][0])))))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (Bitcast<int, uint>((int) ((int) ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) (Bitcast<long, ulong>((long) ((long) ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_75:
	/* FCVTMU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E310000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((float) (floorf((float) (state->V[rn][0]))))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((float) (floorf((float) (state->V[rn][0])))))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((double) (floor((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_76:
	/* FCVTN */
	if((inst & 0xFFBFFC00U) == 0x0E216800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ta = string("");
		auto Tb = string("");
		switch(size) {
			case 0x0: {
				Ta = string("4S");
				Tb = string("4H");
				break;
			}
			case 0x1: {
				Ta = string("2D");
				Tb = string("2S");
				break;
			}
		}
		auto sv = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x0])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x1])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x2])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x3])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((double) (reinterpret_cast<Vector128<double>>(sv)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((double) (reinterpret_cast<Vector128<double>>(sv)[0x1])));
				break;
			}
		}
		return true;
	}
	insn_77:
	/* FCVTN2 */
	if((inst & 0xFFBFFC00U) == 0x4E216800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ta = string("");
		auto Tb = string("");
		switch(size) {
			case 0x0: {
				Ta = string("4S");
				Tb = string("8H");
				break;
			}
			case 0x1: {
				Ta = string("2D");
				Tb = string("4S");
				break;
			}
		}
		auto sv = (Vector128<float>) (state->V[rn]);
		switch(size) {
			case 0x0: {
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x4] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x0])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x5] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x1])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x6] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x2])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x7] = (short) ((short) ((float) (reinterpret_cast<Vector128<float>>(sv)[0x3])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) ((float) ((double) (reinterpret_cast<Vector128<double>>(sv)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) ((float) ((double) (reinterpret_cast<Vector128<double>>(sv)[0x1])));
				break;
			}
		}
		return true;
	}
	insn_78:
	/* FCVTPS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E280000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((int) ((int) ((float) (ceilf((float) (state->V[rn][0]))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (long) ((long) ((float) (ceilf((float) (state->V[rn][0])))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((int) ((int) ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (long) ((long) ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_79:
	/* FCVTPU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E290000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((float) (ceilf((float) (state->V[rn][0]))))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((float) (ceilf((float) (state->V[rn][0])))))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((double) (ceil((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_80:
	/* FCVTZS-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E180000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_432) -> string { switch(temp_432) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch((byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))))) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((float) (state->V[rn][0]), (int) (fbits))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((float) (state->V[rn][0]), (int) (fbits)));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_81:
	/* FCVTZS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E380000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((float) (state->V[rn][0]))))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((float) (state->V[rn][0])))));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) ((int) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_82:
	/* FCVTZU-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E190000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_433) -> string { switch(temp_433) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch((byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))))) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((float) (state->V[rn][0]), (int) (fbits))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((float) (state->V[rn][0]), (int) (fbits)));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (FloatToFixed32((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) (FloatToFixed64((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]), (int) (fbits)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_83:
	/* FCVTZU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E390000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0x7: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x0: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0x4: {
				r1 = string("X");
				r2 = string("S");
				break;
			}
			case 0x1: {
				r1 = string("W");
				r2 = string("D");
				break;
			}
			case 0x5: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((float) (state->V[rn][0]))));
				break;
			}
			case 0x4: {
				state->X[(int) rd] = (ulong) ((ulong) ((float) (state->V[rn][0])));
				break;
			}
			case 0x1: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))));
				break;
			}
			case 0x5: {
				state->X[(int) rd] = (ulong) ((ulong) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_84:
	/* FDIV-scalar */
	if((inst & 0xFF20FC00U) == 0x1E201800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_434) -> string { switch(temp_434) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x3: {
				throw "Not implemented";
				break;
			}
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) / ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) / ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_85:
	/* FDIV-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_435) -> string { switch(temp_435) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) / ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) / ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) / reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_86:
	/* FMADD */
	if((inst & 0xFF208000U) == 0x1F000000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_436) -> string { switch(temp_436) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))))) + ((float) (float) ((float) (state->V[ra][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))) + ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[ra])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_87:
	/* FMAX-scalar */
	if((inst & 0xFF20FC00U) == 0x1E204800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_437) -> string { switch(temp_437) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_88:
	/* FMAXNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E206800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_438) -> string { switch(temp_438) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) > (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_89:
	/* FMIN-scalar */
	if((inst & 0xFF20FC00U) == 0x1E205800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_439) -> string { switch(temp_439) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_90:
	/* FMINNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E207800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_440) -> string { switch(temp_440) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = (float) (state->V[rn][0]);
				auto b = (float) (state->V[rm][0]);
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				auto a = (double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]);
				auto b = (double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]);
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) (((a) < (b)) ? 1U : 0U) != 0) ? (a) : (b)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_91:
	/* FMLA-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F801000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_441) -> string { switch(temp_441) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_442) -> uint { switch(temp_442) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rd])) + reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<double>) {}))))))));
		} else {
			state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rd])) + ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<float>) {}))))));
		}
		return true;
	}
	insn_92:
	/* FMLA-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_443) -> string { switch(temp_443) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rd])) + reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm])))))));
		} else {
			state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rd])) + ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])))));
		}
		return true;
	}
	insn_93:
	/* FMOV-general */
	if((inst & 0x7F36FC00U) == 0x1E260000U) {
		auto sf = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto mode = (inst >> 19) & 0x1U;
		auto ropc = (inst >> 16) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto opc = (byte) ((byte) (((byte) (((byte) (ropc)) << 0)) | ((byte) (((byte) ((byte) ((byte) (0x3)))) << 1))));
		auto tf = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) ((byte) ((byte) (mode)))) << 3)))) | ((byte) (((byte) (type)) << 5)))) | ((byte) (((byte) (sf)) << 7))));
		auto r1 = string("");
		auto r2 = string("");
		switch(tf) {
			case 0x66: {
				r1 = string("W");
				r2 = string("H");
				break;
			}
			case 0xE6: {
				r1 = string("X");
				r2 = string("H");
				break;
			}
			case 0x67: {
				r1 = string("H");
				r2 = string("W");
				break;
			}
			case 0x7: {
				r1 = string("S");
				r2 = string("W");
				break;
			}
			case 0x6: {
				r1 = string("W");
				r2 = string("S");
				break;
			}
			case 0xE7: {
				r1 = string("H");
				r2 = string("X");
				break;
			}
			case 0xA7: {
				r1 = string("D");
				r2 = string("X");
				break;
			}
			case 0xCF: {
				r1 = string("V");
				r2 = string("X");
				break;
			}
			case 0xCE: {
				r1 = string("X");
				r2 = string("V");
				break;
			}
			case 0xA6: {
				r1 = string("X");
				r2 = string("D");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		auto index1 = (string) (((bool) (((r1) == (string("V"))) ? 1U : 0U) != 0) ? (string(".D[1]")) : (string("")));
		auto index2 = (string) (((bool) (((r2) == (string("V"))) ? 1U : 0U) != 0) ? (string(".D[1]")) : (string("")));
		switch(tf) {
			case 0x66: {
				state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0]))));
				break;
			}
			case 0xE6: {
				state->X[(int) rd] = (ulong) ((ulong) ((ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rn])[0])));
				break;
			}
			case 0x67: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x7: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (Bitcast<uint, float>((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->X[(int) rd] = (ulong) (uint) ((uint) (Bitcast<float, uint>((float) (state->V[rn][0]))));
				break;
			}
			case 0xE7: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0xA7: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0 });
				break;
			}
			case 0xA6: {
				state->X[(int) rd] = (ulong) (Bitcast<double, ulong>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])));
				break;
			}
			case 0xCE: {
				state->X[(int) rd] = (ulong) (Bitcast<double, ulong>((double) (reinterpret_cast<Vector128<double>>(state->V[(byte) ((((ulong) ((byte) ((rn) << (uint) (0x1)))) | ((ulong) (0x1))))])[0])));
				break;
			}
			case 0xCF: {
				state->V[(int) ((byte) ((((ulong) ((byte) ((rd) << (uint) (0x1)))) | ((ulong) (0x1)))))] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_94:
	/* FMOV-scalar-immediate */
	if((inst & 0xFF201FE0U) == 0x1E201000U) {
		auto type = (inst >> 22) & 0x3U;
		auto imm = (inst >> 13) & 0xFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_444) -> string { switch(temp_444) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto sv = (float) (Bitcast<uint, float>((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((bool) ((bool) (0x0)))) << 0)) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 1)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 2)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 3)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 4)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 5)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 6)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 7)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 8)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 9)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 10)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 11)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 12)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 13)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 14)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 15)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 16)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 17)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 18)))))) << 0)) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 19)))) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 23)))) | ((uint) (((uint) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))))) << 25)))) | ((uint) (((uint) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 30)))) | ((uint) (((uint) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 31))))));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { sv, 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 0)) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 1)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 2)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 3)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 4)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 5)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 6)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 7)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 8)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 9)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 10)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 11)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 12)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 13)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 14)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 15)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 16)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 17)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 18)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 19)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 20)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 21)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 22)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 23)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 24)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 25)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 26)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 27)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 28)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 29)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 30)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 31)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 32)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 33)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 34)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 35)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 36)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 37)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 38)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 39)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 40)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 41)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 42)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 43)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 44)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 45)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 46)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 47)))))) << 0)) | ((ulong) (((ulong) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 48)))) | ((ulong) (((ulong) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 52)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 5)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 6)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 7)))))) << 54)))) | ((ulong) (((ulong) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 62)))) | ((ulong) (((ulong) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 63)))))), 0 });
				break;
			}
		}
		return true;
	}
	insn_95:
	/* FMOV-vector-immediate-single */
	if((inst & 0xBFF8FC00U) == 0x0F00F400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
		auto sv = (float) (Bitcast<uint, float>((uint) ((((uint) ((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((uint) ((uint) (0x0)))) << 0)) | ((uint) (((uint) (h)) << 19)))) | ((uint) (((uint) (g)) << 20)))) | ((uint) (((uint) (f)) << 21)))) | ((uint) (((uint) (e)) << 22)))) | ((uint) (((uint) (d)) << 23)))) | ((uint) (((uint) (c)) << 24)))) | ((uint) (((uint) (b)) << 25)))) | ((uint) (((uint) (b)) << 26)))) | ((uint) (((uint) (b)) << 27)))) | ((uint) (((uint) (b)) << 28)))) | ((uint) (((uint) (b)) << 29)))) | ((uint) (((uint) (b)) << 30)))) | ((uint) (((uint) (a)) << 31)))))) ^ ((uint) ((uint) (((uint) ((uint) (0x1))) << (uint) (0x1E))))))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>((sv) - (Vector128<float>) {}));
		if((Q) != 0) {
			state->V[rd] = avec;
		} else {
			state->V[rd] = (Vector128<float>) (avec);
		}
		return true;
	}
	insn_96:
	/* FMOV-vector-immediate-double */
	if((inst & 0xFFF8FC00U) == 0x6F00F400U) {
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto sv = (double) (Bitcast<ulong, double>((ulong) ((((ulong) ((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ulong) ((ulong) (0x0)))) << 0)) | ((ulong) (((ulong) (h)) << 48)))) | ((ulong) (((ulong) (g)) << 49)))) | ((ulong) (((ulong) (f)) << 50)))) | ((ulong) (((ulong) (e)) << 51)))) | ((ulong) (((ulong) (d)) << 52)))) | ((ulong) (((ulong) (c)) << 53)))) | ((ulong) (((ulong) (b)) << 54)))) | ((ulong) (((ulong) (b)) << 55)))) | ((ulong) (((ulong) (b)) << 56)))) | ((ulong) (((ulong) (b)) << 57)))) | ((ulong) (((ulong) (b)) << 58)))) | ((ulong) (((ulong) (b)) << 59)))) | ((ulong) (((ulong) (b)) << 60)))) | ((ulong) (((ulong) (b)) << 61)))) | ((ulong) (((ulong) (b)) << 62)))) | ((ulong) (((ulong) (a)) << 63)))))) ^ ((ulong) ((ulong) (((ulong) ((ulong) (0x1))) << (uint) (0x3E))))))));
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>((sv) - (Vector128<double>) {}));
		return true;
	}
	insn_97:
	/* FMSUB */
	if((inst & 0xFF208000U) == 0x1F008000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_445) -> string { switch(temp_445) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[ra][0]))) - ((float) (float) ((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0]))))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (float) ((float) (state->V[ra][0]))) - ((double) (double) ((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0]))))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_98:
	/* FMUL-by-element-scalar-spdp */
	if((inst & 0xFF80F400U) == 0x5F809000U) {
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_446) -> uint { switch(temp_446) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[index])))), 0 });
		} else {
			state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[index])))), 0, 0, 0 };
		}
		return true;
	}
	insn_99:
	/* FMUL-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F809000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_447) -> string { switch(temp_447) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_448) -> uint { switch(temp_448) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<double>) {})))));
		} else {
			state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rm]))[index])) - (Vector128<float>) {}))));
		}
		return true;
	}
	insn_100:
	/* FMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E200800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_449) -> string { switch(temp_449) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_101:
	/* FMUL-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_450) -> string { switch(temp_450) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_102:
	/* FNEG-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E214000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_451) -> string { switch(temp_451) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (-((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (-((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_103:
	/* FNEG-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_452) -> string { switch(temp_452) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto sv = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (-((float) (reinterpret_cast<Vector128<float>>(sv)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (-((float) (reinterpret_cast<Vector128<float>>(sv)[0x1])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (-((float) (reinterpret_cast<Vector128<float>>(sv)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (-((float) (reinterpret_cast<Vector128<float>>(sv)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (-((float) (reinterpret_cast<Vector128<float>>(sv)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (-((float) (reinterpret_cast<Vector128<float>>(sv)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (-((double) (reinterpret_cast<Vector128<double>>(sv)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (-((double) (reinterpret_cast<Vector128<double>>(sv)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_104:
	/* FNMADD */
	if((inst & 0xFF208000U) == 0x1F200000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_453) -> string { switch(temp_453) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (-((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))))))) - ((float) (float) ((float) (state->V[ra][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (-((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))))) - ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[ra])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_105:
	/* FNMSUB */
	if((inst & 0xFF208000U) == 0x1F208000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_454) -> string { switch(temp_454) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))))) - ((float) (float) ((float) (state->V[ra][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))) - ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[ra])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_106:
	/* FNMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E208800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_455) -> string { switch(temp_455) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (-((float) (((float) (float) ((float) (state->V[rn][0]))) * ((float) (float) ((float) (state->V[rm][0])))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (-((double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) * ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_107:
	/* FRINTA-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E264000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_456) -> string { switch(temp_456) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) ((((float) (state->V[rn][0])) < (0x0)) ? 1U : 0U) != 0) ? ((float) (ceilf(((float) (state->V[rn][0])) - 0.5f))) : ((float) (floorf(((float) (state->V[rn][0])) + 0.5f)))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) < (0x0)) ? 1U : 0U) != 0) ? ((double) (ceil(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) - 0.5))) : ((double) (floor(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) + 0.5)))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_108:
	/* FRINTI-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E27C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_457) -> string { switch(temp_457) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (roundf((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (round((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_109:
	/* FRINTM-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E254000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_458) -> string { switch(temp_458) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (ceilf(((float) (state->V[rn][0])) - 0.5f)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (ceil(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) - 0.5)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_110:
	/* FRINTP-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E24C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_459) -> string { switch(temp_459) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (floorf(((float) (state->V[rn][0])) + 0.5f)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (floor(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) + 0.5)), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_111:
	/* FRINTX-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E274000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_460) -> string { switch(temp_460) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (roundf((float) (state->V[rn][0]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (round((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_112:
	/* FRINTZ-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E25C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_461) -> string { switch(temp_461) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((bool) ((((float) (state->V[rn][0])) < (0x0)) ? 1U : 0U) != 0) ? ((float) (floorf(((float) (state->V[rn][0])) + 0.5f))) : ((float) (ceilf(((float) (state->V[rn][0])) - 0.5f)))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((bool) ((((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) < (0x0)) ? 1U : 0U) != 0) ? ((double) (floor(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) + 0.5))) : ((double) (ceil(((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])) - 0.5)))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_113:
	/* FRSQRTE-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_462) -> string { switch(temp_462) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		state->V[rd] = (Vector128<float>) (([=](auto temp_463) -> Vector128<float> { switch(temp_463) { case 0x0: return (Vector128<float>) (VectorFrsqrte((Vector128<float>) (state->V[rn]), 0x20, 0x2)); case 0x1: return (Vector128<float>) (VectorFrsqrte((Vector128<float>) (state->V[rn]), 0x20, 0x4)); case 0x3: return (Vector128<float>) (VectorFrsqrte((Vector128<float>) (state->V[rn]), 0x40, 0x2)); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return true;
	}
	insn_114:
	/* FRSQRTS-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_464) -> string { switch(temp_464) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x3))) - (Vector128<float>) {}))) - ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])))))) / ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x2))) - (Vector128<float>) {})))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x3))) - (Vector128<float>) {}))) - ((Vector128<float>) (((Vector128<float>) (state->V[rn])) * ((Vector128<float>) (state->V[rm])))))) / ((Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) ((float) (0x2))) - (Vector128<float>) {}))));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) ((double) (0x3))) - (Vector128<double>) {}))) - reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) * reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm])))))))) / reinterpret_cast<Vector128<double>>((Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) ((double) (0x2))) - (Vector128<double>) {})))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_115:
	/* FSQRT-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E21C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_465) -> string { switch(temp_465) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) sqrt((double) ((float) (state->V[rn][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) sqrt((double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_116:
	/* FSUB-scalar */
	if((inst & 0xFF20FC00U) == 0x1E203800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_466) -> string { switch(temp_466) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (((float) (float) ((float) (state->V[rn][0]))) - ((float) (float) ((float) (state->V[rm][0])))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))) - ((double) (double) ((double) (reinterpret_cast<Vector128<double>>(state->V[rm])[0])))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_117:
	/* FSUB-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_467) -> string { switch(temp_467) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[rd] = (Vector128<float>) ((Vector128<float>) (((Vector128<float>) (state->V[rn])) - ((Vector128<float>) (state->V[rm]))));
				break;
			}
			case 0x1: {
				state->V[rd] = (Vector128<float>) (((Vector128<float>) (state->V[rn])) - ((Vector128<float>) (state->V[rm])));
				break;
			}
			case 0x3: {
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn])) - reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rm]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_118:
	/* INS-general */
	if((inst & 0xFFE0FC00U) == 0x4E001C00U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index = (uint) ((uint) (0x0));
		auto r = string("W");
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index = (byte) ((imm) >> (uint) (0x1));
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index = (byte) ((imm) >> (uint) (0x2));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index = (byte) ((imm) >> (uint) (0x3));
				} else {
					ts = string("D");
					index = (byte) ((imm) >> (uint) (0x4));
					r = string("X");
				}
			}
		}
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][index] = (byte) ((byte) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][index] = (ushort) ((ushort) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][index] = (float) (Bitcast<uint, float>((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
				} else {
					reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][index] = (double) (Bitcast<ulong, double>((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
				}
			}
		}
		return true;
	}
	insn_119:
	/* INS-vector */
	if((inst & 0xFFE08400U) == 0x6E000400U) {
		auto imm5 = (inst >> 16) & 0x1FU;
		auto imm4 = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index1 = (uint) ((uint) (0x0));
		auto index2 = (uint) ((uint) (0x0));
		if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index1 = (byte) ((imm5) >> (uint) (0x1));
			index2 = imm4;
		} else {
			if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index1 = (byte) ((imm5) >> (uint) (0x2));
				index2 = (byte) ((imm4) >> (uint) (0x1));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index1 = (byte) ((imm5) >> (uint) (0x3));
					index2 = (byte) ((imm4) >> (uint) (0x2));
				} else {
					ts = string("D");
					index1 = (byte) ((imm5) >> (uint) (0x4));
					index2 = (byte) ((imm4) >> (uint) (0x3));
				}
			}
		}
		if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][index1] = (byte) (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn]))[index2]);
		} else {
			if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][index1] = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[index2]);
			} else {
				if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][index1] = (float) (reinterpret_cast<Vector128<float>>((Vector128<float>) (state->V[rn]))[index2]);
				} else {
					reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][index1] = (double) (reinterpret_cast<Vector128<double>>((Vector128<float>) (state->V[rn]))[index2]);
				}
			}
		}
		return true;
	}
	insn_120:
	/* LD1-single-no-offset */
	if((inst & 0xBFFF2000U) == 0x0D400000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto opc = (inst >> 14) & 0x3U;
		auto S = (inst >> 12) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((opc) != (0x3)) ? 1U : 0U)))
			goto insn_121;
		auto t = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("B")) : ((string) (((bool) ((((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) ((((byte) ((((ulong) (size)) & ((ulong) (0x1))))) == (0x0)) ? 1U : 0U))))) != 0) ? (string("H")) : ((string) (((bool) (((opc) == (0x2)) ? 1U : 0U) != 0) ? ((string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : ((string) (((bool) ((((bool) ((bool) (((size) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) (((S) == (0x0)) ? 1U : 0U))))) != 0) ? (string("D")) : throw "Not implemented")))) : throw "Not implemented")))));
		auto index = (uint) (([=](auto temp_468) -> uint { switch(temp_468) { case 0x0: return (uint) ((uint) ((byte) ((byte) (((byte) (byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (S)) << 2)))) | ((byte) (((byte) (Q)) << 3)))))); case 0x1: return (uint) (((uint) ((uint) ((byte) ((byte) (((byte) (byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (S)) << 2)))) | ((byte) (((byte) (Q)) << 3))))))) >> (uint) (0x1)); case 0x2: return (uint) (((bool) ((((byte) ((((ulong) (size)) & ((ulong) (0x1))))) == (0x0)) ? 1U : 0U) != 0) ? ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (S)) << 0)) | ((byte) (((byte) (Q)) << 1))))))) : (Q)); default: throw "Not implemented"; } })(opc));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch(opc) {
			case 0x0: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][index] = (byte) (*(byte*) (address));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][index] = (ushort) (*(ushort*) (address));
				break;
			}
			case 0x2: {
				if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][index] = (float) (*(float*) (address));
				} else {
					reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][index] = (double) (*(double*) (address));
				}
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_121:
	/* LD1-multi-one-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C407000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_469) -> string { switch(temp_469) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) (address));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x1)))));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x2)))));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x3)))));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x5)))));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x6)))));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x7)))));
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x9)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xA)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xB)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xC)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xD)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xE)))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xF)))));
				}
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) (address));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x2)))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x6)))));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xA)))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xC)))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xE)))));
				}
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rt)]))[0][0x0] = (uint) (*(uint*) (address));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rt)]))[0][0x1] = (uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))));
				if((Q) != 0) {
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rt)]))[0][0x2] = (uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rt)]))[0][0x3] = (uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0xC)))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rt)]))[0][0x0] = (ulong) (*(ulong*) (address));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rt)]))[0][0x1] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
				}
				break;
			}
		}
		return true;
	}
	insn_122:
	/* LD1R-single-no-offset */
	if((inst & 0xBFFFF000U) == 0x0D40C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_470) -> string { switch(temp_470) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto sv = (Vector128<float>) (([=](auto temp_471) -> Vector128<float> { switch(temp_471) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) (*(byte*) (address))) - (Vector128<byte>) {})); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) (*(ushort*) (address))) - (Vector128<ushort>) {})); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (*(float*) (address))) - (Vector128<float>) {})); default: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (*(double*) (address))) - (Vector128<double>) {})); } })(size));
		state->V[rt] = (Vector128<float>) ((Q != 0) ? (sv) : ((Vector128<float>) (sv)));
		return true;
	}
	insn_123:
	/* LD1R-single-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0DC0C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_124;
		auto t = (string) (([=](auto temp_472) -> string { switch(temp_472) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto imm = (long) (([=](auto temp_473) -> long { switch(temp_473) { case 0x0: return 0x1; case 0x1: return 0x2; case 0x2: return 0x4; default: return 0x8; } })(size));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto sv = (Vector128<float>) (([=](auto temp_474) -> Vector128<float> { switch(temp_474) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) (*(byte*) (address))) - (Vector128<byte>) {})); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) (*(ushort*) (address))) - (Vector128<ushort>) {})); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (*(float*) (address))) - (Vector128<float>) {})); default: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (*(double*) (address))) - (Vector128<double>) {})); } })(size));
		state->V[rt] = (Vector128<float>) ((Q != 0) ? (sv) : ((Vector128<float>) (sv)));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	insn_124:
	/* LD1R-single-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0DC0C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_125;
		auto t = (string) (([=](auto temp_475) -> string { switch(temp_475) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto sv = (Vector128<float>) (([=](auto temp_476) -> Vector128<float> { switch(temp_476) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) (*(byte*) (address))) - (Vector128<byte>) {})); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) (*(ushort*) (address))) - (Vector128<ushort>) {})); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (*(float*) (address))) - (Vector128<float>) {})); default: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(((double) (*(double*) (address))) - (Vector128<double>) {})); } })(size));
		state->V[rt] = (Vector128<float>) ((Q != 0) ? (sv) : ((Vector128<float>) (sv)));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_125:
	/* LD2-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C408000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto T = (string) (([=](auto temp_477) -> string { switch(temp_477) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				break;
			}
		}
		return true;
	}
	insn_126:
	/* LD2-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0CC08000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto imm = (byte) ((byte) ((long) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_127;
		auto T = (string) (([=](auto temp_478) -> string { switch(temp_478) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		return true;
	}
	insn_127:
	/* LD2-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0CC08000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_128;
		auto T = (string) (([=](auto temp_479) -> string { switch(temp_479) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_128:
	/* LD3-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C404000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto T = (string) (([=](auto temp_480) -> string { switch(temp_480) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt3] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
				break;
			}
		}
		return true;
	}
	insn_129:
	/* LD3-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0CC04000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto imm = (byte) ((byte) ((long) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_130;
		auto T = (string) (([=](auto temp_481) -> string { switch(temp_481) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt3] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		return true;
	}
	insn_130:
	/* LD3-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0CC04000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_131;
		auto T = (string) (([=](auto temp_482) -> string { switch(temp_482) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt3] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_131:
	/* LD4-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C400000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto rt4 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x3))))) % ((ulong) (long) (0x20)));
		auto T = (string) (([=](auto temp_483) -> string { switch(temp_483) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt3] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt4] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x31))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x33))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x35))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x37))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x39))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt4)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt4)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
				break;
			}
		}
		return true;
	}
	insn_132:
	/* LD4-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0CC00000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto rt4 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x3))))) % ((ulong) (long) (0x20)));
		auto imm = (byte) ((byte) ((long) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_133;
		auto T = (string) (([=](auto temp_484) -> string { switch(temp_484) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt3] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt4] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x31))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x33))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x35))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x37))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x39))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt4)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt4)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		return true;
	}
	insn_133:
	/* LD4-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0CC00000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto rt4 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x3))))) % ((ulong) (long) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_134;
		auto T = (string) (([=](auto temp_485) -> string { switch(temp_485) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->V[rt] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt2] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt3] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		state->V[rt4] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x8] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x9] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xA] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xB] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x31))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xC] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x33))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x35))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xD] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x37))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x39))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xE] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0xF] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3F))))));
				} else {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x0] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x1] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x2] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x3] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x4] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x5] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x6] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt2)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt3)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rt4)]))[0][0x7] = (byte) (*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))));
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x4] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x5] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x6] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x7] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))));
				} else {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x0] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x1] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x2] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt2)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt3)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rt4)]))[0][0x3] = (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))));
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x2] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x3] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))));
				} else {
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x0] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt2)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt3)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
					reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rt4)]))[0][0x1] = (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt4)]))[0][0x0] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt2)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt3)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rt4)]))[0][0x1] = (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_134:
	/* LDAR */
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			state->X[(int) rt] = (ulong) (uint) ((uint) (*(uint*) (address)));
		} else {
			auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
			state->X[(int) rt] = (ulong) (*(ulong*) (address));
		}
		return true;
	}
	insn_135:
	/* LDARB */
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (*(byte*) (address))));
		return true;
	}
	insn_136:
	/* LDARH */
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) (address))));
		return true;
	}
	insn_137:
	/* LDAXB */
	if((inst & 0xBFFFFC00U) == 0x885FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (state->Exclusive32 = *(uint*) (address)));
		} else {
			state->X[(int) rt] = (ulong) (state->Exclusive64 = *(ulong*) (address));
		}
		return true;
	}
	insn_138:
	/* LDAXRB */
	if((inst & 0xFFFFFC00U) == 0x085FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (state->Exclusive8 = *(byte*) (address))));
		return true;
	}
	insn_139:
	/* LDAXRH */
	if((inst & 0xFFFFFC00U) == 0x485FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (state->Exclusive16 = *(ushort*) (address))));
		return true;
	}
	insn_140:
	/* LDP-immediate-postindex */
	if((inst & 0x7FC00000U) == 0x28C00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt1] = (ulong) (uint) ((uint) (*(uint*) (address)));
			state->X[(int) rt2] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))));
		} else {
			state->X[(int) rt1] = (ulong) (*(ulong*) (address));
			state->X[(int) rt2] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_141:
	/* LDP-immediate-signed-offset */
	if((inst & 0x7FC00000U) == 0x29400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt1] = (ulong) (uint) ((uint) (*(uint*) (address)));
			state->X[(int) rt2] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))));
		} else {
			state->X[(int) rt1] = (ulong) (*(ulong*) (address));
			state->X[(int) rt2] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))));
		}
		return true;
	}
	insn_142:
	/* LDP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2CC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_486) -> string { switch(temp_486) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_487) -> long { switch(temp_487) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch(opc) {
			case 0x0: {
				state->V[(int) (rt1)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				state->V[(int) (rt2)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt1)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				state->V[(int) (rt2)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8))))), 0 });
				break;
			}
			default: {
				state->V[rt1] = (Vector128<float>) (LoadVector(address));
				state->V[rt2] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))));
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_143:
	/* LDP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2DC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_488) -> string { switch(temp_488) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_489) -> long { switch(temp_489) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		switch(opc) {
			case 0x0: {
				state->V[(int) (rt1)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				state->V[(int) (rt2)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt1)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				state->V[(int) (rt2)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8))))), 0 });
				break;
			}
			default: {
				state->V[rt1] = (Vector128<float>) (LoadVector(address));
				state->V[rt2] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))));
				break;
			}
		}
		return true;
	}
	insn_144:
	/* LDP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D400000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_490) -> string { switch(temp_490) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_491) -> long { switch(temp_491) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch(opc) {
			case 0x0: {
				state->V[(int) (rt1)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				state->V[(int) (rt2)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt1)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				state->V[(int) (rt2)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8))))), 0 });
				break;
			}
			default: {
				state->V[rt1] = (Vector128<float>) (LoadVector(address));
				state->V[rt2] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10)))));
				break;
			}
		}
		return true;
	}
	insn_145:
	/* LDPSW-immediate-signed-offset */
	if((inst & 0xFFC00000U) == 0x69400000U) {
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) (0x2));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		state->X[(int) rt1] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (address)), 32))));
		state->X[(int) rt2] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4))))), 32))));
		return true;
	}
	insn_146:
	/* LDR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8400C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) (address)));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) (address));
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_147:
	/* LDR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8400400U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		return true;
	}
	insn_148:
	/* LDR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))));
		}
		return true;
	}
	insn_149:
	/* LDR-literal */
	if((inst & 0xBF000000U) == 0x18000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (long) (SignExt<long>((uint) ((uint) ((uint) ((rawimm) << (uint) (0x2)))), 21));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (offset)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (*(uint*) (addr)));
		} else {
			state->X[(int) rt] = (ulong) (*(ulong*) (addr));
		}
		return true;
	}
	insn_150:
	/* LDR-simd-immediate-postindex */
	if((inst & 0x3F600C00U) == 0x3C400400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_492) -> string { switch(temp_492) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x2: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (*(ushort*) (address)), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_151:
	/* LDR-simd-immediate-preindex */
	if((inst & 0x3F600C00U) == 0x3C400C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_493) -> string { switch(temp_493) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x2: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (*(ushort*) (address)), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_152:
	/* LDR-simd-immediate-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto ropc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto opc = (byte) ((byte) (((byte) (((byte) ((bool) ((bool) (0x1)))) << 0)) | ((byte) (((byte) (ropc)) << 1))));
		auto m = (byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_494) -> string { switch(temp_494) { case 0x1: return string("B"); case 0x5: return string("H"); case 0x9: return string("S"); case 0xD: return string("D"); default: return string("Q"); } })(m));
		auto imm = (uint) (((uint) ((uint) (rawimm))) << (uint) ((long) (([=](auto temp_495) -> long { switch(temp_495) { case 0x1: return 0x0; case 0x5: return 0x1; case 0x9: return 0x2; case 0xD: return 0x3; default: return 0x4; } })(m))));
		switch(m) {
			case 0x1: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x5: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x9: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0, 0, 0 };
				break;
			}
			case 0xD: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm))))), 0 });
				break;
			}
			default: {
				state->V[rt] = (Vector128<float>) (LoadVector((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (uint) (imm)))));
				break;
			}
		}
		return true;
	}
	insn_153:
	/* LDR-simd-literal */
	if((inst & 0x3F000000U) == 0x1C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_496) -> string { switch(temp_496) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(size));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) (((uint) (((uint) ((byte) ((byte) (0x0)))) << 0)) | ((uint) (((uint) (imm)) << 2)))), 21)))));
		switch(size) {
			case 0x0: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (addr)), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (addr)), 0 });
				break;
			}
			case 0x2: {
				state->V[rt] = (Vector128<float>) (LoadVector(addr));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_154:
	/* LDR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C600800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (string("Q")) : ((string) (([=](auto temp_497) -> string { switch(temp_497) { case 0x0: return string("B"); case 0x1: return string("H"); case 0x2: return string("S"); case 0x3: return string("D"); default: throw "Not implemented"; } })(size))));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (([=](auto temp_498) -> string { switch(temp_498) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto amount = (ulong) (((ulong) (bool) (scale)) * ((ulong) (long) ((long) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (0x4) : ((long) (([=](auto temp_499) -> long { switch(temp_499) { case 0x0: return 0x1; case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: throw "Not implemented"; } })(size)))))));
		auto offset = (ulong) (((ulong) (([=](auto temp_500) -> ulong { switch(temp_500) { case 0x2: return (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))); case 0x3: return (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32)))); case 0x7: return (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]); default: throw "Not implemented"; } })(option))) << (uint) (amount));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_155:
	/* LDR-register */
	if((inst & 0xBFE00C00U) == 0xB8600800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_501) -> string { switch(temp_501) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))));
		} else {
			state->X[(int) rt] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))));
		}
		return true;
	}
	insn_156:
	/* LDRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((byte) (*(byte*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))))));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		return true;
	}
	insn_157:
	/* LDRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((byte) (*(byte*) (address)))));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_158:
	/* LDRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39400000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))))));
		return true;
	}
	insn_159:
	/* LDRB-register */
	if((inst & 0xFFE00C00U) == 0x38600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_502) -> string { switch(temp_502) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		state->X[(int) rt] = (ulong) (uint) ((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))));
		return true;
	}
	insn_160:
	/* LDRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) (address))));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	insn_161:
	/* LDRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) (address))));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_162:
	/* LDRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79400000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))))));
		return true;
	}
	insn_163:
	/* LDRH-register */
	if((inst & 0xFFE00C00U) == 0x78600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_503) -> string { switch(temp_503) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		state->X[(int) rt] = (ulong) (uint) ((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))));
		return true;
	}
	insn_164:
	/* LDRSB-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x38800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) (address)), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) (address)), 8))));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	insn_165:
	/* LDRSB-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x38800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) (address)), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) (address)), 8))));
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_166:
	/* LDRSB-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x39800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 8))));
		}
		return true;
	}
	insn_167:
	/* LDRSB-register */
	if((inst & 0xFFA00C00U) == 0x38A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_504) -> string { switch(temp_504) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 8)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 8))));
		}
		return true;
	}
	insn_168:
	/* LDRSH-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x78800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) (address)), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) (address)), 16))));
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	insn_169:
	/* LDRSH-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x78800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) (address)), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) (address)), 16))));
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_170:
	/* LDRSH-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x79800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 16))));
		}
		return true;
	}
	insn_171:
	/* LDRSH-register */
	if((inst & 0xFFA00C00U) == 0x78A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_505) -> string { switch(temp_505) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 16)))));
		} else {
			state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 16))));
		}
		return true;
	}
	insn_172:
	/* LDRSW-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0xB8800400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (address)), 32))));
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (imm)));
		return true;
	}
	insn_173:
	/* LDRSW-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0xB8800C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (address)), 32))));
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_174:
	/* LDRSW-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0xB9800000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x2));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm))))), 32))));
		return true;
	}
	insn_175:
	/* LDRSW-literal */
	if((inst & 0xFF000000U) == 0x98000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) (((uint) (((uint) ((byte) ((byte) (0x0)))) << 0)) | ((uint) (((uint) (imm)) << 2)))), 21)))));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) (addr)), 32))));
		return true;
	}
	insn_176:
	/* LDRSW-register */
	if((inst & 0xFFE00C00U) == 0xB8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0x2));
		auto extend = (string) (([=](auto temp_506) -> string { switch(temp_506) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset))))), 32))));
		return true;
	}
	insn_177:
	/* LDUR */
	if((inst & 0xBFE00C00U) == 0xB8400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))));
		} else {
			state->X[(int) rd] = (ulong) (*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)))));
		}
		return true;
	}
	insn_178:
	/* LDURB */
	if((inst & 0xFFE00C00U) == 0x38400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rd] = (ulong) ((ulong) ((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)))))));
		return true;
	}
	insn_179:
	/* LDURH */
	if((inst & 0xFFE00C00U) == 0x78400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rd] = (ulong) ((ulong) ((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)))))));
		return true;
	}
	insn_180:
	/* LDURSB */
	if((inst & 0xFFA00C00U) == 0x38800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 8)))));
		} else {
			state->X[(int) rd] = (ulong) ((ulong) ((long) (SignExt<long>((byte) (*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 8))));
		}
		return true;
	}
	insn_181:
	/* LDURSH */
	if((inst & 0xFFA00C00U) == 0x78800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((uint) ((int) (SignExt<int>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 16)))));
		} else {
			state->X[(int) rd] = (ulong) ((ulong) ((long) (SignExt<long>((ushort) (*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 16))));
		}
		return true;
	}
	insn_182:
	/* LDURSW */
	if((inst & 0xFFE00C00U) == 0xB8800000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		state->X[(int) rt] = (ulong) ((ulong) ((long) (SignExt<long>((uint) (*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm))))), 32))));
		return true;
	}
	insn_183:
	/* LDUR-simd */
	if((inst & 0x3F600C00U) == 0x3C400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_507) -> string { switch(temp_507) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (imm)));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<byte>) { (byte) (*(byte*) (address)), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rt)] = (Vector128<float>) { (float) (*(float*) (address)), 0, 0, 0 };
				break;
			}
			case 0x6: {
				state->V[(int) (rt)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (*(double*) (address)), 0 });
				break;
			}
			case 0x1: {
				state->V[rt] = (Vector128<float>) (LoadVector(address));
				break;
			}
		}
		return true;
	}
	insn_184:
	/* LDXR */
	if((inst & 0xBFFFFC00U) == 0x885F7C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rt] = (ulong) (uint) ((uint) (state->Exclusive32 = *(uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))));
		} else {
			state->X[(int) rt] = (ulong) (state->Exclusive64 = *(ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
		}
		return true;
	}
	insn_185:
	/* LDXRB */
	if((inst & 0xFFFFFC00U) == 0x085F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) ((ulong) ((byte) (state->Exclusive8 = *(byte*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])))));
		return true;
	}
	insn_186:
	/* LDXRH */
	if((inst & 0xFFFFFC00U) == 0x485F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) ((ulong) ((ushort) (state->Exclusive16 = *(ushort*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])))));
		return true;
	}
	insn_187:
	/* LSL-register */
	if((inst & 0x7FE0FC00U) == 0x1AC02000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) << (uint) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) << (uint) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))));
		}
		return true;
	}
	insn_188:
	/* LSRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) >> (uint) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) >> (uint) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))));
		}
		return true;
	}
	insn_189:
	/* MADD */
	if((inst & 0x7FE08000U) == 0x1B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) * ((uint) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))) + ((uint) (uint) ((uint) ((ra) == 31 ? 0U : (uint) state->X[(int) ra])))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) * ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))))) + ((ulong) (ulong) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))));
		}
		return true;
	}
	insn_190:
	/* MOVI-scalar-64bit */
	if((inst & 0xFFF8FC00U) == 0x2F00E400U) {
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm8a = (byte) ((byte) ((long) ((a != 0) ? (0xFF) : (0x0))));
		auto imm8b = (byte) ((byte) ((long) ((b != 0) ? (0xFF) : (0x0))));
		auto imm8c = (byte) ((byte) ((long) ((c != 0) ? (0xFF) : (0x0))));
		auto imm8d = (byte) ((byte) ((long) ((d != 0) ? (0xFF) : (0x0))));
		auto imm8e = (byte) ((byte) ((long) ((e != 0) ? (0xFF) : (0x0))));
		auto imm8f = (byte) ((byte) ((long) ((f != 0) ? (0xFF) : (0x0))));
		auto imm8g = (byte) ((byte) ((long) ((g != 0) ? (0xFF) : (0x0))));
		auto imm8h = (byte) ((byte) ((long) ((h != 0) ? (0xFF) : (0x0))));
		auto imm = (ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) (imm8h)) << 0)) | ((ulong) (((ulong) (imm8g)) << 8)))) | ((ulong) (((ulong) (imm8f)) << 16)))) | ((ulong) (((ulong) (imm8e)) << 24)))) | ((ulong) (((ulong) (imm8d)) << 32)))) | ((ulong) (((ulong) (imm8c)) << 40)))) | ((ulong) (((ulong) (imm8b)) << 48)))) | ((ulong) (((ulong) (imm8a)) << 56))));
		state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>(imm)), 0 });
		return true;
	}
	insn_191:
	/* MOVI-vector-8bit */
	if((inst & 0xBFF8FC00U) == 0x0F00E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (imm))) - (Vector128<byte>) {}));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (avec) : ((Vector128<float>) (avec)));
		return true;
	}
	insn_192:
	/* MOVI-vector-16bit */
	if((inst & 0xBFF8DC00U) == 0x0F008400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto cmode = (inst >> 13) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ushort) ((cmode != 0) ? ((ushort) ((ushort) ((ushort) (((ushort) ((ushort) (imm))) << (uint) (0x8))))) : ((ushort) ((ushort) (imm))))) - (Vector128<ushort>) {}));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (avec) : ((Vector128<float>) (avec)));
		return true;
	}
	insn_193:
	/* MOVI-vector-32bit */
	if((inst & 0xBFF89C00U) == 0x0F000400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto cmode = (inst >> 13) & 0x3U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
		auto amount = (long) (([=](auto temp_508) -> long { switch(temp_508) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		auto avec = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((float) (Bitcast<uint, float>((uint) (((uint) ((uint) (imm))) << (uint) (amount))))) - (Vector128<float>) {}));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (avec) : ((Vector128<float>) (avec)));
		return true;
	}
	insn_194:
	/* MOVI-Vx.2D */
	if((inst & 0xFFF8FC00U) == 0x6F00E400U) {
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (h)) << 1)))) | ((byte) (((byte) (h)) << 2)))) | ((byte) (((byte) (h)) << 3)))) | ((byte) (((byte) (h)) << 4)))) | ((byte) (((byte) (h)) << 5)))) | ((byte) (((byte) (h)) << 6)))) | ((byte) (((byte) (h)) << 7)))))) << 0)) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (g)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (g)) << 2)))) | ((byte) (((byte) (g)) << 3)))) | ((byte) (((byte) (g)) << 4)))) | ((byte) (((byte) (g)) << 5)))) | ((byte) (((byte) (g)) << 6)))) | ((byte) (((byte) (g)) << 7)))))) << 8)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (f)) << 0)) | ((byte) (((byte) (f)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (f)) << 3)))) | ((byte) (((byte) (f)) << 4)))) | ((byte) (((byte) (f)) << 5)))) | ((byte) (((byte) (f)) << 6)))) | ((byte) (((byte) (f)) << 7)))))) << 16)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (e)) << 0)) | ((byte) (((byte) (e)) << 1)))) | ((byte) (((byte) (e)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (e)) << 4)))) | ((byte) (((byte) (e)) << 5)))) | ((byte) (((byte) (e)) << 6)))) | ((byte) (((byte) (e)) << 7)))))) << 24)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (d)) << 0)) | ((byte) (((byte) (d)) << 1)))) | ((byte) (((byte) (d)) << 2)))) | ((byte) (((byte) (d)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (d)) << 5)))) | ((byte) (((byte) (d)) << 6)))) | ((byte) (((byte) (d)) << 7)))))) << 32)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (c)) << 0)) | ((byte) (((byte) (c)) << 1)))) | ((byte) (((byte) (c)) << 2)))) | ((byte) (((byte) (c)) << 3)))) | ((byte) (((byte) (c)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (c)) << 6)))) | ((byte) (((byte) (c)) << 7)))))) << 40)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (b)) << 0)) | ((byte) (((byte) (b)) << 1)))) | ((byte) (((byte) (b)) << 2)))) | ((byte) (((byte) (b)) << 3)))) | ((byte) (((byte) (b)) << 4)))) | ((byte) (((byte) (b)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (b)) << 7)))))) << 48)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (a)) << 0)) | ((byte) (((byte) (a)) << 1)))) | ((byte) (((byte) (a)) << 2)))) | ((byte) (((byte) (a)) << 3)))) | ((byte) (((byte) (a)) << 4)))) | ((byte) (((byte) (a)) << 5)))) | ((byte) (((byte) (a)) << 6)))) | ((byte) (((byte) (a)) << 7)))))) << 56))));
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>((imm) - (Vector128<ulong>) {}));
		return true;
	}
	insn_195:
	/* MOVK */
	if((inst & 0x7F800000U) == 0x72800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((((uint) ((uint) ((rd) == 31 ? 0U : (uint) state->X[(int) rd]))) & ((uint) ((uint) ((((uint) ((uint) ((uint) (-0x1)))) ^ ((uint) ((uint) (((uint) ((uint) (0xFFFF))) << (uint) (shift)))))))))))) | ((uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((((ulong) ((ulong) ((rd) == 31 ? 0UL : state->X[(int) rd]))) & ((ulong) ((ulong) ((((ulong) ((ulong) ((ulong) (-0x1)))) ^ ((ulong) ((ulong) (((ulong) ((ulong) (0xFFFF))) << (uint) (shift)))))))))))) | ((ulong) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift))))));
		}
		return true;
	}
	insn_196:
	/* MOVN */
	if((inst & 0x7F800000U) == 0x12800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (~((uint) (((uint) ((uint) (imm))) << (uint) (shift)))));
		} else {
			state->X[(int) rd] = (ulong) (~((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift))));
		}
		return true;
	}
	insn_197:
	/* MOVZ */
	if((inst & 0x7F800000U) == 0x52800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift)));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) ((ulong) (imm))) << (uint) (shift));
		}
		return true;
	}
	insn_198:
	/* MRS */
	if((inst & 0xFFF00000U) == 0xD5300000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		state->X[(int) rt] = (ulong) (SR(op0, op1, cn, cm, op2));
		return true;
	}
	insn_199:
	/* MSR-register */
	if((inst & 0xFFF00000U) == 0xD5100000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		SR(op0, op1, cn, cm, op2, (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]));
		return true;
	}
	insn_200:
	/* MSUB */
	if((inst & 0x7FE08000U) == 0x1B008000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((ra) == 31 ? 0U : (uint) state->X[(int) ra]))) - ((uint) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) * ((uint) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))) - ((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) * ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))))));
		}
		return true;
	}
	insn_201:
	/* MUL-by-element */
	if((inst & 0xBF00F400U) == 0x0F008000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto L = (inst >> 21) & 0x1U;
		auto M = (inst >> 20) & 0x1U;
		auto rv = (inst >> 16) & 0xFU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto rm = (byte) (((bool) (((size) == (0x2)) ? 1U : 0U) != 0) ? ((byte) ((byte) (((byte) (((byte) (rv)) << 0)) | ((byte) (((byte) (M)) << 4))))) : (rv));
		auto t = (string) (([=](auto temp_509) -> string { switch(temp_509) { case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto ts = (string) (([=](auto temp_510) -> string { switch(temp_510) { case 0x1: return string("H"); case 0x2: return string("S"); default: throw "Not implemented"; } })(size));
		auto index = (byte) (([=](auto temp_511) -> byte { switch(temp_511) { case 0x1: return (byte) ((byte) (((byte) (byte) (((byte) (((byte) (M)) << 0)) | ((byte) (((byte) (L)) << 1)))) | ((byte) (((byte) (H)) << 2)))); case 0x2: return (byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))); default: throw "Not implemented"; } })(size));
		auto v = (Vector128<float>) (([=](auto temp_512) -> Vector128<float> { switch(temp_512) { case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn])) * (((ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rm]))[index]))))); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn])) * (((uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rm]))[index]))))); default: throw "Not implemented"; } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	insn_202:
	/* MUL-vector */
	if((inst & 0xBF20FC00U) == 0x0E209C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_513) -> string { switch(temp_513) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto v = (Vector128<float>) (([=](auto temp_514) -> Vector128<float> { switch(temp_514) { case 0x0: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) * (reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm]))))); case 0x1: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn])) * (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rm]))))); case 0x2: return (Vector128<float>) (reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn])) * (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rm]))))); default: throw "Not implemented"; } })(size));
		state->V[rd] = (Vector128<float>) ((Q != 0) ? (v) : ((Vector128<float>) (v)));
		return true;
	}
	insn_203:
	/* NEG-vector */
	if((inst & 0xBF3FFC00U) == 0x2E20B800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_515) -> string { switch(temp_515) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x0] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x0])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x1] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x1])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x2] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x2])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x3] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x3])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x4] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x4])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x5] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x5])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x6] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x6])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x7] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x7])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x0] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x0])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x1] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x1])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x2] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x2])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x3] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x3])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x4] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x4])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x5] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x5])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x6] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x6])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x7] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x7])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x8] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x8])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0x9] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0x9])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xA] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xA])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xB] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xB])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xC] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xC])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xD] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xD])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xE] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xE])));
				reinterpret_cast<Vector128<sbyte>*>(&(state->V[(int) (rd)]))[0][0xF] = (sbyte) (-((sbyte) (reinterpret_cast<Vector128<sbyte>>(n)[0xF])));
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x0])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x1])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x2])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x0])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x1])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x2])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x3])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x4] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x4])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x5] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x5])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x6] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x6])));
				reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x7] = (short) (-((short) (reinterpret_cast<Vector128<short>>(n)[0x7])));
				break;
			}
			case 0x4: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x1])));
				break;
			}
			case 0x5: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) (-((float) (reinterpret_cast<Vector128<float>>(n)[0x3])));
				break;
			}
			case 0x7: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) (-((double) (reinterpret_cast<Vector128<double>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) (-((double) (reinterpret_cast<Vector128<double>>(n)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_204:
	/* NOP */
	if((inst & 0xFFFFFFFFU) == 0xD503201FU) {
		return true;
	}
	insn_205:
	/* ORN-shifted-register */
	if((inst & 0x7F200000U) == 0x2A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_516) -> string { switch(temp_516) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) (~((uint) (([=](auto temp_517) -> uint { switch(temp_517) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) ((ulong) (~((ulong) (([=](auto temp_518) -> ulong { switch(temp_518) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))))));
		}
		return true;
	}
	insn_206:
	/* ORR-immediate */
	if((inst & 0x7F800000U) == 0x32000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ulong) (MakeWMask(up, imms, immr, (long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) ((uint) (imm)))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) (imm))));
			else
				state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) (imm))));
		}
		return true;
	}
	insn_207:
	/* ORR-shifted-register */
	if((inst & 0x7F200000U) == 0x2A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_519) -> string { switch(temp_519) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) | ((uint) ((uint) (([=](auto temp_520) -> uint { switch(temp_520) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) | ((ulong) ((ulong) (([=](auto temp_521) -> ulong { switch(temp_521) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		}
		return true;
	}
	insn_208:
	/* ORR-simd-register */
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x0)) ? 1U : 0U) != 0) ? (string("8B")) : (string("16B")));
		if(((bool) (((rm) == (rn)) ? 1U : 0U)) != 0) {
			state->V[rd] = (Vector128<float>) (state->V[rn]);
		} else {
			auto tv = (Vector128<float>) (reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rn])) | reinterpret_cast<Vector128<byte>>((Vector128<float>) (state->V[rm])))));
			state->V[rd] = (Vector128<float>) ((Q != 0) ? (tv) : ((Vector128<float>) (tv)));
		}
		return true;
	}
	insn_209:
	/* PRFM-immediate */
	if((inst & 0xFFC00000U) == 0xF9800000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto imm5 = (inst >> 0) & 0x1FU;
		auto pimm = (ulong) (((ulong) (ushort) (imm)) * ((ulong) (long) (0x8)));
		return true;
	}
	insn_210:
	/* RBIT */
	if((inst & 0x7FFFFC00U) == 0x5AC00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (ReverseBits((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))));
		} else {
			state->X[(int) rd] = (ulong) (ReverseBits((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
		}
		return true;
	}
	insn_211:
	/* RET */
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchRegister(rn);
		return true;
	}
	insn_212:
	/* REV */
	if((inst & 0x7FFFF800U) == 0x5AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto opc = (inst >> 10) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto x = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
				state->X[(int) rd] = (ulong) (uint) ((uint) ((((((uint) ((uint) (((uint) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x18)))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))) << (uint) (0x10))))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x8))))) | ((uint) ((uint) ((((ulong) ((uint) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF)))))))));
				break;
			}
			case 0x3: {
				auto x = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
				state->X[(int) rd] = (ulong) ((((((((((ulong) ((ulong) (((ulong) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x38)))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))) << (uint) (0x30))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x28))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF))))) << (uint) (0x20))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x20)))) & ((ulong) (0xFF))))) << (uint) (0x18))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x28)))) & ((ulong) (0xFF))))) << (uint) (0x10))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x30)))) & ((ulong) (0xFF))))) << (uint) (0x8))))) | ((ulong) ((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x38)))) & ((ulong) (0xFF))))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_213:
	/* REV16 */
	if((inst & 0x7FFFFC00U) == 0x5AC00400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto x = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((((uint) ((uint) (((uint) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x8)))) | ((uint) ((uint) ((((ulong) ((uint) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x18))))) | ((uint) ((uint) (((uint) ((((ulong) ((uint) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF))))) << (uint) (0x10)))))));
		} else {
			auto x = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			state->X[(int) rd] = (ulong) ((((((((((ulong) ((ulong) (((ulong) ((((ulong) (x)) & ((ulong) (0xFF))))) << (uint) (0x8)))) | ((ulong) ((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x8)))) & ((ulong) (0xFF))))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x10)))) & ((ulong) (0xFF))))) << (uint) (0x18))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x18)))) & ((ulong) (0xFF))))) << (uint) (0x10))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x20)))) & ((ulong) (0xFF))))) << (uint) (0x28))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x28)))) & ((ulong) (0xFF))))) << (uint) (0x20))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x30)))) & ((ulong) (0xFF))))) << (uint) (0x38))))) | ((ulong) ((ulong) (((ulong) ((((ulong) ((ulong) ((x) >> (uint) (0x38)))) & ((ulong) (0xFF))))) << (uint) (0x30))))));
		}
		return true;
	}
	insn_214:
	/* RORV */
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) << (32 - (int) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20)))))) | (((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])) >> (int) ((ulong) (((ulong) (uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]))) % ((ulong) (long) (0x20)))))));
		} else {
			state->X[(int) rd] = (ulong) ((((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) << (64 - (int) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40)))))) | (((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])) >> (int) ((ulong) (((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))) % ((ulong) (long) (0x40))))));
		}
		return true;
	}
	insn_215:
	/* SBCS */
	if((inst & 0x7FE0FC00U) == 0x7A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) ((bool) (state->NZCV_C)));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) ((bool) (state->NZCV_C)));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	insn_216:
	/* SBFM */
	if((inst & 0x7F800000U) == 0x13000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto src = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = (uint) ((((uint) ((uint) (((src) << (32 - (int) (immr))) | ((src) >> (int) (immr))))) & ((uint) (wmask))));
			auto top = (uint) (((uint) (uint) ((uint) ((uint) (0x0)))) - ((uint) (uint) ((uint) ((((ulong) ((uint) ((src) >> (uint) (imms)))) & ((ulong) (0x1)))))));
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) ((uint) ((((uint) (top)) & ((uint) ((uint) (~(tmask)))))))) | ((uint) ((uint) ((((uint) (bot)) & ((uint) (tmask)))))))));
		} else {
			auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = (ulong) ((((ulong) ((ulong) (((src) << (64 - (int) (immr))) | ((src) >> (int) (immr))))) & ((ulong) (wmask))));
			auto top = (ulong) (((ulong) (ulong) ((ulong) ((ulong) (0x0)))) - ((ulong) (ulong) ((ulong) ((((ulong) ((ulong) ((src) >> (uint) (imms)))) & ((ulong) (0x1)))))));
			state->X[(int) rd] = (ulong) ((((ulong) ((ulong) ((((ulong) (top)) & ((ulong) ((ulong) (~(tmask)))))))) | ((ulong) ((ulong) ((((ulong) (bot)) & ((ulong) (tmask))))))));
		}
		return true;
	}
	insn_217:
	/* SCVTF-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E220000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("H");
				r2 = string("W");
				break;
			}
			case 0x0: {
				r1 = string("S");
				r2 = string("W");
				break;
			}
			case 0x1: {
				r1 = string("D");
				r2 = string("W");
				break;
			}
			case 0x7: {
				r1 = string("H");
				r2 = string("X");
				break;
			}
			case 0x4: {
				r1 = string("S");
				r2 = string("X");
				break;
			}
			case 0x5: {
				r1 = string("D");
				r2 = string("X");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))), 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))), 0, 0, 0 };
				break;
			}
			case 0x5: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_218:
	/* SCVTF-scalar */
	if((inst & 0xFFBFFC00U) == 0x5E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((int) (Bitcast<float, int>((float) (state->V[rn][0]))))), 0, 0, 0 };
		} else {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((long) (Bitcast<double, long>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))), 0 });
		}
		return true;
	}
	insn_219:
	/* SCVTF-vector */
	if((inst & 0xBFBFFC00U) == 0x0E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_522) -> string { switch(temp_522) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x1])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) ((float) ((int) (reinterpret_cast<Vector128<int>>(n)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((long) (reinterpret_cast<Vector128<long>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((long) (reinterpret_cast<Vector128<long>>(n)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_220:
	/* SDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto operand2 = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((uint) ((uint) (0x0))) : ((uint) ((uint) ((float) (((float) (float) ((float) ((float) ((int) ((int) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))))) / ((float) (float) ((float) ((float) ((int) ((int) (operand2))))))))))));
		} else {
			auto operand2 = (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) (0x0))) : ((ulong) ((ulong) ((double) (((double) (double) ((double) ((double) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))))) / ((double) (double) ((double) ((double) ((long) ((long) (operand2)))))))))));
		}
		return true;
	}
	insn_221:
	/* SHL-vector */
	if((inst & 0xBF80FC00U) == 0x0F005400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto immh = (inst >> 19) & 0xFU;
		auto immb = (inst >> 16) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = string("");
		auto size = 0x0;
		auto shift = 0x0;
		if(!((bool) (((immh) != (0x0)) ? 1U : 0U)))
			goto insn_222;
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			size = 0x1;
			shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x8)));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				T = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				size = 0x2;
				shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x10)));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					size = 0x4;
					shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x20)));
				} else {
					T = (string) ((Q != 0) ? (string("2D")) : throw "Not implemented");
					size = 0x8;
					shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x20)));
				}
			}
		}
		auto sv = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch(size) {
			case 0x1: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x0])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x0])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x2])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x3])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x4])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x5])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x6])) << (uint) (shift));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x7])) << (uint) (shift));
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x8])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0x9])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0xA])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0xB])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xC] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0xC])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xD] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0xD])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xE] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0xE])) << (uint) (shift));
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xF] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(sv)[0xF])) << (uint) (shift));
				}
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x0])) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x0])) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x2])) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x3])) << (uint) (shift));
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x4])) << (uint) (shift));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x5])) << (uint) (shift));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x6])) << (uint) (shift));
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(sv)[0x7])) << (uint) (shift));
				}
				break;
			}
			case 0x4: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(sv)[0x0])) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(sv)[0x1])) << (uint) (shift));
				if((Q) != 0) {
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(sv)[0x2])) << (uint) (shift));
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(sv)[0x3])) << (uint) (shift));
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((ulong) (reinterpret_cast<Vector128<ulong>>(sv)[0x0])) << (uint) (shift));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((ulong) (reinterpret_cast<Vector128<ulong>>(sv)[0x1])) << (uint) (shift));
				break;
			}
		}
		return true;
	}
	insn_222:
	/* SMADDL */
	if((inst & 0xFFE08000U) == 0x9B200000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) ((ulong) ((long) (((long) (long) ((long) ((long) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))))) + ((long) (long) ((long) (((long) (long) ((long) (SignExt<long>((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]), 32)))) * ((long) (long) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))))))));
		return true;
	}
	insn_223:
	/* SMULH */
	if((inst & 0xFFE0FC00U) == 0x9B407C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) ((ulong) ((long) ((long) ((Int128) (((Int128) (((Int128) (Int128) ((Int128) ((Int128) ((long) ((long) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))))) * ((Int128) (Int128) ((Int128) ((Int128) ((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))))))))) >> (uint) (0x40))))));
		return true;
	}
	insn_224:
	/* SSHLL */
	if((inst & 0xBF80FC00U) == 0x0F00A400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto immh = (inst >> 19) & 0xFU;
		auto immb = (inst >> 16) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto variant = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = string("");
		auto tb = string("");
		auto shift = (ulong) ((ulong) (0x0));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			ta = string("8H");
			tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			shift = (ulong) (((ulong) (byte) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))) - ((ulong) (long) (0x8)));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				ta = string("4S");
				tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				shift = (ulong) (((ulong) (byte) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))) - ((ulong) (long) (0x10)));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					ta = string("2D");
					tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					shift = (ulong) (((ulong) (byte) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))) - ((ulong) (long) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		auto iv = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x0] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x8)))) : (0x0))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x1] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x8)))) : (0x1))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x2] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x2)) + ((long) (long) (0x8)))) : (0x2))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x3] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x3)) + ((long) (long) (0x8)))) : (0x3))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x4] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x4)) + ((long) (long) (0x8)))) : (0x4))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x5] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x5)) + ((long) (long) (0x8)))) : (0x5))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x6] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x6)) + ((long) (long) (0x8)))) : (0x6))))])))) << (uint) (shift));
			reinterpret_cast<Vector128<short>*>(&(state->V[(int) (rd)]))[0][0x7] = (short) (((short) ((short) ((sbyte) (reinterpret_cast<Vector128<sbyte>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x7)) + ((long) (long) (0x8)))) : (0x7))))])))) << (uint) (shift));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x0] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x4)))) : (0x0))))])))) << (uint) (shift));
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x1] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x4)))) : (0x1))))])))) << (uint) (shift));
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x2] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x2)) + ((long) (long) (0x4)))) : (0x2))))])))) << (uint) (shift));
				reinterpret_cast<Vector128<int>*>(&(state->V[(int) (rd)]))[0][0x3] = (int) (((int) ((int) ((short) (reinterpret_cast<Vector128<short>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x3)) + ((long) (long) (0x4)))) : (0x3))))])))) << (uint) (shift));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					reinterpret_cast<Vector128<long>*>(&(state->V[(int) (rd)]))[0][0x0] = (long) (((long) ((long) ((int) (reinterpret_cast<Vector128<int>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x2)))) : (0x0))))])))) << (uint) (shift));
					reinterpret_cast<Vector128<long>*>(&(state->V[(int) (rd)]))[0][0x1] = (long) (((long) ((long) ((int) (reinterpret_cast<Vector128<int>>(iv)[(uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x2)))) : (0x1))))])))) << (uint) (shift));
				} else {
					throw "Not implemented";
				}
			}
		}
		return true;
	}
	insn_225:
	/* ST1-single-no-offset */
	if((inst & 0xBFFF2000U) == 0x0D000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto opc = (inst >> 14) & 0x3U;
		auto S = (inst >> 12) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((opc) != (0x3)) ? 1U : 0U)))
			goto insn_226;
		auto t = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("B")) : ((string) (((bool) ((((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) ((((byte) ((((ulong) (size)) & ((ulong) (0x1))))) == (0x0)) ? 1U : 0U))))) != 0) ? (string("H")) : ((string) (((bool) (((opc) == (0x2)) ? 1U : 0U) != 0) ? ((string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : ((string) (((bool) ((((bool) ((bool) (((size) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) (((S) == (0x0)) ? 1U : 0U))))) != 0) ? (string("D")) : throw "Not implemented")))) : throw "Not implemented")))));
		auto index = (uint) (([=](auto temp_523) -> uint { switch(temp_523) { case 0x0: return (uint) ((uint) ((byte) ((byte) (((byte) (byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (S)) << 2)))) | ((byte) (((byte) (Q)) << 3)))))); case 0x1: return (uint) (((uint) ((uint) ((byte) ((byte) (((byte) (byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (S)) << 2)))) | ((byte) (((byte) (Q)) << 3))))))) >> (uint) (0x1)); case 0x2: return (uint) (((bool) ((((byte) ((((ulong) (size)) & ((ulong) (0x1))))) == (0x0)) ? 1U : 0U) != 0) ? ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (S)) << 0)) | ((byte) (((byte) (Q)) << 1))))))) : (Q)); default: throw "Not implemented"; } })(opc));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto v = (Vector128<float>) (state->V[rt]);
		switch(opc) {
			case 0x0: {
				*(byte*) (address) = (byte) (reinterpret_cast<Vector128<byte>>(v)[index]);
				break;
			}
			case 0x1: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(v)[index]);
				break;
			}
			case 0x2: {
				if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
					*(float*) (address) = (float) (reinterpret_cast<Vector128<float>>(v)[index]);
				} else {
					*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(v)[index]);
				}
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_226:
	/* ST2-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C008000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto T = (string) (([=](auto temp_524) -> string { switch(temp_524) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				break;
			}
		}
		return true;
	}
	insn_227:
	/* ST2-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0C808000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto imm = (byte) ((byte) ((long) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_228;
		auto T = (string) (([=](auto temp_525) -> string { switch(temp_525) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		return true;
	}
	insn_228:
	/* ST2-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0C808000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_229;
		auto T = (string) (([=](auto temp_526) -> string { switch(temp_526) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_229:
	/* ST3-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C004000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto T = (string) (([=](auto temp_527) -> string { switch(temp_527) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		auto c = (Vector128<float>) (state->V[rt3]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x1]);
				break;
			}
		}
		return true;
	}
	insn_230:
	/* ST3-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0C804000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto imm = (byte) ((byte) ((long) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_231;
		auto T = (string) (([=](auto temp_528) -> string { switch(temp_528) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		auto c = (Vector128<float>) (state->V[rt3]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x1]);
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		return true;
	}
	insn_231:
	/* ST3-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0C804000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_232;
		auto T = (string) (([=](auto temp_529) -> string { switch(temp_529) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		auto c = (Vector128<float>) (state->V[rt3]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x1]);
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_232:
	/* ST4-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto rt4 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x3))))) % ((ulong) (long) (0x20)));
		auto T = (string) (([=](auto temp_530) -> string { switch(temp_530) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		auto c = (Vector128<float>) (state->V[rt3]);
		auto d = (Vector128<float>) (state->V[rt4]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x31))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x33))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x35))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x37))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x39))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(d)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (double) (reinterpret_cast<Vector128<double>>(d)[0x1]);
				break;
			}
		}
		return true;
	}
	insn_233:
	/* ST4-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0C800000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto rt4 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x3))))) % ((ulong) (long) (0x20)));
		auto imm = (byte) ((byte) ((long) ((Q != 0) ? (0x40) : (0x2B))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_234;
		auto T = (string) (([=](auto temp_531) -> string { switch(temp_531) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		auto c = (Vector128<float>) (state->V[rt3]);
		auto d = (Vector128<float>) (state->V[rt4]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x31))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x33))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x35))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x37))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x39))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(d)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (double) (reinterpret_cast<Vector128<double>>(d)[0x1]);
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (byte) (imm)));
		return true;
	}
	insn_234:
	/* ST4-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0C800000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1))))) % ((ulong) (long) (0x20)));
		auto rt3 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x2))))) % ((ulong) (long) (0x20)));
		auto rt4 = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x3))))) % ((ulong) (long) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_235;
		auto T = (string) (([=](auto temp_532) -> string { switch(temp_532) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		auto a = (Vector128<float>) (state->V[rt]);
		auto b = (Vector128<float>) (state->V[rt2]);
		auto c = (Vector128<float>) (state->V[rt3]);
		auto d = (Vector128<float>) (state->V[rt4]);
		switch(size) {
			case 0x0: {
				if((Q) != 0) {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x21))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x23))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x8]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x25))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x27))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x9]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x29))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xA]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xB]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x31))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x33))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xC]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x35))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x37))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xD]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x39))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xE]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0xF]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0xF]);
				} else {
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x0]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x5))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x7))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x1]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x9))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xB))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x2]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xD))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xF))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x3]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x11))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x13))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x4]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x15))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x17))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x5]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x19))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1B))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x6]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (byte) (reinterpret_cast<Vector128<byte>>(a)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1D))))) = (byte) (reinterpret_cast<Vector128<byte>>(b)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (byte) (reinterpret_cast<Vector128<byte>>(c)[0x7]);
					*(byte*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1F))))) = (byte) (reinterpret_cast<Vector128<byte>>(d)[0x7]);
				}
				break;
			}
			case 0x1: {
				if((Q) != 0) {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x22))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x26))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x4]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x5]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x32))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x36))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x6]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x7]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x7]);
				} else {
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x6))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x0]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xA))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xE))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x1]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x12))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x16))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x2]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1A))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(b)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(c)[0x3]);
					*(ushort*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1E))))) = (ushort) (reinterpret_cast<Vector128<ushort>>(d)[0x3]);
				}
				break;
			}
			case 0x2: {
				if((Q) != 0) {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x24))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x2C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x2]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x34))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x3]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x3C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x3]);
				} else {
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x4))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0xC))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x0]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (float) (reinterpret_cast<Vector128<float>>(a)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x14))))) = (float) (reinterpret_cast<Vector128<float>>(b)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (float) (reinterpret_cast<Vector128<float>>(c)[0x1]);
					*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x1C))))) = (float) (reinterpret_cast<Vector128<float>>(d)[0x1]);
				}
				break;
			}
			default: {
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x0))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x8))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x10))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x18))))) = (double) (reinterpret_cast<Vector128<double>>(d)[0x0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x20))))) = (double) (reinterpret_cast<Vector128<double>>(a)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x28))))) = (double) (reinterpret_cast<Vector128<double>>(b)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x30))))) = (double) (reinterpret_cast<Vector128<double>>(c)[0x1]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) ((long) (0x38))))) = (double) (reinterpret_cast<Vector128<double>>(d)[0x1]);
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))));
		return true;
	}
	insn_235:
	/* STLR */
	if((inst & 0xBFFFFC00U) == 0x889FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		return true;
	}
	insn_236:
	/* STLRB */
	if((inst & 0xFFFFFC00U) == 0x089FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		*(byte*) (address) = (byte) ((byte) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	insn_237:
	/* STLRH */
	if((inst & 0xFFFFFC00U) == 0x489FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		*(ushort*) (address) = (ushort) ((ushort) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	insn_238:
	/* STLXR */
	if((inst & 0xBFE0FC00U) == 0x8800FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) (address) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		state->X[(int) rs] = (ulong) (uint) (0x0);
		return true;
	}
	insn_239:
	/* STLXRB */
	if((inst & 0xFFE0FC00U) == 0x0800FC00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		*(byte*) (address) = (byte) ((byte) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		state->X[(int) rs] = (ulong) (uint) (0x0);
		return true;
	}
	insn_240:
	/* STP-postindex */
	if((inst & 0x7FC00000U) == 0x28800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt1) == 31 ? 0U : (uint) state->X[(int) rt1]);
			*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (uint) ((rt2) == 31 ? 0U : (uint) state->X[(int) rt2]);
		} else {
			*(ulong*) (address) = (ulong) ((rt1) == 31 ? 0UL : state->X[(int) rt1]);
			*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (ulong) ((rt2) == 31 ? 0UL : state->X[(int) rt2]);
		}
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_241:
	/* STP-preindex */
	if((inst & 0x7FC00000U) == 0x29800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt1) == 31 ? 0U : (uint) state->X[(int) rt1]);
			*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (uint) ((rt2) == 31 ? 0U : (uint) state->X[(int) rt2]);
		} else {
			*(ulong*) (address) = (ulong) ((rt1) == 31 ? 0UL : state->X[(int) rt1]);
			*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (ulong) ((rt2) == 31 ? 0UL : state->X[(int) rt2]);
		}
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	insn_242:
	/* STP-signed-offset */
	if((inst & 0x7FC00000U) == 0x29000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rt1) == 31 ? 0U : (uint) state->X[(int) rt1]);
			*(uint*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (uint) ((rt2) == 31 ? 0U : (uint) state->X[(int) rt2]);
		} else {
			*(ulong*) (address) = (ulong) ((rt1) == 31 ? 0UL : state->X[(int) rt1]);
			*(ulong*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (ulong) ((rt2) == 31 ? 0UL : state->X[(int) rt2]);
		}
		return true;
	}
	insn_243:
	/* STP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2C800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_533) -> string { switch(temp_533) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_534) -> long { switch(temp_534) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		switch(opc) {
			case 0x0: {
				*(float*) (address) = (float) (state->V[rt1][0]);
				*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (float) (state->V[rt2][0]);
				break;
			}
			case 0x1: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt1])[0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt2])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt1]));
				StoreVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10))), (Vector128<float>) (state->V[rt2]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_244:
	/* STP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2D800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_535) -> string { switch(temp_535) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_536) -> long { switch(temp_536) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		switch(opc) {
			case 0x0: {
				*(float*) (address) = (float) (state->V[rt1][0]);
				*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (float) (state->V[rt2][0]);
				break;
			}
			case 0x1: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt1])[0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt2])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt1]));
				StoreVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10))), (Vector128<float>) (state->V[rt2]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	insn_245:
	/* STP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D000000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_537) -> string { switch(temp_537) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_538) -> long { switch(temp_538) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		switch(opc) {
			case 0x0: {
				*(float*) (address) = (float) (state->V[rt1][0]);
				*(float*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x4)))) = (float) (state->V[rt2][0]);
				break;
			}
			case 0x1: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt1])[0]);
				*(double*) ((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x8)))) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt2])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt1]));
				StoreVector((ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (0x10))), (Vector128<float>) (state->V[rt2]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_246:
	/* STR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8000400U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
		} else {
			*(ulong*) (address) = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
		}
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_247:
	/* STR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8000C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) (address) = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
		} else {
			*(ulong*) (address) = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
		}
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	insn_248:
	/* STR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto pimm = (ulong) (((ulong) ((ulong) (imm))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (ulong) (pimm)))) = (uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs]);
		} else {
			*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (ulong) (pimm)))) = (ulong) ((rs) == 31 ? 0UL : state->X[(int) rs]);
		}
		return true;
	}
	insn_249:
	/* STR-register */
	if((inst & 0xBFE00C00U) == 0xB8200800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_539) -> string { switch(temp_539) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		return true;
	}
	insn_250:
	/* STR-simd-postindex */
	if((inst & 0x3F600C00U) == 0x3C000400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_540) -> string { switch(temp_540) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]);
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rn] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_251:
	/* STR-simd-preindex */
	if((inst & 0x3F600C00U) == 0x3C000C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_541) -> string { switch(temp_541) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			state->SP = address;
		else
			state->X[(int) rn] = address;
		return true;
	}
	insn_252:
	/* STR-simd-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_542) -> string { switch(temp_542) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) ((ushort) ((imm) << (uint) (scale)))));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_253:
	/* STR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C200800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r1 = (string) (([=](auto temp_543) -> string { switch(temp_543) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (([=](auto temp_544) -> long { switch(temp_544) { case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: return (long) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (0x4) : (0x0)); } })(size))));
		auto extend = (string) (([=](auto temp_545) -> string { switch(temp_545) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_254:
	/* STRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		*(byte*) (address) = (byte) ((byte) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_255:
	/* STRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		*(byte*) (address) = (byte) ((byte) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	insn_256:
	/* STRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39000000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))) = (byte) ((byte) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	insn_257:
	/* STRB-register */
	if((inst & 0xFFE00C00U) == 0x38200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_546) -> string { switch(temp_546) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (byte) ((byte) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	insn_258:
	/* STRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]);
		*(ushort*) (address) = (ushort) ((ushort) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		else
			state->X[(int) rd] = (ulong) (((ulong) (ulong) (address)) + ((ulong) (long) (simm)));
		return true;
	}
	insn_259:
	/* STRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rd) == 31 ? state->SP : state->X[(int) rd]))) + ((ulong) (long) (simm)));
		*(ushort*) (address) = (ushort) ((ushort) ((uint) ((rs) == 31 ? 0U : (uint) state->X[(int) rs])));
		if(rd == 31)
			state->SP = address;
		else
			state->X[(int) rd] = address;
		return true;
	}
	insn_260:
	/* STRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79000000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ushort) (imm)))) = (ushort) ((ushort) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	insn_261:
	/* STRH-register */
	if((inst & 0xFFE00C00U) == 0x78200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_547) -> string { switch(temp_547) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = (ulong) (((ulong) (((bool) (((option) == (0x6)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) ((long) (SignExt<long>((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]), 32))))) : ((ulong) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) : ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))) << (uint) (amount));
		*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (ulong) (offset)))) = (ushort) ((ushort) ((uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt])));
		return true;
	}
	insn_262:
	/* STUR */
	if((inst & 0xBFE00C00U) == 0xB8000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (long) (SignExt<long>(imm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			*(uint*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]);
		} else {
			*(ulong*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]);
		}
		return true;
	}
	insn_263:
	/* STUR-simd */
	if((inst & 0x3F600C00U) == 0x3C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_548) -> string { switch(temp_548) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (simm)));
		switch(rop) {
			case 0x0: {
				*(float*) (address) = (float) (reinterpret_cast<Vector128<byte>>(state->V[rt])[0]);
				break;
			}
			case 0x4: {
				*(ushort*) (address) = (ushort) (reinterpret_cast<Vector128<ushort>>(state->V[rt])[0]);
				break;
			}
			case 0x8: {
				*(float*) (address) = (float) (state->V[rt][0]);
				break;
			}
			case 0xC: {
				*(double*) (address) = (double) (reinterpret_cast<Vector128<double>>(state->V[rt])[0]);
				break;
			}
			case 0x2: {
				StoreVector(address, (Vector128<float>) (state->V[rt]));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_264:
	/* STURB */
	if((inst & 0xFFE00C00U) == 0x38000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		*(byte*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (byte) ((byte) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	insn_265:
	/* STURH */
	if((inst & 0xFFE00C00U) == 0x78000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		*(ushort*) ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) + ((ulong) (long) (offset)))) = (ushort) ((ushort) ((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])));
		return true;
	}
	insn_266:
	/* STXR */
	if((inst & 0xBFE0FC00U) == 0x88007C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		state->X[(int) rs] = (ulong) (uint) ((bool) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((bool) (CompareAndSwap((uint*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])), (uint) ((rt) == 31 ? 0U : (uint) state->X[(int) rt]), state->Exclusive32))) : ((bool) (CompareAndSwap((ulong*) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])), (ulong) ((rt) == 31 ? 0UL : state->X[(int) rt]), state->Exclusive64)))));
		return true;
	}
	insn_267:
	/* SUB-immediate */
	if((inst & 0x7F800000U) == 0x51000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (long) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) ((uint) (imm))) << (uint) (shift))))));
		} else {
			if(rd == 31)
				state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift)))));
			else
				state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift)))));
		}
		return true;
	}
	insn_268:
	/* SUB-extended-register */
	if((inst & 0x7FE00000U) == 0x4B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_549) -> string { switch(temp_549) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_550) -> string { switch(temp_550) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			if(rd == 31)
				state->SP = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) (([=](auto temp_551) -> uint { switch(temp_551) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
			else
				state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL)))) - ((uint) (uint) ((uint) (((uint) (([=](auto temp_552) -> uint { switch(temp_552) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm)))));
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				if(rd == 31)
					state->SP = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_553) -> ulong { switch(temp_553) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm)))));
				else
					state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (((ulong) (([=](auto temp_554) -> ulong { switch(temp_554) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm)))));
			}
		}
		return true;
	}
	insn_269:
	/* SUB-shifted-register */
	if((inst & 0x7F200000U) == 0x4B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_555) -> string { switch(temp_555) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) - ((uint) (uint) ((uint) (([=](auto temp_556) -> uint { switch(temp_556) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
		} else {
			state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) - ((ulong) (ulong) ((ulong) (([=](auto temp_557) -> ulong { switch(temp_557) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift)))));
		}
		return true;
	}
	insn_270:
	/* SUBS-extended-register */
	if((inst & 0x7FE00000U) == 0x6B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_558) -> string { switch(temp_558) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_559) -> string { switch(temp_559) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? state->SP : (state->X[(int) rn] & 0xFFFFFFFFUL))));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) (((uint) (([=](auto temp_560) -> uint { switch(temp_560) { case 0x0: return (uint) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (uint) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x4: return (uint) ((uint) ((int) (SignExt<int>((byte) ((byte) (m)), 8)))); case 0x5: return (uint) ((uint) ((int) (SignExt<int>((ushort) ((ushort) (m)), 16)))); default: return m; } })(option))) << (uint) (imm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				state->X[(int) rd] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (uint) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			} else {
				auto m = (ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])));
				state->X[(int) rd] = (ulong) (([=]() -> ulong {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? state->SP : state->X[(int) rn])));
						auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) (((ulong) (([=](auto temp_561) -> ulong { switch(temp_561) { case 0x0: return (ulong) ((((ulong) (m)) & ((ulong) (0xFF)))); case 0x1: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFF)))); case 0x2: return (ulong) ((((ulong) (m)) & ((ulong) (0xFFFFFFFF)))); case 0x4: return (ulong) ((ulong) ((long) (SignExt<long>((byte) ((byte) (m)), 8)))); case 0x5: return (ulong) ((ulong) ((long) (SignExt<long>((ushort) ((ushort) (m)), 16)))); case 0x6: return (ulong) ((ulong) ((long) (SignExt<long>(m, 64)))); default: return m; } })(option))) << (uint) (imm))))));
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
						auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
						state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
						state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
						state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
						state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
						return usum;
					})());
			}
		}
		return true;
	}
	insn_271:
	/* SUBS-shifted-register */
	if((inst & 0x7F200000U) == 0x6B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto mode32 = (bool) (((size) == (0x0)) ? 1U : 0U);
		auto r = (string) ((mode32 != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_562) -> string { switch(temp_562) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if((mode32) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) (([=](auto temp_563) -> uint { switch(temp_563) { case 0x0: return (uint) (((uint) ((uint) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (uint) (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (uint) ((uint) ((int) (((int) ((int) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))) >> (uint) (imm)))); default: return (uint) ((((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) << (32 - (int) (imm))) | (((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) (([=](auto temp_564) -> ulong { switch(temp_564) { case 0x0: return (ulong) (((ulong) ((ulong) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) << (uint) (imm)); case 0x1: return (ulong) (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (uint) (imm)); case 0x2: return (ulong) ((ulong) ((long) (((long) ((long) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])))) >> (uint) (imm)))); default: return (ulong) ((((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) << (64 - (int) (imm))) | (((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm])) >> (int) (imm))); } })(shift))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	insn_272:
	/* SUBS-immediate */
	if((inst & 0x7F800000U) == 0x71000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_565) -> string { switch(temp_565) { case 0x0: return string("LSL #0"); case 0x1: return string("LSL #12"); default: throw "Not implemented"; } })(shift));
		auto rimm = (uint) ((shift != 0) ? ((uint) (((uint) ((uint) (imm))) << (uint) (0xC))) : (imm));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->X[(int) rd] = (ulong) (uint) ((uint) (([=]() -> uint {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (uint) ((uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((uint) (rimm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (uint) (((uint) (uint) ((uint) (((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((uint) (uint) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (int) (((int) (int) ((int) (((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((int) (int) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (uint) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((ulong) (((ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((ulong) (ulong) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((uint) ((usum) >> (uint) (bits1))) != ((uint) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})()));
		} else {
			state->X[(int) rd] = (ulong) (([=]() -> ulong {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = (ulong) ((ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn])));
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((ulong) (rimm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = (ulong) (((ulong) (ulong) ((ulong) (((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((ulong) (ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)));
					auto ssum = (long) (((long) (long) ((long) (((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((long) (long) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))));
					state->NZCV_N = (ulong) ((usum) >> (uint) (bits1));
					state->NZCV_Z = (bool) (((usum) == (0x0)) ? 1U : 0U);
					state->NZCV_C = (uint) ((((ulong) ((uint) ((uint) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((UInt128) (UInt128) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (uint) (bits)))))) & ((ulong) (0x1))));
					state->NZCV_V = (bool) ((((bool) ((bool) ((((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))) ? 1U : 0U))) & ((bool) ((bool) ((((ulong) ((usum) >> (uint) (bits1))) != ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (uint) (bits1)))) ? 1U : 0U)))));
					return usum;
				})());
		}
		return true;
	}
	insn_273:
	/* SVC */
	if((inst & 0xFFE0001FU) == 0xD4000001U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		Svc(imm);
		return true;
	}
	insn_274:
	/* SYS */
	if((inst & 0xFFF80000U) == 0xD5080000U) {
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return true;
	}
	insn_275:
	/* TBZ */
	if((inst & 0x7F000000U) == 0x36000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint) ((((uint) ((uint) (((uint) ((uint) (upper))) << (uint) (0x5)))) | ((uint) ((uint) ((uint) (bottom))))));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((ushort) (((ushort) ((ushort) (offset))) << (uint) (0x2)), 16)))));
		if(((ulong) ((((ulong) ((ulong) (((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])) >> (uint) (imm)))) & ((ulong) (0x1))))) != 0) {
			Branch(pc + 4);
		} else {
			Branch(addr);
		}
		return true;
	}
	insn_276:
	/* TBNZ */
	if((inst & 0x7F000000U) == 0x37000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint) ((((uint) ((uint) (((uint) ((uint) (upper))) << (uint) (0x5)))) | ((uint) ((uint) ((uint) (bottom))))));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((ushort) (((ushort) ((ushort) (offset))) << (uint) (0x2)), 16)))));
		if(((ulong) ((((ulong) ((ulong) (((ulong) ((rt) == 31 ? 0UL : state->X[(int) rt])) >> (uint) (imm)))) & ((ulong) (0x1))))) != 0) {
			Branch(addr);
		} else {
			Branch(pc + 4);
		}
		return true;
	}
	insn_277:
	/* UADDLV */
	if((inst & 0xBF3FFC00U) == 0x2E303800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_566) -> string { switch(temp_566) { case 0x0: return string("H"); case 0x1: return string("S"); case 0x2: return string("D"); default: throw "Not implemented"; } })(size));
		auto t = (string) (([=](auto temp_567) -> string { switch(temp_567) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto esize = (long) ((0x8) << (uint) (size));
		auto count = (long) (((long) (long) ((long) ((Q != 0) ? (0x80) : (0x40)))) / ((long) (long) (esize)));
		switch(size) {
			case 0x0: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<ushort>) { (ushort) ((ushort) ((uint) (VectorSumUnsigned((Vector128<float>) (state->V[rn]), esize, count)))), 0, 0, 0, 0, 0, 0, 0 });
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) (Bitcast<uint, float>((uint) (VectorSumUnsigned((Vector128<float>) (state->V[rn]), esize, count)))), 0, 0, 0 };
				break;
			}
			case 0x2: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) (Bitcast<ulong, double>((ulong) ((ulong) ((uint) (VectorSumUnsigned((Vector128<float>) (state->V[rn]), esize, count)))))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_278:
	/* UADDW[2] */
	if((inst & 0xBF20FC00U) == 0x2E201000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto o2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto Ta = string("");
		auto Tb = string("");
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				Ta = string("8H");
				Tb = string("8B");
				break;
			}
			case 0x1: {
				Ta = string("8H");
				Tb = string("16B");
				break;
			}
			case 0x2: {
				Ta = string("4S");
				Tb = string("4H");
				break;
			}
			case 0x3: {
				Ta = string("4S");
				Tb = string("8H");
				break;
			}
			case 0x4: {
				Ta = string("2D");
				Tb = string("2S");
				break;
			}
			case 0x5: {
				Ta = string("2D");
				Tb = string("4S");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		auto a = (Vector128<float>) (state->V[rn]);
		auto b = (Vector128<float>) (state->V[rm]);
		switch(size) {
			case 0x0: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x0]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0x8)) : (0x0))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x1]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0x9)) : (0x1))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x2]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0xA)) : (0x2))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x3]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0xB)) : (0x3))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x4]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0xC)) : (0x4))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x5]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0xD)) : (0x5))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x6]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0xE)) : (0x6))]))))));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((ushort) (ushort) ((ushort) (reinterpret_cast<Vector128<ushort>>(a)[0x7]))) + ((ushort) (ushort) ((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(b)[(long) ((Q != 0) ? ((long) (0xF)) : (0x7))]))))));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) (uint) ((uint) (reinterpret_cast<Vector128<uint>>(a)[0x0]))) + ((uint) (uint) ((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[(long) ((Q != 0) ? ((long) (0x4)) : (0x0))]))))));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) (uint) ((uint) (reinterpret_cast<Vector128<uint>>(a)[0x1]))) + ((uint) (uint) ((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[(long) ((Q != 0) ? ((long) (0x5)) : (0x1))]))))));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((uint) (uint) ((uint) (reinterpret_cast<Vector128<uint>>(a)[0x2]))) + ((uint) (uint) ((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[(long) ((Q != 0) ? ((long) (0x6)) : (0x2))]))))));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((uint) (uint) ((uint) (reinterpret_cast<Vector128<uint>>(a)[0x3]))) + ((uint) (uint) ((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(b)[(long) ((Q != 0) ? ((long) (0x7)) : (0x3))]))))));
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((ulong) (ulong) ((ulong) (reinterpret_cast<Vector128<ulong>>(a)[0x0]))) + ((ulong) (ulong) ((ulong) ((ulong) ((uint) (reinterpret_cast<Vector128<uint>>(b)[(long) ((Q != 0) ? ((long) (0x2)) : (0x0))]))))));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((ulong) (ulong) ((ulong) (reinterpret_cast<Vector128<ulong>>(a)[0x1]))) + ((ulong) (ulong) ((ulong) ((ulong) ((uint) (reinterpret_cast<Vector128<uint>>(b)[(long) ((Q != 0) ? ((long) (0x3)) : (0x1))]))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_279:
	/* UBFM */
	if((inst & 0x7F800000U) == 0x53000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto src = (uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]);
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = (uint) ((((uint) ((uint) (((src) << (32 - (int) (immr))) | ((src) >> (int) (immr))))) & ((uint) (wmask))));
			state->X[(int) rd] = (ulong) (uint) ((uint) ((((uint) (bot)) & ((uint) (tmask)))));
		} else {
			auto src = (ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]);
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = (ulong) ((((ulong) ((ulong) (((src) << (64 - (int) (immr))) | ((src) >> (int) (immr))))) & ((ulong) (wmask))));
			state->X[(int) rd] = (ulong) ((((ulong) (bot)) & ((ulong) (tmask))));
		}
		return true;
	}
	insn_280:
	/* UCVTF-scalar-gpr-integer */
	if((inst & 0x7F3FFC00U) == 0x1E230000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r1 = string("");
		auto r2 = string("");
		switch(st) {
			case 0x3: {
				r1 = string("H");
				r2 = string("W");
				break;
			}
			case 0x0: {
				r1 = string("S");
				r2 = string("W");
				break;
			}
			case 0x1: {
				r1 = string("D");
				r2 = string("W");
				break;
			}
			case 0x7: {
				r1 = string("H");
				r2 = string("X");
				break;
			}
			case 0x4: {
				r1 = string("S");
				r2 = string("X");
				break;
			}
			case 0x5: {
				r1 = string("D");
				r2 = string("X");
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		switch(st) {
			case 0x0: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0, 0, 0 };
				break;
			}
			case 0x1: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))), 0 });
				break;
			}
			case 0x4: {
				state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0, 0, 0 };
				break;
			}
			case 0x5: {
				state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))), 0 });
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_281:
	/* UCVTF-scalar-integer */
	if((inst & 0xFFBFFC00U) == 0x7E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			state->V[(int) (rd)] = (Vector128<float>) { (float) ((float) ((uint) (Bitcast<float, uint>((float) (state->V[rn][0]))))), 0, 0, 0 };
		} else {
			state->V[(int) (rd)] = reinterpret_cast<Vector128<float>>((Vector128<double>) { (double) ((double) ((ulong) (Bitcast<double, ulong>((double) (reinterpret_cast<Vector128<double>>(state->V[rn])[0]))))), 0 });
		}
		return true;
	}
	insn_282:
	/* UCVTF-vector */
	if((inst & 0xBFBFFC00U) == 0x2E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_568) -> string { switch(temp_568) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x0] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x1] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x2] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x2])));
				reinterpret_cast<Vector128<float>*>(&(state->V[(int) (rd)]))[0][0x3] = (float) ((float) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x0] = (double) ((double) ((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x0])));
				reinterpret_cast<Vector128<double>*>(&(state->V[(int) (rd)]))[0][0x1] = (double) ((double) ((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_283:
	/* UDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto operand2 = (uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (uint) ((uint) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((uint) ((uint) (0x0))) : ((uint) (((uint) (uint) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))) / ((uint) (uint) (operand2))))));
		} else {
			auto operand2 = (ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]);
			state->X[(int) rd] = (ulong) (((bool) (((operand2) == (0x0)) ? 1U : 0U) != 0) ? ((ulong) ((ulong) (0x0))) : ((ulong) (((ulong) (ulong) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))) / ((ulong) (ulong) (operand2)))));
		}
		return true;
	}
	insn_284:
	/* UMADDL */
	if((inst & 0xFFE08000U) == 0x9BA00000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) (((ulong) (ulong) ((ulong) ((ra) == 31 ? 0UL : state->X[(int) ra]))) + ((ulong) (ulong) ((ulong) (((ulong) (ulong) ((ulong) ((ulong) ((uint) ((rn) == 31 ? 0U : (uint) state->X[(int) rn]))))) * ((ulong) (ulong) ((ulong) ((ulong) ((uint) ((rm) == 31 ? 0U : (uint) state->X[(int) rm])))))))));
		return true;
	}
	insn_285:
	/* UMULH */
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		state->X[(int) rd] = (ulong) ((ulong) ((UInt128) (((UInt128) (((UInt128) (UInt128) ((UInt128) ((UInt128) ((ulong) ((rn) == 31 ? 0UL : state->X[(int) rn]))))) * ((UInt128) (UInt128) ((UInt128) ((UInt128) ((ulong) ((rm) == 31 ? 0UL : state->X[(int) rm]))))))) >> (uint) (0x40))));
		return true;
	}
	insn_286:
	/* USHL-vector */
	if((inst & 0xBF20FC00U) == 0x2E204400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_569) -> string { switch(temp_569) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto n = (Vector128<float>) (state->V[rn]);
		auto m = (Vector128<float>) (state->V[rm]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x0])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x0])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x1])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x1])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x2])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x2])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x3])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x3])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x4])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x4])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x5])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x5])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x6])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x6])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x7])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x7])));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x0])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x0])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x1])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x1])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x2])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x2])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x3])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x3])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x4])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x4])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x5])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x5])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x6])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x6])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x7])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x7])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x8])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x8])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0x9])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0x9])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xA])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xA])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xB])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xB])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xC] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xC])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xC])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xD] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xD])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xD])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xE] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xE])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xE])));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xF] = (byte) (((byte) (reinterpret_cast<Vector128<byte>>(n)[0xF])) << (uint) ((byte) (reinterpret_cast<Vector128<byte>>(m)[0xF])));
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x0])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x0])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x1])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x1])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x2])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x2])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x3])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x3])));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x0])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x0])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x1])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x1])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x2])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x2])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x3])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x3])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x4])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x4])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x5])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x5])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x6])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x6])));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x7])) << (uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(m)[0x7])));
				break;
			}
			case 0x4: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x0])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x1])));
				break;
			}
			case 0x5: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x0])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x1])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x2])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x2])));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((uint) (reinterpret_cast<Vector128<uint>>(n)[0x3])) << (uint) ((uint) (reinterpret_cast<Vector128<uint>>(m)[0x3])));
				break;
			}
			case 0x7: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x0])) << (uint) ((ulong) (reinterpret_cast<Vector128<ulong>>(m)[0x0])));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((ulong) (reinterpret_cast<Vector128<ulong>>(n)[0x1])) << (uint) ((ulong) (reinterpret_cast<Vector128<ulong>>(m)[0x1])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_287:
	/* USHLL-vector */
	if((inst & 0xBF80FC00U) == 0x2F00A400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto immh = (inst >> 19) & 0xFU;
		auto immb = (inst >> 16) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ta = string("");
		auto Tb = string("");
		auto size = 0x0;
		auto shift = 0x0;
		if(!((bool) (((immh) != (0x0)) ? 1U : 0U)))
			goto insn_288;
		auto i2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			Ta = string("8H");
			Tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			size = 0x0;
			shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x8)));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				Ta = string("4S");
				Tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				size = 0x1;
				shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x10)));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					Ta = string("2D");
					Tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					size = 0x2;
					shift = (ulong) (((ulong) (uint) ((uint) ((uint) ((byte) ((byte) (((byte) (((byte) (immb)) << 0)) | ((byte) (((byte) (immh)) << 3)))))))) - ((ulong) (long) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		auto n = (Vector128<float>) (state->V[rn]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		switch((UInt128) ((UInt128) (((UInt128) (((UInt128) (Q)) << 0)) | ((UInt128) (((UInt128) (size)) << 1))))) {
			case 0x0: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x0])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x1])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x2])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x3])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x4])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x5])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x6])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x7])))) << (uint) (shift));
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x8])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0x9])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0xA])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0xB])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0xC])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0xD])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0xE])))) << (uint) (shift));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (((ushort) ((ushort) ((byte) (reinterpret_cast<Vector128<byte>>(n)[0xF])))) << (uint) (shift));
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x0])))) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x1])))) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x2])))) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x3])))) << (uint) (shift));
				break;
			}
			case 0x3: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x4])))) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x5])))) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x6])))) << (uint) (shift));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (((uint) ((uint) ((ushort) (reinterpret_cast<Vector128<ushort>>(n)[0x7])))) << (uint) (shift));
				break;
			}
			case 0x4: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((ulong) ((ulong) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x0])))) << (uint) (shift));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((ulong) ((ulong) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x1])))) << (uint) (shift));
				break;
			}
			case 0x5: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (((ulong) ((ulong) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x2])))) << (uint) (shift));
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (((ulong) ((ulong) ((uint) (reinterpret_cast<Vector128<uint>>(n)[0x3])))) << (uint) (shift));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_288:
	/* XTN */
	if((inst & 0xFF3FFC00U) == 0x0E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_570) -> string { switch(temp_570) { case 0x0: return string("8B"); case 0x1: return string("4H"); case 0x2: return string("2S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_571) -> string { switch(temp_571) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				auto a = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x3]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ulong) ((ulong) (0x0))) - (Vector128<ulong>) {}));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) ((byte) (a));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) ((byte) (b));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) ((byte) (c));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) ((byte) (d));
				break;
			}
			case 0x1: {
				auto a = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x1]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ulong) ((ulong) (0x0))) - (Vector128<ulong>) {}));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) ((ushort) (a));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) ((ushort) (b));
				break;
			}
			case 0x2: {
				auto a = (ulong) (reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rn]))[0x0]);
				state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((ulong) ((ulong) (0x0))) - (Vector128<ulong>) {}));
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) ((uint) (a));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_289:
	/* XTN2 */
	if((inst & 0xFF3FFC00U) == 0x4E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_572) -> string { switch(temp_572) { case 0x0: return string("16B"); case 0x1: return string("8H"); case 0x2: return string("4S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_573) -> string { switch(temp_573) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				auto a = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x1]);
				auto c = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x2]);
				auto d = (ushort) (reinterpret_cast<Vector128<ushort>>((Vector128<float>) (state->V[rn]))[0x3]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) ((byte) (a));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) ((byte) (b));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) ((byte) (c));
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) ((byte) (d));
				break;
			}
			case 0x1: {
				auto a = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x0]);
				auto b = (uint) (reinterpret_cast<Vector128<uint>>((Vector128<float>) (state->V[rn]))[0x1]);
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) ((ushort) (a));
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) ((ushort) (b));
				break;
			}
			case 0x2: {
				auto a = (ulong) (reinterpret_cast<Vector128<ulong>>((Vector128<float>) (state->V[rn]))[0x0]);
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) ((uint) (a));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	insn_290:
	/* ZIP */
	if((inst & 0xBF20BC00U) == 0x0E003800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto op = (inst >> 14) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto i = (byte) ((byte) ((ulong) (((ulong) (bool) (op)) + ((ulong) (long) (0x1)))));
		auto T = (string) (([=](auto temp_574) -> string { switch(temp_574) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto av = (Vector128<float>) (state->V[rn]);
		auto bv = (Vector128<float>) (state->V[rm]);
		state->V[rd] = (Vector128<float>) (reinterpret_cast<Vector128<float>>(((byte) ((byte) (0x0))) - (Vector128<byte>) {}));
		auto base = (ulong) (((ulong) (uint) ((uint) ((uint) (op)))) * ((ulong) (long) ((long) (((long) (long) ((long) (((long) (long) ((long) ((Q != 0) ? (0x80) : (0x40)))) / ((long) (long) ((long) ((0x8) << (uint) (size))))))) / ((long) (long) (0x2))))));
		switch(size) {
			case 0x0: {
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x0] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x2] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x1)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x4] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x2)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x6] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x3)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x1] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x3] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x1)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x5] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x2)))]);
				reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x7] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x3)))]);
				if((Q) != 0) {
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x8] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x4)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xA] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x5)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xC] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x6)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xE] = (byte) (reinterpret_cast<Vector128<byte>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x7)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0x9] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x4)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xB] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x5)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xD] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x6)))]);
					reinterpret_cast<Vector128<byte>*>(&(state->V[(int) (rd)]))[0][0xF] = (byte) (reinterpret_cast<Vector128<byte>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x7)))]);
				}
				break;
			}
			case 0x1: {
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x0] = (ushort) (reinterpret_cast<Vector128<ushort>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x2] = (ushort) (reinterpret_cast<Vector128<ushort>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x1)))]);
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x1] = (ushort) (reinterpret_cast<Vector128<ushort>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x3] = (ushort) (reinterpret_cast<Vector128<ushort>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x1)))]);
				if((Q) != 0) {
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x4] = (ushort) (reinterpret_cast<Vector128<ushort>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x2)))]);
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x6] = (ushort) (reinterpret_cast<Vector128<ushort>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x3)))]);
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x5] = (ushort) (reinterpret_cast<Vector128<ushort>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x4)))]);
					reinterpret_cast<Vector128<ushort>*>(&(state->V[(int) (rd)]))[0][0x7] = (ushort) (reinterpret_cast<Vector128<ushort>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x5)))]);
				}
				break;
			}
			case 0x2: {
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x0] = (uint) (reinterpret_cast<Vector128<uint>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x1] = (uint) (reinterpret_cast<Vector128<uint>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				if((Q) != 0) {
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x2] = (uint) (reinterpret_cast<Vector128<uint>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x1)))]);
					reinterpret_cast<Vector128<uint>*>(&(state->V[(int) (rd)]))[0][0x3] = (uint) (reinterpret_cast<Vector128<uint>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x1)))]);
				}
				break;
			}
			default: {
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x0] = (ulong) (reinterpret_cast<Vector128<ulong>>(av)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				reinterpret_cast<Vector128<ulong>*>(&(state->V[(int) (rd)]))[0][0x1] = (ulong) (reinterpret_cast<Vector128<ulong>>(bv)[(ulong) (((ulong) (ulong) (base)) + ((ulong) (long) (0x0)))]);
				break;
			}
		}
		return true;
	}
	insn_291:

    return false;
}
