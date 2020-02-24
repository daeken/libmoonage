#include <string>
#include <cstdint>
#include <cmath>
#include "common.h"
#include "recompiler.h"
using std::string;

bool Recompiler::recompile(uint inst, ulong pc) {
	/* ADCS */
	if((inst & 0x7FE0FC00U) == 0x3A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<bool>) (NZCV_CR)))).Store();
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<bool>) (NZCV_CR)))).Store();
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		return true;
	}
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
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_288) -> string { switch(temp_288) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_289) -> string { switch(temp_289) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))).Store();
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (([=](auto temp_290) -> RuntimeValue<uint> { switch(temp_290) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x4: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); default: return m; } })(option))) << (imm))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (([=](auto temp_291) -> RuntimeValue<uint> { switch(temp_291) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x4: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); default: return m; } })(option))) << (imm))))));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				if(rd == 31)
					SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << (imm)))));
				else
					XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << (imm)))));
			} else {
				auto m = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))).Store();
				if(rd == 31)
					SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (([=](auto temp_292) -> RuntimeValue<ulong> { switch(temp_292) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFFFFFF))))); case 0x4: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); case 0x6: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((RuntimeValue<uint>) (m)), 32))))); default: return m; } })(option))) << (imm)))));
				else
					XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (([=](auto temp_293) -> RuntimeValue<ulong> { switch(temp_293) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFFFFFF))))); case 0x4: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); case 0x6: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((RuntimeValue<uint>) (m)), 32))))); default: return m; } })(option))) << (imm)))));
			}
		}
		return true;
	}
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
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (simm))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (simm))));
		} else {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (simm)));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (simm)));
		}
		return true;
	}
	/* ADD-shifted-register */
	if((inst & 0x7F200000U) == 0x0B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_294) -> string { switch(temp_294) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_295) -> RuntimeValue<uint> { switch(temp_295) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_296) -> RuntimeValue<uint> { switch(temp_296) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))));
		} else {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_297) -> RuntimeValue<ulong> { switch(temp_297) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_298) -> RuntimeValue<ulong> { switch(temp_298) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? SPR() : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))));
		}
		return true;
	}
	/* ADD-vector */
	if((inst & 0xBF20FC00U) == 0x0E208400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_299) -> string { switch(temp_299) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto v = ((RuntimeValue<Vector128<float>>) (([=](auto temp_300) -> RuntimeValue<Vector128<float>> { switch(temp_300) { case 0x0: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<byte>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + ((RuntimeValue<Vector128<byte>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); case 0x1: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ushort>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + ((RuntimeValue<Vector128<ushort>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); case 0x2: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<uint>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + ((RuntimeValue<Vector128<uint>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); case 0x3: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ulong>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + ((RuntimeValue<Vector128<ulong>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); default: throw "Not implemented"; } })(size))).Store();
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((Q) != 0 ? (v) : ((RuntimeValue<Vector128<float>>) (v)));
		return true;
	}
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
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) (simm));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) (simm));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		return true;
	}
	/* ADDS-shifted-register */
	if((inst & 0x7F200000U) == 0x2B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_301) -> string { switch(temp_301) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_302) -> RuntimeValue<uint> { switch(temp_302) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_303) -> RuntimeValue<ulong> { switch(temp_303) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		return true;
	}
	/* ADRP */
	if((inst & 0x9F000000U) == 0x90000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) (immlo)) << 12)))) | ((ulong) (((ulong) (immhi)) << 14)))), 33));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) ((ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) ((ulong) ((ulong) ((ulong) (((ulong) (pc)) >> (uint) (0xC)))))) << 12)))))) + ((ulong) (long) (imm)));
		XR[(int) rd] = addr;
		return true;
	}
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
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) & ((RuntimeValue<uint>) ((uint) ((uint) (imm)))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) & ((RuntimeValue<uint>) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) & ((RuntimeValue<ulong>) (imm))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) & ((RuntimeValue<ulong>) (imm))));
		}
		return true;
	}
	/* AND-shifted-register */
	if((inst & 0x7F200000U) == 0x0A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_304) -> string { switch(temp_304) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) & ((RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_305) -> RuntimeValue<uint> { switch(temp_305) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) & ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_306) -> RuntimeValue<ulong> { switch(temp_306) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))));
		}
		return true;
	}
	/* ANDS-shifted-register */
	if((inst & 0x7F200000U) == 0x6A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_307) -> string { switch(temp_307) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto result = ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) & ((RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_308) -> RuntimeValue<uint> { switch(temp_308) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) (result);
			NZCV_NR = (RuntimeValue<uint>) ((result) >> (0x1F));
			NZCV_ZR = (RuntimeValue<bool>) ((result) == (0x0));
			NZCV_CR = 0x0;
			NZCV_VR = 0x0;
		} else {
			auto result = ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) & ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_309) -> RuntimeValue<ulong> { switch(temp_309) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))).Store();
			XR[(int) rd] = result;
			NZCV_NR = (RuntimeValue<ulong>) ((result) >> (0x3F));
			NZCV_ZR = (RuntimeValue<bool>) ((result) == (0x0));
			NZCV_CR = 0x0;
			NZCV_VR = 0x0;
		}
		return true;
	}
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
			auto result = ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) & ((RuntimeValue<ulong>) (imm))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) (result);
			NZCV_NR = (RuntimeValue<uint>) ((result) >> (0x1F));
			NZCV_ZR = (RuntimeValue<bool>) ((result) == (0x0));
			NZCV_CR = 0x0;
			NZCV_VR = 0x0;
		} else {
			auto result = ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) & ((RuntimeValue<ulong>) (imm))))).Store();
			XR[(int) rd] = result;
			NZCV_NR = (RuntimeValue<ulong>) ((result) >> (0x3F));
			NZCV_ZR = (RuntimeValue<bool>) ((result) == (0x0));
			NZCV_CR = 0x0;
			NZCV_VR = 0x0;
		}
		return true;
	}
	/* ASRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))) >> ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x20))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))) >> ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x40)))))));
		}
		return true;
	}
	/* B */
	if((inst & 0xFC000000U) == 0x14000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28)))));
		Branch(addr);
		return true;
	}
	/* B.cond */
	if((inst & 0xFF000010U) == 0x54000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto cond = (inst >> 0) & 0xFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 21)))));
		auto condstr = (string) (([=](auto temp_310) -> string { switch(temp_310) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_311) -> RuntimeValue<bool> { switch(temp_311) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_312 = DefineLabel(), temp_314 = DefineLabel(), temp_313 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_312, temp_314);
		Label(temp_312);
		Branch(addr);
		Branch(temp_313);
		Label(temp_314);
		Branch(pc + 4);
		Branch(temp_313);
		Label(temp_313);
		return true;
	}
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
			auto dst = ((RuntimeValue<uint>) ((rd) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rd]()))).Store();
			auto src = ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Store();
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) (dst)) & ((RuntimeValue<uint>) ((uint) (~(wmask)))))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) (((src) << ((RuntimeValue<uint>) (32 - (immr)))) | ((src) >> ((RuntimeValue<uint>) (immr)))))) & ((RuntimeValue<uint>) (wmask))))))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) (dst)) & ((RuntimeValue<uint>) ((uint) (~(tmask)))))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) (bot)) & ((RuntimeValue<uint>) (tmask)))))))));
		} else {
			auto dst = ((RuntimeValue<ulong>) ((rd) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rd]())).Store();
			auto src = ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Store();
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (dst)) & ((RuntimeValue<ulong>) ((ulong) (~(wmask)))))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((src) << ((RuntimeValue<uint>) (64 - (immr)))) | ((src) >> ((RuntimeValue<uint>) (immr)))))) & ((RuntimeValue<ulong>) (wmask))))))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (dst)) & ((RuntimeValue<ulong>) ((ulong) (~(tmask)))))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (bot)) & ((RuntimeValue<ulong>) (tmask))))))));
		}
		return true;
	}
	/* BIC */
	if((inst & 0x7F200000U) == 0x0A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_315) -> string { switch(temp_315) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) & ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) (([=](auto temp_316) -> RuntimeValue<uint> { switch(temp_316) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) & ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) (([=](auto temp_317) -> RuntimeValue<ulong> { switch(temp_317) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))));
		}
		return true;
	}
	/* BIC-vector-register */
	if((inst & 0xBFE0FC00U) == 0x0E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto v = ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (~(((RuntimeValue<Vector128<byte>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)]))) & ((RuntimeValue<Vector128<byte>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)]))))))).Store();
		if(((bool) (((Q) == (0x1)) ? 1U : 0U)) != 0) {
			VR[(int) (rd)] = v;
		} else {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (v);
		}
		return true;
	}
	/* BL */
	if((inst & 0xFC000000U) == 0x94000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto offset = (long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (offset)));
		BranchLinked(addr);
		return true;
	}
	/* BLR */
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchLinkedRegister(rn);
		return true;
	}
	/* BR */
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchRegister(rn);
		return true;
	}
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
			auto cl = ((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))).Store();
			auto ch = ((RuntimeValue<uint>) (((ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))]()))).Store();
			auto nl = ((RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()))).Store();
			auto nh = ((RuntimeValue<uint>) (((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))]()))).Store();
			auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
			auto data = ((RuntimeValue<ulong>) (((RuntimePointer<ulong>) (address)).value)).Store();
			LabelTag temp_318 = DefineLabel(), temp_320 = DefineLabel(), temp_319 = DefineLabel();
			BranchIf((RuntimeValue<bool>) ((data) == ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (ch))) << (0x20)))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (cl)))))))), temp_318, temp_320);
			Label(temp_318);
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (nh))) << (0x20)))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (nl))))));
			Branch(temp_319);
			Label(temp_320);
			Branch(temp_319);
			Label(temp_319);
			XR[(int) rs] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (data)));
			XR[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) ((data) >> (0x20)))));
		} else {
			auto cl = ((RuntimeValue<ulong>) ((rs) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rs]())).Store();
			auto ch = ((RuntimeValue<ulong>) (((ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))]())).Store();
			auto nl = ((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())).Store();
			auto nh = ((RuntimeValue<ulong>) (((ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) (ulong) (((ulong) (byte) (rt)) + ((ulong) (long) (0x1)))]())).Store();
			auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
			auto dl = ((RuntimeValue<ulong>) (((RuntimePointer<ulong>) (address)).value)).Store();
			auto dh = ((RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value)).Store();
			LabelTag temp_321 = DefineLabel(), temp_323 = DefineLabel(), temp_322 = DefineLabel();
			BranchIf((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) ((dl) == (cl)))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) ((dh) == (ch)))))), temp_321, temp_323);
			Label(temp_321);
			((RuntimePointer<ulong>) (address)).value = nl;
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = nh;
			Branch(temp_322);
			Label(temp_323);
			Branch(temp_322);
			Label(temp_322);
			XR[(int) rs] = dl;
			XR[(int) (ulong) (((ulong) (byte) (rs)) + ((ulong) (long) (0x1)))] = dh;
		}
		return true;
	}
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
	/* CBNZ */
	if((inst & 0x7F000000U) == 0x35000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			LabelTag temp_324 = DefineLabel(), temp_326 = DefineLabel(), temp_325 = DefineLabel();
			BranchIf((RuntimeValue<bool>) (((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))) != ((uint) ((uint) (0x0)))), temp_324, temp_326);
			Label(temp_324);
			Branch(addr);
			Branch(temp_325);
			Label(temp_326);
			Branch(pc + 4);
			Branch(temp_325);
			Label(temp_325);
		} else {
			LabelTag temp_327 = DefineLabel(), temp_329 = DefineLabel(), temp_328 = DefineLabel();
			BranchIf((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((rs) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rs]())) != ((ulong) ((ulong) (0x0)))), temp_327, temp_329);
			Label(temp_327);
			Branch(addr);
			Branch(temp_328);
			Label(temp_329);
			Branch(pc + 4);
			Branch(temp_328);
			Label(temp_328);
		}
		return true;
	}
	/* CBZ */
	if((inst & 0x7F000000U) == 0x34000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			LabelTag temp_330 = DefineLabel(), temp_332 = DefineLabel(), temp_331 = DefineLabel();
			BranchIf((RuntimeValue<bool>) (((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))) == ((uint) ((uint) (0x0)))), temp_330, temp_332);
			Label(temp_330);
			Branch(addr);
			Branch(temp_331);
			Label(temp_332);
			Branch(pc + 4);
			Branch(temp_331);
			Label(temp_331);
		} else {
			LabelTag temp_333 = DefineLabel(), temp_335 = DefineLabel(), temp_334 = DefineLabel();
			BranchIf((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((rs) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rs]())) == ((ulong) ((ulong) (0x0)))), temp_333, temp_335);
			Label(temp_333);
			Branch(addr);
			Branch(temp_334);
			Label(temp_335);
			Branch(pc + 4);
			Branch(temp_334);
			Label(temp_334);
		}
		return true;
	}
	/* CCMN-immediate */
	if((inst & 0x7FE00C10U) == 0x3A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_336) -> string { switch(temp_336) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_337) -> RuntimeValue<bool> { switch(temp_337) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_338 = DefineLabel(), temp_340 = DefineLabel(), temp_339 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_338, temp_340);
		Label(temp_338);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) 0x1F] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) ((uint) (imm))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x0));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) 0x1F] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) ((ulong) (imm))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x0));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		Branch(temp_339);
		Label(temp_340);
		NZCVR = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		Branch(temp_339);
		Label(temp_339);
		return true;
	}
	/* CCMP-immediate */
	if((inst & 0x7FE00C10U) == 0x7A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_341) -> string { switch(temp_341) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_342) -> RuntimeValue<bool> { switch(temp_342) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_343 = DefineLabel(), temp_345 = DefineLabel(), temp_344 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_343, temp_345);
		Label(temp_343);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) 0x1F] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((uint) (imm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) 0x1F] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((ulong) (imm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		Branch(temp_344);
		Label(temp_345);
		NZCVR = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		Branch(temp_344);
		Label(temp_344);
		return true;
	}
	/* CCMP-register */
	if((inst & 0x7FE00C10U) == 0x7A400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_346) -> string { switch(temp_346) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_347) -> RuntimeValue<bool> { switch(temp_347) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_348 = DefineLabel(), temp_350 = DefineLabel(), temp_349 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_348, temp_350);
		Label(temp_348);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) 0x1F] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) 0x1F] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		Branch(temp_349);
		Label(temp_350);
		NZCVR = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		Branch(temp_349);
		Label(temp_349);
		return true;
	}
	/* CLREX */
	if((inst & 0xFFFFF0FFU) == 0xD503305FU) {
		auto crm = (inst >> 8) & 0xFU;
		return true;
	}
	/* CLZ */
	if((inst & 0x7FFFFC00U) == 0x5AC01000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Call<uint, uint>(CountLeadingZeros, (RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (Call<ulong, ulong>(CountLeadingZeros, (RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())));
		}
		return true;
	}
	/* CNT */
	if((inst & 0xBF3FFC00U) == 0x0E205800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_351) -> string { switch(temp_351) { case 0x0: return string("8B"); case 0x1: return string("16B"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (Call<Vector128<float>, Vector128<float>, long>(VectorCountBits, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), (long) (([=](auto temp_352) -> long { switch(temp_352) { case 0x0: return 0x8; default: return 0x10; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))))));
		return true;
	}
	/* CSEL */
	if((inst & 0x7FE00C00U) == 0x1A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_353) -> string { switch(temp_353) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_354) -> RuntimeValue<bool> { switch(temp_354) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_355 = DefineLabel(), temp_357 = DefineLabel(), temp_356 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_355, temp_357);
		Label(temp_355);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]());
		}
		Branch(temp_356);
		Label(temp_357);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]());
		}
		Branch(temp_356);
		Label(temp_356);
		return true;
	}
	/* CSINC */
	if((inst & 0x7FE00C00U) == 0x1A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_358) -> string { switch(temp_358) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_359) -> RuntimeValue<bool> { switch(temp_359) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_360 = DefineLabel(), temp_362 = DefineLabel(), temp_361 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_360, temp_362);
		Label(temp_360);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]());
		}
		Branch(temp_361);
		Label(temp_362);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) ((uint) ((uint) (0x1))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x1)));
		}
		Branch(temp_361);
		Label(temp_361);
		return true;
	}
	/* CSINV */
	if((inst & 0x7FE00C00U) == 0x5A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_363) -> string { switch(temp_363) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_364) -> RuntimeValue<bool> { switch(temp_364) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_365 = DefineLabel(), temp_367 = DefineLabel(), temp_366 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_365, temp_367);
		Label(temp_365);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]());
		}
		Branch(temp_366);
		Label(temp_367);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (~((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())));
		}
		Branch(temp_366);
		Label(temp_366);
		return true;
	}
	/* CSNEG */
	if((inst & 0x7FE00C00U) == 0x5A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_368) -> string { switch(temp_368) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_369) -> RuntimeValue<bool> { switch(temp_369) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_370 = DefineLabel(), temp_372 = DefineLabel(), temp_371 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_370, temp_372);
		Label(temp_370);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]());
		}
		Branch(temp_371);
		Label(temp_372);
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (-((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (-((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))))));
		}
		Branch(temp_371);
		Label(temp_371);
		return true;
	}
	/* DMB */
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU) {
		auto m = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_373) -> string { switch(temp_373) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(m));
		return true;
	}
	/* DSB */
	if((inst & 0xFFFFF0FFU) == 0xD503309FU) {
		auto crm = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_374) -> string { switch(temp_374) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(crm));
		return true;
	}
	/* DUP-general */
	if((inst & 0xBFE0FC00U) == 0x0E000C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto size = ((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((long) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x8)) ? 1U : 0U) != 0) ? (0x40) : (0x20)));
		auto r = (string) (((bool) (((size) == (0x40)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto T = ((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("16B")) : (string("8B")))) : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("8H")) : (string("4H")))) : ((string) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("4S")) : (string("2S")))) : ((string) ((Q != 0) ? (string("2D")) : throw "Not implemented"))))))));
		auto src = ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Store();
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0 ? ((RuntimeValue<Vector128<float>>) ((Q) != 0 ? ((RuntimeValue<Vector128<float>>) (((RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<byte>) (src)))).CreateVector())) : ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<byte>) (src)))).CreateVector()))))) : ((RuntimeValue<Vector128<float>>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U)) != 0 ? ((RuntimeValue<Vector128<float>>) ((Q) != 0 ? ((RuntimeValue<Vector128<float>>) (((RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (src)))).CreateVector())) : ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (src)))).CreateVector()))))) : ((RuntimeValue<Vector128<float>>) (((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U)) != 0 ? ((RuntimeValue<Vector128<float>>) ((Q) != 0 ? ((RuntimeValue<Vector128<float>>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (src)))).CreateVector())) : ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (src)))).CreateVector()))))) : ((RuntimeValue<Vector128<float>>) ((Q) != 0 ? ((RuntimeValue<Vector128<float>>) (((RuntimeValue<ulong>) (src)).CreateVector())) : throw "Not implemented")))))));
		return true;
	}
	/* DUP-element-scalar */
	if((inst & 0xFFE0FC00U) == 0x5E000400U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = string("");
		auto size = 0x0;
		auto index = (uint) ((uint) (0x0));
		if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				r = string("B");
				size = 0x8;
				index = (byte) ((imm) >> (uint) (0x1));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					r = string("H");
					size = 0x10;
					index = (byte) ((imm) >> (uint) (0x2));
				} else {
					if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						r = string("S");
						size = 0x20;
						index = (byte) ((imm) >> (uint) (0x3));
					} else {
						r = string("D");
						size = 0x40;
						index = (byte) ((imm) >> (uint) (0x4));
					}
				}
			}
		}
		switch(size) {
			case 0x8: {
				VBR[(int) (rd)] = (RuntimeValue<byte>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<byte>(index));
				break;
			}
			case 0x10: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(index));
				break;
			}
			case 0x20: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(index));
				break;
			}
			case 0x40: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(index));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* EON-shifted-register */
	if((inst & 0x7F200000U) == 0x4A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_375) -> string { switch(temp_375) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) ^ ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) (([=](auto temp_376) -> RuntimeValue<uint> { switch(temp_376) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) ^ ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) (([=](auto temp_377) -> RuntimeValue<ulong> { switch(temp_377) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))));
		}
		return true;
	}
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
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) ^ ((RuntimeValue<uint>) ((uint) ((uint) (imm)))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) ^ ((RuntimeValue<uint>) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) ^ ((RuntimeValue<ulong>) (imm))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) ^ ((RuntimeValue<ulong>) (imm))));
		}
		return true;
	}
	/* EOR-shifted-register */
	if((inst & 0x7F200000U) == 0x4A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_378) -> string { switch(temp_378) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) ^ ((RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_379) -> RuntimeValue<uint> { switch(temp_379) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) ^ ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_380) -> RuntimeValue<ulong> { switch(temp_380) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))));
		}
		return true;
	}
	/* EXT */
	if((inst & 0xBFE08400U) == 0x2E000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto index = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (Call<Vector128<float>, Vector128<float>, Vector128<float>, uint, uint>(VectorExtract, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), (RuntimeValue<Vector128<float>>) (VR[(int) (rm)]), Q, index));
		return true;
	}
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
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))) << ((ulong) (((ulong) (long) (0x20)) - ((ulong) (byte) (lsb))))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (lsb)))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())) << ((ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (lsb))))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (lsb))))));
		}
		return true;
	}
	/* FABS-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E20C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_381) -> string { switch(temp_381) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<float>) (VSR[(int) (rn)])).Abs());
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<double>) (VDR[(int) (rn)])).Abs());
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FABS-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_382) -> string { switch(temp_382) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto b = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) ((a).Abs()));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) ((b).Abs()));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto b = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto c = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x2))).Store();
				auto d = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x3))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) ((a).Abs()));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) ((b).Abs()));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<float>) ((c).Abs()));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<float>) ((d).Abs()));
				break;
			}
			case 0x3: {
				auto a = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x0))).Store();
				auto b = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<double>) ((double) ((double) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<double>) ((a).Abs()));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<double>) ((b).Abs()));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FADD-scalar */
	if((inst & 0xFF20FC00U) == 0x1E202800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_383) -> string { switch(temp_383) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x3: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (((RuntimeValue<ushort>) (RuntimeValue<ushort>) ((RuntimeValue<ushort>) (VHR[(int) (rn)]))) + ((RuntimeValue<ushort>) (RuntimeValue<ushort>) ((RuntimeValue<ushort>) (VHR[(int) (rm)]))))));
				break;
			}
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rn)]))) + ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rm)]))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rn)]))) + ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rm)]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FADD-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_384) -> string { switch(temp_384) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)]))));
				break;
			}
			case 0x1: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])));
				break;
			}
			case 0x3: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) + (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FADDP-scalar */
	if((inst & 0xFFBFFC00U) == 0x7E30D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0)))) + ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1)))));
		} else {
			VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x0)))) + ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x1)))));
		}
		return true;
	}
	/* FADDP-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_385) -> string { switch(temp_385) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto b = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto c = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x0))).Store();
				auto d = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) (a)) + ((RuntimeValue<float>) (RuntimeValue<float>) (b))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) (c)) + ((RuntimeValue<float>) (RuntimeValue<float>) (d))));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto b = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto c = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x2))).Store();
				auto d = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x3))).Store();
				auto e = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x0))).Store();
				auto f = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x1))).Store();
				auto g = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x2))).Store();
				auto h = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x3))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) (a)) + ((RuntimeValue<float>) (RuntimeValue<float>) (b))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) (c)) + ((RuntimeValue<float>) (RuntimeValue<float>) (d))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) (e)) + ((RuntimeValue<float>) (RuntimeValue<float>) (f))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) (g)) + ((RuntimeValue<float>) (RuntimeValue<float>) (h))));
				break;
			}
			case 0x3: {
				auto a = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x0))).Store();
				auto b = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x1))).Store();
				auto c = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<double>(0x0))).Store();
				auto d = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<double>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) (a)) + ((RuntimeValue<double>) (RuntimeValue<double>) (b))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) (c)) + ((RuntimeValue<double>) (RuntimeValue<double>) (d))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCCMP */
	if((inst & 0xFF200C10U) == 0x1E200400U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (([=](auto temp_386) -> string { switch(temp_386) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_387) -> string { switch(temp_387) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_388) -> RuntimeValue<bool> { switch(temp_388) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_389 = DefineLabel(), temp_391 = DefineLabel(), temp_390 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_389, temp_391);
		Label(temp_389);
		switch(type) {
			case 0x0: {
				auto __macro_fcmp_a = ((RuntimeValue<float>) (VSR[(int) (rn)])).Store();
				auto __macro_fcmp_b = ((RuntimeValue<float>) (VSR[(int) (rm)])).Store();
				NZCVR = (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<long>) (((RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a).IsNaN()))) | ((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_b).IsNaN())))))), 0x3, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) == (__macro_fcmp_b))), 0x6, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) < (__macro_fcmp_b))), 0x8, 0x2))))))) << (0x1C))));
				break;
			}
			case 0x1: {
				auto __macro_fcmp_a = ((RuntimeValue<double>) (VDR[(int) (rn)])).Store();
				auto __macro_fcmp_b = ((RuntimeValue<double>) (VDR[(int) (rm)])).Store();
				NZCVR = (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<long>) (((RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a).IsNaN()))) | ((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_b).IsNaN())))))), 0x3, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) == (__macro_fcmp_b))), 0x6, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) < (__macro_fcmp_b))), 0x8, 0x2))))))) << (0x1C))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		Branch(temp_390);
		Label(temp_391);
		NZCVR = (ulong) (((ulong) ((ulong) (nzcv))) << (uint) (0x1C));
		Branch(temp_390);
		Label(temp_390);
		return true;
	}
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
		auto top = (string) (([=](auto temp_392) -> string { switch(temp_392) { case 0x0: return string("EQ"); case 0x2: return string("GE"); case 0x3: return string("GE"); case 0x6: return string("GT"); case 0x7: return string("GT"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
		auto t = (string) (([=](auto temp_393) -> string { switch(temp_393) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto a1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto a2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto b1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x0))).Store();
				auto b2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (([=](auto temp_394) -> RuntimeValue<float> { switch(temp_394) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) == (b1))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) >= (b1))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x3: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a1).Abs())) >= ((RuntimeValue<float>) ((b1).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x6: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) > (b1))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x7: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a1).Abs())) > ((RuntimeValue<float>) ((b1).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (([=](auto temp_395) -> RuntimeValue<float> { switch(temp_395) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) == (b2))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) >= (b2))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x3: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a2).Abs())) >= ((RuntimeValue<float>) ((b2).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x6: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) > (b2))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x7: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a2).Abs())) > ((RuntimeValue<float>) ((b2).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				break;
			}
			case 0x1: {
				auto a1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto a2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto a3 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x2))).Store();
				auto a4 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x3))).Store();
				auto b1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x0))).Store();
				auto b2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x1))).Store();
				auto b3 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x2))).Store();
				auto b4 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(0x3))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (([=](auto temp_396) -> RuntimeValue<float> { switch(temp_396) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) == (b1))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) >= (b1))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x3: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a1).Abs())) >= ((RuntimeValue<float>) ((b1).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x6: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) > (b1))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x7: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a1).Abs())) > ((RuntimeValue<float>) ((b1).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (([=](auto temp_397) -> RuntimeValue<float> { switch(temp_397) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) == (b2))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) >= (b2))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x3: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a2).Abs())) >= ((RuntimeValue<float>) ((b2).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x6: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) > (b2))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x7: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a2).Abs())) > ((RuntimeValue<float>) ((b2).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<float>) (([=](auto temp_398) -> RuntimeValue<float> { switch(temp_398) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a3) == (b3))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a3) >= (b3))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x3: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a3).Abs())) >= ((RuntimeValue<float>) ((b3).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x6: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a3) > (b3))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x7: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a3).Abs())) > ((RuntimeValue<float>) ((b3).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<float>) (([=](auto temp_399) -> RuntimeValue<float> { switch(temp_399) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a4) == (b4))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a4) >= (b4))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x3: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a4).Abs())) >= ((RuntimeValue<float>) ((b4).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x6: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a4) > (b4))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x7: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<float>) ((a4).Abs())) > ((RuntimeValue<float>) ((b4).Abs())))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				break;
			}
			case 0x3: {
				auto a1 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x0))).Store();
				auto a2 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x1))).Store();
				auto b1 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<double>(0x0))).Store();
				auto b2 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<double>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<double>) (([=](auto temp_400) -> RuntimeValue<double> { switch(temp_400) { case 0x0: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) == (b1))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x2: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) >= (b1))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x3: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<double>) ((a1).Abs())) >= ((RuntimeValue<double>) ((b1).Abs())))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x6: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a1) > (b1))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x7: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<double>) ((a1).Abs())) > ((RuntimeValue<double>) ((b1).Abs())))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<double>) (([=](auto temp_401) -> RuntimeValue<double> { switch(temp_401) { case 0x0: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) == (b2))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x2: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) >= (b2))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x3: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<double>) ((a2).Abs())) >= ((RuntimeValue<double>) ((b2).Abs())))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x6: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a2) > (b2))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x7: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<double>) ((a2).Abs())) > ((RuntimeValue<double>) ((b2).Abs())))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2)))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCMxx-zero-vector */
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto op = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_402) -> string { switch(temp_402) { case 0x0: return string("GT"); case 0x1: return string("GE"); case 0x2: return string("EQ"); default: return string("LE"); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
		auto t = (string) (([=](auto temp_403) -> string { switch(temp_403) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto v1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto v2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (([=](auto temp_404) -> RuntimeValue<float> { switch(temp_404) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) > ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x1: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) >= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) == ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: return (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) <= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (([=](auto temp_405) -> RuntimeValue<float> { switch(temp_405) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) > ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x1: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) >= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) == ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: return (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) <= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				break;
			}
			case 0x1: {
				auto v1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto v2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto v3 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x2))).Store();
				auto v4 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x3))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (([=](auto temp_406) -> RuntimeValue<float> { switch(temp_406) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) > ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x1: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) >= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) == ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: return (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) <= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (([=](auto temp_407) -> RuntimeValue<float> { switch(temp_407) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) > ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x1: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) >= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) == ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: return (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) <= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<float>) (([=](auto temp_408) -> RuntimeValue<float> { switch(temp_408) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v3) > ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x1: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v3) >= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v3) == ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: return (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v3) <= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<float>) (([=](auto temp_409) -> RuntimeValue<float> { switch(temp_409) { case 0x0: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v4) > ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x1: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v4) >= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); case 0x2: return (RuntimeValue<float>) ((RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v4) == ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0))))))); default: return (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v4) <= ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				break;
			}
			case 0x3: {
				auto v1 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x0))).Store();
				auto v2 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<double>) (([=](auto temp_410) -> RuntimeValue<double> { switch(temp_410) { case 0x0: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) > ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x1: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) >= ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x2: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) == ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); default: return (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) <= ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<double>) (([=](auto temp_411) -> RuntimeValue<double> { switch(temp_411) { case 0x0: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) > ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x1: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) >= ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); case 0x2: return (RuntimeValue<double>) ((RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) == ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0))))))); default: return (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) <= ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0)))))); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1)))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCMLT-zero-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_412) -> string { switch(temp_412) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto v1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto v2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) < ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) < ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))));
				break;
			}
			case 0x1: {
				auto v1 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x0))).Store();
				auto v2 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x1))).Store();
				auto v3 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x2))).Store();
				auto v4 = ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(0x3))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) < ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) < ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v3) < ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v4) < ((float) ((float) (0x0))))), (float) (Bitcast<int, float>((int) ((int) (-0x1)))), (float) (Bitcast<int, float>((int) ((int) (0x0)))))));
				break;
			}
			case 0x3: {
				auto v1 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x0))).Store();
				auto v2 = ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<int>) ((int) ((int) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v1) < ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0)))))));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((v2) < ((double) ((double) (0x0))))), (double) (Bitcast<long, double>((long) ((long) (-0x1)))), (double) (Bitcast<long, double>((long) ((long) (0x0)))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCMP */
	if((inst & 0xFF20FC17U) == 0x1E202000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto opc = (inst >> 3) & 0x1U;
		auto r = (string) (([=](auto temp_413) -> string { switch(temp_413) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto zero = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("/0")) : (string("")));
		switch(type) {
			case 0x0: {
				auto __macro_fcmp_a = ((RuntimeValue<float>) (VSR[(int) (rn)])).Store();
				auto __macro_fcmp_b = ((RuntimeValue<float>) (((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0 ? ((float) ((float) (0x0))) : ((RuntimeValue<float>) (VSR[(int) (rm)])))).Store();
				NZCVR = (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<long>) (((RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a).IsNaN()))) | ((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_b).IsNaN())))))), 0x3, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) == (__macro_fcmp_b))), 0x6, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) < (__macro_fcmp_b))), 0x8, 0x2))))))) << (0x1C))));
				break;
			}
			case 0x1: {
				auto __macro_fcmp_a = ((RuntimeValue<double>) (VDR[(int) (rn)])).Store();
				auto __macro_fcmp_b = ((RuntimeValue<double>) (((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0 ? ((double) ((double) (0x0))) : ((RuntimeValue<double>) (VDR[(int) (rm)])))).Store();
				NZCVR = (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<long>) (((RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a).IsNaN()))) | ((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_b).IsNaN())))))), 0x3, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) == (__macro_fcmp_b))), 0x6, (RuntimeValue<long>) (Ternary<bool, long>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((__macro_fcmp_a) < (__macro_fcmp_b))), 0x8, 0x2))))))) << (0x1C))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCSEL */
	if((inst & 0xFF200C00U) == 0x1E200C00U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_414) -> string { switch(temp_414) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_415) -> string { switch(temp_415) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		auto result = ((RuntimeValue<bool>) (([=](auto temp_416) -> RuntimeValue<bool> { switch(temp_416) { case 0x0: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_ZR)); case 0x1: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR)); case 0x2: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_NR)); case 0x3: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_VR)); case 0x4: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (NZCV_CR))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); case 0x5: return (RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR)))); case 0x6: return (RuntimeValue<bool>) ((RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<bool>) (NZCV_NR)) == ((RuntimeValue<bool>) (NZCV_VR))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (!((RuntimeValue<bool>) (NZCV_ZR)))))))); default: return 0x1; } })((byte) ((cond) >> (uint) (0x1))))).Store();
		LabelTag temp_417 = DefineLabel(), temp_419 = DefineLabel(), temp_418 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((byte) ((((byte) ((byte) ((((ulong) (cond)) & ((ulong) (0x1)))))) & ((byte) ((bool) (((cond) != (0xF)) ? 1U : 0U)))))) != 0 ? ((RuntimeValue<bool>) (!(result))) : (result)), temp_417, temp_419);
		Label(temp_417);
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (VSR[(int) (rn)]);
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (VDR[(int) (rn)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		Branch(temp_418);
		Label(temp_419);
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (VSR[(int) (rm)]);
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (VDR[(int) (rm)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		Branch(temp_418);
		Label(temp_418);
		return true;
	}
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
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<ushort>) (VHR[(int) (rn)])));
				break;
			}
			case 0xD: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<ushort>) (VHR[(int) (rn)])));
				break;
			}
			case 0x3: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<float>) (VSR[(int) (rn)])));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<float>) (VSR[(int) (rn)])));
				break;
			}
			case 0x7: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<double>) (VDR[(int) (rn)])));
				break;
			}
			case 0x4: {
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<double>) (VDR[(int) (rn)])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTZS-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E180000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_420) -> string { switch(temp_420) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch((byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))))) {
			case 0x0: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Call<uint, float, int>(FloatToFixed32, (RuntimeValue<float>) (VSR[(int) (rn)]), (RuntimeValue<int>) (fbits))));
				break;
			}
			case 0x4: {
				XR[(int) rd] = (RuntimeValue<ulong>) (Call<ulong, float, int>(FloatToFixed64, (RuntimeValue<float>) (VSR[(int) (rn)]), (RuntimeValue<int>) (fbits)));
				break;
			}
			case 0x1: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Call<uint, double, int>(FloatToFixed32, (RuntimeValue<double>) (VDR[(int) (rn)]), (RuntimeValue<int>) (fbits))));
				break;
			}
			case 0x5: {
				XR[(int) rd] = (RuntimeValue<ulong>) (Call<ulong, double, int>(FloatToFixed64, (RuntimeValue<double>) (VDR[(int) (rn)]), (RuntimeValue<int>) (fbits)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
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
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<float>) (VSR[(int) (rn)]))))));
				break;
			}
			case 0x4: {
				XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<float>) (VSR[(int) (rn)])))));
				break;
			}
			case 0x1: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<double>) (VDR[(int) (rn)]))))));
				break;
			}
			case 0x5: {
				XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<double>) (VDR[(int) (rn)])))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FCVTZU-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E190000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (ulong) (((ulong) (long) (0x40)) - ((ulong) (byte) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_421) -> string { switch(temp_421) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch((byte) ((byte) (((byte) (((byte) (type)) << 0)) | ((byte) (((byte) (size)) << 2))))) {
			case 0x0: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Call<uint, float, int>(FloatToFixed32, (RuntimeValue<float>) (VSR[(int) (rn)]), (RuntimeValue<int>) (fbits))));
				break;
			}
			case 0x4: {
				XR[(int) rd] = (RuntimeValue<ulong>) (Call<ulong, float, int>(FloatToFixed64, (RuntimeValue<float>) (VSR[(int) (rn)]), (RuntimeValue<int>) (fbits)));
				break;
			}
			case 0x1: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Call<uint, double, int>(FloatToFixed32, (RuntimeValue<double>) (VDR[(int) (rn)]), (RuntimeValue<int>) (fbits))));
				break;
			}
			case 0x5: {
				XR[(int) rd] = (RuntimeValue<ulong>) (Call<ulong, double, int>(FloatToFixed64, (RuntimeValue<double>) (VDR[(int) (rn)]), (RuntimeValue<int>) (fbits)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
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
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<float>) (VSR[(int) (rn)]))));
				break;
			}
			case 0x4: {
				XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<float>) (VSR[(int) (rn)])));
				break;
			}
			case 0x1: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<double>) (VDR[(int) (rn)]))));
				break;
			}
			case 0x5: {
				XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<double>) (VDR[(int) (rn)])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FDIV-scalar */
	if((inst & 0xFF20FC00U) == 0x1E201800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_422) -> string { switch(temp_422) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x3: {
				throw "Not implemented";
				break;
			}
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rn)]))) / ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rm)]))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rn)]))) / ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rm)]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMAX-scalar */
	if((inst & 0xFF20FC00U) == 0x1E204800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_423) -> string { switch(temp_423) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = ((RuntimeValue<float>) (VSR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<float>) (VSR[(int) (rm)])).Store();
				VSR[(int) (rd)] = (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) > (b))), a, b));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<double>) (VDR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<double>) (VDR[(int) (rm)])).Store();
				VDR[(int) (rd)] = (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) > (b))), a, b));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMAXNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E206800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_424) -> string { switch(temp_424) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = ((RuntimeValue<float>) (VSR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<float>) (VSR[(int) (rm)])).Store();
				VSR[(int) (rd)] = (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) > (b))), a, b));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<double>) (VDR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<double>) (VDR[(int) (rm)])).Store();
				VDR[(int) (rd)] = (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) > (b))), a, b));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMIN-scalar */
	if((inst & 0xFF20FC00U) == 0x1E205800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_425) -> string { switch(temp_425) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = ((RuntimeValue<float>) (VSR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<float>) (VSR[(int) (rm)])).Store();
				VSR[(int) (rd)] = (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) < (b))), a, b));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<double>) (VDR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<double>) (VDR[(int) (rm)])).Store();
				VDR[(int) (rd)] = (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) < (b))), a, b));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMINNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E207800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_426) -> string { switch(temp_426) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				auto a = ((RuntimeValue<float>) (VSR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<float>) (VSR[(int) (rm)])).Store();
				VSR[(int) (rd)] = (RuntimeValue<float>) (Ternary<bool, float>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) < (b))), a, b));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<double>) (VDR[(int) (rn)])).Store();
				auto b = ((RuntimeValue<double>) (VDR[(int) (rm)])).Store();
				VDR[(int) (rd)] = (RuntimeValue<double>) (Ternary<bool, double>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((a) < (b))), a, b));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMLA-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F801000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_427) -> string { switch(temp_427) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_428) -> uint { switch(temp_428) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rd)])) + (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<double>) ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<double>(index)))).CreateVector())))))));
		} else {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rd)])) + ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(index)))).CreateVector())))));
		}
		return true;
	}
	/* FMLA-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_429) -> string { switch(temp_429) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rd)])) + (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))));
		} else {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rd)])) + ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))));
		}
		return true;
	}
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
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ushort>) (VHR[(int) (rn)]))));
				break;
			}
			case 0xE6: {
				XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (VHR[(int) (rn)])));
				break;
			}
			case 0x67: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))));
				break;
			}
			case 0x7: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Bitcast<float>());
				break;
			}
			case 0x6: {
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<float>) (VSR[(int) (rn)])).Bitcast<uint>()));
				break;
			}
			case 0xE7: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())));
				break;
			}
			case 0xA7: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Bitcast<double>());
				break;
			}
			case 0xA6: {
				XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<double>) (VDR[(int) (rn)])).Bitcast<ulong>());
				break;
			}
			case 0xCE: {
				XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<double>) (VDR[(int) ((byte) ((((ulong) ((byte) ((rn) << (uint) (0x1)))) | ((ulong) (0x1)))))])).Bitcast<ulong>());
				break;
			}
			case 0xCF: {
				VDR[(int) ((byte) ((((ulong) ((byte) ((rd) << (uint) (0x1)))) | ((ulong) (0x1)))))] = (RuntimeValue<double>) (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Bitcast<double>());
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMOV-scalar-immediate */
	if((inst & 0xFF201FE0U) == 0x1E201000U) {
		auto type = (inst >> 22) & 0x3U;
		auto imm = (inst >> 13) & 0xFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_430) -> string { switch(temp_430) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto sv = (float) (Bitcast<uint, float>((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((bool) ((bool) (0x0)))) << 0)) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 1)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 2)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 3)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 4)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 5)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 6)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 7)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 8)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 9)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 10)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 11)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 12)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 13)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 14)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 15)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 16)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 17)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 18)))))) << 0)) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 19)))) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 23)))) | ((uint) (((uint) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))))) << 25)))) | ((uint) (((uint) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 30)))) | ((uint) (((uint) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 31))))));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = sv;
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (double) (Bitcast<ulong, double>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ulong) ((ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (ulong) (((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 0)) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 1)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 2)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 3)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 4)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 5)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 6)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 7)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 8)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 9)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 10)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 11)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 12)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 13)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 14)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 15)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 16)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 17)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 18)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 19)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 20)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 21)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 22)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 23)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 24)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 25)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 26)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 27)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 28)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 29)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 30)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 31)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 32)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 33)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 34)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 35)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 36)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 37)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 38)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 39)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 40)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 41)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 42)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 43)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 44)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 45)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 46)))) | ((ulong) (((ulong) ((bool) ((bool) (0x0)))) << 47)))))) << 0)) | ((ulong) (((ulong) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 48)))) | ((ulong) (((ulong) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 52)))) | ((ulong) (((ulong) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 5)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 6)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 7)))))) << 54)))) | ((ulong) (((ulong) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 62)))) | ((ulong) (((ulong) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 63))))));
				break;
			}
		}
		return true;
	}
	/* FMUL-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F809000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_431) -> string { switch(temp_431) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_432) -> uint { switch(temp_432) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		if((sz) != 0) {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<double>) ((RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<double>(index)))).CreateVector()))));
		} else {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<float>(index)))).CreateVector())));
		}
		return true;
	}
	/* FMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E200800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_433) -> string { switch(temp_433) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rn)]))) * ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rm)]))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rn)]))) * ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rm)]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FMUL-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_434) -> string { switch(temp_434) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)]))));
				break;
			}
			case 0x1: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])));
				break;
			}
			case 0x3: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FNEG */
	if((inst & 0xFF3FFC00U) == 0x1E214000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_435) -> string { switch(temp_435) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (-((RuntimeValue<float>) (VSR[(int) (rn)])));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (-((RuntimeValue<double>) (VDR[(int) (rn)])));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FNMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E208800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_436) -> string { switch(temp_436) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (-((RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rn)]))) * ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rm)]))))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (-((RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rn)]))) * ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rm)]))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FRSQRTE-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_437) -> string { switch(temp_437) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (([=](auto temp_438) -> RuntimeValue<Vector128<float>> { switch(temp_438) { case 0x0: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (Call<Vector128<float>, Vector128<float>, int, int>(VectorFrsqrte, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), 0x20, 0x2))); case 0x1: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (Call<Vector128<float>, Vector128<float>, int, int>(VectorFrsqrte, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), 0x20, 0x4))); case 0x3: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (Call<Vector128<float>, Vector128<float>, int, int>(VectorFrsqrte, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), 0x40, 0x2))); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return true;
	}
	/* FRSQRTS-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_439) -> string { switch(temp_439) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		switch((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x3)))).CreateVector())) - ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))) / ((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x2)))).CreateVector()))));
				break;
			}
			case 0x1: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x3)))).CreateVector())) - ((RuntimeValue<Vector128<float>>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))) / ((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) ((float) (0x2)))).CreateVector())));
				break;
			}
			case 0x3: {
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<double>) ((double) ((double) (0x3)))).CreateVector())) - (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))))) / (RuntimeValue<Vector128<double>>) ((RuntimeValue<Vector128<float>>) (((RuntimeValue<double>) ((double) ((double) (0x2)))).CreateVector()))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FSQRT-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E21C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_440) -> string { switch(temp_440) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<double>) ((RuntimeValue<float>) (VSR[(int) (rn)]))).Sqrt());
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rn)]))).Sqrt());
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* FSUB-scalar */
	if((inst & 0xFF20FC00U) == 0x1E203800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_441) -> string { switch(temp_441) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		switch(type) {
			case 0x0: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rn)]))) - ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) (VSR[(int) (rm)]))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rn)]))) - ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) (VDR[(int) (rm)]))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
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
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(index, (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))));
		} else {
			if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(index, (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					VR[(int) (rd)] = VR[(int) (rd)]().Insert(index, (RuntimeValue<float>) (((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Bitcast<float>()));
				} else {
					VR[(int) (rd)] = VR[(int) (rd)]().Insert(index, (RuntimeValue<double>) (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Bitcast<double>()));
				}
			}
		}
		return true;
	}
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
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(index1, (RuntimeValue<byte>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<byte>(index2)));
		} else {
			if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(index1, (RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(index2)));
			} else {
				if(((bool) ((((byte) ((((ulong) (imm5)) & ((ulong) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					VR[(int) (rd)] = VR[(int) (rd)]().Insert(index1, (RuntimeValue<float>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<float>(index2)));
				} else {
					VR[(int) (rd)] = VR[(int) (rd)]().Insert(index1, (RuntimeValue<double>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<double>(index2)));
				}
			}
		}
		return true;
	}
	/* LDAR */
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value));
		} else {
			auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
			XR[(int) rt] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) (address)).value);
		}
		return true;
	}
	/* LDARB */
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value)));
		return true;
	}
	/* LDARH */
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value)));
		return true;
	}
	/* LDAXB */
	if((inst & 0xBFFFFC00U) == 0x885FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Exclusive32R = ((RuntimePointer<uint>) (address)).value));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) (Exclusive64R = ((RuntimePointer<ulong>) (address)).value);
		}
		return true;
	}
	/* LDAXRB */
	if((inst & 0xFFFFFC00U) == 0x085FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<byte>) (Exclusive8R = ((RuntimePointer<byte>) (address)).value)));
		return true;
	}
	/* LDAXRH */
	if((inst & 0xFFFFFC00U) == 0x485FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (Exclusive16R = ((RuntimePointer<ushort>) (address)).value)));
		return true;
	}
	/* LDP-immediate-postindex */
	if((inst & 0x7FC00000U) == 0x28C00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rt1] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value));
			XR[(int) rt2] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value));
		} else {
			XR[(int) rt1] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) (address)).value);
			XR[(int) rt2] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value);
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* LDP-immediate-signed-offset */
	if((inst & 0x7FC00000U) == 0x29400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rt1] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value));
			XR[(int) rt2] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value));
		} else {
			XR[(int) rt1] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) (address)).value);
			XR[(int) rt2] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value);
		}
		return true;
	}
	/* LDP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2CC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_442) -> string { switch(temp_442) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_443) -> long { switch(temp_443) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		switch(opc) {
			case 0x0: {
				VSR[(int) (rt1)] = (RuntimeValue<float>) (((RuntimePointer<float>) (address)).value);
				VSR[(int) (rt2)] = (RuntimeValue<float>) (((RuntimePointer<float>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value);
				break;
			}
			case 0x1: {
				VDR[(int) (rt1)] = (RuntimeValue<double>) (((RuntimePointer<double>) (address)).value);
				VDR[(int) (rt2)] = (RuntimeValue<double>) (((RuntimePointer<double>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value);
				break;
			}
			default: {
				VR[(int) (rt1)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) (address)).value);
				VR[(int) (rt2)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x10))))).value);
				break;
			}
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* LDP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D400000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_444) -> string { switch(temp_444) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_445) -> long { switch(temp_445) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		switch(opc) {
			case 0x0: {
				VSR[(int) (rt1)] = (RuntimeValue<float>) (((RuntimePointer<float>) (address)).value);
				VSR[(int) (rt2)] = (RuntimeValue<float>) (((RuntimePointer<float>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value);
				break;
			}
			case 0x1: {
				VDR[(int) (rt1)] = (RuntimeValue<double>) (((RuntimePointer<double>) (address)).value);
				VDR[(int) (rt2)] = (RuntimeValue<double>) (((RuntimePointer<double>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value);
				break;
			}
			default: {
				VR[(int) (rt1)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) (address)).value);
				VR[(int) (rt2)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x10))))).value);
				break;
			}
		}
		return true;
	}
	/* LDPSW-immediate-signed-offset */
	if((inst & 0xFFC00000U) == 0x69400000U) {
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) (0x2));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		XR[(int) rt1] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value), 32))));
		XR[(int) rt2] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value), 32))));
		return true;
	}
	/* LDR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8400C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) (address)).value);
		}
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8400400U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value);
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		return true;
	}
	/* LDR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value);
		}
		return true;
	}
	/* LDR-simd-immediate-postindex */
	if((inst & 0x3F600C00U) == 0x3C400400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_446) -> string { switch(temp_446) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VBR[(int) (rt)] = (RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value);
				break;
			}
			case 0x2: {
				VHR[(int) (rt)] = (RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value);
				break;
			}
			case 0x4: {
				VSR[(int) (rt)] = (RuntimeValue<float>) (((RuntimePointer<float>) (address)).value);
				break;
			}
			case 0x6: {
				VDR[(int) (rt)] = (RuntimeValue<double>) (((RuntimePointer<double>) (address)).value);
				break;
			}
			case 0x1: {
				VR[(int) (rt)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) (address)).value);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* LDR-simd-immediate-preindex */
	if((inst & 0x3F600C00U) == 0x3C400C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_447) -> string { switch(temp_447) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VBR[(int) (rt)] = (RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value);
				break;
			}
			case 0x2: {
				VHR[(int) (rt)] = (RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value);
				break;
			}
			case 0x4: {
				VSR[(int) (rt)] = (RuntimeValue<float>) (((RuntimePointer<float>) (address)).value);
				break;
			}
			case 0x6: {
				VDR[(int) (rt)] = (RuntimeValue<double>) (((RuntimePointer<double>) (address)).value);
				break;
			}
			case 0x1: {
				VR[(int) (rt)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) (address)).value);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDR-simd-immediate-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto ropc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto opc = (byte) ((byte) (((byte) (((byte) ((bool) ((bool) (0x1)))) << 0)) | ((byte) (((byte) (ropc)) << 1))));
		auto m = (byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_448) -> string { switch(temp_448) { case 0x1: return string("B"); case 0x5: return string("H"); case 0x9: return string("S"); case 0xD: return string("D"); default: return string("Q"); } })(m));
		auto imm = (uint) (((uint) ((uint) (rawimm))) << (uint) ((long) (([=](auto temp_449) -> long { switch(temp_449) { case 0x1: return 0x0; case 0x5: return 0x1; case 0x9: return 0x2; case 0xD: return 0x3; default: return 0x4; } })(m))));
		switch(m) {
			case 0x1: {
				VBR[(int) (rt)] = (RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (imm))))).value);
				break;
			}
			case 0x5: {
				VHR[(int) (rt)] = (RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (imm))))).value);
				break;
			}
			case 0x9: {
				VSR[(int) (rt)] = (RuntimeValue<float>) (((RuntimePointer<float>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (imm))))).value);
				break;
			}
			case 0xD: {
				VDR[(int) (rt)] = (RuntimeValue<double>) (((RuntimePointer<double>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (imm))))).value);
				break;
			}
			default: {
				VR[(int) (rt)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<uint>) (imm))))).value);
				break;
			}
		}
		return true;
	}
	/* LDR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C600800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (string("Q")) : ((string) (([=](auto temp_450) -> string { switch(temp_450) { case 0x0: return string("B"); case 0x1: return string("H"); case 0x2: return string("S"); case 0x3: return string("D"); default: throw "Not implemented"; } })(size))));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (([=](auto temp_451) -> string { switch(temp_451) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto amount = (ulong) (((ulong) (bool) (scale)) * ((ulong) (long) ((long) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (0x4) : ((long) (([=](auto temp_452) -> long { switch(temp_452) { case 0x0: return 0x1; case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: throw "Not implemented"; } })(size)))))));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (([=](auto temp_453) -> RuntimeValue<ulong> { switch(temp_453) { case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))); case 0x3: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())); case 0x6: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))); case 0x7: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())); default: throw "Not implemented"; } })(option))) << (amount))).Store();
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset)))).Store();
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VBR[(int) (rt)] = (RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value);
				break;
			}
			case 0x4: {
				VSR[(int) (rt)] = (RuntimeValue<float>) (((RuntimePointer<float>) (address)).value);
				break;
			}
			case 0x6: {
				VDR[(int) (rt)] = (RuntimeValue<double>) (((RuntimePointer<double>) (address)).value);
				break;
			}
			case 0x1: {
				VR[(int) (rt)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) (address)).value);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
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
		auto extend = (string) (([=](auto temp_454) -> string { switch(temp_454) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value);
		}
		return true;
	}
	/* LDRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value))));
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		return true;
	}
	/* LDRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value))));
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39400000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value)));
		return true;
	}
	/* LDRB-register */
	if((inst & 0xFFE00C00U) == 0x38600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_455) -> string { switch(temp_455) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value));
		return true;
	}
	/* LDRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value)));
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		return true;
	}
	/* LDRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value)));
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79400000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value)));
		return true;
	}
	/* LDRH-register */
	if((inst & 0xFFE00C00U) == 0x78600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_456) -> string { switch(temp_456) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value));
		return true;
	}
	/* LDRSB-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x38800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value), 8)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value), 8))));
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		return true;
	}
	/* LDRSB-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x38800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value), 8)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value), 8))));
		}
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDRSB-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x39800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value), 8)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value), 8))));
		}
		return true;
	}
	/* LDRSB-register */
	if((inst & 0xFFA00C00U) == 0x38A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_457) -> string { switch(temp_457) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value), 8)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value), 8))));
		}
		return true;
	}
	/* LDRSH-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x78800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value), 16)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value), 16))));
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		return true;
	}
	/* LDRSH-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x78800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value), 16)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) (address)).value), 16))));
		}
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDRSH-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x79800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value), 16)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value), 16))));
		}
		return true;
	}
	/* LDRSH-register */
	if((inst & 0xFFA00C00U) == 0x78A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_458) -> string { switch(temp_458) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value), 16)))));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value), 16))));
		}
		return true;
	}
	/* LDRSW-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0xB8800400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value), 32))));
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)));
		return true;
	}
	/* LDRSW-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0xB8800C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) (address)).value), 32))));
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* LDRSW-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0xB9800000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x2));
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value), 32))));
		return true;
	}
	/* LDRSW-register */
	if((inst & 0xFFE00C00U) == 0xB8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0x2));
		auto extend = (string) (([=](auto temp_459) -> string { switch(temp_459) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value), 32))));
		return true;
	}
	/* LDUR */
	if((inst & 0xBFE00C00U) == 0xB8400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value);
		}
		return true;
	}
	/* LDURB */
	if((inst & 0xFFE00C00U) == 0x38400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value)));
		return true;
	}
	/* LDURH */
	if((inst & 0xFFE00C00U) == 0x78400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value)));
		return true;
	}
	/* LDURSB */
	if((inst & 0xFFA00C00U) == 0x38800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value), 8)))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) (((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value), 8))));
		}
		return true;
	}
	/* LDURSH */
	if((inst & 0xFFA00C00U) == 0x78800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		if(((bool) (((opc) == (0x1)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value), 16)))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) (((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value), 16))));
		}
		return true;
	}
	/* LDURSW */
	if((inst & 0xFFE00C00U) == 0xB8800000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) (((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm))))).value), 32))));
		return true;
	}
	/* LDUR-simd */
	if((inst & 0x3F600C00U) == 0x3C400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_460) -> string { switch(temp_460) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (imm)))).Store();
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				VBR[(int) (rt)] = (RuntimeValue<byte>) (((RuntimePointer<byte>) (address)).value);
				break;
			}
			case 0x4: {
				VSR[(int) (rt)] = (RuntimeValue<float>) (((RuntimePointer<float>) (address)).value);
				break;
			}
			case 0x6: {
				VDR[(int) (rt)] = (RuntimeValue<double>) (((RuntimePointer<double>) (address)).value);
				break;
			}
			case 0x1: {
				VR[(int) (rt)] = (RuntimeValue<Vector128<float>>) (((RuntimePointer<Vector128<float>>) (address)).value);
				break;
			}
		}
		return true;
	}
	/* LDXR */
	if((inst & 0xBFFFFC00U) == 0x885F7C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rt] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Exclusive32R = ((RuntimePointer<uint>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value));
		} else {
			XR[(int) rt] = (RuntimeValue<ulong>) (Exclusive64R = ((RuntimePointer<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value);
		}
		return true;
	}
	/* LDXRB */
	if((inst & 0xFFFFFC00U) == 0x085F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<byte>) (Exclusive8R = ((RuntimePointer<byte>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value)));
		return true;
	}
	/* LDXRH */
	if((inst & 0xFFFFFC00U) == 0x485F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		XR[(int) rt] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ushort>) (Exclusive16R = ((RuntimePointer<ushort>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value)));
		return true;
	}
	/* LSL-register */
	if((inst & 0x7FE0FC00U) == 0x1AC02000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))) << ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x20))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())) << ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x40)))));
		}
		return true;
	}
	/* LSRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))) >> ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x20))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())) >> ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x40)))));
		}
		return true;
	}
	/* MADD */
	if((inst & 0x7FE08000U) == 0x1B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) * ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((ra) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) ra]()))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) * ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((ra) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) ra]()))));
		}
		return true;
	}
	/* MOVI-32bit */
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
		auto amount = (long) (([=](auto temp_461) -> long { switch(temp_461) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		auto avec = ((RuntimeValue<Vector128<float>>) (((RuntimeValue<float>) ((float) (Bitcast<uint, float>((uint) (((uint) ((uint) (imm))) << (uint) (amount)))))).CreateVector())).Store();
		if((Q) != 0) {
			VR[(int) (rd)] = avec;
		} else {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (avec);
		}
		return true;
	}
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
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<ulong>) (imm)).CreateVector());
		return true;
	}
	/* MOVK */
	if((inst & 0x7F800000U) == 0x72800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rd) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rd]())))) & ((RuntimeValue<uint>) ((uint) ((((uint) ((uint) ((uint) (-0x1)))) ^ ((uint) ((uint) (((uint) ((uint) (0xFFFF))) << (uint) (shift)))))))))))) | ((RuntimeValue<uint>) ((uint) (((uint) ((uint) (imm))) << (uint) (shift)))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rd]()))) & ((RuntimeValue<ulong>) ((ulong) ((((ulong) ((ulong) ((ulong) (-0x1)))) ^ ((ulong) ((ulong) (((ulong) ((ulong) (0xFFFF))) << (uint) (shift)))))))))))) | ((RuntimeValue<ulong>) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift))))));
		}
		return true;
	}
	/* MOVN */
	if((inst & 0x7F800000U) == 0x12800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((uint) (~((uint) (((uint) ((uint) (imm))) << (uint) (shift)))));
		} else {
			XR[(int) rd] = (ulong) (~((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift))));
		}
		return true;
	}
	/* MOVZ */
	if((inst & 0x7F800000U) == 0x52800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((uint) (((uint) ((uint) (imm))) << (uint) (shift)));
		} else {
			XR[(int) rd] = (ulong) (((ulong) ((ulong) (imm))) << (uint) (shift));
		}
		return true;
	}
	/* MRS */
	if((inst & 0xFFF00000U) == 0xD5300000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		XR[(int) rt] = (RuntimeValue<ulong>) (Call<ulong, uint, uint, uint, uint, uint>(SR, op0, op1, cn, cm, op2));
		return true;
	}
	/* MSR-register */
	if((inst & 0xFFF00000U) == 0xD5100000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		Call<void, uint, uint, uint, uint, uint, ulong>(SR, op0, op1, cn, cm, op2, (RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]()));
		return true;
	}
	/* MSUB */
	if((inst & 0x7FE08000U) == 0x1B008000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((ra) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) ra]())))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) * ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((ra) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) ra]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) * ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))))));
		}
		return true;
	}
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
		auto t = (string) (([=](auto temp_462) -> string { switch(temp_462) { case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto ts = (string) (([=](auto temp_463) -> string { switch(temp_463) { case 0x1: return string("H"); case 0x2: return string("S"); default: throw "Not implemented"; } })(size));
		auto index = (byte) (([=](auto temp_464) -> byte { switch(temp_464) { case 0x1: return (byte) ((byte) (((byte) (byte) (((byte) (((byte) (M)) << 0)) | ((byte) (((byte) (L)) << 1)))) | ((byte) (((byte) (H)) << 2)))); case 0x2: return (byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))); default: throw "Not implemented"; } })(size));
		auto v = ((RuntimeValue<Vector128<float>>) (([=](auto temp_465) -> RuntimeValue<Vector128<float>> { switch(temp_465) { case 0x1: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ushort>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<ushort>(index)))))); case 0x2: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<uint>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<uint>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])).Element<uint>(index)))))); default: throw "Not implemented"; } })(size))).Store();
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((Q) != 0 ? (v) : ((RuntimeValue<Vector128<float>>) (v)));
		return true;
	}
	/* MUL-vector */
	if((inst & 0xBF20FC00U) == 0x0E209C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_466) -> string { switch(temp_466) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto v = ((RuntimeValue<Vector128<float>>) (([=](auto temp_467) -> RuntimeValue<Vector128<float>> { switch(temp_467) { case 0x0: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<byte>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<byte>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); case 0x1: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ushort>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<ushort>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); case 0x2: return (RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<uint>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])) * ((RuntimeValue<Vector128<uint>>) ((RuntimeValue<Vector128<float>>) (VR[(int) (rm)])))))); default: throw "Not implemented"; } })(size))).Store();
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) ((Q) != 0 ? (v) : ((RuntimeValue<Vector128<float>>) (v)));
		return true;
	}
	/* ORN-shifted-register */
	if((inst & 0x7F200000U) == 0x2A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_468) -> string { switch(temp_468) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) (([=](auto temp_469) -> RuntimeValue<uint> { switch(temp_469) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) (([=](auto temp_470) -> RuntimeValue<ulong> { switch(temp_470) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))));
		}
		return true;
	}
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
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) | ((RuntimeValue<uint>) ((uint) ((uint) (imm)))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) | ((RuntimeValue<uint>) ((uint) ((uint) (imm)))))));
		} else {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) | ((RuntimeValue<ulong>) (imm))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) | ((RuntimeValue<ulong>) (imm))));
		}
		return true;
	}
	/* ORR-shifted-register */
	if((inst & 0x7F200000U) == 0x2A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_471) -> string { switch(temp_471) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_472) -> RuntimeValue<uint> { switch(temp_472) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_473) -> RuntimeValue<ulong> { switch(temp_473) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))));
		}
		return true;
	}
	/* ORR-simd-register */
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U) {
		auto q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((q) == (0x0)) ? 1U : 0U) != 0) ? (string("8B")) : (string("16B")));
		if(((bool) (((rm) == (rn)) ? 1U : 0U)) != 0) {
			VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]);
		} else {
			throw "Not implemented";
		}
		return true;
	}
	/* PRFM-immediate */
	if((inst & 0xFFC00000U) == 0xF9800000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto imm5 = (inst >> 0) & 0x1FU;
		auto pimm = (ulong) (((ulong) (ushort) (imm)) * ((ulong) (long) (0x8)));
		return true;
	}
	/* RBIT */
	if((inst & 0x7FFFFC00U) == 0x5AC00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Call<uint, uint>(ReverseBits, (RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (Call<ulong, ulong>(ReverseBits, (RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())));
		}
		return true;
	}
	/* RET */
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		BranchRegister(rn);
		return true;
	}
	/* REV */
	if((inst & 0x7FFFF800U) == 0x5AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto opc = (inst >> 10) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		switch((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))) {
			case 0x0: {
				auto x = ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Store();
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (x)) & ((RuntimeValue<ulong>) (0xFF))))) << (0x18)))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((x) >> (0x8)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x10))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((x) >> (0x10)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x8))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((x) >> (0x18)))) & ((RuntimeValue<ulong>) (0xFF)))))))));
				break;
			}
			case 0x3: {
				auto x = ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Store();
				XR[(int) rd] = (RuntimeValue<ulong>) ((((((((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (x)) & ((RuntimeValue<ulong>) (0xFF))))) << (0x38)))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x8)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x30))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x10)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x28))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x18)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x20))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x20)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x18))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x28)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x10))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x30)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x8))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x38)))) & ((RuntimeValue<ulong>) (0xFF))))))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* REV16 */
	if((inst & 0x7FFFFC00U) == 0x5AC00400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto x = ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (x)) & ((RuntimeValue<ulong>) (0xFF))))) << (0x8)))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((x) >> (0x8)))) & ((RuntimeValue<ulong>) (0xFF))))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((x) >> (0x10)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x18))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((x) >> (0x18)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x10)))))));
		} else {
			auto x = ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) ((((((((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (x)) & ((RuntimeValue<ulong>) (0xFF))))) << (0x8)))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x8)))) & ((RuntimeValue<ulong>) (0xFF))))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x10)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x18))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x18)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x10))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x20)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x28))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x28)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x20))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x30)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x38))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((x) >> (0x38)))) & ((RuntimeValue<ulong>) (0xFF))))) << (0x30))))));
		}
		return true;
	}
	/* RORV */
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))) << ((RuntimeValue<uint>) (32 - ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x20))))))) | (((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))) >> ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x20))))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())) << ((RuntimeValue<uint>) (64 - ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x40))))))) | (((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())) >> ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))) % ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x40)))))));
		}
		return true;
	}
	/* SBCS */
	if((inst & 0x7FE0FC00U) == 0x7A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<bool>) (NZCV_CR)))).Store();
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<bool>) (NZCV_CR)))).Store();
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		return true;
	}
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
			auto src = ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Store();
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) (((src) << ((RuntimeValue<uint>) (32 - (immr)))) | ((src) >> ((RuntimeValue<uint>) (immr)))))) & ((RuntimeValue<uint>) (wmask))))).Store();
			auto top = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((uint) ((uint) (0x0)))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((src) >> (imms)))) & ((RuntimeValue<ulong>) (0x1)))))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) (top)) & ((RuntimeValue<uint>) ((uint) (~(tmask)))))))) | ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) (bot)) & ((RuntimeValue<uint>) (tmask)))))))));
		} else {
			auto src = ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Store();
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((src) << ((RuntimeValue<uint>) (64 - (immr)))) | ((src) >> ((RuntimeValue<uint>) (immr)))))) & ((RuntimeValue<ulong>) (wmask))))).Store();
			auto top = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (0x0)))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((src) >> (imms)))) & ((RuntimeValue<ulong>) (0x1)))))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (top)) & ((RuntimeValue<ulong>) ((ulong) (~(tmask)))))))) | ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (bot)) & ((RuntimeValue<ulong>) (tmask))))))));
		}
		return true;
	}
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
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))));
				break;
			}
			case 0x4: {
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))));
				break;
			}
			case 0x5: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* SCVTF-vector-integer */
	if((inst & 0xFFBFFC00U) == 0x5E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<int>) (((RuntimeValue<float>) (VSR[(int) (rn)])).Bitcast<int>())));
		} else {
			VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<long>) (((RuntimeValue<double>) (VDR[(int) (rn)])).Bitcast<long>())));
		}
		return true;
	}
	/* SDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto operand2 = ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Ternary<bool, uint>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((operand2) == (0x0))), (uint) ((uint) (0x0)), (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<float>) (((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))))))) / ((RuntimeValue<float>) (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<int>) ((RuntimeValue<int>) (operand2))))))))))));
		} else {
			auto operand2 = ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (Ternary<bool, ulong>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((operand2) == (0x0))), (ulong) ((ulong) (0x0)), (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<double>) (((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))))))) / ((RuntimeValue<double>) (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<long>) ((RuntimeValue<long>) (operand2)))))))))));
		}
		return true;
	}
	/* SMADDL */
	if((inst & 0xFFE08000U) == 0x9B200000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((ra) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) ra]()))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())), 32)))) * ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))))))));
		return true;
	}
	/* SMULH */
	if((inst & 0xFFE0FC00U) == 0x9B407C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<Int128>) (((RuntimeValue<Int128>) (((RuntimeValue<Int128>) (RuntimeValue<Int128>) ((RuntimeValue<Int128>) ((RuntimeValue<Int128>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))))))) * ((RuntimeValue<Int128>) (RuntimeValue<Int128>) ((RuntimeValue<Int128>) ((RuntimeValue<Int128>) ((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))))))))) >> (0x40))))));
		return true;
	}
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
		auto iv = ((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Store();
		VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<byte>) ((byte) ((byte) (0x0)))).CreateVector());
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x8)))) : (0x0))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x8)))) : (0x1))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x2)) + ((long) (long) (0x8)))) : (0x2))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x3)) + ((long) (long) (0x8)))) : (0x3))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x4, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x4)) + ((long) (long) (0x8)))) : (0x4))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x5, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x5)) + ((long) (long) (0x8)))) : (0x5))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x6, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x6)) + ((long) (long) (0x8)))) : (0x6))))))))) << (shift)));
			VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x7, (RuntimeValue<short>) (((RuntimeValue<short>) ((RuntimeValue<short>) ((RuntimeValue<sbyte>) ((iv).Element<sbyte>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x7)) + ((long) (long) (0x8)))) : (0x7))))))))) << (shift)));
		} else {
			if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<short>) ((iv).Element<short>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x4)))) : (0x0))))))))) << (shift)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<short>) ((iv).Element<short>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x4)))) : (0x1))))))))) << (shift)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<short>) ((iv).Element<short>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x2)) + ((long) (long) (0x4)))) : (0x2))))))))) << (shift)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<short>) ((iv).Element<short>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x3)) + ((long) (long) (0x4)))) : (0x3))))))))) << (shift)));
			} else {
				if(((bool) ((((byte) ((((ulong) (immh)) & ((ulong) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<int>) ((iv).Element<int>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x0)) + ((long) (long) (0x2)))) : (0x0))))))))) << (shift)));
					VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<int>) ((iv).Element<int>((uint) ((uint) ((long) ((Q != 0) ? ((long) (((long) (long) (0x1)) + ((long) (long) (0x2)))) : (0x1))))))))) << (shift)));
				} else {
					throw "Not implemented";
				}
			}
		}
		return true;
	}
	/* STLR */
	if((inst & 0xBFFFFC00U) == 0x889FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value = (RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()));
		} else {
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))).value = (RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]());
		}
		return true;
	}
	/* STLRB */
	if((inst & 0xFFFFFC00U) == 0x089FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		((RuntimePointer<byte>) (address)).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()))));
		return true;
	}
	/* STLRH */
	if((inst & 0xFFFFFC00U) == 0x489FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()))));
		return true;
	}
	/* STLXR */
	if((inst & 0xBFE0FC00U) == 0x8800FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) (address)).value = (RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()));
		} else {
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]());
		}
		XR[(int) rs] = (RuntimeValue<ulong>) (RuntimeValue<uint>) (0x0);
		return true;
	}
	/* STLXRB */
	if((inst & 0xFFE0FC00U) == 0x0800FC00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		((RuntimePointer<byte>) (address)).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()))));
		XR[(int) rs] = (RuntimeValue<ulong>) (RuntimeValue<uint>) (0x0);
		return true;
	}
	/* STP-postindex */
	if((inst & 0x7FC00000U) == 0x28800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]())).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) (address)).value = (RuntimeValue<uint>) ((rt1) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt1]()));
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value = (RuntimeValue<uint>) ((rt2) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt2]()));
		} else {
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((rt1) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt1]());
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = (RuntimeValue<ulong>) ((rt2) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt2]());
		}
		if(rd == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* STP-preindex */
	if((inst & 0x7FC00000U) == 0x29800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) (address)).value = (RuntimeValue<uint>) ((rt1) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt1]()));
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value = (RuntimeValue<uint>) ((rt2) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt2]()));
		} else {
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((rt1) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt1]());
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = (RuntimeValue<ulong>) ((rt2) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt2]());
		}
		if(rd == 31)
			SPR = address;
		else
			XR[(int) rd] = address;
		return true;
	}
	/* STP-signed-offset */
	if((inst & 0x7FC00000U) == 0x29000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) (address)).value = (RuntimeValue<uint>) ((rt1) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt1]()));
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value = (RuntimeValue<uint>) ((rt2) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt2]()));
		} else {
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((rt1) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt1]());
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = (RuntimeValue<ulong>) ((rt2) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt2]());
		}
		return true;
	}
	/* STP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2C800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_474) -> string { switch(temp_474) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_475) -> long { switch(temp_475) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]())).Store();
		switch(opc) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt1)]);
				((RuntimePointer<float>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value = (RuntimeValue<float>) (VSR[(int) (rt2)]);
				break;
			}
			case 0x1: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt1)]);
				((RuntimePointer<double>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = (RuntimeValue<double>) (VDR[(int) (rt2)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt1)]);
				((RuntimePointer<Vector128<float>>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x10))))).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt2)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rd == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* STP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2D800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_476) -> string { switch(temp_476) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_477) -> long { switch(temp_477) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		switch(opc) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt1)]);
				((RuntimePointer<float>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value = (RuntimeValue<float>) (VSR[(int) (rt2)]);
				break;
			}
			case 0x1: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt1)]);
				((RuntimePointer<double>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = (RuntimeValue<double>) (VDR[(int) (rt2)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt1)]);
				((RuntimePointer<Vector128<float>>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x10))))).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt2)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rd == 31)
			SPR = address;
		else
			XR[(int) rd] = address;
		return true;
	}
	/* STP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D000000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_478) -> string { switch(temp_478) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_479) -> long { switch(temp_479) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		switch(opc) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt1)]);
				((RuntimePointer<float>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x4))))).value = (RuntimeValue<float>) (VSR[(int) (rt2)]);
				break;
			}
			case 0x1: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt1)]);
				((RuntimePointer<double>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x8))))).value = (RuntimeValue<double>) (VDR[(int) (rt2)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt1)]);
				((RuntimePointer<Vector128<float>>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (0x10))))).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt2)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8000400U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]())).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) (address)).value = (RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()));
		} else {
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((rs) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rs]());
		}
		if(rd == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* STR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8000C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) (address)).value = (RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()));
		} else {
			((RuntimePointer<ulong>) (address)).value = (RuntimeValue<ulong>) ((rs) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rs]());
		}
		if(rd == 31)
			SPR = address;
		else
			XR[(int) rd] = address;
		return true;
	}
	/* STR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto pimm = (ulong) (((ulong) ((ulong) (imm))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (pimm))))).value = (RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()));
		} else {
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (pimm))))).value = (RuntimeValue<ulong>) ((rs) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rs]());
		}
		return true;
	}
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
		auto extend = (string) (([=](auto temp_480) -> string { switch(temp_480) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value = (RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()));
		} else {
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value = (RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]());
		}
		return true;
	}
	/* STR-simd-postindex */
	if((inst & 0x3F600C00U) == 0x3C000400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_481) -> string { switch(temp_481) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())).Store();
		switch(rop) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VBR[(int) (rt)]);
				break;
			}
			case 0x4: {
				((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) (VHR[(int) (rt)]);
				break;
			}
			case 0x8: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt)]);
				break;
			}
			case 0xC: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rn] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* STR-simd-preindex */
	if((inst & 0x3F600C00U) == 0x3C000C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_482) -> string { switch(temp_482) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		switch(rop) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VBR[(int) (rt)]);
				break;
			}
			case 0x4: {
				((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) (VHR[(int) (rt)]);
				break;
			}
			case 0x8: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt)]);
				break;
			}
			case 0xC: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		if(rn == 31)
			SPR = address;
		else
			XR[(int) rn] = address;
		return true;
	}
	/* STR-simd-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_483) -> string { switch(temp_483) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) ((ushort) ((imm) << (uint) (scale)))))).Store();
		switch(rop) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VBR[(int) (rt)]);
				break;
			}
			case 0x4: {
				((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) (VHR[(int) (rt)]);
				break;
			}
			case 0x8: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt)]);
				break;
			}
			case 0xC: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
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
		auto r1 = (string) (([=](auto temp_484) -> string { switch(temp_484) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (([=](auto temp_485) -> long { switch(temp_485) { case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: return (long) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (0x4) : (0x0)); } })(size))));
		auto extend = (string) (([=](auto temp_486) -> string { switch(temp_486) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset)))).Store();
		switch(rop) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VBR[(int) (rt)]);
				break;
			}
			case 0x4: {
				((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) (VHR[(int) (rt)]);
				break;
			}
			case 0x8: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt)]);
				break;
			}
			case 0xC: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]())).Store();
		((RuntimePointer<byte>) (address)).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))));
		if(rd == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* STRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		((RuntimePointer<byte>) (address)).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))));
		if(rd == 31)
			SPR = address;
		else
			XR[(int) rd] = address;
		return true;
	}
	/* STRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39000000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())));
		return true;
	}
	/* STRB-register */
	if((inst & 0xFFE00C00U) == 0x38200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_487) -> string { switch(temp_487) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()))));
		return true;
	}
	/* STRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]())).Store();
		((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))));
		if(rd == 31)
			SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		else
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (address)) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)));
		return true;
	}
	/* STRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rd) == 31 ? SPR() : XR[(int) rd]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<uint>) ((rs) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rs]()))));
		if(rd == 31)
			SPR = address;
		else
			XR[(int) rd] = address;
		return true;
	}
	/* STRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79000000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ushort>) (imm))))).value = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())));
		return true;
	}
	/* STRH-register */
	if((inst & 0xFFE00C00U) == 0x78200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_488) -> string { switch(temp_488) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto offset = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((bool) (((option) == (0x6)) ? 1U : 0U)) != 0 ? ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]())), 32))))) : ((RuntimeValue<ulong>) (((byte) ((((ulong) (option)) & ((ulong) (0x1))))) != 0 ? ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) : ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))) << (amount))).Store();
		((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (offset))))).value = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()))));
		return true;
	}
	/* STUR */
	if((inst & 0xBFE00C00U) == 0xB8000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (long) (SignExt<long>(imm, 9));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			((RuntimePointer<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (offset))))).value = (RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]()));
		} else {
			((RuntimePointer<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (offset))))).value = (RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]());
		}
		return true;
	}
	/* STUR-simd */
	if((inst & 0x3F600C00U) == 0x3C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_489) -> string { switch(temp_489) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		auto address = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (simm)))).Store();
		switch(rop) {
			case 0x0: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VBR[(int) (rt)]);
				break;
			}
			case 0x4: {
				((RuntimePointer<ushort>) (address)).value = (RuntimeValue<ushort>) (VHR[(int) (rt)]);
				break;
			}
			case 0x8: {
				((RuntimePointer<float>) (address)).value = (RuntimeValue<float>) (VSR[(int) (rt)]);
				break;
			}
			case 0xC: {
				((RuntimePointer<double>) (address)).value = (RuntimeValue<double>) (VDR[(int) (rt)]);
				break;
			}
			case 0x2: {
				((RuntimePointer<Vector128<float>>) (address)).value = (RuntimeValue<Vector128<float>>) (VR[(int) (rt)]);
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* STURB */
	if((inst & 0xFFE00C00U) == 0x38000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		((RuntimePointer<byte>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (offset))))).value = (RuntimeValue<byte>) ((RuntimeValue<byte>) ((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())));
		return true;
	}
	/* STURH */
	if((inst & 0xFFE00C00U) == 0x78000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		((RuntimePointer<ushort>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) + ((RuntimeValue<ulong>) (RuntimeValue<long>) (offset))))).value = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())));
		return true;
	}
	/* STXR */
	if((inst & 0xBFE0FC00U) == 0x88007C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		XR[(int) rs] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<bool>) (((bool) (((size) == (0x0)) ? 1U : 0U)) != 0 ? ((RuntimeValue<bool>) (CompareAndSwap((RuntimePointer<uint>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())), (RuntimeValue<uint>) ((rt) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rt]())), Exclusive32R()))) : ((RuntimeValue<bool>) (CompareAndSwap((RuntimePointer<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())), (RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]()), Exclusive64R())))));
		return true;
	}
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
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((uint) (((uint) ((uint) (imm))) << (uint) (shift))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((uint) (((uint) ((uint) (imm))) << (uint) (shift))))));
		} else {
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift)))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) (((ulong) ((ulong) (imm))) << (uint) (shift)))));
		}
		return true;
	}
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
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_490) -> string { switch(temp_490) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_491) -> string { switch(temp_491) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))).Store();
			if(rd == 31)
				SPR = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (([=](auto temp_492) -> RuntimeValue<uint> { switch(temp_492) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x4: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); default: return m; } })(option))) << (imm))))));
			else
				XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (([=](auto temp_493) -> RuntimeValue<uint> { switch(temp_493) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x4: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); default: return m; } })(option))) << (imm))))));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				if(rd == 31)
					SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << (imm)))));
				else
					XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << (imm)))));
			} else {
				auto m = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))).Store();
				if(rd == 31)
					SPR = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (([=](auto temp_494) -> RuntimeValue<ulong> { switch(temp_494) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFFFFFF))))); case 0x4: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); case 0x6: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>(m, 64))))); default: return m; } })(option))) << (imm)))));
				else
					XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (([=](auto temp_495) -> RuntimeValue<ulong> { switch(temp_495) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFFFFFF))))); case 0x4: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); case 0x6: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>(m, 64))))); default: return m; } })(option))) << (imm)))));
			}
		}
		return true;
	}
	/* SUB-shifted-register */
	if((inst & 0x7F200000U) == 0x4B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_496) -> string { switch(temp_496) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) - ((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=](auto temp_497) -> RuntimeValue<uint> { switch(temp_497) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) - ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (([=](auto temp_498) -> RuntimeValue<ulong> { switch(temp_498) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift)))));
		}
		return true;
	}
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
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_499) -> string { switch(temp_499) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_500) -> string { switch(temp_500) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto m = ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? SPR() : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) (((RuntimeValue<uint>) (([=](auto temp_501) -> RuntimeValue<uint> { switch(temp_501) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x4: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (SignExtRuntime<int>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); default: return m; } })(option))) << (imm))))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			if(((bool) ((((byte) ((((ulong) (option)) & ((ulong) (0x3))))) == (0x3)) ? 1U : 0U)) != 0) {
				XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())))).Store();
						auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << (imm))))))).Store();
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
						auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
						NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
						NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
						NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
						NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
						return (usum).Store();
					})());
			} else {
				auto m = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))).Store();
				XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
						auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? SPR() : XR[(int) rn]())))).Store();
						auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (([=](auto temp_502) -> RuntimeValue<ulong> { switch(temp_502) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFF))))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFF))))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (m)) & ((RuntimeValue<ulong>) (0xFFFFFFFF))))); case 0x4: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<byte>) ((RuntimeValue<byte>) (m)), 8))))); case 0x5: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>((RuntimeValue<ushort>) ((RuntimeValue<ushort>) (m)), 16))))); case 0x6: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (SignExtRuntime<long>(m, 64))))); default: return m; } })(option))) << (imm))))))).Store();
						auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
						auto bits = (int) (64);
						auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
						auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
						auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
						NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
						NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
						NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
						NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
						return (usum).Store();
					})());
			}
		}
		return true;
	}
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
		auto shiftstr = (string) (([=](auto temp_503) -> string { switch(temp_503) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		if((mode32) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) (~((RuntimeValue<uint>) (([=](auto temp_504) -> RuntimeValue<uint> { switch(temp_504) { case 0x0: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) << (imm))); case 0x1: return (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> (imm))); case 0x2: return (RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<int>) (((RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))) >> (imm))))); default: return (RuntimeValue<uint>) ((((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) << ((RuntimeValue<uint>) (32 - (imm)))) | (((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (~((RuntimeValue<ulong>) (([=](auto temp_505) -> RuntimeValue<ulong> { switch(temp_505) { case 0x0: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) << (imm))); case 0x1: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> (imm))); case 0x2: return (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<long>) (((RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())))) >> (imm))))); default: return (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) << ((RuntimeValue<uint>) (64 - (imm)))) | (((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())) >> ((RuntimeValue<uint>) (imm)))); } })(shift))))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		return true;
	}
	/* SUBS-immediate */
	if((inst & 0x7F800000U) == 0x71000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_506) -> string { switch(temp_506) { case 0x0: return string("LSL #0"); case 0x1: return string("LSL #12"); default: throw "Not implemented"; } })(shift));
		auto rimm = (uint) ((shift != 0) ? ((uint) (((uint) ((uint) (imm))) << (uint) (0xC))) : (imm));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (([=]() -> RuntimeValue<uint> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (uint) ((uint) ((uint) (~((uint) ((uint) (rimm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (uint) ((uint) (0x1));
					auto bits = (int) (32);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<uint>) (RuntimeValue<uint>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) (((RuntimeValue<int>) (RuntimeValue<int>) ((RuntimeValue<int>) ((RuntimeValue<int>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<int>) (RuntimeValue<int>) ((int) ((int) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<uint>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((ulong) ((ulong) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((uint) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<uint>) ((usum) >> (bits1))) != ((RuntimeValue<uint>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})()));
		} else {
			XR[(int) rd] = (RuntimeValue<ulong>) (([=]() -> RuntimeValue<ulong> {
					auto __macro_add_with_carry_set_nzcv_common_operand1 = ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())))).Store();
					auto __macro_add_with_carry_set_nzcv_common_operand2 = (ulong) ((ulong) ((ulong) (~((ulong) ((ulong) (rimm))))));
					auto __macro_add_with_carry_set_nzcv_common_carryIn = (ulong) ((ulong) (0x1));
					auto bits = (int) (64);
					auto bits1 = (long) (((long) (int) (bits)) - ((long) (long) (0x1)));
					auto usum = ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand1)) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_operand2))))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (__macro_add_with_carry_set_nzcv_common_carryIn)))).Store();
					auto ssum = ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) (((RuntimeValue<long>) (RuntimeValue<long>) ((RuntimeValue<long>) ((RuntimeValue<long>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<long>) (RuntimeValue<long>) ((long) ((long) (__macro_add_with_carry_set_nzcv_common_carryIn)))))).Store();
					NZCV_NR = (RuntimeValue<ulong>) ((usum) >> (bits1));
					NZCV_ZR = (RuntimeValue<bool>) ((usum) == (0x0));
					NZCV_CR = (RuntimeValue<uint>) ((((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((RuntimeValue<uint>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) (__macro_add_with_carry_set_nzcv_common_operand1)))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_operand2))))))) + ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((UInt128) ((UInt128) (__macro_add_with_carry_set_nzcv_common_carryIn)))))) >> (bits)))))) & ((RuntimeValue<ulong>) (0x1))));
					NZCV_VR = (RuntimeValue<bool>) ((((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))) == ((ulong) ((__macro_add_with_carry_set_nzcv_common_operand2) >> (uint) (bits1)))))) & ((RuntimeValue<bool>) ((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((usum) >> (bits1))) != ((RuntimeValue<ulong>) ((__macro_add_with_carry_set_nzcv_common_operand1) >> (bits1))))))));
					return (usum).Store();
				})());
		}
		return true;
	}
	/* SVC */
	if((inst & 0xFFE0001FU) == 0xD4000001U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		Call<void, uint>(Svc, imm);
		return true;
	}
	/* SYS */
	if((inst & 0xFFF80000U) == 0xD5080000U) {
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return true;
	}
	/* TBZ */
	if((inst & 0x7F000000U) == 0x36000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (bool) ((((byte) ((bool) ((upper) << (uint) (0x5)))) | ((byte) (bottom))));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((ushort) (((ushort) ((ushort) (offset))) << (uint) (0x2)), 16)))));
		LabelTag temp_507 = DefineLabel(), temp_509 = DefineLabel(), temp_508 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())) >> (imm)))) & ((RuntimeValue<ulong>) (0x1))))) == (0x0)), temp_507, temp_509);
		Label(temp_507);
		Branch(addr);
		Branch(temp_508);
		Label(temp_509);
		Branch(pc + 4);
		Branch(temp_508);
		Label(temp_508);
		return true;
	}
	/* TBNZ */
	if((inst & 0x7F000000U) == 0x37000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (bool) ((((byte) ((bool) ((upper) << (uint) (0x5)))) | ((byte) (bottom))));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((ushort) (((ushort) ((ushort) (offset))) << (uint) (0x2)), 16)))));
		LabelTag temp_510 = DefineLabel(), temp_512 = DefineLabel(), temp_511 = DefineLabel();
		BranchIf((RuntimeValue<bool>) (((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) ((rt) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rt]())) >> (imm)))) & ((RuntimeValue<ulong>) (0x1))))) != (0x0)), temp_510, temp_512);
		Label(temp_510);
		Branch(addr);
		Branch(temp_511);
		Label(temp_512);
		Branch(pc + 4);
		Branch(temp_511);
		Label(temp_511);
		return true;
	}
	/* UADDLV */
	if((inst & 0xBF3FFC00U) == 0x2E303800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_513) -> string { switch(temp_513) { case 0x0: return string("H"); case 0x1: return string("S"); case 0x2: return string("D"); default: throw "Not implemented"; } })(size));
		auto t = (string) (([=](auto temp_514) -> string { switch(temp_514) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto esize = (long) ((0x8) << (uint) (size));
		auto count = (long) (((long) (long) ((long) ((Q != 0) ? (0x80) : (0x40)))) / ((long) (long) (esize)));
		switch(size) {
			case 0x0: {
				VHR[(int) (rd)] = (RuntimeValue<ushort>) ((RuntimeValue<ushort>) ((RuntimeValue<uint>) (Call<ulong, Vector128<float>, long, long>(VectorSumUnsigned, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), esize, count))));
				break;
			}
			case 0x1: {
				VSR[(int) (rd)] = (RuntimeValue<float>) (((RuntimeValue<uint>) (Call<ulong, Vector128<float>, long, long>(VectorSumUnsigned, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), esize, count))).Bitcast<float>());
				break;
			}
			case 0x2: {
				VDR[(int) (rd)] = (RuntimeValue<double>) (((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) (Call<ulong, Vector128<float>, long, long>(VectorSumUnsigned, (RuntimeValue<Vector128<float>>) (VR[(int) (rn)]), esize, count))))).Bitcast<double>());
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
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
			auto src = ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))).Store();
			auto wmask = (uint) ((uint) ((ulong) (MakeWMask(N, imms, immr, 0x20, 0x0))));
			auto tmask = (uint) ((uint) ((ulong) (MakeTMask(N, imms, immr, 0x20, 0x0))));
			auto bot = ((RuntimeValue<uint>) ((((RuntimeValue<uint>) ((RuntimeValue<uint>) (((src) << ((RuntimeValue<uint>) (32 - (immr)))) | ((src) >> ((RuntimeValue<uint>) (immr)))))) & ((RuntimeValue<uint>) (wmask))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((((RuntimeValue<uint>) (bot)) & ((RuntimeValue<uint>) (tmask)))));
		} else {
			auto src = ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())).Store();
			auto wmask = (ulong) (MakeWMask(N, imms, immr, 0x40, 0x0));
			auto tmask = (ulong) (MakeTMask(N, imms, immr, 0x40, 0x0));
			auto bot = ((RuntimeValue<ulong>) ((((RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((src) << ((RuntimeValue<uint>) (64 - (immr)))) | ((src) >> ((RuntimeValue<uint>) (immr)))))) & ((RuntimeValue<ulong>) (wmask))))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) ((((RuntimeValue<ulong>) (bot)) & ((RuntimeValue<ulong>) (tmask))));
		}
		return true;
	}
	/* UCVTF-scalar-integer */
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
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))));
				break;
			}
			case 0x1: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]()))));
				break;
			}
			case 0x4: {
				VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())));
				break;
			}
			case 0x5: {
				VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]())));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* UCVTF-vector-integer */
	if((inst & 0xFFBFFC00U) == 0x7E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			VSR[(int) (rd)] = (RuntimeValue<float>) ((RuntimeValue<float>) ((RuntimeValue<uint>) (((RuntimeValue<float>) (VSR[(int) (rn)])).Bitcast<uint>())));
		} else {
			VDR[(int) (rd)] = (RuntimeValue<double>) ((RuntimeValue<double>) ((RuntimeValue<ulong>) (((RuntimeValue<double>) (VDR[(int) (rn)])).Bitcast<ulong>())));
		}
		return true;
	}
	/* UDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		if(((bool) (((size) == (0x0)) ? 1U : 0U)) != 0) {
			auto operand2 = ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (RuntimeValue<uint>) ((RuntimeValue<uint>) (Ternary<bool, uint>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((operand2) == (0x0))), (uint) ((uint) (0x0)), (RuntimeValue<uint>) (((RuntimeValue<uint>) (RuntimeValue<uint>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))) / ((RuntimeValue<uint>) (RuntimeValue<uint>) (operand2))))));
		} else {
			auto operand2 = ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]())).Store();
			XR[(int) rd] = (RuntimeValue<ulong>) (Ternary<bool, ulong>((RuntimeValue<bool>) ((RuntimeValue<bool>) ((operand2) == (0x0))), (ulong) ((ulong) (0x0)), (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))) / ((RuntimeValue<ulong>) (RuntimeValue<ulong>) (operand2)))));
		}
		return true;
	}
	/* UMADDL */
	if((inst & 0xFFE08000U) == 0x9BA00000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		XR[(int) rd] = (RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((ra) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) ra]()))) + ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) (((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rn) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rn]())))))) * ((RuntimeValue<ulong>) (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<uint>) ((rm) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) rm]()))))))))));
		return true;
	}
	/* UMULH */
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		XR[(int) rd] = (RuntimeValue<ulong>) ((RuntimeValue<ulong>) ((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<ulong>) ((rn) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rn]()))))) * ((RuntimeValue<UInt128>) (RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<UInt128>) ((RuntimeValue<ulong>) ((rm) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) rm]()))))))) >> (0x40))));
		return true;
	}
	/* XTN */
	if((inst & 0xFF3FFC00U) == 0x0E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_515) -> string { switch(temp_515) { case 0x0: return string("8B"); case 0x1: return string("4H"); case 0x2: return string("2S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_516) -> string { switch(temp_516) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				auto a = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x0))).Store();
				auto b = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x1))).Store();
				auto c = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x2))).Store();
				auto d = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x3))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<ulong>) ((ulong) ((ulong) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<byte>) ((RuntimeValue<byte>) (a)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<byte>) ((RuntimeValue<byte>) (b)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<byte>) ((RuntimeValue<byte>) (c)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x3, (RuntimeValue<byte>) ((RuntimeValue<byte>) (d)));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<uint>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<uint>(0x0))).Store();
				auto b = ((RuntimeValue<uint>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<uint>(0x1))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<ulong>) ((ulong) ((ulong) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<ushort>) ((RuntimeValue<ushort>) (a)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x1, (RuntimeValue<ushort>) ((RuntimeValue<ushort>) (b)));
				break;
			}
			case 0x2: {
				auto a = ((RuntimeValue<ulong>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ulong>(0x0))).Store();
				VR[(int) (rd)] = (RuntimeValue<Vector128<float>>) (((RuntimeValue<ulong>) ((ulong) ((ulong) (0x0)))).CreateVector());
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x0, (RuntimeValue<uint>) ((RuntimeValue<uint>) (a)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}
	/* XTN2 */
	if((inst & 0xFF3FFC00U) == 0x4E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_517) -> string { switch(temp_517) { case 0x0: return string("16B"); case 0x1: return string("8H"); case 0x2: return string("4S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_518) -> string { switch(temp_518) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		switch(size) {
			case 0x0: {
				auto a = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x0))).Store();
				auto b = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x1))).Store();
				auto c = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x2))).Store();
				auto d = ((RuntimeValue<ushort>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ushort>(0x3))).Store();
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x8, (RuntimeValue<byte>) ((RuntimeValue<byte>) (a)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x9, (RuntimeValue<byte>) ((RuntimeValue<byte>) (b)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0xA, (RuntimeValue<byte>) ((RuntimeValue<byte>) (c)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0xB, (RuntimeValue<byte>) ((RuntimeValue<byte>) (d)));
				break;
			}
			case 0x1: {
				auto a = ((RuntimeValue<uint>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<uint>(0x0))).Store();
				auto b = ((RuntimeValue<uint>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<uint>(0x1))).Store();
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x4, (RuntimeValue<ushort>) ((RuntimeValue<ushort>) (a)));
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x5, (RuntimeValue<ushort>) ((RuntimeValue<ushort>) (b)));
				break;
			}
			case 0x2: {
				auto a = ((RuntimeValue<ulong>) (((RuntimeValue<Vector128<float>>) (VR[(int) (rn)])).Element<ulong>(0x0))).Store();
				VR[(int) (rd)] = VR[(int) (rd)]().Insert(0x2, (RuntimeValue<uint>) ((RuntimeValue<uint>) (a)));
				break;
			}
			default: {
				throw "Not implemented";
				break;
			}
		}
		return true;
	}

    return false;
}
