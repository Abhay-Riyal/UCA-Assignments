#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int arr[10000];
    int top;
} stack;

stack* createStack(){
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    return s;
}

void push(stack* s,int data){
    s->arr[++(s->top)]=data;
}

void pop(stack* s){
    if(s->top==-1) return;
    --(s->top);
}

int top(stack* s){
    return s->arr[s->top];
}

bool isEmpty(stack* s){
    return s->top==-1;
}

int main() {
    int testCase;
    scanf("%d",&testCase);
    while(testCase--){
        char arr[10000][100];
        int index=0;
        scanf("%s",arr[index++]);
        while(arr[index-1][0]!='?'){
            scanf("%s",arr[index++]);
        }
        
        stack* st=createStack();
        int start=0;
        while(arr[start][0]!='?'){
            if(arr[start][0]=='+'){
                int operand2=top(st);
                pop(st);
                int operand1=top(st);
                pop(st);
                push(st,(operand1+operand2));
            }else if(arr[start][0]=='-'){
                int operand2=top(st);
                pop(st);
                int operand1=top(st);
                pop(st);
                push(st,(operand1-operand2));
            }else if(arr[start][0]=='*'){
                int operand2=top(st);
                pop(st);
                int operand1=top(st);
                pop(st);
                push(st,(operand1*operand2));
            }else if(arr[start][0]=='/'){
                int operand2=top(st);
                pop(st);
                int operand1=top(st);
                pop(st);
                push(st,(operand1/operand2));
            }else{
                int current=atoi(arr[start]);
                push(st,current);
            }
             start++;          
        }
        printf("%d\n",top(st));
        pop(st);

    }

    return 0;
}
