#include <string>
#include <cstdint>
#include <boost/format.hpp>
#include "common.h"
using std::string;
typedef uint64_t ulong;
typedef uint32_t uint;
typedef uint16_t ushort;
typedef uint8_t byte;

const int instructionClassCount = 327+0;

const char* getInstructionClass(uint inst) {
    ulong pc = 0;
	if((inst & 0x7FE0FC00U) == 0x3A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "ADCS";
	}
	insn_1:
	if((inst & 0x7FE00000U) == 0x0B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_2) -> string { switch(temp_2) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_3) -> string { switch(temp_3) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return "ADD-extended-register";
	}
	insn_2:
	if((inst & 0x7F800000U) == 0x11000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (int64_t) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (shift));
		return "ADD-immediate";
	}
	insn_3:
	if((inst & 0x7F200000U) == 0x0B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_5) -> string { switch(temp_5) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "ADD-shifted-register";
	}
	insn_4:
	if((inst & 0xBF20FC00U) == 0x0E208400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_7) -> string { switch(temp_7) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ADD-vector";
	}
	insn_5:
	if((inst & 0x7FE00000U) == 0x2B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_10) -> string { switch(temp_10) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_11) -> string { switch(temp_11) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return "ADDS-extended-register";
	}
	insn_6:
	if((inst & 0x7F800000U) == 0x31000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (int64_t) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (shift));
		return "ADDS-immediate";
	}
	insn_7:
	if((inst & 0x7F200000U) == 0x2B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_13) -> string { switch(temp_13) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "ADDS-shifted-register";
	}
	insn_8:
	if((inst & 0x9F000000U) == 0x10000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) (((uint32_t) (((uint32_t) (immlo)) << 0)) | ((uint32_t) (((uint32_t) (immhi)) << 2)))), 21));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) (imm)));
		return "ADR";
	}
	insn_9:
	if((inst & 0x9F000000U) == 0x90000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>((uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) ((uint16_t) ((uint16_t) (0x0)))) << 0)) | ((uint64_t) (((uint64_t) (immlo)) << 12)))) | ((uint64_t) (((uint64_t) (immhi)) << 14)))), 33));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) ((uint64_t) (((uint64_t) (((uint64_t) ((uint16_t) ((uint16_t) (0x0)))) << 0)) | ((uint64_t) (((uint64_t) ((uint64_t) ((uint64_t) ((uint64_t) (((uint64_t) (pc)) >> (uint) (0xC)))))) << 12)))))) + ((uint64_t) (int64_t) (imm)));
		return "ADRP";
	}
	insn_10:
	if((inst & 0x7F800000U) == 0x12000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return "AND-immediate";
	}
	insn_11:
	if((inst & 0x7F200000U) == 0x0A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_15) -> string { switch(temp_15) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "AND-shifted-register";
	}
	insn_12:
	if((inst & 0xBFE0FC00U) == 0x0E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return "AND-vector";
	}
	insn_13:
	if((inst & 0x7F200000U) == 0x6A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_17) -> string { switch(temp_17) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "ANDS-shifted-register";
	}
	insn_14:
	if((inst & 0x7F800000U) == 0x72000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return "ANDS-immediate";
	}
	insn_15:
	if((inst & 0x7FE0FC00U) == 0x1AC02800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "ASRV";
	}
	insn_16:
	if((inst & 0xFC000000U) == 0x14000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (0x2)), 28)))));
		return "B";
	}
	insn_17:
	if((inst & 0xFF000010U) == 0x54000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto cond = (inst >> 0) & 0xFU;
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (0x2)), 21)))));
		auto condstr = (string) (([=](auto temp_19) -> string { switch(temp_19) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "B.cond";
	}
	insn_18:
	if((inst & 0x7F800000U) == 0x33000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "BFM";
	}
	insn_19:
	if((inst & 0x7F200000U) == 0x0A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_21) -> string { switch(temp_21) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "BIC";
	}
	insn_20:
	if((inst & 0xBFE0FC00U) == 0x0E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		return "BIC-vector-register";
	}
	insn_21:
	if((inst & 0xBFF8DC00U) == 0x2F009400U) {
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
		auto T = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto amount = (int64_t) ((cmode != 0) ? (0x8) : (0x0));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "BIC-vector-immediate-16bit";
	}
	insn_22:
	if((inst & 0xBFF89C00U) == 0x2F001400U) {
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
		auto T = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto amount = (uint8_t) ((cmode) << (uint) (0x3));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "BIC-vector-immediate-32bit";
	}
	insn_23:
	if((inst & 0x7F200000U) == 0x6A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_23) -> string { switch(temp_23) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "BICS";
	}
	insn_24:
	if((inst & 0xFC000000U) == 0x94000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto offset = (int64_t) (SignExt<int64_t>((uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (0x2)), 28));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) (offset)));
		return "BL";
	}
	insn_25:
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return "BLR";
	}
	insn_26:
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return "BR";
	}
	insn_27:
	if((inst & 0xFFE0001FU) == 0xD4200000U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		return "BRK";
	}
	insn_28:
	if((inst & 0xBFE0FC00U) == 0x2E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return "BSL";
	}
	insn_29:
	if((inst & 0xBFE0FC00U) == 0x08207C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return "CASP";
	}
	insn_30:
	if((inst & 0xBFE0FC00U) == 0x08607C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return "CASPA";
	}
	insn_31:
	if((inst & 0xBFE0FC00U) == 0x0860FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return "CASPAL";
	}
	insn_32:
	if((inst & 0xBFE0FC00U) == 0x0820FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return "CASPL";
	}
	insn_33:
	if((inst & 0x7F000000U) == 0x35000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) ((uint32_t) ((imm) << (uint) (0x2)))), 21)))));
		return "CBNZ";
	}
	insn_34:
	if((inst & 0x7F000000U) == 0x34000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) ((uint32_t) ((imm) << (uint) (0x2)))), 21)))));
		return "CBZ";
	}
	insn_35:
	if((inst & 0x7FE00C10U) == 0x3A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_25) -> string { switch(temp_25) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CCMN-immediate";
	}
	insn_36:
	if((inst & 0x7FE00C10U) == 0x7A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_27) -> string { switch(temp_27) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CCMP-immediate";
	}
	insn_37:
	if((inst & 0x7FE00C10U) == 0x7A400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_29) -> string { switch(temp_29) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CCMP-register";
	}
	insn_38:
	if((inst & 0xFFFFF0FFU) == 0xD503305FU) {
		auto crm = (inst >> 8) & 0xFU;
		return "CLREX";
	}
	insn_39:
	if((inst & 0x7FFFFC00U) == 0x5AC01000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "CLZ";
	}
	insn_40:
	if((inst & 0xFF20FC00U) == 0x7E208C00U) {
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_31) -> string { switch(temp_31) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return "CMEQ-register-scalar";
	}
	insn_41:
	if((inst & 0xBF20FC00U) == 0x2E208C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_33) -> string { switch(temp_33) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "CMEQ-register-vector";
	}
	insn_42:
	if((inst & 0xFF3FFC00U) == 0x5E209800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_35) -> string { switch(temp_35) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return "CMEQ-zero-scalar";
	}
	insn_43:
	if((inst & 0xBF3FFC00U) == 0x0E209800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_37) -> string { switch(temp_37) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "CMEQ-zero-vector";
	}
	insn_44:
	if((inst & 0xFF20FC00U) == 0x5E203400U) {
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_39) -> string { switch(temp_39) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return "CMGT-register-scalar";
	}
	insn_45:
	if((inst & 0xBF20FC00U) == 0x0E203400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_41) -> string { switch(temp_41) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "CMGT-register-vector";
	}
	insn_46:
	if((inst & 0xFF3FFC00U) == 0x5E208800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_43) -> string { switch(temp_43) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return "CMGT-zero-scalar";
	}
	insn_47:
	if((inst & 0xBF3FFC00U) == 0x0E208800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_45) -> string { switch(temp_45) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "CMGT-zero-vector";
	}
	insn_48:
	if((inst & 0xBF3FFC00U) == 0x0E205800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_47) -> string { switch(temp_47) { case 0x0: return string("8B"); case 0x1: return string("16B"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "CNT";
	}
	insn_49:
	if((inst & 0x7FE00C00U) == 0x1A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_49) -> string { switch(temp_49) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CSEL";
	}
	insn_50:
	if((inst & 0x7FE00C00U) == 0x1A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_51) -> string { switch(temp_51) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CSINC";
	}
	insn_51:
	if((inst & 0x7FE00C00U) == 0x5A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_53) -> string { switch(temp_53) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CSINV";
	}
	insn_52:
	if((inst & 0x7FE00C00U) == 0x5A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_55) -> string { switch(temp_55) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "CSNEG";
	}
	insn_53:
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU) {
		auto m = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_57) -> string { switch(temp_57) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(m));
		return "DMB";
	}
	insn_54:
	if((inst & 0xFFFFF0FFU) == 0xD503309FU) {
		auto crm = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_59) -> string { switch(temp_59) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(crm));
		return "DSB";
	}
	insn_55:
	if((inst & 0xFFE0FC00U) == 0x5E000400U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = string("");
		auto index = 0x0;
		auto size = 0x0;
		if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				T = string("B");
				index = (uint8_t) ((imm) >> (uint) (0x1));
				size = 0x1;
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					T = string("H");
					index = (uint8_t) ((imm) >> (uint) (0x2));
					size = 0x2;
				} else {
					if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						T = string("S");
						index = (uint8_t) ((imm) >> (uint) (0x3));
						size = 0x4;
					} else {
						T = string("D");
						index = (uint8_t) ((imm) >> (uint) (0x4));
						size = 0x8;
					}
				}
			}
		}
		return "DUP-element-scalar";
	}
	insn_56:
	if((inst & 0xBFE0FC00U) == 0x0E000400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ts = string("");
		auto T = string("");
		auto index = 0x0;
		auto size = 0x0;
		if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				Ts = string("B");
				T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
				index = (uint8_t) ((imm) >> (uint) (0x1));
				size = 0x1;
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					Ts = string("H");
					T = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
					index = (uint8_t) ((imm) >> (uint) (0x2));
					size = 0x2;
				} else {
					if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						Ts = string("S");
						T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
						index = (uint8_t) ((imm) >> (uint) (0x3));
						size = 0x4;
					} else {
						Ts = string("D");
						T = (string) ((Q != 0) ? (string("2D")) : throw "Not implemented");
						index = (uint8_t) ((imm) >> (uint) (0x4));
						size = 0x8;
					}
				}
			}
		}
		return "DUP-element-vector";
	}
	insn_57:
	if((inst & 0xBFE0FC00U) == 0x0E000C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto size = ((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((int64_t) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x8)) ? 1U : 0U) != 0) ? (0x40) : (0x20)));
		auto r = (string) (((bool) (((size) == (0x40)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto T = ((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((string) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("16B")) : (string("8B")))) : ((string) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("8H")) : (string("4H")))) : ((string) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("4S")) : (string("2S")))) : ((string) ((Q != 0) ? (string("2D")) : throw "Not implemented"))))))));
		return "DUP-general";
	}
	insn_58:
	if((inst & 0x7F200000U) == 0x4A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_61) -> string { switch(temp_61) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "EON-shifted-register";
	}
	insn_59:
	if((inst & 0x7F800000U) == 0x52000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return "EOR-immediate";
	}
	insn_60:
	if((inst & 0x7F200000U) == 0x4A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_63) -> string { switch(temp_63) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "EOR-shifted-register";
	}
	insn_61:
	if((inst & 0xBFE0FC00U) == 0x2E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return "EOR-vector";
	}
	insn_62:
	if((inst & 0xBFE08400U) == 0x2E000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto index = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return "EXT";
	}
	insn_63:
	if((inst & 0x7FA00000U) == 0x13800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto o = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto lsb = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "EXTR";
	}
	insn_64:
	if((inst & 0xFFA0FC00U) == 0x7EA0D400U) {
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_65) -> string { switch(temp_65) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(size));
		return "FABD-scalar";
	}
	insn_65:
	if((inst & 0xFF3FFC00U) == 0x1E20C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_67) -> string { switch(temp_67) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FABS-scalar";
	}
	insn_66:
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_69) -> string { switch(temp_69) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FABS-vector";
	}
	insn_67:
	if((inst & 0xFF20FC00U) == 0x1E202800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_71) -> string { switch(temp_71) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FADD-scalar";
	}
	insn_68:
	if((inst & 0xBFA0FC00U) == 0x0E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_73) -> string { switch(temp_73) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FADD-vector";
	}
	insn_69:
	if((inst & 0xFFBFFC00U) == 0x7E30D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return "FADDP-scalar";
	}
	insn_70:
	if((inst & 0xBFA0FC00U) == 0x2E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_75) -> string { switch(temp_75) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FADDP-vector";
	}
	insn_71:
	if((inst & 0xFF200C10U) == 0x1E200400U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (([=](auto temp_78) -> string { switch(temp_78) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_79) -> string { switch(temp_79) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "FCCMP";
	}
	insn_72:
	if((inst & 0x9F20F400U) == 0x0E20E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto E = (inst >> 23) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ac = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_82) -> string { switch(temp_82) { case 0x0: return string("EQ"); case 0x2: return string("GE"); case 0x3: return string("GE"); case 0x6: return string("GT"); case 0x7: return string("GT"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (ac)) << 0)) | ((uint8_t) (((uint8_t) (U)) << 1)))) | ((uint8_t) (((uint8_t) (E)) << 2))))));
		auto t = (string) (([=](auto temp_83) -> string { switch(temp_83) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FCMxx-register-vector";
	}
	insn_73:
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto op = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_86) -> string { switch(temp_86) { case 0x0: return string("GT"); case 0x1: return string("GE"); case 0x2: return string("EQ"); default: return string("LE"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (U)) << 0)) | ((uint8_t) (((uint8_t) (op)) << 1))))));
		auto t = (string) (([=](auto temp_87) -> string { switch(temp_87) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FCMxx-zero-vector";
	}
	insn_74:
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_89) -> string { switch(temp_89) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FCMLT-zero-vector";
	}
	insn_75:
	if((inst & 0xFF20FC17U) == 0x1E202000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto opc = (inst >> 3) & 0x1U;
		auto r = (string) (([=](auto temp_91) -> string { switch(temp_91) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto zero = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("/0")) : (string("")));
		return "FCMP";
	}
	insn_76:
	if((inst & 0xFF200C00U) == 0x1E200C00U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_94) -> string { switch(temp_94) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_95) -> string { switch(temp_95) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return "FCSEL";
	}
	insn_77:
	if((inst & 0xFF3E7C00U) == 0x1E224000U) {
		auto type = (inst >> 22) & 0x3U;
		auto opc = (inst >> 15) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = string("");
		auto r2 = string("");
		auto tf = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (type)) << 2))));
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
		return "FCVT";
	}
	insn_78:
	if((inst & 0x7F3FFC00U) == 0x1E240000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTAS-scalar-integer";
	}
	insn_79:
	if((inst & 0x7F3FFC00U) == 0x1E250000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTAU-scalar-integer";
	}
	insn_80:
	if((inst & 0xBFBFFC00U) == 0x0E217800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto o2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = (string) ((size != 0) ? (string("2D")) : (string("4S")));
		auto tb = (string) (([=](auto temp_97) -> string { switch(temp_97) { case 0x0: return string("4H"); case 0x1: return string("8H"); case 0x2: return string("2S"); default: return string("4S"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FCVTL[2]";
	}
	insn_81:
	if((inst & 0x7F3FFC00U) == 0x1E300000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTMS-scalar-integer";
	}
	insn_82:
	if((inst & 0x7F3FFC00U) == 0x1E310000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTMU-scalar-integer";
	}
	insn_83:
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
		return "FCVTN";
	}
	insn_84:
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
		return "FCVTN2";
	}
	insn_85:
	if((inst & 0x7F3FFC00U) == 0x1E280000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTPS-scalar-integer";
	}
	insn_86:
	if((inst & 0x7F3FFC00U) == 0x1E290000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTPU-scalar-integer";
	}
	insn_87:
	if((inst & 0x7F3F0000U) == 0x1E180000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (uint64_t) (((uint64_t) (int64_t) (0x40)) - ((uint64_t) (uint8_t) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_99) -> string { switch(temp_99) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FCVTZS-scalar-fixedpoint";
	}
	insn_88:
	if((inst & 0x7F3FFC00U) == 0x1E380000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTZS-scalar-integer";
	}
	insn_89:
	if((inst & 0x7F3F0000U) == 0x1E190000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (uint64_t) (((uint64_t) (int64_t) (0x40)) - ((uint64_t) (uint8_t) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_101) -> string { switch(temp_101) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FCVTZU-scalar-fixedpoint";
	}
	insn_90:
	if((inst & 0x7F3FFC00U) == 0x1E390000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "FCVTZU-scalar-integer";
	}
	insn_91:
	if((inst & 0xFF20FC00U) == 0x1E201800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_103) -> string { switch(temp_103) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FDIV-scalar";
	}
	insn_92:
	if((inst & 0xBFA0FC00U) == 0x2E20FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_105) -> string { switch(temp_105) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FDIV-vector";
	}
	insn_93:
	if((inst & 0xFF208000U) == 0x1F000000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_107) -> string { switch(temp_107) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		return "FMADD";
	}
	insn_94:
	if((inst & 0xFF20FC00U) == 0x1E204800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_109) -> string { switch(temp_109) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FMAX-scalar";
	}
	insn_95:
	if((inst & 0xFF20FC00U) == 0x1E206800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_111) -> string { switch(temp_111) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FMAXNM-scalar";
	}
	insn_96:
	if((inst & 0xFF20FC00U) == 0x1E205800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_113) -> string { switch(temp_113) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FMIN-scalar";
	}
	insn_97:
	if((inst & 0xFF20FC00U) == 0x1E207800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_115) -> string { switch(temp_115) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FMINNM-scalar";
	}
	insn_98:
	if((inst & 0xBF80F400U) == 0x0F801000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_118) -> string { switch(temp_118) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (sz)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_119) -> uint32_t { switch(temp_119) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return "FMLA-by-element-vector-spdp";
	}
	insn_99:
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_121) -> string { switch(temp_121) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return "FMLA-vector";
	}
	insn_100:
	if((inst & 0xBF80F400U) == 0x0F805000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_124) -> string { switch(temp_124) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (sz)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_125) -> uint32_t { switch(temp_125) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return "FMLS-by-element-vector-spdp";
	}
	insn_101:
	if((inst & 0xBFA0FC00U) == 0x0EA0CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_127) -> string { switch(temp_127) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return "FMLS-vector";
	}
	insn_102:
	if((inst & 0x7F36FC00U) == 0x1E260000U) {
		auto sf = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto mode = (inst >> 19) & 0x1U;
		auto ropc = (inst >> 16) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto opc = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (ropc)) << 0)) | ((uint8_t) (((uint8_t) ((uint8_t) ((uint8_t) (0x3)))) << 1))));
		auto tf = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) ((uint8_t) ((uint8_t) (mode)))) << 3)))) | ((uint8_t) (((uint8_t) (type)) << 5)))) | ((uint8_t) (((uint8_t) (sf)) << 7))));
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
		return "FMOV-general";
	}
	insn_103:
	if((inst & 0xFF201FE0U) == 0x1E201000U) {
		auto type = (inst >> 22) & 0x3U;
		auto imm = (inst >> 13) & 0xFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_129) -> string { switch(temp_129) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto sv = (float) (Bitcast<uint32_t, float>((uint32_t) ((uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (((uint32_t) ((uint32_t) ((uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 1)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 2)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 3)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 4)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 5)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 6)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 7)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 8)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 9)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 10)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 11)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 12)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 13)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 14)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 15)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 16)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 17)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 18)))))) << 0)) | ((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) ((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF)))))))) << 19)))) | ((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x4)))) & ((uint64_t) (0x3)))))))) << 23)))) | ((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 0)) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 1)))) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 2)))) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 3)))) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 4)))))) << 25)))) | ((uint32_t) (((uint32_t) ((bool) (((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1))))) != 0 ? 0U : 1U))) << 30)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) ((uint8_t) ((imm) >> (uint) (0x7)))))) << 31))))));
		return "FMOV-scalar-immediate";
	}
	insn_104:
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
		auto sv = (float) (Bitcast<uint32_t, float>((uint32_t) ((((uint32_t) ((uint32_t) ((uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (((uint32_t) ((uint32_t) ((uint32_t) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) (h)) << 19)))) | ((uint32_t) (((uint32_t) (g)) << 20)))) | ((uint32_t) (((uint32_t) (f)) << 21)))) | ((uint32_t) (((uint32_t) (e)) << 22)))) | ((uint32_t) (((uint32_t) (d)) << 23)))) | ((uint32_t) (((uint32_t) (c)) << 24)))) | ((uint32_t) (((uint32_t) (b)) << 25)))) | ((uint32_t) (((uint32_t) (b)) << 26)))) | ((uint32_t) (((uint32_t) (b)) << 27)))) | ((uint32_t) (((uint32_t) (b)) << 28)))) | ((uint32_t) (((uint32_t) (b)) << 29)))) | ((uint32_t) (((uint32_t) (b)) << 30)))) | ((uint32_t) (((uint32_t) (a)) << 31)))))) ^ ((uint32_t) ((uint32_t) (((uint32_t) ((uint32_t) (0x1))) << (uint) (0x1E))))))));
		return "FMOV-vector-immediate-single";
	}
	insn_105:
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
		auto sv = (double) (Bitcast<uint64_t, double>((uint64_t) ((((uint64_t) ((uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) ((uint64_t) ((uint64_t) (0x0)))) << 0)) | ((uint64_t) (((uint64_t) (h)) << 48)))) | ((uint64_t) (((uint64_t) (g)) << 49)))) | ((uint64_t) (((uint64_t) (f)) << 50)))) | ((uint64_t) (((uint64_t) (e)) << 51)))) | ((uint64_t) (((uint64_t) (d)) << 52)))) | ((uint64_t) (((uint64_t) (c)) << 53)))) | ((uint64_t) (((uint64_t) (b)) << 54)))) | ((uint64_t) (((uint64_t) (b)) << 55)))) | ((uint64_t) (((uint64_t) (b)) << 56)))) | ((uint64_t) (((uint64_t) (b)) << 57)))) | ((uint64_t) (((uint64_t) (b)) << 58)))) | ((uint64_t) (((uint64_t) (b)) << 59)))) | ((uint64_t) (((uint64_t) (b)) << 60)))) | ((uint64_t) (((uint64_t) (b)) << 61)))) | ((uint64_t) (((uint64_t) (b)) << 62)))) | ((uint64_t) (((uint64_t) (a)) << 63)))))) ^ ((uint64_t) ((uint64_t) (((uint64_t) ((uint64_t) (0x1))) << (uint) (0x3E))))))));
		return "FMOV-vector-immediate-double";
	}
	insn_106:
	if((inst & 0xFF208000U) == 0x1F008000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_131) -> string { switch(temp_131) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		return "FMSUB";
	}
	insn_107:
	if((inst & 0xFF80F400U) == 0x5F809000U) {
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_133) -> uint32_t { switch(temp_133) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return "FMUL-by-element-scalar-spdp";
	}
	insn_108:
	if((inst & 0xBF80F400U) == 0x0F809000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_136) -> string { switch(temp_136) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (sz)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_137) -> uint32_t { switch(temp_137) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return "FMUL-by-element-vector-spdp";
	}
	insn_109:
	if((inst & 0xFF20FC00U) == 0x1E200800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_139) -> string { switch(temp_139) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FMUL-scalar";
	}
	insn_110:
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_141) -> string { switch(temp_141) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FMUL-vector";
	}
	insn_111:
	if((inst & 0xFF3FFC00U) == 0x1E214000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_143) -> string { switch(temp_143) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FNEG-scalar";
	}
	insn_112:
	if((inst & 0xBFBFFC00U) == 0x2EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_145) -> string { switch(temp_145) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FNEG-vector";
	}
	insn_113:
	if((inst & 0xFF208000U) == 0x1F200000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_147) -> string { switch(temp_147) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FNMADD";
	}
	insn_114:
	if((inst & 0xFF208000U) == 0x1F208000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_149) -> string { switch(temp_149) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FNMSUB";
	}
	insn_115:
	if((inst & 0xFF20FC00U) == 0x1E208800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_151) -> string { switch(temp_151) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FNMUL-scalar";
	}
	insn_116:
	if((inst & 0xFF3FFC00U) == 0x1E264000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_153) -> string { switch(temp_153) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FRINTA-scalar";
	}
	insn_117:
	if((inst & 0xFF3FFC00U) == 0x1E27C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_155) -> string { switch(temp_155) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FRINTI-scalar";
	}
	insn_118:
	if((inst & 0xFF3FFC00U) == 0x1E254000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_157) -> string { switch(temp_157) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FRINTM-scalar";
	}
	insn_119:
	if((inst & 0xFF3FFC00U) == 0x1E24C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_159) -> string { switch(temp_159) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FRINTP-scalar";
	}
	insn_120:
	if((inst & 0xFF3FFC00U) == 0x1E274000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_161) -> string { switch(temp_161) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FRINTX-scalar";
	}
	insn_121:
	if((inst & 0xFF3FFC00U) == 0x1E25C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_163) -> string { switch(temp_163) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FRINTZ-scalar";
	}
	insn_122:
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_165) -> string { switch(temp_165) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FRSQRTE-vector";
	}
	insn_123:
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_167) -> string { switch(temp_167) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FRSQRTS-vector";
	}
	insn_124:
	if((inst & 0xFF3FFC00U) == 0x1E21C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_169) -> string { switch(temp_169) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FSQRT-scalar";
	}
	insn_125:
	if((inst & 0xFF20FC00U) == 0x1E203800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_171) -> string { switch(temp_171) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return "FSUB-scalar";
	}
	insn_126:
	if((inst & 0xBFA0FC00U) == 0x0EA0D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_173) -> string { switch(temp_173) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "FSUB-vector";
	}
	insn_127:
	if((inst & 0xFFE0FC00U) == 0x4E001C00U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index = (uint32_t) ((uint32_t) (0x0));
		auto r = string("W");
		if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index = (uint8_t) ((imm) >> (uint) (0x1));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index = (uint8_t) ((imm) >> (uint) (0x2));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index = (uint8_t) ((imm) >> (uint) (0x3));
				} else {
					ts = string("D");
					index = (uint8_t) ((imm) >> (uint) (0x4));
					r = string("X");
				}
			}
		}
		return "INS-general";
	}
	insn_128:
	if((inst & 0xFFE08400U) == 0x6E000400U) {
		auto imm5 = (inst >> 16) & 0x1FU;
		auto imm4 = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index1 = (uint32_t) ((uint32_t) (0x0));
		auto index2 = (uint32_t) ((uint32_t) (0x0));
		if(((bool) ((((uint8_t) ((((uint64_t) (imm5)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index1 = (uint8_t) ((imm5) >> (uint) (0x1));
			index2 = imm4;
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm5)) & ((uint64_t) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index1 = (uint8_t) ((imm5) >> (uint) (0x2));
				index2 = (uint8_t) ((imm4) >> (uint) (0x1));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm5)) & ((uint64_t) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index1 = (uint8_t) ((imm5) >> (uint) (0x3));
					index2 = (uint8_t) ((imm4) >> (uint) (0x2));
				} else {
					ts = string("D");
					index1 = (uint8_t) ((imm5) >> (uint) (0x4));
					index2 = (uint8_t) ((imm4) >> (uint) (0x3));
				}
			}
		}
		return "INS-vector";
	}
	insn_129:
	if((inst & 0xBFFFF000U) == 0x0C407000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_175) -> string { switch(temp_175) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD1-multi-no-offset-one-register";
	}
	insn_130:
	if((inst & 0xBFFFF000U) == 0x0C40A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_177) -> string { switch(temp_177) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD1-multi-no-offset-two-registers";
	}
	insn_131:
	if((inst & 0xBFFFF000U) == 0x0C406000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_179) -> string { switch(temp_179) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD1-multi-no-offset-three-registers";
	}
	insn_132:
	if((inst & 0xBFFFF000U) == 0x0C402000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_181) -> string { switch(temp_181) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD1-multi-no-offset-four-registers";
	}
	insn_133:
	if((inst & 0xBFFF2000U) == 0x0D400000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto opc = (inst >> 14) & 0x3U;
		auto S = (inst >> 12) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((opc) != (0x3)) ? 1U : 0U)))
			goto insn_134;
		auto t = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("B")) : ((string) (((bool) ((((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U))))) != 0) ? (string("H")) : ((string) (((bool) (((opc) == (0x2)) ? 1U : 0U) != 0) ? ((string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : ((string) (((bool) ((((bool) ((bool) (((size) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) (((S) == (0x0)) ? 1U : 0U))))) != 0) ? (string("D")) : throw "Not implemented")))) : throw "Not implemented")))));
		auto index = (uint32_t) (([=](auto temp_183) -> uint32_t { switch(temp_183) { case 0x0: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3)))))); case 0x1: return (uint32_t) (((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3))))))) >> (uint) (0x1)); case 0x2: return (uint32_t) (((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U) != 0) ? ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (S)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))))) : (Q)); default: throw "Not implemented"; } })(opc));
		return "LD1-single-no-offset";
	}
	insn_134:
	if((inst & 0xBFFFF000U) == 0x0D40C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_185) -> string { switch(temp_185) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD1R-single-no-offset";
	}
	insn_135:
	if((inst & 0xBFE0F000U) == 0x0DC0C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_136;
		auto t = (string) (([=](auto temp_188) -> string { switch(temp_188) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto imm = (int64_t) (([=](auto temp_189) -> int64_t { switch(temp_189) { case 0x0: return 0x1; case 0x1: return 0x2; case 0x2: return 0x4; default: return 0x8; } })(size));
		return "LD1R-single-postindex-immediate";
	}
	insn_136:
	if((inst & 0xBFE0F000U) == 0x0DC0C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_137;
		auto t = (string) (([=](auto temp_191) -> string { switch(temp_191) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD1R-single-postindex-register";
	}
	insn_137:
	if((inst & 0xBFFFF000U) == 0x0C408000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_193) -> string { switch(temp_193) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD2-multi-no-offset";
	}
	insn_138:
	if((inst & 0xBFE0F000U) == 0x0CC08000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_139;
		auto T = (string) (([=](auto temp_195) -> string { switch(temp_195) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD2-multi-postindex-immediate";
	}
	insn_139:
	if((inst & 0xBFE0F000U) == 0x0CC08000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_140;
		auto T = (string) (([=](auto temp_197) -> string { switch(temp_197) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD2-multi-postindex-register";
	}
	insn_140:
	if((inst & 0xBFFFF000U) == 0x0C404000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_199) -> string { switch(temp_199) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD3-multi-no-offset";
	}
	insn_141:
	if((inst & 0xBFE0F000U) == 0x0CC04000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_142;
		auto T = (string) (([=](auto temp_201) -> string { switch(temp_201) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD3-multi-postindex-immediate";
	}
	insn_142:
	if((inst & 0xBFE0F000U) == 0x0CC04000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_143;
		auto T = (string) (([=](auto temp_203) -> string { switch(temp_203) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD3-multi-postindex-register";
	}
	insn_143:
	if((inst & 0xBFFFF000U) == 0x0C400000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_205) -> string { switch(temp_205) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD4-multi-no-offset";
	}
	insn_144:
	if((inst & 0xBFE0F000U) == 0x0CC00000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_145;
		auto T = (string) (([=](auto temp_207) -> string { switch(temp_207) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD4-multi-postindex-immediate";
	}
	insn_145:
	if((inst & 0xBFE0F000U) == 0x0CC00000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_146;
		auto T = (string) (([=](auto temp_209) -> string { switch(temp_209) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LD4-multi-postindex-register";
	}
	insn_146:
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDAR";
	}
	insn_147:
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDARB";
	}
	insn_148:
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDARH";
	}
	insn_149:
	if((inst & 0xBFFFFC00U) == 0x885FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDAXB";
	}
	insn_150:
	if((inst & 0xFFFFFC00U) == 0x085FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDAXRB";
	}
	insn_151:
	if((inst & 0xFFFFFC00U) == 0x485FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDAXRH";
	}
	insn_152:
	if((inst & 0x7FC00000U) == 0x28C00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "LDP-immediate-postindex";
	}
	insn_153:
	if((inst & 0x7FC00000U) == 0x29400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "LDP-immediate-signed-offset";
	}
	insn_154:
	if((inst & 0x3FC00000U) == 0x2CC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_212) -> string { switch(temp_212) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_213) -> int64_t { switch(temp_213) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return "LDP-simd-postindex";
	}
	insn_155:
	if((inst & 0x3FC00000U) == 0x2DC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_216) -> string { switch(temp_216) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_217) -> int64_t { switch(temp_217) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return "LDP-simd-preindex";
	}
	insn_156:
	if((inst & 0x3FC00000U) == 0x2D400000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_220) -> string { switch(temp_220) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_221) -> int64_t { switch(temp_221) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return "LDP-simd-signed-offset";
	}
	insn_157:
	if((inst & 0xFFC00000U) == 0x69400000U) {
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) (0x2));
		return "LDPSW-immediate-signed-offset";
	}
	insn_158:
	if((inst & 0xBFE00C00U) == 0xB8400C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDR-immediate-preindex";
	}
	insn_159:
	if((inst & 0xBFE00C00U) == 0xB8400400U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDR-immediate-postindex";
	}
	insn_160:
	if((inst & 0xBFC00000U) == 0xB9400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint16_t) ((rawimm) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "LDR-immediate-unsigned-offset";
	}
	insn_161:
	if((inst & 0xBF000000U) == 0x18000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) ((uint32_t) ((rawimm) << (uint) (0x2)))), 21));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) (offset)));
		return "LDR-literal";
	}
	insn_162:
	if((inst & 0x3F600C00U) == 0x3C400400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		auto r = (string) (([=](auto temp_223) -> string { switch(temp_223) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LDR-simd-immediate-postindex";
	}
	insn_163:
	if((inst & 0x3F600C00U) == 0x3C400C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		auto r = (string) (([=](auto temp_225) -> string { switch(temp_225) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "LDR-simd-immediate-preindex";
	}
	insn_164:
	if((inst & 0x3F400000U) == 0x3D400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto ropc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto opc = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x1)))) << 0)) | ((uint8_t) (((uint8_t) (ropc)) << 1))));
		auto m = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_228) -> string { switch(temp_228) { case 0x1: return string("B"); case 0x5: return string("H"); case 0x9: return string("S"); case 0xD: return string("D"); default: return string("Q"); } })(m));
		auto imm = (uint32_t) (((uint32_t) ((uint32_t) (rawimm))) << (uint) ((int64_t) (([=](auto temp_229) -> int64_t { switch(temp_229) { case 0x1: return 0x0; case 0x5: return 0x1; case 0x9: return 0x2; case 0xD: return 0x3; default: return 0x4; } })(m))));
		return "LDR-simd-immediate-unsigned-offset";
	}
	insn_165:
	if((inst & 0x3F000000U) == 0x1C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_231) -> string { switch(temp_231) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(size));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) (((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) (imm)) << 2)))), 21)))));
		return "LDR-simd-literal";
	}
	insn_166:
	if((inst & 0x3F600C00U) == 0x3C600800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (string("Q")) : ((string) (([=](auto temp_235) -> string { switch(temp_235) { case 0x0: return string("B"); case 0x1: return string("H"); case 0x2: return string("S"); case 0x3: return string("D"); default: throw "Not implemented"; } })(size))));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (([=](auto temp_236) -> string { switch(temp_236) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto amount = (uint64_t) (((uint64_t) (bool) (scale)) * ((uint64_t) (int64_t) ((int64_t) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (0x4) : ((int64_t) (([=](auto temp_237) -> int64_t { switch(temp_237) { case 0x0: return 0x1; case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: throw "Not implemented"; } })(size)))))));
		return "LDR-simd-register";
	}
	insn_167:
	if((inst & 0xBFE00C00U) == 0xB8600800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_239) -> string { switch(temp_239) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return "LDR-register";
	}
	insn_168:
	if((inst & 0xFFE00C00U) == 0x38400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDRB-immediate-postindex";
	}
	insn_169:
	if((inst & 0xFFE00C00U) == 0x38400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDRB-immediate-preindex";
	}
	insn_170:
	if((inst & 0xFFC00000U) == 0x39400000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDRB-immediate-unsigned-offset";
	}
	insn_171:
	if((inst & 0xFFE00C00U) == 0x38600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_241) -> string { switch(temp_241) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return "LDRB-register";
	}
	insn_172:
	if((inst & 0xFFE00C00U) == 0x78400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDRH-immediate-postindex";
	}
	insn_173:
	if((inst & 0xFFE00C00U) == 0x78400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDRH-immediate-preindex";
	}
	insn_174:
	if((inst & 0xFFC00000U) == 0x79400000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint16_t) ((rawimm) << (uint) (0x1));
		return "LDRH-immediate-unsigned-offset";
	}
	insn_175:
	if((inst & 0xFFE00C00U) == 0x78600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_243) -> string { switch(temp_243) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return "LDRH-register";
	}
	insn_176:
	if((inst & 0xFFA00C00U) == 0x38800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDRSB-immediate-postindex";
	}
	insn_177:
	if((inst & 0xFFA00C00U) == 0x38800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDRSB-immediate-preindex";
	}
	insn_178:
	if((inst & 0xFF800000U) == 0x39800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDRSB-immediate-unsigned-offset";
	}
	insn_179:
	if((inst & 0xFFA00C00U) == 0x38A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_245) -> string { switch(temp_245) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return "LDRSB-register";
	}
	insn_180:
	if((inst & 0xFFA00C00U) == 0x78800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDRSH-immediate-postindex";
	}
	insn_181:
	if((inst & 0xFFA00C00U) == 0x78800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDRSH-immediate-preindex";
	}
	insn_182:
	if((inst & 0xFF800000U) == 0x79800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint16_t) ((rawimm) << (uint) (0x1));
		return "LDRSH-immediate-unsigned-offset";
	}
	insn_183:
	if((inst & 0xFFA00C00U) == 0x78A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_247) -> string { switch(temp_247) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return "LDRSH-register";
	}
	insn_184:
	if((inst & 0xFFE00C00U) == 0xB8800400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDRSW-immediate-postindex";
	}
	insn_185:
	if((inst & 0xFFE00C00U) == 0xB8800C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDRSW-immediate-preindex";
	}
	insn_186:
	if((inst & 0xFFC00000U) == 0xB9800000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint16_t) ((rawimm) << (uint) (0x2));
		return "LDRSW-immediate-unsigned-offset";
	}
	insn_187:
	if((inst & 0xFF000000U) == 0x98000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) (((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) (imm)) << 2)))), 21)))));
		return "LDRSW-literal";
	}
	insn_188:
	if((inst & 0xFFE00C00U) == 0xB8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0x2));
		auto extend = (string) (([=](auto temp_249) -> string { switch(temp_249) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return "LDRSW-register";
	}
	insn_189:
	if((inst & 0xBFE00C00U) == 0xB8400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDUR";
	}
	insn_190:
	if((inst & 0xFFE00C00U) == 0x38400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDURB";
	}
	insn_191:
	if((inst & 0xFFE00C00U) == 0x78400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDURH";
	}
	insn_192:
	if((inst & 0xFFA00C00U) == 0x38800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDURSB";
	}
	insn_193:
	if((inst & 0xFFA00C00U) == 0x78800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDURSH";
	}
	insn_194:
	if((inst & 0xFFE00C00U) == 0xB8800000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDURSW";
	}
	insn_195:
	if((inst & 0x3F600C00U) == 0x3C400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_251) -> string { switch(temp_251) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return "LDUR-simd";
	}
	insn_196:
	if((inst & 0xBFFFFC00U) == 0x885F7C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDXR";
	}
	insn_197:
	if((inst & 0xFFFFFC00U) == 0x085F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDXRB";
	}
	insn_198:
	if((inst & 0xFFFFFC00U) == 0x485F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "LDXRH";
	}
	insn_199:
	if((inst & 0xBFFF8000U) == 0x887F0000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LDXP";
	}
	insn_200:
	if((inst & 0x7FE0FC00U) == 0x1AC02000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LSL-register";
	}
	insn_201:
	if((inst & 0x7FE0FC00U) == 0x1AC02400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "LSRV";
	}
	insn_202:
	if((inst & 0x7FE08000U) == 0x1B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "MADD";
	}
	insn_203:
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
		auto imm8a = (uint8_t) ((uint8_t) ((int64_t) ((a != 0) ? (0xFF) : (0x0))));
		auto imm8b = (uint8_t) ((uint8_t) ((int64_t) ((b != 0) ? (0xFF) : (0x0))));
		auto imm8c = (uint8_t) ((uint8_t) ((int64_t) ((c != 0) ? (0xFF) : (0x0))));
		auto imm8d = (uint8_t) ((uint8_t) ((int64_t) ((d != 0) ? (0xFF) : (0x0))));
		auto imm8e = (uint8_t) ((uint8_t) ((int64_t) ((e != 0) ? (0xFF) : (0x0))));
		auto imm8f = (uint8_t) ((uint8_t) ((int64_t) ((f != 0) ? (0xFF) : (0x0))));
		auto imm8g = (uint8_t) ((uint8_t) ((int64_t) ((g != 0) ? (0xFF) : (0x0))));
		auto imm8h = (uint8_t) ((uint8_t) ((int64_t) ((h != 0) ? (0xFF) : (0x0))));
		auto imm = (uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) (imm8h)) << 0)) | ((uint64_t) (((uint64_t) (imm8g)) << 8)))) | ((uint64_t) (((uint64_t) (imm8f)) << 16)))) | ((uint64_t) (((uint64_t) (imm8e)) << 24)))) | ((uint64_t) (((uint64_t) (imm8d)) << 32)))) | ((uint64_t) (((uint64_t) (imm8c)) << 40)))) | ((uint64_t) (((uint64_t) (imm8b)) << 48)))) | ((uint64_t) (((uint64_t) (imm8a)) << 56))));
		return "MOVI-scalar-64bit";
	}
	insn_204:
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
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "MOVI-vector-8bit";
	}
	insn_205:
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
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "MOVI-vector-16bit";
	}
	insn_206:
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
		auto amount = (int64_t) (([=](auto temp_253) -> int64_t { switch(temp_253) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "MOVI-vector-32bit";
	}
	insn_207:
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
		auto imm = (uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (h)) << 1)))) | ((uint8_t) (((uint8_t) (h)) << 2)))) | ((uint8_t) (((uint8_t) (h)) << 3)))) | ((uint8_t) (((uint8_t) (h)) << 4)))) | ((uint8_t) (((uint8_t) (h)) << 5)))) | ((uint8_t) (((uint8_t) (h)) << 6)))) | ((uint8_t) (((uint8_t) (h)) << 7)))))) << 0)) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (g)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (g)) << 2)))) | ((uint8_t) (((uint8_t) (g)) << 3)))) | ((uint8_t) (((uint8_t) (g)) << 4)))) | ((uint8_t) (((uint8_t) (g)) << 5)))) | ((uint8_t) (((uint8_t) (g)) << 6)))) | ((uint8_t) (((uint8_t) (g)) << 7)))))) << 8)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (f)) << 0)) | ((uint8_t) (((uint8_t) (f)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (f)) << 3)))) | ((uint8_t) (((uint8_t) (f)) << 4)))) | ((uint8_t) (((uint8_t) (f)) << 5)))) | ((uint8_t) (((uint8_t) (f)) << 6)))) | ((uint8_t) (((uint8_t) (f)) << 7)))))) << 16)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (e)) << 0)) | ((uint8_t) (((uint8_t) (e)) << 1)))) | ((uint8_t) (((uint8_t) (e)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (e)) << 4)))) | ((uint8_t) (((uint8_t) (e)) << 5)))) | ((uint8_t) (((uint8_t) (e)) << 6)))) | ((uint8_t) (((uint8_t) (e)) << 7)))))) << 24)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (d)) << 0)) | ((uint8_t) (((uint8_t) (d)) << 1)))) | ((uint8_t) (((uint8_t) (d)) << 2)))) | ((uint8_t) (((uint8_t) (d)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (d)) << 5)))) | ((uint8_t) (((uint8_t) (d)) << 6)))) | ((uint8_t) (((uint8_t) (d)) << 7)))))) << 32)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (c)) << 0)) | ((uint8_t) (((uint8_t) (c)) << 1)))) | ((uint8_t) (((uint8_t) (c)) << 2)))) | ((uint8_t) (((uint8_t) (c)) << 3)))) | ((uint8_t) (((uint8_t) (c)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (c)) << 6)))) | ((uint8_t) (((uint8_t) (c)) << 7)))))) << 40)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (b)) << 0)) | ((uint8_t) (((uint8_t) (b)) << 1)))) | ((uint8_t) (((uint8_t) (b)) << 2)))) | ((uint8_t) (((uint8_t) (b)) << 3)))) | ((uint8_t) (((uint8_t) (b)) << 4)))) | ((uint8_t) (((uint8_t) (b)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (b)) << 7)))))) << 48)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (a)) << 0)) | ((uint8_t) (((uint8_t) (a)) << 1)))) | ((uint8_t) (((uint8_t) (a)) << 2)))) | ((uint8_t) (((uint8_t) (a)) << 3)))) | ((uint8_t) (((uint8_t) (a)) << 4)))) | ((uint8_t) (((uint8_t) (a)) << 5)))) | ((uint8_t) (((uint8_t) (a)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7)))))) << 56))));
		return "MOVI-Vx.2D";
	}
	insn_208:
	if((inst & 0x7F800000U) == 0x72800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (uint8_t) ((hw) << (uint) (0x4));
		return "MOVK";
	}
	insn_209:
	if((inst & 0x7F800000U) == 0x12800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (uint8_t) ((hw) << (uint) (0x4));
		return "MOVN";
	}
	insn_210:
	if((inst & 0x7F800000U) == 0x52800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (uint8_t) ((hw) << (uint) (0x4));
		return "MOVZ";
	}
	insn_211:
	if((inst & 0xFFF00000U) == 0xD5300000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return "MRS";
	}
	insn_212:
	if((inst & 0xFFF00000U) == 0xD5100000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return "MSR-register";
	}
	insn_213:
	if((inst & 0x7FE08000U) == 0x1B008000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "MSUB";
	}
	insn_214:
	if((inst & 0xBF00F400U) == 0x0F008000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto L = (inst >> 21) & 0x1U;
		auto M = (inst >> 20) & 0x1U;
		auto rv = (inst >> 16) & 0xFU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto rm = (uint8_t) (((bool) (((size) == (0x2)) ? 1U : 0U) != 0) ? ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (rv)) << 0)) | ((uint8_t) (((uint8_t) (M)) << 4))))) : (rv));
		auto t = (string) (([=](auto temp_257) -> string { switch(temp_257) { case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto ts = (string) (([=](auto temp_258) -> string { switch(temp_258) { case 0x1: return string("H"); case 0x2: return string("S"); default: throw "Not implemented"; } })(size));
		auto index = (uint8_t) (([=](auto temp_259) -> uint8_t { switch(temp_259) { case 0x1: return (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (M)) << 0)) | ((uint8_t) (((uint8_t) (L)) << 1)))) | ((uint8_t) (((uint8_t) (H)) << 2)))); case 0x2: return (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))); default: throw "Not implemented"; } })(size));
		return "MUL-by-element";
	}
	insn_215:
	if((inst & 0xBF20FC00U) == 0x0E209C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_261) -> string { switch(temp_261) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "MUL-vector";
	}
	insn_216:
	if((inst & 0xBFF8DC00U) == 0x2F008400U) {
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
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		auto amount = (int64_t) ((cmode != 0) ? (0x8) : (0x0));
		return "MVNI-vector-16bit";
	}
	insn_217:
	if((inst & 0xBFF89C00U) == 0x2F000400U) {
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
		auto amount = (int64_t) (([=](auto temp_263) -> int64_t { switch(temp_263) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "MVNI-vector-32bit-LSL";
	}
	insn_218:
	if((inst & 0xBFF8EC00U) == 0x2F00E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto cmode = (inst >> 12) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
		auto amount = (int64_t) ((cmode != 0) ? (0x10) : (0x8));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return "MVNI-vector-32bit-MSL";
	}
	insn_219:
	if((inst & 0xBF3FFC00U) == 0x2E20B800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_265) -> string { switch(temp_265) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "NEG-vector";
	}
	insn_220:
	if((inst & 0xFFFFFFFFU) == 0xD503201FU) {
		return "NOP";
	}
	insn_221:
	if((inst & 0x7F200000U) == 0x2A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_267) -> string { switch(temp_267) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "ORN-shifted-register";
	}
	insn_222:
	if((inst & 0x7F800000U) == 0x32000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return "ORR-immediate";
	}
	insn_223:
	if((inst & 0x7F200000U) == 0x2A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_269) -> string { switch(temp_269) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "ORR-shifted-register";
	}
	insn_224:
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x0)) ? 1U : 0U) != 0) ? (string("8B")) : (string("16B")));
		return "ORR-simd-register";
	}
	insn_225:
	if((inst & 0xBF20FC00U) == 0x0E20E000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto h = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto Ta = (string) (([=](auto temp_272) -> string { switch(temp_272) { case 0x0: return string("8H"); case 0x3: return string("1Q"); default: throw "Not implemented"; } })(size));
		auto Tb = (string) (([=](auto temp_273) -> string { switch(temp_273) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x6: return string("1D"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "PMULL[2]";
	}
	insn_226:
	if((inst & 0xFFC00000U) == 0xF9800000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto imm5 = (inst >> 0) & 0x1FU;
		auto pimm = (uint64_t) (((uint64_t) (uint16_t) (imm)) * ((uint64_t) (int64_t) (0x8)));
		return "PRFM-immediate";
	}
	insn_227:
	if((inst & 0xFF000000U) == 0xD8000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		return "PRFM-literal";
	}
	insn_228:
	if((inst & 0xFFE00C00U) == 0xF8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto opt = (inst >> 13) & 0x7U;
		auto S = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "PRFM-register";
	}
	insn_229:
	if((inst & 0xFFE00C00U) == 0xF8800000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "PRFUM";
	}
	insn_230:
	if((inst & 0x7FFFFC00U) == 0x5AC00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "RBIT";
	}
	insn_231:
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return "RET";
	}
	insn_232:
	if((inst & 0x7FFFF800U) == 0x5AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto opc = (inst >> 10) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "REV";
	}
	insn_233:
	if((inst & 0x7FFFFC00U) == 0x5AC00400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "REV16";
	}
	insn_234:
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "RORV";
	}
	insn_235:
	if((inst & 0x7FE0FC00U) == 0x7A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "SBCS";
	}
	insn_236:
	if((inst & 0x7F800000U) == 0x13000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "SBFM";
	}
	insn_237:
	if((inst & 0x7F3FFC00U) == 0x1E220000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "SCVTF-scalar-integer";
	}
	insn_238:
	if((inst & 0xFFBFFC00U) == 0x5E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return "SCVTF-scalar";
	}
	insn_239:
	if((inst & 0xBFBFFC00U) == 0x0E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_275) -> string { switch(temp_275) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "SCVTF-vector";
	}
	insn_240:
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "SDIV";
	}
	insn_241:
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
			goto insn_242;
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			size = 0x1;
			shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x8)));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				T = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				size = 0x2;
				shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x10)));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					size = 0x4;
					shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x20)));
				} else {
					T = (string) ((Q != 0) ? (string("2D")) : throw "Not implemented");
					size = 0x8;
					shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x20)));
				}
			}
		}
		return "SHL-vector";
	}
	insn_242:
	if((inst & 0xFFE08000U) == 0x9B200000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return "SMADDL";
	}
	insn_243:
	if((inst & 0xFFE0FC00U) == 0x9B407C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return "SMULH";
	}
	insn_244:
	if((inst & 0xBF80FC00U) == 0x0F00A400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto immh = (inst >> 19) & 0xFU;
		auto immb = (inst >> 16) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto variant = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = string("");
		auto tb = string("");
		auto shift = (uint64_t) ((uint64_t) (0x0));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			ta = string("8H");
			tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			shift = (uint64_t) (((uint64_t) (uint8_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))) - ((uint64_t) (int64_t) (0x8)));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				ta = string("4S");
				tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				shift = (uint64_t) (((uint64_t) (uint8_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))) - ((uint64_t) (int64_t) (0x10)));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					ta = string("2D");
					tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					shift = (uint64_t) (((uint64_t) (uint8_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))) - ((uint64_t) (int64_t) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		return "SSHLL";
	}
	insn_245:
	if((inst & 0xBFFFF000U) == 0x0C007000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_277) -> string { switch(temp_277) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-no-offset-one-register";
	}
	insn_246:
	if((inst & 0xBFE0F000U) == 0x0C807000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_247;
		auto T = (string) (([=](auto temp_279) -> string { switch(temp_279) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-immediate-one-register";
	}
	insn_247:
	if((inst & 0xBFE0F000U) == 0x0C807000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_248;
		auto T = (string) (([=](auto temp_281) -> string { switch(temp_281) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-register-one-register";
	}
	insn_248:
	if((inst & 0xBFFFF000U) == 0x0C00A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_283) -> string { switch(temp_283) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-no-offset-two-registers";
	}
	insn_249:
	if((inst & 0xBFE0F000U) == 0x0C80A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_250;
		auto T = (string) (([=](auto temp_285) -> string { switch(temp_285) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-immediate-two-registers";
	}
	insn_250:
	if((inst & 0xBFE0F000U) == 0x0C80A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_251;
		auto T = (string) (([=](auto temp_287) -> string { switch(temp_287) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-register-two-registers";
	}
	insn_251:
	if((inst & 0xBFFFF000U) == 0x0C006000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_289) -> string { switch(temp_289) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-no-offset-three-registers";
	}
	insn_252:
	if((inst & 0xBFE0F000U) == 0x0C806000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_253;
		auto T = (string) (([=](auto temp_291) -> string { switch(temp_291) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-immediate-three-registers";
	}
	insn_253:
	if((inst & 0xBFE0F000U) == 0x0C806000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_254;
		auto T = (string) (([=](auto temp_293) -> string { switch(temp_293) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-register-three-registers";
	}
	insn_254:
	if((inst & 0xBFFFF000U) == 0x0C002000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_295) -> string { switch(temp_295) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-no-offset-four-registers";
	}
	insn_255:
	if((inst & 0xBFE0F000U) == 0x0C802000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x40) : (0x20))));
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_256;
		auto T = (string) (([=](auto temp_297) -> string { switch(temp_297) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-immediate-four-registers";
	}
	insn_256:
	if((inst & 0xBFE0F000U) == 0x0C802000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_257;
		auto T = (string) (([=](auto temp_299) -> string { switch(temp_299) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST1-multi-postindex-register-four-registers";
	}
	insn_257:
	if((inst & 0xBFFF2000U) == 0x0D000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto opc = (inst >> 14) & 0x3U;
		auto S = (inst >> 12) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((opc) != (0x3)) ? 1U : 0U)))
			goto insn_258;
		auto t = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("B")) : ((string) (((bool) ((((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U))))) != 0) ? (string("H")) : ((string) (((bool) (((opc) == (0x2)) ? 1U : 0U) != 0) ? ((string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : ((string) (((bool) ((((bool) ((bool) (((size) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) (((S) == (0x0)) ? 1U : 0U))))) != 0) ? (string("D")) : throw "Not implemented")))) : throw "Not implemented")))));
		auto index = (uint32_t) (([=](auto temp_301) -> uint32_t { switch(temp_301) { case 0x0: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3)))))); case 0x1: return (uint32_t) (((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3))))))) >> (uint) (0x1)); case 0x2: return (uint32_t) (((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U) != 0) ? ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (S)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))))) : (Q)); default: throw "Not implemented"; } })(opc));
		return "ST1-single-no-offset";
	}
	insn_258:
	if((inst & 0xBFFFF000U) == 0x0C008000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_303) -> string { switch(temp_303) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST2-multi-no-offset";
	}
	insn_259:
	if((inst & 0xBFE0F000U) == 0x0C808000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_260;
		auto T = (string) (([=](auto temp_305) -> string { switch(temp_305) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST2-multi-postindex-immediate";
	}
	insn_260:
	if((inst & 0xBFE0F000U) == 0x0C808000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_261;
		auto T = (string) (([=](auto temp_307) -> string { switch(temp_307) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST2-multi-postindex-register";
	}
	insn_261:
	if((inst & 0xBFFFF000U) == 0x0C004000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_309) -> string { switch(temp_309) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST3-multi-no-offset";
	}
	insn_262:
	if((inst & 0xBFE0F000U) == 0x0C804000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_263;
		auto T = (string) (([=](auto temp_311) -> string { switch(temp_311) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST3-multi-postindex-immediate";
	}
	insn_263:
	if((inst & 0xBFE0F000U) == 0x0C804000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_264;
		auto T = (string) (([=](auto temp_313) -> string { switch(temp_313) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST3-multi-postindex-register";
	}
	insn_264:
	if((inst & 0xBFFFF000U) == 0x0C000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_315) -> string { switch(temp_315) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST4-multi-no-offset";
	}
	insn_265:
	if((inst & 0xBFE0F000U) == 0x0C800000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x40) : (0x2B))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_266;
		auto T = (string) (([=](auto temp_317) -> string { switch(temp_317) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST4-multi-postindex-immediate";
	}
	insn_266:
	if((inst & 0xBFE0F000U) == 0x0C800000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_267;
		auto T = (string) (([=](auto temp_319) -> string { switch(temp_319) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ST4-multi-postindex-register";
	}
	insn_267:
	if((inst & 0xBFFFFC00U) == 0x889FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "STLR";
	}
	insn_268:
	if((inst & 0xFFFFFC00U) == 0x089FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "STLRB";
	}
	insn_269:
	if((inst & 0xFFFFFC00U) == 0x489FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "STLRH";
	}
	insn_270:
	if((inst & 0xBFE0FC00U) == 0x8800FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "STLXR";
	}
	insn_271:
	if((inst & 0xFFE0FC00U) == 0x0800FC00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "STLXRB";
	}
	insn_272:
	if((inst & 0x7FC00000U) == 0x28800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "STP-postindex";
	}
	insn_273:
	if((inst & 0x7FC00000U) == 0x29800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "STP-preindex";
	}
	insn_274:
	if((inst & 0x7FC00000U) == 0x29000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "STP-signed-offset";
	}
	insn_275:
	if((inst & 0x3FC00000U) == 0x2C800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_322) -> string { switch(temp_322) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_323) -> int64_t { switch(temp_323) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return "STP-simd-postindex";
	}
	insn_276:
	if((inst & 0x3FC00000U) == 0x2D800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_326) -> string { switch(temp_326) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_327) -> int64_t { switch(temp_327) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return "STP-simd-preindex";
	}
	insn_277:
	if((inst & 0x3FC00000U) == 0x2D000000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_330) -> string { switch(temp_330) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_331) -> int64_t { switch(temp_331) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return "STP-simd-signed-offset";
	}
	insn_278:
	if((inst & 0xBFE00C00U) == 0xB8000400U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STR-immediate-postindex";
	}
	insn_279:
	if((inst & 0xBFE00C00U) == 0xB8000C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STR-immediate-preindex";
	}
	insn_280:
	if((inst & 0xBFC00000U) == 0xB9000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto pimm = (uint64_t) (((uint64_t) ((uint64_t) (imm))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return "STR-immediate-unsigned-offset";
	}
	insn_281:
	if((inst & 0xBFE00C00U) == 0xB8200800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_333) -> string { switch(temp_333) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return "STR-register";
	}
	insn_282:
	if((inst & 0x3F600C00U) == 0x3C000400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_335) -> string { switch(temp_335) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STR-simd-postindex";
	}
	insn_283:
	if((inst & 0x3F600C00U) == 0x3C000C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_337) -> string { switch(temp_337) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 2))));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STR-simd-preindex";
	}
	insn_284:
	if((inst & 0x3F400000U) == 0x3D000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_339) -> string { switch(temp_339) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 2))));
		return "STR-simd-unsigned-offset";
	}
	insn_285:
	if((inst & 0x3F600C00U) == 0x3C200800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r1 = (string) (([=](auto temp_343) -> string { switch(temp_343) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((int64_t) (([=](auto temp_344) -> int64_t { switch(temp_344) { case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: return (int64_t) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (0x4) : (0x0)); } })(size))));
		auto extend = (string) (([=](auto temp_345) -> string { switch(temp_345) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return "STR-simd-register";
	}
	insn_286:
	if((inst & 0xFFE00C00U) == 0x38000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STRB-immediate-postindex";
	}
	insn_287:
	if((inst & 0xFFE00C00U) == 0x38000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STRB-immediate-preindex";
	}
	insn_288:
	if((inst & 0xFFC00000U) == 0x39000000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "STRB-immediate-unsigned-offset";
	}
	insn_289:
	if((inst & 0xFFE00C00U) == 0x38200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_347) -> string { switch(temp_347) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return "STRB-register";
	}
	insn_290:
	if((inst & 0xFFE00C00U) == 0x78000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STRH-immediate-postindex";
	}
	insn_291:
	if((inst & 0xFFE00C00U) == 0x78000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STRH-immediate-preindex";
	}
	insn_292:
	if((inst & 0xFFC00000U) == 0x79000000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint16_t) ((rawimm) << (uint) (0x1));
		return "STRH-immediate-unsigned-offset";
	}
	insn_293:
	if((inst & 0xFFE00C00U) == 0x78200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_349) -> string { switch(temp_349) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return "STRH-register";
	}
	insn_294:
	if((inst & 0xBFE00C00U) == 0xB8000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STUR";
	}
	insn_295:
	if((inst & 0x3F600C00U) == 0x3C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_351) -> string { switch(temp_351) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STUR-simd";
	}
	insn_296:
	if((inst & 0xFFE00C00U) == 0x38000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STURB";
	}
	insn_297:
	if((inst & 0xFFE00C00U) == 0x78000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (int64_t) (SignExt<int64_t>(imm, 9));
		return "STURH";
	}
	insn_298:
	if((inst & 0xFFE0FC00U) == 0x08007C00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return "STXRB";
	}
	insn_299:
	if((inst & 0xBFE0FC00U) == 0x88007C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "STXR";
	}
	insn_300:
	if((inst & 0xBFE08000U) == 0x88200000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "STXP";
	}
	insn_301:
	if((inst & 0x7F800000U) == 0x51000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (int64_t) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		return "SUB-immediate";
	}
	insn_302:
	if((inst & 0x7FE00000U) == 0x4B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_354) -> string { switch(temp_354) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_355) -> string { switch(temp_355) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return "SUB-extended-register";
	}
	insn_303:
	if((inst & 0x7F200000U) == 0x4B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_357) -> string { switch(temp_357) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "SUB-shifted-register";
	}
	insn_304:
	if((inst & 0x7FE00000U) == 0x6B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_360) -> string { switch(temp_360) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_361) -> string { switch(temp_361) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return "SUBS-extended-register";
	}
	insn_305:
	if((inst & 0x7F200000U) == 0x6B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto mode32 = (bool) (((size) == (0x0)) ? 1U : 0U);
		auto r = (string) ((mode32 != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_363) -> string { switch(temp_363) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return "SUBS-shifted-register";
	}
	insn_306:
	if((inst & 0x7F800000U) == 0x71000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_365) -> string { switch(temp_365) { case 0x0: return string("LSL #0"); case 0x1: return string("LSL #12"); default: throw "Not implemented"; } })(shift));
		return "SUBS-immediate";
	}
	insn_307:
	if((inst & 0xFFE0001FU) == 0xD4000001U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		return "SVC";
	}
	insn_308:
	if((inst & 0xFFF80000U) == 0xD5080000U) {
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return "SYS";
	}
	insn_309:
	if((inst & 0x7F000000U) == 0x36000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint32_t) ((((uint32_t) ((uint32_t) (((uint32_t) ((uint32_t) (upper))) << (uint) (0x5)))) | ((uint32_t) ((uint32_t) ((uint32_t) (bottom))))));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint16_t) (((uint16_t) ((uint16_t) (offset))) << (uint) (0x2)), 16)))));
		return "TBZ";
	}
	insn_310:
	if((inst & 0x7F000000U) == 0x37000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint32_t) ((((uint32_t) ((uint32_t) (((uint32_t) ((uint32_t) (upper))) << (uint) (0x5)))) | ((uint32_t) ((uint32_t) ((uint32_t) (bottom))))));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint16_t) (((uint16_t) ((uint16_t) (offset))) << (uint) (0x2)), 16)))));
		return "TBNZ";
	}
	insn_311:
	if((inst & 0xBF3FFC00U) == 0x2E303800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_368) -> string { switch(temp_368) { case 0x0: return string("H"); case 0x1: return string("S"); case 0x2: return string("D"); default: throw "Not implemented"; } })(size));
		auto t = (string) (([=](auto temp_369) -> string { switch(temp_369) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto esize = (int64_t) ((0x8) << (uint) (size));
		auto count = (int64_t) (((int64_t) (int64_t) ((int64_t) ((Q != 0) ? (0x80) : (0x40)))) / ((int64_t) (int64_t) (esize)));
		return "UADDLV";
	}
	insn_312:
	if((inst & 0xBF20FC00U) == 0x2E201000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto o2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto Ta = string("");
		auto Tb = string("");
		switch((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))) {
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
		return "UADDW[2]";
	}
	insn_313:
	if((inst & 0x7F800000U) == 0x53000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "UBFM";
	}
	insn_314:
	if((inst & 0x7F3FFC00U) == 0x1E230000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return "UCVTF-scalar-gpr-integer";
	}
	insn_315:
	if((inst & 0xFFBFFC00U) == 0x7E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return "UCVTF-scalar-integer";
	}
	insn_316:
	if((inst & 0xBFBFFC00U) == 0x2E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_371) -> string { switch(temp_371) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "UCVTF-vector";
	}
	insn_317:
	if((inst & 0x7FE0FC00U) == 0x1AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return "UDIV";
	}
	insn_318:
	if((inst & 0xFFE08000U) == 0x9BA00000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return "UMADDL";
	}
	insn_319:
	if((inst & 0xBFE0FC00U) == 0x0E003C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = string("");
		auto index = 0x0;
		auto r = (string) ((Q != 0) ? (string("X")) : (string("W")));
		auto size = (int64_t) ((Q != 0) ? (0x40) : ((int64_t) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? (0x8) : ((int64_t) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? (0x10) : (0x20))))));
		switch(size) {
			case 0x8: {
				T = string("B");
				index = (uint8_t) ((imm) >> (uint) (0x1));
				break;
			}
			case 0x10: {
				T = string("H");
				index = (uint8_t) ((imm) >> (uint) (0x2));
				break;
			}
			case 0x20: {
				T = string("S");
				index = (uint8_t) ((imm) >> (uint) (0x3));
				break;
			}
			default: {
				T = string("D");
				index = (uint8_t) ((imm) >> (uint) (0x4));
				break;
			}
		}
		return "UMOV";
	}
	insn_320:
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return "UMULH";
	}
	insn_321:
	if((inst & 0xBF20FC00U) == 0x2E204400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_373) -> string { switch(temp_373) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "USHL-vector";
	}
	insn_322:
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
			goto insn_323;
		auto i2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			Ta = string("8H");
			Tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			size = 0x0;
			shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x8)));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				Ta = string("4S");
				Tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				size = 0x1;
				shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x10)));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					Ta = string("2D");
					Tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					size = 0x2;
					shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		return "USHLL-vector";
	}
	insn_323:
	if((inst & 0xFF3FFC00U) == 0x0E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_376) -> string { switch(temp_376) { case 0x0: return string("8B"); case 0x1: return string("4H"); case 0x2: return string("2S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_377) -> string { switch(temp_377) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		return "XTN";
	}
	insn_324:
	if((inst & 0xFF3FFC00U) == 0x4E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_380) -> string { switch(temp_380) { case 0x0: return string("16B"); case 0x1: return string("8H"); case 0x2: return string("4S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_381) -> string { switch(temp_381) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		return "XTN2";
	}
	insn_325:
	if((inst & 0xFFFFFFFFU) == 0xD503203FU) {
		return "YIELD";
	}
	insn_326:
	if((inst & 0xBF20BC00U) == 0x0E003800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto op = (inst >> 14) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto i = (uint8_t) ((uint8_t) ((uint64_t) (((uint64_t) (bool) (op)) + ((uint64_t) (int64_t) (0x1)))));
		auto T = (string) (([=](auto temp_383) -> string { switch(temp_383) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return "ZIP";
	}
	insn_327:

    return nullptr;
}

string disassemble(uint inst, ulong pc) {
	/* ADCS */
	if((inst & 0x7FE0FC00U) == 0x3A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("adcs %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
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
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_0) -> string { switch(temp_0) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_1) -> string { switch(temp_1) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("add %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str();
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
		auto shift = (int64_t) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (shift));
		return (boost::format("add %1%%2%, %3%%4%, #0x%5$#x, LSL #%6%0x%7$#x") % r % rd % r % rn % imm % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str();
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
		auto shiftstr = (string) (([=](auto temp_4) -> string { switch(temp_4) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("add %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_4:
	/* ADD-vector */
	if((inst & 0xBF20FC00U) == 0x0E208400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_6) -> string { switch(temp_6) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("add V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str();
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
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_8) -> string { switch(temp_8) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_9) -> string { switch(temp_9) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("adds %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str();
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
		auto shift = (int64_t) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		auto simm = (uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (shift));
		return (boost::format("adds %1%%2%, %3%%4%, #0x%5$#x, LSL #%6%0x%7$#x") % r % rd % r % rn % imm % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str();
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
		auto shiftstr = (string) (([=](auto temp_12) -> string { switch(temp_12) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("adds %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_8:
	/* ADR */
	if((inst & 0x9F000000U) == 0x10000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) (((uint32_t) (((uint32_t) (immlo)) << 0)) | ((uint32_t) (((uint32_t) (immhi)) << 2)))), 21));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) (imm)));
		return (boost::format("adr X%1%, #0x%2$#x") % rd % addr).str();
	}
	insn_9:
	/* ADRP */
	if((inst & 0x9F000000U) == 0x90000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>((uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) ((uint16_t) ((uint16_t) (0x0)))) << 0)) | ((uint64_t) (((uint64_t) (immlo)) << 12)))) | ((uint64_t) (((uint64_t) (immhi)) << 14)))), 33));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) ((uint64_t) (((uint64_t) (((uint64_t) ((uint16_t) ((uint16_t) (0x0)))) << 0)) | ((uint64_t) (((uint64_t) ((uint64_t) ((uint64_t) ((uint64_t) (((uint64_t) (pc)) >> (uint) (0xC)))))) << 12)))))) + ((uint64_t) (int64_t) (imm)));
		return (boost::format("adrp X%1%, #0x%2$#x") % rd % addr).str();
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
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return (boost::format("and %1%%2%, %3%%4%, #0x%5$#x") % r % rd % r % rn % imm).str();
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
		auto shiftstr = (string) (([=](auto temp_14) -> string { switch(temp_14) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("and %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_12:
	/* AND-vector */
	if((inst & 0xBFE0FC00U) == 0x0E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("and V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str();
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
		auto shiftstr = (string) (([=](auto temp_16) -> string { switch(temp_16) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("ands %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
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
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return (boost::format("ands %1%%2%, %3%%4%, #0x%5$#x") % r % rd % r % rn % imm).str();
	}
	insn_15:
	/* ASRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("asrv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_16:
	/* B */
	if((inst & 0xFC000000U) == 0x14000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (0x2)), 28)))));
		return (boost::format("b #0x%1$#x") % addr).str();
	}
	insn_17:
	/* B.cond */
	if((inst & 0xFF000010U) == 0x54000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto cond = (inst >> 0) & 0xFU;
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (0x2)), 21)))));
		auto condstr = (string) (([=](auto temp_18) -> string { switch(temp_18) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("b.%1% #0x%2$#x") % condstr % addr).str();
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
		return (boost::format("bfm %1%%2%, %3%%4%, #%5%, #%6%") % r % rd % r % rn % immr % imms).str();
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
		auto shiftstr = (string) (([=](auto temp_20) -> string { switch(temp_20) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("bic %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_20:
	/* BIC-vector-register */
	if((inst & 0xBFE0FC00U) == 0x0E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("bic V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_21:
	/* BIC-vector-immediate-16bit */
	if((inst & 0xBFF8DC00U) == 0x2F009400U) {
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
		auto T = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto amount = (int64_t) ((cmode != 0) ? (0x8) : (0x0));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("bic V%1%.%2%, #%3%, LSL #%4%0x%5$#x") % rd % T % (uint16_t) imm % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_22:
	/* BIC-vector-immediate-32bit */
	if((inst & 0xBFF89C00U) == 0x2F001400U) {
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
		auto T = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		auto amount = (uint8_t) ((cmode) << (uint) (0x3));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("bic V%1%.%2%, #%3%, LSL #%4%") % rd % T % (uint16_t) imm % amount).str();
	}
	insn_23:
	/* BICS */
	if((inst & 0x7F200000U) == 0x6A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_22) -> string { switch(temp_22) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("bics %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_24:
	/* BL */
	if((inst & 0xFC000000U) == 0x94000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto offset = (int64_t) (SignExt<int64_t>((uint32_t) (((uint32_t) ((uint32_t) (imm))) << (uint) (0x2)), 28));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) (offset)));
		return (boost::format("bl #0x%1$#x") % addr).str();
	}
	insn_25:
	/* BLR */
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return (boost::format("blr X%1%") % rn).str();
	}
	insn_26:
	/* BR */
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return (boost::format("br X%1%") % rn).str();
	}
	insn_27:
	/* BRK */
	if((inst & 0xFFE0001FU) == 0xD4200000U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		return (boost::format("brk #0x%1$#x") % imm).str();
	}
	insn_28:
	/* BSL */
	if((inst & 0xBFE0FC00U) == 0x2E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("bsl V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_29:
	/* CASP */
	if((inst & 0xBFE0FC00U) == 0x08207C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return (boost::format("casp %1%%2%, %3%0x%4$#x, %5%%6%, %7%0x%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str();
	}
	insn_30:
	/* CASPA */
	if((inst & 0xBFE0FC00U) == 0x08607C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return (boost::format("caspa %1%%2%, %3%0x%4$#x, %5%%6%, %7%0x%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str();
	}
	insn_31:
	/* CASPAL */
	if((inst & 0xBFE0FC00U) == 0x0860FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return (boost::format("caspal %1%%2%, %3%0x%4$#x, %5%%6%, %7%0x%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str();
	}
	insn_32:
	/* CASPL */
	if((inst & 0xBFE0FC00U) == 0x0820FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto rs2 = (uint64_t) (((uint64_t) (uint8_t) (rs)) + ((uint64_t) (int64_t) (0x1)));
		auto rt2 = (uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1)));
		return (boost::format("caspl %1%%2%, %3%0x%4$#x, %5%%6%, %7%0x%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str();
	}
	insn_33:
	/* CBNZ */
	if((inst & 0x7F000000U) == 0x35000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) ((uint32_t) ((imm) << (uint) (0x2)))), 21)))));
		return (boost::format("cbnz %1%%2%, #0x%3$#x") % r % rs % addr).str();
	}
	insn_34:
	/* CBZ */
	if((inst & 0x7F000000U) == 0x34000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) ((uint32_t) ((imm) << (uint) (0x2)))), 21)))));
		return (boost::format("cbz %1%%2%, #0x%3$#x") % r % rs % addr).str();
	}
	insn_35:
	/* CCMN-immediate */
	if((inst & 0x7FE00C10U) == 0x3A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_24) -> string { switch(temp_24) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("ccmn %1%%2%, #%3%, #%4%, %5%") % r % rn % imm % nzcv % condstr).str();
	}
	insn_36:
	/* CCMP-immediate */
	if((inst & 0x7FE00C10U) == 0x7A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_26) -> string { switch(temp_26) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("ccmp %1%%2%, #%3%, #%4%, %5%") % r % rn % imm % nzcv % condstr).str();
	}
	insn_37:
	/* CCMP-register */
	if((inst & 0x7FE00C10U) == 0x7A400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_28) -> string { switch(temp_28) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("ccmp %1%%2%, %3%%4%, #%5%, %6%") % r % rn % r % rm % nzcv % condstr).str();
	}
	insn_38:
	/* CLREX */
	if((inst & 0xFFFFF0FFU) == 0xD503305FU) {
		auto crm = (inst >> 8) & 0xFU;
		return (boost::format("clrex")).str();
	}
	insn_39:
	/* CLZ */
	if((inst & 0x7FFFFC00U) == 0x5AC01000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("clz %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_40:
	/* CMEQ-register-scalar */
	if((inst & 0xFF20FC00U) == 0x7E208C00U) {
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_30) -> string { switch(temp_30) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return (boost::format("cmeq %1%%2%, %3%%4%, %5%%6%") % V % rd % V % rn % V % rm).str();
	}
	insn_41:
	/* CMEQ-register-vector */
	if((inst & 0xBF20FC00U) == 0x2E208C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_32) -> string { switch(temp_32) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("cmeq V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_42:
	/* CMEQ-zero-scalar */
	if((inst & 0xFF3FFC00U) == 0x5E209800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_34) -> string { switch(temp_34) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return (boost::format("cmeq %1%%2%, %3%%4%, #0") % V % rd % V % rn).str();
	}
	insn_43:
	/* CMEQ-zero-vector */
	if((inst & 0xBF3FFC00U) == 0x0E209800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_36) -> string { switch(temp_36) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("cmeq V%1%.%2%, V%3%.%4%, #0") % rd % T % rn % T).str();
	}
	insn_44:
	/* CMGT-register-scalar */
	if((inst & 0xFF20FC00U) == 0x5E203400U) {
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_38) -> string { switch(temp_38) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return (boost::format("cmgt %1%%2%, %3%%4%, %5%%6%") % V % rd % V % rn % V % rm).str();
	}
	insn_45:
	/* CMGT-register-vector */
	if((inst & 0xBF20FC00U) == 0x0E203400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_40) -> string { switch(temp_40) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("cmgt V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_46:
	/* CMGT-zero-scalar */
	if((inst & 0xFF3FFC00U) == 0x5E208800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto V = (string) (([=](auto temp_42) -> string { switch(temp_42) { case 0x3: return string("D"); default: throw "Not implemented"; } })(size));
		return (boost::format("cmgt %1%%2%, %3%%4%, #0") % V % rd % V % rn).str();
	}
	insn_47:
	/* CMGT-zero-vector */
	if((inst & 0xBF3FFC00U) == 0x0E208800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_44) -> string { switch(temp_44) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("cmeq V%1%.%2%, V%3%.%4%, #0") % rd % T % rn % T).str();
	}
	insn_48:
	/* CNT */
	if((inst & 0xBF3FFC00U) == 0x0E205800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_46) -> string { switch(temp_46) { case 0x0: return string("8B"); case 0x1: return string("16B"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("cnt V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str();
	}
	insn_49:
	/* CSEL */
	if((inst & 0x7FE00C00U) == 0x1A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_48) -> string { switch(temp_48) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csel %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str();
	}
	insn_50:
	/* CSINC */
	if((inst & 0x7FE00C00U) == 0x1A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_50) -> string { switch(temp_50) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csinc %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str();
	}
	insn_51:
	/* CSINV */
	if((inst & 0x7FE00C00U) == 0x5A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_52) -> string { switch(temp_52) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csinv %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str();
	}
	insn_52:
	/* CSNEG */
	if((inst & 0x7FE00C00U) == 0x5A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_54) -> string { switch(temp_54) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csneg %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str();
	}
	insn_53:
	/* DMB */
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU) {
		auto m = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_56) -> string { switch(temp_56) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(m));
		return (boost::format("DMB %1%") % option).str();
	}
	insn_54:
	/* DSB */
	if((inst & 0xFFFFF0FFU) == 0xD503309FU) {
		auto crm = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_58) -> string { switch(temp_58) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(crm));
		return (boost::format("DSB %1%") % option).str();
	}
	insn_55:
	/* DUP-element-scalar */
	if((inst & 0xFFE0FC00U) == 0x5E000400U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = string("");
		auto index = 0x0;
		auto size = 0x0;
		if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				T = string("B");
				index = (uint8_t) ((imm) >> (uint) (0x1));
				size = 0x1;
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					T = string("H");
					index = (uint8_t) ((imm) >> (uint) (0x2));
					size = 0x2;
				} else {
					if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						T = string("S");
						index = (uint8_t) ((imm) >> (uint) (0x3));
						size = 0x4;
					} else {
						T = string("D");
						index = (uint8_t) ((imm) >> (uint) (0x4));
						size = 0x8;
					}
				}
			}
		}
		return (boost::format("dup %1%%2%, V%3%.%4%[%5%0x%6$#x]") % T % rd % rn % T % ((index) < 0 ? "-" : "") % ((index) < 0 ? -(index) : (index))).str();
	}
	insn_56:
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
		if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U)) != 0) {
			throw "Not implemented";
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
				Ts = string("B");
				T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
				index = (uint8_t) ((imm) >> (uint) (0x1));
				size = 0x1;
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U)) != 0) {
					Ts = string("H");
					T = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
					index = (uint8_t) ((imm) >> (uint) (0x2));
					size = 0x2;
				} else {
					if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x7))))) == (0x4)) ? 1U : 0U)) != 0) {
						Ts = string("S");
						T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
						index = (uint8_t) ((imm) >> (uint) (0x3));
						size = 0x4;
					} else {
						Ts = string("D");
						T = (string) ((Q != 0) ? (string("2D")) : throw "Not implemented");
						index = (uint8_t) ((imm) >> (uint) (0x4));
						size = 0x8;
					}
				}
			}
		}
		return (boost::format("dup V%1%.%2%, V%3%.%4%[%5%0x%6$#x]") % rd % T % rn % Ts % ((index) < 0 ? "-" : "") % ((index) < 0 ? -(index) : (index))).str();
	}
	insn_57:
	/* DUP-general */
	if((inst & 0xBFE0FC00U) == 0x0E000C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto size = ((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((int64_t) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x8)) ? 1U : 0U) != 0) ? (0x40) : (0x20)));
		auto r = (string) (((bool) (((size) == (0x40)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto T = ((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF))))) == (0x0)) ? 1U : 0U) != 0) ? throw "Not implemented" : ((string) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("16B")) : (string("8B")))) : ((string) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("8H")) : (string("4H")))) : ((string) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x7))))) == (0x4)) ? 1U : 0U) != 0) ? ((string) ((Q != 0) ? (string("4S")) : (string("2S")))) : ((string) ((Q != 0) ? (string("2D")) : throw "Not implemented"))))))));
		return (boost::format("dup V%1%.%2%, %3%%4%") % rd % T % r % rn).str();
	}
	insn_58:
	/* EON-shifted-register */
	if((inst & 0x7F200000U) == 0x4A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_60) -> string { switch(temp_60) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("eon %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_59:
	/* EOR-immediate */
	if((inst & 0x7F800000U) == 0x52000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return (boost::format("and %1%%2%, %3%%4%, #0x%5$#x") % r % rd % r % rn % imm).str();
	}
	insn_60:
	/* EOR-shifted-register */
	if((inst & 0x7F200000U) == 0x4A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_62) -> string { switch(temp_62) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("eor %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_61:
	/* EOR-vector */
	if((inst & 0xBFE0FC00U) == 0x2E201C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("eor V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_62:
	/* EXT */
	if((inst & 0xBFE08400U) == 0x2E000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto index = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("ext V%1%.%2%, V%3%.%4%, V%5%.%6%, #%7%") % rd % ts % rn % ts % rm % ts % index).str();
	}
	insn_63:
	/* EXTR */
	if((inst & 0x7FA00000U) == 0x13800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto o = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto lsb = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("extr %1%%2%, %3%%4%, %5%%6%, #%7%") % r % rd % r % rn % r % rm % lsb).str();
	}
	insn_64:
	/* FABD-scalar */
	if((inst & 0xFFA0FC00U) == 0x7EA0D400U) {
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_64) -> string { switch(temp_64) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(size));
		return (boost::format("fabd %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_65:
	/* FABS-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E20C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_66) -> string { switch(temp_66) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fabs %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_66:
	/* FABS-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_68) -> string { switch(temp_68) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fabs V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str();
	}
	insn_67:
	/* FADD-scalar */
	if((inst & 0xFF20FC00U) == 0x1E202800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_70) -> string { switch(temp_70) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fadd %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_68:
	/* FADD-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_72) -> string { switch(temp_72) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fadd V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str();
	}
	insn_69:
	/* FADDP-scalar */
	if((inst & 0xFFBFFC00U) == 0x7E30D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return (boost::format("faddp %1%%2%, V%3%.2%4%") % r % rd % rn % r).str();
	}
	insn_70:
	/* FADDP-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_74) -> string { switch(temp_74) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("faddp V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str();
	}
	insn_71:
	/* FCCMP */
	if((inst & 0xFF200C10U) == 0x1E200400U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (([=](auto temp_76) -> string { switch(temp_76) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_77) -> string { switch(temp_77) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("fccmp %1%%2%, %3%%4%, #%5%, %6%") % r % rn % r % rm % nzcv % condstr).str();
	}
	insn_72:
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
		auto top = (string) (([=](auto temp_80) -> string { switch(temp_80) { case 0x0: return string("EQ"); case 0x2: return string("GE"); case 0x3: return string("GE"); case 0x6: return string("GT"); case 0x7: return string("GT"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (ac)) << 0)) | ((uint8_t) (((uint8_t) (U)) << 1)))) | ((uint8_t) (((uint8_t) (E)) << 2))))));
		auto t = (string) (([=](auto temp_81) -> string { switch(temp_81) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("FCM%1% V%2%.%3%, V%4%.%5%, V%6%.%7%") % top % rd % t % rn % t % rm % t).str();
	}
	insn_73:
	/* FCMxx-zero-vector */
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto op = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_84) -> string { switch(temp_84) { case 0x0: return string("GT"); case 0x1: return string("GE"); case 0x2: return string("EQ"); default: return string("LE"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (U)) << 0)) | ((uint8_t) (((uint8_t) (op)) << 1))))));
		auto t = (string) (([=](auto temp_85) -> string { switch(temp_85) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("FCM%1% V%2%.%3%, V%4%.%5%, #0.0") % top % rd % t % rn % t).str();
	}
	insn_74:
	/* FCMLT-zero-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_88) -> string { switch(temp_88) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("FCMLT V%1%.%2%, V%3%.%4%, #0.0") % rd % t % rn % t).str();
	}
	insn_75:
	/* FCMP */
	if((inst & 0xFF20FC17U) == 0x1E202000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto opc = (inst >> 3) & 0x1U;
		auto r = (string) (([=](auto temp_90) -> string { switch(temp_90) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto zero = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("/0")) : (string("")));
		return (boost::format("fcmp %1%%2%, %3%%4% %5%") % r % rn % r % rm % zero).str();
	}
	insn_76:
	/* FCSEL */
	if((inst & 0xFF200C00U) == 0x1E200C00U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_92) -> string { switch(temp_92) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_93) -> string { switch(temp_93) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("fcsel %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str();
	}
	insn_77:
	/* FCVT */
	if((inst & 0xFF3E7C00U) == 0x1E224000U) {
		auto type = (inst >> 22) & 0x3U;
		auto opc = (inst >> 15) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = string("");
		auto r2 = string("");
		auto tf = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (type)) << 2))));
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
		return (boost::format("fcvt %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_78:
	/* FCVTAS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E240000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtas %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_79:
	/* FCVTAU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E250000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtau %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_80:
	/* FCVTL[2] */
	if((inst & 0xBFBFFC00U) == 0x0E217800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto o2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto ta = (string) ((size != 0) ? (string("2D")) : (string("4S")));
		auto tb = (string) (([=](auto temp_96) -> string { switch(temp_96) { case 0x0: return string("4H"); case 0x1: return string("8H"); case 0x2: return string("2S"); default: return string("4S"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fcvtl%1% V%2%.%3%, V%4%.%5%") % o2 % rd % ta % rn % tb).str();
	}
	insn_81:
	/* FCVTMS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E300000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtms %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_82:
	/* FCVTMU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E310000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtmu %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_83:
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
		return (boost::format("fcvtn V%1%.%2%, V%3%.%4%") % rd % Tb % rn % Ta).str();
	}
	insn_84:
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
		return (boost::format("fcvtn2 V%1%.%2%, V%3%.%4%") % rd % Tb % rn % Ta).str();
	}
	insn_85:
	/* FCVTPS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E280000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtps %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_86:
	/* FCVTPU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E290000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtpu %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_87:
	/* FCVTZS-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E180000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (uint64_t) (((uint64_t) (int64_t) (0x40)) - ((uint64_t) (uint8_t) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_98) -> string { switch(temp_98) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fcvtzs %1%%2%, %3%%4%, #0x%5$#x") % r1 % rd % r2 % rn % fbits).str();
	}
	insn_88:
	/* FCVTZS-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E380000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtzs %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_89:
	/* FCVTZU-scalar-fixedpoint */
	if((inst & 0x7F3F0000U) == 0x1E190000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto scale = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto fbits = (uint64_t) (((uint64_t) (int64_t) (0x40)) - ((uint64_t) (uint8_t) (scale)));
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (([=](auto temp_100) -> string { switch(temp_100) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fcvtzu %1%%2%, %3%%4%, #0x%5$#x") % r1 % rd % r2 % rn % fbits).str();
	}
	insn_90:
	/* FCVTZU-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E390000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("fcvtzu %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_91:
	/* FDIV-scalar */
	if((inst & 0xFF20FC00U) == 0x1E201800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_102) -> string { switch(temp_102) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fdiv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_92:
	/* FDIV-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_104) -> string { switch(temp_104) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fdiv V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str();
	}
	insn_93:
	/* FMADD */
	if((inst & 0xFF208000U) == 0x1F000000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_106) -> string { switch(temp_106) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmadd %1%%2%, %3%%4%, %5%%6%, %7%%8%") % t % rd % t % rn % t % rm % t % ra).str();
	}
	insn_94:
	/* FMAX-scalar */
	if((inst & 0xFF20FC00U) == 0x1E204800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_108) -> string { switch(temp_108) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmax %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_95:
	/* FMAXNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E206800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_110) -> string { switch(temp_110) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmaxnm %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_96:
	/* FMIN-scalar */
	if((inst & 0xFF20FC00U) == 0x1E205800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_112) -> string { switch(temp_112) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmin %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_97:
	/* FMINNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E207800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_114) -> string { switch(temp_114) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fminnm %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_98:
	/* FMLA-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F801000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_116) -> string { switch(temp_116) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (sz)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_117) -> uint32_t { switch(temp_117) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return (boost::format("fmla V%1%.%2%, V%3%.%4%, V%5%.%6%[0x%7$#x]") % rd % T % rn % T % rm % Ts % index).str();
	}
	insn_99:
	/* FMLA-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_120) -> string { switch(temp_120) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return (boost::format("fmla V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_100:
	/* FMLS-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F805000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_122) -> string { switch(temp_122) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (sz)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_123) -> uint32_t { switch(temp_123) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return (boost::format("fmls V%1%.%2%, V%3%.%4%, V%5%.%6%[0x%7$#x]") % rd % T % rn % T % rm % Ts % index).str();
	}
	insn_101:
	/* FMLS-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_126) -> string { switch(temp_126) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return (boost::format("fmls V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str();
	}
	insn_102:
	/* FMOV-general */
	if((inst & 0x7F36FC00U) == 0x1E260000U) {
		auto sf = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto mode = (inst >> 19) & 0x1U;
		auto ropc = (inst >> 16) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto opc = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (ropc)) << 0)) | ((uint8_t) (((uint8_t) ((uint8_t) ((uint8_t) (0x3)))) << 1))));
		auto tf = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) ((uint8_t) ((uint8_t) (mode)))) << 3)))) | ((uint8_t) (((uint8_t) (type)) << 5)))) | ((uint8_t) (((uint8_t) (sf)) << 7))));
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
		return (boost::format("fmov %1%%2%%3%, %4%%5%%6%") % r1 % rd % index1 % r2 % rn % index2).str();
	}
	insn_103:
	/* FMOV-scalar-immediate */
	if((inst & 0xFF201FE0U) == 0x1E201000U) {
		auto type = (inst >> 22) & 0x3U;
		auto imm = (inst >> 13) & 0xFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_128) -> string { switch(temp_128) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto sv = (float) (Bitcast<uint32_t, float>((uint32_t) ((uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (((uint32_t) ((uint32_t) ((uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 1)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 2)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 3)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 4)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 5)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 6)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 7)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 8)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 9)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 10)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 11)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 12)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 13)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 14)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 15)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 16)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 17)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) (0x0)))) << 18)))))) << 0)) | ((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) ((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0xF)))))))) << 19)))) | ((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x4)))) & ((uint64_t) (0x3)))))))) << 23)))) | ((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 0)) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 1)))) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 2)))) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 3)))) | ((uint8_t) (((uint8_t) ((bool) ((bool) ((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1)))))))) << 4)))))) << 25)))) | ((uint32_t) (((uint32_t) ((bool) (((uint8_t) ((((uint64_t) ((uint8_t) ((imm) >> (uint) (0x6)))) & ((uint64_t) (0x1))))) != 0 ? 0U : 1U))) << 30)))) | ((uint32_t) (((uint32_t) ((bool) ((bool) ((uint8_t) ((imm) >> (uint) (0x7)))))) << 31))))));
		return (boost::format("fmov %1%%2%, #%3%") % r % rd % sv).str();
	}
	insn_104:
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
		auto sv = (float) (Bitcast<uint32_t, float>((uint32_t) ((((uint32_t) ((uint32_t) ((uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (uint32_t) (((uint32_t) (((uint32_t) ((uint32_t) ((uint32_t) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) (h)) << 19)))) | ((uint32_t) (((uint32_t) (g)) << 20)))) | ((uint32_t) (((uint32_t) (f)) << 21)))) | ((uint32_t) (((uint32_t) (e)) << 22)))) | ((uint32_t) (((uint32_t) (d)) << 23)))) | ((uint32_t) (((uint32_t) (c)) << 24)))) | ((uint32_t) (((uint32_t) (b)) << 25)))) | ((uint32_t) (((uint32_t) (b)) << 26)))) | ((uint32_t) (((uint32_t) (b)) << 27)))) | ((uint32_t) (((uint32_t) (b)) << 28)))) | ((uint32_t) (((uint32_t) (b)) << 29)))) | ((uint32_t) (((uint32_t) (b)) << 30)))) | ((uint32_t) (((uint32_t) (a)) << 31)))))) ^ ((uint32_t) ((uint32_t) (((uint32_t) ((uint32_t) (0x1))) << (uint) (0x1E))))))));
		return (boost::format("fmov V%1%.%2%, #%3%") % rd % T % sv).str();
	}
	insn_105:
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
		auto sv = (double) (Bitcast<uint64_t, double>((uint64_t) ((((uint64_t) ((uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) ((uint64_t) ((uint64_t) (0x0)))) << 0)) | ((uint64_t) (((uint64_t) (h)) << 48)))) | ((uint64_t) (((uint64_t) (g)) << 49)))) | ((uint64_t) (((uint64_t) (f)) << 50)))) | ((uint64_t) (((uint64_t) (e)) << 51)))) | ((uint64_t) (((uint64_t) (d)) << 52)))) | ((uint64_t) (((uint64_t) (c)) << 53)))) | ((uint64_t) (((uint64_t) (b)) << 54)))) | ((uint64_t) (((uint64_t) (b)) << 55)))) | ((uint64_t) (((uint64_t) (b)) << 56)))) | ((uint64_t) (((uint64_t) (b)) << 57)))) | ((uint64_t) (((uint64_t) (b)) << 58)))) | ((uint64_t) (((uint64_t) (b)) << 59)))) | ((uint64_t) (((uint64_t) (b)) << 60)))) | ((uint64_t) (((uint64_t) (b)) << 61)))) | ((uint64_t) (((uint64_t) (b)) << 62)))) | ((uint64_t) (((uint64_t) (a)) << 63)))))) ^ ((uint64_t) ((uint64_t) (((uint64_t) ((uint64_t) (0x1))) << (uint) (0x3E))))))));
		return (boost::format("fmov V%1%.2D, #%2%") % rd % sv).str();
	}
	insn_106:
	/* FMSUB */
	if((inst & 0xFF208000U) == 0x1F008000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_130) -> string { switch(temp_130) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x3: return string("H"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmsub %1%%2%, %3%%4%, %5%%6%, %7%%8%") % t % rd % t % rn % t % rm % t % ra).str();
	}
	insn_107:
	/* FMUL-by-element-scalar-spdp */
	if((inst & 0xFF80F400U) == 0x5F809000U) {
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_132) -> uint32_t { switch(temp_132) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return (boost::format("fmul %1%%2%, %3%%4%, V%5%.%6%[0x%7$#x]") % Ts % rd % Ts % rn % rm % Ts % index).str();
	}
	insn_108:
	/* FMUL-by-element-vector-spdp */
	if((inst & 0xBF80F400U) == 0x0F809000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto L = (inst >> 21) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto H = (inst >> 11) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_134) -> string { switch(temp_134) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (sz)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint32_t) (([=](auto temp_135) -> uint32_t { switch(temp_135) { case 0x2: return (uint32_t) ((uint32_t) (H)); case 0x3: throw "Not implemented"; default: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))))); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (sz)) << 1))))));
		return (boost::format("fmul V%1%.%2%, V%3%.%4%, V%5%.%6%[0x%7$#x]") % rd % T % rn % T % rm % Ts % index).str();
	}
	insn_109:
	/* FMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E200800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_138) -> string { switch(temp_138) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmul %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_110:
	/* FMUL-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_140) -> string { switch(temp_140) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fmul V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str();
	}
	insn_111:
	/* FNEG-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E214000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_142) -> string { switch(temp_142) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fneg %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_112:
	/* FNEG-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_144) -> string { switch(temp_144) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fneg V%1%.%2%, V%3%.%4%") % rd % T % rn % T).str();
	}
	insn_113:
	/* FNMADD */
	if((inst & 0xFF208000U) == 0x1F200000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_146) -> string { switch(temp_146) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fnmadd %1%%2%, %3%%4%, %5%%6%, %7%%8%") % r % rd % r % rn % r % rm % r % ra).str();
	}
	insn_114:
	/* FNMSUB */
	if((inst & 0xFF208000U) == 0x1F208000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_148) -> string { switch(temp_148) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fnmsub %1%%2%, %3%%4%, %5%%6%, %7%%8%") % r % rd % r % rn % r % rm % r % ra).str();
	}
	insn_115:
	/* FNMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E208800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_150) -> string { switch(temp_150) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fnmul %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_116:
	/* FRINTA-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E264000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_152) -> string { switch(temp_152) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("frinta %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_117:
	/* FRINTI-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E27C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_154) -> string { switch(temp_154) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("frinti %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_118:
	/* FRINTM-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E254000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_156) -> string { switch(temp_156) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("frintm %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_119:
	/* FRINTP-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E24C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_158) -> string { switch(temp_158) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("frintp %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_120:
	/* FRINTX-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E274000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_160) -> string { switch(temp_160) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("frintx %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_121:
	/* FRINTZ-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E25C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_162) -> string { switch(temp_162) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("frintz %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_122:
	/* FRSQRTE-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_164) -> string { switch(temp_164) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("frsqrte V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str();
	}
	insn_123:
	/* FRSQRTS-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_166) -> string { switch(temp_166) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("frsqrts V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str();
	}
	insn_124:
	/* FSQRT-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E21C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_168) -> string { switch(temp_168) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fsqrt %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_125:
	/* FSUB-scalar */
	if((inst & 0xFF20FC00U) == 0x1E203800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_170) -> string { switch(temp_170) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fsub %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_126:
	/* FSUB-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_172) -> string { switch(temp_172) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("fsub V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str();
	}
	insn_127:
	/* INS-general */
	if((inst & 0xFFE0FC00U) == 0x4E001C00U) {
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index = (uint32_t) ((uint32_t) (0x0));
		auto r = string("W");
		if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index = (uint8_t) ((imm) >> (uint) (0x1));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index = (uint8_t) ((imm) >> (uint) (0x2));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index = (uint8_t) ((imm) >> (uint) (0x3));
				} else {
					ts = string("D");
					index = (uint8_t) ((imm) >> (uint) (0x4));
					r = string("X");
				}
			}
		}
		return (boost::format("ins V%1%.%2%[0x%3$#x], %4%%5%") % rd % ts % index % r % rn).str();
	}
	insn_128:
	/* INS-vector */
	if((inst & 0xFFE08400U) == 0x6E000400U) {
		auto imm5 = (inst >> 16) & 0x1FU;
		auto imm4 = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = string("");
		auto index1 = (uint32_t) ((uint32_t) (0x0));
		auto index2 = (uint32_t) ((uint32_t) (0x0));
		if(((bool) ((((uint8_t) ((((uint64_t) (imm5)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U)) != 0) {
			ts = string("B");
			index1 = (uint8_t) ((imm5) >> (uint) (0x1));
			index2 = imm4;
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (imm5)) & ((uint64_t) (0x2))))) == (0x2)) ? 1U : 0U)) != 0) {
				ts = string("H");
				index1 = (uint8_t) ((imm5) >> (uint) (0x2));
				index2 = (uint8_t) ((imm4) >> (uint) (0x1));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (imm5)) & ((uint64_t) (0x4))))) == (0x4)) ? 1U : 0U)) != 0) {
					ts = string("S");
					index1 = (uint8_t) ((imm5) >> (uint) (0x3));
					index2 = (uint8_t) ((imm4) >> (uint) (0x2));
				} else {
					ts = string("D");
					index1 = (uint8_t) ((imm5) >> (uint) (0x4));
					index2 = (uint8_t) ((imm4) >> (uint) (0x3));
				}
			}
		}
		return (boost::format("ins V%1%.%2%[0x%3$#x], V%4%.%5%[0x%6$#x]") % rd % ts % index1 % rn % ts % index2).str();
	}
	insn_129:
	/* LD1-multi-no-offset-one-register */
	if((inst & 0xBFFFF000U) == 0x0C407000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_174) -> string { switch(temp_174) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld1 { V%1%.%2% }, [X%3%]") % rt % T % rn).str();
	}
	insn_130:
	/* LD1-multi-no-offset-two-registers */
	if((inst & 0xBFFFF000U) == 0x0C40A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_176) -> string { switch(temp_176) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld1 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%]") % rt % T % rt2 % T % rn).str();
	}
	insn_131:
	/* LD1-multi-no-offset-three-registers */
	if((inst & 0xBFFFF000U) == 0x0C406000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_178) -> string { switch(temp_178) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%]") % rt % T % rt2 % T % rt3 % T % rn).str();
	}
	insn_132:
	/* LD1-multi-no-offset-four-registers */
	if((inst & 0xBFFFF000U) == 0x0C402000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_180) -> string { switch(temp_180) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%]") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn).str();
	}
	insn_133:
	/* LD1-single-no-offset */
	if((inst & 0xBFFF2000U) == 0x0D400000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto opc = (inst >> 14) & 0x3U;
		auto S = (inst >> 12) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((opc) != (0x3)) ? 1U : 0U)))
			goto insn_134;
		auto t = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("B")) : ((string) (((bool) ((((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U))))) != 0) ? (string("H")) : ((string) (((bool) (((opc) == (0x2)) ? 1U : 0U) != 0) ? ((string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : ((string) (((bool) ((((bool) ((bool) (((size) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) (((S) == (0x0)) ? 1U : 0U))))) != 0) ? (string("D")) : throw "Not implemented")))) : throw "Not implemented")))));
		auto index = (uint32_t) (([=](auto temp_182) -> uint32_t { switch(temp_182) { case 0x0: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3)))))); case 0x1: return (uint32_t) (((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3))))))) >> (uint) (0x1)); case 0x2: return (uint32_t) (((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U) != 0) ? ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (S)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))))) : (Q)); default: throw "Not implemented"; } })(opc));
		return (boost::format("ld1 { V%1%.%2% }[0x%3$#x], [X%4%]") % rt % t % index % rn).str();
	}
	insn_134:
	/* LD1R-single-no-offset */
	if((inst & 0xBFFFF000U) == 0x0D40C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_184) -> string { switch(temp_184) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld1r { V%1%.%2% }, [X%3%]") % rt % t % rn).str();
	}
	insn_135:
	/* LD1R-single-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0DC0C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_136;
		auto t = (string) (([=](auto temp_186) -> string { switch(temp_186) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto imm = (int64_t) (([=](auto temp_187) -> int64_t { switch(temp_187) { case 0x0: return 0x1; case 0x1: return 0x2; case 0x2: return 0x4; default: return 0x8; } })(size));
		return (boost::format("ld1r { V%1%.%2% }, [X%3%], #%4%0x%5$#x") % rt % t % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_136:
	/* LD1R-single-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0DC0C000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_137;
		auto t = (string) (([=](auto temp_190) -> string { switch(temp_190) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x6: return string("1D"); default: return string("2D"); } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld1r { V%1%.%2% }, [X%3%], X%4%") % rt % t % rn % rm).str();
	}
	insn_137:
	/* LD2-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C408000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_192) -> string { switch(temp_192) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld2 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%]") % rt % T % rt2 % T % rn).str();
	}
	insn_138:
	/* LD2-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0CC08000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_139;
		auto T = (string) (([=](auto temp_194) -> string { switch(temp_194) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld2 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%], #%6%") % rt % T % rt2 % T % rn % (uint16_t) imm).str();
	}
	insn_139:
	/* LD2-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0CC08000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_140;
		auto T = (string) (([=](auto temp_196) -> string { switch(temp_196) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld2 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%], X%6%") % rt % T % rt2 % T % rn % rm).str();
	}
	insn_140:
	/* LD3-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C404000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_198) -> string { switch(temp_198) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld3 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%]") % rt % T % rt2 % T % rt3 % T % rn).str();
	}
	insn_141:
	/* LD3-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0CC04000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_142;
		auto T = (string) (([=](auto temp_200) -> string { switch(temp_200) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld3 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%], #%8%") % rt % T % rt2 % T % rt3 % T % rn % (uint16_t) imm).str();
	}
	insn_142:
	/* LD3-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0CC04000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_143;
		auto T = (string) (([=](auto temp_202) -> string { switch(temp_202) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld3 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%], X%8%") % rt % T % rt2 % T % rt3 % T % rn % rm).str();
	}
	insn_143:
	/* LD4-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C400000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_204) -> string { switch(temp_204) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld4 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%]") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn).str();
	}
	insn_144:
	/* LD4-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0CC00000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_145;
		auto T = (string) (([=](auto temp_206) -> string { switch(temp_206) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld4 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%], #%10%") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn % (uint16_t) imm).str();
	}
	insn_145:
	/* LD4-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0CC00000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_146;
		auto T = (string) (([=](auto temp_208) -> string { switch(temp_208) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ld4 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%], X%10%") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn % rm).str();
	}
	insn_146:
	/* LDAR */
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldar %1%%2%, [X%3%]") % r % rt % rn).str();
	}
	insn_147:
	/* LDARB */
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldarb W%1%, [X%2%]") % rt % rn).str();
	}
	insn_148:
	/* LDARH */
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldarh W%1%, [X%2%]") % rt % rn).str();
	}
	insn_149:
	/* LDAXB */
	if((inst & 0xBFFFFC00U) == 0x885FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldaxb W%1%, [X%2%]") % rt % rn).str();
	}
	insn_150:
	/* LDAXRB */
	if((inst & 0xFFFFFC00U) == 0x085FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldaxrb W%1%, [X%2%]") % rt % rn).str();
	}
	insn_151:
	/* LDAXRH */
	if((inst & 0xFFFFFC00U) == 0x485FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldaxrh W%1%, [X%2%]") % rt % rn).str();
	}
	insn_152:
	/* LDP-immediate-postindex */
	if((inst & 0x7FC00000U) == 0x28C00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%], #%6%0x%7$#x") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_153:
	/* LDP-immediate-signed-offset */
	if((inst & 0x7FC00000U) == 0x29400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_154:
	/* LDP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2CC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_210) -> string { switch(temp_210) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_211) -> int64_t { switch(temp_211) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%], #%6%0x%7$#x") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_155:
	/* LDP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2DC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_214) -> string { switch(temp_214) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_215) -> int64_t { switch(temp_215) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]!") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_156:
	/* LDP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D400000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_218) -> string { switch(temp_218) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_219) -> int64_t { switch(temp_219) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_157:
	/* LDPSW-immediate-signed-offset */
	if((inst & 0xFFC00000U) == 0x69400000U) {
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) (0x2));
		return (boost::format("ldpsw X%1%, X%2%, [X%3%, #%4%0x%5$#x]") % rt1 % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_158:
	/* LDR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8400C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldr %1%%2%, [X%3%, #%4%0x%5$#x]!") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_159:
	/* LDR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8400400U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldr %1%%2%, [X%3%], #%4%0x%5$#x") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_160:
	/* LDR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint16_t) ((rawimm) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("ldr %1%%2%, [X%3%, #0x%4$#x]") % r % rd % rn % imm).str();
	}
	insn_161:
	/* LDR-literal */
	if((inst & 0xBF000000U) == 0x18000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) ((uint32_t) ((rawimm) << (uint) (0x2)))), 21));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) (offset)));
		return (boost::format("ldr %1%%2%, #0x%3$#x") % r % rt % addr).str();
	}
	insn_162:
	/* LDR-simd-immediate-postindex */
	if((inst & 0x3F600C00U) == 0x3C400400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		auto r = (string) (([=](auto temp_222) -> string { switch(temp_222) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ldr %1%%2%, [X%3%], #%4%0x%5$#x") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_163:
	/* LDR-simd-immediate-preindex */
	if((inst & 0x3F600C00U) == 0x3C400C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		auto r = (string) (([=](auto temp_224) -> string { switch(temp_224) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ldr %1%%2%, [X%3%, #%4%0x%5$#x]!") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_164:
	/* LDR-simd-immediate-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto ropc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto opc = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x1)))) << 0)) | ((uint8_t) (((uint8_t) (ropc)) << 1))));
		auto m = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_226) -> string { switch(temp_226) { case 0x1: return string("B"); case 0x5: return string("H"); case 0x9: return string("S"); case 0xD: return string("D"); default: return string("Q"); } })(m));
		auto imm = (uint32_t) (((uint32_t) ((uint32_t) (rawimm))) << (uint) ((int64_t) (([=](auto temp_227) -> int64_t { switch(temp_227) { case 0x1: return 0x0; case 0x5: return 0x1; case 0x9: return 0x2; case 0xD: return 0x3; default: return 0x4; } })(m))));
		return (boost::format("ldr %1%%2%, [X%3%, #0x%4$#x]") % r % rt % rn % imm).str();
	}
	insn_165:
	/* LDR-simd-literal */
	if((inst & 0x3F000000U) == 0x1C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_230) -> string { switch(temp_230) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(size));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) (((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) (imm)) << 2)))), 21)))));
		return (boost::format("ldr %1%%2%, #0x%3$#x") % r % rt % addr).str();
	}
	insn_166:
	/* LDR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C600800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (string("Q")) : ((string) (([=](auto temp_232) -> string { switch(temp_232) { case 0x0: return string("B"); case 0x1: return string("H"); case 0x2: return string("S"); case 0x3: return string("D"); default: throw "Not implemented"; } })(size))));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (([=](auto temp_233) -> string { switch(temp_233) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto amount = (uint64_t) (((uint64_t) (bool) (scale)) * ((uint64_t) (int64_t) ((int64_t) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (0x4) : ((int64_t) (([=](auto temp_234) -> int64_t { switch(temp_234) { case 0x0: return 0x1; case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: throw "Not implemented"; } })(size)))))));
		return (boost::format("ldr %1%%2%, [X%3%, %4%%5%, %6% 0x%7$#x]") % r1 % rt % rn % r2 % rm % extend % amount).str();
	}
	insn_167:
	/* LDR-register */
	if((inst & 0xBFE00C00U) == 0xB8600800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_238) -> string { switch(temp_238) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("ldr %1%%2%, [X%3%, %4%%5%, %6% %7%0x%8$#x]") % r1 % rt % rn % r2 % rm % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_168:
	/* LDRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldrb W%1%, [X%2%], #%3%0x%4$#x") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_169:
	/* LDRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldrb W%1%, [X%2%, #%3%0x%4$#x]!") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_170:
	/* LDRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39400000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldrb W%1%, [X%2%, #0x%3$#x]") % rt % rn % imm).str();
	}
	insn_171:
	/* LDRB-register */
	if((inst & 0xFFE00C00U) == 0x38600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_240) -> string { switch(temp_240) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrb W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str();
	}
	insn_172:
	/* LDRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldrh W%1%, [X%2%], #%3%0x%4$#x") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_173:
	/* LDRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldrh W%1%, [X%2%, #%3%0x%4$#x]!") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_174:
	/* LDRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79400000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint16_t) ((rawimm) << (uint) (0x1));
		return (boost::format("ldrh W%1%, [X%2%, #0x%3$#x]") % rt % rn % imm).str();
	}
	insn_175:
	/* LDRH-register */
	if((inst & 0xFFE00C00U) == 0x78600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_242) -> string { switch(temp_242) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrh W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str();
	}
	insn_176:
	/* LDRSB-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x38800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsb %1%%2%, [X%3%], #%4%0x%5$#x") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_177:
	/* LDRSB-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x38800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsb %1%%2%, [X%3%, #%4%0x%5$#x]!") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_178:
	/* LDRSB-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x39800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsb %1%%2%, [X%3%, #0x%4$#x]") % r % rt % rn % imm).str();
	}
	insn_179:
	/* LDRSB-register */
	if((inst & 0xFFA00C00U) == 0x38A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_244) -> string { switch(temp_244) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrsb %1%%2%, [X%3%, %4%%5%, %6% %7%]") % r % rt % rn % r % rm % str % amount).str();
	}
	insn_180:
	/* LDRSH-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x78800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsh %1%%2%, [X%3%], #%4%0x%5$#x") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_181:
	/* LDRSH-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x78800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsh %1%%2%, [X%3%, #%4%0x%5$#x]!") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_182:
	/* LDRSH-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x79800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint16_t) ((rawimm) << (uint) (0x1));
		return (boost::format("ldrsh %1%%2%, [X%3%, #0x%4$#x]") % r % rt % rn % imm).str();
	}
	insn_183:
	/* LDRSH-register */
	if((inst & 0xFFA00C00U) == 0x78A00800U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_246) -> string { switch(temp_246) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrsh %1%%2%, [X%3%, %4%%5%, %6% %7%]") % r % rt % rn % r % rm % str % amount).str();
	}
	insn_184:
	/* LDRSW-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0xB8800400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldrsw X%1%, [X%2%], #%3%0x%4$#x") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_185:
	/* LDRSW-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0xB8800C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldrsw X%1%, [X%2%, #%3%0x%4$#x]!") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_186:
	/* LDRSW-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0xB9800000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint16_t) ((rawimm) << (uint) (0x2));
		return (boost::format("ldrsw X%1%, [X%2%, #0x%3$#x]") % rt % rn % imm).str();
	}
	insn_187:
	/* LDRSW-literal */
	if((inst & 0xFF000000U) == 0x98000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint32_t) ((uint32_t) (((uint32_t) (((uint32_t) ((uint8_t) ((uint8_t) (0x0)))) << 0)) | ((uint32_t) (((uint32_t) (imm)) << 2)))), 21)))));
		return (boost::format("ldrsw X%1%, #0x%2$#x") % rt % addr).str();
	}
	insn_188:
	/* LDRSW-register */
	if((inst & 0xFFE00C00U) == 0xB8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0x2));
		auto extend = (string) (([=](auto temp_248) -> string { switch(temp_248) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("ldrsw X%1%, [X%2%, %3%%4%, %5% %6%0x%7$#x]") % rt % rn % r % rm % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_189:
	/* LDUR */
	if((inst & 0xBFE00C00U) == 0xB8400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldur %1%%2%, [X%3%, #%4%0x%5$#x]") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_190:
	/* LDURB */
	if((inst & 0xFFE00C00U) == 0x38400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldurb W%1%, [X%2%, #%3%0x%4$#x]") % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_191:
	/* LDURH */
	if((inst & 0xFFE00C00U) == 0x78400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldurh W%1%, [X%2%, #%3%0x%4$#x]") % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_192:
	/* LDURSB */
	if((inst & 0xFFA00C00U) == 0x38800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldursb %1%%2%, [X%3%, #%4%0x%5$#x]") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_193:
	/* LDURSH */
	if((inst & 0xFFA00C00U) == 0x78800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldursh %1%%2%, [X%3%, #%4%0x%5$#x]") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_194:
	/* LDURSW */
	if((inst & 0xFFE00C00U) == 0xB8800000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldursw X%1%, [X%2%, #%3%0x%4$#x]") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_195:
	/* LDUR-simd */
	if((inst & 0x3F600C00U) == 0x3C400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_250) -> string { switch(temp_250) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (opc)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto imm = (int64_t) (SignExt<int64_t>(rawimm, 9));
		return (boost::format("ldur %1%%2%, [X%3%, #%4%0x%5$#x]") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str();
	}
	insn_196:
	/* LDXR */
	if((inst & 0xBFFFFC00U) == 0x885F7C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldxr %1%%2%, [X%3%]") % r % rt % rn).str();
	}
	insn_197:
	/* LDXRB */
	if((inst & 0xFFFFFC00U) == 0x085F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldxrb W%1%, [X%2%]") % rt % rn).str();
	}
	insn_198:
	/* LDXRH */
	if((inst & 0xFFFFFC00U) == 0x485F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldxrh W%1%, [X%2%]") % rt % rn).str();
	}
	insn_199:
	/* LDXP */
	if((inst & 0xBFFF8000U) == 0x887F0000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldxp %1%%2%, %3%%4%, [X%5%]") % r % rt % r % rt2 % rn).str();
	}
	insn_200:
	/* LSL-register */
	if((inst & 0x7FE0FC00U) == 0x1AC02000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("lsl %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_201:
	/* LSRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("lsrv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_202:
	/* MADD */
	if((inst & 0x7FE08000U) == 0x1B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("madd %1%%2%, %3%%4%, %5%%6%, %7%%8%") % r % rd % r % rn % r % rm % r % ra).str();
	}
	insn_203:
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
		auto imm8a = (uint8_t) ((uint8_t) ((int64_t) ((a != 0) ? (0xFF) : (0x0))));
		auto imm8b = (uint8_t) ((uint8_t) ((int64_t) ((b != 0) ? (0xFF) : (0x0))));
		auto imm8c = (uint8_t) ((uint8_t) ((int64_t) ((c != 0) ? (0xFF) : (0x0))));
		auto imm8d = (uint8_t) ((uint8_t) ((int64_t) ((d != 0) ? (0xFF) : (0x0))));
		auto imm8e = (uint8_t) ((uint8_t) ((int64_t) ((e != 0) ? (0xFF) : (0x0))));
		auto imm8f = (uint8_t) ((uint8_t) ((int64_t) ((f != 0) ? (0xFF) : (0x0))));
		auto imm8g = (uint8_t) ((uint8_t) ((int64_t) ((g != 0) ? (0xFF) : (0x0))));
		auto imm8h = (uint8_t) ((uint8_t) ((int64_t) ((h != 0) ? (0xFF) : (0x0))));
		auto imm = (uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) (imm8h)) << 0)) | ((uint64_t) (((uint64_t) (imm8g)) << 8)))) | ((uint64_t) (((uint64_t) (imm8f)) << 16)))) | ((uint64_t) (((uint64_t) (imm8e)) << 24)))) | ((uint64_t) (((uint64_t) (imm8d)) << 32)))) | ((uint64_t) (((uint64_t) (imm8c)) << 40)))) | ((uint64_t) (((uint64_t) (imm8b)) << 48)))) | ((uint64_t) (((uint64_t) (imm8a)) << 56))));
		return (boost::format("movi D%1%, #0x%2$#x") % rd % imm).str();
	}
	insn_204:
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
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("movi V%1%.%2%, #%3%") % rd % t % (uint16_t) imm).str();
	}
	insn_205:
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
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("movi V%1%.%2%, #%3%") % rd % t % (uint16_t) imm).str();
	}
	insn_206:
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
		auto amount = (int64_t) (([=](auto temp_252) -> int64_t { switch(temp_252) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("movi V%1%.%2%, #%3%, LSL #%4%0x%5$#x") % rd % t % (uint16_t) imm % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_207:
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
		auto imm = (uint64_t) ((uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (uint64_t) (((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (h)) << 1)))) | ((uint8_t) (((uint8_t) (h)) << 2)))) | ((uint8_t) (((uint8_t) (h)) << 3)))) | ((uint8_t) (((uint8_t) (h)) << 4)))) | ((uint8_t) (((uint8_t) (h)) << 5)))) | ((uint8_t) (((uint8_t) (h)) << 6)))) | ((uint8_t) (((uint8_t) (h)) << 7)))))) << 0)) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (g)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (g)) << 2)))) | ((uint8_t) (((uint8_t) (g)) << 3)))) | ((uint8_t) (((uint8_t) (g)) << 4)))) | ((uint8_t) (((uint8_t) (g)) << 5)))) | ((uint8_t) (((uint8_t) (g)) << 6)))) | ((uint8_t) (((uint8_t) (g)) << 7)))))) << 8)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (f)) << 0)) | ((uint8_t) (((uint8_t) (f)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (f)) << 3)))) | ((uint8_t) (((uint8_t) (f)) << 4)))) | ((uint8_t) (((uint8_t) (f)) << 5)))) | ((uint8_t) (((uint8_t) (f)) << 6)))) | ((uint8_t) (((uint8_t) (f)) << 7)))))) << 16)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (e)) << 0)) | ((uint8_t) (((uint8_t) (e)) << 1)))) | ((uint8_t) (((uint8_t) (e)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (e)) << 4)))) | ((uint8_t) (((uint8_t) (e)) << 5)))) | ((uint8_t) (((uint8_t) (e)) << 6)))) | ((uint8_t) (((uint8_t) (e)) << 7)))))) << 24)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (d)) << 0)) | ((uint8_t) (((uint8_t) (d)) << 1)))) | ((uint8_t) (((uint8_t) (d)) << 2)))) | ((uint8_t) (((uint8_t) (d)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (d)) << 5)))) | ((uint8_t) (((uint8_t) (d)) << 6)))) | ((uint8_t) (((uint8_t) (d)) << 7)))))) << 32)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (c)) << 0)) | ((uint8_t) (((uint8_t) (c)) << 1)))) | ((uint8_t) (((uint8_t) (c)) << 2)))) | ((uint8_t) (((uint8_t) (c)) << 3)))) | ((uint8_t) (((uint8_t) (c)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (c)) << 6)))) | ((uint8_t) (((uint8_t) (c)) << 7)))))) << 40)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (b)) << 0)) | ((uint8_t) (((uint8_t) (b)) << 1)))) | ((uint8_t) (((uint8_t) (b)) << 2)))) | ((uint8_t) (((uint8_t) (b)) << 3)))) | ((uint8_t) (((uint8_t) (b)) << 4)))) | ((uint8_t) (((uint8_t) (b)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (b)) << 7)))))) << 48)))) | ((uint64_t) (((uint64_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (a)) << 0)) | ((uint8_t) (((uint8_t) (a)) << 1)))) | ((uint8_t) (((uint8_t) (a)) << 2)))) | ((uint8_t) (((uint8_t) (a)) << 3)))) | ((uint8_t) (((uint8_t) (a)) << 4)))) | ((uint8_t) (((uint8_t) (a)) << 5)))) | ((uint8_t) (((uint8_t) (a)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7)))))) << 56))));
		return (boost::format("movi V%1%, #0x%2$#x") % rd % imm).str();
	}
	insn_208:
	/* MOVK */
	if((inst & 0x7F800000U) == 0x72800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (uint8_t) ((hw) << (uint) (0x4));
		return (boost::format("movk %1%%2%, #0x%3$#x, LSL #%4%") % r % rd % imm % shift).str();
	}
	insn_209:
	/* MOVN */
	if((inst & 0x7F800000U) == 0x12800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (uint8_t) ((hw) << (uint) (0x4));
		return (boost::format("movn %1%%2%, #0x%3$#x, LSL #%4%") % r % rd % imm % shift).str();
	}
	insn_210:
	/* MOVZ */
	if((inst & 0x7F800000U) == 0x52800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (uint8_t) ((hw) << (uint) (0x4));
		return (boost::format("movz %1%%2%, #0x%3$#x, LSL #%4%") % r % rd % imm % shift).str();
	}
	insn_211:
	/* MRS */
	if((inst & 0xFFF00000U) == 0xD5300000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("mrs S%1% %2% %3% %4% %5%, X%6%") % op0 % op1 % cn % cm % op2 % rt).str();
	}
	insn_212:
	/* MSR-register */
	if((inst & 0xFFF00000U) == 0xD5100000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("msr S%1% %2% %3% %4% %5%, X%6%") % op0 % op1 % cn % cm % op2 % rt).str();
	}
	insn_213:
	/* MSUB */
	if((inst & 0x7FE08000U) == 0x1B008000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("msub %1%%2%, %3%%4%, %5%%6%, %7%%8%") % r % rd % r % rn % r % rm % r % ra).str();
	}
	insn_214:
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
		auto rm = (uint8_t) (((bool) (((size) == (0x2)) ? 1U : 0U) != 0) ? ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (rv)) << 0)) | ((uint8_t) (((uint8_t) (M)) << 4))))) : (rv));
		auto t = (string) (([=](auto temp_254) -> string { switch(temp_254) { case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto ts = (string) (([=](auto temp_255) -> string { switch(temp_255) { case 0x1: return string("H"); case 0x2: return string("S"); default: throw "Not implemented"; } })(size));
		auto index = (uint8_t) (([=](auto temp_256) -> uint8_t { switch(temp_256) { case 0x1: return (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (M)) << 0)) | ((uint8_t) (((uint8_t) (L)) << 1)))) | ((uint8_t) (((uint8_t) (H)) << 2)))); case 0x2: return (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (L)) << 0)) | ((uint8_t) (((uint8_t) (H)) << 1)))); default: throw "Not implemented"; } })(size));
		return (boost::format("mul V%1%.%2%, V%3%.%4%, V%5%.%6%[%7%]") % rd % t % rn % t % rm % ts % index).str();
	}
	insn_215:
	/* MUL-vector */
	if((inst & 0xBF20FC00U) == 0x0E209C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_260) -> string { switch(temp_260) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("mul V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str();
	}
	insn_216:
	/* MVNI-vector-16bit */
	if((inst & 0xBFF8DC00U) == 0x2F008400U) {
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
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		auto amount = (int64_t) ((cmode != 0) ? (0x8) : (0x0));
		return (boost::format("mvni V%1%.%2%, #%3%, LSL #%4%0x%5$#x") % rd % t % (uint16_t) imm % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_217:
	/* MVNI-vector-32bit-LSL */
	if((inst & 0xBFF89C00U) == 0x2F000400U) {
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
		auto amount = (int64_t) (([=](auto temp_262) -> int64_t { switch(temp_262) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("mvni V%1%.%2%, #%3%, LSL #%4%0x%5$#x") % rd % t % (uint16_t) imm % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_218:
	/* MVNI-vector-32bit-MSL */
	if((inst & 0xBFF8EC00U) == 0x2F00E400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto a = (inst >> 18) & 0x1U;
		auto b = (inst >> 17) & 0x1U;
		auto c = (inst >> 16) & 0x1U;
		auto cmode = (inst >> 12) & 0x1U;
		auto d = (inst >> 9) & 0x1U;
		auto e = (inst >> 8) & 0x1U;
		auto f = (inst >> 7) & 0x1U;
		auto g = (inst >> 6) & 0x1U;
		auto h = (inst >> 5) & 0x1U;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
		auto amount = (int64_t) ((cmode != 0) ? (0x10) : (0x8));
		auto imm = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (h)) << 0)) | ((uint8_t) (((uint8_t) (g)) << 1)))) | ((uint8_t) (((uint8_t) (f)) << 2)))) | ((uint8_t) (((uint8_t) (e)) << 3)))) | ((uint8_t) (((uint8_t) (d)) << 4)))) | ((uint8_t) (((uint8_t) (c)) << 5)))) | ((uint8_t) (((uint8_t) (b)) << 6)))) | ((uint8_t) (((uint8_t) (a)) << 7))));
		return (boost::format("mvni V%1%.%2%, #%3%, MSL #%4%0x%5$#x") % rd % t % (uint16_t) imm % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_219:
	/* NEG-vector */
	if((inst & 0xBF3FFC00U) == 0x2E20B800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_264) -> string { switch(temp_264) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("neg V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str();
	}
	insn_220:
	/* NOP */
	if((inst & 0xFFFFFFFFU) == 0xD503201FU) {
		return (boost::format("nop")).str();
	}
	insn_221:
	/* ORN-shifted-register */
	if((inst & 0x7F200000U) == 0x2A200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_266) -> string { switch(temp_266) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("orn %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_222:
	/* ORR-immediate */
	if((inst & 0x7F800000U) == 0x32000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto up = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint64_t) (MakeWMask(up, imms, immr, (int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x20) : (0x40)), 0x1));
		return (boost::format("orr %1%%2%, %3%%4%, #0x%5$#x") % r % rd % r % rn % imm).str();
	}
	insn_223:
	/* ORR-shifted-register */
	if((inst & 0x7F200000U) == 0x2A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_268) -> string { switch(temp_268) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("orr %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_224:
	/* ORR-simd-register */
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x0)) ? 1U : 0U) != 0) ? (string("8B")) : (string("16B")));
		return (boost::format("orr V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str();
	}
	insn_225:
	/* PMULL[2] */
	if((inst & 0xBF20FC00U) == 0x0E20E000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto h = (string) ((Q != 0) ? (string("2")) : (string("")));
		auto Ta = (string) (([=](auto temp_270) -> string { switch(temp_270) { case 0x0: return string("8H"); case 0x3: return string("1Q"); default: throw "Not implemented"; } })(size));
		auto Tb = (string) (([=](auto temp_271) -> string { switch(temp_271) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x6: return string("1D"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("pmull%1% V%2%.%3%, V%4%.%5%, V%6%.%7%") % h % rd % Ta % rn % Tb % rm % Tb).str();
	}
	insn_226:
	/* PRFM-immediate */
	if((inst & 0xFFC00000U) == 0xF9800000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto imm5 = (inst >> 0) & 0x1FU;
		auto pimm = (uint64_t) (((uint64_t) (uint16_t) (imm)) * ((uint64_t) (int64_t) (0x8)));
		return (boost::format("prfm #%1%, [X%2%, #0x%3$#x]") % imm5 % rn % pimm).str();
	}
	insn_227:
	/* PRFM-literal */
	if((inst & 0xFF000000U) == 0xD8000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("prfm TODO")).str();
	}
	insn_228:
	/* PRFM-register */
	if((inst & 0xFFE00C00U) == 0xF8A00800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto opt = (inst >> 13) & 0x7U;
		auto S = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("prfm TODO")).str();
	}
	insn_229:
	/* PRFUM */
	if((inst & 0xFFE00C00U) == 0xF8800000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("prfum TODO")).str();
	}
	insn_230:
	/* RBIT */
	if((inst & 0x7FFFFC00U) == 0x5AC00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rbit %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_231:
	/* RET */
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return (boost::format("ret X%1%") % rn).str();
	}
	insn_232:
	/* REV */
	if((inst & 0x7FFFF800U) == 0x5AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto opc = (inst >> 10) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rev %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_233:
	/* REV16 */
	if((inst & 0x7FFFFC00U) == 0x5AC00400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rev16 %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_234:
	/* RORV */
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rorv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_235:
	/* SBCS */
	if((inst & 0x7FE0FC00U) == 0x7A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("sbcs %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_236:
	/* SBFM */
	if((inst & 0x7F800000U) == 0x13000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("sbfm %1%%2%, %3%%4%, #%5%, #%6%") % r % rd % r % rn % immr % imms).str();
	}
	insn_237:
	/* SCVTF-scalar-integer */
	if((inst & 0x7F3FFC00U) == 0x1E220000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("scvtf %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_238:
	/* SCVTF-scalar */
	if((inst & 0xFFBFFC00U) == 0x5E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return (boost::format("scvtf %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_239:
	/* SCVTF-vector */
	if((inst & 0xBFBFFC00U) == 0x0E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_274) -> string { switch(temp_274) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("scvtf V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str();
	}
	insn_240:
	/* SDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("sdiv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_241:
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
			goto insn_242;
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			T = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			size = 0x1;
			shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x8)));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				T = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				size = 0x2;
				shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x10)));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					T = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					size = 0x4;
					shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x20)));
				} else {
					T = (string) ((Q != 0) ? (string("2D")) : throw "Not implemented");
					size = 0x8;
					shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x20)));
				}
			}
		}
		return (boost::format("shl V%1%.%2%, V%3%.%4%, #%5%0x%6$#x") % rd % T % rn % T % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str();
	}
	insn_242:
	/* SMADDL */
	if((inst & 0xFFE08000U) == 0x9B200000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("smaddl X%1%, W%2%, W%3%, X%4%") % rd % rn % rm % ra).str();
	}
	insn_243:
	/* SMULH */
	if((inst & 0xFFE0FC00U) == 0x9B407C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("smulh X%1%, X%2%, X%3%") % rd % rn % rm).str();
	}
	insn_244:
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
		auto shift = (uint64_t) ((uint64_t) (0x0));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			ta = string("8H");
			tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			shift = (uint64_t) (((uint64_t) (uint8_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))) - ((uint64_t) (int64_t) (0x8)));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				ta = string("4S");
				tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				shift = (uint64_t) (((uint64_t) (uint8_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))) - ((uint64_t) (int64_t) (0x10)));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					ta = string("2D");
					tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					shift = (uint64_t) (((uint64_t) (uint8_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))) - ((uint64_t) (int64_t) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		return (boost::format("sshll%1% V%2%.%3%, V%4%.%5%, #0x%6$#x") % variant % rd % ta % rn % tb % shift).str();
	}
	insn_245:
	/* ST1-multi-no-offset-one-register */
	if((inst & 0xBFFFF000U) == 0x0C007000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_276) -> string { switch(temp_276) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2% }, [X%3%]") % rt % T % rn).str();
	}
	insn_246:
	/* ST1-multi-postindex-immediate-one-register */
	if((inst & 0xBFE0F000U) == 0x0C807000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_247;
		auto T = (string) (([=](auto temp_278) -> string { switch(temp_278) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2% }, [X%3%], #%4%") % rt % T % rn % (uint16_t) imm).str();
	}
	insn_247:
	/* ST1-multi-postindex-register-one-register */
	if((inst & 0xBFE0F000U) == 0x0C807000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_248;
		auto T = (string) (([=](auto temp_280) -> string { switch(temp_280) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2% }, [X%3%], X%4%") % rt % T % rn % rm).str();
	}
	insn_248:
	/* ST1-multi-no-offset-two-registers */
	if((inst & 0xBFFFF000U) == 0x0C00A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_282) -> string { switch(temp_282) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%]") % rt % T % rt2 % T % rn).str();
	}
	insn_249:
	/* ST1-multi-postindex-immediate-two-registers */
	if((inst & 0xBFE0F000U) == 0x0C80A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_250;
		auto T = (string) (([=](auto temp_284) -> string { switch(temp_284) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%], #%6%") % rt % T % rt2 % T % rn % (uint16_t) imm).str();
	}
	insn_250:
	/* ST1-multi-postindex-register-two-registers */
	if((inst & 0xBFE0F000U) == 0x0C80A000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_251;
		auto T = (string) (([=](auto temp_286) -> string { switch(temp_286) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%], X%6%") % rt % T % rt2 % T % rn % rm).str();
	}
	insn_251:
	/* ST1-multi-no-offset-three-registers */
	if((inst & 0xBFFFF000U) == 0x0C006000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_288) -> string { switch(temp_288) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%]") % rt % T % rt2 % T % rt3 % T % rn).str();
	}
	insn_252:
	/* ST1-multi-postindex-immediate-three-registers */
	if((inst & 0xBFE0F000U) == 0x0C806000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_253;
		auto T = (string) (([=](auto temp_290) -> string { switch(temp_290) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%], #%8%") % rt % T % rt2 % T % rt3 % T % rn % (uint16_t) imm).str();
	}
	insn_253:
	/* ST1-multi-postindex-register-three-registers */
	if((inst & 0xBFE0F000U) == 0x0C806000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_254;
		auto T = (string) (([=](auto temp_292) -> string { switch(temp_292) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%], X%8%") % rt % T % rt2 % T % rt3 % T % rn % rm).str();
	}
	insn_254:
	/* ST1-multi-no-offset-four-registers */
	if((inst & 0xBFFFF000U) == 0x0C002000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_294) -> string { switch(temp_294) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%]") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn).str();
	}
	insn_255:
	/* ST1-multi-postindex-immediate-four-registers */
	if((inst & 0xBFE0F000U) == 0x0C802000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x40) : (0x20))));
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_256;
		auto T = (string) (([=](auto temp_296) -> string { switch(temp_296) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%], #%10%") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn % (uint16_t) imm).str();
	}
	insn_256:
	/* ST1-multi-postindex-register-four-registers */
	if((inst & 0xBFE0F000U) == 0x0C802000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_257;
		auto T = (string) (([=](auto temp_298) -> string { switch(temp_298) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st1 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%], X%10%") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn % rm).str();
	}
	insn_257:
	/* ST1-single-no-offset */
	if((inst & 0xBFFF2000U) == 0x0D000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto opc = (inst >> 14) & 0x3U;
		auto S = (inst >> 12) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		if(!((bool) (((opc) != (0x3)) ? 1U : 0U)))
			goto insn_258;
		auto t = (string) (((bool) (((opc) == (0x0)) ? 1U : 0U) != 0) ? (string("B")) : ((string) (((bool) ((((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U))))) != 0) ? (string("H")) : ((string) (((bool) (((opc) == (0x2)) ? 1U : 0U) != 0) ? ((string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : ((string) (((bool) ((((bool) ((bool) (((size) == (0x1)) ? 1U : 0U))) & ((bool) ((bool) (((S) == (0x0)) ? 1U : 0U))))) != 0) ? (string("D")) : throw "Not implemented")))) : throw "Not implemented")))));
		auto index = (uint32_t) (([=](auto temp_300) -> uint32_t { switch(temp_300) { case 0x0: return (uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3)))))); case 0x1: return (uint32_t) (((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (S)) << 2)))) | ((uint8_t) (((uint8_t) (Q)) << 3))))))) >> (uint) (0x1)); case 0x2: return (uint32_t) (((bool) ((((uint8_t) ((((uint64_t) (size)) & ((uint64_t) (0x1))))) == (0x0)) ? 1U : 0U) != 0) ? ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (S)) << 0)) | ((uint8_t) (((uint8_t) (Q)) << 1))))))) : (Q)); default: throw "Not implemented"; } })(opc));
		return (boost::format("st1 { V%1%.%2% }[0x%3$#x], [X%4%]") % rt % t % index % rn).str();
	}
	insn_258:
	/* ST2-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C008000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_302) -> string { switch(temp_302) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st2 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%]") % rt % T % rt2 % T % rn).str();
	}
	insn_259:
	/* ST2-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0C808000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x20) : (0x10))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_260;
		auto T = (string) (([=](auto temp_304) -> string { switch(temp_304) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st2 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%], #%6%") % rt % T % rt2 % T % rn % (uint16_t) imm).str();
	}
	insn_260:
	/* ST2-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0C808000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_261;
		auto T = (string) (([=](auto temp_306) -> string { switch(temp_306) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st2 { V%1%.%2%, V0x%3$#x.%4% }, [X%5%], X%6%") % rt % T % rt2 % T % rn % rm).str();
	}
	insn_261:
	/* ST3-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C004000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_308) -> string { switch(temp_308) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st3 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%]") % rt % T % rt2 % T % rt3 % T % rn).str();
	}
	insn_262:
	/* ST3-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0C804000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x30) : (0x18))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_263;
		auto T = (string) (([=](auto temp_310) -> string { switch(temp_310) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st3 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%], #%8%") % rt % T % rt2 % T % rt3 % T % rn % (uint16_t) imm).str();
	}
	insn_263:
	/* ST3-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0C804000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_264;
		auto T = (string) (([=](auto temp_312) -> string { switch(temp_312) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st3 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6% }, [X%7%], X%8%") % rt % T % rt2 % T % rt3 % T % rn % rm).str();
	}
	insn_264:
	/* ST4-multi-no-offset */
	if((inst & 0xBFFFF000U) == 0x0C000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto T = (string) (([=](auto temp_314) -> string { switch(temp_314) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st4 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%]") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn).str();
	}
	insn_265:
	/* ST4-multi-postindex-immediate */
	if((inst & 0xBFE0F000U) == 0x0C800000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		auto imm = (uint8_t) ((uint8_t) ((int64_t) ((Q != 0) ? (0x40) : (0x2B))));
		if(!((bool) (((rm) == (0x1F)) ? 1U : 0U)))
			goto insn_266;
		auto T = (string) (([=](auto temp_316) -> string { switch(temp_316) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st4 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%], #%10%") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn % (uint16_t) imm).str();
	}
	insn_266:
	/* ST4-multi-postindex-register */
	if((inst & 0xBFE0F000U) == 0x0C800000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto size = (inst >> 10) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rt2 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x1))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt3 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x2))))) % ((uint64_t) (int64_t) (0x20)));
		auto rt4 = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (((uint64_t) (uint8_t) (rt)) + ((uint64_t) (int64_t) (0x3))))) % ((uint64_t) (int64_t) (0x20)));
		if(!((bool) (((rm) != (0x1F)) ? 1U : 0U)))
			goto insn_267;
		auto T = (string) (([=](auto temp_318) -> string { switch(temp_318) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("st4 { V%1%.%2%, V0x%3$#x.%4%, V0x%5$#x.%6%, V0x%7$#x.%8% }, [X%9%], X%10%") % rt % T % rt2 % T % rt3 % T % rt4 % T % rn % rm).str();
	}
	insn_267:
	/* STLR */
	if((inst & 0xBFFFFC00U) == 0x889FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stlr %1%%2%, [X%3%]") % r % rt % rn).str();
	}
	insn_268:
	/* STLRB */
	if((inst & 0xFFFFFC00U) == 0x089FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stlrb W%1%, [X%2%]") % rt % rn).str();
	}
	insn_269:
	/* STLRH */
	if((inst & 0xFFFFFC00U) == 0x489FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stlrh W%1%, [X%2%]") % rt % rn).str();
	}
	insn_270:
	/* STLXR */
	if((inst & 0xBFE0FC00U) == 0x8800FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stlxr W%1%, %2%%3%, [X%4%]") % rs % r % rt % rn).str();
	}
	insn_271:
	/* STLXRB */
	if((inst & 0xFFE0FC00U) == 0x0800FC00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stlxrr W%1%, W%2%, [X%3%]") % rs % rt % rn).str();
	}
	insn_272:
	/* STP-postindex */
	if((inst & 0x7FC00000U) == 0x28800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%], #%6%0x%7$#x") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_273:
	/* STP-preindex */
	if((inst & 0x7FC00000U) == 0x29800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]!") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_274:
	/* STP-signed-offset */
	if((inst & 0x7FC00000U) == 0x29000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_275:
	/* STP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2C800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_320) -> string { switch(temp_320) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_321) -> int64_t { switch(temp_321) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%], #%6%0x%7$#x") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_276:
	/* STP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2D800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_324) -> string { switch(temp_324) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_325) -> int64_t { switch(temp_325) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]!") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_277:
	/* STP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D000000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_328) -> string { switch(temp_328) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (int64_t) (((int64_t) (SignExt<int64_t>(imm, 7))) << (uint) ((int64_t) (([=](auto temp_329) -> int64_t { switch(temp_329) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%0x%7$#x]") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_278:
	/* STR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8000400U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%], #%4%0x%5$#x") % r % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_279:
	/* STR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8000C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%, #%4%0x%5$#x]!") % r % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_280:
	/* STR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto pimm = (uint64_t) (((uint64_t) ((uint64_t) (imm))) << (uint) ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("str %1%%2%, [X%3%, #0x%4$#x]") % r % rs % rd % pimm).str();
	}
	insn_281:
	/* STR-register */
	if((inst & 0xBFE00C00U) == 0xB8200800U) {
		auto size = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((int64_t) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		auto extend = (string) (([=](auto temp_332) -> string { switch(temp_332) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("str %1%%2%, [X%3%, %4%%5%, %6% %7%0x%8$#x]") % r1 % rt % rn % r2 % rm % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_282:
	/* STR-simd-postindex */
	if((inst & 0x3F600C00U) == 0x3C000400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_334) -> string { switch(temp_334) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%], #%4%0x%5$#x") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_283:
	/* STR-simd-preindex */
	if((inst & 0x3F600C00U) == 0x3C000C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_336) -> string { switch(temp_336) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 2))));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%, #%4%0x%5$#x]!") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_284:
	/* STR-simd-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_338) -> string { switch(temp_338) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (size)) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 2))));
		return (boost::format("str %1%%2%, [X%3%, #0x%4$#x]") % r % rt % rn % imm).str();
	}
	insn_285:
	/* STR-simd-register */
	if((inst & 0x3F600C00U) == 0x3C200800U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto scale = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r1 = (string) (([=](auto temp_340) -> string { switch(temp_340) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto r2 = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (int64_t) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((int64_t) (([=](auto temp_341) -> int64_t { switch(temp_341) { case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: return (int64_t) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (0x4) : (0x0)); } })(size))));
		auto extend = (string) (([=](auto temp_342) -> string { switch(temp_342) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("str %1%%2%, [X%3%, %4%, %5% %6%0x%7$#x]") % r1 % rt % rn % r2 % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str();
	}
	insn_286:
	/* STRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("strb W%1%, [X%2%], #%3%0x%4$#x") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_287:
	/* STRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("strb W%1%, [X%2%, #%3%0x%4$#x]!") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_288:
	/* STRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39000000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("strb W%1%, [X%2%, #0x%3$#x]") % rt % rn % imm).str();
	}
	insn_289:
	/* STRB-register */
	if((inst & 0xFFE00C00U) == 0x38200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_346) -> string { switch(temp_346) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("strb W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str();
	}
	insn_290:
	/* STRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("strh W%1%, [X%2%], #%3%0x%4$#x") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_291:
	/* STRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("strh W%1%, [X%2%, #%3%0x%4$#x]!") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_292:
	/* STRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79000000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (uint16_t) ((rawimm) << (uint) (0x1));
		return (boost::format("strh W%1%, [X%2%, #0x%3$#x]") % rt % rn % imm).str();
	}
	insn_293:
	/* STRH-register */
	if((inst & 0xFFE00C00U) == 0x78200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_348) -> string { switch(temp_348) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("strh W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str();
	}
	insn_294:
	/* STUR */
	if((inst & 0xBFE00C00U) == 0xB8000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("stur %1%%2%, [X%3%, #%4%0x%5$#x]") % r % rt % rn % ((offset) < 0 ? "-" : "") % ((offset) < 0 ? -(offset) : (offset))).str();
	}
	insn_295:
	/* STUR-simd */
	if((inst & 0x3F600C00U) == 0x3C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (uint8_t) ((uint8_t) (((uint8_t) (uint8_t) (((uint8_t) (((uint8_t) ((bool) ((bool) (0x0)))) << 0)) | ((uint8_t) (((uint8_t) (opc)) << 1)))) | ((uint8_t) (((uint8_t) (size)) << 2))));
		auto r = (string) (([=](auto temp_350) -> string { switch(temp_350) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("stur %1%%2%, [X%3%, #%4%0x%5$#x]") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str();
	}
	insn_296:
	/* STURB */
	if((inst & 0xFFE00C00U) == 0x38000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("sturb W%1%, [X%2%, #%3%0x%4$#x]") % rt % rn % ((offset) < 0 ? "-" : "") % ((offset) < 0 ? -(offset) : (offset))).str();
	}
	insn_297:
	/* STURH */
	if((inst & 0xFFE00C00U) == 0x78000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (int64_t) (SignExt<int64_t>(imm, 9));
		return (boost::format("sturh W%1%, [X%2%, #%3%0x%4$#x]") % rt % rn % ((offset) < 0 ? "-" : "") % ((offset) < 0 ? -(offset) : (offset))).str();
	}
	insn_298:
	/* STXRB */
	if((inst & 0xFFE0FC00U) == 0x08007C00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stxrb W%1%, W%2%, [X%3%]") % rs % rt % rn).str();
	}
	insn_299:
	/* STXR */
	if((inst & 0xBFE0FC00U) == 0x88007C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stxr W%1%, %2%%3%, [X%4%]") % rs % r % rt % rn).str();
	}
	insn_300:
	/* STXP */
	if((inst & 0xBFE08000U) == 0x88200000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stxp W%1%, %2%%3%, %4%%5%, [X%6%]") % rs % r % rt % r % rt2 % rn).str();
	}
	insn_301:
	/* SUB-immediate */
	if((inst & 0x7F800000U) == 0x51000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto sh = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (int64_t) (((bool) (((sh) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : (0xC));
		return (boost::format("sub %1%%2%, %3%%4%, #0x%5$#x, LSL #%6%0x%7$#x") % r % rd % r % rn % imm % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str();
	}
	insn_302:
	/* SUB-extended-register */
	if((inst & 0x7FE00000U) == 0x4B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_352) -> string { switch(temp_352) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_353) -> string { switch(temp_353) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("sub %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str();
	}
	insn_303:
	/* SUB-shifted-register */
	if((inst & 0x7F200000U) == 0x4B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto imm = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_356) -> string { switch(temp_356) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("sub %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_304:
	/* SUBS-extended-register */
	if((inst & 0x7FE00000U) == 0x6B200000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto imm = (inst >> 10) & 0x7U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r1 = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto r2 = (string) (((bool) ((((uint8_t) ((((uint64_t) (option)) & ((uint64_t) (0x3))))) == (0x3)) ? 1U : 0U) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_358) -> string { switch(temp_358) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_359) -> string { switch(temp_359) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("subs %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str();
	}
	insn_305:
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
		auto shiftstr = (string) (([=](auto temp_362) -> string { switch(temp_362) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("subs %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str();
	}
	insn_306:
	/* SUBS-immediate */
	if((inst & 0x7F800000U) == 0x71000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_364) -> string { switch(temp_364) { case 0x0: return string("LSL #0"); case 0x1: return string("LSL #12"); default: throw "Not implemented"; } })(shift));
		return (boost::format("subs %1%%2%, %3%%4%, #0x%5$#x, %6%") % r % rd % r % rn % imm % shiftstr).str();
	}
	insn_307:
	/* SVC */
	if((inst & 0xFFE0001FU) == 0xD4000001U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		return (boost::format("svc #0x%1$#x") % imm).str();
	}
	insn_308:
	/* SYS */
	if((inst & 0xFFF80000U) == 0xD5080000U) {
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("sys #%1%, %2%, %3%, #%4%, X%5%") % op1 % cn % cm % op2 % rt).str();
	}
	insn_309:
	/* TBZ */
	if((inst & 0x7F000000U) == 0x36000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint32_t) ((((uint32_t) ((uint32_t) (((uint32_t) ((uint32_t) (upper))) << (uint) (0x5)))) | ((uint32_t) ((uint32_t) ((uint32_t) (bottom))))));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint16_t) (((uint16_t) ((uint16_t) (offset))) << (uint) (0x2)), 16)))));
		return (boost::format("tbz %1%%2%, #0x%3$#x, 0x%4$#x") % r % rt % imm % addr).str();
	}
	insn_310:
	/* TBNZ */
	if((inst & 0x7F000000U) == 0x37000000U) {
		auto upper = (inst >> 31) & 0x1U;
		auto bottom = (inst >> 19) & 0x1FU;
		auto offset = (inst >> 5) & 0x3FFFU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((upper) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (uint32_t) ((((uint32_t) ((uint32_t) (((uint32_t) ((uint32_t) (upper))) << (uint) (0x5)))) | ((uint32_t) ((uint32_t) ((uint32_t) (bottom))))));
		auto addr = (uint64_t) (((uint64_t) (uint64_t) ((uint64_t) (pc))) + ((uint64_t) (int64_t) ((int64_t) (SignExt<int64_t>((uint16_t) (((uint16_t) ((uint16_t) (offset))) << (uint) (0x2)), 16)))));
		return (boost::format("tbnz %1%%2%, #0x%3$#x, 0x%4$#x") % r % rt % imm % addr).str();
	}
	insn_311:
	/* UADDLV */
	if((inst & 0xBF3FFC00U) == 0x2E303800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_366) -> string { switch(temp_366) { case 0x0: return string("H"); case 0x1: return string("S"); case 0x2: return string("D"); default: throw "Not implemented"; } })(size));
		auto t = (string) (([=](auto temp_367) -> string { switch(temp_367) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		auto esize = (int64_t) ((0x8) << (uint) (size));
		auto count = (int64_t) (((int64_t) (int64_t) ((int64_t) ((Q != 0) ? (0x80) : (0x40)))) / ((int64_t) (int64_t) (esize)));
		return (boost::format("uaddlv %1%%2%, V%3%.%4%") % r % rd % rn % t).str();
	}
	insn_312:
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
		switch((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))) {
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
		return (boost::format("uaddw%1% V%2%.%3%, V%4%.%5%, V%6%.%7%") % o2 % rd % Ta % rn % Ta % rm % Tb).str();
	}
	insn_313:
	/* UBFM */
	if((inst & 0x7F800000U) == 0x53000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto N = (inst >> 22) & 0x1U;
		auto immr = (inst >> 16) & 0x3FU;
		auto imms = (inst >> 10) & 0x3FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ubfm %1%%2%, %3%%4%, #%5%, #%6%") % r % rd % r % rn % immr % imms).str();
	}
	insn_314:
	/* UCVTF-scalar-gpr-integer */
	if((inst & 0x7F3FFC00U) == 0x1E230000U) {
		auto size = (inst >> 31) & 0x1U;
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto st = (uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (type)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 2))));
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
		return (boost::format("ucvtf %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str();
	}
	insn_315:
	/* UCVTF-scalar-integer */
	if((inst & 0xFFBFFC00U) == 0x7E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return (boost::format("ucvtf %1%%2%, %3%%4%") % r % rd % r % rn).str();
	}
	insn_316:
	/* UCVTF-vector */
	if((inst & 0xBFBFFC00U) == 0x2E21D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_370) -> string { switch(temp_370) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ucvtf V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str();
	}
	insn_317:
	/* UDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("udiv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str();
	}
	insn_318:
	/* UMADDL */
	if((inst & 0xFFE08000U) == 0x9BA00000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("umaddl X%1%, W%2%, W%3%, X%4%") % rd % rn % rm % ra).str();
	}
	insn_319:
	/* UMOV */
	if((inst & 0xBFE0FC00U) == 0x0E003C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = string("");
		auto index = 0x0;
		auto r = (string) ((Q != 0) ? (string("X")) : (string("W")));
		auto size = (int64_t) ((Q != 0) ? (0x40) : ((int64_t) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x1))))) == (0x1)) ? 1U : 0U) != 0) ? (0x8) : ((int64_t) (((bool) ((((uint8_t) ((((uint64_t) (imm)) & ((uint64_t) (0x3))))) == (0x2)) ? 1U : 0U) != 0) ? (0x10) : (0x20))))));
		switch(size) {
			case 0x8: {
				T = string("B");
				index = (uint8_t) ((imm) >> (uint) (0x1));
				break;
			}
			case 0x10: {
				T = string("H");
				index = (uint8_t) ((imm) >> (uint) (0x2));
				break;
			}
			case 0x20: {
				T = string("S");
				index = (uint8_t) ((imm) >> (uint) (0x3));
				break;
			}
			default: {
				T = string("D");
				index = (uint8_t) ((imm) >> (uint) (0x4));
				break;
			}
		}
		return (boost::format("umov %1%%2%, V%3%.%4%[%5%0x%6$#x]") % r % rd % rn % T % ((index) < 0 ? "-" : "") % ((index) < 0 ? -(index) : (index))).str();
	}
	insn_320:
	/* UMULH */
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("umulh X%1%, X%2%, X%3%") % rd % rn % rm).str();
	}
	insn_321:
	/* USHL-vector */
	if((inst & 0xBF20FC00U) == 0x2E204400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_372) -> string { switch(temp_372) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("ushl V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str();
	}
	insn_322:
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
			goto insn_323;
		auto i2 = (string) ((Q != 0) ? (string("2")) : (string("")));
		if(((bool) (((immh) == (0x1)) ? 1U : 0U)) != 0) {
			Ta = string("8H");
			Tb = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
			size = 0x0;
			shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x8)));
		} else {
			if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xE))))) == (0x2)) ? 1U : 0U)) != 0) {
				Ta = string("4S");
				Tb = (string) ((Q != 0) ? (string("8H")) : (string("4H")));
				size = 0x1;
				shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x10)));
			} else {
				if(((bool) ((((uint8_t) ((((uint64_t) (immh)) & ((uint64_t) (0xC))))) == (0x4)) ? 1U : 0U)) != 0) {
					Ta = string("2D");
					Tb = (string) ((Q != 0) ? (string("4S")) : (string("2S")));
					size = 0x2;
					shift = (uint64_t) (((uint64_t) (uint32_t) ((uint32_t) ((uint32_t) ((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (immb)) << 0)) | ((uint8_t) (((uint8_t) (immh)) << 3)))))))) - ((uint64_t) (int64_t) (0x20)));
				} else {
					throw "Not implemented";
				}
			}
		}
		return (boost::format("ushll%1% V%2%.%3%, V%4%.%5%, #%6%0x%7$#x") % i2 % rd % Ta % rn % Tb % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str();
	}
	insn_323:
	/* XTN */
	if((inst & 0xFF3FFC00U) == 0x0E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_374) -> string { switch(temp_374) { case 0x0: return string("8B"); case 0x1: return string("4H"); case 0x2: return string("2S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_375) -> string { switch(temp_375) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		return (boost::format("xtn V%1%.%2%, V%3%.%4%") % rd % tb % rn % ta).str();
	}
	insn_324:
	/* XTN2 */
	if((inst & 0xFF3FFC00U) == 0x4E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_378) -> string { switch(temp_378) { case 0x0: return string("16B"); case 0x1: return string("8H"); case 0x2: return string("4S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_379) -> string { switch(temp_379) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		return (boost::format("xtn2 V%1%.%2%, V%3%.%4%") % rd % tb % rn % ta).str();
	}
	insn_325:
	/* YIELD */
	if((inst & 0xFFFFFFFFU) == 0xD503203FU) {
		return (boost::format("yield")).str();
	}
	insn_326:
	/* ZIP */
	if((inst & 0xBF20BC00U) == 0x0E003800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto op = (inst >> 14) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto i = (uint8_t) ((uint8_t) ((uint64_t) (((uint64_t) (bool) (op)) + ((uint64_t) (int64_t) (0x1)))));
		auto T = (string) (([=](auto temp_382) -> string { switch(temp_382) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((uint8_t) ((uint8_t) (((uint8_t) (((uint8_t) (Q)) << 0)) | ((uint8_t) (((uint8_t) (size)) << 1))))));
		return (boost::format("zip%1% V%2%.%3%, V%4%.%5%, V%6%.%7%") % (uint16_t) i % rd % T % rn % T % rm % T).str();
	}
	insn_327:

    return "";
}