using System;
using System.Runtime.InteropServices;

namespace HvTest {
    public class KvmException : Exception {
        public KvmException(string message) : base(message) {}
    }
    
    public class SafeUnixHandle : SafeHandle {
        public SafeUnixHandle() : base(new IntPtr(-1), true) { }
        protected override bool ReleaseHandle() => Ioctls.Close(handle) != -1;
        public override bool IsInvalid => handle == new IntPtr(-1) || handle == new IntPtr(0xFFFFFFFF);
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public struct KvmUserspaceMemoryRegion {
        public uint Slot, Flags;
        public ulong GuestPhysAddr, MemorySize, UserspaceAddr;
    }
    
    unsafe class Ioctls {
        [DllImport("libc", EntryPoint = "open", SetLastError = true)]
        internal static extern SafeUnixHandle Open(string path, uint flag, int mode);

        [DllImport("libc", EntryPoint = "close", SetLastError = true)]
        internal static extern int Close(IntPtr handle);

        [DllImport("libc", EntryPoint = "ioctl", SetLastError = true)]
        internal static extern int Ioctl(SafeUnixHandle handle, uint request, void* buffer);
        [DllImport("libc", EntryPoint = "ioctl", SetLastError = true)]
        internal static extern SafeUnixHandle IoctlHandle(SafeUnixHandle handle, uint request, void* buffer);

        internal static int Ioctl(SafeUnixHandle handle, uint request) => Ioctl(handle, request, null);
        internal static int Ioctl(SafeUnixHandle handle, uint request, int param) => Ioctl(handle, request, (void*) (uint) param);
        internal static SafeUnixHandle IoctlHandle(SafeUnixHandle handle, uint request) => IoctlHandle(handle, request, null);
        internal static SafeUnixHandle IoctlHandle(SafeUnixHandle handle, uint request, int param) => IoctlHandle(handle, request, (void*) (uint) param);

        static uint IO(uint dir, uint ty, uint nr, uint size) => (dir << 30) | (ty << 8) | (nr << 0) | (size << 16);
        static uint IO_NR(uint nr) => IO(0, 174, nr, 0);
        static uint IOW_NR<T>(uint nr) => IO(1, 174, nr, (uint) Marshal.SizeOf<T>());

        static readonly uint
            KVM_GET_API_VERSION              = IO_NR(0x00), 
            KVM_CREATE_VM                    = IO_NR(0x01),
            KVM_CREATE_VCPU                  = IO_NR(0x41), 
            KVM_SET_USER_MEMORY_REGION       = IOW_NR<KvmUserspaceMemoryRegion>(0x46);

        internal static uint KvmGetApiVersion(SafeUnixHandle handle) => (uint) Ioctl(handle, KVM_GET_API_VERSION);
        internal static SafeUnixHandle KvmCreateVm(SafeUnixHandle handle) => IoctlHandle(handle, KVM_CREATE_VM);
        internal static int VmSetUserMemoryRegion(SafeUnixHandle handle, KvmUserspaceMemoryRegion region) =>
            Ioctl(handle, KVM_SET_USER_MEMORY_REGION, &region);
        internal static SafeUnixHandle VmCreateVcpu(SafeUnixHandle handle, int id) => IoctlHandle(handle, KVM_CREATE_VCPU);
    }

    public class VCpu {
        internal readonly SafeUnixHandle Handle;

        internal VCpu(SafeUnixHandle handle) => Handle = handle;
    }

    public class Vm {
        internal readonly SafeUnixHandle Handle;

        internal Vm(SafeUnixHandle handle) => Handle = handle;

        public bool SetUserMemoryRegion(KvmUserspaceMemoryRegion region) => Ioctls.VmSetUserMemoryRegion(Handle, region) == 0;

        public VCpu CreateVCpu(int id) {
            var handle = Ioctls.VmCreateVcpu(Handle, id);
            if(Handle.IsInvalid) throw new KvmException("Could not create VCpu");
            return new VCpu(handle);
        }
    }
    
    public class Kvm {
        readonly SafeUnixHandle Handle;

        public uint Version => Ioctls.KvmGetApiVersion(Handle);
        
        public Kvm() {
            Handle = Ioctls.Open("/dev/kvm", 0x80002, 0); // O_RDWR | O_CLOEXEC
            if(Handle.IsInvalid) throw new KvmException("Could not open /dev/kvm");
        }

        public Vm CreateVm() {
            var handle = Ioctls.KvmCreateVm(Handle);
            if(Handle.IsInvalid) throw new KvmException("Could not create VM");
            return new Vm(handle);
        }
    }
}