using System;
using System.Runtime.InteropServices;

namespace LocalHvTest {
    public class KvmException : Exception {
        public KvmException(string message) : base(message) {}
    }
    
    public class SafeUnixHandle : SafeHandle {
        public SafeUnixHandle() : base(new IntPtr(-1), true) { }
        protected override bool ReleaseHandle() => Ioctls.Close(handle) != -1;
        public override bool IsInvalid => handle == new IntPtr(-1) || handle == new IntPtr(0xFFFFFFFF);
    }

    public unsafe class MmappedRegion {
        public readonly SafeUnixHandle Handle;
        public readonly void* Pointer;
        readonly ulong Length;

        [DllImport("libc", EntryPoint = "mmap")]
        static extern void* Mmap(void* addr, ulong length, int prot, int flags, int fd, ulong offset);
        [DllImport("libc", EntryPoint = "munmap")]
        static extern void Munmap(void* addr, ulong length);

        public MmappedRegion(SafeUnixHandle handle, int size = 0x1000, int offset = 0) {
            Pointer = Mmap(null, Length = (ulong) size, 4|2, 0x10, (int) handle.DangerousGetHandle(), (ulong) offset);
            if(Pointer == null) throw new KvmException("Could not mmap region");
        }

        ~MmappedRegion() {
            Munmap(Pointer, Length);
        }
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public struct KvmUserspaceMemoryRegion {
        public uint Slot, Flags;
        public ulong GuestPhysAddr, MemorySize, UserspaceAddr;
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public unsafe struct KvmVcpuInit {
        public uint Target;
        public fixed uint Features[7];
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public unsafe struct KvmGuestDebug {
        public const uint ENABLE = 1, SINGLESTEP = 2;
        
        public uint Control;
        uint Pad;
        public fixed ulong Bcr[16];
        public fixed ulong Bvr[16];
        public fixed ulong Wcr[16];
        public fixed ulong Wvr[16];
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public struct KvmOneReg {
        public ulong Id, Addr;
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
        static uint IOR_NR<T>(uint nr) => IO(2, 174, nr, (uint) Marshal.SizeOf<T>());
        
        static readonly uint
            KVM_GET_API_VERSION              = IO_NR(0x00), 
            KVM_CREATE_VM                    = IO_NR(0x01), 
            KVM_CREATE_VCPU                  = IO_NR(0x41), 
            KVM_SET_USER_MEMORY_REGION       = IOW_NR<KvmUserspaceMemoryRegion>(0x46), 
            KVM_RUN                          = IO_NR(0x80), 
            KVM_SET_GUEST_DEBUG              = IOW_NR<KvmGuestDebug>(0x9b), 
            KVM_GET_ONE_REG                  = IOW_NR<KvmOneReg>(0xab), 
            KVM_SET_ONE_REG                  = IOW_NR<KvmOneReg>(0xac), 
            KVM_ARM_VCPU_INIT                = IOW_NR<KvmVcpuInit>(0xae), 
            KVM_ARM_PREFERRED_TARGET         = IOR_NR<KvmVcpuInit>(0xaf);

        internal static uint KvmGetApiVersion(SafeUnixHandle handle) => (uint) Ioctl(handle, KVM_GET_API_VERSION);
        internal static SafeUnixHandle KvmCreateVm(SafeUnixHandle handle) => IoctlHandle(handle, KVM_CREATE_VM);
        internal static int VmSetUserMemoryRegion(SafeUnixHandle handle, KvmUserspaceMemoryRegion region) =>
            Ioctl(handle, KVM_SET_USER_MEMORY_REGION, &region);
        internal static SafeUnixHandle VmCreateVcpu(SafeUnixHandle handle, int id) => IoctlHandle(handle, KVM_CREATE_VCPU);
        internal static bool VcpuRun(SafeUnixHandle handle) => Ioctl(handle, KVM_RUN) == 0;

        internal static bool VmArmPreferredTarget(SafeUnixHandle handle, out KvmVcpuInit init) {
            fixed(KvmVcpuInit* ptr = &init)
                return Ioctl(handle, KVM_ARM_PREFERRED_TARGET, ptr) == 0;
        }

        internal static bool VcpuArmInit(SafeUnixHandle handle, KvmVcpuInit init)
            => Ioctl(handle, KVM_ARM_VCPU_INIT, &init) == 0;

        internal static bool VcpuSetGuestDebug(SafeUnixHandle handle, KvmGuestDebug debug)
            => Ioctl(handle, KVM_SET_GUEST_DEBUG, &debug) == 0;

        internal static bool VcpuGetOneReg(SafeUnixHandle handle, KvmOneReg reg) =>
            Ioctl(handle, KVM_GET_ONE_REG, &reg) == 0;

        internal static bool VcpuSetOneReg(SafeUnixHandle handle, KvmOneReg reg)
            => Ioctl(handle, KVM_SET_ONE_REG, &reg) == 0;
    }

    public unsafe class RegWrapper {
        readonly SafeUnixHandle Handle;
        readonly ulong Base, Stride;
        internal RegWrapper(SafeUnixHandle handle, ulong @base, ulong stride) {
            Handle = handle;
            Base = @base;
            Stride = stride;
        }

        public ulong this[int index] {
            get {
                ulong output;
                if(!Ioctls.VcpuGetOneReg(Handle, new KvmOneReg {
                    Id = Base + (ulong) index * Stride, 
                    Addr = (ulong) &output
                }))
                    throw new KvmException("Could not get register");
                return output;
            }
            set {
                if(!Ioctls.VcpuSetOneReg(Handle, new KvmOneReg {
                    Id = Base + (ulong) index * Stride, 
                    Addr = (ulong) &value
                }))
                    throw new KvmException("Could not set register");
            }
        }
    }

    public unsafe class VecWrapper {
        readonly SafeUnixHandle Handle;
        readonly ulong Base;
        readonly byte[] Buffer = new byte[16];
        internal VecWrapper(SafeUnixHandle handle, ulong @base) {
            Handle = handle;
            Base = @base;
        }

        public (ulong, ulong) this[int index] {
            get {
                fixed(byte* buf = Buffer) {
                    var tb = (ulong*) buf;
                    tb[0] = tb[1] = 0;
                    if(!Ioctls.VcpuGetOneReg(Handle, new KvmOneReg {
                        Id = Base + (ulong) index * 4,
                        Addr = (ulong) buf
                    }))
                        throw new KvmException("Could not get register");
                    return (tb[0], tb[1]);
                }
            }
            set {
                fixed(byte* buf = Buffer) {
                    var tb = (ulong*) buf;
                    tb[0] = value.Item1;
                    tb[1] = value.Item2;
                    if(!Ioctls.VcpuSetOneReg(Handle, new KvmOneReg {
                        Id = Base + (ulong) index * 4,
                        Addr = (ulong) tb
                    }))
                        throw new KvmException("Could not set register");
                }
            }
        }
    }

    public unsafe class VCpu : IDisposable {
        internal readonly SafeUnixHandle Handle;

        public RegWrapper X;
        public VecWrapper V;

        public ulong SP { get => X[34]; set => X[34] = value; }
        public ulong PC { get => X[32]; set => X[32] = value; }

        ulong SR(ulong op0, ulong CRn, ulong op1, ulong op2, ulong CRm) =>
            (0x6030_0000_0013UL << 16) |
            (op0 << 14) |
            (op1 << 11) |
            (CRn << 7) |
            (CRm << 3) | 
            op2;
        
        public ulong CPACR_EL1 {
            get {
                ulong output;
                if(!Ioctls.VcpuGetOneReg(Handle, new KvmOneReg {
                    Id = SR(0b11, 0b0001, 0b000, 0b010, 0b0000), 
                    Addr = (ulong) &output
                }))
                    throw new KvmException("Could not get CPACR_EL1");
                return output;
            }
            set {
                if(!Ioctls.VcpuSetOneReg(Handle, new KvmOneReg {
                    Id = SR(0b11, 0b0001, 0b000, 0b010, 0b0000), 
                    Addr = (ulong) &value
                }))
                    throw new KvmException("Could not set CPACR_EL1");
            }
        }

        public ulong SCTLR_EL1 {
            get {
                ulong output;
                if(!Ioctls.VcpuGetOneReg(Handle, new KvmOneReg {
                    Id = SR(0b11, 0b0001, 0b000, 0b000, 0b0000), 
                    Addr = (ulong) &output
                }))
                    throw new KvmException("Could not get CPACR_EL1");
                return output;
            }
            set {
                if(!Ioctls.VcpuSetOneReg(Handle, new KvmOneReg {
                    Id = SR(0b11, 0b0001, 0b000, 0b000, 0b0000), 
                    Addr = (ulong) &value
                }))
                    throw new KvmException("Could not set CPACR_EL1");
            }
        }

        public ulong NZCV { get => X[33] & 0xF_000_0000UL; set => X[33] = (X[33] & ~0xF_000_0000UL) | value; }

        internal VCpu(SafeUnixHandle handle) {
            Handle = handle;
            X = new RegWrapper(Handle, 0x6030_0000_0010_0000, 2);
            V = new VecWrapper(Handle, 0x6040_0000_0010_0054);
        }

        public bool Init(KvmVcpuInit init) => Ioctls.VcpuArmInit(Handle, init);

        public KvmGuestDebug Debug {
            set {
                if(!Ioctls.VcpuSetGuestDebug(Handle, value))
                    throw new KvmException("Could not set guest debugging");
            }
        }

        public bool Run() => Ioctls.VcpuRun(Handle);

        public void Dispose() => Handle?.Dispose();
    }

    public class Vm : IDisposable {
        internal readonly SafeUnixHandle Handle;

        internal Vm(SafeUnixHandle handle) => Handle = handle;

        public bool SetUserMemoryRegion(KvmUserspaceMemoryRegion region) => Ioctls.VmSetUserMemoryRegion(Handle, region) == 0;

        public VCpu CreateVCpu(int id) {
            var handle = Ioctls.VmCreateVcpu(Handle, id);
            if(Handle.IsInvalid) throw new KvmException("Could not create VCpu");
            return new VCpu(handle);
        }

        public bool GetArmPreferredTarget(out KvmVcpuInit init) => Ioctls.VmArmPreferredTarget(Handle, out init);

        public void Dispose() => Handle?.Dispose();
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
