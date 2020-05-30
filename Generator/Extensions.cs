using System;

namespace Generator {
    public static class Extensions {
        public static dynamic AsDynamic(this object value) => value;
        public static T AsDynamic<T>(this object value, Func<dynamic, T> func) => func(value);
        public static bool AsBool(this object value) => value.AsDynamic(x => x is bool b ? b : x != 0);
        public static string AsName(this PTree node)
            => node is PName(var name) ? name : throw new InvalidCastException(); 
        public static dynamic WithCommonType(this (dynamic A, dynamic B) values, Func<dynamic, dynamic, dynamic> func) {
            var (a, b) = values;
            if(a.GetType() == b.GetType())
                return func(a, b);
            return func((ulong) a, (ulong) b); // TODO: Make this cast to the proper type
        }
    }
}