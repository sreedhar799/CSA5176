#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int extendedEuclidean(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int calculatePrivateKey(int e, int n)
{
    int p, q;
    int phi_n, d;

    for (p = 2; p <= n; p++)
    {
        if (n % p == 0)
            break;
    }

    q = n / p;

    phi_n = (p - 1) * (q - 1);

    int x, y;
    extendedEuclidean(e, phi_n, &x, &y);

    d = x < 0 ? x + phi_n : x;

    return d;
}

int main()
{
    int e = 31;
    int n = 3599;
    int private_key = calculatePrivateKey(e, n);

    printf("Private key: %d\n", private_key);

    return 0;
}
