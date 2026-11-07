#include <iostream>
#include "Memory.h"
#include "RegisterFile.h"
#include "SCREEN.H"
#include "CPU.h"
#include "PROGRAM_LOADER.h"
#include "ConsoleUI.h"

int main() {
    Memory memory;
    RegisterFile regFile;
    Screen screen;

    CPU cpu(memory, regFile, screen);
    std::string programFile = "program1.txt";

    if (ProgramLoader::loadProgramFromFile(programFile, memory, 0x00)) {
        std::cout << "Program loaded successfully!" << std::endl;
        cpu.setProgramCounter(0x00);
        cpu.run();
    }
    else {
        std::cout << "Failed to load program file." << std::endl;
    }

    return 0;
}