using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using PrettyPrinter;
using MoreLinq;

namespace Generator {
	enum ContextTypes {
		Disassembler, 
		Interpreter, 
		Recompiler
	}

	public abstract class Builtin {
		public static EType TypeFromName(PTree expr) {
			if(!(expr is PName name)) throw new NotSupportedException($"Attempted to make type from expr {expr.ToPrettyString()}");

			var ns = name.Name;
			if(ns[0] == 'f') return new EFloat(int.Parse(ns.Substring(1)));
			if(ns == "vec") return EType.Vector;
			return ns[0] == 'i' ? new EInt(true, int.Parse(ns.Substring(1))) : new EInt(false, int.Parse(ns.Substring(1)));
		}
		
		public static void Statement(string name, Func<PList, EType> signature, Action<CodeBuilder, PList> compiletime, Action<CodeBuilder, PList> runtime = null) {
			if(Program.Statements.ContainsKey(name)) throw new Exception();
			Program.Statements[name] = (signature, compiletime, runtime ?? compiletime);
		}
		public static void Expression(string name, Func<PList, EType> signature, Func<PList, string> compiletime, Func<PList, string> runtime = null) {
			if(Program.Expressions.ContainsKey(name)) throw new Exception();
			Program.Expressions[name] = (signature, compiletime, runtime ?? compiletime);
		}
		public static void Expression(IEnumerable<string> names, Func<PList, EType> signature, Func<PList, string> compiletime, Func<PList, string> runtime = null) =>
			names.ForEach(name => Expression(name, signature, compiletime, runtime));

		public static string TempName() => Program.TempName();

		public static string GenerateType(EType type) => Program.GenerateType(type);
		public static string GenerateExpression(PTree expr, bool lhs = false) => Program.GenerateExpression(expr, lhs);

		public static void GenerateStatement(CodeBuilder c, PList list) => Program.GenerateStatement(c, list);
		
		public abstract void Define();
	}
	
	static class Program {
		static void Main(string[] args) {
			AppDomain.CurrentDomain.GetAssemblies().SelectMany(x => x.GetTypes())
				.Where(x => x.IsSubclassOf(typeof(Builtin)))
				.ForEach(x => ((Builtin) Activator.CreateInstance(x)).Define());
			
			var ptree = ListParser.Parse(File.ReadAllText("aarch64.isa"));
			ptree = MacroProcessor.Rewrite(ptree);
			var defs = Def.ParseAll(ptree).Select(InferRuntime).ToList();
			BuildDisassembler(defs);
			BuildInterpreter(defs);
			BuildRecompiler(defs);
		}

		public static readonly Dictionary<string, (Func<PList, EType> Signature, Action<CodeBuilder, PList> CompileTime, Action<CodeBuilder, PList> RunTime)>
			Statements = new Dictionary<string, (Func<PList, EType> Signature, Action<CodeBuilder, PList> CompileTime, Action<CodeBuilder, PList> RunTime)>();
		public static readonly Dictionary<string, (Func<PList, EType> Signature, Func<PList, string> CompileTime, Func<PList, string> RunTime)>
			Expressions = new Dictionary<string, (Func<PList, EType> Signature, Func<PList, string> CompileTime, Func<PList, string> RunTime)>();

		static Def InferRuntime(Def def) {
			void InferList(PList list) {
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

			EType InferExpression(PTree tree) {
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

			InferList(def.Decode);
			InferList(def.Eval);
			return def;
		}

		static ContextTypes Context;
		static int TempI;

		public static string TempName() => $"temp_{TempI++}";

		static void GenerateFields(CodeBuilder c, Def def) {
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

		static void GenerateRuntimeStatement(CodeBuilder c, PList list) {
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

		static string ToHex(long value) => value < 0 ? $"-0x{-value:X}" : $"0x{value:X}";
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
					default: throw new NotImplementedException();
				}
			}

			return Context == ContextTypes.Recompiler && type.Runtime
				? $"RuntimeValue<{__GenerateType()}>"
				: __GenerateType();
		}

		static string GenerateListExpression(PList list, bool lhs = false) {
			if(Context == ContextTypes.Recompiler && list.Type.Runtime) {
				var expr = GenerateBaseListRuntimeExpression(list);
				return lhs || list.Type is EUnit ? expr : $"({GenerateType(list.Type)}) ({expr})";
			} else {
				var expr = GenerateBaseListExpression(list);
				return lhs || list.Type is EUnit ? expr : $"({GenerateType(list.Type)}) ({expr})";
			}
		}

		static string GenerateBaseListExpression(PList list) {
			switch(list[0]) {
				case PName("count-leading-zeros"): return $"CountLeadingZeros({GenerateExpression(list[1])})";
				case PName("reverse-bits"): return $"ReverseBits({GenerateExpression(list[1])})";
				case PName("make-tmask"):
					return $"MakeTMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})";
				case PName("make-wmask"):
					return $"MakeWMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})";
				
				case PName("vector-all"): return $"reinterpret_cast<Vector128<float>>(({GenerateExpression(list[1])}) - (Vector128<{GenerateType(list[1].Type)}>) {{}})";
				case PName("vector-zero-top"): return GenerateExpression(list[1]);
				case PName("vector-insert"): return $"reinterpret_cast<Vector128<{GenerateType(list[3].Type)}>*>(&(State->V[(int) ({GenerateExpression(list[1])})]))[{GenerateExpression(list[2])}] = {GenerateExpression(list[3])}";
				case PName("vector-element"):
					return $"reinterpret_cast<Vector128<{GenerateType(list.Type.AsCompiletime())}>>({GenerateExpression(list[1])})[{GenerateExpression(list[2])}]";
				case PName("vector-count-bits"): return $"VectorCountBits({GenerateExpression(list[1])}, {GenerateExpression(list[2])})";
				case PName("vector-sum-unsigned"): return $"VectorSumUnsigned({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])})";
				case PName("vector-extract"): return $"VectorExtract({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])})";
				
				case PName("float-to-fixed-point"): return $"FloatToFixed{((EInt) list.Type).Width}({GenerateExpression(list[1])}, (int) ({GenerateExpression(list[3])}))";
				
				case PName name when Expressions.ContainsKey(name): return Expressions[name].CompileTime(list);
				case PName name: throw new NotImplementedException($"Unknown name for GenerateListExpression: {name}");
				default: throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		static string GenerateBaseListRuntimeExpression(PList list) {
			Debug.Assert(Context == ContextTypes.Recompiler);
			switch(list[0]) {
				case PName("count-leading-zeros"): return $"Call<{GenerateType(list[1].Type.AsCompiletime())}, {GenerateType(list[1].Type.AsCompiletime())}>(CountLeadingZeros, {GenerateExpression(list[1])})";
				case PName("reverse-bits"): return $"Call<{GenerateType(list[1].Type.AsCompiletime())}, {GenerateType(list[1].Type.AsCompiletime())}>(ReverseBits, {GenerateExpression(list[1])})";
				case PName("make-tmask"):
					return $"MakeTMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})";
				case PName("make-wmask"):
					return $"MakeWMask({GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[5])}, {GenerateExpression(list[4])})";
				
				case PName("vector-all"):
					return $"(({GenerateType(list[1].Type.AsRuntime())}) ({GenerateExpression(list[1])})).CreateVector()";
				case PName("vector-zero-top"): return GenerateExpression(list[1]);
				
				case PName("vector-insert"):
					return $"VR[(int) ({GenerateExpression(list[1])})] = VR[(int) ({GenerateExpression(list[1])})]().Insert({GenerateExpression(list[2])}, {GenerateExpression(list[3])})";
				case PName("vector-element"):
					return $"({GenerateExpression(list[1])}).Element<{GenerateType(list.Type.AsCompiletime())}>({GenerateExpression(list[2])})";
				
				case PName("vector-count-bits"): return $"Call<Vector128<float>, Vector128<float>, long>(VectorCountBits, {GenerateExpression(list[1])}, {GenerateExpression(list[2])})";
				case PName("vector-sum-unsigned"): return $"Call<ulong, Vector128<float>, long, long>(VectorSumUnsigned, {GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])})";
				case PName("vector-extract"): return $"Call<Vector128<float>, Vector128<float>, Vector128<float>, uint, uint>(VectorExtract, {GenerateExpression(list[1])}, {GenerateExpression(list[2])}, {GenerateExpression(list[3])}, {GenerateExpression(list[4])})";
				
				case PName("float-to-fixed-point"): return $"Call<{(((EInt) list.Type).Width == 64 ? "ulong" : "uint")}, {GenerateType(list[1].Type.AsCompiletime())}, int>(FloatToFixed{((EInt) list.Type).Width}, {GenerateExpression(list[1])}, (RuntimeValue<int>) ({GenerateExpression(list[3])}))";
				
				case PName name when Expressions.ContainsKey(name): return Expressions[name].RunTime(list);
				case PName name: throw new NotImplementedException($"Unknown name for GenerateRuntimeListExpression: {name}");
				default: throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		static void BuildDisassembler(List<Def> defs) {
			Context = ContextTypes.Disassembler;
			
			var c = new CodeBuilder();
			c += 1;
			
			foreach(var def in defs) {
				Console.WriteLine(def.Name + "...");
				var args = new List<string>();
				string RewriteFormat(string fmt) =>
					Regex.Replace(fmt, @"\$(\$|[a-zA-Z\-][a-zA-Z\-0-9]*)", 
						match => {
							if(match.Groups[1].Value == "$$")
								return "$";
							var name = match.Groups[1].Value;
							if(def.Locals[name] is EInt(var signed, var size) && size > 8) {
								if(signed) {
									args.Add($"(({name}) < 0 ? \"-\" : \"\")");
									args.Add($"(({name}) < 0 ? -({name}) : ({name}))");
									return $"%{args.Count - 1}%%{args.Count}$#x";
								} else {
									args.Add(name);
									return $"%{args.Count}$#x";
								}
							}
							//if(def.Locals[name] is EInt(var signed, var size) && size > 8)
							//	return signed ? $"{{({name} < 0 ? $\"-0x{{-{name}:X}}\" : $\"0x{{{name}:X}}\")}}" : $"0x{{{name}:X}}";
							args.Add(name);
							return $"%{args.Count}%";
						});
				
				c += $"/* {def.Name} */";
				c += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				c++;
				GenerateFields(c, def);
				GenerateStatement(c, def.Decode);
				var line = $"return (boost::format(\"{RewriteFormat(def.Disassembly)}\")";
				foreach(var arg in args)
					line += " % " + arg;
				c += line + ").str().c_str();";
				c--;
				c += "}";
			}
			
			using var fp = File.Open("../disassembler.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("disassemblerStub.cpp").Replace("/*%CODE%*/", c.Code));
		}
		
		static void BuildInterpreter(List<Def> defs) {
			Context = ContextTypes.Interpreter;
			
			var c = new CodeBuilder();
			c += 1;
			
			foreach(var def in defs) {
				c += $"/* {def.Name} */";
				c += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				c++;
				GenerateFields(c, def);
				GenerateStatement(c, def.Decode);
				GenerateStatement(c, def.Eval);
				c += "return true;";
				c--;
				c += "}";
			}

			using var fp = File.Open("../interpreter.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("interpreterStub.cpp").Replace("/*%CODE%*/", c.Code));
		}
		
		static void BuildRecompiler(List<Def> defs) {
			Context = ContextTypes.Recompiler;
			
			var c = new CodeBuilder();
			c += 1;
			
			foreach(var def in defs) {
				c += $"/* {def.Name} */";
				c += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				c++;
				GenerateFields(c, def);
				GenerateStatement(c, def.Decode);
				GenerateStatement(c, def.Eval);
				c += "return true;";
				c--;
				c += "}";
			}
			
			using var fp = File.Open("../recompiler.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("recompilerStub.cpp").Replace("/*%CODE%*/", c.Code));
		}
	}
}