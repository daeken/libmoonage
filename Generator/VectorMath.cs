using System;

namespace Generator {
	class VectorMath : Builtin {
		public override void Define() {
			Expression("vector-all", list => EType.Vector.AsRuntime(),
				list => $"reinterpret_cast<Vector128<float>>(({GenerateExpression(list[1])}) - (Vector128<{GenerateType(list[1].Type)}>) {{}})",
				list => $"(({GenerateType(list[1].Type.AsRuntime())}) ({GenerateExpression(list[1])})).CreateVector()");
			Expression("vector-zero-top", list => EType.Vector.AsRuntime(), list => GenerateExpression(list[1]));
			Expression("vector-insert", _ => EType.Unit,
				list => $"reinterpret_cast<Vector128<{GenerateType(list[3].Type)}>*>(&(state->V[(int) ({GenerateExpression(list[1])})]))[0][{GenerateExpression(list[2])}] = {GenerateExpression(list[3])}",
				list => $"VR[(int) ({GenerateExpression(list[1])})] = VR[(int) ({GenerateExpression(list[1])})]().Insert({GenerateExpression(list[2])}, {GenerateExpression(list[3])})");
			Expression("vector-element", list => TypeFromName(list[3]).AsRuntime(),
				list => $"reinterpret_cast<Vector128<{GenerateType(list.Type.AsCompiletime())}>>({GenerateExpression(list[1])})[{GenerateExpression(list[2])}]",
				list => $"({GenerateExpression(list[1])}).Element<{GenerateType(list.Type.AsCompiletime())}>({GenerateExpression(list[2])})");
			Expression("vector-extract", list => EType.Vector.AsRuntime(list[1].Type.Runtime || list[2].Type.Runtime), 
				list => $"VectorExtract({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])})", 
				list => $"Call<Vector128<float>, Vector128<float>, Vector128<float>, uint, uint>(VectorExtract, {GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])})");

			Expression("vector-count-bits", _ => EType.Vector, 
				list => $"VectorCountBits({GenerateExpression(list[1])}, {GenerateExpression(list[2])})", 
				list => $"Call<Vector128<float>, Vector128<float>, long>(VectorCountBits, {GenerateExpression(list[1])}, {GenerateExpression(list[2])})");

			Expression("vector-sum-unsigned", _ => new EInt(false, 32),
				list => $"VectorSumUnsigned({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])})", 
				list => $"Call<ulong, Vector128<float>, long, long>(VectorSumUnsigned, {GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])})");
			
			Expression("vec-frsqrte", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => $"VectorFrsqrte({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])})", 
				list => $"Call<Vector128<float>, Vector128<float>, int, int>(VectorFrsqrte, {GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])})");
			
			Expression("vec+", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) + ({GenerateExpression(list[2])})", 
					PInt(64) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>({GenerateExpression(list[1])}) + reinterpret_cast<Vector128<double>>({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				}, 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) + ({GenerateExpression(list[2])})", 
					PInt(64) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ({GenerateExpression(list[1])}) + (RuntimeValue<Vector128<double>>) ({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				});
			
			Expression("vec-", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) - ({GenerateExpression(list[2])})", 
					PInt(64) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>({GenerateExpression(list[1])}) - reinterpret_cast<Vector128<double>>({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				}, 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) - ({GenerateExpression(list[2])})", 
					PInt(64) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ({GenerateExpression(list[1])}) - (RuntimeValue<Vector128<double>>) ({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				});
			
			Expression("vec*", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) * ({GenerateExpression(list[2])})", 
					PInt(64) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>({GenerateExpression(list[1])}) * reinterpret_cast<Vector128<double>>({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				}, 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) * ({GenerateExpression(list[2])})", 
					PInt(64) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ({GenerateExpression(list[1])}) * (RuntimeValue<Vector128<double>>) ({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				});

			string CastVector(PTree elem, string type) =>
				elem.Type is EVector
					? $"reinterpret_cast<Vector128<{type}>>({GenerateExpression(elem)})"
					: $"({GenerateExpression(elem)})";
			string RuntimeCastVector(PTree elem, string type) =>
				elem.Type is EVector
					? $"((RuntimeValue<Vector128<{type}>>) ({GenerateExpression(elem)}))"
					: $"({GenerateExpression(elem)})";
			
			Expression("vec-uint+", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => list[3] switch {
					PInt(8) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<byte>>({GenerateExpression(list[1])}) + ({CastVector(list[2], "byte")}))",
					PInt(16) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>({GenerateExpression(list[1])}) + ({CastVector(list[2], "ushort")}))",
					PInt(32) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>({GenerateExpression(list[1])}) + ({CastVector(list[2], "uint")}))",
					PInt(64) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ulong>>({GenerateExpression(list[1])}) + ({CastVector(list[2], "ulong")}))",
					_ => throw new NotSupportedException()
				}, 
				list => list[3] switch {
					PInt(8) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[1])}) + {RuntimeCastVector(list[2], "byte")})",
					PInt(16) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ushort>>) ({GenerateExpression(list[1])}) + {RuntimeCastVector(list[2], "ushort")})",
					PInt(32) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<uint>>) ({GenerateExpression(list[1])}) + {RuntimeCastVector(list[2], "uint")})",
					PInt(64) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ulong>>) ({GenerateExpression(list[1])}) + {RuntimeCastVector(list[2], "ulong")})",
					_ => throw new NotSupportedException()
				});
			
			Expression("vec-uint*", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => list[3] switch {
					PInt(8) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<byte>>({GenerateExpression(list[1])}) * ({CastVector(list[2], "byte")}))",
					PInt(16) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ushort>>({GenerateExpression(list[1])}) * ({CastVector(list[2], "ushort")}))",
					PInt(32) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<uint>>({GenerateExpression(list[1])}) * ({CastVector(list[2], "uint")}))",
					PInt(64) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<ulong>>({GenerateExpression(list[1])}) * ({CastVector(list[2], "ulong")}))",
					_ => throw new NotSupportedException()
				}, 
				list => list[3] switch {
					PInt(8) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[1])}) * {RuntimeCastVector(list[2], "byte")})",
					PInt(16) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ushort>>) ({GenerateExpression(list[1])}) * {RuntimeCastVector(list[2], "ushort")})",
					PInt(32) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<uint>>) ({GenerateExpression(list[1])}) * {RuntimeCastVector(list[2], "uint")})",
					PInt(64) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<ulong>>) ({GenerateExpression(list[1])}) * {RuntimeCastVector(list[2], "ulong")})",
					_ => throw new NotSupportedException()
				});
			
			Expression("vec/", list => EType.Vector.AsRuntime(list.AnyRuntime), 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) / ({GenerateExpression(list[2])})", 
					PInt(64) => $"reinterpret_cast<Vector128<float>>(reinterpret_cast<Vector128<double>>({GenerateExpression(list[1])}) / reinterpret_cast<Vector128<double>>({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				}, 
				list => list[3] switch {
					PInt(32) => $"({GenerateExpression(list[1])}) / ({GenerateExpression(list[2])})", 
					PInt(64) => $"(RuntimeValue<Vector128<float>>) ((RuntimeValue<Vector128<double>>) ({GenerateExpression(list[1])}) / (RuntimeValue<Vector128<double>>) ({GenerateExpression(list[2])}))",
					_ => throw new NotSupportedException()
				});
			
			Expression("vec&", list => list[1].Type, 
				list => $"reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>({GenerateExpression(list[1])}) & reinterpret_cast<Vector128<byte>>({GenerateExpression(list[2])})))",
				list => $"(RuntimeValue<Vector128<float>>) ((((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[1])})) & ((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[2])}))))");
			
			Expression("vec&~", list => list[1].Type, 
				list => $"reinterpret_cast<Vector128<float>>(~(reinterpret_cast<Vector128<byte>>({GenerateExpression(list[1])}) & reinterpret_cast<Vector128<byte>>({GenerateExpression(list[2])})))",
				list => $"(RuntimeValue<Vector128<float>>) (~(((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[1])})) & ((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[2])}))))");
			
			Expression("vec|", list => list[1].Type, 
				list => $"reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>({GenerateExpression(list[1])}) | reinterpret_cast<Vector128<byte>>({GenerateExpression(list[2])})))",
				list => $"(RuntimeValue<Vector128<float>>) ((((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[1])})) | ((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[2])}))))");
		
			Expression("vec^", list => list[1].Type, 
				list => $"reinterpret_cast<Vector128<float>>((reinterpret_cast<Vector128<byte>>({GenerateExpression(list[1])}) ^ reinterpret_cast<Vector128<byte>>({GenerateExpression(list[2])})))",
				list => $"(RuntimeValue<Vector128<float>>) ((((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[1])})) ^ ((RuntimeValue<Vector128<byte>>) ({GenerateExpression(list[2])}))))");
		}
	}
}