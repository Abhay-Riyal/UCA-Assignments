#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int currentSize;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue=(MyCircularQueue* )malloc(sizeof(MyCircularQueue));
    queue->arr=(int*)malloc(k*sizeof(int));
    queue->front=0;
    queue->rear=-1;
    queue->size=k;
    queue->currentSize=0;
    return queue;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->currentSize==0) ? true : false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->currentSize==obj->size;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)) return false;
    obj->rear=(obj->rear+1) % obj->size;
    obj->arr[obj->rear]=value;
    ++obj->currentSize;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return false;
    obj->front=(obj->front+1) % obj->size;
    --obj->currentSize;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj) return;
    free(obj);
}


int main(){
    MyCircularQueue* queue=myCircularQueueCreate(5);
    myCircularQueueEnQueue(queue,1);
    myCircularQueueEnQueue(queue,2);
    myCircularQueueEnQueue(queue,3);
    myCircularQueueEnQueue(queue,4);
    myCircularQueueEnQueue(queue,5);

    printf("%d\n",myCircularQueueFront(queue));
    printf("%d\n",myCircularQueueRear(queue));

    myCircularQueueDeQueue(queue);
    myCircularQueueDeQueue(queue);

    printf("%d\n",myCircularQueueFront(queue));
    printf("%d\n",myCircularQueueRear(queue));

    myCircularQueueFree(queue);

    return 0;
}