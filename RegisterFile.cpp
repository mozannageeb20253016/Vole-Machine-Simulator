#include "RegisterFile.h"

RegisterFile::RegisterFile() {
    clear();
}

uint8_t RegisterFile::getRegister(int regNum) const {
    if (regNum >= 0 && regNum < 16) {
        return m_regs[regNum];
    }
    return 0;
}

void RegisterFile::setRegister(int regNum, uint8_t val) {
    if (regNum >= 0 && regNum < 16) {
        m_regs[regNum] = val;
    }
}

void RegisterFile::clear() {
    for (int i = 0; i < 16; i++) {
        m_regs[i] = 0;
    }
}