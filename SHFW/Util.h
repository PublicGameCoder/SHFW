#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t lowByte(uint16_t wrd);

uint8_t highByte(uint16_t wrd);

uint16_t makeWord(unsigned char high, unsigned char low);

double map(double x, double in_min, double in_max, double out_min, double out_max);

double constrain(double value, double min, double max);

#ifdef __cplusplus
}
#endif

#endif // UTIL_H
