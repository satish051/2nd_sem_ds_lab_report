#include <stdio.h>
int LinSearch(int a[], int l, int r, int key)
{
    if (r < l)
        return -1;
    if (a[l] == key)
        return l;
    return LinSearch(a, l + 1, r, key);
}
int main()
{
    int n;
    int key;
    printf("Enter the size of the list:");
    scanf("%d", &n);
    int a[n], i;
    printf("\nEnter the elements of the list:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key to be searched:");
    scanf("%d", &key);
    int index = LinSearch(a, 0, n - 1, key);
    if (index != -1)
        printf("Element %d is present at index %d", key, index);
    else
        printf("Element %d is not present", key);
    return 0;
}
