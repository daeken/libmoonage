#pragma once

#include "common.h"
#include "state.h"
#include "cacheManager.h"
#include "runtimeValue.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/GlobalValue.h>
#include <unordered_set>
#include <queue>
using std::unordered_set;
using std::queue;
using std::tuple;

class _LabelTag {
public:
    static long inc;
    long id = ++inc;
    llvm::BasicBlock* _block;
    std::function<llvm::BasicBlock*()> lazyBlock;
    inline _LabelTag(llvm::BasicBlock* block) : _block(block) {}
    inline _LabelTag(std::function<llvm::BasicBlock*()> lazyBlock) : _block(nullptr), lazyBlock(std::move(lazyBlock)) {}
    inline llvm::BasicBlock* block() { return _block == nullptr ? _block = lazyBlock() : _block; }
};
using LabelTag = std::shared_ptr<_LabelTag>;

template<typename T>
class Local {
public:
    llvm::Value* pointer;
    Property<RuntimeValue<T>> value{
        [=]() { return RuntimeValue<T>([=]() { return Builder.CreateLoad(pointer); }); },
        [=](auto val) { Builder.CreateStore(val, pointer); }
    };
    inline Local() : pointer(Builder.CreateAlloca(LlvmType<T>())) { }
};

struct BlockContext {
    ulong LR = -1UL;
};

class Recompiler {
public:
    Recompiler();
    bool recompile(uint inst, ulong pc);
    void run(ulong pc, ulong sp);
    void recompileMultiple(Block* block);

    volatile CpuState state;
    ulong currentPC;
    bool registersUsed[31];
    Local<ulong>* registerLocals[31];

    llvm::Function* function;
    std::unique_ptr<llvm::Module> module;
    BlockContext context;
    bool branched;
    bool justBranched;
    long suppressedBranch;
    llvm::BasicBlock* currentBlock;
    unordered_set<long> usedLabels;
    LabelTag* preStoreRegistersLabel;
    unordered_map<ulong, LabelTag> blockLabels;
    queue<tuple<BlockContext, ulong>> blocksNeeded;
    RuntimeValue<ulong> CpuStateRef{nullptr};
#define FieldAddress(name) (CpuStateRef + offsetof(CpuState, name))

    Indexer<RuntimeValue<ulong>> XR{
        [=](auto reg) {
            if(reg == 31)
                return (RuntimeValue<ulong>) 0UL;
            registersUsed[reg] = true;
            return registerLocals[reg]->value();
        },
        [=](auto reg, auto value) {
            if(reg == 31) {
                value.Emit();
                return;
            }
            registersUsed[reg] = true;
            registerLocals[reg]->value = value;
        }
    };
    Indexer<RuntimeValue<Vector128<float>>> VR{
        [=](auto reg) {
            assert(reg >= 0 && reg <= 31);
            return RuntimeValue<Vector128<float>>([=]() {
                auto addr = FieldAddress(V0) + (reg * 16);
                auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<Vector128<float>*>());
                return Builder.CreateLoad(ptr);
            });
        },
        [=](auto reg, auto value) {
            assert(reg >= 0 && reg <= 31);
            auto addr = FieldAddress(V0) + (reg * 16);
            auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<Vector128<float>*>());
            Builder.CreateStore(value, ptr);
        }
    };
    Indexer<RuntimeValue<byte>> VBR{
        [=](auto reg) {
            assert(reg >= 0 && reg <= 31);
            return RuntimeValue<byte>([=]() {
                auto addr = FieldAddress(V0) + (reg * 16);
                auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<byte *>());
                return Builder.CreateLoad(ptr);
            });
        },
        [=](auto reg, auto value) {
            assert(reg >= 0 && reg <= 31);
            auto addr = FieldAddress(V0) + (reg * 16);
            auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<Vector128<byte>*>());
            auto bvec = Builder.CreateInsertElement(llvm::UndefValue::get(LlvmType<Vector128<byte>>()), value, (RuntimeValue<int>) 0);
            for(auto i = 1; i < 16; ++i)
                bvec = Builder.CreateInsertElement(bvec, (RuntimeValue<byte>) 0, (RuntimeValue<int>) i);
            Builder.CreateStore(bvec, ptr);
        }
    };
    Indexer<RuntimeValue<ushort>> VHR{
            [=](auto reg) {
                assert(reg >= 0 && reg <= 31);
                return RuntimeValue<ushort>([=]() {
                    auto addr = FieldAddress(V0) + (reg * 16);
                    auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<ushort *>());
                    return Builder.CreateLoad(ptr);
                });
            },
            [=](auto reg, auto value) {
                assert(reg >= 0 && reg <= 31);
                auto addr = FieldAddress(V0) + (reg * 16);
                auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<Vector128<ushort>*>());
                auto bvec = Builder.CreateInsertElement(llvm::UndefValue::get(LlvmType<Vector128<ushort>>()), value, (RuntimeValue<int>) 0);
                for(auto i = 1; i < 8; ++i)
                    bvec = Builder.CreateInsertElement(bvec, (RuntimeValue<ushort>) 0, (RuntimeValue<int>) i);
                Builder.CreateStore(bvec, ptr);
            }
    };
    Indexer<RuntimeValue<float>> VSR{
            [=](auto reg) {
                assert(reg >= 0 && reg <= 31);
                return RuntimeValue<float>([=]() {
                    auto addr = FieldAddress(V0) + (reg * 16);
                    auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<float *>());
                    return Builder.CreateLoad(ptr);
                });
            },
            [=](auto reg, auto value) {
                assert(reg >= 0 && reg <= 31);
                auto addr = FieldAddress(V0) + (reg * 16);
                auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<Vector128<float>*>());
                auto bvec = Builder.CreateInsertElement(llvm::UndefValue::get(LlvmType<Vector128<float>>()), value, (RuntimeValue<int>) 0);
                for(auto i = 1; i < 4; ++i)
                    bvec = Builder.CreateInsertElement(bvec, (RuntimeValue<float>) 0.0f, (RuntimeValue<int>) i);
                Builder.CreateStore(bvec, ptr);
            }
    };
    Indexer<RuntimeValue<double>> VDR{
            [=](auto reg) {
                assert(reg >= 0 && reg <= 31);
                return RuntimeValue<double>([=]() {
                    auto addr = FieldAddress(V0) + (reg * 16);
                    auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<double *>());
                    return Builder.CreateLoad(ptr);
                });
            },
            [=](auto reg, auto value) {
                assert(reg >= 0 && reg <= 31);
                auto addr = FieldAddress(V0) + (reg * 16);
                auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<Vector128<double>*>());
                auto bvec = Builder.CreateInsertElement(llvm::UndefValue::get(LlvmType<Vector128<double>>()), value, (RuntimeValue<int>) 0);
                bvec = Builder.CreateInsertElement(bvec, (RuntimeValue<double>) 0.0, (RuntimeValue<int>) 1);
                Builder.CreateStore(bvec, ptr);
            }
    };

#define FIELD(name) Property<RuntimeValue<decltype(CpuState::name)>> name##R{ \
    [=]() { return Field<decltype(CpuState::name)>(offsetof(CpuState, name)); }, \
    [=](auto value) { Field(offsetof(CpuState, name), value); } \
}

    FIELD(BranchTo);
    FIELD(PC);
    FIELD(SP);
    FIELD(Exclusive8);
    FIELD(Exclusive16);
    FIELD(Exclusive32);
    FIELD(Exclusive64);
    FIELD(NZCV_N);
    FIELD(NZCV_Z);
    FIELD(NZCV_C);
    FIELD(NZCV_V);
    Property<RuntimeValue<ulong>> NZCVR{
        [=]() { return (NZCV_NR() << 31) | (NZCV_ZR() << 30) | (NZCV_CR() << 29) | (NZCV_VR() << 28); },
        [=](auto value) {
            NZCV_NR = (value >> 31) & 1;
            NZCV_ZR = (value >> 30) & 1;
            NZCV_CR = (value >> 29) & 1;
            NZCV_VR = (value >> 28) & 1;
        }
    };

    template<typename T>
    inline RuntimeValue<T> Field(int offset) const {
        return RuntimeValue<T>([=]() {
            auto addr = CpuStateRef + offset;
            auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<T*>());
            return Builder.CreateLoad(ptr);
        });
    }

    template<typename T>
    inline void Field(int offset, RuntimeValue<T> value) const {
        auto addr = CpuStateRef + offset;
        auto ptr = Builder.CreateIntToPtr(addr.Emit(), LlvmType<T*>());
        Builder.CreateStore(value, ptr);
    }

    template<typename T>
    inline RuntimeValue<T> SignExtRuntime(RuntimeValue<ulong> value, int size) const {
        return RuntimeValue<T>([=]() {
            return Builder.CreateSExt(Builder.CreateTrunc(value, llvm::Type::getIntNTy(Builder.getContext(), size)), LlvmType<T>());
        });
    }

    template<typename RetType, typename ... ArgTypes, typename = std::enable_if_t<!std::is_void_v<RetType>>>
    inline RuntimeValue<RetType> Call(RetType (*func)(ArgTypes ...), RuntimeValue<ArgTypes> ... args) const {
        return RuntimeValue<RetType>([=]() {
            return Builder.CreateCall(Builder.CreateIntToPtr((RuntimeValue<ulong>) (ulong) func, LlvmType<std::function<RetType(ArgTypes ...)>*>()), { args.Emit()... });
        });
    }

    template<typename RetType, typename ... ArgTypes, typename = std::enable_if_t<std::is_void_v<RetType>>>
    inline void Call(void (*func)(ArgTypes ...), RuntimeValue<ArgTypes> ... args) const {
        Builder.CreateCall(Builder.CreateIntToPtr((RuntimeValue<ulong>) (ulong) func, LlvmType<std::function<void(ArgTypes ...)>>()), { args.Emit()... });
    }

    inline LabelTag DefineLabel() const { return std::make_shared<_LabelTag>([=]() { return llvm::BasicBlock::Create(Builder.getContext(), "", function); }); }
    inline void Label(LabelTag label) {
        if(justBranched && suppressedBranch == label->id && !usedLabels.count(label->id)) {
            justBranched = false;
            return;
        }
        justBranched = false;
        Builder.SetInsertPoint(currentBlock = label->block());
    }
    inline void Branch(LabelTag label) {
        if(!justBranched) {
            Builder.CreateBr(label->block());
            usedLabels.insert(label->id);
        } else
            suppressedBranch = label->id;
        justBranched = true;
    }
    inline void BranchIf(RuntimeValue<bool> cond, LabelTag _if, LabelTag _else) {
        if(justBranched) return;
        usedLabels.insert(_if->id);
        usedLabels.insert(_else->id);
        Builder.CreateCondBr(cond, _if->block(), _else->block());
        justBranched = true;
    }

    inline void WithLink(const std::function<void()>& func) {
        auto next = currentPC + 4;
        XR[30] = next;
        // Handle case where the next instruction after branch is bad
        if(disassemble(*(uint*) next, next) == nullptr) {
            func();
            return;
        }
        if(!blockLabels.count(next)) {
            blockLabels[next] = DefineLabel();
            blocksNeeded.push({context, next});
        }

        auto old = context;
        context = old;
        context.LR = next;
        func();
        context = old;
    }

    inline void Branch(ulong addr) {
        LabelTag label;
        if(blockLabels.count(addr) == 0) {
            label = blockLabels[addr] = DefineLabel();
            blocksNeeded.push({context, addr});
        } else
            label = blockLabels[addr];
        Branch(label);
        branched = true;
    }
    inline void BranchLinked(ulong addr) { WithLink([=]() { Branch(addr); }); }

    inline void BranchRegister(int reg) {
        auto base = [&]() {
            BranchToR = XR[reg]();
            Branch(*preStoreRegistersLabel);
            branched = true;
        };
        if(reg != 30 || context.LR == -1UL) {
            base();
            return;
        }

        auto if_ = DefineLabel(), else_ = DefineLabel();
        BranchIf(XR[30]() == context.LR, if_, else_);
        Label(if_);
        Branch(context.LR);
        Label(else_);
        base();
    }
    inline void BranchLinkedRegister(int reg) { WithLink([=]() { BranchRegister(reg); }); }

    template<typename T>
    inline RuntimeValue<byte> CompareAndSwap(RuntimePointer<T> pointer, RuntimeValue<T> value, RuntimeValue<T> comparand) {
        assert(false);
    }
};

template<typename CondT, typename ValueT>
inline RuntimeValue<ValueT> Ternary(RuntimeValue<CondT> cond, RuntimeValue<ValueT> a, RuntimeValue<ValueT> b) {
    return RuntimeValue<ValueT>([=]() {
        auto rec = &RecompilerInstance;
        auto if_ = rec->DefineLabel(), else_ = rec->DefineLabel(), end = rec->DefineLabel();
        rec->BranchIf(cond, if_, else_);
        rec->Label(if_);
        auto av = a.Emit();
        auto ab = rec->currentBlock;
        rec->Branch(end);
        rec->Label(else_);
        auto bv = b.Emit();
        auto bb = rec->currentBlock;
        rec->Branch(end);
        rec->Label(end);
        auto phi = Builder.CreatePHI(LlvmType<ValueT>(), 2);
        phi->addIncoming(av, ab);
        phi->addIncoming(bv, bb);
        return phi;
    });
}

ulong SR(uint op0, uint op1, uint crn, uint crm, uint op2);
void SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value);

void Svc(uint svc);
