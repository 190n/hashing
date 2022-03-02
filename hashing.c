#include "hash_function.h"
#include "xor.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline size_t div_8_ceil(size_t n) {
	return (n % 8 == 0) ? (n / 8) : (n / 8 + 1);
}

double check_avalanche(hash_desc h, const void *salt, size_t len, const uint8_t *data) {
	uint8_t *flipped_data = (uint8_t *) malloc(len * sizeof(uint8_t));
	uint8_t *orig_out = (uint8_t *) calloc(div_8_ceil(h.out_bits), sizeof(uint8_t)),
	        *flipped_out = (uint8_t *) calloc(div_8_ceil(h.out_bits), sizeof(uint8_t));
	memcpy(flipped_data, data, len);
	h.func(orig_out, salt, len, data);

	double sum_flipped_fraction = 0.0;

	// flip each bit one at a time
	for (size_t bit = 0; bit < 8 * len; bit += 1) {
		uint8_t mask = 0x01 << (bit % 8);
		flipped_data[bit / 8] ^= mask;
		// try hashing
		h.func(flipped_out, salt, len, flipped_data);
		// count flipped bits
		size_t flipped = 0;
		for (size_t i = 0; i < h.out_bits; i += 1) {
			if (flipped_data[i / 8] & (0x01 << (i % 8))) {
				flipped += 1;
			}
		}
		sum_flipped_fraction += (double) flipped / (double) h.out_bits;
		// flip it back
		flipped_data[bit / 8] ^= mask;
	}

	// divide by total number of bits to get an average
	return sum_flipped_fraction / (double) (8 * len);
}

int main(int argc, char **argv) {
	assert(argc == 2);
	uint32_t salt[4] = { 0xdeadbeef, 0xbeefd00d, 0xbeefbbad, 0x12345678 };
	printf("%f\n", check_avalanche(xor_hash_desc, salt, strlen(argv[1]), (uint8_t *) argv[1]));
	return EXIT_SUCCESS;
}
