#include <iostream>
#include <ios>
#include <interpreter.h>
#include <recompiler.h>
#include <interface.h>
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
    bool isValidCodePointer(uint64_t addr, CpuState* state) override {
        //cout << "Checking pointer validity: " << hex << addr << endl;
        return addr != 0xDEADBEE0;
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

int main(int argc, char** argv) {
    //uint8_t body[] = { 0x21, 0x00, 0x80, 0xd2, 0x02, 0xe2, 0x84, 0xd2, 0x00, 0x00, 0x01, 0x8b, 0x43, 0x00, 0x00, 0xcb, 0xc3, 0xff, 0xff, 0xb5, 0xc0, 0x03, 0x5f, 0xd6 };
    uint8_t body[] = { 0x21, 0x00, 0x80, 0xd2, 0x02, 0xe2, 0x84, 0xd2, 0x00, 0x00, 0x01, 0x8b, 0x1f, 0x00, 0x02, 0xeb, 0xcb, 0xff, 0xff, 0x54, 0xc0, 0x03, 0x5f, 0xd6 };
    TestInterface interface;
    registerCpuInterface(&interface);

    if(argc == 1) {
        RecompilerInstance.state.X30 = 0xDEADBEE0;
        RecompilerInstance.run((ulong) body, 0);
        dumpregs(&RecompilerInstance.state);
    } else {
        auto interpreter = new Interpreter();
        interpreter->state->X30 = 0xDEADBEE0;
        interpreter->run((ulong) body, 0);
        dumpregs(interpreter->state);
    }

    return 0;
}
