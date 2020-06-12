using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using MoreLinq;
using PrettyPrinter;

namespace Arch {
	public enum ContextTypes {
		Disassembler, 
		Interpreter, 
		Recompiler
	}
	
	public class Capture {
		public static readonly List<Capture> UnassignedCaptures = new List<Capture>();
		public readonly string Name, RawName;
		readonly Action<Func<PList, ExecutionState, dynamic>> Assign;

		public Capture(string type, string name, Action<Func<PList, ExecutionState, dynamic>> assign) {
			var st = new StackTrace();
			var frame = st.GetFrame(2);
			var method = frame?.GetMethod() ?? throw new Exception();
			RawName = name;
			Name = type + " " + name + " in " + method.DeclaringType.Name;
			Assign = assign;
			UnassignedCaptures.Add(this);
		}
		
		public void Interpret(Func<PList, ExecutionState, dynamic> func) {
			UnassignedCaptures.Remove(this);
			Assign(func);
		}

		public void NoInterpret() {
			UnassignedCaptures.Remove(this);
			Assign((_, __) => throw new BailoutException());
		}
	}

	public abstract class Builtin {
		public static EType TypeFromName(PTree expr) {
			if(!(expr is PName name)) throw new NotSupportedException($"Attempted to make type from expr {expr.ToPrettyString()}");

			var ns = name.Name;
			if(ns[0] == 'f') return new EFloat(int.Parse(ns.Substring(1)));
			if(ns == "vec") return EType.Vector;
			return ns[0] == 'i' ? new EInt(true, int.Parse(ns.Substring(1))) : new EInt(false, int.Parse(ns.Substring(1)));
		}
		
		public static Capture Statement(string name, Func<PList, EType> signature, Action<CodeBuilder, PList> compiletime, Action<CodeBuilder, PList> runtime = null) {
			if(Core.Statements.ContainsKey(name)) throw new Exception();
			return new Capture("Statement", name, func => Core.Statements[name] = (signature, compiletime, runtime ?? compiletime, func));
		}
		public static Capture Expression(string name, Func<PList, EType> signature, Func<PList, string> compiletime, Func<PList, string> runtime = null) {
			if(Core.Expressions.ContainsKey(name)) throw new Exception();
			return new Capture("Expression", name, func => Core.Expressions[name] = (signature, compiletime, runtime ?? compiletime, func));
		}
		public static Capture Expression(IEnumerable<string> names, Func<PList, EType> signature, Func<PList, string> compiletime, Func<PList, string> runtime = null) {
			var nameList = names.ToList();
			return new Capture("Expressions", $"[ {string.Join(" ", nameList)} ]",
				func => MoreEnumerable.ForEach(nameList, name => Expression(name, signature, compiletime, runtime).Interpret(func)));
		}

		public static void Interpret(string name, Func<PList, ExecutionState, dynamic> func) {
			var captures = Capture.UnassignedCaptures.Where(x => x.RawName == name).ToList();
			Debug.Assert(captures.Count != 0);
			foreach(var capture in captures)
				capture.Interpret(func);
		}

		public static string TempName() => Core.TempName();

		public static string GenerateType(EType type) => Core.GenerateType(type);
		public static string GenerateExpression(PTree expr, bool lhs = false) => Core.GenerateExpression(expr, lhs);

		public static void GenerateStatement(CodeBuilder c, PList list) => Core.GenerateStatement(c, list);
		
		public abstract void Define();
	}

	public class Core {
		public static string NextLabel;

		public static readonly Dictionary<string, (Func<PList, EType> Signature, Action<CodeBuilder, PList> CompileTime,
			Action<CodeBuilder, PList> RunTime, Func<PList, ExecutionState, dynamic> Execute)>
			Statements =
				new Dictionary<string, (Func<PList, EType> Signature, Action<CodeBuilder, PList> CompileTime,
					Action<CodeBuilder, PList> RunTime, Func<PList, ExecutionState, dynamic> Execute)>();

		public static readonly Dictionary<string, (Func<PList, EType> Signature, Func<PList, string> CompileTime,
			Func<PList, string> RunTime, Func<PList, ExecutionState, dynamic> Execute)>
			Expressions =
				new Dictionary<string, (Func<PList, EType> Signature, Func<PList, string> CompileTime,
					Func<PList, string> RunTime, Func<PList, ExecutionState, dynamic>)>();

		public static void InferList(PList list) {
			switch(list[0]) {
				case PName(var name) when Statements.ContainsKey(name):
					foreach(var elem in list.Skip(1))
						if(elem is PList sublist)
							InferList(sublist);
					list.Type = Statements[name].Signature(list);
					break;
				default:
					InferExpression(list);
					break;
			}
		}

		public static EType InferExpression(PTree tree) {
			if(tree.Type.Runtime) return tree.Type;
			switch(tree) {
				case PList list:
					var set = false;
					foreach(var elem in list)
						if(InferExpression(elem).Runtime)
							set = true;
					return list.Type = set ? list.Type.AsRuntime() : list.Type;
				default:
					return tree.Type;
			}
		}
		
		public static Def InferRuntime(Def def) {
			InferList(def.Decode);
			InferList(def.Eval);
			return def;
		}

		public static readonly List<Def> Defs;

		static Core() {
			MoreEnumerable.ForEach(AppDomain.CurrentDomain.GetAssemblies().SelectMany(x => x.GetTypes())
				.Where(x => x.IsSubclassOf(typeof(Builtin))), x => ((Builtin) Activator.CreateInstance(x)).Define());

			if(Capture.UnassignedCaptures.Count != 0) {
				Console.WriteLine("The following captures have not been assigned:");
				foreach(var capture in Capture.UnassignedCaptures)
					Console.WriteLine($"- {capture.Name}");
				Console.WriteLine("---Press Enter To Continue---");
				Console.ReadLine();
				//return;
				while(Capture.UnassignedCaptures.Count != 0)
					foreach(var capture in Capture.UnassignedCaptures) {
						capture.Interpret((_, __) => throw new NotImplementedException(capture.Name));
						break;
					}
			}
			
			var ptree = ListParser.Parse(File.ReadAllText("/Users/daeken/projects/libmoonage/Generator/aarch64.isa")); // TODO: Figure out a saner approach
			ptree = MacroProcessor.Rewrite(ptree);
			var es = ExecutionState.Cleanroom();
			foreach(var tle in ptree) {
				try {
					es.Evaluate(tle);
				} catch(BailoutException) {}
			}
			Defs = Def.ParseAll(ptree).Select(InferRuntime).ToList();
		}
		
		public static ContextTypes Context;
		static int TempI;

		public static string TempName() => $"temp_{TempI++}";

		public static void GenerateFields(CodeBuilder c, Def def) {
			foreach(var field in def.Fields)
				c += $"auto {field.Key} = (inst >> {field.Value.Shift}) & 0x{(1 << field.Value.Bits) - 1:X}U;";
		}

		public static void GenerateStatement(CodeBuilder c, PList list) {
			if(Context == ContextTypes.Recompiler && list.Type.Runtime) {
				GenerateRuntimeStatement(c, list);
				return;
			}

			switch(list[0]) {
				case PName(var name) when Statements.ContainsKey(name):
					Statements[name].CompileTime(c, list);
					break;
				case PName name:
					c += $"{GenerateExpression(list)};";
					break;
				default:
					throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		public static void GenerateRuntimeStatement(CodeBuilder c, PList list) {
			Debug.Assert(Context == ContextTypes.Recompiler);
			switch(list[0]) {
				case PName(var name) when Statements.ContainsKey(name):
					Statements[name].RunTime(c, list);
					break;
				case PName name:
					c += $"{GenerateExpression(list)};";
					break;
				default:
					throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		public static string ToHex(long value) => value < 0 ? $"-0x{-value:X}" : $"0x{value:X}";

		public static string GenerateExpression(PTree v, bool lhs = false) {
			switch(v) {
				case PName name: return name.Name;
				case PInt value: return ((EInt) value.Type).Signed ? ToHex(value.Value) : ToHex(value.Value) + "U";
				case PString str: return $"string({str.String.ToPrettyString()})";
				case PList list: return GenerateListExpression(list, lhs: lhs);
				default: throw new NotImplementedException();
			}
		}

		public static string GenerateType(EType type) {
			string __GenerateType() {
				switch(type) {
					case null: return "void";
					case EUnit _: return "void";
					case EString _: return "string";
					case EInt i:
						switch(i.Width) {
							case int x when x == 1: return "bool";
							case int x when x > 64: return i.Signed ? "Int128" : "UInt128";
							case int x when x > 32: return i.Signed ? "long" : "ulong";
							case int x when x > 16: return i.Signed ? "int" : "uint";
							case int x when x > 8: return i.Signed ? "short" : "ushort";
							default: return i.Signed ? "sbyte" : "byte";
						}
					case EFloat f:
						switch(f.Width) {
							case int x when x > 64: return "Vector128<float>";
							case int x when x > 32: return "double";
							default: return "float";
						}
					case EVector _: return "Vector128<float>";
					default: throw new NotImplementedException($"Type {type.ToString()}");
				}
			}

			return Context == ContextTypes.Recompiler && type.Runtime
				? $"RuntimeValue<{__GenerateType()}>"
				: __GenerateType();
		}

		public static string GenerateListExpression(PList list, bool lhs = false) {
			if(Context == ContextTypes.Recompiler && list.Type.Runtime) {
				var expr = GenerateBaseListRuntimeExpression(list);
				return lhs || list.Type is EUnit ? expr : $"({GenerateType(list.Type)}) ({expr})";
			} else {
				var expr = GenerateBaseListExpression(list);
				return lhs || list.Type is EUnit ? expr : $"({GenerateType(list.Type)}) ({expr})";
			}
		}

		public static string GenerateBaseListExpression(PList list) {
			switch(list[0]) {
				case PName name when Expressions.ContainsKey(name): return Expressions[name].CompileTime(list);
				case PName name: throw new NotImplementedException($"Unknown name for GenerateListExpression: {name}");
				default: throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		public static string GenerateBaseListRuntimeExpression(PList list) {
			Debug.Assert(Context == ContextTypes.Recompiler);
			switch(list[0]) {
				case PName name when Expressions.ContainsKey(name): return Expressions[name].RunTime(list);
				case PName name:
					throw new NotImplementedException($"Unknown name for GenerateRuntimeListExpression: {name}");
				default: throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}
	}
}