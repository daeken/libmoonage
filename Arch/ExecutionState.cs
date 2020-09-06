using System;
using System.Collections.Generic;
using System.Linq;

namespace Arch {
    class BailoutException : Exception {}
    class MissingValueException : Exception {
        public EType Type;
        protected MissingValueException(EType type) => Type = type;
    }
    class MissingRegisterException : MissingValueException {
        public string Register;
        public MissingRegisterException(string register) : base(EType.Undef) => Register = register;
        public override string ToString() => $"Missing register {Register}";
    }
    class MissingMemoryException : MissingValueException {
        public ulong Address;
        public MissingMemoryException(ulong address, EType type) : base(type) => Address = address;
        public override string ToString() => $"Missing memory 0x{Address:X}";
    }
    
    public class ExecutionState {
        public readonly Dictionary<string, dynamic> Locals = new Dictionary<string,dynamic>();
        public readonly Dictionary<string, dynamic> Registers = new Dictionary<string, dynamic>();
        public readonly Dictionary<ulong, byte[]> Memory = new Dictionary<ulong, byte[]>();
        
        public static ExecutionState Cleanroom() => new ExecutionState();

        dynamic Clamp(EType type, dynamic value) => type switch {
            EInt(true, var width) when width <= 8 => (dynamic) (sbyte) Extensions.AsNonBool(value),
            EInt(true, var width) when width <= 16 => (dynamic) (short) Extensions.AsNonBool(value),
            EInt(true, var width) when width <= 32 => (dynamic) (int) Extensions.AsNonBool(value),
            EInt(true, var width) when width <= 64 => (dynamic) (long) Extensions.AsNonBool(value),
            EInt(false, var width) when width <= 8 => (dynamic) (byte) Extensions.AsNonBool(value),
            EInt(false, var width) when width <= 16 => (dynamic) (ushort) Extensions.AsNonBool(value),
            EInt(false, var width) when width <= 32 => (dynamic) (uint) Extensions.AsNonBool(value),
            EInt(false, var width) when width <= 64 => (dynamic) (ulong) Extensions.AsNonBool(value),
            EFloat(32) => (dynamic) (float) value,
            EFloat(64) => (dynamic) (double) value,
            _ => value
        };

        public dynamic Evaluate(PTree node) {
            switch(node) {
                case PInt pi: return !(pi.Type is EInt ei && !ei.Signed) ? (dynamic) (ulong) pi.Value : pi.Value;
                case PString ps: return ps.String;
                case PName pn when Locals.ContainsKey(pn.Name): return Locals[pn.Name];
                case PList pl: {
                    if(!(pl[0] is PName(var name))) throw new NotSupportedException($"First element of list {node} is not a name: {pl[0]}");
                    if(Core.Statements.TryGetValue(name, out var st) && st.Execute != null)
                        return st.Execute(pl, this);
                    if(Core.Expressions.TryGetValue(name, out var et) && et.Execute != null)
                        return Clamp(pl.Type, et.Execute(pl, this));
                    throw new NotImplementedException($"No compile-time execution of {node}");
                }
                default: throw new NotImplementedException($"Evaluation failed on node {node}");
            }
        }

        public dynamic Evaluate(IEnumerable<PTree> list) {
            dynamic value = null;
            foreach(var elem in list) {
                var sub = Evaluate(elem);
                if(sub != null)
                    value = sub;
            }
            return value;
        }

        public dynamic GetRegister(string name) {
            if(name == "X31")
                return 0UL;
            if(Registers.TryGetValue(name, out var value))
                return value;
            throw new MissingRegisterException(name);
        }

        public dynamic GetMemory(ulong addr, EType type) {
            if(addr > 0xFF_FFFF_FFFFUL)
                throw new BailoutException();
            if((addr & 0x7) != 0)
                throw new BailoutException();
            var page = addr >> 12;
            if(!Memory.TryGetValue(page, out var mem)) throw new MissingMemoryException(addr, type);
            mem = mem.Skip((int) (addr - (page << 12))).ToArray();
            return type switch {
                EInt(false, 8) => (dynamic) mem[0], 
                EInt(false, 16) => (dynamic) BitConverter.ToUInt16(mem), 
                EInt(false, 32) => (dynamic) BitConverter.ToUInt32(mem), 
                EInt(false, 64) => (dynamic) BitConverter.ToUInt64(mem), 
                EInt(true, 16) => (dynamic) BitConverter.ToInt16(mem), 
                EInt(true, 32) => (dynamic) BitConverter.ToInt32(mem), 
                EInt(true, 64) => (dynamic) BitConverter.ToInt64(mem), 
                EFloat(32) => (dynamic) BitConverter.ToSingle(mem), 
                EFloat(64) => (dynamic) BitConverter.ToDouble(mem),
                EVector _ => (dynamic) new Vector128<double>(new[] { BitConverter.ToDouble(mem), BitConverter.ToDouble(mem, 8) }), 
                _ => throw new NotSupportedException()
            };
        }

        public void SetMemory(ulong addr, dynamic value) {
            if(addr > 0xFF_FFFF_FFFFUL)
                throw new BailoutException();
            if((addr & 0x7) != 0)
                throw new BailoutException();
            var page = addr >> 12;
            if(!Memory.TryGetValue(page, out var mem))
                mem = Memory[page] = new byte[8192];
            var bytes = ((object) value).GetBytes();
            Array.Copy(bytes, 0, mem, (int) (addr - (page << 12)), bytes.Length);
        }
    }
}