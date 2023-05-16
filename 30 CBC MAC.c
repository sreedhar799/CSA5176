#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 16 
#define KEY_SIZE 16 

void cbc_mac(const uint8_t *key, const uint8_t *message, uint8_t *mac) {
    uint8_t iv[BLOCK_SIZE]; 
    uint8_t block[BLOCK_SIZE]; 
    uint8_t cipher[BLOCK_SIZE]; 
    uint8_t last_cipher[BLOCK_SIZE];

    memset(iv, 0, BLOCK_SIZE);

    memcpy(last_cipher, iv, BLOCK_SIZE);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = message[i] ^ last_cipher[i];
    }


    memcpy(last_cipher, cipher, BLOCK_SIZE);

    memcpy(mac, last_cipher, BLOCK_SIZE);
}

int main() {
    uint8_t key[KEY_SIZE] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10}; // 128-bit key
    uint8_t message[BLOCK_SIZE] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10}; // One-block message (X)
    uint8_t mac[BLOCK_SIZE];

    cbc_mac(key, message, mac);

    printf("MAC for one-block message X: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", mac[i]);
    }
    printf("\n");

    uint8_t message2[BLOCK_SIZE*2];
    memcpy(message2, message, BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        message2[BLOCK_SIZE+i] = message[i] ^ mac[i];
    }

    cbc_mac(key, message2, mac);

    printf("MAC for two-block message X || (X ? T): ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", mac[i]);
    }
    printf("\n");

    return 0;
}
