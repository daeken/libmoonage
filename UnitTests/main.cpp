#include <iostream>
#include <ios>
#include <interpreter.h>
#include <recompiler.h>
#include <interface.h>
#include "insts.h"
using namespace std;

void dumpregs(volatile CpuState* state) {
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
    bool isValidCodePointer(uint64_t addr, CpuState* state) override {
        return addr >= base && addr < end;
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

int main(int argc, char** argv) {
    uint32_t body;
    TestInterface interface((uint8_t*) &body, 4);
    registerCpuInterface(&interface);
    auto interpreter = new Interpreter();

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

    auto fails = 0, total = 0;
    for(auto& ic : ics) {
        auto& [cls, insts] = ic;
        if(cls.starts_with("ST") || cls.starts_with("LD")) continue;
        total++;
        cout << "Testing " << cls << "..." << endl;

        auto failed = false;
        for(auto inst : *insts) {
            body = inst;
            auto ptr1 = (uint8_t*) &RecompilerInstance.state, ptr2 = (uint8_t*) interpreter->State;
            for(auto i = 0; i < sizeof(CpuState); ++i)
                ptr1[i] = ptr2[i] = (i % 254) + 1;
            interpreter->run((ulong) &body, 0x123456789abcdef1UL);
            Cache.Clear();
            RecompilerInstance.run((ulong) &body, 0x123456789abcdef1UL);

            auto s1 = interpreter->State, s2 = (CpuState*) &RecompilerInstance.state;
#define CEQ(name) do { if(memcmp(&s1->name, &s2->name, sizeof(s1->name)) != 0) { failed = true; cout << "\tMismatch in " << #name << " "; show(s1->name, s2->name); cout << endl; } } while(0)
            CEQ(PC);
            CEQ(SP);
            CEQ(X0 ); CEQ(X1 ); CEQ(X2 ); CEQ(X3 ); CEQ(X4 ); CEQ(X5 ); CEQ(X6 ); CEQ(X7 ); CEQ(X8 ); CEQ(X9 );
            CEQ(X10); CEQ(X11); CEQ(X12); CEQ(X13); CEQ(X14); CEQ(X15); CEQ(X16); CEQ(X17); CEQ(X18); CEQ(X19);
            CEQ(X20); CEQ(X21); CEQ(X22); CEQ(X23); CEQ(X24); CEQ(X25); CEQ(X26); CEQ(X27); CEQ(X28); CEQ(X29);
            CEQ(X30);
            CEQ(V0 ); CEQ(V1 ); CEQ(V2 ); CEQ(V3 ); CEQ(V4 ); CEQ(V5 ); CEQ(V6 ); CEQ(V7 ); CEQ(V8 ); CEQ(V9 );
            CEQ(V10); CEQ(V11); CEQ(V12); CEQ(V13); CEQ(V14); CEQ(V15); CEQ(V16); CEQ(V17); CEQ(V18); CEQ(V19);
            CEQ(V20); CEQ(V21); CEQ(V22); CEQ(V23); CEQ(V24); CEQ(V25); CEQ(V26); CEQ(V27); CEQ(V28); CEQ(V29);
            CEQ(V30); CEQ(V31);
            CEQ(Exclusive8);
            CEQ(Exclusive16);
            CEQ(Exclusive32);
            CEQ(Exclusive64);
            CEQ(NZCV_N);
            CEQ(NZCV_Z);
            CEQ(NZCV_C);
            CEQ(NZCV_V);
            if(failed) break;
        }
        if(failed)
            fails++;
        cout << "\t" << (failed ? "FAIL" : "SUCCESS") << endl;
    }
    cout << (total - fails) << "/" << total << " passed" << endl;

    return 0;
}
