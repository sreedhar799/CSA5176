#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8 
void ecb_encrypt(char* plaintext, char* key, int len)
{
    int i, j;
    char block[BLOCK_SIZE];
    char ciphertext[len];

    int padding = BLOCK_SIZE - (len % BLOCK_SIZE);
    if (padding > 0 && padding < BLOCK_SIZE) {
        memset(plaintext + len, 0, padding);
        len += padding;
    }

    for (i = 0; i < len; i += BLOCK_SIZE) {
        memcpy(block, plaintext + i, BLOCK_SIZE);
        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= key[j];
        }
        memcpy(ciphertext + i, block, BLOCK_SIZE);
    }

    printf("Ciphertext: %s\n", ciphertext);
}

int main()
{
    char plaintext[] = "This is a test message.";
    char key[] = "secretke";

    ecb_encrypt(plaintext, key, strlen(plaintext));

    return 0;
}
