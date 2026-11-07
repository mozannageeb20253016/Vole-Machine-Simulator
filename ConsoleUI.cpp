#include "ConsoleUI.h"
#include <iostream>

void ConsoleUI::displayState(const Memory& memory, const RegisterFile& registers, const Screen& screen, uint8_t pc) {
    std::cout << "\n------------------ CPU STATE ------------------\n";
    std::cout << "Program Counter (PC): 0x" << std::hex << (int)pc << std::dec << "\n";

    std::cout << "Registers: \n";
    for (int i = 0; i < 16; ++i) {
        std::cout << "R" << i << ": 0x" << std::hex << (int)registers.getRegister(i) << std::dec << "  ";
        if ((i + 1) % 4 == 0) std::cout << "\n";
    }

    std::cout << "-----------------------------------------------\n";
}