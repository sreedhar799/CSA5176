#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

#define ALPHABET_SIZE 26

#define MESSAGE_SIZE 1024

#define PLAINTEXT_SIZE 1024

#define MAX_PLAINTEXTS 10

void count_letters(char* message, int* freq) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            freq[message[i] - 'a']++;
        }
    }
}

int find_most_common_letter(int* freq) {
    int i, max_freq = 0, max_letter = 0;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_letter = i;
        }
    }
    return max_letter;
}
void decrypt(char* message, char* key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = key[message[i] - 'a'];
        }
    }
}

int main() {
    char message[MESSAGE_SIZE];
    char plaintext[PLAINTEXT_SIZE];
    char key[ALPHABET_SIZE];
    int freq[ALPHABET_SIZE] = {0};
    int i, j, k;
    int num_possible_plaintexts = 0;
    int max_freq, max_letter;

    printf("Enter the encrypted message: ");
    fgets(message, MESSAGE_SIZE, stdin);

    message[strlen(message) - 1] = '\0';

    count_letters(message, freq);

    max_letter = find_most_common_letter(freq);

    for (i = 0; i < ALPHABET_SIZE; i++) {
        for (j = 0; j < ALPHABET_SIZE; j++) {
            for (k = 0; k < ALPHABET_SIZE; k++) {
               
                key[max_letter] = ALPHABET[i];
                key[(max_letter + 1) % ALPHABET_SIZE] = ALPHABET[j];
                key[(max_letter + 2) % ALPHABET_SIZE] = ALPHABET[k];
                for (int l = 0; l < ALPHABET_SIZE; l++) {
                    if (l != max_letter && l != (max_letter + 1) % ALPHABET_SIZE && l != (max_letter + 2) % ALPHABET_SIZE) {
                        key[l] = ALPHABET[l];
                    }
                }

                strcpy(plaintext, message);
                decrypt(plaintext, key);

                count_letters(plaintext, freq);

                max_letter = find_most_common_letter(freq);

                int is_plaintext = 1;
                for (int l = 0; l < strlen(plaintext); l++) {
                    if (plaintext[l] < 'a' || plaintext[l] > 'z') {
                        is_plaintext = 0;
                        break;
                    }
                }
                if (is_plaintext) {
                    printf("%s\n", plaintext);
                    num_possible_plaintexts++;
                }

                if (num_possible_plaintexts == MAX_PLAINTEXTS) {
                    return 0;
                }
            }
        }
    }
    if (num_possible_plaintexts == 0) {
        printf("No possible plaintexts found.\n");
    }

    return 0;
}
