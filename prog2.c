// #include <stdio.h>

// int topo[10], k;

// void dfs(int a[10][10], int n, int v[], int source)
// {
//     int i;
//     v[source] = 1;
//     for (i = 1; i <= n; i++)
//     {
//         if (v[i] == 0 && a[source][i] == 1)
//             dfs(a, n, v, i);
//     }
//     topo[k++] = source;
// }

// int main()
// {
//     int n, i, j, a[10][10], v[10];
//     printf("\nEnter the number of nodes\n");
//     scanf("%d", &n);
//     printf("Enter the adjacency matrix\n");
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= n; j++)
//         {
//             scanf("%d", &a[i][j]);
//         }
//     }
//     for (i = 1; i <= n; i++)
//         v[i] = 0;
//     for (i = 1; i < n; i++)
//     {
//         if (v[i] == 0)
//             dfs(a, n, v, i);
//     }
//     for (i = n - 1; i >= 0; i--)
//         printf("%d\t", topo[i]);
// }

#include <stdio.h>
#include <stdlib.h>
int k = 1, res[10];

void topo(int a[10][10], int v[10], int n, int source)
{
    v[source] = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 0 && a[source][i] == 1)
            topo(a, v, n, i);
    }
    res[k++] = source;
}

int main()
{
    int a[10][10], n, i, j, v[10];
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
    {
        v[i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            topo(a, v, n, i);
    }
    for (i = n; i > 0; i--)
        printf("%d\t", res[i]);
}