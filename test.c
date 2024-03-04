// #include <stdio.h>

// int TOH(int n,char s,char t,char d){
//     int count=0;
//     if(n==1){
//         printf("\nMove %d disc from %c to %c\n",n,s,d);
//         count++;
//     }
//     else{
//         count+=TOH(n-1,s,d,t);
//         printf("\nMove %d disc from %c to %c\n",n,s,d);
//         count++;
//         count+=TOH(n-1,t,s,d);
//     }
//     return count;
// }

// int main(){
//     int n=3;
//     int i=TOH(n,'s','t','d');
//     printf("\nNumber of steps=%d",i);
//     return 0;
// }

#include <stdio.h>

struct stack{
    char data[25];
    int top;
};

typedef struct stack STACK;

void push(STACK *S,char item){
    S->data[++(S->top)]=item;
}

void pop(STACK *S){
    S->data[(S->top)--]=0;
}



void check(STACK *S,char seq[]){
    char temp;
    int i,count=0,flag=0;
    if(seq[0]==')')
        flag=1;
    else{
    for(i=0;seq[i]!='\0';i++){
        temp=seq[i];
        if(temp=='(')
            push(S,temp);
        else 
            pop(S);
        if(count<=S->top)
        count=S->top+1;
    }}
    if(S->top==-1 && flag!=1){
        printf("Sequence is right with max value %d\n",count);
    }
    else
    printf("\nSequence is invalid\n");
}

int main(){
    STACK S;
    S.top=-1;
    char seq[25];
    printf("Enter the sequence\n");
    scanf("%s",seq);
    check(&S,seq);
    return 0;
}