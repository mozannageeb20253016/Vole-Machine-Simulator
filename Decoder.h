#ifndef DECODER_H
#define DECODER_H

#include "Instruction.h"

class Decoder {
public:
    static Instruction decode(uint16_t rawCode);
};

#endif