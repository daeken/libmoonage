#pragma once

#include <utility>
#include <llvm/IR/IRBuilder.h>

#include "common.h"

#define RV(T, value) return RuntimeValue<T>([=]() { return (value); })

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
    std::function<llvm::Value*()> generator;

    template<typename U = T>
    inline RuntimeValue(T value) {
        static_assert(!is_vector_t<T>());
        if constexpr(std::is_floating_point<T>())
            generator = [=]() { return llvm::ConstantFP::get(LlvmType<T>(), (double) value); };
        else
            generator = [=]() { return llvm::ConstantInt::get(LlvmType<T>(), (ulong) value, is_signed<T>()); };
    }

    inline RuntimeValue(llvm::Value* value) : generator([=]() { return value; }) { }

    inline RuntimeValue(std::function<llvm::Value*()> generator) : generator(generator) { }

    inline void BuildGenerator(llvm::Value* value) { generator = [=]() { return value; }; }

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
            RV(OT, Builder.CreateBitCast(*this, LlvmType<OT>()));
        } else if constexpr(std::is_same<T, bool>())
            RV(OT, Builder.CreateZExt(*this, LlvmType<OT>()));
        else if constexpr(std::is_same<OT, bool>())
            RV(OT, Builder.CreateICmpNE(*this, (RuntimeValue<OT>) OT(0)));
        else if constexpr(std::is_floating_point<OT>()) {
            if constexpr(std::is_integral<T>()) {
                if constexpr(std::is_signed<T>())
                    RV(OT, Builder.CreateSIToFP(*this, LlvmType<OT>()));
                else
                    RV(OT, Builder.CreateUIToFP(*this, LlvmType<OT>()));
            } else
                RV(OT, Builder.CreateFPCast(*this, LlvmType<OT>()));
        } else if constexpr(std::is_floating_point<T>()) {
            static_assert(std::is_integral<OT>());
            if constexpr(std::is_signed<OT>())
                RV(OT, Builder.CreateFPToSI(*this, LlvmType<OT>()));
            else
                RV(OT, Builder.CreateFPToUI(*this, LlvmType<OT>()));
        } else if constexpr(sizeof(T) == sizeof(OT))
            RV(OT, Builder.CreateBitCast(*this, LlvmType<OT>()));
        else if constexpr(sizeof(T) > sizeof(OT))
            RV(OT, Builder.CreateTrunc(*this, LlvmType<OT>()));
        else if constexpr(std::is_signed<OT>())
            RV(OT, Builder.CreateSExt(*this, LlvmType<OT>()));
        else
            RV(OT, Builder.CreateZExt(*this, LlvmType<OT>()));
    }

    template<typename RetType, typename ... ArgTypes, typename = std::enable_if_t<!std::is_void_v<RetType>>>
    static inline RuntimeValue<RetType> CallIntrinsic(const char* name, RuntimeValue<ArgTypes> ... args) {
        return RuntimeValue<RetType>([=]() {
            auto func = (llvm::Function*) getModule()->getNamedIFunc(name);
            if(func == nullptr)
                func = llvm::Function::Create((llvm::FunctionType*) LlvmType<std::function<RetType(ArgTypes ...)>>(), llvm::GlobalValue::LinkageTypes::CommonLinkage, name, getModule());
            return Builder.CreateCall(func, { args.Emit()... });
        });
    }

    inline RuntimeValue<T> Store() const {
        auto value = Emit();
        RV(T, value);
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline RuntimeValue<T> Abs() const {
        if constexpr(std::is_same<U, float>())
            RV(T, (CallIntrinsic<float, float>("llvm.fabs.f32", *this)));
        else if constexpr(std::is_same<U, double>())
            RV(T, (CallIntrinsic<double, double>("llvm.fabs.f64", *this)));
        else
            static_assert(std::is_void<U>());
    }

    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator+(RuntimeValue<element_t<U>> right) const {
        return *this + right.CreateVector();
    }
    inline RuntimeValue<T> operator+(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateAdd(*this, right));
        else
            RV(T, Builder.CreateFAdd(*this, right));
    }
    template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
    inline friend RuntimeValue<T> operator+(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left + right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator-(RuntimeValue<element_t<U>> right) const {
        return *this - right.CreateVector();
    }
    inline RuntimeValue<T> operator-(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateSub(*this, right));
        else
            RV(T, Builder.CreateFSub(*this, right));
    }
    inline friend RuntimeValue<T> operator-(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left - right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator*(RuntimeValue<element_t<U>> right) const {
        return *this * right.CreateVector();
    }
    inline RuntimeValue<T> operator*(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>())
            RV(T, Builder.CreateMul(*this, right));
        else
            RV(T, Builder.CreateFMul(*this, right));
    }
    inline friend RuntimeValue<T> operator*(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left * right; }
    template<typename U = T, typename = std::enable_if<is_vector_t<U>()>>
    inline RuntimeValue<T> operator/(RuntimeValue<element_t<U>> right) const {
        return *this / right.CreateVector();
    }
    inline RuntimeValue<T> operator/(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>()) {
            if constexpr(is_signed<T>())
                RV(T, Builder.CreateSDiv(*this, right));
            else
                RV(T, Builder.CreateUDiv(*this, right));
        } else
            RV(T, Builder.CreateFDiv(*this, right));
    }
    inline friend RuntimeValue<T> operator/(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left / right; }
    inline RuntimeValue<T> operator%(RuntimeValue<T> right) const {
        if constexpr(is_int_ptr_vec_t<T>()) {
            if constexpr(is_signed<T>())
                RV(T, Builder.CreateSRem(*this, right));
            else
                RV(T, Builder.CreateURem(*this, right));
        } else
            RV(T, Builder.CreateFRem(*this, right));
    }
    inline friend RuntimeValue<T> operator%(T left, RuntimeValue<T> right) { return (RuntimeValue<T>) left % right; }
    inline RuntimeValue<T> operator-() {
        if constexpr(is_floating_point<T>())
            RV(T, Builder.CreateFNeg(*this));
        else
            RV(T, Builder.CreateNeg(*this));
    }

    inline RuntimeValue<T> operator>>(RuntimeValue<T> right) const {
        return Ternary(
            (RuntimeValue<bool>) (right >= sizeof(T) * 8),
            (RuntimeValue<T>) (T) 0,
            RuntimeValue<T>([=]() { return Builder.CreateShl(*this, right); })
        );
    }
    inline RuntimeValue<T> operator<<(RuntimeValue<T> right) const {
        return Ternary(
            (RuntimeValue<bool>) (right >= sizeof(T) * 8),
            (RuntimeValue<T>) (T) 0,
            is_signed<T>()
                ? RuntimeValue<T>([=]() { return Builder.CreateAShr(*this, right); })
                : RuntimeValue<T>([=]() { return Builder.CreateLShr(*this, right); })
        );
    }
    inline RuntimeValue<T> operator&(RuntimeValue<T> right) const {
        RV(T, Builder.CreateAnd(*this, right));
    }
    inline RuntimeValue<T> operator|(RuntimeValue<T> right) const {
        RV(T, Builder.CreateOr(*this, right));
    }
    inline RuntimeValue<T> operator^(RuntimeValue<T> right) const {
        RV(T, Builder.CreateXor(*this, right));
    }
    inline RuntimeValue<T> operator!() const {
        RV(T, Builder.CreateICmpEQ(*this, (RuntimeValue<T>) (T) 0));
    }
    inline RuntimeValue<T> operator~() const {
        RV(T, Builder.CreateNot(*this));
    }
    inline RuntimeValue<T> AndNot(RuntimeValue<T> right) const {
        if constexpr(is_vector_t<T>())
            RV(T, Builder.CreateBitCast(Builder.CreateAnd(Bitcast<UInt128>(), Builder.CreateNot(right.Bitcast<UInt128>())), LlvmType<T>()));
        else
            return *this & ~right;
    }

    inline RuntimeValue<byte> operator==(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>())
            RV(byte, Builder.CreateICmpEQ(*this, right));
        else
            RV(byte, Builder.CreateFCmpOEQ(*this, right));
    }
    inline RuntimeValue<byte> operator!=(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>())
            RV(byte, Builder.CreateICmpNE(*this, right));
        else
            RV(byte, Builder.CreateFCmpONE(*this, right));
    }
    inline RuntimeValue<byte> operator>=(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(byte, Builder.CreateICmpSGE(*this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(byte, Builder.CreateICmpUGE(*this, right));
        else
            RV(byte, Builder.CreateFCmpOGE(*this, right));
    }
    inline RuntimeValue<byte> operator>(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(byte, Builder.CreateICmpSGT(*this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(byte, Builder.CreateICmpUGT(*this, right));
        else
            RV(byte, Builder.CreateFCmpOGT(*this, right));
    }
    inline RuntimeValue<byte> operator<(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(byte, Builder.CreateICmpSLT(*this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(byte, Builder.CreateICmpULT(*this, right));
        else
            RV(byte, Builder.CreateFCmpOLT(*this, right));
    }
    inline RuntimeValue<byte> operator<=(RuntimeValue<T> right) const {
        if constexpr(std::is_integral<T>() && std::is_signed<T>())
            RV(byte, Builder.CreateICmpSLE(*this, right));
        else if constexpr(std::is_integral<T>() && !std::is_signed<T>())
            RV(byte, Builder.CreateICmpULE(*this, right));
        else
            RV(byte, Builder.CreateFCmpOLE(*this, right));
    }

    template<typename U = T>
    inline RuntimeValue<Vector128<U>> CreateVector() const {
        return RuntimeValue<Vector128<U>>([=]() {
            auto value = Emit();
            llvm::Value* vec = llvm::UndefValue::get(LlvmType<Vector128<U>>());
            for(auto i = 0; i < element_count<Vector128<U>>(); ++i)
                vec = Builder.CreateInsertElement(vec, value, i);
            return vec;
        });
    }

    template<typename ElementT>
    inline RuntimeValue<ElementT> Element(int index) const {
        RV(ElementT, Builder.CreateExtractElement((RuntimeValue<Vector128<ElementT>>) *this, index));
    }

    template<typename ElementT, typename U = T, typename = std::enable_if_t<std::is_same_v<U, Vector128<float>>>>
    inline RuntimeValue<Vector128<float>> Insert(int index, RuntimeValue<ElementT> value) const {
        return RuntimeValue<Vector128<float>>([=]() {
            auto vec = Emit();
            if constexpr(std::is_same<ElementT, float>())
                vec = Builder.CreateBitCast(vec, LlvmType<Vector128<ElementT>>());
            vec = Builder.CreateInsertElement(vec, value, index);
            if constexpr(std::is_same<ElementT, float>())
                return Builder.CreateBitCast(vec, LlvmType<Vector128<float>>());
            return vec;
        });
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline RuntimeValue<byte> IsNaN() const {
        return RuntimeValue<bool>([=]() {
            auto value = Emit();
            return Builder.CreateFCmpUNO(value, value);
        });
    }

    template<typename U>
    inline RuntimeValue<U> Bitcast() const {
        static_assert(sizeof(T) == sizeof(U));
        RV(U, Builder.CreateBitCast(*this, LlvmType<U>()));
    }

    template<typename U = T, typename = std::enable_if_t<std::is_floating_point_v<U>>>
    inline RuntimeValue<T> Sqrt() const {
        if constexpr(std::is_same<U, float>())
            RV(T, (CallIntrinsic<float, float>("sqrtf", *this)));
        else if constexpr(std::is_same<U, double>())
            RV(T, (CallIntrinsic<double, double>("sqrt", *this)));
        else
            static_assert(std::is_void<U>());
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
                auto load = Builder.CreateLoad(pointer);
                load->setAlignment(1);
                if(isVolatile)
                    load->setVolatile(true);
                return load;
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
