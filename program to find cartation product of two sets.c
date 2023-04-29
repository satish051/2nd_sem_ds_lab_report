#include <stdio.h>
int main()
{
    int a[10], b[10], c[10], i, j, k;
    printf("Enter the elements in set A: ");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    printf("\nEnter elements in set B: ");
    for (j = 0; j < 5; j++)
        scanf("%d", &b[j]);
    printf("\nCartesian product: {");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("(%d,%d)", a[i], b[j]);
            if (i !=4 && j != 4)
                printf(",");
        }
    }
    printf("}");
    return 0;
}