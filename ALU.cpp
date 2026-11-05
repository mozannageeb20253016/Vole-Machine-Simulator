#include "ALU.h"
#include <cmath>
uint8_t ALU::addTwoComplement(uint8_t val1, uint8_t val2) {
    return val1 + val2;
}
uint8_t ALU::bitwiseOR(uint8_t val1, uint8_t val2) {
    return val1 | val2;
}
uint8_t ALU::bitwiseAND(uint8_t val1, uint8_t val2) {
    return val1 & val2;
}
uint8_t ALU::bitwiseXOR(uint8_t val1, uint8_t val2) {
    return val1 ^ val2;
}
uint8_t ALU::rotateRight(uint8_t val, uint8_t steps) {
    steps = steps % 8;
    if (steps == 0) {
        return val;
    }
    return (val >> steps) | (val << (8 - steps));
}
uint8_t ALU::addFloatingPoint(uint8_t val1, uint8_t val2) {
    double s1 = ((val1 & 0x80) != 0) ? -1.0 : 1.0;
    int e1 = ((val1 & 0x70) >> 4) - 4;
    double m1 = (val1 & 0x0F) / 16.0;
    double s2 = ((val2 & 0x80) != 0) ? -1.0 : 1.0;
    int e2 = ((val2 & 0x70) >> 4) - 4;
    double m2 = (val2 & 0x0F) / 16.0;
    double v1 = s1 * m1 * std::pow(2, e1);
    double v2 = s2 * m2 * std::pow(2, e2);
    double sum = v1 + v2;
    if (sum == 0.0) {
        return 0x00;
    }
    uint8_t sign = 0;
    if (sum < 0) {
        sign = 1;
        sum = -sum;
    }
    int exp = 0;
    while (sum >= 1.0) {
        sum /= 2.0;
        exp++;
    }
    while (sum < 0.5 && exp > -4) {
        sum *= 2.0;
        exp--;
    }
    int biasedExp = exp + 4;
    if (biasedExp < 0) biasedExp = 0;
    if (biasedExp > 7) biasedExp = 7;
    uint8_t mant = static_cast<uint8_t>(sum * 16.0);
    if (mant > 15) mant = 15;
    return (sign << 7) | ((biasedExp & 0x07) << 4) | (mant & 0x0F);
}