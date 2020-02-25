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
    bool Svc(uint32_t svc, CpuState* state) override {
        assert(false);
    }
    uint64_t SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2) override {
        assert(false);
    }
    void SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2, uint64_t value) override {
        assert(false);
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
            auto ptr1 = (uint8_t*) &RecompilerInstance.state, ptr2 = (uint8_t*) interpreter->state;
            for(auto i = 0; i < sizeof(CpuState); ++i)
                ptr1[i] = ptr2[i] = (i % 254) + 1;
            interpreter->run((ulong) &body, 0x123456789abcdef1UL);
            Cache.Clear();
            RecompilerInstance.run((ulong) &body, 0x123456789abcdef1UL);

            auto s1 = interpreter->state, s2 = (CpuState*) &RecompilerInstance.state;
            auto ifailed = false;
#define CEQ(name) do { if(memcmp(&s1->name, &s2->name, sizeof(s1->name)) != 0) { if(!ifailed) { cout << "\tFailure in " << disassemble(inst, (ulong) &body) << endl; } ifailed = true; cout << "\t\tMismatch in " << #name << " "; show(s1->name, s2->name); cout << endl; } } while(0)
            STATE_MEMBER_DEFS(CEQ);
            if(ifailed) {
                ++ifails;
                failed = true;
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
