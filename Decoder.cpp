#include "Decoder.h"

Instruction Decoder::decode(uint16_t rawCode) {
    Instruction inst;
    inst.fullInst = rawCode;

    inst.opCode = (rawCode >> 12) & 0x0F;
    inst.targetReg = (rawCode >> 8) & 0x0F;
    inst.regX = (rawCode >> 4) & 0x0F;
    inst.regY = rawCode & 0x0F;
    inst.memAddr = rawCode & 0xFF;

    return inst;
}