#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using the Vigenere cipher
void encrypt(char *message, char *key) {
    int i, j;
    char encrypted[1000] = "";

    // Convert the key to lowercase
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }

    // Encrypt each letter of the message using a separate monoalphabetic substitution cipher
    for (i = 0, j = 0; i < strlen(message); i++, j = (j+1) % strlen(key)) {
        char ch = tolower(message[i]);

        if (isalpha(ch)) {
            // Calculate the shift amount based on the corresponding letter in the key
            int shift = key[j] - 'a';

            // Encrypt the letter using the monoalphabetic substitution cipher
            char encrypted_ch = 'a' + (ch - 'a' + shift) % 26;

            // Append the encrypted letter to the result string
            strncat(encrypted, &encrypted_ch, 1);
        } else {
            // Append non-alphabetic characters to the result string without encryption
            strncat(encrypted, &ch, 1);
        }
    }

    printf("Encrypted message: %s\n", encrypted);
}

int main() {
    char message[1000], key[100];

    // Read in the message and key from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, 1000, stdin);
    printf("Enter the key: ");
    fgets(key, 100, stdin);

    // Remove the newline character from the end of the message and key
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypt the message using the Vigenere cipher
    encrypt(message, key);

    return 0;
}
