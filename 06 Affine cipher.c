#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000
int freq[26]; // array to store the frequency of each letter in the ciphertext
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int mod_inverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

void count_freq(char *text) {
    int len = strlen(text);
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < len; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            freq[text[i] - 'A']++;
        }
    }
}

int main() {
    char ciphertext[MAX_LENGTH];
    printf("Enter the ciphertext:\n");
    fgets(ciphertext, MAX_LENGTH, stdin);
    int len = strlen(ciphertext);
    if (ciphertext[len - 1] == '\n') {
        ciphertext[len - 1] = '\0'; // remove newline character
    }
    count_freq(ciphertext);
    int max_freq = 0, second_max_freq = 0;
    char max_char, second_max_char;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            second_max_freq = max_freq;
            second_max_char = max_char;
            max_freq = freq[i];
            max_char = 'A' + i;
        } else if (freq[i] > second_max_freq) {
            second_max_freq = freq[i];
            second_max_char = 'A' + i;
        }
    }
    int a, b;
    // assume 'B' is encrypted as 'E' (most common letter in English)
    a = mod_inverse((max_char - 'E' + 26) % 26, 26);
    b = (second_max_char - 'U' + 26) % 26;
    // decrypt the ciphertext using the found parameters
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int x = ciphertext[i] - 'A';
            int y = (a * (x - b + 26) % 26) % 26;
            printf("%c", 'A' + y);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
    return 0;
}
