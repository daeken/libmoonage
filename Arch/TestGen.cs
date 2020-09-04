using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using MoreLinq;

namespace Arch {
    public class TestGen {
        public const ulong PC = 0x4_5000_0000UL;
        readonly Def Def;
        public readonly Dictionary<uint, string> Instructions = new Dictionary<uint, string>();

        public TestGen(Def def) {
            Def = def;
            var fields =
                new LinkedList<(string Name, int Bits, int Shift)>(def.Fields.Select(x =>
                    (Name: x.Key, x.Value.Bits, x.Value.Shift)));
            IEnumerable<uint> Sub(LinkedList<(string Name, int Bits, int Shift)> parse) {
                if(parse.Count == 0) yield break;
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
            Console.WriteLine($"{def.Name} -- {Instructions.Count} instructions");
        }

        public
            ParallelQuery<(uint Inst, string Disasm, List<(Dictionary<object, dynamic>, Dictionary<object, dynamic>)>)>
            InstructionsWithConditions =>
                Instructions.AsParallel().Select(x => {
                    var cond = CreateConditions(Def, x.Key);
                    //Console.WriteLine($"Generated {cond.Count} condition sets for {x.Value}");
                    return (x.Key, x.Value, cond);
                });

        List<(Dictionary<object, dynamic>, Dictionary<object, dynamic>)> CreateConditions(Def def, uint inst) {
            var preconditionSets = new ConcurrentQueue<Dictionary<object, dynamic>>();
            preconditionSets.Enqueue(new Dictionary<object, dynamic>());
            var conditionSets = new ConcurrentBag<(Dictionary<object, dynamic>, Dictionary<object, dynamic>)>();

            var masterState = ExecutionState.Cleanroom();
            masterState.Registers["PC"] = PC;
            var masterLocals = masterState.Locals;
            foreach(var field in def.Fields)
                masterLocals[field.Key] = (inst >> field.Value.Shift) & ((1U << field.Value.Bits) - 1);
            try {
                masterState.Evaluate((PTree) def.Decode);
            } catch(BailoutException) {
                return null;
            }

            void Map(Dictionary<object, dynamic> preconditions) {
                var state = ExecutionState.Cleanroom();
                state.Registers["PC"] = PC;
                foreach(var (key, value) in preconditions) {
                    if(key is ulong page)
                        state.Memory[page] = value;
                    else
                        state.Registers[(string) key] = value;
                }
                foreach(var (lname, lvalue) in masterLocals)
                    state.Locals[lname] = lvalue;

                state.Evaluate((PTree) def.Eval);

                bool Equal(dynamic a, dynamic b) {
                    try {
                        return a == b;
                    } catch(Exception) {
                        return a.Equals(b);
                    }
                }

                var postconditions = new Dictionary<object, dynamic>();
                foreach(var (name, value) in state.Registers)
                    if(!preconditions.TryGetValue(name, out var pv) || !Equal(pv, value))
                        postconditions[name] = value;
                foreach(var (page, data) in state.Memory)
                    if(!preconditions.TryGetValue(page, out var pv) || pv != data)
                        postconditions[page] = data;
                preconditions.Remove("PC");
                if(postconditions.TryGetValue("PC", out var pc) && pc == PC)
                    postconditions.Remove("PC");
                if(postconditions.Count > 0)
                    conditionSets.Add((preconditions, postconditions));
            }

            while(preconditionSets.TryDequeue(out var preconditions)) {
                try {
                    Map(preconditions);
                } catch(BailoutException) { } catch(MissingRegisterException mrpe) {
                    if(mrpe.Register.StartsWith("NZCV")) {
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = 0UL });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = 1UL });
                    } else if(mrpe.Register[0] == 'X' || mrpe.Register == "SP") {
                        for(var i = 0; i < 4; ++i) {
                            var value = 1UL << (i * 16);
                            preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions) {
                                [mrpe.Register] = value
                            });
                            preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions) {
                                [mrpe.Register] = ~value
                            });
                        }

                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions) {
                            [mrpe.Register] = 1UL << 63
                        });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions) {
                            [mrpe.Register] = 1UL << 31
                        });
                    } else if(mrpe.Register[0] == 'V') {
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<byte>(0) });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<byte>(1) });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<byte>(0xFF) });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<float>(123f) });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<float>(-123f) });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<double>(123.0) });
                        preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions)
                            { [mrpe.Register] = new Vector128<double>(-123.0) });
                    } else throw new NotImplementedException($"Register {mrpe.Register}");
                } catch(MissingMemoryException mmpe) {
                    if(mmpe.Address > 0xFFFF_FFFF_FFFFUL)
                        continue;
                    var page = mmpe.Address >> 12;
                    var offset = (int) (mmpe.Address & 0xFFF);
                    var twoPage = offset >= 0xE00;
                    var data = new[] {
                        new byte[] { 0 }, new byte[] { 1 }, new byte[] { 0xFF },
                        BitConverter.GetBytes(123f), BitConverter.GetBytes(-123f),
                        BitConverter.GetBytes(123.0), BitConverter.GetBytes(-123.0)
                    };
                    foreach(var bytes in data) {
                        var mdata = new byte[4096];
                        for(var i = offset; i < 4096 - bytes.Length; i += bytes.Length)
                            Array.Copy(bytes, 0, mdata, i, bytes.Length);
                        for(var i = offset - bytes.Length; i >= 0; i -= bytes.Length)
                            Array.Copy(bytes, 0, mdata, i, bytes.Length);
                        if(page == PC >> 12)
                            Array.Copy(BitConverter.GetBytes(inst), 0, mdata, 0, 4);
                        else if(page == (PC >> 12) - 1)
                            Array.Copy(BitConverter.GetBytes(inst), 0, mdata, 0x1000, 4);
                        if(twoPage) {
                            preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions) {
                                [page] = mdata,
                                [page + 1] = mdata,
                            });
                        } else
                            preconditionSets.Enqueue(new Dictionary<object, dynamic>(preconditions) { [page] = mdata });
                    }
                }
            }
            return conditionSets.ToList();
        }

        string Disassemble(Def def, uint inst) {
            if((inst & def.Mask) != def.Match) return null;

            var state = ExecutionState.Cleanroom();
            state.Registers["PC"] = PC;
            var locals = state.Locals;
            foreach(var field in def.Fields)
                locals[field.Key] = (inst >> field.Value.Shift) & ((1U << field.Value.Bits) - 1);
            
            try {
                state.Evaluate((PTree) def.Decode);
            } catch(BailoutException) {
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
    }
}
