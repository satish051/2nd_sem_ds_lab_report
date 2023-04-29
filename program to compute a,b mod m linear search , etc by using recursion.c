#include<stdio.h>
int power(int b,int n)
{
    if (n==0)
    return 1;
    else
    return (b*power(b,n-1));
}
int main()
{
    int b,n,result;
    printf("Enter base number: ");
    scanf("%d",&b);

    printf("Enter power number(Positive integer):");
    scanf("%d",&n);

    result = power(b,n);

    printf("%d ^ %d = %d",b,n,result);
    return 0;
}