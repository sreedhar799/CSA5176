#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

int main() {
    char message[100], encrypted[100], decrypted[100], key[ALPHABET_SIZE];
    int i, choice;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter the substitution key: ");
    fgets(key, ALPHABET_SIZE + 1, stdin);

    // Remove newline from key input
    key[strcspn(key, "\n")] = '\0';

    // Encryption
    for (i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted[i] = toupper(key[message[i] - 'A']);
            } else {
                encrypted[i] = tolower(key[message[i] - 'a']);
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
                    decrypted[i] = 'A' + (strchr(key, encrypted[i]) - key);
                } else {
                    decrypted[i] = 'a' + (strchr(key, encrypted[i]) - key);
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
