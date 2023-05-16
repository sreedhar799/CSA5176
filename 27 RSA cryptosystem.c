#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate modular exponentiation
long long int modExp(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
  
    long long int p = 101; 
    long long int q = 103; 
    long long int n = p * q; 
    long long int phi = (p-1) * (q-1); 
    long long int e = 65537; 
    long long int d = 0; 

    long long int k = 1;
    while ((k * phi + 1) % e != 0) {
        k++;
    }
    d = (k * phi + 1) / e;

    long long int ciphertext[100] = {  }; 
    int ciphertextLength = 50; 
    char message[100] = ""; 
    for (int i = 0; i < ciphertextLength; i++) {
        long long int plaintext = modExp(ciphertext[i], d, n);
        message[i] = (char) ((int) plaintext % 26 + 'A');
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}
