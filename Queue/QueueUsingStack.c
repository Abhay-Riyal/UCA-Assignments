#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef struct{
    int arr[10000];
    int top;
}stack;

stack* create(){
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    return s;
}

void push(stack* s,int n){
    s->arr[++(s->top)]=n;
}

void pop(stack* s){
    if(s->top==-1){
        return;
    }
    s->top=(s->top)-1;
}

int top(stack* s){
    return (s->arr[s->top]);
}

bool isEmpty(stack* s){
    return s->top==-1;
}


typedef struct {
    stack* s1;
    stack* s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue=(MyQueue*)malloc(sizeof(MyQueue));
    queue->s1=create();
    queue->s2=create();
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    while(!isEmpty(obj->s1)){
        push(obj->s2,top(obj->s1));
        pop(obj->s1);
    }
    push(obj->s2,x);
    while(!isEmpty(obj->s2)){
        push(obj->s1,top(obj->s2));
        pop(obj->s2);
    }
}

int myQueuePop(MyQueue* obj) {
    int temp=top(obj->s1);
    pop(obj->s1);
    return temp;
}

int myQueuePeek(MyQueue* obj) {
    return top(obj->s1);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    if(!obj) return;
    free(obj);
}

int main(){
    //initialise queue struct
    MyQueue* queue=(MyQueue*)malloc(sizeof(MyQueue));
    myQueuePush(queue,1);
    myQueuePush(queue,2);
    //pushing 2 elements 
    // queue should look like 1<->2 with 1 being at front
    assert(myQueuePeek(queue)==1);
    myQueuePop(queue);
    //after popping 2 should be at front
    assert(myQueuePeek(queue)==2);
    myQueuePop(queue);
    //after popping our queue should be empty
    assert(myQueueEmpty(queue)==true);
    myQueueFree(queue);
    
    return 0;
}