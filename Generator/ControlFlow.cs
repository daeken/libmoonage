using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using MoreLinq.Extensions;

namespace Generator {
	class ControlFlow : Builtin {
		public override void Define() {
			Statement("requires", list => EType.Unit,
				(c, list) => {
					c += $"if({string.Join(" && ", list.Skip(1).Select(x => $"!({GenerateExpression(x)})"))})";
					c++;
					c += $"goto {Program.NextLabel};";
					c--;
				}).Interpret(
					(list, state) =>
						list.Skip(1).Select(x => state.Evaluate(x).AsBool()).Aggregate((a, b) => a && b)
							? true
							: throw new BailoutException());
			
			Statement("block", list => list.Last().Type,
				(c, list) => list.Skip(1).ForEach(x => GenerateStatement(c, (PList) x)))
				.Interpret((list, state) => state.Evaluate(list.Skip(1)));
			
			Expression("block", list => list.Last().Type, 
				list => $@"([=]() -> {GenerateType(list.Type)} {{
{string.Join('\n', list.Skip(1).Select((x, i) => {
					string code;
					if(x is PList xl) {
						var c = new CodeBuilder();
						GenerateStatement(c, xl);
						code = c.Code;
					} else
						code = GenerateExpression(x) + ";";
					if(i == list.Count - 2)
						return $"\t\treturn {code.Trim()}";
					return $"\t\t{code.Trim()}";
				}))}
	}})()", 
				list => $@"([=]() -> {GenerateType(list.Type)} {{
{string.Join('\n', list.Skip(1).Select((x, i) => {
					string code;
					if(x is PList xl) {
						var c = new CodeBuilder();
						GenerateStatement(c, xl);
						code = c.Code;
					} else
						code = GenerateExpression(x) + ";";
					if(i == list.Count - 2)
						return $"\t\treturn ({code.Trim().TrimEnd(';')}).Store();";
					return $"\t\t{code.Trim()}";
				}))}
	}})()").Interpret((list, state) => state.Evaluate(list.Skip(1)));

			Statement("if",
				list => list[2].Type.AsRuntime(list[1].Type.Runtime ||
				                               !(list[2].Type is EUnit) && list[2].Type.Runtime ||
				                               !(list[3].Type is EUnit) && list[3].Type.Runtime),
				(c, list) => {
					c += $"if(({GenerateExpression(list[1])}) != 0) {{";
					c++;
					GenerateStatement(c, (PList) list[2]);
					c--;
					c += "} else {";
					c++;
					GenerateStatement(c, (PList) list[3]);
					c--;
					c += "}";
				}, (c, list) => {
					if(list[1].Type.Runtime) {
						var if_label = TempName();
						var end_label = TempName();
						var else_label = TempName();
						c += $"LabelTag {if_label} = DefineLabel(), {else_label} = DefineLabel(), {end_label} = DefineLabel();";
						c += $"BranchIf({GenerateExpression(list[1])}, {if_label}, {else_label});";
						c += $"Label({if_label});";
						GenerateStatement(c, (PList) list[2]);
						c += $"Branch({end_label});";
						c += $"Label({else_label});";
						GenerateStatement(c, (PList) list[3]);
						c += $"Branch({end_label});";
						c += $"Label({end_label});";
					} else {
						c += $"if(({GenerateExpression(list[1])}) != 0) {{";
						c++;
						GenerateStatement(c, (PList) list[2]);
						c--;
						c += "} else {";
						c++;
						GenerateStatement(c, (PList) list[3]);
						c--;
						c += "}";
					}
				});
			
			Expression("if", list => list[2].Type, list => {
				var a = GenerateExpression(list[2]);
				var b = GenerateExpression(list[3]);
				if(!a.StartsWith("throw")) a = $"({a})";
				if(!b.StartsWith("throw")) b = $"({b})";
				return $"({GenerateExpression(list[1])} != 0) ? {a} : {b}";
			}, list => {
				var a = GenerateExpression(list[2]);
				var b = GenerateExpression(list[3]);
				
				if(list[1].Type.Runtime) {
					if(a.StartsWith("throw")) a = "null";
					if(b.StartsWith("throw")) b = "null";
					return $"Ternary<{GenerateType(list[1].Type.AsCompiletime())}, {GenerateType(list[2].Type.AsCompiletime())}>((RuntimeValue<{GenerateType(list[1].Type.AsCompiletime())}>) ({GenerateExpression(list[1])}), {a}, {b})";
				}
				
				if(!a.StartsWith("throw")) a = $"({a})";
				if(!b.StartsWith("throw")) b = $"({b})";
				return $"({GenerateExpression(list[1])}) != 0 ? {a} : {b}";
			});

			Interpret("if", (list, state) => state.Evaluate(list[1]).AsBool() ? state.Evaluate(list[2]) : state.Evaluate(list[3]));
			
			Statement("for", _ => EType.Unit,
				(c, list) => {
					if(!(list[1] is PList dlist) || !(dlist[0] is PName vname)) throw new NotSupportedException();
					int start = 0, end = 0, step = 1;
					var name = vname.Name;
					if(dlist.Count == 2) {
						if (!(dlist[1] is PInt ei)) throw new NotSupportedException();
						end = (int) ei.Value;
					} else if(dlist.Count == 3) {
						if (!(dlist[1] is PInt si) || !(dlist[2] is PInt ei)) throw new NotSupportedException();
						start = (int) si.Value;
						end = (int) ei.Value;
					} else if(dlist.Count == 4) {
						if(!(dlist[1] is PInt si) || !(dlist[2] is PInt ei) || !(dlist[3] is PInt ti))
							throw new NotSupportedException();
						start = (int) si.Value;
						end = (int) ei.Value;
						step = (int) ti.Value;
					}
					else
						throw new NotSupportedException();

					for(var i = start; i < end; i += step) {
						var pi = new PInt(i);
						pi.Type = new EInt(true, 32);
						list.Skip(2).ForEach(x => GenerateStatement(c, ((PList) x).MapLeaves(y => y is PName pn && pn.Name == name ? pi : y)));
					}
				}).Interpret((list, state) => {
					var rlist = (PList) list[1];
					var varName = ((PName) rlist[0]).Name;
					var range = rlist.Skip(1).Select(state.Evaluate).ToList();
					int start = 0, end = 0, step = 1;
					if(range.Count == 1)
						end = range[0];
					else if(range.Count == 2)
						(start, end) = (range[0], range[1]);
					else if(range.Count == 3)
						(start, end, step) = (range[0], range[1], range[2]);
					else
						throw new NotSupportedException();
					var hasPrevious = state.Locals.ContainsKey(varName);
					var preValue = hasPrevious ? state.Locals[varName] : null;
					for(var i = start; i < end; i += step) {
						state.Locals[varName] = i;
						state.Evaluate(list.Skip(2));
					}
					if(hasPrevious)
						state.Locals[varName] = preValue;
					else
						state.Locals.Remove(varName);
					return null;
				});
			
			Statement("when", _ => EType.Unit,
				(c, list) => {
					c += $"if(({GenerateExpression(list[1])}) != 0) {{";
					c++;
					list.Skip(2).ForEach(x => GenerateStatement(c, (PList) x));
					c--;
					c += "}";
				}, (c, list) => {
					if(list[1].Type.Runtime) {
						var if_label = TempName();
						var end_label = TempName();
						c += $"LabelTag {if_label} = DefineLabel(), {end_label} = DefineLabel();";
						c += $"BranchIf({GenerateExpression(list[1])}, {if_label}, {end_label});";
						c += $"Label({if_label});";
						list.Skip(2).ForEach(x => GenerateStatement(c, (PList) x));
						c += $"Branch({end_label});";
						c += $"Label({end_label});";
					} else {
						c += $"if(({GenerateExpression(list[1])}) != 0) {{";
						c++;
						list.Skip(2).ForEach(x => GenerateStatement(c, (PList) x));
						c--;
						c += "}";
					}
				}).Interpret((list, state) => state.Evaluate(list[1]).AsBool() ? state.Evaluate(list[2]) : null);
			
			Statement("match", list => list.Count == 3 ? list[2].Type : list[3].Type,
				(c, list) => {
					c += $"switch({GenerateExpression(list[1])}) {{";
					c++;
					for(var i = 2; i < list.Count; i += 2)
						if(i + 1 == list.Count) {
							c += "default: {";
							c++;
							GenerateStatement(c, (PList) list[i]);
							c += "break;";
							c--;
							c += "}";
						} else {
							c += $"case {GenerateExpression(list[i])}: {{";
							c++;
							GenerateStatement(c, (PList) list[i + 1]);
							c += "break;";
							c--;
							c += "}";
						}
					c--;
					c += "}";
				});

			string GenerateReturn(string expr) => expr.StartsWith("throw ") ? expr : $"return {expr}";

			Expression("match", list => list.Count == 3 ? list[2].Type : list[3].Type,
				list => {
					var opts = new List<string>();
					for(var i = 2; i < list.Count; i += 2)
						opts.Add(i + 1 == list.Count
							? $"default: {GenerateReturn(GenerateExpression(list[i]))};"
							: $"case {GenerateExpression(list[i])}: {GenerateReturn(GenerateExpression(list[i + 1]))};");
					var tn = TempName();
					return $"([=](auto {tn}) -> {GenerateType(list.Count == 3 ? list[2].Type : list[3].Type)} {{ switch({tn}) {{ {string.Join(" ", opts)} }} }})({GenerateExpression(list[1])})";
				}, list => {
					string Expr(PTree expr) {
						var str = GenerateExpression(expr);
						return str.StartsWith("throw ") ? str : $"({GenerateType(list.Type)}) ({str})";
					}
					var opts = new List<string>();
					for(var i = 2; i < list.Count; i += 2)
						opts.Add(i + 1 == list.Count
							? $"default: {GenerateReturn(GenerateExpression(list[i]))};"
							: $"case {GenerateExpression(list[i])}: {GenerateReturn(Expr(list[i + 1]))};");
					var tn = TempName();
					return $"([=](auto {tn}) -> {GenerateType(list.Count == 3 ? list[2].Type : list[3].Type)} {{ switch({tn}) {{ {string.Join(" ", opts)} }} }})({GenerateExpression(list[1])})";
				});

			Interpret("match", (list, state) => {
				var mv = state.Evaluate(list[1]);
				for(var i = 2; i < list.Count; i += 2) {
					if(i + 1 < list.Count) {
						var cv = state.Evaluate(list[i]);
						var mcond = false;
						try {
							mcond = cv == mv;
						} catch(Exception) {
							mcond = (ulong) cv == (ulong) mv;
						}
						if(mcond)
							return state.Evaluate(list[i + 1]);
					} else
						return state.Evaluate(list[i]);
				}
				throw new BailoutException(); // This can only be hit if nothing matches and there's no default case
			});

			Expression("svc", _ => EType.Unit.AsRuntime(),
				list => $"Svc({GenerateExpression(list[1])})",
				list => $"CallSvc({GenerateExpression(list[1])})")
				.NoInterpret();
			
			Expression("branch", _ => EType.Unit.AsRuntime(), list => $"Branch({GenerateExpression(list[1])})");
			Expression("branch-linked", _ => EType.Unit.AsRuntime(), list => $"BranchLinked({GenerateExpression(list[1])})");
			Expression("branch-linked-register", _ => EType.Unit.AsRuntime(), list => $"BranchLinkedRegister({GenerateExpression(list[1])})");
			Expression("branch-register", _ => EType.Unit.AsRuntime(), list => $"BranchRegister({GenerateExpression(list[1])})");
			Expression("branch-default", _ => EType.Unit.AsRuntime(), list => "Branch(pc + 4)");
			
			Expression("unimplemented", _ => EType.Unit, _ => "throw \"Not implemented\"").NoInterpret();
		}
	}
}