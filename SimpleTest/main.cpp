#include <common.h>
#include <metacpu.h>
#include <interface.h>
using namespace std;

class TestInterface : public CpuInterface {
public:
    uint64_t base, end;
    TestInterface(uint8_t* body, size_t size) : base((ulong) body), end((ulong) body + size) {}
    bool isValidCodePointer(CodeSource source, uint64_t addr, CpuState* state) override {
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

int main() {
    uint8_t body[] = {
            0x00, 0x00, 0x40, 0xbd,
            0x21, 0x00, 0x40, 0xbd,
            0x02, 0x28, 0x21, 0x1e,
            0xc0, 0x03, 0x5f, 0xd6
    };
    auto interface = new TestInterface(body, 4 * 4);
    auto metacpu = new MetaCpu(interface);
    metacpu->setBaseline(MetaMode::LightRecompiling);
    metacpu->initialize();
    auto fp1 = 6.7f, fp2 = 7.9f;
    metacpu->state->X0 = (uint64_t) &fp1;
    metacpu->state->X1 = (uint64_t) &fp2;
    metacpu->run((uint64_t) body, 0xf000);
    //cout << "0xdeadbeef + 0xf00b == 0x" << hex << metacpu->state->X0 << " (should be 0x" << (0xdeadbeefUL + 0xf00b) << ")" << endl;
    cout << fp1 << " + " << fp2 << " == " << metacpu->state->V2[0] << " (should be " << (fp1 + fp2) << ")" << endl;
}
