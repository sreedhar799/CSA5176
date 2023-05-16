#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    char message[100], encrypted[100], decrypted[100];
    int key, i, choice;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    // Encryption
    for (i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted[i] = ((message[i] - 'A' + key) % ALPHABET_SIZE) + 'A';
            } else {
                encrypted[i] = ((message[i] - 'a' + key) % ALPHABET_SIZE) + 'a';
            }
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';

    printf("Encrypted message: %s\n", encrypted);

    // Decryption
    printf("Do you want to decrypt the message? (1 for yes, 0 for no): ");
    scanf("%d", &choice);

    if (choice) {
        for (i = 0; encrypted[i] != '\0'; ++i) {
            if (isalpha(encrypted[i])) {
                if (isupper(encrypted[i])) {
                    decrypted[i] = ((encrypted[i] - 'A' + ALPHABET_SIZE - key) % ALPHABET_SIZE) + 'A';
                } else {
                    decrypted[i] = ((encrypted[i] - 'a' + ALPHABET_SIZE - key) % ALPHABET_SIZE) + 'a';
                }
            } else {
                decrypted[i] = encrypted[i];
            }
        }
        decrypted[i] = '\0';

        printf("Decrypted message: %s\n", decrypted);
    }

    return 0;
}
