#include <stdio.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modular_pow(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    int p, q, n, totient_n, e, d, plaintext, ciphertext;

    p = 61;
    q = 53;

    n = p * q;

    totient_n = (p - 1) * (q - 1);

    e = 17;
    while (gcd(e, totient_n) != 1) {
        e++;
    }

    d = 0;
    while ((d * e) % totient_n != 1) {
        d++;
    }

    plaintext = 123;
    ciphertext = modular_pow(plaintext, e, n);
    printf("Plaintext: %d\nCiphertext: %d\n", plaintext, ciphertext);

    plaintext = modular_pow(ciphertext, d, n);
    printf("Decrypted Plaintext: %d\n", plaintext);

    return 0;
}



