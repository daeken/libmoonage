#pragma once

#include "common.h"
#include "state.h"
#include "cacheManager.h"
#include "lightRuntimeValue.h"
#include "interface.h"

#include <unordered_set>
#include <queue>
using std::unordered_set;
using std::queue;
using std::tuple;

#include "xbyak/xbyak.h"

int Svc(ulong recompilerPtr, uint svc, ulong state);
ulong SR(ulong recompilerPtr, uint op0, uint op1, uint crn, uint crm, uint op2);
void SR(ulong recompilerPtr, uint op0, uint op1, uint crn, uint crm, uint op2, ulong value);

class EXPORTED LightRecompiler {
public:
    LightRecompiler();
    bool recompile(uint inst, ulong pc);
    void run(ulong pc, ulong sp);
    void runOne(Block* block);
    void runOne();
    void precompile(ulong pc);
    void recompileMultiple(Block* block);

    CpuState state;
    bool isOptimizer = false;
    CpuInterface* interface;
    ulong currentPC;

    LightLabel prologue, epilogue;
    BlockContext context;
    bool noLocalBranches;
    bool branched;
    unordered_map<ulong, LightLabel> blockLabels;
    queue<tuple<BlockContext, ulong>> blocksNeeded;
    LightRuntimeValue<ulong> CpuStateRef{[]() { LC->push(rbx); }};
#define FieldAddress(name) (CpuStateRef + offsetof(CpuState, name))

    Indexer<LightRuntimeValue<uint64_t>> XR{
        [=](auto reg) {
            if(reg == 31)
                return LightRuntimeValue<uint64_t>(0);
            return LightRuntimePointer<uint64_t>(CpuStateRef + offsetof(CpuState, X0) + 8 * reg).value();
        },
        [=](auto reg, auto value) {
            if(reg == 31) {
                value.Emit();
                LC->pop(rax);
                return;
            }
            LightRuntimePointer<uint64_t>(CpuStateRef + offsetof(CpuState, X0) + 8 * reg).value(value);
        }
    };
    Indexer<LightRuntimeValue<Vector128<float>>> VR{
        [=](auto reg) {
            return LightRuntimePointer<Vector128<float>>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value();
        },
        [=](auto reg, auto value) {
            LightRuntimePointer<Vector128<float>>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value(value);
        }
    };
    Indexer<LightRuntimeValue<uint8_t>> VBR{
        [=](auto reg) {
            return LightRuntimePointer<uint8_t>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value();
        },
        [=](auto reg, auto value) {
            LightRuntimePointer<__uint128_t>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value(value);
        }
    };
    Indexer<LightRuntimeValue<uint16_t>> VHR{
            [=](auto reg) {
                return LightRuntimePointer<uint16_t>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value();
            },
            [=](auto reg, auto value) {
                LightRuntimePointer<__uint128_t>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value(value);
            }
    };
    Indexer<LightRuntimeValue<float>> VSR{
            [=](auto reg) {
                return LightRuntimePointer<float>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value();
            },
            [=](auto reg, auto value) {
                LightRuntimePointer<__uint128_t>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value(value.template Bitcast<uint32_t>());
            }
    };
    Indexer<LightRuntimeValue<double>> VDR{
            [=](auto reg) {
                return LightRuntimePointer<double>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value();
            },
            [=](auto reg, auto value) {
                LightRuntimePointer<__uint128_t>(CpuStateRef + offsetof(CpuState, V0) + 16 * reg).value(value.template Bitcast<uint64_t>());
            }
    };

#undef FIELD
#define FIELD(name) Property<LightRuntimeValue<decltype(CpuState::name)>> name##R{ \
    [=]() { return LightRuntimePointer<decltype(CpuState::name)>(CpuStateRef + offsetof(CpuState, name)).value(); }, \
    [=](auto value) { LightRuntimePointer<decltype(CpuState::name)>(CpuStateRef + offsetof(CpuState, name)).value(value); } \
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
    Property<LightRuntimeValue<uint64_t>> NZCVR{
        [=]() { return (NZCV_NR() << 31) | (NZCV_ZR() << 30) | (NZCV_CR() << 29) | (NZCV_VR() << 28); },
        [=](auto value) {
            NZCV_NR = (value >> 31) & 1;
            NZCV_ZR = (value >> 30) & 1;
            NZCV_CR = (value >> 29) & 1;
            NZCV_VR = (value >> 28) & 1;
        }
    };

    template<typename T>
    inline LightRuntimeValue<T> SignExtRuntime(LightRuntimeValue<ulong> value, int size) const {
        return Call<T, uint64_t, int>(SignExt, value, size);
    }

    template<typename TFirst, typename ... TRest>
    inline static void EmitArgs(LightRuntimeValue<TFirst> first, LightRuntimeValue<TRest> ... rest) {
        if constexpr(sizeof...(rest) != 0) EmitArgs(rest ...);
        first.Emit();
    }

    template<typename TFirst, typename ... TRest>
    inline static void UnrollArgs(int intArgs, int vecArgs, LightRuntimeValue<TFirst> first, LightRuntimeValue<TRest> ... rest) {
        if constexpr(is_vector_t<TFirst>() || is_floating_point<TFirst>()) {
            Xbyak::Xmm reg;
            switch(vecArgs) {
                case 0: reg = xmm0; break;
                case 1: reg = xmm1; break;
                case 2: reg = xmm2; break;
                case 3: reg = xmm3; break;
                case 4: reg = xmm4; break;
                case 5: reg = xmm5; break;
                case 6: reg = xmm6; break;
                case 7: reg = xmm7; break;
                default: throw "Too many vector arguments!";
            }
            LC->pop(rax);
            LC->movq(reg, rax);
            if constexpr(is_vector_t<TFirst>()) {
                LC->pop(rax);
                LC->pinsrq(reg, rax, 1);
            } else
                static_assert(sizeof(TFirst) <= 8);
            vecArgs++;
        } else {
            static_assert(sizeof(TFirst) <= 8);
            switch(intArgs) {
                case 0: LC->pop(rdi); break;
                case 1: LC->pop(rsi); break;
                case 2: LC->pop(rdx); break;
                case 3: LC->pop(rcx); break;
                case 4: LC->pop(r8); break;
                case 5: LC->pop(r9); break;
                default: throw "Too many integer arguments!";
            }
            intArgs++;
        }

        if constexpr(sizeof...(rest) != 0) UnrollArgs(intArgs, vecArgs, rest ...);
    }

    template<typename RetType, typename ... ArgTypes, typename = std::enable_if_t<!std::is_void_v<RetType>>>
    inline LightRuntimeValue<RetType> Call(RetType (*func)(ArgTypes ...), LightRuntimeValue<ArgTypes> ... args) const {
        return LightRuntimeValue<RetType>([func, args...]() {
            if constexpr(sizeof...(args) != 0) { EmitArgs(args ...); UnrollArgs(0, 0, args ...); }
            LC->call(func);
            if constexpr(is_vector_t<RetType>()) {
                LC->movq(rax, xmm0);
                LC->movhlps(xmm0, xmm0);
                LC->movq(rdx, xmm0);
                LC->push(rax);
                LC->push(rdx);
            } else if constexpr(is_floating_point<RetType>()) {
                LC->movq(rax, xmm0);
                if constexpr(sizeof(RetType) == 4)
                    LC->mov(eax, eax);
                else
                    static_assert(sizeof(RetType) == 8);
                LC->push(rax);
            } else {
                static_assert(sizeof(RetType) <= 8);
                LC->push(rax);
            }
        });
    }

    template<typename RetType, typename ... ArgTypes, typename = std::enable_if_t<std::is_void_v<RetType>>>
    inline void Call(void (*func)(ArgTypes ...), LightRuntimeValue<ArgTypes> ... args) const {
        if constexpr(sizeof...(args) != 0) { EmitArgs(args ...); UnrollArgs(0, 0, args ...); }
        LC->call(func);
    }

    inline LightLabel DefineLabel() const { return std::make_shared<_LightLabel>(); }
    inline void Label(LightLabel label) {
        LC->L(label->label);
    }

    inline void CallSvc(uint svc) {
    }

    inline void Branch(LightLabel label) {
        LC->jmp(label->label);
    }
    inline void BranchIf(const LightRuntimeValue<bool>& cond, LightLabel _if, LightLabel _else) {
        cond.Emit();
        LC->pop(rax);
        LC->test(al, al);
        LC->jnz(_if->label);
        LC->jmp(_else->label);
    }

    inline void WithLink(const std::function<void()>& func) {
        auto next = currentPC + 4;
        XR[30] = next;
        // Handle case where the next instruction after branch is bad
        // Or we're only recompiling a single block for debugging
        if(noLocalBranches || getInstructionClass(*(uint*) next) == nullptr) {
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
        if(noLocalBranches) {
            BranchToR = addr;
            LC->jmp(epilogue->label);
            branched = true;
            return;
        }
        LightLabel label;
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
            LC->jmp(epilogue->label);
            branched = true;
        };
        // Uncomment to follow paths after bl(r) instructions
        //if(reg != 30 || context.LR == -1UL) {
            base();
            return;
        //}

        auto if_ = DefineLabel(), else_ = DefineLabel();
        BranchIf(XR[30]() == context.LR, if_, else_);
        Label(if_);
        Branch(context.LR);
        Label(else_);
        base();
    }
    inline void BranchLinkedRegister(int reg) { WithLink([=]() { BranchRegister(reg); }); }

    template<typename T>
    inline LightRuntimeValue<uint8_t> CompareAndSwap(LightRuntimePointer<T> pointer, LightRuntimeValue<T> value, LightRuntimeValue<T> comparand) {
        return Call<uint8_t, T*, T, T>(::CompareAndSwap, pointer.address.template Bitcast<T*>(), value, comparand);
    }

#include "recompiler.generated.h" // We can use the recompiler one; this just defines methods for each instruction
};

template<typename CondT, typename ValueT>
inline LightRuntimeValue<ValueT> Ternary(LightRuntimeValue<CondT> cond, LightRuntimeValue<ValueT> a, LightRuntimeValue<ValueT> b) {
    return LightRuntimeValue<ValueT>([=]() {
        auto rec = &LightRecompilerInstance;
        auto if_ = rec->DefineLabel(), else_ = rec->DefineLabel(), end = rec->DefineLabel();
        rec->BranchIf(cond, if_, else_);
        rec->Label(if_);
        a.Emit();
        rec->Branch(end);
        rec->Label(else_);
        b.Emit();
        rec->Label(end);
    });
}
