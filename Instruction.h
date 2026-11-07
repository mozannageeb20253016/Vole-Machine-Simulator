#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>

struct Instruction {
    uint16_t fullInst;
    uint8_t opCode;
    uint8_t targetReg;
    uint8_t regX;
    uint8_t regY;
    uint8_t memAddr;
};

#endif