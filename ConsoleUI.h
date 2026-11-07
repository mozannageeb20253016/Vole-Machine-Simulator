#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "Memory.h"
#include "RegisterFile.h"
#include "Screen.h"

class ConsoleUI {
public:
    static void displayState(const Memory& memory, const RegisterFile& registers, const Screen& screen, uint8_t pc);
};

#endif#pragma once
