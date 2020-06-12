using System;

namespace Arch {
    public static class Extensions {
        public static dynamic AsDynamic(this object value) => value;
        public static T AsDynamic<T>(this object value, Func<dynamic, T> func) => func(value);
        public static bool AsBool(this object value) => value.AsDynamic(x => x is bool b ? b : x != 0);
        public static dynamic AsNonBool(this object value) => value is bool b ? (dynamic) (b ? 1UL : 0UL) : value;
        public static string AsName(this PTree node)
            => node is PName(var name) ? name : throw new InvalidCastException(); 
        public static dynamic WithCommonType(this (dynamic A, dynamic B) values, Func<dynamic, dynamic, dynamic> func) {
            var (a, b) = values;
            if(a.GetType() == b.GetType())
                return func(a, b);
            if((a is double _ && !(b is double _)) || (b is double _ && !(a is double _)))
                return func((double) a, (double) b);
            if((a is float _ && !(b is float _)) || (b is float _ && !(a is float _)))
                return func((float) a, (float) b);
            if(a is bool)
                a = a ? 1UL : 0UL;
            if(b is bool)
                b = b ? 1UL : 0UL;
            return func((ulong) a, (ulong) b); // TODO: Make this cast to the proper type
        }

        public static object If<T>(this object value, Func<T, dynamic> func) => value is T tvalue ? func(tvalue) : value;
        public static object IfNot<T>(this object value, Func<dynamic, dynamic> func)
            => value is T ? value : func(value);
    }
}