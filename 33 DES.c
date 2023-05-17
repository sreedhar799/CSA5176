#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void xor_cipher(char *plaintext, char *key, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
}

int main() {
    char plaintext[MAX_LENGTH];
    char key[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; 
    
    printf("Enter key: ");
    fgets(key, MAX_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; 
    
    xor_cipher(plaintext, key, ciphertext);
    
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}
