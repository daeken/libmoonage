using System;
using System.Collections.Generic;
using PrettyPrinter;

namespace Generator {
	public class BuiltinTypes {
		static EType TypeFromName(PTree expr) {
			if(!(expr is PName name)) throw new NotSupportedException($"Attempted to make type from expr {expr.ToPrettyString()}");

			var ns = name.Name;
			if(ns[0] == 'f') return new EFloat(int.Parse(ns.Substring(1)));
			if(ns == "vec") return EType.Vector;
			return ns[0] == 'i' ? new EInt(true, int.Parse(ns.Substring(1))) : new EInt(false, int.Parse(ns.Substring(1)));
		}

		static EType LogicalType(EType a, EType b) {
			if(a is EInt || b is EInt) {
				if(!(a is EInt ai)) throw new NotSupportedException("Logical expression contains lhs that is non-int");
				if(!(b is EInt bi)) throw new NotSupportedException("Logical expression contains rhs that is non-int");
				return new EInt(
					ai.Signed == bi.Signed && ai.Signed,
					Math.Max(ai.Width, bi.Width)
				) { Runtime = ai.Runtime || bi.Runtime };
			}
			if(a is EFloat || b is EFloat) {
				if(!(a is EFloat af)) throw new NotSupportedException("Logical expression contains lhs that is non-float");
				if(!(b is EFloat bf)) throw new NotSupportedException("Logical expression contains rhs that is non-float");
				return new EFloat(Math.Max(af.Width, bf.Width)) { Runtime = af.Runtime || bf.Runtime };
			}
			throw new NotImplementedException("Logical expression has non-int/non-float type");
		}
		
		public static readonly IReadOnlyDictionary<string, Func<PList, EType>> Builtins = new Dictionary<string, Func<PList, EType>> {
			["make-wmask"] = _ => new EInt(false, 64), 
			["make-tmask"] = _ => new EInt(false, 64), 
			["count-leading-zeros"] = x => x[1].Type, 
			["reverse-bits"] = x => x[1].Type, 
			["vector-all"] = _ => EType.Vector.AsRuntime(), 
			["vector-zero-top"] = _ => EType.Vector.AsRuntime(), 
			["vector-insert"] = _ => EType.Unit, 
			["vector-element"] = x => TypeFromName(x[3]).AsRuntime(), 
			["vector-extract"] = x => EType.Vector.AsRuntime(x[1].Type.Runtime || x[2].Type.Runtime), 
			["vector-count-bits"] = _ => EType.Vector, 
			["vector-sum-unsigned"] = _ => new EInt(false, 32), 
			["float-to-fixed-point"] = x => TypeFromName(x[2]).AsRuntime(x[1].Type.Runtime || x[3].Type.Runtime), 
		};
	}
}