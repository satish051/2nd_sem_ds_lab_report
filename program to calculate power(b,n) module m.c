#include <stdio.h>
int power(int b, unsigned int n, int m)
{
    int res = 1;
    b = b % m; // update b if it is more than or equal to m
    while (n > 0)
    {
        /* If n is odd,multiply b with result */
        if (n & 1)
            res = (res * b) % m;

        // n must be even now
        n = n >> 1; // y=y/2
        b = (b * b) % m;
    }
    return res;
}
int main()
{
    int b, n, m, result;

    // Enter the value of b,n,m
    printf("\n Enter the positive integer b:");
    scanf("%d", &b);
    printf("\nEnter positive integer n:");
    scanf("%d", &n);
    printf("\nEnter the positive integer m:");
    scanf("%d", &m);

    // calculate the result
    result = power(b, n, m);
    printf("Modulo power is %d", result);
    return 0;
}
