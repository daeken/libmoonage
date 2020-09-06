using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;

namespace Arch {
    public class Vector128<T> where T : struct {
        public T[] Data;
        public int Length = default(T) switch {
            byte _ => 16, sbyte _ => 16, 
            ushort _ => 8, short _ => 8, 
            uint _ => 4, int _ => 4, float _ => 4, 
            ulong _ => 2, long _ => 2, double _ => 2, 
            _ => throw new NotImplementedException()
        };

        public T this[int index] { get => Data[index]; set => Data[index] = value; }

        public Vector128(T value, bool single = false) {
            Data = new T[Length];
            for(var i = 0; i < (single ? 1 : Length); ++i)
                Data[i] = value;
        }

        public Vector128(IEnumerable<T> enumerable) => Data = enumerable.ToArray();

        public unsafe Vector128(ulong* data) {
            Data = new T[Length];
            var handle = GCHandle.Alloc(Data, GCHandleType.Pinned);
            var ptr = (ulong*) handle.AddrOfPinnedObject();
            ptr[0] = data[0];
            ptr[1] = data[1];
            handle.Free();
        }

        public static Vector128<T> FromBytes(byte[] data) => new Vector128<byte>(data).As<T>();

        public unsafe Vector128<U> As<U>() where U : struct {
            if(typeof(T) == typeof(U)) return (Vector128<U>) (object) this;
            var handle = GCHandle.Alloc(Data, GCHandleType.Pinned);
            var ptr = (ulong*) handle.AddrOfPinnedObject();
            var nv = new Vector128<U>(ptr);
            handle.Free();
            return nv;
        }

        public dynamic As(EType type) =>
            type switch {
                EInt(false, 8) => (dynamic) As<byte>(), 
                EInt(true, 8) => (dynamic) As<sbyte>(), 
                EInt(false, 16) => (dynamic) As<ushort>(), 
                EInt(true, 16) => (dynamic) As<short>(), 
                EInt(false, 32) => (dynamic) As<uint>(), 
                EInt(true, 32) => (dynamic) As<int>(), 
                EInt(false, 64) => (dynamic) As<ulong>(), 
                EInt(true, 64) => (dynamic) As<long>(), 
                EFloat(32) => (dynamic) As<float>(), 
                EFloat(64) => (dynamic) As<double>(), 
                _ => throw new NotSupportedException($"Cannot cast vector to type {type}")
            };

        public static dynamic FromDynamic(dynamic value) =>
            value switch {
                byte   v => new Vector128<byte  >(v), 
                sbyte  v => new Vector128<sbyte >(v), 
                ushort v => new Vector128<ushort>(v), 
                short  v => new Vector128<short >(v), 
                uint   v => new Vector128<uint  >(v), 
                int    v => new Vector128<int   >(v), 
                float  v => new Vector128<float >(v), 
                long   v => new Vector128<long  >(v), 
                ulong  v => new Vector128<ulong >(v), 
                double v => new Vector128<double>(v), 
                _ => throw new NotImplementedException()
            };

        public Vector128<T> Map(Func<T, T> mapper) => new Vector128<T>(Data.Select(mapper));
        public Vector128<T> Map(Func<int, T, T> mapper) => new Vector128<T>(Data.Select((x, i) => mapper(i, x)));
        public Vector128<T> Map(Func<dynamic, dynamic> mapper) => new Vector128<T>(Data.Select(x => (T) mapper(x)));
        public Vector128<T> MapTwo(Vector128<T> right, Func<T, T, T> mapper) => new Vector128<T>(Data.Zip(right.Data).Select(t => mapper(t.First, t.Second)));
        public Vector128<T> MapTwo(Vector128<T> right, Func<dynamic, dynamic, dynamic> mapper) => new Vector128<T>(Data.Zip(right.Data).Select(t => (T) mapper(t.First, t.Second)));
        
        public Vector128<T> ZeroTop() => new Vector128<T>(Data.Take(Length / 2).Concat(new T[Length / 2]));

        public static Vector128<T> operator +(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a + b);
        public static Vector128<T> operator -(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a - b);
        public static Vector128<T> operator *(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a * b);
        public static Vector128<T> operator /(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a / b);
        public static Vector128<T> operator %(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a % b);
        public static Vector128<T> operator ^(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a ^ b);
        public static Vector128<T> operator |(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a | b);
        public static Vector128<T> operator &(Vector128<T> left, Vector128<T> right) => left.MapTwo(right, (a, b) => a & b);
        
        public static Vector128<T> operator ~(Vector128<T> left) => left.Map(a => ~a);

        public bool Equals<U>(Vector128<U> other) where U : struct {
            var left = As<ulong>();
            var right = other.As<ulong>();
            return left[0] == right[0] && left[1] == right[1];
        }

        public override bool Equals(object obj) {
            if(obj is Vector128<T> v)
                return Data.Zip(v.Data).All(x => x.First.Equals(x.Second));
            return false;
        }

        public override string ToString() => $"Vector128<{typeof(T).Name}> {{ {string.Join(", ", Data.Select(x => x.ToString()))} }}";

        public static Vector128<T> Ensure(dynamic value) =>
            ((Type) value.GetType()).IsValueType
                ? (Vector128<T>) FromDynamic(value).As<T>()
                : (Vector128<T>) value.As<T>();
    }
}