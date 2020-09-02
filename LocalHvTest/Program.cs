using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using Arch;
using MoreLinq;
using PrettyPrinter;

namespace LocalHvTest {
	class Program {
        static readonly Kvm Kvm = new Kvm();
        static readonly ConcurrentQueue<ulong> PageBaseQueue = new ConcurrentQueue<ulong>();

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

        class PageBase {
            public readonly ulong Addr;

            public PageBase(ulong addr) => Addr = addr;
            ~PageBase() => PageBaseQueue.Enqueue(Addr);
        }

        static PageBase GetPageBase() {
            if(PageBaseQueue.TryDequeue(out var addr)) return new PageBase(addr);
            addr = (ulong) Marshal.AllocHGlobal(0x3000);
            while((addr & 0xFFF) != 0) addr++;
            return new PageBase(addr);
        }

        public static bool Run(Dictionary<int, ulong> registers, Dictionary<int, (ulong, ulong)> vectors, Dictionary<ulong, byte[]> memory, List<int> outRegs, List<int> outVecs, List<ulong> outMem) {
            try {
                using var vm = Kvm.CreateVm();
                using var vcpu = vm.CreateVCpu(0);
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
                var pagebases = new List<PageBase>();
                foreach(var (addr, data) in memory) {
                    var pb = GetPageBase();
                    pagebases.Add(pb);
                    Marshal.Copy(data, 0, (IntPtr) pb.Addr, data.Length);
                    //Console.WriteLine($"Attempting to assign memory at 0x{addr:X}");
                    if(!vm.SetUserMemoryRegion(new KvmUserspaceMemoryRegion {
                        Slot = (uint) mi,
                        Flags = 0,
                        GuestPhysAddr = addr,
                        MemorySize = 0x2000,
                        UserspaceAddr = pb.Addr
                    })) {
                        Console.WriteLine($"Failed to assign memory region for addr 0x{addr:X}");
                        return false;
                    }
                    caddrs[addr] = pb.Addr;
                }
                
                vcpu.Debug = new KvmGuestDebug { Control = KvmGuestDebug.ENABLE | KvmGuestDebug.SINGLESTEP };

                vcpu.Run();
                
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
        
        static void Main(string[] args) {
			Core.Defs.Select(x => x.Name).Where(x => !x.StartsWith("CAS")).OrderBy(x => x).ForEach(name => {
                var def = Core.Defs.First(x => x.Name == name);
                Console.WriteLine("Generating tests");
                var tg = new TestGen(def);
                try {
                    Parallel.ForEach(tg.InstructionsWithConditions, x => {
                        var (insn, disasm, conds) = x;
                        Console.WriteLine(disasm);
                        var idata = BitConverter.GetBytes(insn);
                        foreach(var (pre, post) in conds) {
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
                                    ms.Add(addr << 12);
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
                            pre.PrettyPrint();
                            post.PrettyPrint();
                            foreach(var (k, v) in post) {
                                if(k is ulong addr) {
                                    addr <<= 12;
                                    outMem.Add(addr);
                                    em[addr] = (byte[]) v;
                                    if(!ms.Contains(addr)) {
                                        ms.Add(addr);
                                        mem[addr] = new byte[0];
                                    }
                                } else if(k is string reg) {
                                    if(reg[0] == 'X') {
                                        var rn = int.Parse(reg.Substring(1));
                                        outRegs.Add((int) rn);
                                        er[rn] = (ulong) v;
                                    } else if(reg == "SP") {
                                        outRegs.Add(34);
                                        er[34] = (ulong) v;
                                    } else if(reg == "PC") {
                                        outRegs.Add(32);
                                        er[32] = (ulong) v;
                                    } else if(reg[0] == 'V') {
                                        var rn = int.Parse(reg.Substring(1));
                                        outVecs.Add((int) rn);
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

                            if(!ms.Contains(TestGen.PC) && !ms.Contains(TestGen.PC - 0x1000)) {
                                mem[TestGen.PC] = idata;
                            }

                            void Throw(string description) =>
                                throw new MagicException(insn, disasm, description, pre, er, regs, ev, vecs, em, mem);

                            if(!Run(regs, vecs, mem, outRegs, outVecs, outMem))
                                Throw("Execution");

                            foreach(var rn in outRegs)
                                if(er[rn] != regs[rn])
                                    Throw(rn switch { 34 => "SP", 32 => "PC", 0x1000 => "NZCV", _ => $"X{rn}" });

                            foreach(var rn in outVecs) {
                                var (ea, eb) = ev[rn];
                                var (ga, gb) = vecs[rn];
                                if(ea != ga) Throw($"V{rn}L");
                                if(eb != gb) Throw($"V{rn}H");
                            }

                            /*var mc = Read();
                            Assert.AreEqual(em.Count, mc);
                            for(var i = 0; i < (int) mc; ++i) {
                                var addr = Read();
                                var len = (int) Read();
                                var td = new byte[len];
                                ReadAll(td);
                                var ml = Math.Min(len, em[addr].Length);
                                var (a, b) = ml == len && em[addr].Length == ml
                                    ? (em[addr], td)
                                    : (em[addr].Take(ml).ToArray(), td.Take(ml).ToArray());
                                Assert.AreEqual(a, b, $"[0x{addr:X}]");
                            }*/
                        }
                    });
                } catch(AggregateException ae) {
                    foreach(var e in ae.InnerExceptions) {
                        if(e is MagicException me) {
                            Console.WriteLine($"Legit failure? {me.Disasm} -- {me.Failure}");
                        } else
                            Console.WriteLine(e);
                    }
                }
            });
		}
	}
}