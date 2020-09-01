#pragma once

#include <iostream>
#include <ios>
#include <utility>
#include <llvm/IR/IRBuilder.h>

#include "common.h"

#define RV(T, value) return LlvmRuntimeValue<T>([=, __this=*this]() { return (value); })

template<typename T> struct function_traits;

template<typename T>
inline llvm::Type* LlvmType() {
    if constexpr(std::is_void<T>())
        return llvm::Type::getVoidTy(Builder.getContext());
    else if constexpr(is_std_function<T>())
        return llvm::FunctionType::get(LlvmType<typename function_traits<T>::result_type>(), function_traits<T>::ArgTypes(), false);
    else if constexpr(std::is_pointer<T>())
        return llvm::PointerType::get(LlvmType<std::remove_pointer_t<T>>(), 0);
    else if constexpr(is_vector_t<T>())
        return llvm::VectorType::get(LlvmType<element_t<T>>(), element_count<T>());
    else if constexpr(std::is_same<T, bool>())
        return llvm::Type::getInt1Ty(Builder.getContext());
    else if constexpr(std::is_integral<T>())
        return llvm::Type::getIntNTy(Builder.getContext(), sizeof(T) * 8);
    else if constexpr(std::is_same<T, float>())
        return llvm::Type::getFloatTy(Builder.getContext());
    else if constexpr(std::is_same<T, double>())
        return llvm::Type::getDoubleTy(Builder.getContext());
    else {
        static_assert(std::is_void<T>());
        static_assert(!std::is_void<T>());
    }
}

template<typename R, typename ...Args>
struct function_traits<std::function<R(Args...)>> {
    static const size_t nargs = sizeof...(Args);

    typedef R result_type;

    static std::array<llvm::Type*, nargs> ArgTypes() {
        return { LlvmType<Args>()... };
    }
};

template<typename T> class LlvmRuntimeValue;
template<typename CondT, typename ValueT>
inline LlvmRuntimeValue<ValueT> Ternary(LlvmRuntimeValue<CondT> cond, LlvmRuntimeValue<ValueT> a, LlvmRuntimeValue<ValueT> b);

template<typename T>
class LlvmRuntimeValue {
public:
    using Type = T;
    std::function<llvm::Value*()> generator;

    template<typename U = T>
    inline LlvmRuntimeValue(T value) {
        static_assert(!is_vector_t<T>());
        if constexpr(std::is_floating_point<T>())
            generator = [=]() { return llvm::ConstantFP::get(LlvmType<T>(), (double) value); };
        else
            generator = [=]() { return llvm::ConstantInt::get(LlvmType<T>(), (ulong) value, is_signed<T>()); };
    }

    inline LlvmRuntimeValue(std::function<llvm::Value*()> generator) : generator(std::move(generator)) {
    }

    inline llvm::Value* Emit() const {
        auto value = generator();
        assert(value != nullptr);
        emitted();
        return value;
    }
    template<typename U = T>
    operator llvm::Value*() const { return Emit(); }

    template <typename OT>
    operator LlvmRuntimeValue<OT>() const {
        if constexpr(std::is_same<T, OT>()) return *this;
        else if constexpr(is_vector_t<T>() || is_vector_t<OT>()) {
            static_assert(is_vector_t<T>());
            static_assert(is_vector_t<OT>());
            RV(OT, Builder.CreateBitCast(__this, LlvmType<OT>()));
        } else if constexpr(std::is_same<T, bool>())
            RV(OT, Builder.CreateZExt(__this, LlvmType<OT>()));
        else if constexpr(std::is_same<OT, bool>())
            RV(OT, Builder.CreateICmpNE(__this, (LlvmRuntimeValue<T>) (T) 0));
        else if constexpr(std::is_floating_point<OT>()) {
            if constexpr(std::is_integral<T>()) {
                if constexpr(std::is_signed<T>())
                    RV(OT, Builder.CreateSIToFP(__this, LlvmType<OT>()));
                else
                    RV(OT, Builder.CreateUIToFP(__this, LlvmType<OT>()));
            } else
                RV(OT, Builder.CreateFPCast(__this, LlvmType<OT>()));
        } else if constexpr(std::is_floating_point<T>()) {
            static_assert(std::is_integral<OT>());
            if constexpr(std::is_signed<OT>())
                RV(OT, Builder.CreateFPToSI(__this, LlvmType<OT>()));
            else
                RV(OT, Builder.CreateFPToUI(__this, LlvmType<OT>()));
        } else if constexpr(sizeof(T) == sizeof(OT))
            RV(OT, Builder.CreateBitCast(__this, LlvmType<OT>()));
        else if constexpr(sizeof(T) > sizeof(OT))
            RV(OT, Builder.CreateTrunc(__this, LlvmType<OT>()));
        else if constexpr(std::is_signed<OT>())
            RV(OT, Builder.CreateSExt(__this, LlvmType<OT>()));
        else
            RV(OT, Builder.CreateZExt(__this, LlvmType<OT>()));
    }

    template<typename RetType, typename ... ArgTypes, typename = std::enable_if_t<!std::is_void_v<RetType>>>
    static inline LlvmRuntimeValue<RetType> CallIntrinsic(llvm::Intrinsic::ID id, LlvmRuntimeValue<ArgTypes> ... args) {
        return LlvmRuntimeValue<RetType>([=]() {
            return Builder.CreateCall(llvm::Intrinsic::getDeclaration(getModule(), id, { LlvmType<ArgTypes>()... }), { args.Emit()... });
        });
    }

    inline LlvmRuntimeValue<T> Store() const {
        auto value = Emit();
        assert(value != nullptr);
        RV(T, value);
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> Abs() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::fabs, __this)));
    }

    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LlvmRuntimeValue<T> operator+(LlvmRuntimeValue<element_t<U>> right) const {
        return *this + right.CreateVector();
    }
    LlvmRuntimeValue<T> operator+(LlvmRuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateAdd(__this, right));
        else
            RV(T, Builder.CreateFAdd(__this, right));
    }
    template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
    friend LlvmRuntimeValue<T> operator+(T left, LlvmRuntimeValue<T> right) { return (LlvmRuntimeValue<T>) left + right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LlvmRuntimeValue<T> operator-(LlvmRuntimeValue<element_t<U>> right) const {
        return *this - right.CreateVector();
    }
    LlvmRuntimeValue<T> operator-(LlvmRuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateSub(__this, right));
        else
            RV(T, Builder.CreateFSub(__this, right));
    }
    friend LlvmRuntimeValue<T> operator-(T left, LlvmRuntimeValue<T> right) { return (LlvmRuntimeValue<T>) left - right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LlvmRuntimeValue<T> operator*(LlvmRuntimeValue<element_t<U>> right) const {
        return *this * right.CreateVector();
    }
    LlvmRuntimeValue<T> operator*(LlvmRuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateMul(__this, right));
        else
            RV(T, Builder.CreateFMul(__this, right));
    }
    friend LlvmRuntimeValue<T> operator*(T left, LlvmRuntimeValue<T> right) { return (LlvmRuntimeValue<T>) left * right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    LlvmRuntimeValue<T> operator/(LlvmRuntimeValue<element_t<U>> right) const {
        return *this / right.CreateVector();
    }
    LlvmRuntimeValue<T> operator/(LlvmRuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>()) {
            if constexpr(is_signed<T>())
                RV(T, Builder.CreateSDiv(__this, right));
            else
                RV(T, Builder.CreateUDiv(__this, right));
        } else
            RV(T, Builder.CreateFDiv(__this, right));
    }
    friend LlvmRuntimeValue<T> operator/(T left, LlvmRuntimeValue<T> right) { return (LlvmRuntimeValue<T>) left / right; }
    LlvmRuntimeValue<T> operator%(LlvmRuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>()) {
            if constexpr(is_signed<T>())
                RV(T, Builder.CreateSRem(__this, right));
            else
                RV(T, Builder.CreateURem(__this, right));
        } else
            RV(T, Builder.CreateFRem(__this, right));
    }
    friend LlvmRuntimeValue<T> operator%(T left, LlvmRuntimeValue<T> right) { return (LlvmRuntimeValue<T>) left % right; }
    LlvmRuntimeValue<T> operator-() {
        if constexpr(is_floating_point<T>())
            RV(T, Builder.CreateFNeg(__this));
        else
            RV(T, Builder.CreateNeg(__this));
    }

    LlvmRuntimeValue<T> operator<<(LlvmRuntimeValue<T> right) const {
        return Ternary(
                (LlvmRuntimeValue<bool>) (right >= (sizeof(T) * 8)),
                (LlvmRuntimeValue<T>) (T) 0,
                LlvmRuntimeValue<T>([__this=*this, right]() { return Builder.CreateShl(__this, right); })
        );
    }
    LlvmRuntimeValue<T> operator>>(LlvmRuntimeValue<T> right) const {
        return Ternary(
            (LlvmRuntimeValue<bool>) (right >= (sizeof(T) * 8)),
            (LlvmRuntimeValue<T>) (T) 0,
            is_signed<T>()
                ? LlvmRuntimeValue<T>([__this=*this, right]() { return Builder.CreateAShr(__this, right); })
                : LlvmRuntimeValue<T>([__this=*this, right]() { return Builder.CreateLShr(__this, right); })
        );
    }
    LlvmRuntimeValue<T> operator&(LlvmRuntimeValue<T> right) const {
        RV(T, Builder.CreateAnd(__this, right));
    }
    LlvmRuntimeValue<T> operator|(LlvmRuntimeValue<T> right) const {
        RV(T, Builder.CreateOr(__this, right));
    }
    LlvmRuntimeValue<T> operator^(LlvmRuntimeValue<T> right) const {
        RV(T, Builder.CreateXor(__this, right));
    }
    LlvmRuntimeValue<bool> operator!() const {
        RV(bool, Builder.CreateICmpEQ(__this, (LlvmRuntimeValue<T>) (T) 0));
    }
    LlvmRuntimeValue<T> operator~() const {
        RV(T, Builder.CreateNot(__this));
    }

    LlvmRuntimeValue<bool> operator==(LlvmRuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>())
            RV(bool, Builder.CreateICmpEQ(__this, right));
        else
            RV(bool, Builder.CreateFCmpOEQ(__this, right));
    }
    LlvmRuntimeValue<bool> operator!=(LlvmRuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>())
            RV(bool, Builder.CreateICmpNE(__this, right));
        else
            RV(bool, Builder.CreateFCmpONE(__this, right));
    }
    LlvmRuntimeValue<bool> operator>=(LlvmRuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSGE(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpUGE(__this, right));
        else
            RV(bool, Builder.CreateFCmpOGE(__this, right));
    }
    LlvmRuntimeValue<bool> operator>(LlvmRuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSGT(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpUGT(__this, right));
        else
            RV(bool, Builder.CreateFCmpOGT(__this, right));
    }
    LlvmRuntimeValue<bool> operator<(LlvmRuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSLT(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpULT(__this, right));
        else
            RV(bool, Builder.CreateFCmpOLT(__this, right));
    }
    LlvmRuntimeValue<bool> operator<=(LlvmRuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSLE(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpULE(__this, right));
        else
            RV(bool, Builder.CreateFCmpOLE(__this, right));
    }

    template<typename U = T>
    inline LlvmRuntimeValue<Vector128<U>> CreateVector() const {
        return LlvmRuntimeValue<Vector128<U>>([=, __this=*this]() {
            auto value = __this.Emit();
            llvm::Value* vec = llvm::UndefValue::get(LlvmType<Vector128<U>>());
            for(auto i = 0; i < element_count<Vector128<U>>(); ++i)
                vec = Builder.CreateInsertElement(vec, value, i);
            return vec;
        });
    }

    inline LlvmRuntimeValue<T> ZeroTop() const {
        return LlvmRuntimeValue<T>([=, __this=*this]() {
            auto vec = __this.Emit();
            vec = Builder.CreateBitCast(vec, LlvmType<Vector128<uint64_t>>());
            vec = Builder.CreateInsertElement(vec, (LlvmRuntimeValue<uint64_t>) 0, 1);
            return Builder.CreateBitCast(vec, LlvmType<T>());
        });
    }

    template<typename ElementT>
    inline LlvmRuntimeValue<ElementT> Element(int index) const {
        RV(ElementT, Builder.CreateExtractElement((LlvmRuntimeValue<Vector128<ElementT>>) __this, index));
    }

    template<typename ElementT, typename U = T, typename = std::enable_if_t<std::is_same_v<U, Vector128<float>>>>
    inline LlvmRuntimeValue<Vector128<float>> Insert(int index, LlvmRuntimeValue<ElementT> value) const {
        return LlvmRuntimeValue<Vector128<float>>([index, value, __this=*this]() {
            auto vec = __this.Emit();
            if constexpr(!std::is_same<ElementT, float>())
                vec = Builder.CreateBitCast(vec, LlvmType<Vector128<ElementT>>());
            vec = Builder.CreateInsertElement(vec, value, index);
            if constexpr(!std::is_same<ElementT, float>())
                return Builder.CreateBitCast(vec, LlvmType<Vector128<float>>());
            return vec;
        });
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<uint8_t> IsNaN() const {
        return LlvmRuntimeValue<bool>([__this=*this]() {
            auto value = __this.Emit();
            return Builder.CreateFCmpUNO(value, value);
        });
    }

    template<typename U>
    inline LlvmRuntimeValue<U> Bitcast() const {
        static_assert(sizeof(T) == sizeof(U));
        RV(U, Builder.CreateBitCast(__this, LlvmType<U>()));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> Sqrt() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::sqrt, __this)));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> Round() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::round, __this)));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> RoundHalfDown() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::ceil, __this - (T) 0.5)));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> RoundHalfUp() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::floor, __this + (T) 0.5)));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> Ceil() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::ceil, __this)));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline LlvmRuntimeValue<T> Floor() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::floor, __this)));
    }
};

template<typename T>
class LlvmRuntimePointer {
public:
    LlvmRuntimeValue<ulong> address, pointer;
    const bool safe, isVolatile;
    inline LlvmRuntimePointer(const LlvmRuntimePointer<T>& rp) : address(rp.address), pointer(rp.pointer),
                                                                 safe(rp.safe), isVolatile(rp.isVolatile) {}
    inline LlvmRuntimePointer(LlvmRuntimeValue<ulong> addr, bool safe = false, bool isVolatile = false)
            : address(addr), pointer([addr]() { return Builder.CreateIntToPtr(addr, LlvmType<T*>()); }),
              safe(safe), isVolatile(isVolatile) {}

    LlvmRuntimeValue<T> value() {
        return LlvmRuntimeValue<T>([__this=*this]() {
            auto load = Builder.CreateLoad(__this.pointer);
            load->setAlignment(1);
            if(__this.isVolatile)
                load->setVolatile(true);
            return load;
        });
    }

    void value(LlvmRuntimeValue<T> v) {
        auto store = Builder.CreateStore(v, pointer);
        store->setAlignment(1);
        if(isVolatile)
            store->setVolatile(true);
    }
};

#include "recompiler.h"
