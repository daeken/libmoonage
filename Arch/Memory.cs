#define USE_SYSTEM_MEMORY

using System;

namespace Arch {
	public class Memory : Builtin {
		public const bool UseSystemMemory = true;
		public override void Define() {
			Expression("load", list => TypeFromName(list[2]).AsRuntime(),
				list => {
					var type = GenerateType(list.Type);
#if USE_SYSTEM_MEMORY
					if(type == "Vector128<float>")
						return $"LoadVector({GenerateExpression(list[1])})";
					return $"*({type}*) ({GenerateExpression(list[1])})";
#else
					return $"ReadMemory<{type}>({GenerateExpression(list[1])})";
#endif
				},
				list =>
					$"((RuntimePointer<{GenerateType(list.Type.AsCompiletime())}>) ({GenerateExpression(list[1])})).value()")
				.Interpret((list, state) => state.GetMemory(state.Evaluate(list[1]), list.Type));

			Expression("load-exclusive", list => TypeFromName(list[2]).AsRuntime(),
				list =>
					$"state->Exclusive{(list.Type is EInt(_, var ewidth) ? ewidth : throw new NotSupportedException())} = *({GenerateType(list.Type)}*) ({GenerateExpression(list[1])})",
				list =>
					$"Exclusive{(list.Type is EInt(_, var width) ? width : throw new NotSupportedException())}R = ((RuntimePointer<{GenerateType(list.Type.AsCompiletime())}>) ({GenerateExpression(list[1])})).value()")
				.NoInterpret(); // TODO: Implement
			
			Expression("store", _ => EType.Unit.AsRuntime(),
				list => {
					var type = GenerateType(list[2].Type);
#if USE_SYSTEM_MEMORY
					if(type == "Vector128<float>")
						return $"StoreVector({GenerateExpression(list[1])}, {GenerateExpression(list[2])})";
					return $"*({GenerateType(list[2].Type)}*) ({GenerateExpression(list[1])}) = {GenerateExpression(list[2])}";
#else
					return $"WriteMemory<{type}>({GenerateExpression(list[1])}, {GenerateExpression(list[2])})";
#endif
				},
				list =>
					$"((RuntimePointer<{GenerateType(list[2].Type.AsCompiletime())}>) ({GenerateExpression(list[1])})).value({GenerateExpression(list[2])})")
				.Interpret((list, state) => {
					state.SetMemory(state.Evaluate(list[1]), state.Evaluate(list[2]));
					return null;
				});
			
			Expression("store-exclusive", _ => new EInt(false, 1).AsRuntime(), 
				list => $"CompareAndSwap(({GenerateType(list[2].Type)}*) ({GenerateExpression(list[1])}), {GenerateExpression(list[2])}, state->Exclusive{(list[2].Type is EInt(_, var sewidth) ? sewidth : throw new NotSupportedException())})", 
				list => $"CompareAndSwap((RuntimePointer<{GenerateType(list[2].Type.AsCompiletime())}>) ({GenerateExpression(list[1])}), {GenerateExpression(list[2])}, Exclusive{(list[2].Type is EInt(_, var sewidth) ? sewidth : throw new NotSupportedException())}R())")
				.NoInterpret(); // TODO: Implement
		}
	}
}