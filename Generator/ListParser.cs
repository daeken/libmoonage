using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using MoreLinq.Extensions;
using PrettyPrinter;

namespace Generator {
	public abstract class EType {
		public static readonly EUndef Undef = new EUndef();
		public static readonly EUnit Unit = (EUnit) EUnit.CompiletimeType;
		public static readonly EString String = (EString) EString.CompiletimeType;
		public static readonly EVector Vector = (EVector) EVector.CompiletimeType;

		public bool Runtime;
		public abstract EType AsRuntime();
		public abstract EType AsCompiletime();
		public EType AsRuntime(bool cond) => cond ? AsRuntime() : this;
	}

	public class EInt : EType {
		public readonly bool Signed;
		public readonly int Width;
		public EInt(bool signed, int width) {
			Signed = signed;
			Width = width;
		}

		public override EType AsCompiletime() => Runtime ? new EInt(Signed, Width) { Runtime = false } : this;
		public override EType AsRuntime() => Runtime ? this : new EInt(Signed, Width) { Runtime = true };
		public override string ToString() => $"EInt({(Signed ? "i" : "u")}{Width})";

		public void Deconstruct(out bool signed, out int width) {
			signed = Signed;
			width = Width;
		}
	}
	public class EFloat : EType {
		public readonly int Width;
		public EFloat(int width) => Width = width;

		public override EType AsRuntime() => Runtime ? this : new EFloat(Width) { Runtime = true };
		public override EType AsCompiletime() => Runtime ? new EFloat(Width) { Runtime = false } : this;
		public override string ToString() => $"EFloat({Width})";

		public void Deconstruct(out int width) => width = Width;
	}
	public class EUndef : EType {
		public override EType AsRuntime() => Runtime ? this : new EUndef { Runtime = true };
		public override EType AsCompiletime() => Runtime ? Undef : this;
	}
	public class EString : EType {
		public static readonly EType RuntimeType = new EString { Runtime = true };
		public static readonly EType CompiletimeType = new EString { Runtime = false };
		public override EType AsRuntime() => RuntimeType;
		public override EType AsCompiletime() => CompiletimeType;
	}
	public class EUnit : EType {
		public static readonly EType RuntimeType = new EUnit { Runtime = true };
		public static readonly EType CompiletimeType = new EUnit { Runtime = false };
		public override EType AsRuntime() => RuntimeType;
		public override EType AsCompiletime() => CompiletimeType;
	}
	public class EVector : EType {
		public static readonly EType RuntimeType = new EVector { Runtime = true };
		public static readonly EType CompiletimeType = new EVector { Runtime = false };
		public override EType AsRuntime() => RuntimeType;
		public override EType AsCompiletime() => CompiletimeType;
	}
	
	public abstract class PTree {
		public EType Type = EType.Undef;
	}

	public class PList : PTree, IEnumerable<PTree> {
		public readonly List<PTree> Children = new List<PTree>();
		public PTree Head => Children.First();
		public int Count => Children.Count;
		
		public PList() {}
		public PList(IEnumerable<PTree> elems) => elems.ForEach(Add);

		public void Add(PTree child) => Children.Add(child);

		public PTree this[int index] => Children[index];

		public IEnumerator<PTree> GetEnumerator() => Children.GetEnumerator();
		IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

		public override string ToString() => $"({(Type.Runtime ? "~runtime~ " : "")}{string.Join(' ', Children.Select(x => x.ToString()))})";

		public bool AnyRuntime => Type.Runtime || Children.Any(x => x.Type.Runtime);

		public PList MapLeaves(Func<PTree, PTree> mapper) {
			var c = new List<PTree>();
			var modified = false;

			foreach(var child in this) {
				if(child is PList list) {
					var sub = list.MapLeaves(mapper);
					c.Add(sub);
					if(!ReferenceEquals(list, sub))
						modified = true;
				} else {
					var sub = mapper(child);
					c.Add(sub);
					if(!ReferenceEquals(child, sub))
						modified = true;
				}
			}
			
			return modified ? new PList(c) { Type = Type } : this;
		}
	}

	public class PName : PTree {
		public readonly string Name;
		public PName(string name) => Name = name;
		public override string ToString() => Name;
		public void Deconstruct(out string name) => name = Name;
		public static implicit operator string(PName name) => name.Name;
	}

	public class PString : PTree {
		public readonly string String;
		public PString(string @string) => String = @string;
		public override string ToString() => String.ToPrettyString();
		public static implicit operator string(PString str) => str.String;
	}

	public class PInt : PTree {
		public readonly long Value;
		public PInt(long value) => Value = value;
		public override string ToString() => Value.ToString();
		public void Deconstruct(out long value) => value = Value;
		public static implicit operator long(PInt val) => val.Value;
	}
	
	public static class ListParser {
		public static PList Parse(string code) {
			var i = 0;
			return ParseList(code, ref i, true);
		}

		static PList ParseList(string code, ref int i, bool top = false) {
			var list = new PList();

			while(i < code.Length) {
				switch(code[i]) {
					case ' ': case '\t': case '\n': case '\r':
						i++;
						break;
					case '(':
						i++;
						list.Add(ParseList(code, ref i));
						break;
					case ')':
						i++;
						return list;
					case '-' when code[i + 1] >= '0' && code[i + 1] <= '9':
					case char x when x >= '0' && x <= '9':
						list.Add(ParseInt(code, ref i));
						break;
					case '"': case '\'':
						list.Add(ParseString(code, ref i));
						break;
					default:
						list.Add(ParseName(code, ref i));
						break;
				}
			}
			
			if(!top)
				throw new Exception("Reached end of file parsing non-top list");
			
			return list;
		}

		static PInt ParseInt(string code, ref int i) {
			var negative = false;
			if(code[i] == '-') {
				negative = true;
				i++;
			}

			var value = 0L;
			if(code[i] == '0' && code[i + 1] == 'b') {
				i += 2;
				while(code[i] == '0' || code[i] == '1' || code[i] == '_') {
					if(code[i] == '_')
						i++;
					else if(code[i++] == '0')
						value <<= 1;
					else
						value = (value << 1) | 1L;
				}
			} else if(code[i] == '0' && code[i + 1] == 'x') {
				i += 2;
				while(true) {
					if(code[i] == '_') {
					} else if(code[i] >= '0' && code[i] <= '9')
						value = (value << 4) | (uint) (code[i] - '0');
					else if(code[i] >= '0' && code[i] <= '9')
						value = (value << 4) | (uint) (code[i] - '0');
					else if(code[i] >= 'a' && code[i] <= 'f')
						value = (value << 4) | (uint) (code[i] - 'a' + 10);
					else if(code[i] >= 'A' && code[i] <= 'F')
						value = (value << 4) | (uint) (code[i] - 'A' + 10);
					else
						break;
					i++;
				}
			} else {
				while(code[i] == '_' || code[i] >= '0' && code[i] <= '9') {
					if(code[i] == '_')
						i++;
					else
						value = value * 10 + (uint) (code[i++] - '0');
				}
			}
			return new PInt(negative ? -value : value);
		}

		static PString ParseString(string code, ref int i) {
			var start = code[i++];
			var parsed = "";
			while(true) {
				switch(code[i++]) {
					case '\\':
						parsed += code[i++];
						break;
					case char x when x == start:
						return new PString(parsed);
					case char x:
						parsed += x;
						break;
				}
			}
		}

		static PName ParseName(string code, ref int i) {
			var name = "";
			while(true) {
				switch(code[i++]) {
					case ' ': case '\t': case '\n': case '\r': case '(': case ')':
						i--;
						return new PName(name);
					case char x:
						name += x;
						break;
				}
			}
		}
	}
}