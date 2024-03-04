// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define SIZE 255
// int Table[SIZE];
// void shiftable(char P[])
// {
//     int i, m;
//     m = strlen(P);
//     for (i = 0; i < SIZE; i++)
//         Table[i] = m;
//     for (i = 0; i < m - 1; i++)
//         Table[P[i]] = m - i - 1;
// }

// int horsepool(char T[], char P[])
// {
//     int i, j, k, m, n;
//     n = strlen(T);
//     m = strlen(P);
//     i = m - 1;
//     while (i <= n - 1)
//     {
//         k = 0;
//         while (k < m && P[m - 1 - k] == T[i - k])
//             k++;
//         if (k == m)
//             return i - m + 1;
//         else
//             i = i + Table[T[i]];
//     }
//     return -1;
// }

// int main()
// {
//     char T[SIZE], P[SIZE], value;
//     printf("Enter the text\n");
//     gets(T);
//     printf("Enter the pattern\n");
//     gets(P);
//     shiftable(P);
//     value = horsepool(T, P);
//     if (value == -1)
//         printf("String not found\n");
//     else
//         printf("\nThe strinf is found at %d", value + 1);
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256
int Table[SIZE];

void shiftTable(char P[]){
    int i,m;
    m=strlen(P);
    for(i=0;i<SIZE;i++){
        Table[i]=m;
    }
    for(i=0;i<m-1;i++)
    Table[P[i]]=m-1-i;
}
int horsepool(char T[],char P[]){
    shiftTable(P);
    int m,n,i,k=0;
    n=strlen(T);
    m=strlen(P);
    i=m-1;
    while(i<=n-1){
        k=0;
        while(k<m && T[i-k]==P[m-k-1])
        k=k+1;
        if(k==m)
        return i-m+1;
        else
        i=i+Table[T[i]];
    }
    return -1;

}

int main(){
    char T[100],P[100];
    printf("Enter the text\n");
    gets(T);
    printf("Enter the pattern to be found\n");
    gets(P);
    int value=horsepool(T,P);
    if(value==-1){
        printf("\nThe pattern is not found\n");
    }
    else{
        printf("\nPattern found at %d position",value+1);
    }
    return 0;
}