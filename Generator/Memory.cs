using System;

namespace Generator {
	public class Memory : Builtin {
		public override void Define() {
			Expression("load", list => TypeFromName(list[2]).AsRuntime(),
				list => $"*({GenerateType(list.Type)}*) ({GenerateExpression(list[1])})",
				list =>
					$"((RuntimePointer<{GenerateType(list.Type.AsCompiletime())}>) ({GenerateExpression(list[1])})).value");

			Expression("load-exclusive", list => TypeFromName(list[2]).AsRuntime(),
				list =>
					$"state->Exclusive{(list.Type is EInt(_, var ewidth) ? ewidth : throw new NotSupportedException())} = *({GenerateType(list.Type)}*) ({GenerateExpression(list[1])})",
				list =>
					$"Exclusive{(list.Type is EInt(_, var width) ? width : throw new NotSupportedException())}R = ((RuntimePointer<{GenerateType(list.Type.AsCompiletime())}>) ({GenerateExpression(list[1])})).value");
			
			Expression("store", _ => EType.Unit.AsRuntime(),
				list => 
					$"*({GenerateType(list[2].Type)}*) ({GenerateExpression(list[1])}) = {GenerateExpression(list[2])}",
				list =>
					$"((RuntimePointer<{GenerateType(list[2].Type.AsCompiletime())}>) ({GenerateExpression(list[1])})).value = {GenerateExpression(list[2])}");
			
			Expression("store-exclusive", _ => new EInt(false, 1).AsRuntime(), 
				list => $"CompareAndSwap(({GenerateType(list[2].Type)}*) ({GenerateExpression(list[1])}), {GenerateExpression(list[2])}, state->Exclusive{(list[2].Type is EInt(_, var sewidth) ? sewidth : throw new NotSupportedException())})", 
				list => $"CompareAndSwap((RuntimePointer<{GenerateType(list[2].Type.AsCompiletime())}>) ({GenerateExpression(list[1])}), {GenerateExpression(list[2])}, Exclusive{(list[2].Type is EInt(_, var sewidth) ? sewidth : throw new NotSupportedException())}R())");
		}
	}
}