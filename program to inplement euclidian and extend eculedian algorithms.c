#include <stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int gcdExtended(int a, int b, int *x, int *y)
{
    int x1, y1, gcd;
    // base case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    x1, y1; // to store the results of recursive calls
    gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x1 and y1 using results of recursive calls
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main()
{
    int a = 100, b = 150, c;
    c = gcd(a, b);
    printf("the GCD of %d and %d = %d\n", a, b, c);
    a = 90, b = 2;
    c = gcd(a, b);
    printf("the GCD of %d and %d = %d\n", a, b, c);
    int x, y;
    int g = gcdExtended(a, b, &x, &y);
    printf("gcd(%d,%d)=%d", a, b, g);

    return 0;
}
