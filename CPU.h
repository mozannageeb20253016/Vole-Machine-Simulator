#ifndef CPU_H
#define CPU_H

#include "Memory.h"
#include "RegisterFile.h"
#include "ALU.h"
#include "SCREEN.H"
#include "Decoder.h"

class CPU {
private:
    Memory& memory;
    RegisterFile& registers;
    ALU alu;
    Screen& screen;
    uint8_t programCounter;

public:
    CPU(Memory& mem, RegisterFile& reg, Screen& scr);
    void setProgramCounter(uint8_t address);
    uint8_t getProgramCounter() const;
    bool step();
    void run();
};

#endif