#ifndef ALU_H
#define ALU_H
#include <cstdint>
class ALU {
public:
    uint8_t addTwoComplement(uint8_t val1, uint8_t val2);
    uint8_t addFloatingPoint(uint8_t val1, uint8_t val2);
    uint8_t bitwiseOR(uint8_t val1, uint8_t val2);
    uint8_t bitwiseAND(uint8_t val1, uint8_t val2);
    uint8_t bitwiseXOR(uint8_t val1, uint8_t val2);
    uint8_t rotateRight(uint8_t val, uint8_t steps);
};
#endif
