using System;

namespace Generator {
	public class Registers : Builtin {
		public override void Define() {
			Expression("pc", _ => new EInt(false, 64), _ => "pc").Interpret((_, state) => state.GetRegister("PC"));
			
			Expression("gpr32", _ => new EInt(false, 32).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? 0U : (uint) state->X[(int) {GenerateExpression(list[1])}]",
				list => $"({GenerateExpression(list[1])}) == 31 ? (RuntimeValue<uint>) 0U : (RuntimeValue<uint>) (XR[(int) {GenerateExpression(list[1])}]())")
				.Interpret((list, state) => {
					var reg = state.Evaluate(list[1]);
					if(reg == 31)
						return 0U;
					return (uint) state.GetRegister($"X{reg}");
				});
			Expression("gpr-or-sp32", _ => new EInt(false, 32).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? state->SP : (state->X[(int) {GenerateExpression(list[1])}] & 0xFFFFFFFFUL)",
				list => $"({GenerateExpression(list[1])}) == 31 ? SPR() : XR[(int) {GenerateExpression(list[1])}]()")
				.Interpret((list, state) => {
					var reg = state.Evaluate(list[1]);
					return (uint) state.GetRegister(reg == 31 ? "SP" : $"X{reg}");
				});
			Expression("gpr64", _ => new EInt(false, 64).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? 0UL : state->X[(int) {GenerateExpression(list[1])}]",
				list => $"({GenerateExpression(list[1])}) == 31 ? (RuntimeValue<ulong>) 0UL : XR[(int) {GenerateExpression(list[1])}]()")
				.Interpret((list, state) => {
					var reg = state.Evaluate(list[1]);
					if(reg == 31)
						return 0U;
					return (ulong) state.GetRegister($"X{reg}");
				});
			Expression("gpr-or-sp64", _ => new EInt(false, 64).AsRuntime(),
				list => $"({GenerateExpression(list[1])}) == 31 ? state->SP : state->X[(int) {GenerateExpression(list[1])}]",
				list => $"({GenerateExpression(list[1])}) == 31 ? SPR() : XR[(int) {GenerateExpression(list[1])}]()")
				.Interpret((list, state) => {
					var reg = state.Evaluate(list[1]);
					return (ulong) state.GetRegister(reg == 31 ? "SP" : $"X{reg}");
				});
			
			Expression("vec", _ => EType.Vector.AsRuntime(), 
				list => $"state->V[{GenerateExpression(list[1])}]", 
				list => $"VR[(int) ({GenerateExpression(list[1])})]")
				.Interpret((list, state) => state.GetRegister($"V{state.Evaluate(list[1])}"));
			Expression("vec-b", _ => new EFloat(8).AsRuntime(),
				list => $"reinterpret_cast<Vector128<byte>>(state->V[{GenerateExpression(list[1])}])[0]",
				list => $"VBR[(int) ({GenerateExpression(list[1])})]")
				.Interpret((list, state) => state.GetRegister($"V{state.Evaluate(list[1])}").As<byte>()[0]);
			Expression("vec-h", _ => new EInt(false, 16).AsRuntime(),
				list => $"reinterpret_cast<Vector128<ushort>>(state->V[{GenerateExpression(list[1])}])[0]",
				list => $"VHR[(int) ({GenerateExpression(list[1])})]")
				.Interpret((list, state) => state.GetRegister($"V{state.Evaluate(list[1])}").As<ushort>()[0]);
			Expression("vec-s", _ => new EFloat(32).AsRuntime(),
				list => $"state->V[{GenerateExpression(list[1])}][0]",
				list => $"VSR[(int) ({GenerateExpression(list[1])})]")
				.Interpret((list, state) => state.GetRegister($"V{state.Evaluate(list[1])}").As<float>()[0]);
			Expression("vec-d", _ => new EFloat(64).AsRuntime(),
				list => $"reinterpret_cast<Vector128<double>>(state->V[{GenerateExpression(list[1])}])[0]",
				list => $"VDR[(int) ({GenerateExpression(list[1])})]")
				.Interpret((list, state) => state.GetRegister($"V{state.Evaluate(list[1])}").As<double>()[0]);
			
			Expression("nzcv", list => new EInt(false, list.Count == 1 ? 32 : 1).AsRuntime(),
				list => {
					if(list.Count == 1) throw new NotSupportedException();
					switch(list[1]) {
						case PName("n"): return "state->NZCV_N";
						case PName("z"): return "state->NZCV_Z";
						case PName("c"): return "state->NZCV_C";
						case PName("v"): return "state->NZCV_V";
						default: throw new NotSupportedException($"Unknown field of NZCV: {list[1]}");
					}
				}, list => {
					if(list.Count == 1) throw new NotSupportedException();
					switch(list[1]) {
						case PName("n"): return "NZCV_NR";
						case PName("z"): return "NZCV_ZR";
						case PName("c"): return "NZCV_CR";
						case PName("v"): return "NZCV_VR";
						default: throw new NotSupportedException($"Unknown field of NZCV: {list[1]}");
					}
				}).Interpret((list, state) => {
					if(list.Count == 1) throw new NotSupportedException();
					return list[1] switch {
						PName("n") => Extensions.AsBool(state.GetRegister("NZCV-N")) ? 1 : 0, 
						PName("z") => Extensions.AsBool(state.GetRegister("NZCV-Z")) ? 1 : 0, 
						PName("c") => Extensions.AsBool(state.GetRegister("NZCV-C")) ? 1 : 0, 
						PName("v") => Extensions.AsBool(state.GetRegister("NZCV-V")) ? 1 : 0, 
						_ => throw new NotSupportedException()
					};
				});
			
			Expression("sr", _ => new EInt(false, 64).AsRuntime(), 
				list => $"SR({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])}, {GenerateExpression(list[5])})", 
				list => $"Call<ulong, ulong, uint, uint, uint, uint, uint>(SR, (ulong) this, {GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])}, {GenerateExpression(list[5])})")
				.NoInterpret();
		}
	}
}