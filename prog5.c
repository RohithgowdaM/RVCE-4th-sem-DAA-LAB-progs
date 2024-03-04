// #include <stdio.h>
// #include <stdlib.h>
// int n, W, w[10], V[10], v[10][10], x[10] = {0};

// int max(int a, int b)
// {
//     return a > b ? a : b;
// }

// void hello()
// {
//     int i, j;
//     i = n;
//     j = W;
//     while (i != 0 || j != 0)
//     {
//         if (v[i][j] != v[i - 1][j])
//         {
//             x[i] = 1;
//             j = j - w[i];
//         }
//         i = i - 1;
//     }
// }

// int main()
// {
//     int i, j;
//     printf("Enter the number of weights\n");
//     scanf("%d", &n);
//     printf("Enter the weights\n");
//     for (i = 1; i <= n; i++)
//         scanf("%d", &w[i]);
//     printf("Enter the values of the weights\n");
//     for (i = 1; i <= n; i++)
//         scanf("%d", &V[i]);
//     printf("\nEnter the knapsack capacity\n");
//     scanf("%d", &W);
//     for (i = 0; i <= n; i++)
//     {
//         for (j = 0; j <= W; j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 v[i][j] = 0;
//             }
//             else if ((j - w[i]) < 0)
//                 v[i][j] = v[i - 1][j];
//             else
//             {
//                 v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + V[i]);
//             }
//         }
//     }
//     printf("\nThe max profit is %d \t", v[n][W]);
//     hello();
//     printf("\n-------------\n");
//     for (i = 1; i <= n; i++)
//     {
//         if (x[i] == 1)
//             printf("\n%d is present", i);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    return a>b?a:b;
}

int v[10][10],w[10],W,V[10],X[10]={0},n;

void hello(){
    int i,j;
    i=n;
    j=W;
    while(i!=0 || j!=0){
        if(v[i][j]!=v[i-1][j]){
            X[i]=1;
            j=j-w[i];
        }
        i=i-1;
    }
}

int main(){
    int i,j;
    printf("Enter the number of weights\n");
    scanf("%d",&n);
    printf("Enter the weights\n");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    printf("Enter the values of the weights\n");
    for(i=1;i<=n;i++)
    scanf("%d",&V[i]);
    printf("Enter the knapsack capacity\n");
    scanf("%d",&W);
    for(i=0;i<n+1;i++){
        for(j=0;j<W+1;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }
            else if((j-w[i])<0){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+V[i]);
            }
        }
    }
    printf("The maximum value obtained is %d\n",v[n][W]);
    hello();
    for(i=1;i<=n;i++){
        if(X[i]==1)
        printf("Object %d is included\n",i);
    }
    return 0;
}