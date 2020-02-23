#include <iostream>
#include <ios>
#include <interpreter.h>
#include <recompiler.h>
#include <interface.h>
using namespace std;

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
    bool isValidCodePointer(uint64_t addr, CpuState* state) override {
        cout << "Checking pointer validity: " << hex << addr << endl;
        return true;
    }
};

int main() {
    uint8_t body[] = { 0x21, 0x04, 0x00, 0x91, 0xff, 0xff, 0xff, 0x17 };
    /*auto interpreter = new Interpreter();
    interpreter->State->PC = (ulong) body;
    //while(true) {
    for(auto i = 0; i < 100000; ++i) {
        //dumpregs(interpreter);
        interpreter->runOne();
    }*/
    TestInterface interface;
    registerCpuInterface(&interface);
    RecompilerInstance.run((ulong) body, 0);
    return 0;
}
