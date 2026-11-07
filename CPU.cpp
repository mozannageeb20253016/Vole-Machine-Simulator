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
    Instruction ins = Decoder::decode((static_cast<uint16_t>(b1) << 8) | b2);
    programCounter += 2;
    uint8_t op = ins.opCode;
    uint8_t r = ins.targetReg;
    uint8_t xy = ins.memAddr;
    uint8_t x = ins.regX;
    uint8_t y = ins.regY;
    if (op == 0x1) {
        registers.setRegister(r, memory.readByte(xy));
    }
    else if (op == 0x2) {
        registers.setRegister(r, xy);
    }
    else if (op == 0x3) {
        memory.writeByte(xy, registers.getRegister(r));
        if (xy == 0xFF) {
            screen.displayByte(registers.getRegister(r));
        }
    }
    else if (op == 0x4) {
        registers.setRegister(y, registers.getRegister(x));
    }
    else if (op == 0x5) {
        uint8_t res = alu.addTwoComplement(registers.getRegister(x), registers.getRegister(y));
        registers.setRegister(r, res);
    }
    else if (op == 0x6) {
        uint8_t res = alu.addFloatingPoint(registers.getRegister(x), registers.getRegister(y));
        registers.setRegister(r, res);
    }
    else if (op == 0x7) {
        uint8_t res = alu.bitwiseOR(registers.getRegister(x), registers.getRegister(y));
        registers.setRegister(r, res);
    }
    else if (op == 0x8) {
        uint8_t res = alu.bitwiseAND(registers.getRegister(x), registers.getRegister(y));
        registers.setRegister(r, res);
    }
    else if (op == 0x9) {
        uint8_t res = alu.bitwiseXOR(registers.getRegister(x), registers.getRegister(y));
        registers.setRegister(r, res);
    }
    else if (op == 0xA) {
        uint8_t res = alu.rotateRight(registers.getRegister(r), y);
        registers.setRegister(r, res);
    }
    else if (op == 0xB) {
        if (registers.getRegister(r) == registers.getRegister(0)) {
            programCounter = xy;
        }
    }
    else if (op == 0xC) {
        return false;
    }

    return true;
}
void CPU::run() {
    while (step()) {
    }
}