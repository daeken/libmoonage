using System;
using System.Diagnostics;
using System.Linq;
using MoreLinq.Extensions;

namespace Arch {
	public class Logic : Builtin {
		public override void Define() {
			Statement("=", list => list[2].Type?.AsRuntime(list.AnyRuntime) ?? throw new NotImplementedException(),
				(c, list) => {
					if(list[1] is PList sub)
						switch(sub[0]) {
							case PName("gpr32"):
								c += $"state->X[(int) {GenerateExpression(sub[1])}] = (ulong) (uint) ({GenerateExpression(list[2])});";
								return;
							case PName("gpr-or-sp32"):
								c += $"if({GenerateExpression(sub[1])} == 31)";
								c++;
								c += $"state->SP = (ulong) (uint) ({GenerateExpression(list[2])});";
								c--;
								c += "else";
								c++;
								c += $"state->X[(int) {GenerateExpression(sub[1])}] = (ulong) (uint) ({GenerateExpression(list[2])});";
								c--;
								return;
							case PName("gpr64"):
								c += $"state->X[(int) {GenerateExpression(sub[1])}] = {GenerateExpression(list[2])};";
								return;
							case PName("gpr-or-sp64"):
								c += $"if({GenerateExpression(sub[1])} == 31)";
								c++;
								c += $"state->SP = {GenerateExpression(list[2])};";
								c--;
								c += "else";
								c++;
								c += $"state->X[(int) {GenerateExpression(sub[1])}] = {GenerateExpression(list[2])};";
								c--;
								return;
							
							case PName("vec-b"):
								c += $"state->V[(int) ({GenerateExpression(sub[1])})] = reinterpret_cast<Vector128<float>>((Vector128<uint8_t>) {{ {GenerateExpression(list[2])}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }});";
								return;
							case PName("vec-h"):
								c += $"state->V[(int) ({GenerateExpression(sub[1])})] = reinterpret_cast<Vector128<float>>((Vector128<uint16_t>) {{ {GenerateExpression(list[2])}, 0, 0, 0, 0, 0, 0, 0 }});";
								return;
							case PName("vec-s"):
								c += $"state->V[(int) ({GenerateExpression(sub[1])})] = (Vector128<float>) {{ {GenerateExpression(list[2])}, 0, 0, 0 }};";
								return;
							case PName("vec-d"):
								c += $"state->V[(int) ({GenerateExpression(sub[1])})] = reinterpret_cast<Vector128<float>>((Vector128<double>) {{ {GenerateExpression(list[2])}, 0 }});";
								return;
							
							case PName("sr"):
								c += $"SR({GenerateExpression(sub[1])}, {GenerateExpression(sub[2])}, {GenerateExpression(sub[3])}, {GenerateExpression(sub[4])}, {GenerateExpression(sub[5])}, {GenerateExpression(list[2])});";
								return;
							
							case PName("nzcv") when sub.Count == 1:
								c += $"NZCV = {GenerateExpression(list[2])};";
								return;
						}

					c += $"{GenerateExpression(list[1], lhs: true)} = {GenerateExpression(list[2])};";
				},
				(c, list) => {
					if(list[1] is PList sub)
						switch(sub[0]) {
							case PName("gpr32"):
								c += $"XR[(int) {GenerateExpression(sub[1])}] = (LlvmRuntimeValue<uint64_t>) (LlvmRuntimeValue<uint32_t>) ({GenerateExpression(list[2])});";
								return;
							case PName("gpr-or-sp32"):
								c += $"if({GenerateExpression(sub[1])} == 31)";
								c++;
								c += $"SPR = (LlvmRuntimeValue<uint64_t>) (LlvmRuntimeValue<uint32_t>) ({GenerateExpression(list[2])});";
								c--;
								c += "else";
								c++;
								c += $"XR[(int) {GenerateExpression(sub[1])}] = (LlvmRuntimeValue<uint64_t>) (LlvmRuntimeValue<uint32_t>) ({GenerateExpression(list[2])});";
								c--;
								return;
							case PName("gpr64"):
								c += $"XR[(int) {GenerateExpression(sub[1])}] = {GenerateExpression(list[2])};";
								return;
							case PName("gpr-or-sp64"):
								c += $"if({GenerateExpression(sub[1])} == 31)";
								c++;
								c += $"SPR = {GenerateExpression(list[2])};";
								c--;
								c += "else";
								c++;
								c += $"XR[(int) {GenerateExpression(sub[1])}] = {GenerateExpression(list[2])};";
								c--;
								return;
							case PName("sr"):
								c += $"Call<void, ulong, uint, uint, uint, uint, uint, ulong>(SR, (uint64_t) this, {GenerateExpression(sub[1])}, {GenerateExpression(sub[2])}, {GenerateExpression(sub[3])}, {GenerateExpression(sub[4])}, {GenerateExpression(sub[5])}, {GenerateExpression(list[2])});";
								return;
							case PName("nzcv") when sub.Count == 1:
								c += $"NZCVR = {GenerateExpression(list[2])};";
								return;
						}

					c += $"{GenerateExpression(list[1], lhs: true)} = {GenerateExpression(list[2])};";
				}).Interpret((list, state) => {
					var value = state.Evaluate(list[2]);
					if(list[1] is PList sub)
						switch(sub[0]) {
							case PName("gpr32"):
								var regz32 = state.Evaluate(sub[1]);
								if(regz32 != 31)
									state.Registers[$"X{regz32}"] = (ulong) (uint) value;
								break;
							case PName("gpr-or-sp32"):
								var reg32 = state.Evaluate(sub[1]);
								state.Registers[reg32 == 31 ? "SP" : $"X{reg32}"] = (ulong) (uint) value;
								break;
							case PName("gpr64"):
								var regz64 = state.Evaluate(sub[1]);
								if(regz64 != 31)
									state.Registers[$"X{regz64}"] = (ulong) value;
								break;
							case PName("gpr-or-sp64"):
								var reg64 = state.Evaluate(sub[1]);
								state.Registers[reg64 == 31 ? "SP" : $"X{reg64}"] = (ulong) value;
								break;
							
							case PName("vec"):
								state.Registers[$"V{state.Evaluate(sub[1])}"] = value;
								break;
							case PName("vec-b"):
								state.Registers[$"V{state.Evaluate(sub[1])}"] = new Vector128<byte>((byte) value, single: true);
								break;
							case PName("vec-h"):
								state.Registers[$"V{state.Evaluate(sub[1])}"] = new Vector128<ushort>((ushort) value, single: true);
								break;
							case PName("vec-s"):
								state.Registers[$"V{state.Evaluate(sub[1])}"] = new Vector128<float>((float) value, single: true);
								break;
							case PName("vec-d"):
								state.Registers[$"V{state.Evaluate(sub[1])}"] = new Vector128<double>((double) value, single: true);
								break;
							
							case PName("nzcv"):
								if(sub.Count == 1) {
									state.Registers["NZCV-N"] = (value >> 31) & 1;
									state.Registers["NZCV-Z"] = (value >> 30) & 1;
									state.Registers["NZCV-C"] = (value >> 29) & 1;
									state.Registers["NZCV-V"] = (value >> 28) & 1;
								} else
									switch(sub[1]) {
										case PName("n"):
											state.Registers["NZCV-N"] = Extensions.AsBool(value) ? 1UL : 0UL;
											break;
										case PName("z"):
											state.Registers["NZCV-Z"] = Extensions.AsBool(value) ? 1UL : 0UL;
											break;
										case PName("c"):
											state.Registers["NZCV-C"] = Extensions.AsBool(value) ? 1UL : 0UL;
											break;
										case PName("v"):
											state.Registers["NZCV-V"] = Extensions.AsBool(value) ? 1UL : 0UL;
											break;
										default:
											throw new NotSupportedException();
									}
								break;
							
							case PName("sr"):
								throw new BailoutException();
							
							default:
								throw new NotSupportedException();
						}
					else
						state.Locals[list[1].AsName()] = value;
					return value;
				});
			
			Statement("let", 
				list => list.Last().Type.AsRuntime(list[2].Type.Runtime),
				(c, list) => {
					c += $"auto {list[1]} = {GenerateExpression(list[2])};";
					list.Skip(3).ForEach(x => GenerateStatement(c, (PList) x));
				}, (c, list) => {
					if(list[2].Type.Runtime)
						c += $"auto {list[1]} = ({GenerateExpression(list[2])}).Store();";
					else
						c += $"auto {list[1]} = {GenerateExpression(list[2])};";
					list.Skip(3).ForEach(x => GenerateStatement(c, (PList) x));
				}).Interpret((list, state) => {
					state.Locals[list[1].AsName()] = state.Evaluate(list[2]);
					return state.Evaluate(list.Skip(3));
				});

			Statement("mlet", 
				list => list.Last().Type.AsRuntime(list.AnyRuntime),
				(c, list) => {
					if(!(list[1] is PList dlist)) throw new NotSupportedException();
					Debug.Assert(dlist.Count % 2 == 0);
					for(var i = 0; i < dlist.Count; i += 2)
						c += $"auto {dlist[i]} = {GenerateExpression(dlist[i + 1])};";
					list.Skip(2).ForEach(x => GenerateStatement(c, (PList) x));
				}, (c, list) => {
					if(!(list[1] is PList dlist)) throw new NotSupportedException();
					Debug.Assert(dlist.Count % 2 == 0);
					for(var i = 0; i < dlist.Count; i += 2)
						if(dlist[i + 1].Type.Runtime)
							c += $"auto {dlist[i]} = ({GenerateExpression(dlist[i + 1])}).Store();";
						else
							c += $"auto {dlist[i]} = {GenerateExpression(dlist[i + 1])};";
					list.Skip(2).ForEach(x => GenerateStatement(c, (PList) x));
				}).Interpret((list, state) => {
					var assigns = (PList) list[1];
					Debug.Assert(assigns.Count % 2 == 0);
					for(var i = 0; i < assigns.Count; i += 2)
						state.Locals[assigns[i].AsName()] = state.Evaluate(assigns[i + 1]);
					return state.Evaluate(list.Skip(2));
				});

			Expression("cast", list => TypeFromName(list[2]).AsRuntime(list.AnyRuntime), 
				list => $"({GenerateType(list.Type)}) ({GenerateExpression(list[1])})")
				.Interpret((list, state) => TypeFromName(list[2]) switch {
					EInt(true, var width) when width <= 8 => (dynamic) (sbyte) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(true, var width) when width <= 16 => (dynamic) (short) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(true, var width) when width <= 32 => (dynamic) (int) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(true, var width) when width <= 64 => (dynamic) (long) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(true, var width) when width <= 128 => (dynamic) (Int128Wrapper) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(false, var width) when width <= 8 => (dynamic) (byte) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(false, var width) when width <= 16 => (dynamic) (ushort) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(false, var width) when width <= 32 => (dynamic) (uint) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(false, var width) when width <= 64 => (dynamic) (ulong) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EInt(false, var width) when width <= 128 => (dynamic) (UInt128Wrapper) Extensions.AsNonBool(state.Evaluate(list[1])), 
					EFloat(32) => (dynamic) (float) state.Evaluate(list[1]), 
					EFloat(64) => (dynamic) (double) state.Evaluate(list[1]), 
					{} type => throw new NotSupportedException($"Cannot cast to type {type}")
				});
			Expression("bitcast", list => TypeFromName(list[2]).AsRuntime(list.AnyRuntime), 
				list => $"Bitcast<{GenerateType(list[1].Type)}, {GenerateType(list.Type)}>({GenerateExpression(list[1])})", 
				list => $"({GenerateExpression(list[1])}).Bitcast<{GenerateType(list.Type.AsCompiletime())}>()")
				.Interpret((list, state) => {
					var bytes = ((byte[]) BitConverter.GetBytes(state.Evaluate(list[1]))).Concat(new byte[8]).ToArray();
					return TypeFromName(list[2]) switch {
						EInt(true, 8) => (dynamic) (sbyte) bytes[0], 
						EInt(false, 8) => bytes[0], 
						EInt(true, 16) => BitConverter.ToInt16(bytes), 
						EInt(false, 16) => BitConverter.ToUInt16(bytes), 
						EInt(true, 32) => BitConverter.ToInt32(bytes), 
						EInt(false, 32) => BitConverter.ToUInt32(bytes), 
						EInt(true, 64) => BitConverter.ToInt64(bytes), 
						EInt(false, 64) => BitConverter.ToUInt64(bytes),
						EFloat(32) => BitConverter.ToSingle(bytes), 
						EFloat(64) => BitConverter.ToDouble(bytes), 
						EVector _ => Vector128<float>.FromBytes(bytes), 
						{} type => throw new NotSupportedException($"Cannot bitcast to type {type}")
					};
				});
			
			T SignExt<T>(ulong value, int size) {
				if(typeof(T) == typeof(long))
					return (T) (object) ((value & (1UL << (size - 1))) != 0 ? (long) value - (1L << size) : (long) value);
				if(typeof(T) == typeof(int))
					return (T) (object) ((value & (1UL << (size - 1))) != 0 ? (int) value - (1 << size) : (int) value);
				throw new NotImplementedException($"Unknown return for SignExt: {typeof(T)}");
			}

			Expression("signext", list => TypeFromName(list[2]).AsRuntime(list.AnyRuntime), 
				list => $"SignExt<{GenerateType(list.Type)}>({GenerateExpression(list[1])}, {((EInt) list[1].Type).Width})", 
				list => $"SignExtRuntime<{GenerateType(list.Type.AsCompiletime())}>({GenerateExpression(list[1])}, {((EInt) list[1].Type).Width})")
				.Interpret((list, state) =>
					TypeFromName(list[2]) switch {
						EInt(true, 32) => SignExt<int>((ulong) state.Evaluate(list[1]), ((EInt) list[1].Type).Width), 
						EInt(true, 64) => SignExt<long>((ulong) state.Evaluate(list[1]), ((EInt) list[1].Type).Width),
						{} type => throw new NotSupportedException($"SignExt on unsupported type {type}")
					});

			Expression(new[] { "==", "!=", ">", ">=", "<=", "<" },
				list => new EInt(false, 1).AsRuntime(list.AnyRuntime),
				list => $"(({GenerateExpression(list[1])}) {list[0]} ({GenerateExpression(list[2])})) ? 1U : 0U",
				list => $"({GenerateExpression(list[1])}) {list[0]} ({GenerateExpression(list[2])})")
				.Interpret(
					(list, state) =>
						(state.Evaluate(list[1]), state.Evaluate(list[2])).WithCommonType((a, b) =>
							list[0].AsName() switch {
								"==" => a == b, "!=" => a != b, 
								">" => a > b, ">=" => a >= b, 
								"<" => a < b, "<=" => a <= b, 
								_ => throw new BailoutException()
								}));
		}
	}
}