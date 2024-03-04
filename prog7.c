// #include <stdio.h>
// #define max 10
// int d, s[max], x[max];
// void sub(int p, int k, int r)
// {
//     static int b = 0;
//     int i;
//     x[k] = 1;
//     if (p + s[k] == d)
//     {
//         printf("\n Subset %d { ", ++b);
//         for (i = 1; i <= k; i++)
//         {
//             if (x[i] == 1)
//                 printf("%d\t", s[i]);
//         }
//         printf("}\n");
//     }
//     else if (p + s[k] + s[k + 1] <= d)
//         sub(p + s[k], k + 1, r - s[k]);
//     if ((p + r - s[k] >= d) && (p + s[k + 1] <= d))
//     {
//         x[k] = 0;
//         sub(p, k + 1, r - s[k]);
//     }
// }

// void main()
// {
//     int i, n, sum = 0;
//     printf("Enter no of elements\n");
//     scanf("%d", &n);
//     printf("Enter elements in ascending order\n");
//     for (i = 1; i <= n; i++)
//     {
//         scanf("%d", &s[i]);
//         sum += s[i];
//     }

//     printf("\n Enter max subset value");
//     scanf("%d", &d);
//     if (sum < d || s[1] > d)
//         printf("\n no subset possible");
//     else
//         sub(0, 1, sum);
// }

#include <stdio.h>
#include <stdlib.h>
int d,s[10],x[10];

void sub(int p,int k,int r){
    static int b=0;
    int i;
    x[k]=1;
    if(p+s[k]==d){
        printf("The subset %d is{\t",b++);
        for(i=1;i<=k;i++){
            if(x[i]==1)
            printf("%d\t",s[i]);
        }
        printf("}\n");
    }
    else if(p+s[k]+s[k+1]<=d){
        sub(p+s[k],k+1,r-s[k]);
    }
    if((p+r-s[k]>=d) &&(p+s[k+1]<=d)){
        x[k]=0;
        sub(p,k+1,r-s[k]);
    }
}

int main(){
    int i,n,sum=0;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements in ascending order\n");
    for(i=1;i<=n;i++){
    scanf("%d",&s[i]);
    sum+=s[i];
    }
    printf("Enter the subset max value\n");
    scanf("%d",&d);
    if(sum<d || s[1]>d)
    printf("NO subsets are possible");
    else
    sub(0,1,sum);
}