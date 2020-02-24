#include <string>
#include <cstdint>
#include <boost/format.hpp>
#include "common.h"
using std::string;
typedef uint64_t ulong;
typedef uint32_t uint;
typedef uint16_t ushort;
typedef uint8_t byte;

const int instructionClassCount = 214+0;

const char* getInstructionClass(uint inst) {
	if((inst & 0x7FE0FC00U) == 0x3A000000U)
		return "ADCS";
	if((inst & 0x7FE00000U) == 0x0B200000U)
		return "ADD-extended-register";
	if((inst & 0x7F800000U) == 0x11000000U)
		return "ADD-immediate";
	if((inst & 0x7F200000U) == 0x0B000000U)
		return "ADD-shifted-register";
	if((inst & 0xBF20FC00U) == 0x0E208400U)
		return "ADD-vector";
	if((inst & 0x7F800000U) == 0x31000000U)
		return "ADDS-immediate";
	if((inst & 0x7F200000U) == 0x2B000000U)
		return "ADDS-shifted-register";
	if((inst & 0x9F000000U) == 0x90000000U)
		return "ADRP";
	if((inst & 0x7F800000U) == 0x12000000U)
		return "AND-immediate";
	if((inst & 0x7F200000U) == 0x0A000000U)
		return "AND-shifted-register";
	if((inst & 0x7F200000U) == 0x6A000000U)
		return "ANDS-shifted-register";
	if((inst & 0x7F800000U) == 0x72000000U)
		return "ANDS-immediate";
	if((inst & 0x7FE0FC00U) == 0x1AC02800U)
		return "ASRV";
	if((inst & 0xFC000000U) == 0x14000000U)
		return "B";
	if((inst & 0xFF000010U) == 0x54000000U)
		return "B.cond";
	if((inst & 0x7F800000U) == 0x33000000U)
		return "BFM";
	if((inst & 0x7F200000U) == 0x0A200000U)
		return "BIC";
	if((inst & 0xBFE0FC00U) == 0x0E601C00U)
		return "BIC-vector-register";
	if((inst & 0xFC000000U) == 0x94000000U)
		return "BL";
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U)
		return "BLR";
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U)
		return "BR";
	if((inst & 0xBFE0FC00U) == 0x08207C00U)
		return "CASP";
	if((inst & 0xBFE0FC00U) == 0x08607C00U)
		return "CASPA";
	if((inst & 0xBFE0FC00U) == 0x0860FC00U)
		return "CASPAL";
	if((inst & 0xBFE0FC00U) == 0x0820FC00U)
		return "CASPL";
	if((inst & 0x7F000000U) == 0x35000000U)
		return "CBNZ";
	if((inst & 0x7F000000U) == 0x34000000U)
		return "CBZ";
	if((inst & 0x7FE00C10U) == 0x3A400800U)
		return "CCMN-immediate";
	if((inst & 0x7FE00C10U) == 0x7A400800U)
		return "CCMP-immediate";
	if((inst & 0x7FE00C10U) == 0x7A400000U)
		return "CCMP-register";
	if((inst & 0xFFFFF0FFU) == 0xD503305FU)
		return "CLREX";
	if((inst & 0x7FFFFC00U) == 0x5AC01000U)
		return "CLZ";
	if((inst & 0xBF3FFC00U) == 0x0E205800U)
		return "CNT";
	if((inst & 0x7FE00C00U) == 0x1A800000U)
		return "CSEL";
	if((inst & 0x7FE00C00U) == 0x1A800400U)
		return "CSINC";
	if((inst & 0x7FE00C00U) == 0x5A800000U)
		return "CSINV";
	if((inst & 0x7FE00C00U) == 0x5A800400U)
		return "CSNEG";
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU)
		return "DMB";
	if((inst & 0xFFFFF0FFU) == 0xD503309FU)
		return "DSB";
	if((inst & 0xBFE0FC00U) == 0x0E000C00U)
		return "DUP-general";
	if((inst & 0xFFE0FC00U) == 0x5E000400U)
		return "DUP-element-scalar";
	if((inst & 0x7F200000U) == 0x4A200000U)
		return "EON-shifted-register";
	if((inst & 0x7F800000U) == 0x52000000U)
		return "EOR-immediate";
	if((inst & 0x7F200000U) == 0x4A000000U)
		return "EOR-shifted-register";
	if((inst & 0xBFE08400U) == 0x2E000000U)
		return "EXT";
	if((inst & 0x7FA00000U) == 0x13800000U)
		return "EXTR";
	if((inst & 0xFF3FFC00U) == 0x1E20C000U)
		return "FABS-scalar";
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U)
		return "FABS-vector";
	if((inst & 0xFF20FC00U) == 0x1E202800U)
		return "FADD-scalar";
	if((inst & 0xBFA0FC00U) == 0x0E20D400U)
		return "FADD-vector";
	if((inst & 0xFFBFFC00U) == 0x7E30D800U)
		return "FADDP-scalar";
	if((inst & 0xBFA0FC00U) == 0x2E20D400U)
		return "FADDP-vector";
	if((inst & 0xFF200C10U) == 0x1E200400U)
		return "FCCMP";
	if((inst & 0x9F20F400U) == 0x0E20E400U)
		return "FCMxx-register-vector";
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U)
		return "FCMxx-zero-vector";
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U)
		return "FCMLT-zero-vector";
	if((inst & 0xFF20FC17U) == 0x1E202000U)
		return "FCMP";
	if((inst & 0xFF200C00U) == 0x1E200C00U)
		return "FCSEL";
	if((inst & 0xFF3E7C00U) == 0x1E224000U)
		return "FCVT";
	if((inst & 0x7F3F0000U) == 0x1E180000U)
		return "FCVTZS-scalar-fixedpoint";
	if((inst & 0x7F3FFC00U) == 0x1E380000U)
		return "FCVTZS-scalar-integer";
	if((inst & 0x7F3F0000U) == 0x1E190000U)
		return "FCVTZU-scalar-fixedpoint";
	if((inst & 0x7F3FFC00U) == 0x1E390000U)
		return "FCVTZU-scalar-integer";
	if((inst & 0xFF20FC00U) == 0x1E201800U)
		return "FDIV-scalar";
	if((inst & 0xFF20FC00U) == 0x1E204800U)
		return "FMAX-scalar";
	if((inst & 0xFF20FC00U) == 0x1E206800U)
		return "FMAXNM-scalar";
	if((inst & 0xFF20FC00U) == 0x1E205800U)
		return "FMIN-scalar";
	if((inst & 0xFF20FC00U) == 0x1E207800U)
		return "FMINNM-scalar";
	if((inst & 0xBF80F400U) == 0x0F801000U)
		return "FMLA-by-element-vector-spdp";
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U)
		return "FMLA-vector";
	if((inst & 0x7F36FC00U) == 0x1E260000U)
		return "FMOV-general";
	if((inst & 0xFF201FE0U) == 0x1E201000U)
		return "FMOV-scalar-immediate";
	if((inst & 0xBF80F400U) == 0x0F809000U)
		return "FMUL-by-element-vector-spdp";
	if((inst & 0xFF20FC00U) == 0x1E200800U)
		return "FMUL-scalar";
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U)
		return "FMUL-vector";
	if((inst & 0xFF3FFC00U) == 0x1E214000U)
		return "FNEG";
	if((inst & 0xFF20FC00U) == 0x1E208800U)
		return "FNMUL-scalar";
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U)
		return "FRSQRTE-vector";
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U)
		return "FRSQRTS-vector";
	if((inst & 0xFF3FFC00U) == 0x1E21C000U)
		return "FSQRT-scalar";
	if((inst & 0xFF20FC00U) == 0x1E203800U)
		return "FSUB-scalar";
	if((inst & 0xFFE0FC00U) == 0x4E001C00U)
		return "INS-general";
	if((inst & 0xFFE08400U) == 0x6E000400U)
		return "INS-vector";
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U)
		return "LDAR";
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U)
		return "LDARB";
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U)
		return "LDARH";
	if((inst & 0xBFFFFC00U) == 0x885FFC00U)
		return "LDAXB";
	if((inst & 0xFFFFFC00U) == 0x085FFC00U)
		return "LDAXRB";
	if((inst & 0xFFFFFC00U) == 0x485FFC00U)
		return "LDAXRH";
	if((inst & 0x7FC00000U) == 0x28C00000U)
		return "LDP-immediate-postindex";
	if((inst & 0x7FC00000U) == 0x29400000U)
		return "LDP-immediate-signed-offset";
	if((inst & 0x3FC00000U) == 0x2CC00000U)
		return "LDP-simd-postindex";
	if((inst & 0x3FC00000U) == 0x2D400000U)
		return "LDP-simd-signed-offset";
	if((inst & 0xFFC00000U) == 0x69400000U)
		return "LDPSW-immediate-signed-offset";
	if((inst & 0xBFE00C00U) == 0xB8400C00U)
		return "LDR-immediate-preindex";
	if((inst & 0xBFE00C00U) == 0xB8400400U)
		return "LDR-immediate-postindex";
	if((inst & 0xBFC00000U) == 0xB9400000U)
		return "LDR-immediate-unsigned-offset";
	if((inst & 0x3F600C00U) == 0x3C400400U)
		return "LDR-simd-immediate-postindex";
	if((inst & 0x3F600C00U) == 0x3C400C00U)
		return "LDR-simd-immediate-preindex";
	if((inst & 0x3F400000U) == 0x3D400000U)
		return "LDR-simd-immediate-unsigned-offset";
	if((inst & 0x3F600C00U) == 0x3C600800U)
		return "LDR-simd-register";
	if((inst & 0xBFE00C00U) == 0xB8600800U)
		return "LDR-register";
	if((inst & 0xFFE00C00U) == 0x38400400U)
		return "LDRB-immediate-postindex";
	if((inst & 0xFFE00C00U) == 0x38400C00U)
		return "LDRB-immediate-preindex";
	if((inst & 0xFFC00000U) == 0x39400000U)
		return "LDRB-immediate-unsigned-offset";
	if((inst & 0xFFE00C00U) == 0x38600800U)
		return "LDRB-register";
	if((inst & 0xFFE00C00U) == 0x78400400U)
		return "LDRH-immediate-postindex";
	if((inst & 0xFFE00C00U) == 0x78400C00U)
		return "LDRH-immediate-preindex";
	if((inst & 0xFFC00000U) == 0x79400000U)
		return "LDRH-immediate-unsigned-offset";
	if((inst & 0xFFE00C00U) == 0x78600800U)
		return "LDRH-register";
	if((inst & 0xFFA00C00U) == 0x38800400U)
		return "LDRSB-immediate-postindex";
	if((inst & 0xFFA00C00U) == 0x38800C00U)
		return "LDRSB-immediate-preindex";
	if((inst & 0xFF800000U) == 0x39800000U)
		return "LDRSB-immediate-unsigned-offset";
	if((inst & 0xFFA00C00U) == 0x38A00800U)
		return "LDRSB-register";
	if((inst & 0xFFA00C00U) == 0x78800400U)
		return "LDRSH-immediate-postindex";
	if((inst & 0xFFA00C00U) == 0x78800C00U)
		return "LDRSH-immediate-preindex";
	if((inst & 0xFF800000U) == 0x79800000U)
		return "LDRSH-immediate-unsigned-offset";
	if((inst & 0xFFA00C00U) == 0x78A00800U)
		return "LDRSH-register";
	if((inst & 0xFFE00C00U) == 0xB8800400U)
		return "LDRSW-immediate-postindex";
	if((inst & 0xFFE00C00U) == 0xB8800C00U)
		return "LDRSW-immediate-preindex";
	if((inst & 0xFFC00000U) == 0xB9800000U)
		return "LDRSW-immediate-unsigned-offset";
	if((inst & 0xFFE00C00U) == 0xB8A00800U)
		return "LDRSW-register";
	if((inst & 0xBFE00C00U) == 0xB8400000U)
		return "LDUR";
	if((inst & 0xFFE00C00U) == 0x38400000U)
		return "LDURB";
	if((inst & 0xFFE00C00U) == 0x78400000U)
		return "LDURH";
	if((inst & 0xFFA00C00U) == 0x38800000U)
		return "LDURSB";
	if((inst & 0xFFA00C00U) == 0x78800000U)
		return "LDURSH";
	if((inst & 0xFFE00C00U) == 0xB8800000U)
		return "LDURSW";
	if((inst & 0x3F600C00U) == 0x3C400000U)
		return "LDUR-simd";
	if((inst & 0xBFFFFC00U) == 0x885F7C00U)
		return "LDXR";
	if((inst & 0xFFFFFC00U) == 0x085F7C00U)
		return "LDXRB";
	if((inst & 0xFFFFFC00U) == 0x485F7C00U)
		return "LDXRH";
	if((inst & 0x7FE0FC00U) == 0x1AC02000U)
		return "LSL-register";
	if((inst & 0x7FE0FC00U) == 0x1AC02400U)
		return "LSRV";
	if((inst & 0x7FE08000U) == 0x1B000000U)
		return "MADD";
	if((inst & 0xBFF89C00U) == 0x0F000400U)
		return "MOVI-32bit";
	if((inst & 0xFFF8FC00U) == 0x6F00E400U)
		return "MOVI-Vx.2D";
	if((inst & 0x7F800000U) == 0x72800000U)
		return "MOVK";
	if((inst & 0x7F800000U) == 0x12800000U)
		return "MOVN";
	if((inst & 0x7F800000U) == 0x52800000U)
		return "MOVZ";
	if((inst & 0xFFF00000U) == 0xD5300000U)
		return "MRS";
	if((inst & 0xFFF00000U) == 0xD5100000U)
		return "MSR-register";
	if((inst & 0x7FE08000U) == 0x1B008000U)
		return "MSUB";
	if((inst & 0xBF00F400U) == 0x0F008000U)
		return "MUL-by-element";
	if((inst & 0xBF20FC00U) == 0x0E209C00U)
		return "MUL-vector";
	if((inst & 0x7F200000U) == 0x2A200000U)
		return "ORN-shifted-register";
	if((inst & 0x7F800000U) == 0x32000000U)
		return "ORR-immediate";
	if((inst & 0x7F200000U) == 0x2A000000U)
		return "ORR-shifted-register";
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U)
		return "ORR-simd-register";
	if((inst & 0xFFC00000U) == 0xF9800000U)
		return "PRFM-immediate";
	if((inst & 0x7FFFFC00U) == 0x5AC00000U)
		return "RBIT";
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U)
		return "RET";
	if((inst & 0x7FFFF800U) == 0x5AC00800U)
		return "REV";
	if((inst & 0x7FFFFC00U) == 0x5AC00400U)
		return "REV16";
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U)
		return "RORV";
	if((inst & 0x7FE0FC00U) == 0x7A000000U)
		return "SBCS";
	if((inst & 0x7F800000U) == 0x13000000U)
		return "SBFM";
	if((inst & 0x7F3FFC00U) == 0x1E220000U)
		return "SCVTF-scalar-integer";
	if((inst & 0xFFBFFC00U) == 0x5E21D800U)
		return "SCVTF-vector-integer";
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U)
		return "SDIV";
	if((inst & 0xFFE08000U) == 0x9B200000U)
		return "SMADDL";
	if((inst & 0xFFE0FC00U) == 0x9B407C00U)
		return "SMULH";
	if((inst & 0xBF80FC00U) == 0x0F00A400U)
		return "SSHLL";
	if((inst & 0xBFFFFC00U) == 0x889FFC00U)
		return "STLR";
	if((inst & 0xFFFFFC00U) == 0x089FFC00U)
		return "STLRB";
	if((inst & 0xFFFFFC00U) == 0x489FFC00U)
		return "STLRH";
	if((inst & 0xBFE0FC00U) == 0x8800FC00U)
		return "STLXR";
	if((inst & 0xFFE0FC00U) == 0x0800FC00U)
		return "STLXRB";
	if((inst & 0x7FC00000U) == 0x28800000U)
		return "STP-postindex";
	if((inst & 0x7FC00000U) == 0x29800000U)
		return "STP-preindex";
	if((inst & 0x7FC00000U) == 0x29000000U)
		return "STP-signed-offset";
	if((inst & 0x3FC00000U) == 0x2C800000U)
		return "STP-simd-postindex";
	if((inst & 0x3FC00000U) == 0x2D800000U)
		return "STP-simd-preindex";
	if((inst & 0x3FC00000U) == 0x2D000000U)
		return "STP-simd-signed-offset";
	if((inst & 0xBFE00C00U) == 0xB8000400U)
		return "STR-immediate-postindex";
	if((inst & 0xBFE00C00U) == 0xB8000C00U)
		return "STR-immediate-preindex";
	if((inst & 0xBFC00000U) == 0xB9000000U)
		return "STR-immediate-unsigned-offset";
	if((inst & 0xBFE00C00U) == 0xB8200800U)
		return "STR-register";
	if((inst & 0x3F600C00U) == 0x3C000400U)
		return "STR-simd-postindex";
	if((inst & 0x3F600C00U) == 0x3C000C00U)
		return "STR-simd-preindex";
	if((inst & 0x3F400000U) == 0x3D000000U)
		return "STR-simd-unsigned-offset";
	if((inst & 0x3F600C00U) == 0x3C200800U)
		return "STR-simd-register";
	if((inst & 0xFFE00C00U) == 0x38000400U)
		return "STRB-immediate-postindex";
	if((inst & 0xFFE00C00U) == 0x38000C00U)
		return "STRB-immediate-preindex";
	if((inst & 0xFFC00000U) == 0x39000000U)
		return "STRB-immediate-unsigned-offset";
	if((inst & 0xFFE00C00U) == 0x38200800U)
		return "STRB-register";
	if((inst & 0xFFE00C00U) == 0x78000400U)
		return "STRH-immediate-postindex";
	if((inst & 0xFFE00C00U) == 0x78000C00U)
		return "STRH-immediate-preindex";
	if((inst & 0xFFC00000U) == 0x79000000U)
		return "STRH-immediate-unsigned-offset";
	if((inst & 0xFFE00C00U) == 0x78200800U)
		return "STRH-register";
	if((inst & 0xBFE00C00U) == 0xB8000000U)
		return "STUR";
	if((inst & 0x3F600C00U) == 0x3C000000U)
		return "STUR-simd";
	if((inst & 0xFFE00C00U) == 0x38000000U)
		return "STURB";
	if((inst & 0xFFE00C00U) == 0x78000000U)
		return "STURH";
	if((inst & 0xBFE0FC00U) == 0x88007C00U)
		return "STXR";
	if((inst & 0x7F800000U) == 0x51000000U)
		return "SUB-immediate";
	if((inst & 0x7FE00000U) == 0x4B200000U)
		return "SUB-extended-register";
	if((inst & 0x7F200000U) == 0x4B000000U)
		return "SUB-shifted-register";
	if((inst & 0x7FE00000U) == 0x6B200000U)
		return "SUBS-extended-register";
	if((inst & 0x7F200000U) == 0x6B000000U)
		return "SUBS-shifted-register";
	if((inst & 0x7F800000U) == 0x71000000U)
		return "SUBS-immediate";
	if((inst & 0xFFE0001FU) == 0xD4000001U)
		return "SVC";
	if((inst & 0xFFF80000U) == 0xD5080000U)
		return "SYS";
	if((inst & 0x7F000000U) == 0x36000000U)
		return "TBZ";
	if((inst & 0x7F000000U) == 0x37000000U)
		return "TBNZ";
	if((inst & 0xBF3FFC00U) == 0x2E303800U)
		return "UADDLV";
	if((inst & 0x7F800000U) == 0x53000000U)
		return "UBFM";
	if((inst & 0x7F3FFC00U) == 0x1E230000U)
		return "UCVTF-scalar-integer";
	if((inst & 0xFFBFFC00U) == 0x7E21D800U)
		return "UCVTF-vector-integer";
	if((inst & 0x7FE0FC00U) == 0x1AC00800U)
		return "UDIV";
	if((inst & 0xFFE08000U) == 0x9BA00000U)
		return "UMADDL";
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U)
		return "UMULH";
	if((inst & 0xFF3FFC00U) == 0x0E212800U)
		return "XTN";
	if((inst & 0xFF3FFC00U) == 0x4E212800U)
		return "XTN2";

    return nullptr;
}

const char* disassemble(uint inst, ulong pc) {
	/* ADCS */
	if((inst & 0x7FE0FC00U) == 0x3A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("adcs %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
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
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_0) -> string { switch(temp_0) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_1) -> string { switch(temp_1) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("add %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str().c_str();
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
		return (boost::format("add %1%%2%, %3%%4%, #%5$#x, LSL #%6%%7$#x") % r % rd % r % rn % imm % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_2) -> string { switch(temp_2) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("add %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
	}
	/* ADD-vector */
	if((inst & 0xBF20FC00U) == 0x0E208400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_3) -> string { switch(temp_3) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); case 0x7: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("add V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str().c_str();
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
		return (boost::format("adds %1%%2%, %3%%4%, #%5$#x, LSL #%6%%7$#x") % r % rd % r % rn % imm % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_4) -> string { switch(temp_4) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("adds %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
	}
	/* ADRP */
	if((inst & 0x9F000000U) == 0x90000000U) {
		auto immlo = (inst >> 29) & 0x3U;
		auto immhi = (inst >> 5) & 0x7FFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>((ulong) ((ulong) (((ulong) (ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) (immlo)) << 12)))) | ((ulong) (((ulong) (immhi)) << 14)))), 33));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) ((ulong) (((ulong) (((ulong) ((ushort) ((ushort) (0x0)))) << 0)) | ((ulong) (((ulong) ((ulong) ((ulong) ((ulong) (((ulong) (pc)) >> (uint) (0xC)))))) << 12)))))) + ((ulong) (long) (imm)));
		return (boost::format("adrp X%1%, #%2$#x") % rd % addr).str().c_str();
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
		return (boost::format("and %1%%2%, %3%%4%, #%5$#x") % r % rd % r % rn % imm).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_5) -> string { switch(temp_5) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("and %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_6) -> string { switch(temp_6) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("ands %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
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
		return (boost::format("ands %1%%2%, %3%%4%, #%5$#x") % r % rd % r % rn % imm).str().c_str();
	}
	/* ASRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("asrv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* B */
	if((inst & 0xFC000000U) == 0x14000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28)))));
		return (boost::format("b #%1$#x") % addr).str().c_str();
	}
	/* B.cond */
	if((inst & 0xFF000010U) == 0x54000000U) {
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto cond = (inst >> 0) & 0xFU;
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 21)))));
		auto condstr = (string) (([=](auto temp_7) -> string { switch(temp_7) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("b.%1% #%2$#x") % condstr % addr).str().c_str();
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
		return (boost::format("bfm %1%%2%, %3%%4%, #%5%, #%6%") % r % rd % r % rn % immr % imms).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_8) -> string { switch(temp_8) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("bic %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
	}
	/* BIC-vector-register */
	if((inst & 0xBFE0FC00U) == 0x0E601C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((Q) == (0x1)) ? 1U : 0U) != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("bic V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str().c_str();
	}
	/* BL */
	if((inst & 0xFC000000U) == 0x94000000U) {
		auto imm = (inst >> 0) & 0x3FFFFFFU;
		auto offset = (long) (SignExt<long>((uint) (((uint) ((uint) (imm))) << (uint) (0x2)), 28));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) (offset)));
		return (boost::format("bl #%1$#x") % addr).str().c_str();
	}
	/* BLR */
	if((inst & 0xFFFFFC1FU) == 0xD63F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return (boost::format("blr X%1%") % rn).str().c_str();
	}
	/* BR */
	if((inst & 0xFFFFFC1FU) == 0xD61F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return (boost::format("br X%1%") % rn).str().c_str();
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
		return (boost::format("casp %1%%2%, %3%%4$#x, %5%%6%, %7%%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str().c_str();
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
		return (boost::format("caspa %1%%2%, %3%%4$#x, %5%%6%, %7%%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str().c_str();
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
		return (boost::format("caspal %1%%2%, %3%%4$#x, %5%%6%, %7%%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str().c_str();
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
		return (boost::format("caspl %1%%2%, %3%%4$#x, %5%%6%, %7%%8$#x, [X%9%]") % r % rs % r % rs2 % r % rt % r % rt2 % rn).str().c_str();
	}
	/* CBNZ */
	if((inst & 0x7F000000U) == 0x35000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		return (boost::format("cbnz %1%%2%, #%3$#x") % r % rs % addr).str().c_str();
	}
	/* CBZ */
	if((inst & 0x7F000000U) == 0x34000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 5) & 0x7FFFFU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto addr = (ulong) (((ulong) (ulong) ((ulong) (pc))) + ((ulong) (long) ((long) (SignExt<long>((uint) ((uint) ((uint) ((imm) << (uint) (0x2)))), 21)))));
		return (boost::format("cbz %1%%2%, #%3$#x") % r % rs % addr).str().c_str();
	}
	/* CCMN-immediate */
	if((inst & 0x7FE00C10U) == 0x3A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_9) -> string { switch(temp_9) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("ccmn %1%%2%, #%3%, #%4%, %5%") % r % rn % imm % nzcv % condstr).str().c_str();
	}
	/* CCMP-immediate */
	if((inst & 0x7FE00C10U) == 0x7A400800U) {
		auto size = (inst >> 31) & 0x1U;
		auto imm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_10) -> string { switch(temp_10) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("ccmp %1%%2%, #%3%, #%4%, %5%") % r % rn % imm % nzcv % condstr).str().c_str();
	}
	/* CCMP-register */
	if((inst & 0x7FE00C10U) == 0x7A400000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_11) -> string { switch(temp_11) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("ccmp %1%%2%, %3%%4%, #%5%, %6%") % r % rn % r % rm % nzcv % condstr).str().c_str();
	}
	/* CLREX */
	if((inst & 0xFFFFF0FFU) == 0xD503305FU) {
		auto crm = (inst >> 8) & 0xFU;
		return (boost::format("clrex")).str().c_str();
	}
	/* CLZ */
	if((inst & 0x7FFFFC00U) == 0x5AC01000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("clz %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* CNT */
	if((inst & 0xBF3FFC00U) == 0x0E205800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_12) -> string { switch(temp_12) { case 0x0: return string("8B"); case 0x1: return string("16B"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("cnt V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str().c_str();
	}
	/* CSEL */
	if((inst & 0x7FE00C00U) == 0x1A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_13) -> string { switch(temp_13) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csel %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str().c_str();
	}
	/* CSINC */
	if((inst & 0x7FE00C00U) == 0x1A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_14) -> string { switch(temp_14) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csinc %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str().c_str();
	}
	/* CSINV */
	if((inst & 0x7FE00C00U) == 0x5A800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_15) -> string { switch(temp_15) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csinv %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str().c_str();
	}
	/* CSNEG */
	if((inst & 0x7FE00C00U) == 0x5A800400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto condstr = (string) (([=](auto temp_16) -> string { switch(temp_16) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("csneg %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str().c_str();
	}
	/* DMB */
	if((inst & 0xFFFFF0FFU) == 0xD50330BFU) {
		auto m = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_17) -> string { switch(temp_17) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(m));
		return (boost::format("DMB %1%") % option).str().c_str();
	}
	/* DSB */
	if((inst & 0xFFFFF0FFU) == 0xD503309FU) {
		auto crm = (inst >> 8) & 0xFU;
		auto option = (string) (([=](auto temp_18) -> string { switch(temp_18) { case 0xF: return string("SY"); case 0xE: return string("ST"); case 0xD: return string("LD"); case 0xB: return string("ISH"); case 0xA: return string("ISHST"); case 0x9: return string("ISHLD"); case 0x7: return string("NSH"); case 0x6: return string("NSHST"); case 0x5: return string("NSHLD"); case 0x3: return string("OSH"); case 0x2: return string("OSHST"); default: return string("OSHLD"); } })(crm));
		return (boost::format("DSB %1%") % option).str().c_str();
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
		return (boost::format("dup V%1%.%2%, %3%%4%") % rd % T % r % rn).str().c_str();
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
		return (boost::format("dup %1%%2%, V%3%.%4%[%5$#x]") % r % rd % rn % r % index).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_19) -> string { switch(temp_19) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("eon %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
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
		return (boost::format("and %1%%2%, %3%%4%, #%5$#x") % r % rd % r % rn % imm).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_20) -> string { switch(temp_20) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("eor %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
	}
	/* EXT */
	if((inst & 0xBFE08400U) == 0x2E000000U) {
		auto Q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto index = (inst >> 11) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) ((Q != 0) ? (string("16B")) : (string("8B")));
		return (boost::format("ext V%1%.%2%, V%3%.%4%, V%5%.%6%, #%7%") % rd % ts % rn % ts % rm % ts % index).str().c_str();
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
		return (boost::format("extr %1%%2%, %3%%4%, %5%%6%, #%7%") % r % rd % r % rn % r % rm % lsb).str().c_str();
	}
	/* FABS-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E20C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_21) -> string { switch(temp_21) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fabs %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* FABS-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0F800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_22) -> string { switch(temp_22) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("fabs V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str().c_str();
	}
	/* FADD-scalar */
	if((inst & 0xFF20FC00U) == 0x1E202800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_23) -> string { switch(temp_23) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fadd %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FADD-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_24) -> string { switch(temp_24) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("fadd V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str().c_str();
	}
	/* FADDP-scalar */
	if((inst & 0xFFBFFC00U) == 0x7E30D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return (boost::format("faddp %1%%2%, V%3%.2%4%") % r % rd % rn % r).str().c_str();
	}
	/* FADDP-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20D400U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_25) -> string { switch(temp_25) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("faddp V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str().c_str();
	}
	/* FCCMP */
	if((inst & 0xFF200C10U) == 0x1E200400U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto nzcv = (inst >> 0) & 0xFU;
		auto r = (string) (([=](auto temp_26) -> string { switch(temp_26) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_27) -> string { switch(temp_27) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("fccmp %1%%2%, %3%%4%, #%5%, %6%") % r % rn % r % rm % nzcv % condstr).str().c_str();
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
		auto top = (string) (([=](auto temp_28) -> string { switch(temp_28) { case 0x0: return string("EQ"); case 0x2: return string("GE"); case 0x3: return string("GE"); case 0x6: return string("GT"); case 0x7: return string("GT"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (byte) (((byte) (((byte) (ac)) << 0)) | ((byte) (((byte) (U)) << 1)))) | ((byte) (((byte) (E)) << 2))))));
		auto t = (string) (([=](auto temp_29) -> string { switch(temp_29) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("FCM%1% V%2%.%3%, V%4%.%5%, V%6%.%7%") % top % rd % t % rn % t % rm % t).str().c_str();
	}
	/* FCMxx-zero-vector */
	if((inst & 0x9FBFEC00U) == 0x0EA0C800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto U = (inst >> 29) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto op = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto top = (string) (([=](auto temp_30) -> string { switch(temp_30) { case 0x0: return string("GT"); case 0x1: return string("GE"); case 0x2: return string("EQ"); default: return string("LE"); } })((byte) ((byte) (((byte) (((byte) (U)) << 0)) | ((byte) (((byte) (op)) << 1))))));
		auto t = (string) (([=](auto temp_31) -> string { switch(temp_31) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("FCM%1% V%2%.%3%, V%4%.%5%, #0.0") % top % rd % t % rn % t).str().c_str();
	}
	/* FCMLT-zero-vector */
	if((inst & 0xBFBFFC00U) == 0x0EA0E800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_32) -> string { switch(temp_32) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("FCMLT V%1%.%2%, V%3%.%4%, #0.0") % rd % t % rn % t).str().c_str();
	}
	/* FCMP */
	if((inst & 0xFF20FC17U) == 0x1E202000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto opc = (inst >> 3) & 0x1U;
		auto r = (string) (([=](auto temp_33) -> string { switch(temp_33) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto zero = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("/0")) : (string("")));
		return (boost::format("fcmp %1%%2%, %3%%4% %5%") % r % rn % r % rm % zero).str().c_str();
	}
	/* FCSEL */
	if((inst & 0xFF200C00U) == 0x1E200C00U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto cond = (inst >> 12) & 0xFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_34) -> string { switch(temp_34) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto condstr = (string) (([=](auto temp_35) -> string { switch(temp_35) { case 0x0: return string("EQ"); case 0x1: return string("NE"); case 0x2: return string("CS"); case 0x3: return string("CC"); case 0x4: return string("MI"); case 0x5: return string("PL"); case 0x6: return string("VS"); case 0x7: return string("VC"); case 0x8: return string("HI"); case 0x9: return string("LS"); case 0xA: return string("GE"); case 0xB: return string("LT"); case 0xC: return string("GT"); case 0xD: return string("LE"); default: return string("AL"); } })(cond));
		return (boost::format("fcsel %1%%2%, %3%%4%, %5%%6%, %7%") % r % rd % r % rn % r % rm % condstr).str().c_str();
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
		return (boost::format("fcvt %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str().c_str();
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
		auto r2 = (string) (([=](auto temp_36) -> string { switch(temp_36) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fcvtzs %1%%2%, %3%%4%, #%5$#x") % r1 % rd % r2 % rn % fbits).str().c_str();
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
		return (boost::format("fcvtzs %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str().c_str();
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
		auto r2 = (string) (([=](auto temp_37) -> string { switch(temp_37) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fcvtzu %1%%2%, %3%%4%, #%5$#x") % r1 % rd % r2 % rn % fbits).str().c_str();
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
		return (boost::format("fcvtzu %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str().c_str();
	}
	/* FDIV-scalar */
	if((inst & 0xFF20FC00U) == 0x1E201800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_38) -> string { switch(temp_38) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fdiv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FMAX-scalar */
	if((inst & 0xFF20FC00U) == 0x1E204800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_39) -> string { switch(temp_39) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmax %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FMAXNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E206800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_40) -> string { switch(temp_40) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmaxnm %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FMIN-scalar */
	if((inst & 0xFF20FC00U) == 0x1E205800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_41) -> string { switch(temp_41) { case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmin %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FMINNM-scalar */
	if((inst & 0xFF20FC00U) == 0x1E207800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_42) -> string { switch(temp_42) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fminnm %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
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
		auto T = (string) (([=](auto temp_43) -> string { switch(temp_43) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_44) -> uint { switch(temp_44) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		return (boost::format("fmla V%1%.%2%, V%3%.%4%, V%5%.%6%[%7$#x]") % rd % T % rn % T % rm % Ts % index).str().c_str();
	}
	/* FMLA-vector */
	if((inst & 0xBFA0FC00U) == 0x0E20CC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto sz = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto T = (string) (([=](auto temp_45) -> string { switch(temp_45) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		return (boost::format("fmla V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % T % rn % T % rm % T).str().c_str();
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
		return (boost::format("fmov %1%%2%%3%, %4%%5%%6%") % r1 % rd % index1 % r2 % rn % index2).str().c_str();
	}
	/* FMOV-scalar-immediate */
	if((inst & 0xFF201FE0U) == 0x1E201000U) {
		auto type = (inst >> 22) & 0x3U;
		auto imm = (inst >> 13) & 0xFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_46) -> string { switch(temp_46) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		auto sv = (float) (Bitcast<uint, float>((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((uint) ((uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (uint) (((uint) (((uint) ((bool) ((bool) (0x0)))) << 0)) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 1)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 2)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 3)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 4)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 5)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 6)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 7)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 8)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 9)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 10)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 11)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 12)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 13)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 14)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 15)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 16)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 17)))) | ((uint) (((uint) ((bool) ((bool) (0x0)))) << 18)))))) << 0)) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) (imm)) & ((ulong) (0xF)))))))) << 19)))) | ((uint) (((uint) ((byte) ((byte) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x4)))) & ((ulong) (0x3)))))))) << 23)))) | ((uint) (((uint) ((byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 0)) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 1)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 2)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 3)))) | ((byte) (((byte) ((bool) ((bool) ((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1)))))))) << 4)))))) << 25)))) | ((uint) (((uint) ((bool) (((byte) ((((ulong) ((byte) ((imm) >> (uint) (0x6)))) & ((ulong) (0x1))))) != 0 ? 0U : 1U))) << 30)))) | ((uint) (((uint) ((bool) ((bool) ((byte) ((imm) >> (uint) (0x7)))))) << 31))))));
		return (boost::format("fmov %1%%2%, #%3%") % r % rd % sv).str().c_str();
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
		auto T = (string) (([=](auto temp_47) -> string { switch(temp_47) { case 0x0: return string("2S"); case 0x2: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (sz)) << 0)) | ((byte) (((byte) (Q)) << 1))))));
		auto Ts = (string) ((sz != 0) ? (string("D")) : (string("S")));
		auto index = (uint) (([=](auto temp_48) -> uint { switch(temp_48) { case 0x2: return (uint) ((uint) (H)); case 0x3: throw "Not implemented"; default: return (uint) ((uint) ((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))))); } })((byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (sz)) << 1))))));
		return (boost::format("fmul V%1%.%2%, V%3%.%4%, V%5%.%6%[%7$#x]") % rd % T % rn % T % rm % Ts % index).str().c_str();
	}
	/* FMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E200800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_49) -> string { switch(temp_49) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fmul %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FMUL-vector */
	if((inst & 0xBFA0FC00U) == 0x2E20DC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto ts = (string) (([=](auto temp_50) -> string { switch(temp_50) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("fmul V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % ts % rn % ts % rm % ts).str().c_str();
	}
	/* FNEG */
	if((inst & 0xFF3FFC00U) == 0x1E214000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_51) -> string { switch(temp_51) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fneg %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* FNMUL-scalar */
	if((inst & 0xFF20FC00U) == 0x1E208800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_52) -> string { switch(temp_52) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fnmul %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* FRSQRTE-vector */
	if((inst & 0xBFBFFC00U) == 0x2EA1D800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_53) -> string { switch(temp_53) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("frsqrte V%1%.%2%, V%3%.%4%") % rd % t % rn % t).str().c_str();
	}
	/* FRSQRTS-vector */
	if((inst & 0xBFA0FC00U) == 0x0EA0FC00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_54) -> string { switch(temp_54) { case 0x0: return string("2S"); case 0x1: return string("4S"); case 0x3: return string("2D"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("frsqrts V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str().c_str();
	}
	/* FSQRT-scalar */
	if((inst & 0xFF3FFC00U) == 0x1E21C000U) {
		auto type = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_55) -> string { switch(temp_55) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fsqrt %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* FSUB-scalar */
	if((inst & 0xFF20FC00U) == 0x1E203800U) {
		auto type = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_56) -> string { switch(temp_56) { case 0x3: return string("H"); case 0x0: return string("S"); case 0x1: return string("D"); default: throw "Not implemented"; } })(type));
		return (boost::format("fsub %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
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
		return (boost::format("ins V%1%.%2%[%3$#x], %4%%5%") % rd % ts % index % r % rn).str().c_str();
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
		return (boost::format("ins V%1%.%2%[%3$#x], V%4%.%5%[%6$#x]") % rd % ts % index1 % rn % ts % index2).str().c_str();
	}
	/* LDAR */
	if((inst & 0xBFFFFC00U) == 0x88DFFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldar %1%%2%, [X%3%]") % r % rt % rn).str().c_str();
	}
	/* LDARB */
	if((inst & 0xFFFFFC00U) == 0x08DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldarb W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* LDARH */
	if((inst & 0xFFFFFC00U) == 0x48DFFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldarh W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* LDAXB */
	if((inst & 0xBFFFFC00U) == 0x885FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldaxb W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* LDAXRB */
	if((inst & 0xFFFFFC00U) == 0x085FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldaxrb W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* LDAXRH */
	if((inst & 0xFFFFFC00U) == 0x485FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldaxrh W%1%, [X%2%]") % rt % rn).str().c_str();
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
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%], #%6%%7$#x") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
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
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%, #%6%%7$#x]") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* LDP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2CC00000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_57) -> string { switch(temp_57) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_58) -> long { switch(temp_58) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%], #%6%%7$#x") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* LDP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D400000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_59) -> string { switch(temp_59) { case 0x0: return string("S"); case 0x1: return string("D"); default: return string("Q"); } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_60) -> long { switch(temp_60) { case 0x0: return 0x2; case 0x1: return 0x3; default: return 0x4; } })(opc))));
		return (boost::format("ldp %1%%2%, %3%%4%, [X%5%, #%6%%7$#x]") % r % rt1 % r % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* LDPSW-immediate-signed-offset */
	if((inst & 0xFFC00000U) == 0x69400000U) {
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) (0x2));
		return (boost::format("ldpsw X%1%, X%2%, [X%3%, #%4%%5$#x]") % rt1 % rt2 % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* LDR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8400C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldr %1%%2%, [X%3%, #%4%%5$#x]!") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8400400U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldr %1%%2%, [X%3%], #%4%%5$#x") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("ldr %1%%2%, [X%3%, #%4$#x]") % r % rd % rn % imm).str().c_str();
	}
	/* LDR-simd-immediate-postindex */
	if((inst & 0x3F600C00U) == 0x3C400400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_61) -> string { switch(temp_61) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("ldr %1%%2%, [X%3%], #%4%%5$#x") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* LDR-simd-immediate-preindex */
	if((inst & 0x3F600C00U) == 0x3C400C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		auto r = (string) (([=](auto temp_62) -> string { switch(temp_62) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("ldr %1%%2%, [X%3%, #%4%%5$#x]!") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
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
		auto r = (string) (([=](auto temp_63) -> string { switch(temp_63) { case 0x1: return string("B"); case 0x5: return string("H"); case 0x9: return string("S"); case 0xD: return string("D"); default: return string("Q"); } })(m));
		auto imm = (uint) (((uint) ((uint) (rawimm))) << (uint) ((long) (([=](auto temp_64) -> long { switch(temp_64) { case 0x1: return 0x0; case 0x5: return 0x1; case 0x9: return 0x2; case 0xD: return 0x3; default: return 0x4; } })(m))));
		return (boost::format("ldr %1%%2%, [X%3%, #%4$#x]") % r % rt % rn % imm).str().c_str();
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
		auto r1 = (string) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (string("Q")) : ((string) (([=](auto temp_65) -> string { switch(temp_65) { case 0x0: return string("B"); case 0x1: return string("H"); case 0x2: return string("S"); case 0x3: return string("D"); default: throw "Not implemented"; } })(size))));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto extend = (string) (([=](auto temp_66) -> string { switch(temp_66) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		auto amount = (ulong) (((ulong) (bool) (scale)) * ((ulong) (long) ((long) (((bool) ((((bool) ((bool) (((size) == (0x0)) ? 1U : 0U))) & ((bool) ((bool) (((opc) == (0x1)) ? 1U : 0U))))) != 0) ? (0x4) : ((long) (([=](auto temp_67) -> long { switch(temp_67) { case 0x0: return 0x1; case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: throw "Not implemented"; } })(size)))))));
		return (boost::format("ldr %1%%2%, [X%3%, %4%%5%, %6% %7$#x]") % r1 % rt % rn % r2 % rm % extend % amount).str().c_str();
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
		auto extend = (string) (([=](auto temp_68) -> string { switch(temp_68) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("ldr %1%%2%, [X%3%, %4%%5%, %6% %7%%8$#x]") % r1 % rt % rn % r2 % rm % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str().c_str();
	}
	/* LDRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldrb W%1%, [X%2%], #%3%%4$#x") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldrb W%1%, [X%2%, #%3%%4$#x]!") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39400000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldrb W%1%, [X%2%, #%3$#x]") % rt % rn % imm).str().c_str();
	}
	/* LDRB-register */
	if((inst & 0xFFE00C00U) == 0x38600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_69) -> string { switch(temp_69) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrb W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str().c_str();
	}
	/* LDRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78400400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldrh W%1%, [X%2%], #%3%%4$#x") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78400C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldrh W%1%, [X%2%, #%3%%4$#x]!") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79400000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		return (boost::format("ldrh W%1%, [X%2%, #%3$#x]") % rt % rn % imm).str().c_str();
	}
	/* LDRH-register */
	if((inst & 0xFFE00C00U) == 0x78600800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_70) -> string { switch(temp_70) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrh W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str().c_str();
	}
	/* LDRSB-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x38800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsb %1%%2%, [X%3%], #%4%%5$#x") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRSB-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x38800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsb %1%%2%, [X%3%, #%4%%5$#x]!") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRSB-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x39800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsb %1%%2%, [X%3%, #%4$#x]") % r % rt % rn % imm).str().c_str();
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
		auto str = (string) (([=](auto temp_71) -> string { switch(temp_71) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrsb %1%%2%, [X%3%, %4%%5%, %6% %7%]") % r % rt % rn % r % rm % str % amount).str().c_str();
	}
	/* LDRSH-immediate-postindex */
	if((inst & 0xFFA00C00U) == 0x78800400U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsh %1%%2%, [X%3%], #%4%%5$#x") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRSH-immediate-preindex */
	if((inst & 0xFFA00C00U) == 0x78800C00U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldrsh %1%%2%, [X%3%, #%4%%5$#x]!") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRSH-immediate-unsigned-offset */
	if((inst & 0xFF800000U) == 0x79800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		return (boost::format("ldrsh %1%%2%, [X%3%, #%4$#x]") % r % rt % rn % imm).str().c_str();
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
		auto str = (string) (([=](auto temp_72) -> string { switch(temp_72) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("ldrsh %1%%2%, [X%3%, %4%%5%, %6% %7%]") % r % rt % rn % r % rm % str % amount).str().c_str();
	}
	/* LDRSW-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0xB8800400U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldrsw X%1%, [X%2%], #%3%%4$#x") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRSW-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0xB8800C00U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldrsw X%1%, [X%2%, #%3%%4$#x]!") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDRSW-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0xB9800000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x2));
		return (boost::format("ldrsw X%1%, [X%2%, #%3$#x]") % rt % rn % imm).str().c_str();
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
		auto extend = (string) (([=](auto temp_73) -> string { switch(temp_73) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("ldrsw X%1%, [X%2%, %3%%4%, %5% %6%%7$#x]") % rt % rn % r % rm % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str().c_str();
	}
	/* LDUR */
	if((inst & 0xBFE00C00U) == 0xB8400000U) {
		auto size = (inst >> 30) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldur %1%%2%, [X%3%, #%4%%5$#x]") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDURB */
	if((inst & 0xFFE00C00U) == 0x38400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldurb W%1%, [X%2%, #%3%%4$#x]") % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDURH */
	if((inst & 0xFFE00C00U) == 0x78400000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldurh W%1%, [X%2%, #%3%%4$#x]") % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDURSB */
	if((inst & 0xFFA00C00U) == 0x38800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldursb %1%%2%, [X%3%, #%4%%5$#x]") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDURSH */
	if((inst & 0xFFA00C00U) == 0x78800000U) {
		auto opc = (inst >> 22) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldursh %1%%2%, [X%3%, #%4%%5$#x]") % r % rd % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDURSW */
	if((inst & 0xFFE00C00U) == 0xB8800000U) {
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldursw X%1%, [X%2%, #%3%%4$#x]") % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDUR-simd */
	if((inst & 0x3F600C00U) == 0x3C400000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto rawimm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_74) -> string { switch(temp_74) { case 0x0: return string("B"); case 0x2: return string("H"); case 0x4: return string("S"); case 0x6: return string("D"); case 0x1: return string("Q"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (opc)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto imm = (long) (SignExt<long>(rawimm, 9));
		return (boost::format("ldur %1%%2%, [X%3%, #%4%%5$#x]") % r % rt % rn % ((imm) < 0 ? "-" : "") % ((imm) < 0 ? -(imm) : (imm))).str().c_str();
	}
	/* LDXR */
	if((inst & 0xBFFFFC00U) == 0x885F7C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("ldxr %1%%2%, [X%3%]") % r % rt % rn).str().c_str();
	}
	/* LDXRB */
	if((inst & 0xFFFFFC00U) == 0x085F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldxrb W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* LDXRH */
	if((inst & 0xFFFFFC00U) == 0x485F7C00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("ldxrh W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* LSL-register */
	if((inst & 0x7FE0FC00U) == 0x1AC02000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("lsl %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* LSRV */
	if((inst & 0x7FE0FC00U) == 0x1AC02400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("lsrv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* MADD */
	if((inst & 0x7FE08000U) == 0x1B000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("madd %1%%2%, %3%%4%, %5%%6%, %7%%8%") % r % rd % r % rn % r % rm % r % ra).str().c_str();
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
		auto amount = (long) (([=](auto temp_75) -> long { switch(temp_75) { case 0x0: return 0x0; case 0x1: return 0x8; case 0x2: return 0x10; case 0x3: return 0x18; default: throw "Not implemented"; } })(cmode));
		auto imm = (byte) ((byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (byte) (((byte) (((byte) (h)) << 0)) | ((byte) (((byte) (g)) << 1)))) | ((byte) (((byte) (f)) << 2)))) | ((byte) (((byte) (e)) << 3)))) | ((byte) (((byte) (d)) << 4)))) | ((byte) (((byte) (c)) << 5)))) | ((byte) (((byte) (b)) << 6)))) | ((byte) (((byte) (a)) << 7))));
		return (boost::format("movi V%1%.%2%, #%3%, LSL #%4%%5$#x") % rd % t % imm % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str().c_str();
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
		return (boost::format("movi V%1%, #%2$#x") % rd % imm).str().c_str();
	}
	/* MOVK */
	if((inst & 0x7F800000U) == 0x72800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		return (boost::format("movk %1%%2%, #%3$#x, LSL #%4%") % r % rd % imm % shift).str().c_str();
	}
	/* MOVN */
	if((inst & 0x7F800000U) == 0x12800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		return (boost::format("movn %1%%2%, #%3$#x, LSL #%4%") % r % rd % imm % shift).str().c_str();
	}
	/* MOVZ */
	if((inst & 0x7F800000U) == 0x52800000U) {
		auto size = (inst >> 31) & 0x1U;
		auto hw = (inst >> 21) & 0x3U;
		auto imm = (inst >> 5) & 0xFFFFU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shift = (byte) ((hw) << (uint) (0x4));
		return (boost::format("movz %1%%2%, #%3$#x, LSL #%4%") % r % rd % imm % shift).str().c_str();
	}
	/* MRS */
	if((inst & 0xFFF00000U) == 0xD5300000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("mrs S%1% %2% %3% %4% %5%, X%6%") % op0 % op1 % cn % cm % op2 % rt).str().c_str();
	}
	/* MSR-register */
	if((inst & 0xFFF00000U) == 0xD5100000U) {
		auto op0 = (inst >> 19) & 0x1U;
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("msr S%1% %2% %3% %4% %5%, X%6%") % op0 % op1 % cn % cm % op2 % rt).str().c_str();
	}
	/* MSUB */
	if((inst & 0x7FE08000U) == 0x1B008000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("msub %1%%2%, %3%%4%, %5%%6%, %7%%8%") % r % rd % r % rn % r % rm % r % ra).str().c_str();
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
		auto t = (string) (([=](auto temp_76) -> string { switch(temp_76) { case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto ts = (string) (([=](auto temp_77) -> string { switch(temp_77) { case 0x1: return string("H"); case 0x2: return string("S"); default: throw "Not implemented"; } })(size));
		auto index = (byte) (([=](auto temp_78) -> byte { switch(temp_78) { case 0x1: return (byte) ((byte) (((byte) (byte) (((byte) (((byte) (M)) << 0)) | ((byte) (((byte) (L)) << 1)))) | ((byte) (((byte) (H)) << 2)))); case 0x2: return (byte) ((byte) (((byte) (((byte) (L)) << 0)) | ((byte) (((byte) (H)) << 1)))); default: throw "Not implemented"; } })(size));
		return (boost::format("mul V%1%.%2%, V%3%.%4%, V%5%.%6%[%7%]") % rd % t % rn % t % rm % ts % index).str().c_str();
	}
	/* MUL-vector */
	if((inst & 0xBF20FC00U) == 0x0E209C00U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (([=](auto temp_79) -> string { switch(temp_79) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x4: return string("2S"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		return (boost::format("mul V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_80) -> string { switch(temp_80) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("orn %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
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
		return (boost::format("orr %1%%2%, %3%%4%, #%5$#x") % r % rd % r % rn % imm).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_81) -> string { switch(temp_81) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("orr %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
	}
	/* ORR-simd-register */
	if((inst & 0xBFE0FC00U) == 0x0EA01C00U) {
		auto q = (inst >> 30) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto t = (string) (((bool) (((q) == (0x0)) ? 1U : 0U) != 0) ? (string("8B")) : (string("16B")));
		return (boost::format("orr V%1%.%2%, V%3%.%4%, V%5%.%6%") % rd % t % rn % t % rm % t).str().c_str();
	}
	/* PRFM-immediate */
	if((inst & 0xFFC00000U) == 0xF9800000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto imm5 = (inst >> 0) & 0x1FU;
		auto pimm = (ulong) (((ulong) (ushort) (imm)) * ((ulong) (long) (0x8)));
		return (boost::format("prfm #%1%, [X%2%, #%3$#x]") % imm5 % rn % pimm).str().c_str();
	}
	/* RBIT */
	if((inst & 0x7FFFFC00U) == 0x5AC00000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rbit %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* RET */
	if((inst & 0xFFFFFC1FU) == 0xD65F0000U) {
		auto rn = (inst >> 5) & 0x1FU;
		return (boost::format("ret X%1%") % rn).str().c_str();
	}
	/* REV */
	if((inst & 0x7FFFF800U) == 0x5AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto opc = (inst >> 10) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rev %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* REV16 */
	if((inst & 0x7FFFFC00U) == 0x5AC00400U) {
		auto size = (inst >> 31) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rev16 %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* RORV */
	if((inst & 0x7FE0FC00U) == 0x1AC02C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("rorv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* SBCS */
	if((inst & 0x7FE0FC00U) == 0x7A000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("sbcs %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
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
		return (boost::format("sbfm %1%%2%, %3%%4%, #%5%, #%6%") % r % rd % r % rn % immr % imms).str().c_str();
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
		return (boost::format("scvtf %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str().c_str();
	}
	/* SCVTF-vector-integer */
	if((inst & 0xFFBFFC00U) == 0x5E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return (boost::format("scvtf %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* SDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00C00U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("sdiv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* SMADDL */
	if((inst & 0xFFE08000U) == 0x9B200000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("smaddl X%1%, W%2%, W%3%, X%4%") % rd % rn % rm % ra).str().c_str();
	}
	/* SMULH */
	if((inst & 0xFFE0FC00U) == 0x9B407C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("smulh X%1%, X%2%, X%3%") % rd % rn % rm).str().c_str();
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
		return (boost::format("sshll%1% V%2%.%3%, V%4%.%5%, #%6$#x") % variant % rd % ta % rn % tb % shift).str().c_str();
	}
	/* STLR */
	if((inst & 0xBFFFFC00U) == 0x889FFC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stlr %1%%2%, [X%3%]") % r % rt % rn).str().c_str();
	}
	/* STLRB */
	if((inst & 0xFFFFFC00U) == 0x089FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stlrb W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* STLRH */
	if((inst & 0xFFFFFC00U) == 0x489FFC00U) {
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stlrh W%1%, [X%2%]") % rt % rn).str().c_str();
	}
	/* STLXR */
	if((inst & 0xBFE0FC00U) == 0x8800FC00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stlxr W%1%, %2%%3%, [X%4%]") % rs % r % rt % rn).str().c_str();
	}
	/* STLXRB */
	if((inst & 0xFFE0FC00U) == 0x0800FC00U) {
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("stlxrr W%1%, W%2%, [X%3%]") % rs % rt % rn).str().c_str();
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
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%], #%6%%7$#x") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
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
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%%7$#x]!") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
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
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%%7$#x]") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STP-simd-postindex */
	if((inst & 0x3FC00000U) == 0x2C800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_82) -> string { switch(temp_82) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_83) -> long { switch(temp_83) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%], #%6%%7$#x") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STP-simd-preindex */
	if((inst & 0x3FC00000U) == 0x2D800000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_84) -> string { switch(temp_84) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_85) -> long { switch(temp_85) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%%7$#x]!") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STP-simd-signed-offset */
	if((inst & 0x3FC00000U) == 0x2D000000U) {
		auto opc = (inst >> 30) & 0x3U;
		auto imm = (inst >> 15) & 0x7FU;
		auto rt2 = (inst >> 10) & 0x1FU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rt1 = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_86) -> string { switch(temp_86) { case 0x0: return string("S"); case 0x1: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(opc));
		auto simm = (long) (((long) (SignExt<long>(imm, 7))) << (uint) ((long) (([=](auto temp_87) -> long { switch(temp_87) { case 0x0: return 0x2; case 0x1: return 0x3; case 0x2: return 0x4; default: throw "Not implemented"; } })(opc))));
		return (boost::format("stp %1%%2%, %3%%4%, [X%5%, #%6%%7$#x]") % r % rt1 % r % rt2 % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STR-immediate-postindex */
	if((inst & 0xBFE00C00U) == 0xB8000400U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%], #%4%%5$#x") % r % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STR-immediate-preindex */
	if((inst & 0xBFE00C00U) == 0xB8000C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%, #%4%%5$#x]!") % r % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STR-immediate-unsigned-offset */
	if((inst & 0xBFC00000U) == 0xB9000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto pimm = (ulong) (((ulong) ((ulong) (imm))) << (uint) ((long) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (0x2) : (0x3))));
		return (boost::format("str %1%%2%, [X%3%, #%4$#x]") % r % rs % rd % pimm).str().c_str();
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
		auto extend = (string) (([=](auto temp_88) -> string { switch(temp_88) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("str %1%%2%, [X%3%, %4%%5%, %6% %7%%8$#x]") % r1 % rt % rn % r2 % rm % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str().c_str();
	}
	/* STR-simd-postindex */
	if((inst & 0x3F600C00U) == 0x3C000400U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_89) -> string { switch(temp_89) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%], #%4%%5$#x") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STR-simd-preindex */
	if((inst & 0x3F600C00U) == 0x3C000C00U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_90) -> string { switch(temp_90) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("str %1%%2%, [X%3%, #%4%%5$#x]!") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STR-simd-unsigned-offset */
	if((inst & 0x3F400000U) == 0x3D000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_91) -> string { switch(temp_91) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto scale = (byte) ((byte) (((byte) (((byte) (size)) << 0)) | ((byte) (((byte) (opc)) << 2))));
		return (boost::format("str %1%%2%, [X%3%, #%4$#x]") % r % rt % rn % imm).str().c_str();
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
		auto r1 = (string) (([=](auto temp_92) -> string { switch(temp_92) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto r2 = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto amount = (long) (((bool) (((scale) == (0x0)) ? 1U : 0U) != 0) ? (0x0) : ((long) (([=](auto temp_93) -> long { switch(temp_93) { case 0x1: return 0x1; case 0x2: return 0x2; case 0x3: return 0x3; default: return (long) (((bool) (((opc) == (0x1)) ? 1U : 0U) != 0) ? (0x4) : (0x0)); } })(size))));
		auto extend = (string) (([=](auto temp_94) -> string { switch(temp_94) { case 0x2: return string("UXTW"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: return string("LSL"); } })(option));
		return (boost::format("str %1%%2%, [X%3%, %4%, %5% %6%%7$#x]") % r1 % rt % rn % r2 % extend % ((amount) < 0 ? "-" : "") % ((amount) < 0 ? -(amount) : (amount))).str().c_str();
	}
	/* STRB-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x38000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("strb W%1%, [X%2%], #%3%%4$#x") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STRB-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x38000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("strb W%1%, [X%2%, #%3%%4$#x]!") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STRB-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x39000000U) {
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("strb W%1%, [X%2%, #%3$#x]") % rt % rn % imm).str().c_str();
	}
	/* STRB-register */
	if((inst & 0xFFE00C00U) == 0x38200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_95) -> string { switch(temp_95) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("strb W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str().c_str();
	}
	/* STRH-immediate-postindex */
	if((inst & 0xFFE00C00U) == 0x78000400U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("strh W%1%, [X%2%], #%3%%4$#x") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STRH-immediate-preindex */
	if((inst & 0xFFE00C00U) == 0x78000C00U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rd = (inst >> 5) & 0x1FU;
		auto rs = (inst >> 0) & 0x1FU;
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("strh W%1%, [X%2%, #%3%%4$#x]!") % rs % rd % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STRH-immediate-unsigned-offset */
	if((inst & 0xFFC00000U) == 0x79000000U) {
		auto rawimm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto imm = (ushort) ((rawimm) << (uint) (0x1));
		return (boost::format("strh W%1%, [X%2%, #%3$#x]") % rt % rn % imm).str().c_str();
	}
	/* STRH-register */
	if((inst & 0xFFE00C00U) == 0x78200800U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto option = (inst >> 13) & 0x7U;
		auto amount = (inst >> 12) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((byte) ((((ulong) (option)) & ((ulong) (0x1)))) != 0) ? (string("X")) : (string("W")));
		auto str = (string) (([=](auto temp_96) -> string { switch(temp_96) { case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x6: return string("SXTW"); case 0x7: return string("SXTX"); default: throw "Not implemented"; } })(option));
		return (boost::format("strh W%1%, [X%2%, %3%%4%, %5% %6%]") % rt % rn % r % rm % str % amount).str().c_str();
	}
	/* STUR */
	if((inst & 0xBFE00C00U) == 0xB8000000U) {
		auto size = (inst >> 30) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto offset = (long) (SignExt<long>(imm, 9));
		return (boost::format("stur %1%%2%, [X%3%, #%4%%5$#x]") % r % rt % rn % ((offset) < 0 ? "-" : "") % ((offset) < 0 ? -(offset) : (offset))).str().c_str();
	}
	/* STUR-simd */
	if((inst & 0x3F600C00U) == 0x3C000000U) {
		auto size = (inst >> 30) & 0x3U;
		auto opc = (inst >> 23) & 0x1U;
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto rop = (byte) ((byte) (((byte) (byte) (((byte) (((byte) ((bool) ((bool) (0x0)))) << 0)) | ((byte) (((byte) (opc)) << 1)))) | ((byte) (((byte) (size)) << 2))));
		auto r = (string) (([=](auto temp_97) -> string { switch(temp_97) { case 0x0: return string("B"); case 0x4: return string("H"); case 0x8: return string("S"); case 0xC: return string("D"); case 0x2: return string("Q"); default: throw "Not implemented"; } })(rop));
		auto simm = (long) (SignExt<long>(imm, 9));
		return (boost::format("stur %1%%2%, [X%3%, #%4%%5$#x]") % r % rt % rn % ((simm) < 0 ? "-" : "") % ((simm) < 0 ? -(simm) : (simm))).str().c_str();
	}
	/* STURB */
	if((inst & 0xFFE00C00U) == 0x38000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		return (boost::format("sturb W%1%, [X%2%, #%3%%4$#x]") % rt % rn % ((offset) < 0 ? "-" : "") % ((offset) < 0 ? -(offset) : (offset))).str().c_str();
	}
	/* STURH */
	if((inst & 0xFFE00C00U) == 0x78000000U) {
		auto imm = (inst >> 12) & 0x1FFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto offset = (long) (SignExt<long>(imm, 9));
		return (boost::format("sturh W%1%, [X%2%, #%3%%4$#x]") % rt % rn % ((offset) < 0 ? "-" : "") % ((offset) < 0 ? -(offset) : (offset))).str().c_str();
	}
	/* STXR */
	if((inst & 0xBFE0FC00U) == 0x88007C00U) {
		auto size = (inst >> 30) & 0x1U;
		auto rs = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rt = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("stxr W%1%, %2%%3%, [X%4%]") % rs % r % rt % rn).str().c_str();
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
		return (boost::format("sub %1%%2%, %3%%4%, #%5$#x, LSL #%6%%7$#x") % r % rd % r % rn % imm % ((shift) < 0 ? "-" : "") % ((shift) < 0 ? -(shift) : (shift))).str().c_str();
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
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_98) -> string { switch(temp_98) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_99) -> string { switch(temp_99) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("sub %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_100) -> string { switch(temp_100) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("sub %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
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
		auto extend = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? ((string) (([=](auto temp_101) -> string { switch(temp_101) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("LSL"); case 0x3: return string("UXTX"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))) : ((string) (([=](auto temp_102) -> string { switch(temp_102) { case 0x0: return string("UXTB"); case 0x1: return string("UXTH"); case 0x2: return string("UXTW"); case 0x3: return string("LSL"); case 0x4: return string("SXTB"); case 0x5: return string("SXTH"); case 0x6: return string("SXTW"); default: return string("SXTX"); } })(option))));
		return (boost::format("subs %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r1 % rd % r1 % rn % r2 % rm % extend % imm).str().c_str();
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
		auto shiftstr = (string) (([=](auto temp_103) -> string { switch(temp_103) { case 0x0: return string("LSL"); case 0x1: return string("LSR"); case 0x2: return string("ASR"); default: return string("ROR"); } })(shift));
		return (boost::format("subs %1%%2%, %3%%4%, %5%%6%, %7% #%8%") % r % rd % r % rn % r % rm % shiftstr % imm).str().c_str();
	}
	/* SUBS-immediate */
	if((inst & 0x7F800000U) == 0x71000000U) {
		auto size = (inst >> 31) & 0x1U;
		auto shift = (inst >> 22) & 0x1U;
		auto imm = (inst >> 10) & 0xFFFU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		auto shiftstr = (string) (([=](auto temp_104) -> string { switch(temp_104) { case 0x0: return string("LSL #0"); case 0x1: return string("LSL #12"); default: throw "Not implemented"; } })(shift));
		return (boost::format("subs %1%%2%, %3%%4%, #%5$#x, %6%") % r % rd % r % rn % imm % shiftstr).str().c_str();
	}
	/* SVC */
	if((inst & 0xFFE0001FU) == 0xD4000001U) {
		auto imm = (inst >> 5) & 0xFFFFU;
		return (boost::format("svc #%1$#x") % imm).str().c_str();
	}
	/* SYS */
	if((inst & 0xFFF80000U) == 0xD5080000U) {
		auto op1 = (inst >> 16) & 0x7U;
		auto cn = (inst >> 12) & 0xFU;
		auto cm = (inst >> 8) & 0xFU;
		auto op2 = (inst >> 5) & 0x7U;
		auto rt = (inst >> 0) & 0x1FU;
		return (boost::format("sys #%1%, %2%, %3%, #%4%, X%5%") % op1 % cn % cm % op2 % rt).str().c_str();
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
		return (boost::format("tbz %1%%2%, #%3%, %4$#x") % r % rt % imm % addr).str().c_str();
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
		return (boost::format("tbnz %1%%2%, #%3%, %4$#x") % r % rt % imm % addr).str().c_str();
	}
	/* UADDLV */
	if((inst & 0xBF3FFC00U) == 0x2E303800U) {
		auto Q = (inst >> 30) & 0x1U;
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (([=](auto temp_105) -> string { switch(temp_105) { case 0x0: return string("H"); case 0x1: return string("S"); case 0x2: return string("D"); default: throw "Not implemented"; } })(size));
		auto t = (string) (([=](auto temp_106) -> string { switch(temp_106) { case 0x0: return string("8B"); case 0x1: return string("16B"); case 0x2: return string("4H"); case 0x3: return string("8H"); case 0x5: return string("4S"); default: throw "Not implemented"; } })((byte) ((byte) (((byte) (((byte) (Q)) << 0)) | ((byte) (((byte) (size)) << 1))))));
		auto esize = (long) ((0x8) << (uint) (size));
		auto count = (long) (((long) (long) ((long) ((Q != 0) ? (0x80) : (0x40)))) / ((long) (long) (esize)));
		return (boost::format("uaddlv %1%%2%, V%3%.%4%") % r % rd % rn % t).str().c_str();
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
		return (boost::format("ubfm %1%%2%, %3%%4%, #%5%, #%6%") % r % rd % r % rn % immr % imms).str().c_str();
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
		return (boost::format("ucvtf %1%%2%, %3%%4%") % r1 % rd % r2 % rn).str().c_str();
	}
	/* UCVTF-vector-integer */
	if((inst & 0xFFBFFC00U) == 0x7E21D800U) {
		auto size = (inst >> 22) & 0x1U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("S")) : (string("D")));
		return (boost::format("ucvtf %1%%2%, %3%%4%") % r % rd % r % rn).str().c_str();
	}
	/* UDIV */
	if((inst & 0x7FE0FC00U) == 0x1AC00800U) {
		auto size = (inst >> 31) & 0x1U;
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto r = (string) (((bool) (((size) == (0x0)) ? 1U : 0U) != 0) ? (string("W")) : (string("X")));
		return (boost::format("udiv %1%%2%, %3%%4%, %5%%6%") % r % rd % r % rn % r % rm).str().c_str();
	}
	/* UMADDL */
	if((inst & 0xFFE08000U) == 0x9BA00000U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto ra = (inst >> 10) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("umaddl X%1%, W%2%, W%3%, X%4%") % rd % rn % rm % ra).str().c_str();
	}
	/* UMULH */
	if((inst & 0xFFE0FC00U) == 0x9BC07C00U) {
		auto rm = (inst >> 16) & 0x1FU;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		return (boost::format("umulh X%1%, X%2%, X%3%") % rd % rn % rm).str().c_str();
	}
	/* XTN */
	if((inst & 0xFF3FFC00U) == 0x0E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_107) -> string { switch(temp_107) { case 0x0: return string("8B"); case 0x1: return string("4H"); case 0x2: return string("2S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_108) -> string { switch(temp_108) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		return (boost::format("xtn V%1%.%2%, V%3%.%4%") % rd % tb % rn % ta).str().c_str();
	}
	/* XTN2 */
	if((inst & 0xFF3FFC00U) == 0x4E212800U) {
		auto size = (inst >> 22) & 0x3U;
		auto rn = (inst >> 5) & 0x1FU;
		auto rd = (inst >> 0) & 0x1FU;
		auto tb = (string) (([=](auto temp_109) -> string { switch(temp_109) { case 0x0: return string("16B"); case 0x1: return string("8H"); case 0x2: return string("4S"); default: throw "Not implemented"; } })(size));
		auto ta = (string) (([=](auto temp_110) -> string { switch(temp_110) { case 0x0: return string("8H"); case 0x1: return string("4S"); case 0x2: return string("2D"); default: throw "Not implemented"; } })(size));
		return (boost::format("xtn2 V%1%.%2%, V%3%.%4%") % rd % tb % rn % ta).str().c_str();
	}

    return nullptr;
}