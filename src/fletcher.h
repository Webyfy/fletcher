#ifndef _FLETCHER_H_
#define _FLETCHER_H_

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

uint16_t fletcher16(const uint8_t *data, size_t bytes);
uint32_t fletcher32(const uint16_t *data, size_t words);

#ifdef __cplusplus
}
#endif

#endif // _FLETCHER_H