using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using Arch;
using PrettyPrinter;
using MoreLinq;

namespace Generator {
	class Program : Core {
		static void Main(string[] args) {
			BuildDisassembler(Defs);
			BuildInterpreter(Defs);
			BuildLightRecompiler(Defs);
			BuildRecompiler(Defs);
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
				.Replace("/*%FUNCS%*/", fc.Code.Replace("LlvmRuntimeValue", "LlvmRuntimeValue").Replace("RuntimePointer", "LlvmRuntimePointer")));
			dsw.Close();
		}
		
		static void BuildLightRecompiler(List<Def> defs) {
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

			foreach(var def in defs) {
				NextLabel = "unimplemented";
				fc += "";
				fc += $"/* {def.Name} */";
				fc += $"bool LightRecompiler::{Rename(def.Name)}(uint inst, ulong pc) {{";
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

			using var fp = File.Open("../lightRecompiler.generated.cpp", FileMode.Truncate);
			using var sw = new StreamWriter(fp);
			sw.Write(File.ReadAllText("lightRecompilerStub.cpp").Replace("/*%CODE%*/", c.Code)
				.Replace("/*%FUNCS%*/", fc.Code.Replace("LlvmRuntimeValue", "LightRuntimeValue").Replace("RuntimePointer", "LightRuntimePointer").Replace("LabelTag", "LightLabel")));
		}
	}
}