using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text.RegularExpressions;
using PrettyPrinter;

namespace Generator {
    public class TestGen {
        private const ulong PC = 0x4_5000_0000UL;
        public readonly Dictionary<uint, string> Instructions = new Dictionary<uint, string>();
        public TestGen(Def def) {
            Console.WriteLine($"Generating test for {def.Name}");
            var fields =
                new LinkedList<(string Name, int Bits, int Shift)>(def.Fields.Select(x =>
                    (Name: x.Key, x.Value.Bits, x.Value.Shift)));
            IEnumerable<uint> Sub(LinkedList<(string Name, int Bits, int Shift)> parse) {
                var (name, bits, shift) = parse.First.Value;
                parse.RemoveFirst();
                var values = new List<uint> { 0, 1 };

                if(bits == 5 && name[0] == 'r') {
                    values.Add(2);
                    values.Add(3);
                    values.Add(0b11111);
                } else if(bits <= 4)
                    values = Enumerable.Range(0, 1 << bits).Select(x => (uint) x).ToList();
                else {
                    var max = (1U << bits) - 1;
                    values.Add(max);
                    values.Add(max - 1);
                }

                if(parse.Count == 0)
                    foreach(var value in values)
                        yield return value << shift;
                else {
                    var next = Sub(parse).ToList();
                    foreach(var value in values)
                        foreach(var nv in next)
                            yield return (value << shift) | nv;
                }
            }
            
            foreach(var values in Sub(fields)) {
                var inst = def.Match | values;

                var disasm = Disassemble(def, inst);
                if(disasm == null)
                    continue;

                Instructions[inst] = disasm;
            }

            var instsWithConditions =
                Instructions.Select(x => (x.Key, x.Value, CreateConditions(def, x.Key))).ToList();
        }

        class UnusablePreconditionException : Exception {}
        class MissingPreconditionException : Exception {
            public EType Type;
            protected MissingPreconditionException(EType type) { Type = type; }
        }
        class MissingRegisterPreconditionException : MissingPreconditionException {
            public string Register;
            public MissingRegisterPreconditionException(string register, EType type) : base(type) { Register = register; }
        }
        class MissingMemoryPreconditionException : MissingPreconditionException {
            public ulong Address;
            public MissingMemoryPreconditionException(ulong address, EType type) : base(type) { Address = address; }
        }

        class CpuState {
            public Func<string, dynamic> ReadRegister;
            public Action<string, dynamic> WriteRegister;
            public Func<ulong, EType, dynamic> ReadMemory;
            public Action<ulong, EType, dynamic> WriteMemory;
        }

        List<(Dictionary<string, dynamic>, Dictionary<string, dynamic>)> CreateConditions(Def def, uint inst) {
            var preconditionSets = new Queue<Dictionary<string, dynamic>>();
            preconditionSets.Enqueue(new Dictionary<string, dynamic>());
            var conditionSets = new List<(Dictionary<string, dynamic>, Dictionary<string, dynamic>)>();
            
            var masterLocals = new Dictionary<string, dynamic>();
            foreach(var field in def.Fields)
                masterLocals[field.Key] = (inst >> field.Value.Shift) & ((1U << field.Value.Bits) - 1);
            Evaluate(def.Decode, masterLocals);

            void Map(Dictionary<string, dynamic> preconditions) {
                var registerValues = new Dictionary<string, dynamic>();
                var memoryValues = new Dictionary<ulong, dynamic>();

                dynamic ReadRegister(string name) {
                    return 127;
                }

                void WriteRegister(string name, dynamic value) {
                    Console.WriteLine($"Writing {value} to {name}");
                }

                dynamic ReadMemory(ulong address, EType type) {
                    return null;
                }

                void WriteMemory(ulong address, EType type, dynamic value) {
                }

                var cpuState = new CpuState {
                    ReadRegister = ReadRegister, WriteRegister = WriteRegister, 
                    ReadMemory = ReadMemory, WriteMemory = WriteMemory
                };

                Evaluate(def.Eval, new Dictionary<string, dynamic>(masterLocals), cpuState);

                var postconditions = registerValues;
                foreach(var kv in memoryValues)
                    postconditions[$"[0x{kv.Key:X}]"] = kv.Value;
                conditionSets.Add((preconditions, postconditions));
            }
            
            while(preconditionSets.TryDequeue(out var preconditions)) {
                try {
                    Map(preconditions);
                } catch(UnusablePreconditionException) {
                    
                } catch(MissingRegisterPreconditionException mrpe) {
                    
                } catch(MissingMemoryPreconditionException mmpe) {
                    
                }
            }

            return conditionSets;
        }

        void Evaluate(PTree tree, Dictionary<string, dynamic> locals, CpuState state = null) {
            dynamic Binary(PList list, Func<dynamic, dynamic, dynamic> func) {
                var a = Interpret(list[1]);
                var b = Interpret(list[2]);
                try {
                    return func(a, b);
                } catch(Exception) {
                    return func((ulong) a, (ulong) b);
                }
            }
            
            dynamic Interpret(PTree tree) {
                if(tree is PList list) {
                    if(!(list[0] is PName lhn)) throw new NotImplementedException($"PList {list}");
                    switch(lhn.Name) {
                        case "let": {
                            var value = locals[((PName) list[1]).Name] = Interpret(list[2]);
                            foreach(var elem in list.Skip(3))
                                value = Interpret(elem);
                            return value;
                        }
                        case "mlet": {
                            dynamic value = null;
                            if(!(list[1] is PList mlist)) throw new NotImplementedException($"mlet argument not a list? {list}");
                            for(var i = 0; i < mlist.Count; i += 2)
                                value = locals[((PName) mlist[i]).Name] = Interpret(mlist[i + 1]);
                            foreach(var elem in list.Skip(2))
                                value = Interpret(elem);
                            return value;
                        }
                        case "=":
                            if(list[1] is PList alist) {
                                if(!(alist[0] is PName aname)) throw new NotImplementedException();
                                return Interpret(new PList(new[] { new PName("=" + aname.Name) }.Concat(alist.Skip(1)).Concat(list.Skip(2))));
                            } else
                                return locals[((PName) list[1]).Name] = Interpret(list[2]);
                        case "=gpr32": {
                            var reg = Interpret(list[1]);
                            state.WriteRegister($"X{reg}", (ulong) (uint) Interpret(list[2]));
                            return null;
                        }
                        case "=gpr64": {
                            var reg = Interpret(list[1]);
                            state.WriteRegister($"X{reg}", (ulong) Interpret(list[2]));
                            return null;
                        }
                        case "gpr32": return (uint) state.ReadRegister($"X{Interpret(list[1])}");
                        case "gpr64": return (ulong) state.ReadRegister($"X{Interpret(list[1])}");
                        case "nzcv": {
                            var nzcv = (uint) state.ReadRegister("NZCV");
                            if(list.Count == 1) return nzcv;
                            var sub = ((PName) list[1]).Name;
                            switch(sub) {
                                case "n": return (nzcv >> 31) & 1;
                                case "z": return (nzcv >> 30) & 1;
                                case "c": return (nzcv >> 29) & 1;
                                case "v": return (nzcv >> 28) & 1;
                                default: throw new NotImplementedException();
                            }
                        }
                        case "if": {
                            var cond = Interpret(list[1]);
                            var bcond = cond is bool b ? b : cond != 0;
                            return Interpret(list[bcond ? 2 : 3]);
                        }
                        case "requires": {
                            var cond = Interpret(list[1]);
                            var bcond = cond is bool b ? b : cond != 0;
                            if(!bcond) throw new NotSupportedException();
                            return null;
                        }
                        case "block":
                            dynamic tv = null;
                            foreach(var elem in list.Skip(1))
                                tv = Interpret(elem);
                            return tv;
                        case "match":
                            var mv = Interpret(list[1]);
                            for(var i = 2; i < list.Count; i += 2) {
                                if(i + 1 < list.Count) {
                                    var cv = Interpret(list[i]);
                                    bool mcond = false;
                                    try {
                                        mcond = cv == mv;
                                    } catch(Exception) {
                                        mcond = (ulong) cv == (ulong) mv;
                                    }
                                    if(mcond)
                                        return Interpret(list[i + 1]);
                                } else
                                    return Interpret(list[i]);
                            }
                            throw new NotImplementedException("Hit end of match?!");
                        case "cast": {
                            var icv = Interpret(list[1]);
                            if(!(list[2] is PName tn))
                                throw new NotImplementedException($"Type for cast not a name? '{list[2]}'");
                            switch(tn.Name) {
                                case "u8": return (byte) icv;
                                case "i8": return (sbyte) icv;
                                case "u16": return (ushort) icv;
                                case "i16": return (short) icv;
                                case "u32": return (uint) icv;
                                case "i32": return (int) icv;
                                case "u64": return (ulong) icv;
                                case "i64": return (long) icv;
                                case {} type when type[0] == 'u': return (ulong) icv;
                                case {} type when type[0] == 'i': return (long) icv;
                                default: throw new NotImplementedException($"Casting to '{tn.Name}'");
                            }
                        }
                        case "bitcast": {
                            var icv = Interpret(list[1]);
                            if(!(list[2] is PName tn))
                                throw new NotImplementedException($"Type for bitcast not a name? '{list[2]}'");
                            switch(tn.Name) {
                                case "u8": return (byte) icv;
                                case "i8": return (sbyte) icv;
                                case "u16": return (ushort) icv;
                                case "i16": return (short) icv;
                                case "u32": return (uint) icv;
                                case "i32": return (int) icv;
                                case "u64": return (ulong) icv;
                                case "i64": return (long) icv;
                                case "f32": return BitConverter.ToSingle(BitConverter.GetBytes(icv));
                                case "f64": return BitConverter.ToDouble(BitConverter.GetBytes(icv));
                                case {} type when type[0] == 'u': return (ulong) icv;
                                case {} type when type[0] == 'i': return (long) icv;
                                default: throw new NotImplementedException($"Bitcasting to '{tn.Name}'");
                            }
                        }
                        case "bitwidth": {
                            var typeName = ((PName) list[1]).Name;
                            return int.Parse(typeName.Substring(1));
                        }
                        case "signext":
                            var isv = Interpret(list[1]);
                            if(!(list[2] is PName stn))
                                throw new NotImplementedException($"Type for signext not a name? '{list[2]}'");
                            switch(stn.Name) {
                                case "i8": return SignExt<sbyte>((ulong) isv, list[1].Type is EInt sei ? sei.Width : throw new NotImplementedException());
                                case "i16": return SignExt<short>((ulong) isv, list[1].Type is EInt sei16 ? sei16.Width : throw new NotImplementedException());
                                case "i32": return SignExt<int>((ulong) isv, list[1].Type is EInt sei32 ? sei32.Width : throw new NotImplementedException());
                                case "i64": return SignExt<long>((ulong) isv, list[1].Type is EInt sei64 ? sei64.Width : throw new NotImplementedException());
                                default: throw new NotImplementedException($"Casting to '{stn.Name}'");
                            }
                        case ":":
                            var ccv = Interpret(list[1]);
                            foreach(var elem in list.Skip(2)) {
                                ccv <<= elem.Type is EInt ei ? ei.Width : throw new NotImplementedException();
                                ccv |= Interpret(elem);
                            }
                            return ccv;
                        case "unimplemented": throw new NotSupportedException();
                        case "pc": return PC;

                        case "make-wmask": {
                            var ilist = list.Skip(1).Select(Interpret).ToList();
                            return MakeWMask((uint) ilist[0], (uint) ilist[1], (uint) ilist[2], (long) ilist[4], (int) ilist[3]);
                        }
                        case "make-tmask": {
                            var ilist = list.Skip(1).Select(Interpret).ToList();
                            return MakeTMask((uint) ilist[0], (uint) ilist[1], (uint) ilist[2], (long) ilist[4], (int) ilist[3]);
                        }

                        case "replicate": {
                            if(!(list[1].Type is EInt(_, var width))) throw new NotSupportedException();
                            var value = Interpret(list[1]);
                            var count = Interpret(list[2]);
                            var rv = 0UL;
                            for(var i = 0; i < count; ++i)
                                rv |= (ulong) value << (int) (i * width);
                            return rv;
                        }

                        case "!": return (ulong) Interpret(list[1]) == 0 ? 1UL : 0UL;
                        case "==": return Binary(list, (a, b) => a == b);
                        case "!=": return Binary(list, (a, b) => a != b);
                        case "+":  return Binary(list, (a, b) => a + b);
                        case "-":  return Binary(list, (a, b) => a - b);
                        case "*":  return Binary(list, (a, b) => a * b);
                        case "/":  return Binary(list, (a, b) => a / b);
                        case "%":  return Binary(list, (a, b) => a % b);
                        case ">>": return Binary(list, (a, b) => a >> (int) b);
                        case "<<": return Binary(list, (a, b) => a << (int) b);
                        case "&":  return Binary(list, (a, b) => a & b);
                        case "|":  return Binary(list, (a, b) => a | b);
                        case "^":  return Binary(list, (a, b) => a ^ b);
                        default:
                            throw new NotImplementedException($"List head '{lhn.Name}'");
                    }
                }
                if(tree is PInt pi)
                    return pi.Type is EInt ei && ei.Signed ? (dynamic) pi.Value : (ulong) pi.Value;
                if(tree is PString ps)
                    return ps.String;
                if(tree is PName pn && locals.ContainsKey(pn.Name))
                    return locals[pn.Name];
                throw new NotImplementedException($"PTree '{tree}'");
            }

            Interpret(tree);
        }

        string Disassemble(Def def, uint inst) {
            if((inst & def.Mask) != def.Match) return null;

            var locals = new Dictionary<string, dynamic>();
            foreach(var field in def.Fields)
                locals[field.Key] = (inst >> field.Value.Shift) & ((1U << field.Value.Bits) - 1);
            
            try {
                Evaluate(def.Decode, locals);
            } catch(NotSupportedException) {
                return null;
            }

            string RewriteFormat(string fmt) =>
                Regex.Replace(fmt, @"\$(\$|[a-zA-Z\-][a-zA-Z\-0-9]*)", 
                    match => {
                        if(match.Groups[1].Value == "$$")
                            return "$";
                        var name = match.Groups[1].Value;
                        var v = locals[name];
                        if(def.Locals[name] is EInt(var signed, var size) && size > 8)
                            return signed && (long) v < 0 ? $"-0x{-(long) v:X}" : $"0x{v:X}";
                        return v.ToString();
                    });

            return RewriteFormat(def.Disassembly);
        }

        static T SignExt<T>(ulong value, int size) {
            if(typeof(T) == typeof(long))
                return (T) (object) ((value & (1UL << (size - 1))) != 0 ? (long) value - (1L << size) : (long) value);
            if(typeof(T) == typeof(int))
                return (T) (object) ((value & (1UL << (size - 1))) != 0 ? (int) value - (1 << size) : (int) value);
            throw new NotImplementedException($"Unknown return for SignExt: {typeof(T)}");
        }
        
        static int HighestSetBit(ulong v, int bits) {
            for(var i = bits - 1; i >= 0; --i)
                if((v & (1UL << i)) != 0)
                    return i;
            return -1;
        }
        static ulong ZeroExtend(ulong v, int bits) => v & Ones(bits);
        static ulong Ones(int bits) => Enumerable.Range(0, bits).Select(i => 1UL << i).Aggregate((a, b) => a | b);
        static ulong Replicate(ulong v, int bits, int start, int rep, int ext) {
            var repval = (v >> start) & Ones(rep);
            var times = ext / rep;
            var val = 0UL;
            for(var i = 0; i < times; ++i)
                val = (val << rep) | repval;
            return v | (val << start);
        }
        static ulong RollRight(ulong v, int size, int rotate) => ((v << (size - rotate)) | (v >> rotate)) & Ones(size);
        static (ulong, ulong) MakeMasks(uint n, uint imms, uint immr, int m, bool immediate) {
            var len = HighestSetBit((n << 6) | (imms ^ 0b111111U), 7);
            if(!(len > 0 && m >= 1 << len)) throw new NotSupportedException();

            var levels = ZeroExtend(Ones(len), 6);
            if(!(!immediate || (imms & levels) != levels)) throw new NotSupportedException();
            
            var S = imms & levels;
            var R = immr & levels;

            var diff = (S - R) & 0b111111;
            var esize = 1 << len;
            var d = diff & Ones(len);

            var welem = ZeroExtend(Ones((int) (S + 1)), esize);
            var telem = ZeroExtend(Ones((int) (d + 1)), esize);

            var wmask = Replicate(RollRight(welem, esize, (int) R), esize, 0, esize, m);
            var tmask = Replicate(telem, esize, 0, esize, m);
            return (wmask, tmask);
        }
        
        static ulong MakeWMask(uint n, uint imms, uint immr, long m, int immediate) =>
            MakeMasks(n, imms, immr, (int) m, immediate != 0).Item1;
        static ulong MakeTMask(uint n, uint imms, uint immr, long m, int immediate) =>
            MakeMasks(n, imms, immr, (int) m, immediate != 0).Item2;
    }
}