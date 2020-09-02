using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Threading.Tasks;
using Arch;
using NUnit.Framework;
using NUnit.Framework.Internal;
using PrettyPrinter;

namespace RemoteTestRunner {
    [Parallelizable(ParallelScope.All)]
    public class Tests {
        [Test, TestCaseSource("GetTestCases")]
        [Parallelizable(ParallelScope.All)]
        public void TestDef(string name) {
            var client = new TcpClient("localhost", 12347);
            var socket = client.Client;

            void WriteAll(byte[] data) {
                var len = data.Length;
                var i = 0;
                while(i < len) {
                    var s = socket.Send(data, i, len - i, SocketFlags.None);
                    if(s <= 0)
                        throw new Exception();
                    i += s;
                }
            }
            void Write(ulong v) => WriteAll(BitConverter.GetBytes(v));

            var cmdBuf = new byte[8];
            void ReadAll(byte[] data) {
                var len = data.Length;
                var i = 0;
                while(i < len) {
                    var s = socket.Receive(data, i, len - i, SocketFlags.None);
                    if(s <= 0)
                        throw new Exception();
                    i += s;
                }
            }
            ulong Read() {
                ReadAll(cmdBuf);
                return BitConverter.ToUInt64(cmdBuf);
            }
            
            var def = Core.Defs.First(x => x.Name == name);
            Console.WriteLine("Generating tests");
            var tg = new TestGen(def);
            Parallel.ForEach(tg.InstructionsWithConditions, x => {
                var (insn, disasm, conds) = x;
                Console.WriteLine(disasm);
                var idata = BitConverter.GetBytes(insn);
                foreach(var (pre, post) in conds) {
                    var ms = new HashSet<ulong>();
                    var nnzcv = false;
                    var nzcv = 0UL;
                    foreach(var (k, v) in pre) {
                        if(k is ulong addr) {
                            ms.Add(addr << 12);
                            Write(2);
                            Write(addr << 12);
                            if(!(v is byte[] data)) throw new Exception();
                            if(data.Length == 8192)
                                Console.WriteLine(
                                    $"Foo? {insn:X} {BitConverter.ToUInt32(data, 4):X} {BitConverter.ToUInt64(data, 4):X}");
                            Write((ulong) data.Length);
                            WriteAll(data);
                        } else if(k is string reg) {
                            if(reg[0] == 'X') {
                                Write(1);
                                Write(ulong.Parse(reg.Substring(1)));
                                Write((ulong) v);
                            } else if(reg == "SP") {
                                Write(1);
                                Write(34);
                                Write((ulong) v);
                            } else if(reg == "PC") {
                                Write(1);
                                Write(32);
                                Write((ulong) v);
                            } else if(reg[0] == 'V') {
                                var ri = ulong.Parse(reg.Substring(1));
                                var vec = (Vector128<ulong>) v.As<ulong>();
                                Write(5);
                                Write(ri);
                                Write(vec[0]);
                                Write(vec[1]);
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

                    var er = new Dictionary<ulong, ulong>();
                    var ev = new Dictionary<ulong, (ulong, ulong)>();
                    var em = new Dictionary<ulong, byte[]>();
                    var nenzcv = false;
                    var enzcv = nzcv;
                    pre.PrettyPrint();
                    post.PrettyPrint();
                    foreach(var (k, v) in post) {
                        if(k is ulong addr) {
                            addr <<= 12;
                            Write(4);
                            Write(addr);
                            em[addr] = (byte[]) v;
                            if(!ms.Contains(addr)) {
                                ms.Add(addr);
                                Write(2);
                                Write(addr);
                                Write(0);
                            }
                        } else if(k is string reg) {
                            if(reg[0] == 'X') {
                                Write(3);
                                var rn = ulong.Parse(reg.Substring(1));
                                Write(rn);
                                er[rn] = (ulong) v;
                            } else if(reg == "SP") {
                                Write(3);
                                Write(34);
                                er[34] = (ulong) v;
                            } else if(reg == "PC") {
                                Write(3);
                                Write(32);
                                er[32] = (ulong) v;
                            } else if(reg[0] == 'V') {
                                var rn = ulong.Parse(reg.Substring(1));
                                Write(6);
                                Write(rn);
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

                    Write(1);
                    Write(32);
                    Write(TestGen.PC);
                    if(nenzcv) {
                        Write(1);
                        Write(0x1000);
                        Write(nzcv);
                        Write(3);
                        Write(0x1000);
                        er[0x1000] = enzcv;
                    } else if(nnzcv) {
                        Write(1);
                        Write(0x1000);
                        Write(nzcv);
                    }

                    if(!ms.Contains(TestGen.PC) && !ms.Contains(TestGen.PC - 0x1000)) {
                        Write(2);
                        Write(TestGen.PC);
                        Write(4);
                        WriteAll(idata);
                    }

                    Write(0);

                    Assert.IsTrue(Read() == 1, "Execution");

                    var rc = Read();
                    Assert.AreEqual(er.Count, (int) rc);
                    for(var i = 0; i < (int) rc; ++i) {
                        var rn = Read();
                        var v = Read();
                        Assert.AreEqual(er[rn], v,
                            rn switch { 34 => "SP", 32 => "PC", 0x1000 => "NZCV", _ => $"X{rn}" });
                    }

                    var vc = Read();
                    Assert.AreEqual(ev.Count, (int) vc);
                    for(var i = 0; i < (int) vc; ++i) {
                        var rn = Read();
                        var a = Read();
                        var b = Read();
                        var (ea, eb) = ev[rn];
                        Assert.AreEqual(ea, a, $"V{rn}L");
                        Assert.AreEqual(eb, b, $"V{rn}H");
                    }

                    var mc = Read();
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
                    }
                }
            });
            Assert.Pass();
        }

        static string[] GetTestCases() {
            return Core.Defs.Select(x => x.Name).Where(x => !x.StartsWith("CAS")).OrderBy(x => x).ToArray();
        }
    }
}