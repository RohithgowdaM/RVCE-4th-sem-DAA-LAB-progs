#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024

void merge(int a[], int l, int m, int r)
{
    int i, j, k, b[SIZE];
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
            b[k++] = a[j++];
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = b[i];
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n, a[SIZE], i, j, flag = 0;
    printf("\nEnter the number of elements\n");
    scanf("%d", &n);
    printf("\nEnter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            printf("\nThe array is not unique");
            flag = 1;
        }
    }
    if (flag = 0)
        printf("\nThe array is unique");
}