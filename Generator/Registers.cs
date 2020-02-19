using System;

namespace Generator {
	public class Registers : Builtin {
		public override void Define() {
			Expression("pc", _ => new EInt(false, 64), _ => "pc");
			
			Expression("gpr32", _ => new EInt(false, 32).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? 0U : (uint) State->X[(int) {GenerateExpression(list[1])}]",
				list => $"({GenerateExpression(list[1])}) == 31 ? 0U : (RuntimeValue<uint>) XR[(int) {GenerateExpression(list[1])}]");
			Expression("gpr-or-sp32", _ => new EInt(false, 32).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? State->SP : (State->X[(int) {GenerateExpression(list[1])}] & 0xFFFFFFFFUL)",
				list => $"({GenerateExpression(list[1])}) == 31 ? SPR : XR[(int) {GenerateExpression(list[1])}]");
			Expression("gpr64", _ => new EInt(false, 64).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? 0UL : State->X[(int) {GenerateExpression(list[1])}]",
				list => $"({GenerateExpression(list[1])}) == 31 ? 0UL : (RuntimeValue<ulong>) XR[(int) {GenerateExpression(list[1])}]");
			Expression("gpr-or-sp64", _ => new EInt(false, 64).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? State->SP : State->X[(int) {GenerateExpression(list[1])}]",
				list => $"({GenerateExpression(list[1])}) == 31 ? SPR : XR[(int) {GenerateExpression(list[1])}]");
			
			Expression("vec", _ => EType.Vector.AsRuntime(), 
				list => $"State->V[{GenerateExpression(list[1])}]", 
				list => $"VR[(int) ({GenerateExpression(list[1])})]");
			Expression("vec-b", _ => new EFloat(8).AsRuntime(),
				list => $"reinterpret_cast<vector128_byte>(State->V[{GenerateExpression(list[1])}])[0]",
				list => $"VBR[(int) ({GenerateExpression(list[1])})]");
			Expression("vec-h", _ => new EInt(false, 16).AsRuntime(),
				list => $"reinterpret_cast<vector128_ushort>(State->V[{GenerateExpression(list[1])}])[0]",
				list => $"VHR[(int) ({GenerateExpression(list[1])})]");
			Expression("vec-s", _ => new EFloat(32).AsRuntime(),
				list => $"State->V[{GenerateExpression(list[1])}][0]",
				list => $"VSR[(int) ({GenerateExpression(list[1])})]");
			Expression("vec-d", _ => new EFloat(64).AsRuntime(),
				list => $"reinterpret_cast<vector128_double>(State->V[{GenerateExpression(list[1])}])[0]",
				list => $"VDR[(int) ({GenerateExpression(list[1])})]");
			
			Expression("nzcv", list => new EInt(false, list.Count == 1 ? 32 : 1).AsRuntime(),
				list => {
					if(list.Count == 1) return "NZCV";
					switch(list[1]) {
						case PName("n"): return "State->NZCV_N";
						case PName("z"): return "State->NZCV_Z";
						case PName("c"): return "State->NZCV_C";
						case PName("v"): return "State->NZCV_V";
						default: throw new NotSupportedException($"Unknown field of NZCV: {list[1]}");
					}
				}, list => {
					if(list.Count == 1) return "NZCVR";
					switch(list[1]) {
						case PName("n"): return "NZCV_NR";
						case PName("z"): return "NZCV_ZR";
						case PName("c"): return "NZCV_CR";
						case PName("v"): return "NZCV_VR";
						default: throw new NotSupportedException($"Unknown field of NZCV: {list[1]}");
					}
				});
			
			Expression("sr", _ => new EInt(false, 64).AsRuntime(), 
				list => $"SR({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])}, {GenerateExpression(list[5])})", 
				list => $"CallSR({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])}, {GenerateExpression(list[5])})");
		}
	}
}