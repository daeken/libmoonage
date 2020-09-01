#pragma once

#include <iostream>
#include <ios>
#include <utility>

#include "common.h"
#include "lightRecompiler.h"

template<typename...> inline constexpr bool false_v = false;

template<typename T> class LightRuntimeValue;
template<typename CondT, typename ValueT>
inline LightRuntimeValue<ValueT> Ternary(LightRuntimeValue<CondT> cond, LightRuntimeValue<ValueT> a, LightRuntimeValue<ValueT> b);

template<typename T>
class LightRuntimeValue {
public:
    using Type = T;
    std::function<void()> generator;

    template<typename U = T>
    inline LightRuntimeValue(T value) {
        generator = [value]() {
            if constexpr(sizeof(T) == 16) {
                auto vec = (Vector128<uint64_t>) value;
                LC->mov(rdx, vec[1]);
                LC->mov(rax, vec[0]);
                LC->push(rdx);
                LC->push(rax);
            } else if constexpr(sizeof(T) < 4)
                LC->push((uint32_t) value);
            else if constexpr(sizeof(T) == 4)
                LC->push(*(uint32_t*) &value);
            else if constexpr(sizeof(T) == 8) {
                LC->mov(rax, *(uint64_t*) &value);
                LC->push(rax);
            } else
                static_assert(false_v<T>, "Unsupported type");
        };
    }

    inline LightRuntimeValue(std::function<void()> generator) : generator(std::move(generator)) {}

    inline void Emit() const {
        generator();
    }

    template <typename OT>
    operator LightRuntimeValue<OT>() const {
        if constexpr(std::is_same_v<T, OT> || (sizeof(T) == sizeof(OT) && !std::is_floating_point_v<OT> && !std::is_floating_point_v<T>))
            return LightRuntimeValue<OT>(generator);
        return LightRuntimeValue<OT>([__this=*this]() {
            __this.Emit();
            if constexpr(std::is_floating_point_v<OT>) {
                throw "Unsupported cast";//static_assert(false_v<T>, "Unsupported type");
            } else if constexpr(sizeof(OT) == 16 && sizeof(T) == 16) {
                // We shouldn't have to do anything at all here
            } else if constexpr(sizeof(OT) == 16) {
                // Just add a high zero
                LC->xor_(rax, rax);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 16) {
                LC->add(rsp, 8);
                if constexpr(sizeof(OT) == 8) {
                } else {
                    LC->pop(rax);
                    if constexpr(sizeof(OT) == 1)
                        LC->mov(al, al);
                    else if constexpr(sizeof(OT) == 2)
                        LC->mov(ax, ax);
                    else if constexpr(sizeof(OT) == 4)
                        LC->mov(eax, eax);
                    else
                        static_assert(false_v<T>, "Unsupported type");
                    LC->push(rax);
                }
            } else if constexpr(std::is_signed_v<OT> && sizeof(OT) > sizeof(T)) {
                Xbyak::Reg a, b;
                LC->pop(rax);
                if constexpr(sizeof(OT) == 2)
                    a = ax;
                else if constexpr(sizeof(OT) == 4)
                    a = eax;
                else if constexpr(sizeof(OT) == 8)
                    a = rax;
                else
                    static_assert(false_v<T>, "Unsupported type");
                if constexpr(sizeof(T) == 1)
                    b = al;
                else if constexpr(sizeof(T) == 2)
                    b = ax;
                else if constexpr(sizeof(T) == 4)
                    b = eax;
                else
                    static_assert(false_v<T>, "Unsupported type");
                LC->movsx(a, b);
                LC->push(rax);
            } else {
                Xbyak::Reg a, b;
                LC->pop(rax);
                if constexpr(sizeof(OT) == 1)
                    a = al;
                else if constexpr(sizeof(OT) == 2)
                    a = ax;
                else if constexpr(sizeof(OT) == 4)
                    a = eax;
                else if constexpr(sizeof(OT) == 8)
                    a = rax;
                else
                    static_assert(false_v<T>, "Unsupported type");
                if constexpr(sizeof(T) == 1)
                    b = al;
                else if constexpr(sizeof(T) == 2)
                    b = ax;
                else if constexpr(sizeof(T) == 4)
                    b = eax;
                else if constexpr(sizeof(T) == 8)
                    b = rax;
                else
                    static_assert(false_v<T>, "Unsupported type");
                LC->mov(a, b);
                LC->push(rax);
            }
        });
    }

    inline LightRuntimeValue<T> Store() const {
        auto offset = (LightLocalOffset += sizeof(T) > 8 ? sizeof(T) : 8);
        Emit();
        if(sizeof(T) == 16) {
            LC->pop(rdx);
            LC->pop(rax);
            LC->mov(ptr[rbp - offset], rax);
            LC->mov(ptr[rbp - offset + 8], rdx);
        } else {
            LC->pop(rax);
            LC->mov(ptr[rbp - offset], rax);
        }
        return LightRuntimeValue<T>([offset]() {
            if constexpr(sizeof(T) == 16) {
                LC->mov(rax, ptr[rbp - offset]);
                LC->mov(rdx, ptr[rbp - offset + 8]);
                LC->push(rax);
                LC->push(rdx);
            } else {
                LC->mov(rax, ptr[rbp - offset]);
                LC->push(rax);
            }
        });
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> Abs() const {
        throw "Unimplemented";
    }

    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LightRuntimeValue<T> operator+(LightRuntimeValue<element_t<U>> right) const {
        return *this + right.CreateVector();
    }
    LightRuntimeValue<T> operator+(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(std::is_floating_point_v<T>) {
                if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movd(xmm0, eax);
                    LC->movd(xmm1, edx);
                    LC->addss(xmm0, xmm1);
                    LC->movd(eax, xmm0);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movq(xmm0, rax);
                    LC->movq(xmm1, rdx);
                    LC->addsd(xmm0, xmm1);
                    LC->movq(rax, xmm0);
                    LC->push(rax);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            } else if constexpr(is_vector_t<T>()) {
                LC->pop(rdx);
                LC->pop(rax);
                LC->movq(xmm0, rax);
                LC->pinsrq(xmm0, rdx, 1);
                LC->pop(rdx);
                LC->pop(rax);
                LC->movq(xmm1, rax);
                LC->pinsrq(xmm1, rdx, 1);
                if constexpr(sizeof(element_t<T>) == 1)
                    LC->paddb(xmm0, xmm1);
                else if constexpr(sizeof(element_t<T>) == 2)
                    LC->paddw(xmm0, xmm1);
                else if constexpr(sizeof(element_t<T>) == 4) {
                    if constexpr(std::is_floating_point_v<T>)
                        LC->addps(xmm0, xmm1);
                    else
                        LC->paddd(xmm0, xmm1);
                } else if constexpr(sizeof(element_t<T>) == 8) {
                    if constexpr(std::is_floating_point_v<T>)
                        LC->addpd(xmm0, xmm1);
                    else
                        LC->paddq(xmm0, xmm1);
                } else
                    static_assert(false_v<T>, "Unsupported type");
                LC->movq(rax, xmm0);
                LC->movhlps(xmm0, xmm0);
                LC->movq(rdx, xmm0);
                LC->push(rax);
                LC->push(rdx);
            } else {
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->add(al, dl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->add(ax, dx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->add(eax, edx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->add(rax, rdx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 16) {
                    LC->pop(rdx);
                    LC->pop(rax);
                    LC->pop(r9);
                    LC->pop(r8);
                    LC->add(rax, r8);
                    LC->adc(rdx, r9);
                    LC->push(rax);
                    LC->push(rdx);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            }
        });
    }
    template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
    friend LightRuntimeValue<T> operator+(T left, LightRuntimeValue<T> right) { return (LightRuntimeValue<T>) left + right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LightRuntimeValue<T> operator-(LightRuntimeValue<element_t<U>> right) const {
        return *this - right.CreateVector();
    }
    LightRuntimeValue<T> operator-(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(std::is_floating_point_v<T>) {
                if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movd(xmm0, eax);
                    LC->movd(xmm1, edx);
                    LC->subss(xmm0, xmm1);
                    LC->movd(eax, xmm0);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movq(xmm0, rax);
                    LC->movq(xmm1, rdx);
                    LC->subsd(xmm0, xmm1);
                    LC->movq(rax, xmm0);
                    LC->push(rax);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            } else if constexpr(is_vector_t<T>()) {
                LC->pop(rdx);
                LC->pop(rax);
                LC->movq(xmm0, rax);
                LC->pinsrq(xmm0, rdx, 1);
                LC->pop(rdx);
                LC->pop(rax);
                LC->movq(xmm1, rax);
                LC->pinsrq(xmm1, rdx, 1);
                if constexpr(sizeof(element_t<T>) == 1)
                    LC->psubb(xmm0, xmm1);
                else if constexpr(sizeof(element_t<T>) == 2)
                    LC->psubw(xmm0, xmm1);
                else if constexpr(sizeof(element_t<T>) == 4) {
                    if constexpr(std::is_floating_point_v<element_t<T>>)
                        LC->subps(xmm0, xmm1);
                    else
                        LC->psubd(xmm0, xmm1);
                } else if constexpr(sizeof(element_t<T>) == 8) {
                    if constexpr(std::is_floating_point_v<element_t<T>>)
                        LC->subpd(xmm0, xmm1);
                    else
                        LC->psubq(xmm0, xmm1);
                } else
                    static_assert(false_v<T>, "Unsupported type");
                LC->movq(rax, xmm0);
                LC->movhlps(xmm0, xmm0);
                LC->movq(rdx, xmm0);
                LC->push(rax);
                LC->push(rdx);
            } else {
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->sub(al, dl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->sub(ax, dx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->sub(eax, edx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->sub(rax, rdx);
                    LC->push(rax);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            }
        });
    }
    friend LightRuntimeValue<T> operator-(T left, LightRuntimeValue<T> right) { return (LightRuntimeValue<T>) left - right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LightRuntimeValue<T> operator*(LightRuntimeValue<element_t<U>> right) const {
        return *this * right.CreateVector();
    }

    LightRuntimeValue<T> operator*(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(std::is_floating_point_v<T>) {
                if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movd(xmm0, eax);
                    LC->movd(xmm1, edx);
                    LC->mulss(xmm0, xmm1);
                    LC->movd(eax, xmm0);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movq(xmm0, rax);
                    LC->movq(xmm1, rdx);
                    LC->mulsd(xmm0, xmm1);
                    LC->movq(rax, xmm0);
                    LC->push(rax);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            } else if constexpr(is_vector_t<T>()) {
                if constexpr(is_floating_point<T>()) {
                    LC->pop(rdx);
                    LC->pop(rax);
                    LC->movq(xmm0, rax);
                    LC->pinsrq(xmm0, rdx, 1);
                    LC->pop(rdx);
                    LC->pop(rax);
                    LC->movq(xmm1, rax);
                    LC->pinsrq(xmm1, rdx, 1);
                    if constexpr(sizeof(element_t<T>) == 4)
                        LC->mulps(xmm0, xmm1);
                    else if constexpr(sizeof(element_t<T>) == 8)
                        LC->mulpd(xmm0, xmm1);
                    else
                        static_assert(false_v<T>, "Unsupported type");
                    LC->movq(rax, xmm0);
                    LC->movhlps(xmm0, xmm0);
                    LC->movq(rdx, xmm0);
                    LC->push(rax);
                    LC->push(rdx);
                } else {
                    LC->mov(rdi, rsp);
                    if constexpr(sizeof(element_t<T>) == 1)
                        LC->call(is_signed<T>() ? (void*) mul_i8_vector : (void*) mul_u8_vector);
                    else if constexpr(sizeof(element_t<T>) == 2)
                        LC->call(is_signed<T>() ? (void*) mul_i16_vector : (void*) mul_u16_vector);
                    else if constexpr(sizeof(element_t<T>) == 4)
                        LC->call(is_signed<T>() ? (void*) mul_i32_vector : (void*) mul_u32_vector);
                    else if constexpr(sizeof(element_t<T>) == 8)
                        LC->call(is_signed<T>() ? (void*) mul_i64_vector : (void*) mul_u64_vector);
                    else
                        static_assert(false_v<T>, "Unsupported type");
                    LC->add(rsp, 16);
                }
            } else {
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->mul(dl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->mul(dx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->mul(edx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->mul(rdx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 16) {
                    LC->mov(rdi, rsp);
                    LC->call(is_signed<T>() ? (void*) mul_i128 : (void*) mul_u128);
                    LC->add(rsp, 16);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            }
        });
    }
    friend LightRuntimeValue<T> operator*(T left, LightRuntimeValue<T> right) { return (LightRuntimeValue<T>) left * right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LightRuntimeValue<T> operator/(LightRuntimeValue<element_t<U>> right) const {
        return *this / right.CreateVector();
    }
    LightRuntimeValue<T> operator/(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(std::is_floating_point_v<T>) {
                if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movd(xmm0, eax);
                    LC->movd(xmm1, edx);
                    LC->divss(xmm0, xmm1);
                    LC->movd(eax, xmm0);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->movq(xmm0, rax);
                    LC->movq(xmm1, rdx);
                    LC->divsd(xmm0, xmm1);
                    LC->movq(rax, xmm0);
                    LC->push(rax);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            } else if constexpr(is_vector_t<T>()) {
                if constexpr(is_floating_point<T>()) {
                    LC->pop(rdx);
                    LC->pop(rax);
                    LC->movq(xmm0, rax);
                    LC->pinsrq(xmm0, rdx, 1);
                    LC->pop(rdx);
                    LC->pop(rax);
                    LC->movq(xmm1, rax);
                    LC->pinsrq(xmm1, rdx, 1);
                    if constexpr(sizeof(element_t<T>) == 4)
                        LC->divps(xmm0, xmm1);
                    else if constexpr(sizeof(element_t<T>) == 8)
                        LC->divpd(xmm0, xmm1);
                    else
                        static_assert(false_v<T>, "Unsupported type");
                    LC->movq(rax, xmm0);
                    LC->movhlps(xmm0, xmm0);
                    LC->movq(rdx, xmm0);
                    LC->push(rax);
                    LC->push(rdx);
                } else {
                    LC->mov(rdi, rsp);
                    if constexpr(sizeof(element_t<T>) == 1)
                        LC->call(is_signed<T>() ? (void*) div_i8_vector : (void*) div_u8_vector);
                    else if constexpr(sizeof(element_t<T>) == 2)
                        LC->call(is_signed<T>() ? (void*) div_i16_vector : (void*) div_u16_vector);
                    else if constexpr(sizeof(element_t<T>) == 4)
                        LC->call(is_signed<T>() ? (void*) div_i32_vector : (void*) div_u32_vector);
                    else if constexpr(sizeof(element_t<T>) == 8)
                        LC->call(is_signed<T>() ? (void*) div_i64_vector : (void*) div_u64_vector);
                    else
                        static_assert(false_v<T>, "Unsupported type");
                    LC->add(rsp, 16);
                }
            } else {
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->mov(al, al);
                    LC->div(dl);
                    LC->mov(al, al);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->xor_(rdx, rdx);
                    LC->div(cx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->xor_(rdx, rdx);
                    LC->div(ecx);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->xor_(rdx, rdx);
                    LC->div(rcx);
                    LC->push(rax);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            }
        });
    }
    friend LightRuntimeValue<T> operator/(T left, LightRuntimeValue<T> right) { return (LightRuntimeValue<T>) left / right; }

    LightRuntimeValue<T> operator%(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(std::is_floating_point_v<T>)
                static_assert(false_v<T>, "Unsupported type");
            else if constexpr(is_vector_t<T>())
                static_assert(false_v<T>, "Unsupported type");
            else {
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rdx);
                    LC->mov(al, al);
                    LC->div(dl);
                    LC->mov(al, ah);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->xor_(rdx, rdx);
                    LC->div(cx);
                    LC->push(rdx);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->xor_(rdx, rdx);
                    LC->div(ecx);
                    LC->push(rdx);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->xor_(rdx, rdx);
                    LC->div(rcx);
                    LC->push(rdx);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            }
        });
    }
    friend LightRuntimeValue<T> operator%(T left, LightRuntimeValue<T> right) { return (LightRuntimeValue<T>) left % right; }

    LightRuntimeValue<T> operator-() {
        static_assert(is_signed<T>(), "Negation only makes sense for signed types");
        return LightRuntimeValue<T>([__this=*this]() {
            __this.Emit();
            if constexpr(sizeof(T) == 1) {
                LC->pop(rax);
                LC->neg(al);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 2) {
                LC->pop(rax);
                LC->neg(ax);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 4) {
                LC->pop(rax);
                LC->neg(eax);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 8) {
                LC->pop(rax);
                LC->neg(rax);
                LC->push(rax);
            } else
                static_assert(false_v<T>, "Unsupported type");
        });
    }

    LightRuntimeValue<T> operator<<(LightRuntimeValue<T> right) const {
        return Ternary(
            right >= (sizeof(T) * 8),
            (LightRuntimeValue<T>) (T) 0,
            LightRuntimeValue<T>([__this=*this, right]() {
                right.Emit();
                __this.Emit();
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->shl(al, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->shl(ax, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->shl(eax, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    LC->shl(rax, cl);
                    LC->push(rax);
                } else
                    throw "Unsupported";//static_assert(false_v<T>, "Unsupported type");
            })
        );
    }
    LightRuntimeValue<T> operator>>(LightRuntimeValue<T> right) const {
        return Ternary(
            (LightRuntimeValue<uint64_t>) right >= (sizeof(T) * 8),
            (LightRuntimeValue<T>) (T) 0,
            LightRuntimeValue<T>([__this=*this, right]() {
                right.Emit();
                __this.Emit();
                if constexpr(sizeof(T) == 1) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    if(is_signed<T>())
                        LC->sar(al, cl);
                    else
                        LC->shr(al, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 2) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    if(is_signed<T>())
                        LC->sar(ax, cl);
                    else
                        LC->shr(ax, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 4) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    if(is_signed<T>())
                        LC->sar(eax, cl);
                    else
                        LC->shr(eax, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 8) {
                    LC->pop(rax);
                    LC->pop(rcx);
                    if(is_signed<T>())
                        LC->sar(rax, cl);
                    else
                        LC->shr(rax, cl);
                    LC->push(rax);
                } else if constexpr(sizeof(T) == 16) {
                    LC->mov(rdi, rsp);
                    LC->call(is_signed<T>() ? (void*) shr_i128 : (void*) shr_u128);
                    LC->add(rsp, 16);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            })
        );
    }
    LightRuntimeValue<T> operator&(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(sizeof(T) == 1) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->and_(al, dl);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 2) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->and_(ax, dx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 4) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->and_(eax, edx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 8) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->and_(rax, rdx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 16) {
                LC->pop(rdx);
                LC->pop(rax);
                LC->pop(r9);
                LC->pop(r8);
                LC->and_(rax, r8);
                LC->and_(rdx, r9);
                LC->push(rax);
                LC->push(rdx);
            } else
                static_assert(false_v<T>, "Unsupported type");
        });
    }
    LightRuntimeValue<T> operator|(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(sizeof(T) == 1) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->or_(al, dl);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 2) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->or_(ax, dx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 4) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->or_(eax, edx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 8) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->or_(rax, rdx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 16) {
                LC->pop(rdx);
                LC->pop(rax);
                LC->pop(r9);
                LC->pop(r8);
                LC->or_(rax, r8);
                LC->or_(rdx, r9);
                LC->push(rax);
                LC->push(rdx);
            } else
                static_assert(false_v<T>, "Unsupported type");
        });
    }
    LightRuntimeValue<T> operator^(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            if constexpr(sizeof(T) == 1) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->xor_(al, dl);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 2) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->xor_(ax, dx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 4) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->xor_(eax, edx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 8) {
                LC->pop(rax);
                LC->pop(rdx);
                LC->xor_(rax, rdx);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 16) {
                LC->pop(rdx);
                LC->pop(rax);
                LC->pop(r9);
                LC->pop(r8);
                LC->xor_(rax, r8);
                LC->xor_(rdx, r9);
                LC->push(rax);
                LC->push(rdx);
            } else
                static_assert(false_v<T>, "Unsupported type");
        });
    }
    LightRuntimeValue<bool> operator!() const {
        return LightRuntimeValue<T>([__this=*this]() {
            __this.Emit();
            LC->pop(rax);
            LC->xor_(rdx, rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                static_assert(false_v<T>, "Unsupported type");
            LC->je(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }
    LightRuntimeValue<T> operator~() const {
        return LightRuntimeValue<T>([__this=*this]() {
            __this.Emit();
            if constexpr(sizeof(T) == 1) {
                LC->pop(rax);
                LC->not_(al);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 2) {
                LC->pop(rax);
                LC->not_(ax);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 4) {
                LC->pop(rax);
                LC->not_(eax);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 8) {
                LC->pop(rax);
                LC->not_(rax);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 16) {
                LC->pop(rdx);
                LC->pop(rax);
                LC->not_(rax);
                LC->not_(rdx);
                LC->push(rax);
                LC->push(rdx);
            } else
                static_assert(false_v<T>, "Unsupported type");
        });
    }

    LightRuntimeValue<bool> operator==(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            LC->pop(rax);
            LC->pop(rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                static_assert(false_v<T>, "Unsupported type");
            LC->je(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }
    LightRuntimeValue<bool> operator!=(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            LC->pop(rax);
            LC->pop(rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                static_assert(false_v<T>, "Unsupported type");
            LC->jne(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }
    LightRuntimeValue<bool> operator>=(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            LC->pop(rax);
            LC->pop(rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                throw "Unsupported";//static_assert(false_v<T>, "Unsupported type");
            if(std::is_signed_v<T>)
                LC->jge(one);
            else
                LC->jnb(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }
    LightRuntimeValue<bool> operator>(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            LC->pop(rax);
            LC->pop(rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                static_assert(false_v<T>, "Unsupported type");
            if(std::is_signed_v<T>)
                LC->jg(one);
            else
                LC->jnbe(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }
    LightRuntimeValue<bool> operator<(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            LC->pop(rax);
            LC->pop(rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                static_assert(false_v<T>, "Unsupported type");
            if(std::is_signed_v<T>)
                LC->jl(one);
            else
                LC->jb(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }
    LightRuntimeValue<bool> operator<=(LightRuntimeValue<T> right) const {
        return LightRuntimeValue<T>([__this=*this, right]() {
            right.Emit();
            __this.Emit();
            LC->pop(rax);
            LC->pop(rdx);
            Xbyak::Label one, after;
            if constexpr(sizeof(T) == 1)
                LC->cmp(al, dl);
            else if constexpr(sizeof(T) == 2)
                LC->cmp(ax, dx);
            else if constexpr(sizeof(T) == 4)
                LC->cmp(eax, edx);
            else if constexpr(sizeof(T) == 8)
                LC->cmp(rax, rdx);
            else
                static_assert(false_v<T>, "Unsupported type");
            if(std::is_signed_v<T>)
                LC->jle(one);
            else
                LC->jbe(one);
            LC->xor_(rax, rax);
            LC->jmp(after);
            LC->L(one);
            LC->mov(rax, 1);
            LC->L(after);
            LC->push(rax);
        });
    }

    template<typename U = T>
    inline LightRuntimeValue<Vector128<U>> CreateVector() const {
        return LightRuntimeValue<Vector128<U>>([__this=*this]() {
            __this.Emit();
            if constexpr(sizeof(T) == 8)
                LC->pop(rax);
            else {
                LC->pop(rdx);
                LC->mov(rax, rdx);
                if constexpr(sizeof(T) == 1) {
                    LC->mov(dh, dl);
                    LC->or_(rdx, rax);
                    LC->mov(rax, rdx);
                    LC->shl(rdx, 16);
                    LC->or_(rdx, rax);
                    LC->mov(rax, rdx);
                    LC->shl(rdx, 32);
                    LC->or_(rax, rdx);
                } else if constexpr(sizeof(T) == 2) {
                    LC->shl(rdx, 16);
                    LC->or_(rdx, rax);
                    LC->mov(rax, rdx);
                    LC->shl(rdx, 32);
                    LC->or_(rax, rdx);
                } else if constexpr(sizeof(T) == 4) {
                    LC->shl(rdx, 32);
                    LC->or_(rax, rdx);
                } else
                    static_assert(false_v<T>, "Unsupported type");
            }
            LC->push(rax);
            LC->push(rax);
        });
    }

    inline LightRuntimeValue<T> ZeroTop() const {
        throw "Unsupported";
    }

    template<typename ElementT>
    inline LightRuntimeValue<ElementT> Element(int index) const {
        return LightRuntimeValue<ElementT>([__this=*this, index]() {
            __this.Emit();
            if(sizeof(ElementT) * index >= 8) {
                LC->pop(rax);
                LC->add(rsp, 8);
            } else {
                LC->add(rsp, 8);
                LC->pop(rax);
            }
            auto offset = ((sizeof(ElementT) * index) % 8) * 8;
            if(offset != 0)
                LC->shr(rax, offset);
            if(sizeof(ElementT) < 8 && offset + sizeof(ElementT) * 8 < 64) {
                LC->mov(r8, (1UL << (sizeof(ElementT) * 8)) - 1);
                LC->and_(rax, r8);
            }
            LC->push(rax);
        });
    }

    template<typename ElementT, typename U = T, typename = std::enable_if_t<std::is_same_v<U, Vector128<float>>>>
    inline LightRuntimeValue<Vector128<float>> Insert(int index, LightRuntimeValue<ElementT> value) const {
        return LightRuntimeValue<Vector128<float>>([__this=*this, index, value]() {
            value.Emit();
            __this.Emit();
            if(sizeof(ElementT) * index >= 8) {
                LC->pop(rax);
                LC->pop(rdx);
            } else {
                LC->pop(rdx);
                LC->pop(rax);
            }
            LC->pop(rcx);
            auto offset = ((sizeof(ElementT) * index) % 8) * 8;
            if constexpr(sizeof(ElementT) < 8) {
                LC->mov(r8, (1UL << (sizeof(ElementT) * 8)) - 1);
                LC->and_(rcx, r8);
                if(offset != 0)
                    LC->shl(rcx, offset);
            }
            if constexpr(sizeof(ElementT) < 8) {
                LC->mov(r8, ~(((1UL << (sizeof(ElementT) * 8)) - 1) << offset));
                LC->and_(rax, r8);
                LC->or_(rax, rcx);
            } else
                LC->mov(rax, rcx);
            if(sizeof(ElementT) * index >= 8) {
                LC->push(rdx);
                LC->push(rax);
            } else {
                LC->push(rax);
                LC->push(rdx);
            }
        });
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<uint8_t> IsNaN() const {
        throw "Unimplemented";
    }

    template<typename U>
    inline LightRuntimeValue<U> Bitcast() const {
        static_assert(sizeof(T) == sizeof(U));
        return LightRuntimeValue<U>(generator);
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> Sqrt() const {
        throw "Unimplemented";
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> Round() const {
        throw "Unimplemented";
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> RoundHalfDown() const {
        throw "Unimplemented";
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> RoundHalfUp() const {
        throw "Unimplemented";
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> Ceil() const {
        throw "Unimplemented";
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LightRuntimeValue<T> Floor() const {
        throw "Unimplemented";
    }
};

template<typename T>
class LightRuntimePointer {
public:
    LightRuntimeValue<ulong> address;
    const bool safe, isVolatile;
    inline LightRuntimePointer(const LightRuntimePointer<T>& rp) : address(rp.address),
                                                                 safe(rp.safe), isVolatile(rp.isVolatile) {}
    inline LightRuntimePointer(LightRuntimeValue<ulong> addr, bool safe = false, bool isVolatile = false)
            : address(addr), safe(safe), isVolatile(isVolatile) {}

    LightRuntimeValue<T> value() {
        return LightRuntimeValue<T>([__this=*this]() {
            __this.address.Emit();
            LC->pop(rcx);
            if constexpr(sizeof(T) == 1) {
                LC->mov(al, ptr[rcx]);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 2) {
                LC->mov(ax, ptr[rcx]);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 4) {
                LC->mov(eax, ptr[rcx]);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 8) {
                LC->mov(rax, ptr[rcx]);
                LC->push(rax);
            } else if constexpr(sizeof(T) == 16) {
                LC->mov(rax, ptr[rcx]);
                LC->mov(rdx, ptr[rcx + 8]);
                LC->push(rax);
                LC->push(rdx);
            } else
                static_assert(false_v<T>, "Unsupported type");
        });
    }

    void value(LightRuntimeValue<T> v) {
        v.Emit();
        address.Emit();
        LC->pop(rcx);
        if constexpr(sizeof(T) == 1) {
            LC->pop(rax);
            LC->mov(ptr[rcx], al);
        } else if constexpr(sizeof(T) == 2) {
            LC->pop(rax);
            LC->mov(ptr[rcx], ax);
        } else if constexpr(sizeof(T) == 4) {
            LC->pop(rax);
            LC->mov(ptr[rcx], eax);
        } else if constexpr(sizeof(T) == 8) {
            LC->pop(rax);
            LC->mov(ptr[rcx], rax);
        } else if constexpr(sizeof(T) == 16) {
            LC->pop(rdx);
            LC->pop(rax);
            LC->mov(ptr[rcx + 8], rdx);
            LC->mov(ptr[rcx], rax);
        } else
            static_assert(false_v<T>, "Unsupported type");
    }
};

#include "lightRecompiler.h"
