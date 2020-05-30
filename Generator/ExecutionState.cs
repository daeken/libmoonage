using System;
using System.Collections.Generic;

namespace Generator {
    class BailoutException : Exception {}
    class MissingValueException : Exception {
        public EType Type;
        protected MissingValueException(EType type) { Type = type; }
    }
    class MissingRegisterException : MissingValueException {
        public string Register;
        public MissingRegisterException(string register, EType type) : base(type) { Register = register; }
    }
    class MissingMemoryException : MissingValueException {
        public ulong Address;
        public MissingMemoryException(ulong address, EType type) : base(type) { Address = address; }
    }
    
    public class ExecutionState {
        public readonly Dictionary<string, dynamic> Locals = new Dictionary<string,dynamic>();
        
        public static ExecutionState Cleanroom() => new ExecutionState();

        public dynamic Evaluate(PTree node) {
            switch(node) {
                case PInt pi: return !(pi.Type is EInt ei && !ei.Signed) ? (dynamic) (ulong) pi.Value : pi.Value;
                case PString ps: return ps.String;
                case PName pn when Locals.ContainsKey(pn.Name): return Locals[pn.Name];
                case PList pl: {
                    if(!(pl[0] is PName(var name))) throw new NotSupportedException($"First element of list {node} is not a name: {pl[0]}");
                    if(Program.Statements.TryGetValue(name, out var st) && st.Execute != null)
                        return st.Execute(pl, this);
                    if(Program.Expressions.TryGetValue(name, out var et) && et.Execute != null)
                        return et.Execute(pl, this);
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
    }
}