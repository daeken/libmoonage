#include <iostream>
#include <ios>
#include <interpreter.h>
#include <recompiler.h>
#include <interface.h>
#include <unicorn/unicorn.h>
#define UCHECKED(expr) do { if(auto _cerr = (expr)) { printf("Call " #expr " failed with error: %u (%s)\n", _cerr, uc_strerror(_cerr)); exit(1); } } while(0)
using namespace std;

#define TEST_INSTRUCTION(inst, dasm) inst,
const uint32_t test_insts[] = {
//#include "../test_instructions.generated.h"
};

void dumpregs(CpuState* state) {
    cout << "-----" << endl;
    for(auto i = 0; i < 32; ++i) {
        cout << "X" << dec << i << "=" << hex << state->X[i] << "  ";
        if((i & 1) == 1) cout << endl;
    }
    cout << "PC=" << hex << state->PC << "  " << "SP=" << state->SP << endl;
    cout << "-----" << dec << endl;
}

class TestInterface : public CpuInterface {
public:
    ulong base, end;
    TestInterface(uint8_t* body, size_t size) : base((ulong) body), end((ulong) body + size) {}
    bool isValidCodePointer(bool fromOptimizer, uint64_t addr, CpuState* state) override {
        return addr >= base && addr < end;
    }
    bool Svc(uint32_t svc, CpuState* state) override {
        assert(false);
    }
    uint64_t SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2) override {
        assert(false);
    }
    void SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2, uint64_t value) override {
        assert(false);
    }

    void Log(const string& str) override {
        cout << "Log message: " << str << endl;
    }
    void Error(const string& str) override {
        cout << "Error message: " << str << endl;
        throw new exception;
    }
};

template<typename T>
void show(T& left, T& right) {
    if constexpr(is_same<T, uint8_t>())
        cout << hex << (uint16_t) left << " vs " << (uint16_t) right << dec;
    else if constexpr(is_integral<T>())
        cout << hex << left << " vs " << right << dec;
    else if constexpr(std::is_floating_point<T>())
        cout << dec << left << " vs " << right;
}

#define TEST_STATE_MEMBER_DEFS(v) \
do { \
    v(SP); \
    v(X0 ); v(X1 ); v(X2 ); v(X3 ); v(X4 ); v(X5 ); v(X6 ); v(X7 ); \
    v(X8 ); v(X9 ); v(X10); v(X11); v(X12); v(X13); v(X14); v(X15); \
    v(X16); v(X17); v(X18); v(X19); v(X20); v(X21); v(X22); v(X23); \
    v(X24); v(X25); v(X26); v(X27); v(X28); v(X29); v(X30);         \
    v(V0 ); v(V1 ); v(V2 ); v(V3 ); v(V4 ); v(V5 ); v(V6 ); v(V7 ); \
    v(V8 ); v(V9 ); v(V10); v(V11); v(V12); v(V13); v(V14); v(V15); \
    v(V16); v(V17); v(V18); v(V19); v(V20); v(V21); v(V22); v(V23); \
    v(V24); v(V25); v(V26); v(V27); v(V28); v(V29); v(V30); v(V31); \
} while(0)

int main(int argc, char** argv) {
    uint32_t body;
    TestInterface interface((uint8_t*) &body, 4);
    auto interpreter = new Interpreter(&interface);
    uc_engine* uc;
    UCHECKED(uc_open(UC_ARCH_ARM64, UC_MODE_ARM, &uc));
    auto fpv = 3 << 20;
    UCHECKED(uc_reg_write(uc, UC_ARM64_REG_CPACR_EL1, &fpv));
    auto bpage = (uint64_t) &body & ~0xFFFULL;
    UCHECKED(uc_mem_map_ptr(uc, bpage, 0x1000, UC_PROT_READ | UC_PROT_WRITE | UC_PROT_EXEC, (void*) bpage));

    map<string, unordered_set<uint>*> ics;
    auto matchFails = 0;
    for(auto inst : test_insts) {
        auto ic = getInstructionClass(inst);
        if(ic == nullptr) {
            matchFails++;
            continue;
        }
        auto set = ics.count(ic) == 0 ? ics[ic] = new unordered_set<uint>() : ics[ic];
        set->insert(inst);
    }

    cout << "Testing " << ics.size() << "/" << instructionClassCount << " instruction classes\n";
    cout << matchFails << " unique instructions failed to match" << endl;

    CpuState unicornState;
    auto fails = 0, total = 0, ifails = 0, itotal = 0;
    for(auto& ic : ics) {
        auto& [cls, insts] = ic;
        if(cls.starts_with("ST") || cls.starts_with("LD")) continue;
        total++;
        cout << "Testing " << cls << "..." << endl;

        auto failed = false;
        for(auto inst : *insts) {
            itotal++;
            body = inst;
            auto ptr1 = (uint8_t*) interpreter->state, ptr2 = (uint8_t*) &unicornState;
            for(auto i = 0; i < sizeof(CpuState); ++i)
                ptr1[i] = ptr2[i] = (i % 254) + 1;
            unicornState.PC = interpreter->state->PC = (ulong) &body;
            unicornState.SP = interpreter->state->SP = 0x123456789abcdef1UL;
            unicornState.NZCV_N = interpreter->state->NZCV_N = 0;
            unicornState.NZCV_Z = interpreter->state->NZCV_Z = 0;
            unicornState.NZCV_C = interpreter->state->NZCV_C = 0;
            unicornState.NZCV_V = interpreter->state->NZCV_V = 0;
            try {
                interpreter->runOne();
            } catch(const char* exc) {
                cout << "\t\tFailed to execute" << endl;
                ++ifails;
                failed = true;
                continue;
            }

            for(auto i = 0; i < 29; ++i)
                uc_reg_write(uc, UC_ARM64_REG_X0 + i, &unicornState.X[i]);
            uc_reg_write(uc, UC_ARM64_REG_X29, &unicornState.X29);
            uc_reg_write(uc, UC_ARM64_REG_X30, &unicornState.X30);
            for(auto i = 0; i < 32; ++i)
                uc_reg_write(uc, UC_ARM64_REG_V0 + i, &unicornState.V[i]);
            uc_reg_write(uc, UC_ARM64_REG_SP, &unicornState.SP);
            uc_reg_write(uc, UC_ARM64_REG_PC, &unicornState.PC);
            auto nzcv = (uint64_t) (((unicornState.NZCV_N & 1) << 31) | ((unicornState.NZCV_Z & 1) << 30) | ((unicornState.NZCV_C & 1) << 29) | ((unicornState.NZCV_V & 1) << 28));
            uc_reg_write(uc, UC_ARM64_REG_NZCV, &nzcv);

            auto ret = uc_emu_start(uc, (ulong) &body, -0x1ULL, 0, 1);

            for(auto i = 0; i < 29; ++i)
                uc_reg_read(uc, UC_ARM64_REG_X0 + i, &unicornState.X[i]);
            uc_reg_read(uc, UC_ARM64_REG_X29, &unicornState.X29);
            uc_reg_read(uc, UC_ARM64_REG_X30, &unicornState.X30);
            for(auto i = 0; i < 32; ++i)
                uc_reg_read(uc, UC_ARM64_REG_V0 + i, &unicornState.V[i]);
            uc_reg_read(uc, UC_ARM64_REG_SP, &unicornState.SP);
            uc_reg_read(uc, UC_ARM64_REG_PC, &unicornState.PC);

            auto s1 = interpreter->state, s2 = &unicornState;
            auto ifailed = false;
#define CEQ(name) do { if(memcmp(&s1->name, &s2->name, sizeof(s1->name)) != 0) { if(!ifailed) { cout << "\tFailure in " << disassemble(inst, (ulong) &body) << endl; } ifailed = true; cout << "\t\tMismatch in " << #name << " "; show(s1->name, s2->name); cout << endl; } } while(0)
            TEST_STATE_MEMBER_DEFS(CEQ);
            if(ifailed) {
                ++ifails;
                failed = true;
                break;
            }
        }
        if(failed)
            fails++;
        else
            cout << "\tSUCCESS" << endl;
    }
    cout << (total - fails) << "/" << total << " passed (" << (itotal - ifails) << "/" << itotal << " instructions)" << endl;

    return 0;
}
