using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using PrettyPrinter;
using MoreLinq;

namespace Generator {
	public class Def {
		public static List<Def> ParseAll(PList top) => top.Where(x => ((PList) x)[0] is PName("def")).Select(x => new Def((PList) x)).ToList();
		
		public readonly string Name;
		public readonly uint Mask, Match;
		public readonly string Disassembly;
		public readonly IReadOnlyDictionary<string, EType> Locals;
		public readonly IReadOnlyDictionary<string, (int Bits, int Shift)> Fields;
		public readonly PList Decode, Eval;

		public Def(PList def) {
			if(!(def[0] is PName("def"))) throw new Exception();
			if(!(def[1] is PName name)) throw new Exception();
			if(!(def[2] is PString bitstr)) throw new Exception();
			if(!(def[3] is PString disasm)) throw new Exception();
			if(!(def[4] is PList names)) throw new Exception();
			if(!(def[5] is PList decode)) throw new Exception();
			if(!(def[6] is PList eval)) throw new Exception();
			
			Name = name;
			Disassembly = disasm;

			var fieldNames = names.Skip(1).Select(x => (PList) x)
				.Select(x => (((PName) x[1]).Name, ((PName) x[0]).Name)).ToDictionary();

			var fields = new Dictionary<string, (int, int)>();
			var mask = 0U;
			var match = 0U;
			name.Print();
			var bitstring = bitstr.String.Replace(" ", "");
			Debug.Assert(bitstring.Length == 32);
			for(var i = 0; i < 32; ++i) {
				var bit = 31 - i;
				mask <<= 1;
				match <<= 1;
				switch(bitstring[i]) {
					case '0':
						mask |= 1;
						break;
					case '1':
						mask |= 1;
						match |= 1;
						break;
					case char x:
						var field = fieldNames[x.ToString()];
						fields[field] = fields.ContainsKey(field) ? (fields[field].Item1 + 1, bit) : (1, bit);
						break;
				}
			}

			Mask = mask;
			Match = match;
			Fields = fields;

			Decode = decode;
			Eval = eval;

			var locals = new Dictionary<string, EType>();
			foreach(var (fname, (bits, _)) in Fields)
				locals[fname] = new EInt(false, bits);
			void InferList(PList list) => list.Skip(1).ForEach(x => InferType(x));

			EType InferType(PTree tree) => tree.Type is EUndef ? tree.Type = _InferType(tree) : tree.Type;
			EType _InferType(PTree tree) {
				switch(tree) {
					case PList list:
						switch(((PName) list[0]).Name) {
							case "block":
								InferList(list);
								return list.Last().Type;
							case "for":
								locals[((PName) ((PList) list[1])[0]).Name] = new EInt(true, 32);
								list.Skip(2).ForEach(x => InferType(x));
								return EType.Unit;
							case "let":
								locals[((PName) list[1]).Name] = InferType(list[2]);
								list.Skip(3).ForEach(x => InferType(x));
								return list.Last().Type;
							case "mlet":
								if(!(list[1] is PList dlist)) throw new NotSupportedException();
								Debug.Assert(dlist.Count % 2 == 0);
								for(var i = 0; i < dlist.Count; i += 2)
									locals[((PName) dlist[i]).Name] = InferType(dlist[i + 1]);
								list.Skip(2).ForEach(x => InferType(x));
								return list.Last().Type;
							case { } fname when Program.Statements.ContainsKey(fname):
								InferList(list);
								return Program.Statements[fname].Signature(list);
							case { } fname when Program.Expressions.ContainsKey(fname):
								InferList(list);
								return Program.Expressions[fname].Signature(list);
							case { } fname when BuiltinTypes.Builtins.ContainsKey(fname):
								InferList(list);
								return BuiltinTypes.Builtins[fname](list);
							default:
								throw new NotImplementedException($"Unhandled function: {list[0]}");
						}
					case PString _:
						return EType.String;
					case PInt _:
						return new EInt(true, 64);
					case PName pname:
						return locals.ContainsKey(pname.Name) ? locals[pname.Name] : EType.Unit;
					default:
						throw new NotImplementedException($"Unknown type for inference: {tree.ToPrettyString()}");
				}
			}
			InferType(Decode);
			InferType(Eval);
			Locals = locals;
		}
	}
}