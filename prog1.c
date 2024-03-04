// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 1024
// int count = 0;
// void merge(int A[], int l, int m, int r)
// {
//     int i = l;
//     int j = m + 1;
//     int k = l;
//     int B[SIZE];
//     while (i <= m && j <= r)
//     {
//         if (A[i] < A[j])
//         {
//             B[k++] = A[i++];
//             count++;
//         }
//         else
//         {
//             B[k++] = A[j++];
//             count++;
//         }
//     }
//     while (i <= m)
//     {
//         B[k++] = A[i++];
//         count++;
//     }
//     while (j <= r)
//     {
//         B[k++] = A[j++];
//         count++;
//     }
//     for (i = l; i <= r; i++)
//     {
//         A[i] = B[i];
//     }
// }

// void mergesort(int A[SIZE], int l, int r)
// {
//     if (l < r)
//     {
//         int m = (l + r) / 2;
//         mergesort(A, l, m);
//         mergesort(A, m + 1, r);
//         merge(A, l, m, r);
//     }
// }

// int main()
// {
//     int a[SIZE], X[SIZE], Y[SIZE], Z[SIZE];
//     int n, i, c1, c2, c3;
//     printf("Enter the size of the array\n");
//     scanf("%d", &n);
//     printf("Enter the elements\n");
//     for (i = 0; i < n; i++)
//         scanf("%d", &a[i]);
//     mergesort(a, 0, n - 1);
//     printf("The sorted elements are\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);
//     printf("\nThe basic is excecuted %d times\n", count);
//     count = 0;
//     printf("\nSIZE\t ASC \t DESC \t RAND\n");
//     for (i = 16; i <= SIZE; i = i * 2)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             X[j] = j;
//             Y[j] = i - j - 1;
//             Z[j] = rand() % i + 3;
//         }
//         count = 0;
//         mergesort(X, 0, i - 1);
//         c1 = count;
//         count = 0;
//         mergesort(Y, 0, i - 1);
//         c2 = count;
//         count = 0;
//         mergesort(Z, 0, i - 1);
//         c3 = count;
//         count = 0;
//         printf("%d \t %d \t %d\t %d\n", i, c1, c2, c3);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024
int count = 0;

void merge(int a[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = i;
    int b[SIZE];
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
            count++;
        }
        else
        {
            b[k++] = a[j++];
            count++;
        }
    }
    while (i <= m)
    {
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        b[k++] = a[j++];
    }
    for (i = l; i <= r; i++)
    {
        a[i] = b[i];
    }
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
    int n, a[SIZE], i, x[SIZE], y[SIZE], z[SIZE], c1, c2, c3, j;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elemnets\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("Sorted elemnets are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("Number of iterations done is %d\n", count);
    printf("\nSIZE \t ASC \t DESC \t Rand \n");
    for (i = 16; i <= SIZE; i = i * 2)
    {
        for (j = 0; j < i; j++)
        {
            x[j] = j;
            y[j] = i - j - 1;
            z[j] = rand() % i;
        }
        count = 0;
        mergesort(x, 0, i - 1);
        c1 = count;
        count = 0;
        mergesort(y, 0, i - 1);
        c2 = count;
        count = 0;
        mergesort(z, 0, i - 1);
        c3 = count;
        printf("%d \t %d\t %d\t %d\n", i, c1, c2, c3);
    }
    return 0;
}