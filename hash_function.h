#ifndef __HASH_FUNCTION_H__
#define __HASH_FUNCTION_H__

#include <stddef.h>
#include <stdint.h>

typedef void (*hash_function)(uint8_t *out, const void *salt, size_t len, const uint8_t *data);

typedef struct {
	size_t out_bits;
	size_t salt_bits;
	hash_function func;
} hash_desc;

#endif
