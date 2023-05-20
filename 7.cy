#include <stdio.h>

int main() {
    int freq[26] = {0};
    char c;

    // read the ciphertext and calculate frequency distribution
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        }
    }

    // find the most frequent letters
    int max_i = 0, second_max_i = 0, third_max_i = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[max_i]) {
            third_max_i = second_max_i;
            second_max_i = max_i;
            max_i = i;
        } else if (freq[i] > freq[second_max_i]) {
            third_max_i = second_max_i;
            second_max_i = i;
        } else if (freq[i] > freq[third_max_i]) {
            third_max_i = i;
        }
    }

    // print the mapping
    printf("Mapping:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c -> %c\n", 'A' + i, 'A' + ((i == max_i) ? 'E' : (i == second_max_i) ? 'T' : (i == third_max_i) ? 'A' : ' '));
    }

    return 0;
}
