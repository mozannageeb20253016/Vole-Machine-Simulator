#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <cstdint>

class RegisterFile {
private:
    uint8_t m_regs[16];

public:
    RegisterFile();
    uint8_t getRegister(int regNum) const;
    void setRegister(int regNum, uint8_t val);
    void clear();
};

#endif