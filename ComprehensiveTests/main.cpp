#include <iostream>
#include <ios>
#include <interpreter.h>
#include <recompiler.h>
#include <interface.h>
#include <sys/mman.h>
#include <signal.h>
using namespace std;

#define TESTCASE_COUNT 16
CpuState** testcases;
Interpreter* interpreter;
Recompiler* recompiler;
uint32_t* insnBase;

class TestCpuInterface : public CpuInterface {
public:
    bool isValidCodePointer(uint64_t addr, CpuState* state) override { return addr == (uint64_t) insnBase; }
    bool Svc(uint32_t svc, CpuState* state) override { return false; }
    uint64_t SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2) override { return 0; }
    void SR(uint32_t op0, uint32_t op1, uint32_t crn, uint32_t crm, uint32_t op2, uint64_t value) override { }
};

bool runOneInstruction(uint32_t insn, CpuState* testcase) {
    auto cpid = fork();
    if(cpid == 0) { // Child
        insnBase[0] = insn;
        insnBase[1] = insnBase[2] = 0xD503201F;
        memcpy(interpreter->state, testcase, sizeof(CpuState));
        memcpy((CpuState*) &recompiler->state, testcase, sizeof(CpuState));

        try {
            interpreter->runOne();
        } catch(...) {
            cout << "if" << endl;
            exit(1);
        }
        try {
            recompiler->runOne();
        } catch(...) {
            cout << "rf" << endl;
            exit(1);
        }

        interpreter->state->BranchTo = recompiler->state.BranchTo = 0;
        interpreter->state->X31 = recompiler->state.X31 = 0;
        if(memcmp(interpreter->state, (CpuState*) &recompiler->state, sizeof(CpuState)) == 0)
            exit(0);
        for(auto i = 0; i < sizeof(CpuState); ++i)
            if(((uint8_t*) interpreter->state)[i] != ((uint8_t*) &recompiler->state)[i]) {
                cout << "mm* " << dec << i << endl;
                break;
            }
        exit(1);
    } else { // Parent
        alarm(5);
        int status;
        if(EINTR == waitpid(cpid, &status, 0)) {
            cout << "to" << endl;
            kill(cpid, 9);
            alarm(0);
            return false;
        }
        return WIFEXITED(status) && WEXITSTATUS(status) == 0;
    }
}

bool testInstruction(const string& mnem, uint32_t insn) {
    auto disassembled = false;
    try {
        disassembled = !disassemble(insn, (uint64_t) insnBase).empty();
    } catch(...) {
    }
    if(!disassembled) {
        cout << "df " << hex << insn << endl;
        return false;
    }
    for(auto i = 0; i < TESTCASE_COUNT; ++i)
        if(!runOneInstruction(insn, testcases[i])) {
            cout << "fi " << hex << insn << " " << dec << i << endl;
            return false;
        }
    //cout << "Success with " << mnem << " 0x" << hex << insn << endl;
    return true;
}

#pragma pack(1)
struct TestcaseNative {
    uint64_t V[64];
    uint64_t X[31];
    uint8_t NZCV;
};
#pragma pack()

CpuState* readTestcase(FILE* fp) {
    TestcaseNative ntc;
    fread(&ntc, sizeof(TestcaseNative), 1, fp);
    auto state = new CpuState;
    memset(state, 0, sizeof(CpuState));
    memcpy(state->X, ntc.X, 8 * 31);
    memcpy(state->V, ntc.V, 16 * 32);
    state->NZCV_N = (ntc.NZCV >> 3) & 1;
    state->NZCV_Z = (ntc.NZCV >> 2) & 1;
    state->NZCV_C = (ntc.NZCV >> 1) & 1;
    state->NZCV_V = (ntc.NZCV >> 0) & 1;
    state->PC = (uint64_t) insnBase;
    state->SP = 0x7ffffff00;
    return state;
}

int main() {
    //mprotect((void*) 0x100000000, 0x1000, PROT_READ | PROT_WRITE);
    //*((uint32_t*) 0x100000000) = 0xf00;
    insnBase = (uint32_t*) mmap(nullptr, 0x1000, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);

    registerCpuInterface(new TestCpuInterface);
    recompiler = &RecompilerInstance;
    recompiler->noLocalBranches = true;
    interpreter = new Interpreter;

    unordered_map<string, vector<uint32_t>*> allInsts;
    unordered_map<string, int> instOffsets;

    auto fp = fopen("limitedInsns.bin", "rb");
    assert(fp != nullptr);
    uint32_t numInsts = 0;
    fread(&numInsts, sizeof(uint32_t), 1, fp);
    for(auto i = 0; i < numInsts; ++i) {
        uint32_t numSeq = 0, mnemLen = 0;
        fread(&numSeq, sizeof(uint32_t), 1, fp);
        fread(&mnemLen, sizeof(uint32_t), 1, fp);
        auto mnemCStr = new char[mnemLen];
        fread(mnemCStr, 1, mnemLen, fp);
        string mnem(mnemCStr);
        auto vec = allInsts[mnem] = new vector<uint32_t>();
        instOffsets[mnem] = 0;
        for(auto j = 0; j < numSeq; ++j) {
            uint32_t inst;
            fread(&inst, sizeof(uint32_t), 1, fp);
            vec->push_back(inst);
        }
    }

    fp = fopen("baselineStates.bin", "rb");
    assert(fp != nullptr);
    uint8_t count;
    fread(&count, 1, 1, fp);
    assert(count == TESTCASE_COUNT);
    testcases = new CpuState*[TESTCASE_COUNT];
    for(auto i = 0; i < TESTCASE_COUNT; ++i)
        testcases[i] = readTestcase(fp);

    while(true) {
        auto found = false;

        for(auto& [mnem, insts] : allInsts) {
            auto offset = instOffsets[mnem]++;
            if(offset >= insts->size())
                continue;
            found = true;
            if(!testInstruction(mnem, (*insts)[offset])) {
                cout << "mf " << mnem << " " << dec << offset << endl;
                instOffsets[mnem] = insts->size();
            } else if(offset == insts->size() - 1)
                cout << "ms " << mnem << endl;
        }

        if(!found)
            break;
    }

    return 0;
}
