// Binary integer addition and subtraction and multiplication and division
#include <stdio.h>
int Addition(int a, int b)
{
    int c; // carry
    while (b != 0)
    {
        // find carry and shift it left
        c = (a & b) << 1;
        // find the sum
        a = a ^ b;
        b = c;
    }
    return a;
}

int Subtraction(int a, int b)
{
    int carry;
    // get 2's complement of b and add in a
    b = Addition(~b, 1);

    while (b != 0)
    {
        // find carry and shift it left
        carry = (a & b) << 1;
        // find the sum
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{
    int n1, n2, binAdd, binSub;
    printf("Input first integer value:");
    scanf("%d", &n1);

    printf("Input second integer value:");
    scanf("%d", &n2);

    binAdd = Addition(n1, n2);
    binSub=Subtraction(n1,n2);

    printf("Binary addition : %d\n",binAdd);
    printf("Binary subtraction : %d\n",binSub);
    return 0;
}