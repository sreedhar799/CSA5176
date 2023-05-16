#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

int find_inverse(int a) {
    int i;
    for (i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            return i;
        }
    }
    return -1;
}

int encrypt(int a, int b, char p) {
    if (isalpha(p)) {
        int c = toupper(p) - 'A';
        return (a * c + b) % 26;
    } else {
        return p;
    }
}

int decrypt(int a, int b, char c) {
    if (isalpha(c)) {
        int inv_a = find_inverse(a);
        int p = (inv_a * ((c - 'A' - b + 26) % 26)) % 26;
        return p;
    } else {
        return c;
    }
}

int main() {
    int a, b;
    char plaintext[100], ciphertext[100], decrypted[100];
    printf("Enter value of a: ");
    scanf("%d", &a);
    if (gcd(a, 26) != 1) {
        printf("Invalid value of a. Choose a value that is coprime with 26.\n");
        exit(1);
    }
    printf("Enter value of b: ");
    scanf("%d", &b);
    printf("Enter plaintext: ");
    scanf(" %[^\n]", plaintext);

    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encrypt(a, b, plaintext[i]);
    }
    ciphertext[i] = '\0';
    printf("Ciphertext: %s\n", ciphertext);

    for (i = 0; ciphertext[i] != '\0'; i++) {
        decrypted[i] = decrypt(a, b, ciphertext[i]);
    }
    decrypted[i] = '\0';
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
