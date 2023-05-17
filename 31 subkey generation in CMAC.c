#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE_64 8 
#define BLOCK_SIZE_128 16 

void generate_subkeys(const uint8_t *block, int block_size, uint8_t *subkey1, uint8_t *subkey2) {
    uint8_t L[block_size]; 
    uint8_t const_R[block_size];

    for (int i = 0; i < block_size; i++) {
        L[i] = 0;
    }

    if (block_size == BLOCK_SIZE_64) {
        const_R[0] = 0x1B; 
    } else if (block_size == BLOCK_SIZE_128) {
        const_R[0] = 0x87; 
    }

    for (int i = 0; i < block_size; i++) {
        subkey1[i] = L[i] << 1;
        if (i < block_size - 1 && (L[i+1] & 0x80)) {
            subkey1[i] |= 0x01;
        }
        subkey1[i] ^= const_R[i];
    }

    for (int i = 0; i < block_size; i++) {
        subkey2[i] = subkey1[i] << 1;
        if (i < block_size - 1 && (subkey1[i+1] & 0x80)) {
            subkey2[i] |= 0x01;
        }
        subkey2[i] ^= const_R[i];
    }
}

int main() {
    uint8_t block[BLOCK_SIZE_64] = {0}; 
    uint8_t subkey1[BLOCK_SIZE_64], subkey2[BLOCK_SIZE_64];

    generate_subkeys(block, BLOCK_SIZE_64, subkey1, subkey2);

    printf("Subkey 1: ");
    for (int i = 0; i < BLOCK_SIZE_64; i++) {
        printf("%02x ", subkey1[i]);
    }
    printf("\n");

    printf("Subkey 2: ");
    for (int i = 0; i < BLOCK_SIZE_64; i++) {
        printf("%02x ", subkey2[i]);
    }
    printf("\n");

    return 0;
}
