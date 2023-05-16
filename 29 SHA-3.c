#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 128 
#define STATE_SIZE 200 
#define HASH_SIZE 32 
#define ROTL64(x,n) ((x)<<(n))|((x)>>(64-(n)))

const uint64_t RC[24] = {
    0x0000000000000001ULL,
    0x0000000000008082ULL,
    0x800000000000808aULL,
    0x8000000080008000ULL,
    0x000000000000808bULL,
    0x0000000080000001ULL,
    0x8000000080008081ULL,
    0x8000000000008009ULL,
    0x000000000000008aULL,
    0x0000000000000088ULL,
    0x0000000080008009ULL,
    0x000000008000000aULL,
    0x000000008000808bULL,
    0x800000000000008bULL,
    0x8000000000008089ULL,
    0x8000000000008003ULL,
    0x8000000000008002ULL,
    0x8000000000000080ULL,
    0x000000000000800aULL,
    0x800000008000000aULL,
    0x8000000080008081ULL,
    0x8000000000008080ULL,
    0x0000000080000001ULL,
    0x8000000080008008ULL
};

void sha3(const uint8_t *message, uint64_t message_size, uint8_t *hash) {
  
    uint64_t state[STATE_SIZE];
    memset(state, 0, STATE_SIZE * sizeof(uint64_t));

    uint64_t message_blocks = (message_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    uint64_t block_offset = 0;
    for (uint64_t i = 0; i < message_blocks; i++) {
        for (uint64_t j = 0; j < BLOCK_SIZE / sizeof(uint64_t); j++) {
            uint64_t word = 0;
            for (uint64_t k = 0; k < sizeof(uint64_t); k++) {
                uint8_t byte = 0;
                if (block_offset < message_size) {
                    byte = message[block_offset];
                }
                word |= ((uint64_t)byte) << (k * 8);
                block_offset++;
            }
            state[j] ^= word;
        }

    }

    memset(&state[25], 0, 3 * sizeof(uint64_t));

        uint64_t round = 0;
    while (1) {
        uint64_t zero_lanes = 0;
        for (uint64_t i = 0; i < 25; i++) {
            if (i % 5 < 3) {
               
                zero_lanes |= state[i] ^ state[25 + (i % 5)];
            } else {
                
                zero_lanes |= state[i];
            }
        }
        if (zero_lanes == 0) {
            break;
        }

        state[25] ^= RC[round];

        round++;
    }

    for (uint64_t i = 0; i < HASH_SIZE / sizeof(uint64_t); i++) {
        uint64_t word = 0;
        for (uint64_t j = 0; j < sizeof(uint64_t); j++) {
            uint8_t byte = ((uint8_t*)state)[i * sizeof(uint64_t) + j];
            word |= ((uint64_t)byte) << (j * 8);
        }
        ((uint64_t*)hash)[i] = word;
    }
}
