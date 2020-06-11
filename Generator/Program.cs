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
			if(Program.Statements.ContainsKey(name)) throw new Exception();
			return new Capture("Statement", name, func => Program.Statements[name] = (signature, compiletime, runtime ?? compiletime, func));
		}
		public static Capture Expression(string name, Func<PList, EType> signature, Func<PList, string> compiletime, Func<PList, string> runtime = null) {
			if(Program.Expressions.ContainsKey(name)) throw new Exception();
			return new Capture("Expression", name, func => Program.Expressions[name] = (signature, compiletime, runtime ?? compiletime, func));
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

		public static string TempName() => Program.TempName();

		public static string GenerateType(EType type) => Program.GenerateType(type);
		public static string GenerateExpression(PTree expr, bool lhs = false) => Program.GenerateExpression(expr, lhs);

		public static void GenerateStatement(CodeBuilder c, PList list) => Program.GenerateStatement(c, list);
		
		public abstract void Define();
	}

	static class Program {
		public static string NextLabel;

		static void Main(string[] args) {
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
			
			var ptree = ListParser.Parse(File.ReadAllText("aarch64.isa"));
			ptree = MacroProcessor.Rewrite(ptree);
			var es = ExecutionState.Cleanroom();
			foreach(var tle in ptree) {
				try {
					es.Evaluate(tle);
				} catch(BailoutException) {}
			}
			var defs = Def.ParseAll(ptree).Select(InferRuntime).ToList();
			if(args.Length == 0 || args[0] != "tests") {
				BuildDisassembler(defs);
				BuildInterpreter(defs);
				BuildRecompiler(defs);
			} else
				BuildTests(defs);
		}

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
					default: throw new NotImplementedException($"Type {type.ToString()}");
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
				case PName name when Expressions.ContainsKey(name): return Expressions[name].CompileTime(list);
				case PName name: throw new NotImplementedException($"Unknown name for GenerateListExpression: {name}");
				default: throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		static string GenerateBaseListRuntimeExpression(PList list) {
			Debug.Assert(Context == ContextTypes.Recompiler);
			switch(list[0]) {
				case PName name when Expressions.ContainsKey(name): return Expressions[name].RunTime(list);
				case PName name:
					throw new NotImplementedException($"Unknown name for GenerateRuntimeListExpression: {name}");
				default: throw new NotSupportedException($"Non-name for first element of list {list.ToPrettyString()}");
			}
		}

		static void BuildDisassembler(List<Def> defs) {
			Context = ContextTypes.Disassembler;

			var c = new CodeBuilder();
			c += 1;
			var ic = new CodeBuilder();
			ic += 1;

			var labelNum = 0;

			foreach(var def in defs) {
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
									return $"%{args.Count - 1}%0x%{args.Count}$#x";
								} else {
									args.Add(name);
									return $"0x%{args.Count}$#x";
								}
							} else if(def.Locals[name] is EInt(var ssigned, var ssize) && ssize == 8) {
								args.Add((ssigned ? "(int16_t) " : "(uint16_t) ") + name);
								return $"%{args.Count}%";
							}

							//if(def.Locals[name] is EInt(var signed, var size) && size > 8)
							//	return signed ? $"{{({name} < 0 ? $\"-0x{{-{name}:X}}\" : $\"0x{{{name}:X}}\")}}" : $"0x{{{name}:X}}";
							args.Add(name);
							return $"%{args.Count}%";
						});

				NextLabel = $"insn_{++labelNum}";
				c += $"/* {def.Name} */";
				c += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				ic += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				c++;
				ic++;
				GenerateFields(c, def);
				GenerateStatement(c, def.Decode);
				GenerateFields(ic, def);
				GenerateStatement(ic, def.Decode);
				ic += $"return \"{def.Name}\";";
				var line = $"return (boost::format(\"{RewriteFormat(def.Disassembly)}\")";
				foreach(var arg in args)
					line += " % " + arg;
				c += line + ").str();";
				c--;
				ic--;
				c += "}";
				ic += "}";
				c += $"{NextLabel}:";
				ic += $"{NextLabel}:";
			}

			using var fp = File.Open("../disassembler.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("disassemblerStub.cpp")
				.Replace("/*%D_CODE%*/", c.Code)
				.Replace("/*%IC_CODE%*/", ic.Code)
				.Replace("/*%IC_COUNT%*/", defs.Count.ToString()));
		}

		static void BuildInterpreter(List<Def> defs) {
			Context = ContextTypes.Interpreter;

			var c = new CodeBuilder();
			c += 1;
			var labelNum = 0;

			foreach(var def in defs) {
				NextLabel = $"insn_{++labelNum}";
				c += $"/* {def.Name} */";
				c += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				c++;
				GenerateFields(c, def);
				GenerateStatement(c, def.Decode);
				GenerateStatement(c, def.Eval);
				c += "return true;";
				c--;
				c += "}";
				c += $"{NextLabel}:";
			}

			using var fp = File.Open("../interpreter.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("interpreterStub.cpp").Replace("/*%CODE%*/", c.Code));
		}

		static void BuildRecompiler(List<Def> defs) {
			string Rename(string name) => name.Replace('-', '_').Replace('.', '_').Replace('[', '_').Replace(']', '_');
			Context = ContextTypes.Recompiler;

			var c = new CodeBuilder();
			c++;

			foreach(var def in defs) {
				c += $"if((inst & 0x{def.Mask:X8}U) == 0x{def.Match:X8}U) {{";
				c++;
				//c += $"printf(\"Instruction: {def.Name}\\n\");";
				c += $"if({Rename(def.Name)}(inst, pc)) return true;";
				c--;
				c += "}";
			}

			var fc = new CodeBuilder();

			var dfp = File.Open("../recompiler.generated.h", FileMode.Truncate);
			var dsw = new StreamWriter(dfp);
			foreach(var def in defs) {
				NextLabel = "unimplemented";
				fc += "";
				fc += $"/* {def.Name} */";
				fc += $"bool Recompiler::{Rename(def.Name)}(uint inst, ulong pc) {{";
				dsw.WriteLine($"bool {Rename(def.Name)}(uint inst, ulong pc);");
				fc++;
				fc += "{";
				fc++;
				GenerateFields(fc, def);
				GenerateStatement(fc, def.Decode);
				GenerateStatement(fc, def.Eval);
				fc += "return true;";
				fc--;
				fc += "}";
				fc--;
				fc += "unimplemented:";
				fc++;
				fc += "return false;";
				fc--;
				fc += "}";
			}

			using var fp = File.Open("../recompiler.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("recompilerStub.cpp").Replace("/*%CODE%*/", c.Code)
				.Replace("/*%FUNCS%*/", fc.Code));
			dsw.Close();
		}

		static void BuildTests(List<Def> defs) {
			using var fp = File.Open("../test_instructions.generated.h", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			var found = false;
			foreach(var def in defs) {
				if(def.Fields.Count == 0) continue;
				if(!found && def.Name != "LDP-simd-postindex")
					continue;
				found = true;
				var miss = false;
				if(def.Name.StartsWith("LD") || def.Name.StartsWith("ST")) miss = true;
				if(def.Name.StartsWith("SVC") || def.Name.StartsWith("BRK")) miss = true;
				if(def.Name.StartsWith("MSR") || def.Name.StartsWith("MRS")) miss = true;
				if(def.Name.StartsWith("CAS")) continue;

				if(!miss) continue;

				if(def.Eval.WalkLeaves<string>(tree => tree is PName pn && pn.Name.StartsWith("branch") ? "" : null) !=
				   null) continue;
				
				var tg = new TestGen(def);
				if(tg.Instructions.Count == 0) continue;
				
				sw.WriteLine($"/* {def.Name} */");
				foreach(var (inst, disasm) in tg.Instructions.OrderBy(x => x.Value))
					sw.WriteLine($"TEST_INSTRUCTION(0x{inst:X08}, {disasm.ToPrettyString()})");
			}
		}
	}
}