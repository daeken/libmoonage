using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;
using Arch;
using PrettyPrinter;

namespace LocalHvTest {
	class Program {
        class MagicException : Exception {
            public readonly uint Insn;
            public readonly string Disasm, Failure;
            public readonly Dictionary<object, dynamic> Preconditions;
            public readonly Dictionary<int, ulong> ExpectedRegisters, GotRegisters;
            public readonly Dictionary<int, (ulong, ulong)> ExpectedVectors, GotVectors;
            public readonly Dictionary<ulong, byte[]> ExpectedMemory, GotMemory;

            public MagicException(
                uint insn, string disasm, string failure, 
                Dictionary<object, dynamic> pre, 
                Dictionary<int, ulong> er, Dictionary<int, ulong> gr, 
                Dictionary<int, (ulong, ulong)> ev, Dictionary<int, (ulong, ulong)> gv, 
                Dictionary<ulong, byte[]> em, Dictionary<ulong, byte[]> gm
            ) {
                Insn = insn;
                Disasm = disasm;
                Failure = failure;
                Preconditions = pre;
                ExpectedRegisters = er;
                GotRegisters = gr;
                ExpectedVectors = ev;
                GotVectors = gv;
                ExpectedMemory = em;
                GotMemory = gm;
            }
        }

        static bool RunWithTimeout(int ms, Action func) {
            var tcsStart = new TaskCompletionSource<bool>();
            var tcsComplete = new TaskCompletionSource<bool>();
            var thread = new Thread(() => {
                tcsStart.SetResult(true);
                func();
                tcsComplete.SetResult(true);
            });
            thread.Start();
            tcsStart.Task.Wait();
            return tcsComplete.Task.Wait(ms) || tcsComplete.Task.IsCompleted;
        }

        class Worker {
            readonly Kvm Kvm = new Kvm();
            readonly ulong[] PageBases = new ulong[8];
            
            public Worker() {
                for(var i = 0; i < 8; ++i) {
                    var addr = (ulong) Marshal.AllocHGlobal(0x2000);
                    while((addr & 0xFFF) != 0) addr++;
                    PageBases[i] = addr;
                }
            }
            
            public bool Run(Dictionary<int, ulong> registers, Dictionary<int, (ulong, ulong)> vectors,
                Dictionary<ulong, byte[]> memory, List<int> outRegs, List<int> outVecs, List<ulong> outMem) {
                try {
                    var (_vm, _vcpu) = HangChecker.Check("CreateVmAndVCpu", () => Kvm.CreateVmAndVCpu());
                    using var vm = _vm;
                    using var vcpu = _vcpu;
                    //using var vm = HangChecker.Check("CreateVM", () => Kvm.CreateVm());
                    //using var vcpu = HangChecker.Check("CreateVCpu", () => vm.CreateVCpu(0, true));
                    if(!vm.GetArmPreferredTarget(out var init))
                        return false;
                    if(!vcpu.Init(init))
                        return false;
                    vcpu.CPACR_EL1 = 3 << 20;
                    //Console.WriteLine($"Alignment flag: {vcpu.SCTLR_EL1 & 2}");
                    vcpu.SCTLR_EL1 &= ~(1UL << 1);
                    Debug.Assert(memory.Count <= 7);
                    foreach(var (num, value) in registers)
                        if(num == 0x1000)
                            vcpu.NZCV = value;
                        else
                            vcpu.X[num] = value;
                    foreach(var (num, value) in vectors)
                        vcpu.V[num] = value;

                    var mi = 0;
                    var caddrs = new Dictionary<ulong, ulong>();
                    foreach(var (addr, data) in memory) {
                        Marshal.Copy(data, 0, (IntPtr) PageBases[mi], data.Length);
                        //Console.WriteLine($"Attempting to assign memory at 0x{addr:X}");
                        if(!vm.SetUserMemoryRegion(new KvmUserspaceMemoryRegion {
                            Slot = (uint) mi,
                            Flags = 0,
                            GuestPhysAddr = addr,
                            MemorySize = 0x1000,
                            UserspaceAddr = PageBases[mi]
                        })) {
                            Console.WriteLine($"Failed to assign memory region for addr 0x{addr:X}");
                            return false;
                        }

                        caddrs[addr] = PageBases[mi++];
                    }

                    vcpu.Debug = new KvmGuestDebug { Control = KvmGuestDebug.ENABLE | KvmGuestDebug.SINGLESTEP };

                    /*var success = false;
                    if(!RunWithTimeout(500, () => { success = vcpu.Run(); })) {
                        vcpu.Stop();
                        throw new TimeoutException();
                    }*/
                    var success = HangChecker.Check("VCpu Run", vcpu.Run);

                    if(!success) return false;

                    foreach(var num in outRegs)
                        if(num == 0x1000)
                            registers[0x1000] = vcpu.NZCV;
                        else
                            registers[num] = vcpu.X[num];
                    foreach(var num in outVecs)
                        vectors[num] = vcpu.V[num];

                    foreach(var addr in outMem)
                        Marshal.Copy((IntPtr) caddrs[addr], memory[addr], 0, memory[addr].Length);

                    return true;
                } catch(KvmException e) {
                    Console.WriteLine(e);
                    return false;
                }
            }
        }

        static string Hexdump(ulong addr, byte[] memory) {
            var ret = "<pre>";
            for(var i = 0; i < memory.Length; i += 32) {
                ret += $"{addr + (ulong) i:X04}  ";
                for(var j = 0; j < 32 && i + j < memory.Length; ++j) {
                    ret += $"{memory[i + j]:X02} ";
                    if(j % 8 == 7) ret += " ";
                }
                ret += "\n";
            }
            ret += $"{addr + (ulong) memory.Length:X04}</pre>";
            return ret;
        }

        static void Main(string[] args) {
            HangChecker.Run();

            var defs = Core.Defs.Select(x => x.Name).Where(x => !x.StartsWith("CAS")).OrderBy(x => x).ToList();

            try {
                File.Delete("testresults.xml");
            } catch(Exception) { }
            using var ofp = File.OpenWrite("testresults.xml");
            using var sw = new StreamWriter(ofp);
            sw.WriteLine("<instructions>");
            var availableWorkers = new ConcurrentQueue<Worker>(Enumerable.Range(0, Environment.ProcessorCount).Select(_ => new Worker()));
            void WithWorker(Action<Worker> func) {
                while(true) {
                    if(availableWorkers.TryDequeue(out var worker)) {
                        try {
                            func(worker);
                        } finally {
                            availableWorkers.Enqueue(worker);
                        }
                        return;
                    }
                    Thread.Sleep(1);
                }
            }

            var successes = 0;
            var failures = 0;
            foreach(var name in defs) {
                //if(name != "CCMN-immediate") continue;
                var failed = false;
                var def = Core.Defs.First(x => x.Name == name);
                try {
                    var tg = new TestGen(def);
                    tg.InstructionsWithConditions.ForAll(x => {
                        var (insn, disasm, pre, post) = x;
                        //if(post.ContainsKey("PC"))
                        //    continue;
                        var ms = new HashSet<ulong>();
                        var nnzcv = false;
                        var nzcv = 0UL;
                        var regs = new Dictionary<int, ulong>();
                        var vecs = new Dictionary<int, (ulong, ulong)>();
                        var mem = new Dictionary<ulong, byte[]>();
                        var outRegs = new List<int>();
                        var outVecs = new List<int>();
                        var outMem = new List<ulong>();
                        foreach(var (k, v) in pre) {
                            if(k is ulong addr) {
                                addr <<= 12;
                                ms.Add(addr);
                                if(!(v is byte[] data)) throw new Exception();
                                mem[addr] = data;
                            } else if(k is string reg) {
                                if(reg[0] == 'X')
                                    regs[(int) ulong.Parse(reg.Substring(1))] = (ulong) v;
                                else if(reg == "SP") {
                                    regs[34] = (ulong) v;
                                } else if(reg == "PC") {
                                    regs[32] = (ulong) v;
                                } else if(reg[0] == 'V') {
                                    var ri = ulong.Parse(reg.Substring(1));
                                    var vec = (Vector128<ulong>) v.As<ulong>();
                                    vecs[(int) ri] = (vec[0], vec[1]);
                                } else if(reg[0] == 'N') {
                                    nnzcv = true;
                                    var bit = ((ulong) v) & 1;
                                    switch(reg[5]) {
                                        case 'N':
                                            nzcv |= bit << 31;
                                            break;
                                        case 'Z':
                                            nzcv |= bit << 30;
                                            break;
                                        case 'C':
                                            nzcv |= bit << 29;
                                            break;
                                        case 'V':
                                            nzcv |= bit << 28;
                                            break;
                                    }
                                } else
                                    throw new NotImplementedException(reg);
                            } else
                                throw new NotImplementedException(k.ToPrettyString());
                        }

                        var er = new Dictionary<int, ulong>();
                        var ev = new Dictionary<int, (ulong, ulong)>();
                        var em = new Dictionary<ulong, byte[]>();
                        var nenzcv = false;
                        var enzcv = nzcv;
                        //pre.PrettyPrint();
                        //post.PrettyPrint();
                        foreach(var (k, v) in post) {
                            if(k is ulong addr) {
                                addr <<= 12;
                                outMem.Add(addr);
                                em[addr] = (byte[]) v;
                                if(!ms.Contains(addr)) {
                                    ms.Add(addr);
                                    mem[addr] = new byte[0x1000];
                                }
                            } else if(k is string reg) {
                                if(reg[0] == 'X') {
                                    var rn = int.Parse(reg.Substring(1));
                                    outRegs.Add(rn);
                                    er[rn] = (ulong) v;
                                } else if(reg == "SP") {
                                    outRegs.Add(34);
                                    er[34] = (ulong) v;
                                } else if(reg == "PC") {
                                    outRegs.Add(32);
                                    er[32] = (ulong) v;
                                } else if(reg[0] == 'V') {
                                    var rn = int.Parse(reg.Substring(1));
                                    outVecs.Add(rn);
                                    var vec = (Vector128<ulong>) v.As<ulong>();
                                    ev[rn] = (vec[0], vec[1]);
                                } else if(reg[0] == 'N') {
                                    var bit = ((ulong) v) & 1;
                                    nenzcv = true;
                                    switch(reg[5]) {
                                        case 'N':
                                            enzcv = (enzcv & ~(1UL << 31)) | (bit << 31);
                                            break;
                                        case 'Z':
                                            enzcv = (enzcv & ~(1UL << 30)) | (bit << 30);
                                            break;
                                        case 'C':
                                            enzcv = (enzcv & ~(1UL << 29)) | (bit << 29);
                                            break;
                                        case 'V':
                                            enzcv = (enzcv & ~(1UL << 28)) | (bit << 28);
                                            break;
                                    }
                                } else
                                    throw new NotImplementedException(reg);
                            } else
                                throw new NotImplementedException(k.ToPrettyString());
                        }

                        regs[32] = TestGen.PC;
                        if(nenzcv) {
                            regs[0x1000] = nzcv;
                            outRegs.Add(0x1000);
                            er[0x1000] = enzcv;
                        } else if(nnzcv)
                            regs[0x1000] = nzcv;

                        if(!ms.Contains(TestGen.PC))
                            mem[TestGen.PC] = BitConverter.GetBytes(insn);

                        void Throw(string description) =>
                            throw new MagicException(insn, disasm, description, pre, er, regs, ev, vecs, em, mem);

                        var success = false;
                        for(var i = 0; i < 10; ++i)
                            try {
                                WithWorker(worker => {
                                    if(!worker.Run(regs, vecs, mem, outRegs, outVecs, outMem))
                                        Throw("Execution");
                                });
                                success = true;
                                break;
                            } catch(TimeoutException) {
                                Console.WriteLine($"Timeout on {name} -- {disasm} -- attempt {i}");
                            }

                        if(!success) Throw("Timeout");

                        foreach(var rn in outRegs)
                            if(er[rn] != regs[rn])
                                Throw(rn switch { 34 => "SP", 32 => "PC", 0x1000 => "NZCV", _ => $"X{rn}" });

                        foreach(var rn in outVecs) {
                            var (ea, eb) = ev[rn];
                            var (ga, gb) = vecs[rn];
                            if(ea != ga) Throw($"V{rn}L");
                            if(eb != gb) Throw($"V{rn}H");
                        }

                        foreach(var addr in outMem) {
                            var e = em[addr];
                            var g = mem[addr];
                            var ml = Math.Min(g.Length, e.Length);
                            var (a, b) = ml == g.Length && e.Length == ml
                                ? (e, g)
                                : (e.Take(ml).ToArray(), g.Take(ml).ToArray());
                            for(var i = 0; i < ml; ++i)
                                if(e[i] != g[i]) {
                                    Throw($"[0x{addr + (ulong) i:X}]");
                                    break;
                                }
                        }
                    });
                } catch(AggregateException ae) {
                    failed = true;
                    var ie = ae.InnerExceptions.First();
                    if(ie is MagicException me)
                        lock(sw) {
                            sw.WriteLine($"<instruction><instname>{name}</instname>");
                            sw.WriteLine(
                                $"<instruction>{string.Join(' ', BitConverter.GetBytes(me.Insn).Select(x => $"{x:X02}"))}</instruction>");
                            sw.WriteLine($"<disasm>{me.Disasm}</disasm>");
                            sw.WriteLine($"<failure>{me.Failure}</failure>");
                            if(me.Preconditions.Count != 0) {
                                sw.WriteLine("<preconditions>");
                                foreach(var (k, v) in me.Preconditions) {
                                    if(k is ulong addr) {
                                        addr <<= 12;
                                        if(!(v is byte[] data)) throw new Exception();
                                        sw.WriteLine($"<tr><td>0x{addr:X}</td><td>{Hexdump(addr, data)}</td></tr>");
                                    } else if(k is string reg) {
                                        sw.Write($"<tr><td>{reg}</td><td>");
                                        if(reg[0] == 'X' || reg == "SP" || reg == "PC" || reg[0] == 'N')
                                            sw.Write($"0x{(ulong) v:X}");
                                        else if(reg[0] == 'V') {
                                            var ri = ulong.Parse(reg.Substring(1));
                                            var vec = (Vector128<byte>) v.As<byte>();
                                            sw.Write(string.Join(' ', vec.Data.Select(x => $"{x:X02}")));
                                        }

                                        sw.WriteLine("</td></tr>");
                                    }
                                }

                                sw.WriteLine("</preconditions>");
                            }

                            sw.WriteLine(
                                "<postconditions>");
                            foreach(var rn in me.ExpectedRegisters.Keys) {
                                var ev = me.ExpectedRegisters[rn];
                                ulong? gv = null;
                                if(me.GotRegisters.TryGetValue(rn, out var _gv))
                                    gv = _gv;
                                sw.Write($"<tr><td>{(gv.HasValue && ev == gv ? "&#x2705;" : "&#x274C;")}</td>");
                                sw.Write(
                                    $"<td>{rn switch { 34 => "SP", 32 => "PC", 0x1000 => "NZCV", _ => $"X{rn}" }}</td>");
                                sw.Write($"<td>0x{ev:X}</td>");
                                if(gv.HasValue)
                                    sw.WriteLine($"<td>0x{gv.Value:X}</td></tr>");
                                else
                                    sw.WriteLine($"<td>Undefined</td></tr>");
                            }

                            foreach(var rn in me.ExpectedVectors.Keys) {
                                var ev = me.ExpectedVectors[rn];
                                (ulong, ulong)? gv = null;
                                if(me.GotVectors.TryGetValue(rn, out var _gv))
                                    gv = _gv;
                                sw.Write(
                                    $"<tr><td>{(gv.HasValue && ev.Item1 == gv.Value.Item1 && ev.Item2 == gv.Value.Item2 ? "&#x2705;" : "&#x274C;")}</td>");
                                sw.Write($"<td>V{rn}</td>");
                                sw.Write(
                                    $"<td>{string.Join(' ', BitConverter.GetBytes(ev.Item1).Concat(BitConverter.GetBytes(ev.Item2)).Select(x => $"{x:X02}"))}</td>");
                                if(gv.HasValue)
                                    sw.WriteLine(
                                        $"<td>{string.Join(' ', BitConverter.GetBytes(gv.Value.Item1).Concat(BitConverter.GetBytes(gv.Value.Item2)).Select(x => $"{x:X02}"))}</td></tr>");
                                else
                                    sw.WriteLine("<td>Undefined</td></tr>");
                            }

                            foreach(var addr in me.ExpectedMemory.Keys) {
                                var e = me.ExpectedMemory[addr];
                                if(!me.GotMemory.TryGetValue(addr, out var g))
                                    g = null;
                                var ml = g == null ? e.Length : Math.Min(g.Length, e.Length);
                                var (a, b) = g == null || (ml == g.Length && e.Length == ml)
                                    ? (e, g)
                                    : (e.Take(ml).ToArray(), g.Take(ml).ToArray());
                                sw.Write(
                                    $"<tr><td>{(g != null && a.Zip(b).All(x => x.First == x.Second) ? "&#x2705;" : "&#x274C;")}</td>");
                                sw.Write($"<td>0x{addr:X}</td>");
                                sw.Write($"<td>{Hexdump(addr, a)}</td>");
                                sw.WriteLine($"<td>{(g != null ? Hexdump(addr, b) : "Undefined")}</td></tr>");
                            }

                            sw.WriteLine("</postconditions>");
                            sw.WriteLine("</instruction>");
                            sw.Flush();
                        }
                    else
                        lock(sw) {
                            sw.WriteLine($"<instruction><instname>{name}</instname>");
                            sw.WriteLine($"<pre>{ie.ToString().Replace("&", "&amp;").Replace("<", "&lt;")}</pre>");
                            sw.WriteLine("</instruction>");
                            sw.Flush();
                        }
                } catch(Exception e) {
                    failed = true;
                    lock(sw) {
                        sw.WriteLine($"<instruction><instname>{name}</instname>");
                        sw.WriteLine($"<pre>{e.ToString().Replace("&", "&amp;").Replace("<", "&lt;")}</pre>");
                        sw.WriteLine("</instruction>");
                        sw.Flush();
                    }
                }

                lock(defs) {
                    if(failed)
                        failures++;
                    else
                        successes++;
                    Console.Write($"{failures+successes}/{defs.Count}  --  ");
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write($"{successes} passed  ");
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine($"{failures} failed");
                    Console.ResetColor();
                    GC.Collect();
                }
            }
            sw.WriteLine("</instructions>");
		}
	}
}
