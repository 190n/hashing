#include "xor.h"

const hash_desc xor_hash_desc = {
	.out_bits = 32,
	.salt_bits = 128,
	.func = xor_hash,
};

void xor_hash(uint8_t *out, const void *salt, size_t len, const uint8_t *data) {
	uint32_t *salt32 = (uint32_t *) salt, *out32 = (uint32_t *) out;

	*out32 = salt32[0] ^ salt32[1] ^ salt32[2] ^ salt32[3];
	for (size_t i = 0; i < len; i += 1) {
		*out32 ^= (data[i] << ((i % 4) * 8));
	}
}
