#include "CPU.h"
#include "Instruction.h"
#include <iostream>

CPU::CPU(Memory& mem, RegisterFile& reg, Screen& scr)
    : memory(mem), registers(reg), screen(scr), programCounter(0) {
}

void CPU::setProgramCounter(uint8_t address) {
    programCounter = address;
}

uint8_t CPU::getProgramCounter() const {
    return programCounter;
}

bool CPU::step() {
    if (programCounter > 0xFE) return false;

    uint8_t b1 = memory.readByte(programCounter);
    uint8_t b2 = memory.readByte(programCounter + 1);
    programCounter += 2;

    uint16_t rawCode = (static_cast<uint16_t>(b1) << 8) | b2;

    Instruction ins = Decoder::decode((uint16_t(b1) << 8) | b2);

    uint8_t op = ins.opCode;
    uint8_t r = ins.targetReg;
    uint8_t xy = ins.memAddr;
    uint8_t x = ins.regX;
    uint8_t y = ins.regY;

    if (op == 0xC) return false;

    return true;
}

void CPU::run() {
    while (step()) {
        // Continue stepping through instructions until a halt instruction is encountered
    }
}