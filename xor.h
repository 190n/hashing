#ifndef __XOR_H__
#define __XOR_H__

#include "hash_function.h"

#include <stddef.h>
#include <stdint.h>

void xor_hash(uint8_t *out, const void *salt, size_t len, const uint8_t *data);

extern const hash_desc xor_hash_desc;

#endif
