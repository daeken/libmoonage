using System;
using System.Diagnostics;
using System.Linq;

namespace Arch {
	class ScalarMath : Builtin {
		static EType FirstType(PList list) => list[1].Type.AsRuntime(list.AnyRuntime);
		
		static EType LogicalType(EType a, EType b) {
			if(a is EInt || b is EInt) {
				if(!(a is EInt ai)) throw new NotSupportedException("Logical expression contains lhs that is non-int");
				if(!(b is EInt bi)) throw new NotSupportedException("Logical expression contains rhs that is non-int");
				return new EInt(
					ai.Signed == bi.Signed && ai.Signed,
					Math.Max(ai.Width, bi.Width)
				) { Runtime = ai.Runtime || bi.Runtime };
			}
			if(a is EFloat || b is EFloat) {
				if(!(a is EFloat af)) throw new NotSupportedException("Logical expression contains lhs that is non-float");
				if(!(b is EFloat bf)) throw new NotSupportedException("Logical expression contains rhs that is non-float");
				return new EFloat(Math.Max(af.Width, bf.Width)) { Runtime = af.Runtime || bf.Runtime };
			}
			throw new NotImplementedException("Logical expression has non-int/non-float type");
		}

		static EType LogicalType(PList list) => list.Skip(1).Select(x => x.Type).Aggregate(LogicalType);
		
		public override void Define() {
			Expression(
				new[] {"+", "-", "*", "/", "%"}, LogicalType,
				list => {
					Debug.Assert(list.Count == 3);
					if(list[1].Type is EInt(var sa, var ba) && list[2].Type is EInt(var sb, var bb)) {
						var stype = new EInt(sa && sb, Math.Max(ba, bb))
						{Runtime = list[1].Type.Runtime || list[2].Type.Runtime};
						return
							$"(({GenerateType(stype)}) ({GenerateType(list[1].Type.AsRuntime(list.Type.Runtime))}) ({GenerateExpression(list[1])})) {list[0]} (({GenerateType(stype)}) ({GenerateType(list[2].Type.AsRuntime(list.Type.Runtime))}) ({GenerateExpression(list[2])}))";
					}

					if(list[1].Type is EFloat(var wa) && list[2].Type is EFloat(var wb)) {
						var stype = new EFloat(Math.Max(wa, wb))
						{Runtime = list[1].Type.Runtime || list[2].Type.Runtime};
						return
							$"(({GenerateType(stype)}) ({GenerateType(list[1].Type.AsRuntime(list.Type.Runtime))}) ({GenerateExpression(list[1])})) {list[0]} (({GenerateType(stype)}) ({GenerateType(list[2].Type.AsRuntime(list.Type.Runtime))}) ({GenerateExpression(list[2])}))";
					}

					throw new NotImplementedException();
				}).Interpret(
					(list, state) =>
						(state.Evaluate(list[1]), state.Evaluate(list[2])).WithCommonType((a, b) =>
							list[0].AsName() switch {
								"+" => unchecked(a + b), "-" => unchecked(a - b), 
								"*" => unchecked(a * b), "/" => unchecked(a / b), 
								"%" => unchecked(a % b), 
								_ => throw new BailoutException()
							}));

			Expression(
				new[] { "|", "&", "^" }, FirstType,
				list => {
					var signed = true;
					var size = 0;
					foreach(var elem in list.Skip(1)) {
						if(!(elem.Type is EInt(var s, var ba)))
							throw new NotImplementedException();
						signed = signed && s;
						size = Math.Max(size, ba);
					}

					var stype = GenerateType(new EInt(signed, size).AsRuntime(list.AnyRuntime));
					return list.Skip(1).Select(x => $"(({stype}) ({GenerateExpression(x)}))")
						.Aggregate((x1, x2) => $"({x1} {list[0]} {x2})");
				}).Interpret(
				(list, state) =>
					list.Skip(2).Aggregate((object) state.Evaluate(list[1]), (al, bl) =>
						((dynamic) al, state.Evaluate(bl)).WithCommonType((a, b) =>
							list[0].AsName() switch {
								"|" => a | b,
								"&" => a & b,
								"^" => a ^ b,
								_ => throw new BailoutException()
							})));
			
			Expression("~", FirstType, list => $"~({GenerateExpression(list[1])})").Interpret((list, state) => ~state.Evaluate(list[1]));
			Expression("-!", FirstType, list => $"-({GenerateExpression(list[1])})").Interpret((list, state) => -state.Evaluate(list[1]));
			Expression("!", list => new EInt(false, 1).AsRuntime(list[1].Type.Runtime), 
				list => $"({GenerateExpression(list[1])}) != 0 ? 0U : 1U", list => $"!({GenerateExpression(list[1])})")
				.Interpret((list, state) => !Extensions.AsBool(state.Evaluate(list[1])));
			
			Expression("<<", FirstType, 
				list => $"({GenerateExpression(list[1])}) << (uint) ({GenerateExpression(list[2])})", 
				list => $"({GenerateExpression(list[1])}) << ({GenerateExpression(list[2])})")
				.Interpret((list, state) => {
					var shift = (int) state.Evaluate(list[2]);
					if(list[1].Type is EInt(_, var size) && shift >= size) return 0;
					return state.Evaluate(list[1]) << shift;
				});
			
			Expression(">>", FirstType, 
				list => $"({GenerateExpression(list[1])}) >> (uint) ({GenerateExpression(list[2])})", 
				list => $"({GenerateExpression(list[1])}) >> ({GenerateExpression(list[2])})")
				.Interpret((list, state) => {
					var shift = (int) state.Evaluate(list[2]);
					if(list[1].Type is EInt(var signed, var size) && shift >= size)
						return signed ? 0xFFFFFFFF_FFFFFFFFUL : 0;
					return state.Evaluate(list[1]) >> shift;
				});
			
			Expression(">>>", FirstType,
				list => {
					if(!(list[1].Type is EInt(false, var bs))) throw new NotSupportedException();
					return
						$"(({GenerateExpression(list[1])}) << ({bs} - (int) ({GenerateExpression(list[2])}))) | (({GenerateExpression(list[1])}) >> (int) ({GenerateExpression(list[2])}))";
				}, list => {
					if(!(list[1].Type is EInt(false, var bs))) throw new NotSupportedException();
					return
						$"(({GenerateExpression(list[1])}) << ((LlvmRuntimeValue<uint>) ({bs} - ({GenerateExpression(list[2])})))) | (({GenerateExpression(list[1])}) >> ((LlvmRuntimeValue<uint>) ({GenerateExpression(list[2])})))";
				}).Interpret((list, state) => {
					var left = state.Evaluate(list[1]);
					var right = (int) state.Evaluate(list[2]);
					if(!(list[1].Type is EInt(false, var bs))) throw new NotSupportedException();
					return (left << (bs - right)) | (left >> right);
				});

			Expression("reverse-bits", list => list[1].Type,
				list => $"ReverseBits({GenerateExpression(list[1])})",
				list => $"Call<{GenerateType(list[1].Type.AsCompiletime())}, {GenerateType(list[1].Type.AsCompiletime())}>(ReverseBits, {GenerateExpression(list[1])})")
				.NoInterpret(); // TODO: Implement

			Expression("count-leading-zeros", list => list[1].Type,
				list => $"CountLeadingZeros({GenerateExpression(list[1])})", 
				list => $"Call<{GenerateType(list[1].Type.AsCompiletime())}, {GenerateType(list[1].Type.AsCompiletime())}>(CountLeadingZeros, {GenerateExpression(list[1])})")
				.NoInterpret(); // TODO: Implement

			Expression(":", list => new EInt(false,
					list.Skip(1).Select(y => y.Type is EInt(_, var width) ? width : throw new NotSupportedException())
						.Sum()).AsRuntime(list.AnyRuntime),
				list => {
					var offset = 0;
					return list.Skip(1).Reverse().Select(x => {
						if(!(x.Type is EInt(_, var width))) throw new NotSupportedException();
						var ret = $"((({GenerateType(list.Type)}) ({GenerateExpression(x)})) << {offset})";
						offset += width;
						return ret;
					}).Aggregate((a, x) =>
						$"({GenerateType(list.Type)}) ((({GenerateType(list.Type)}) {a}) | (({GenerateType(list.Type)}) {x}))");
				}).Interpret((list, state) => {
					var ret = 0UL;
					foreach(var elem in list.Skip(1)) {
						var value = state.Evaluate(elem);
						if(!(elem.Type is EInt(_, var width))) throw new NotSupportedException("Non-int element in :");
						ret <<= width;
						ret |= (ulong) Extensions.AsNonBool(value);
					}
					return ret;
				});

			Expression("replicate", list => new EInt(false,
					list[1].Type is EInt(_, var elemWidth) && list[2] is PInt(var count)
						? elemWidth * (int) count
						: throw new NotSupportedException()).AsRuntime(list[1].Type.Runtime),
				list => {
					if(!(list[1].Type is EInt(_, var width))) throw new NotSupportedException();
					if(!(list[2] is PInt(var count))) throw new NotSupportedException();
					return Enumerable.Range(0, (int) count)
						.Select(i => $"((({GenerateType(list.Type)}) ({GenerateExpression(list[1])})) << {i * width})")
						.Aggregate((a, x) =>
							$"({GenerateType(list.Type)}) ((({GenerateType(list.Type)}) {a}) | (({GenerateType(list.Type)}) {x}))");
				}).Interpret((list, state) => {
					var ret = 0UL;
					var value = (ulong) state.Evaluate(list[1]);
					var count = (int) state.Evaluate(list[2]);
					if(!(list[1].Type is EInt(_, var width))) throw new NotSupportedException("Non-int value for replicate");
					for(var i = 0; i < count; ++i) {
						ret <<= width;
						ret |= value;
					}
					return ret;
				});
			
			Expression("abs", list => list[1].Type, 
				list => list[1].Type switch {
					EFloat(_) => $"fabs({GenerateExpression(list[1])})", 
					_ => throw new NotSupportedException()
				}, 
				list => $"({GenerateExpression(list[1])}).Abs()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Abs(x)).IfNot<float>(x => Math.Abs(x)));

			Expression("sqrt", list => list[1].Type,
				list => $"({GenerateType(list.Type)}) sqrt((double) ({GenerateExpression(list[1])}))",
				list => $"({GenerateType(list.Type)}) (({GenerateType(new EFloat(64).AsRuntime(list[1].Type.Runtime))}) ({GenerateExpression(list[1])})).Sqrt()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Sqrt(x)).IfNot<float>(x => Math.Sqrt((double) x)));
			
			Expression("round", list => list[1].Type, 
				list => $"round{(list[1].Type is EFloat(var size) && size == 32 ? "f" : "")}({GenerateExpression(list[1])})", 
				list => $"({GenerateExpression(list[1])}).Round()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Round(x)).IfNot<float>(x => Math.Round((double) x)));
			
			Expression("round-half-down", list => list[1].Type, 
				list => $"ceil{(list[1].Type is EFloat(var size) && size == 32 ? "f" : "")}(({GenerateExpression(list[1])}) - 0.5{(list[1].Type is EFloat(var _size) && _size == 32 ? "f" : "")})", 
				list => $"({GenerateExpression(list[1])}).RoundHalfDown()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Ceiling(x - 0.5f)).IfNot<float>(x => Math.Ceiling((double) x - 0.5)));
			
			Expression("round-half-up", list => list[1].Type, 
				list => $"floor{(list[1].Type is EFloat(var size) && size == 32 ? "f" : "")}(({GenerateExpression(list[1])}) + 0.5{(list[1].Type is EFloat(var _size) && _size == 32 ? "f" : "")})", 
				list => $"({GenerateExpression(list[1])}).RoundHalfUp()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Floor(x + 0.5f)).IfNot<float>(x => Math.Floor((double) x + 0.5)));
			
			Expression("ceil", list => list[1].Type, 
				list => $"ceil{(list[1].Type is EFloat(var size) && size == 32 ? "f" : "")}({GenerateExpression(list[1])})", 
				list => $"({GenerateExpression(list[1])}).Ceil()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Ceiling(x)).IfNot<float>(x => Math.Ceiling((double) x)));
			
			Expression("floor", list => list[1].Type, 
				list => $"floor{(list[1].Type is EFloat(var size) && size == 32 ? "f" : "")}({GenerateExpression(list[1])})", 
				list => $"({GenerateExpression(list[1])}).Floor()")
				.Interpret((list, state) => ((object) state.Evaluate(list[1])).If<float>(x => MathF.Floor(x)).IfNot<float>(x => Math.Floor((double) x)));

			Expression("float-to-fixed-point", list => TypeFromName(list[2]).AsRuntime(list[1].Type.Runtime || list[3].Type.Runtime), 
				list => $"FloatToFixed{((EInt) list.Type).Width}({GenerateExpression(list[1])}, (int) ({GenerateExpression(list[3])}))", 
				list => $"Call<{(((EInt) list.Type).Width == 64 ? "ulong" : "uint")}, {GenerateType(list[1].Type.AsCompiletime())}, int>(FloatToFixed{((EInt) list.Type).Width}, {GenerateExpression(list[1])}, (LlvmRuntimeValue<int>) ({GenerateExpression(list[3])}))")
				.Interpret((list, state) => {
					var width = ((EInt) list.Type).Width;
					var swidth = ((EFloat) list[1].Type).Width;
					var fvalue = state.Evaluate(list[1]);
					var fbits = (int) state.Evaluate(list[3]);
					return (width, swidth) switch {
						(32, 32) => (dynamic) unchecked((uint) (int) MathF.Round(fvalue * (1 << fbits))), 
						(64, 32) => (dynamic) unchecked((ulong) (long) MathF.Round(fvalue * (1 << fbits))), 
						(32, 64) => (dynamic) unchecked((uint) (int) Math.Round(fvalue * (1 << fbits))), 
						(64, 64) => (dynamic) unchecked((ulong) (long) Math.Round(fvalue * (1 << fbits))), 
						_ => throw new NotSupportedException()
					};
				});
			
			Expression("bitwidth", _ => new EInt(true, 32),
				list => {
					switch(TypeFromName(list[1])) {
						case EInt(_, var iwidth): return iwidth.ToString();
						case EFloat(var fwidth): return fwidth.ToString();
						case EVector _: return "128";
						default: throw new NotSupportedException(list[1].Type.ToString());
					}
				}).Interpret((list, state) => TypeFromName(list[1]) switch {
					EInt(_, var width) => width, 
					EFloat(var width) => width, 
					EVector _ => 128, 
					var type => throw new NotSupportedException($"Bitwidth on type {type}")
				});

			Expression("NaN?", list => new EInt(false, 1).AsRuntime(list[1].Type.Runtime),
				list => $"isnan({GenerateExpression(list[1])}) ? 1U : 0U",
				list => $"({GenerateExpression(list[1])}).IsNaN()")
				.Interpret((list, state) => 
					state.Evaluate(list[1]) switch { float v => float.IsNaN(v), double v => double.IsNaN(v), _ => false });

			Expression("literal", list => list[1].Type,
				list => GenerateExpression(new PInt((long) ExecutionState.Cleanroom().Evaluate(list[1])) { Type = list[1].Type }))
				.Interpret((list, state) => state.Evaluate(list[1]));

			Expression("make-wmask", _ => new EInt(false, 64),
				list => $"MakeWMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})",
				list => $"MakeWMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})")
				.Interpret((list, state) => MakeWMask((uint) state.Evaluate(list[1]), (uint) state.Evaluate(list[2]), (uint) state.Evaluate(list[3]), (long) state.Evaluate(list[5]), (int) state.Evaluate(list[4])));

			Expression("make-tmask", _ => new EInt(false, 64),
				list => $"MakeTMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})",
				list => $"MakeTMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})")
				.Interpret((list, state) => MakeTMask((uint) state.Evaluate(list[1]), (uint) state.Evaluate(list[2]), (uint) state.Evaluate(list[3]), (long) state.Evaluate(list[5]), (int) state.Evaluate(list[4])));
		}

		static int HighestSetBit(ulong v, int bits) {
			for(var i = bits - 1; i >= 0; --i)
				if((v & (1UL << i)) != 0)
					return i;
			return -1;
		}

		static ulong ZeroExtend(ulong v, int bits) => v & Ones(bits);
		static ulong Ones(int bits) => Enumerable.Range(0, bits).Select(i => 1UL << i).Aggregate((a, b) => a | b);

		static ulong Replicate(ulong v, int bits, int start, int rep, int ext) {
			var repval = (v >> start) & Ones(rep);
			var times = ext / rep;
			var val = 0UL;
			for(var i = 0; i < times; ++i)
				val = (val << rep) | repval;
			return v | (val << start);
		}

		static ulong RollRight(ulong v, int size, int rotate) => ((v << (size - rotate)) | (v >> rotate)) & Ones(size);

		static (ulong, ulong) MakeMasks(uint n, uint imms, uint immr, int m, bool immediate) {
			var len = HighestSetBit((n << 6) | (imms ^ 0b111111U), 7);
			if(!(len > 0 && m >= 1 << len)) throw new BailoutException();

			var levels = ZeroExtend(Ones(len), 6);
			if(!(!immediate || (imms & levels) != levels)) throw new BailoutException();
            
			var S = imms & levels;
			var R = immr & levels;

			var diff = (S - R) & 0b111111;
			var esize = 1 << len;
			var d = diff & Ones(len);

			var welem = ZeroExtend(Ones((int) (S + 1)), esize);
			var telem = ZeroExtend(Ones((int) (d + 1)), esize);

			var wmask = Replicate(RollRight(welem, esize, (int) R), esize, 0, esize, m);
			var tmask = Replicate(telem, esize, 0, esize, m);
			return (wmask, tmask);
		}

		static ulong MakeWMask(uint n, uint imms, uint immr, long m, int immediate) => MakeMasks(n, imms, immr, (int) m, immediate != 0).Item1;
		static ulong MakeTMask(uint n, uint imms, uint immr, long m, int immediate) => MakeMasks(n, imms, immr, (int) m, immediate != 0).Item2;
	}
}