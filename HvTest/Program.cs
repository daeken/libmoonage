using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Threading;

namespace HvTest {
    class Program {
        unsafe class Worker {
            readonly Kvm Kvm = new Kvm();
            readonly ulong[] PageBases = new ulong[8];
            
            public Worker() {
                for(var i = 0; i < 8; ++i) {
                    var addr = (ulong) Marshal.AllocHGlobal(0x3000);
                    while((addr & 0xFFF) != 0) addr++;
                    PageBases[i] = addr;
                }
            }

            public bool Run(Dictionary<int, ulong> registers, Dictionary<int, (ulong, ulong)> vectors, Dictionary<ulong, byte[]> memory, List<int> outRegs, List<int> outVecs, List<ulong> outMem) {
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
                    foreach(var (addr, data) in memory) {
                        Marshal.Copy(data, 0, (IntPtr) PageBases[mi], data.Length);
                        //Console.WriteLine($"Attempting to assign memory at 0x{addr:X}");
                        if(!vm.SetUserMemoryRegion(new KvmUserspaceMemoryRegion {
                            Slot = (uint) mi,
                            Flags = 0,
                            GuestPhysAddr = addr,
                            MemorySize = 0x2000,
                            UserspaceAddr = PageBases[mi]
                        })) {
                            Console.WriteLine($"Failed to assign memory region for addr 0x{addr:X}");
                            return false;
                        }
                        caddrs[addr] = PageBases[mi++];
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
        }
        
        static void Main(string[] args) {
            var available = new ConcurrentQueue<Worker>(Enumerable.Range(0, 10).Select(_ => new Worker()));
            
            var server = new TcpListener(IPAddress.Any, 12347);
            server.Start(100);
            Console.WriteLine("Starting server");
            while(true) {
                var client = server.AcceptSocket();
                new Thread(p => {
                    var socket = (Socket) p;
                    var dataBufs = Enumerable.Range(0, 8).Select(_ => new byte[0x2000]).ToArray();
                    var cmdBuf = new byte[8];
                    ulong ReadOne() {
                        var i = 0;
                        while(i < 8) {
                            var read = socket.Receive(cmdBuf, i, 8 - i, SocketFlags.None);
                            if(read <= 0)
                                throw new Exception();
                            i += read;
                        }
                        return BitConverter.ToUInt64(cmdBuf);
                    }

                    void WriteAll(byte[] data, int len) {
                        var i = 0;
                        while(i < len) {
                            var s = socket.Send(data, i, len - i, SocketFlags.None);
                            if(s <= 0)
                                throw new Exception();
                            i += s;
                        }
                    }
                    void WriteOne(ulong value) => WriteAll(BitConverter.GetBytes(value), 8);
                    try {
                        while(true) {
                            var bi = 0;
                            var regs = new Dictionary<int, ulong>();
                            var vecs = new Dictionary<int, (ulong, ulong)>();
                            var mem = new Dictionary<ulong, byte[]>();
                            var outRegs = new List<int>();
                            var outVecs = new List<int>();
                            var outMem = new List<ulong>();
                            while(true) {
                                switch(ReadOne()) {
                                    case 0: { // Run!
                                        //Console.WriteLine("Running...");
                                        var success = false;
                                        while(true) {
                                            if(available.TryDequeue(out var worker)) {
                                                try {
                                                    success = worker.Run(regs, vecs, mem, outRegs, outVecs, outMem);
                                                } catch(Exception e) {
                                                    Console.WriteLine($"Worker failed: {e}");
                                                }
                                                available.Enqueue(worker);
                                                break;
                                            }
                                            Thread.Sleep(1);
                                        }
                                        if(success) {
                                            //Console.WriteLine("Success");
                                            WriteOne(1);
                                            WriteOne((ulong) outRegs.Count);
                                            foreach(var n in outRegs) {
                                                WriteOne((ulong) n);
                                                WriteOne(regs[n]);
                                            }
                                            WriteOne((ulong) outVecs.Count);
                                            foreach(var n in outVecs) {
                                                WriteOne((ulong) n);
                                                var (a, b) = vecs[n];
                                                WriteOne(a);
                                                WriteOne(b);
                                            }
                                            WriteOne((ulong) outMem.Count);
                                            foreach(var addr in outMem) {
                                                WriteOne(addr);
                                                WriteOne((ulong) mem[addr].Length);
                                                WriteAll(mem[addr], mem[addr].Length);
                                            }
                                        } else {
                                            //Console.WriteLine("Failure");
                                            WriteOne(0);
                                        }
                                        goto end;
                                    }
                                    case 1: { // Set reg
                                        var reg = ReadOne();
                                        var value = ReadOne();
                                        regs[(int) reg] = value;
                                        break;
                                    }
                                    case 5: { // Set vec
                                        var reg = ReadOne();
                                        var value1 = ReadOne();
                                        var value2 = ReadOne();
                                        vecs[(int) reg] = (value1, value2);
                                        break;
                                    }
                                    case 2: { // Set memory
                                        var addr = ReadOne();
                                        var len = (int) ReadOne();
                                        var buf = dataBufs[bi++];
                                        var i = 0;
                                        while(i < len) {
                                            var r = socket.Receive(buf, i, len - i, SocketFlags.None);
                                            if(r <= 0)
                                                throw new Exception();
                                            i += r;
                                        }
                                        mem[addr] = buf;
                                        break;
                                    }
                                    case 3: { // Request reg
                                        outRegs.Add((int) ReadOne());
                                        break;
                                    }
                                    case 4: { // Request memory
                                        outMem.Add(ReadOne());
                                        break;
                                    }
                                    case 6: { // Request vec
                                        outVecs.Add((int) ReadOne());
                                        break;
                                    }
                                    default:
                                        throw new NotImplementedException();
                                }
                                continue;
                                end:
                                    while(--bi >= 0)
                                        dataBufs[bi].Initialize();
                                    break;
                            }
                        }
                    } catch(Exception) { }
                }).Start(client);
            }
        }
    }
}