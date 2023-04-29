#include <stdio.h>
#include <math.h>
int main()
{
    float num;
    printf("Enter a floating number: ");
    scanf("%f", &num);
    float c=ceil(num);
    float f=floor(num);
    printf("Floor: %f\nCeiling:%f",f,c);
    return 0;
}
