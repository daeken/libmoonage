#pragma once

#include <utility>
#include <llvm/IR/IRBuilder.h>

#include "common.h"

#define RV(T, value) return RuntimeValue<T>([=, __this=*this]() { return (value); })

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

template<typename T> class RuntimeValue;
template<typename CondT, typename ValueT>
inline RuntimeValue<ValueT> Ternary(RuntimeValue<CondT> cond, RuntimeValue<ValueT> a, RuntimeValue<ValueT> b);

template<typename T>
class RuntimeValue {
public:
    using Type = T;
    int constructor;
    std::function<llvm::Value*()> generator;

    template<typename U = T>
    inline RuntimeValue(T value) {
        static_assert(!is_vector_t<T>());
        constructor = 0xf001;
        if constexpr(std::is_floating_point<T>())
            generator = [=]() { return llvm::ConstantFP::get(LlvmType<T>(), (double) value); };
        else
            generator = [=]() { return llvm::ConstantInt::get(LlvmType<T>(), (ulong) value, is_signed<T>()); };
    }

    inline RuntimeValue(std::function<llvm::Value*()> generator) : constructor(0xf003), generator(generator) {
    }

    inline llvm::Value* Emit() const {
        auto value = generator();
        assert(value != nullptr);
        emitted();
        return value;
    }
    template<typename U = T>
    inline operator llvm::Value*() const { return Emit(); }

    template <typename OT>
    inline operator RuntimeValue<OT>() const {
        if constexpr(std::is_same<T, OT>()) return *this;
        else if constexpr(is_vector_t<T>() || is_vector_t<OT>()) {
            static_assert(is_vector_t<T>());
            static_assert(is_vector_t<OT>());
            RV(OT, Builder.CreateBitCast(__this, LlvmType<OT>()));
        } else if constexpr(std::is_same<T, bool>())
            RV(OT, Builder.CreateZExt(__this, LlvmType<OT>()));
        else if constexpr(std::is_same<OT, bool>())
            RV(OT, Builder.CreateICmpNE(__this, (RuntimeValue<T>) (T) 0));
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
    static inline RuntimeValue<RetType> CallIntrinsic(llvm::Intrinsic::ID id, RuntimeValue<ArgTypes> ... args) {
        return RuntimeValue<RetType>([=]() {
            return Builder.CreateCall(llvm::Intrinsic::getDeclaration(getModule(), id, { LlvmType<ArgTypes>()... }), { args.Emit()... });
        });
    }

    inline RuntimeValue<T> Store() const {
        auto value = Emit();
        assert(value != nullptr);
        RV(T, value);
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline RuntimeValue<T> Abs() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::fabs, __this)));
    }

    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator+(RuntimeValue<element_t<U>> right) const {
        return *this + right.CreateVector();
    }
    inline RuntimeValue<T> operator+(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateAdd(__this, right));
        else
            RV(T, Builder.CreateFAdd(__this, right));
    }
    template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
    inline friend RuntimeValue<T> operator+(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left + right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator-(RuntimeValue<element_t<U>> right) const {
        return *this - right.CreateVector();
    }
    inline RuntimeValue<T> operator-(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateSub(__this, right));
        else
            RV(T, Builder.CreateFSub(__this, right));
    }
    inline friend RuntimeValue<T> operator-(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left - right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator*(RuntimeValue<element_t<U>> right) const {
        return *this * right.CreateVector();
    }
    inline RuntimeValue<T> operator*(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateMul(__this, right));
        else
            RV(T, Builder.CreateFMul(__this, right));
    }
    inline friend RuntimeValue<T> operator*(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left * right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator/(RuntimeValue<element_t<U>> right) const {
        return *this / right.CreateVector();
    }
    inline RuntimeValue<T> operator/(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>()) {
            if constexpr(is_signed<T>())
                RV(T, Builder.CreateSDiv(__this, right));
            else
                RV(T, Builder.CreateUDiv(__this, right));
        } else
            RV(T, Builder.CreateFDiv(__this, right));
    }
    inline friend RuntimeValue<T> operator/(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left / right; }
    inline RuntimeValue<T> operator%(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>()) {
            if constexpr(is_signed<T>())
                RV(T, Builder.CreateSRem(__this, right));
            else
                RV(T, Builder.CreateURem(__this, right));
        } else
            RV(T, Builder.CreateFRem(__this, right));
    }
    inline friend RuntimeValue<T> operator%(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left % right; }
    inline RuntimeValue<T> operator-() {
        if constexpr(is_floating_point<T>())
            RV(T, Builder.CreateFNeg(__this));
        else
            RV(T, Builder.CreateNeg(__this));
    }

    inline RuntimeValue<T> operator<<(RuntimeValue<T> right) const {
        return Ternary(
            (RuntimeValue<bool>) (right >= (sizeof(T) * 8)),
            (RuntimeValue<T>) (T) 0,
            RuntimeValue<T>([__this=*this, right]() { return Builder.CreateShl(__this, right); })
        );
    }
    inline RuntimeValue<T> operator>>(RuntimeValue<T> right) const {
        return Ternary(
            (RuntimeValue<bool>) (right >= (sizeof(T) * 8)),
            (RuntimeValue<T>) (T) 0,
            is_signed<T>()
                ? RuntimeValue<T>([__this=*this, right]() { return Builder.CreateAShr(__this, right); })
                : RuntimeValue<T>([__this=*this, right]() { return Builder.CreateLShr(__this, right); })
        );
    }
    inline RuntimeValue<T> operator&(RuntimeValue<T> right) const {
        RV(T, Builder.CreateAnd(__this, right));
    }
    inline RuntimeValue<T> operator|(RuntimeValue<T> right) const {
        RV(T, Builder.CreateOr(__this, right));
    }
    inline RuntimeValue<T> operator^(RuntimeValue<T> right) const {
        RV(T, Builder.CreateXor(__this, right));
    }
    inline RuntimeValue<bool> operator!() const {
        RV(bool, Builder.CreateICmpEQ(__this, (RuntimeValue<T>) (T) 0));
    }
    inline RuntimeValue<T> operator~() const {
        RV(T, Builder.CreateNot(__this));
    }

    inline RuntimeValue<bool> operator==(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>())
            RV(bool, Builder.CreateICmpEQ(__this, right));
        else
            RV(bool, Builder.CreateFCmpOEQ(__this, right));
    }
    inline RuntimeValue<bool> operator!=(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>())
            RV(bool, Builder.CreateICmpNE(__this, right));
        else
            RV(bool, Builder.CreateFCmpONE(__this, right));
    }
    inline RuntimeValue<bool> operator>=(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSGE(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpUGE(__this, right));
        else
            RV(bool, Builder.CreateFCmpOGE(__this, right));
    }
    inline RuntimeValue<bool> operator>(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSGT(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpUGT(__this, right));
        else
            RV(bool, Builder.CreateFCmpOGT(__this, right));
    }
    inline RuntimeValue<bool> operator<(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSLT(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpULT(__this, right));
        else
            RV(bool, Builder.CreateFCmpOLT(__this, right));
    }
    inline RuntimeValue<bool> operator<=(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(bool, Builder.CreateICmpSLE(__this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(bool, Builder.CreateICmpULE(__this, right));
        else
            RV(bool, Builder.CreateFCmpOLE(__this, right));
    }

    template<typename U = T>
    inline RuntimeValue<Vector128<U>> CreateVector() const {
        return RuntimeValue<Vector128<U>>([=, __this=*this]() {
            auto value = __this.Emit();
            llvm::Value* vec = llvm::UndefValue::get(LlvmType<Vector128<U>>());
            for(auto i = 0; i < element_count<Vector128<U>>(); ++i)
                vec = Builder.CreateInsertElement(vec, value, i);
            return vec;
        });
    }

    template<typename ElementT>
    inline RuntimeValue<ElementT> Element(int index) const {
        RV(ElementT, Builder.CreateExtractElement((RuntimeValue<Vector128<ElementT>>) __this, index));
    }

    template<typename ElementT, typename U = T, typename = std::enable_if_t<std::is_same_v<U, Vector128<float>>>>
    inline RuntimeValue<Vector128<float>> Insert(int index, RuntimeValue<ElementT> value) const {
        return RuntimeValue<Vector128<float>>([index, value, __this=*this]() {
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
    inline RuntimeValue<byte> IsNaN() const {
        return RuntimeValue<bool>([__this=*this]() {
            auto value = __this.Emit();
            return Builder.CreateFCmpUNO(value, value);
        });
    }

    template<typename U>
    inline RuntimeValue<U> Bitcast() const {
        static_assert(sizeof(T) == sizeof(U));
        RV(U, Builder.CreateBitCast(__this, LlvmType<U>()));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline RuntimeValue<T> Sqrt() const {
        RV(T, (CallIntrinsic<T, T>(llvm::Intrinsic::ID::sqrt, __this)));
    }
};

template<typename T>
class RuntimePointer {
public:
    RuntimeValue<ulong> address, pointer;
    const bool safe, isVolatile;
    inline RuntimePointer(RuntimeValue<ulong> addr, bool safe = false, bool isVolatile = false)
            : address(addr), pointer([=]() { return Builder.CreateIntToPtr(addr, LlvmType<T*>()); }),
              safe(safe), isVolatile(isVolatile) {}
    Property<RuntimeValue<T>> value{
            [=]() {
                return RuntimeValue<T>([__this=*this]() {
                    auto load = Builder.CreateLoad(__this.pointer);
                    load->setAlignment(1);
                    if(__this.isVolatile)
                        load->setVolatile(true);
                    return load;
                });
            },
            [=](auto v) {
                auto store = Builder.CreateStore(pointer, v);
                store->setAlignment(1);
                if(isVolatile)
                    store->setVolatile(true);
                return store;
            }
    };
};

#include "recompiler.h"
