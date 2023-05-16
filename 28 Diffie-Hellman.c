#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long long int modExp(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return result;
}

int main() {
    
    long long int p = 23; 
    long long int g = 5; 
    srand(time(NULL));
    long long int xA = rand() % (p-1) + 1; 
    long long int xB = rand() % (p-1) + 1; 

    long long int yA = modExp(g, xA, p); 
    long long int yB = modExp(g, xB, p); 

    long long int sharedKeyA = modExp(yB, xA, p); 
    long long int sharedKeyB = modExp(yA, xB, p); 
    
    printf("Alice's secret number: %lld\n", xA);
    printf("Bob's secret number: %lld\n", xB);
    printf("Alice's public key: %lld\n", yA);
    printf("Bob's public key: %lld\n", yB);
    printf("Alice's shared key: %lld\n", sharedKeyA);
    printf("Bob's shared key: %lld\n", sharedKeyB);

    return 0;
}
