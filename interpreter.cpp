#include "interpreter.h"
#include <iostream>
#include <ios>
#include "interface.h"
using namespace std;

Interpreter::Interpreter(CpuInterface* interface, CpuState* state) : interface(interface) {
    this->state = state == nullptr ? new CpuState : state;
    memset(this->state, 0, sizeof(CpuState));
}

void Interpreter::run(ulong pc, ulong sp) {
    state->PC = pc;
    state->SP = sp;
    bailOut = false;
    while(!bailOut) {
        if(!interface->isValidCodePointer(CodeSource::Execution, state->PC, state))
            break;
        runOne();
    }
}

void Interpreter::runOne() {
    /*cout << "-----" << endl;
    for(auto i = 0; i < 32; ++i) {
        cout << "X" << dec << i << "=" << hex << state->X[i] << "  ";
        if((i & 1) == 1) cout << endl;
    }
    cout << "PC=" << hex << state->PC << "  " << "SP=" << state->SP << endl;
    cout << "-----" << dec << endl;*/
    auto inst = *(uint*) state->PC;
    /*auto _asm = disassemble(inst, state->PC);
    if(_asm.empty()) {
        cout << "Disassembly failed at " << hex << state->PC << " --- " << inst << endl;
        exit(1);
    }
    if(logInstructions)
        cout << "Running instruction for 0x" << hex << state->PC << " (" << inst << ") - " << _asm << endl;*/
    state->BranchTo = (ulong) -3L;
    if(!interpret(inst, state->PC)) {
        //throw "Interpretation failed";
        cout << "Interpretation failed at " << hex << state->PC << " --- " << inst << endl;
        __builtin_trap();
    }
    if(state->BranchTo != (ulong) -3L) {
        state->PC = state->BranchTo;
        state->BranchTo = (ulong) -3L;
    } else
        state->PC += 4;
}

void Interpreter::runBlock(ulong pc) {
    state->PC = pc;
    bailOut = false;
    while(!bailOut) {
        if(!interface->isValidCodePointer(CodeSource::Execution, state->PC, state))
            break;
        auto inst = *(uint*) state->PC;
        /*auto _asm = disassemble(inst, state->PC);
        if(_asm.empty()) {
            cout << "Disassembly failed at " << hex << state->PC << " --- " << inst << endl;
            exit(1);
        }
        if(logInstructions)
            cout << "Running instruction for 0x" << hex << state->PC << " (" << inst << ") - " << _asm << endl;*/
        state->BranchTo = (ulong) -3L;
        /*for(auto i = 0; i < 31; ++i)
            if(state->X[i] == 0xee007265636e756f)
                __builtin_trap();*/
        if(!interpret(inst, state->PC)) {
            interface->Error((boost::format("Interpretation failed at %1$#x --- %2$#x") % state->PC % inst).str());
        }
        if(state->BranchTo != (ulong) -3L) {
            state->PC = state->BranchTo;
            state->BranchTo = (ulong) -3L;
            break;
        } else
            state->PC += 4;
    }
}

void Interpreter::Branch(ulong addr) {
    state->BranchTo = addr;
}
void Interpreter::BranchRegister(int reg) {
    state->BranchTo = state->X[reg];
}
void Interpreter::BranchLinked(ulong addr) {
    state->X30 = state->PC + 4;
    state->BranchTo = addr;
}
void Interpreter::BranchLinkedRegister(int reg) {
    state->X30 = state->PC + 4;
    state->BranchTo = state->X[reg];
}

void Interpreter::Svc(uint svc) {
    bailOut = interface->Svc(svc, state);
}

ulong Interpreter::SR(uint op0, uint op1, uint crn, uint crm, uint op2) {
    return interface->SR(op0, op1, crn, crm, op2);
}
void Interpreter::SR(uint op0, uint op1, uint crn, uint crm, uint op2, ulong value) {
    interface->SR(op0, op1, crn, crm, op2, value);
}
