using System;
using System.Runtime.InteropServices;

namespace HvTest {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Hello?");
            var kvm = new Kvm();
            Console.WriteLine($"KVM Version: {kvm.Version}");
            var vm = kvm.CreateVm();
            Console.WriteLine($"Created VM: {vm.Handle.DangerousGetHandle()}");
            var addr = (ulong) Marshal.AllocHGlobal(0x2000);
            while((addr & 0xFFF) != 0) addr++;
            var mem = vm.SetUserMemoryRegion(new KvmUserspaceMemoryRegion {
                Slot = 0, Flags = 0, 
                GuestPhysAddr = 0x4_5000_0000UL, 
                MemorySize = 0x1000, 
                UserspaceAddr = addr
            });
            Console.WriteLine($"Memory? {mem}");
            var vcpu = vm.CreateVCpu(0);
            Console.WriteLine($"Created VCpu: {vcpu.Handle.DangerousGetHandle()}");
            
            if(vm.GetArmPreferredTarget(out var init))
                Console.WriteLine("Got preferred target!");
            
            if(vcpu.Init(init))
                Console.WriteLine("Initialized vcpu");
            
            vcpu.Debug = new KvmGuestDebug { Control = KvmGuestDebug.ENABLE | KvmGuestDebug.SINGLESTEP };

            vcpu.PC = 0x4_5000_0000UL;
            vcpu.X[0] = 123;
            vcpu.X[1] = 100;
            unsafe {
                *(uint*) addr = 0x8b010002;
            }
            Console.WriteLine($"Set PC to {vcpu.PC:X}");
            Console.WriteLine($"X2 == {vcpu.X[2]}");
            
            Console.WriteLine("Attempting to single step CPU");

            var rs = vcpu.Run();
            Console.WriteLine($"Run success? {rs}");
            Console.WriteLine($"X2 == {vcpu.X[2]}");
        }
    }
}