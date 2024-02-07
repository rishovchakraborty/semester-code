#include<stdio.h>
#include<stdlib.h>

#define n 100

// defining  structure for queue
typedef struct{
    int arr[n];
    int rear;
    int front;
}queue;

queue* initQueue(){
    queue* q=(queue*)malloc(sizeof(queue));
    q->rear=-1;
    q->front=-1;
 return q;
}

int isEmpty(queue* q){
    return q->front==-1;
}

int isFull(queue* q){
    return q->rear==(n-1);
}

void enqueue(queue* q,int data){
    if(isFull(q)){
        printf("full hain bhai!");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear++;
    q->arr[q->rear]=data;
}

int dequeue(queue* q){
    if(isEmpty(q)){
        printf("kuch bacha hi nhi");
        return -1;
    }
    int item=q->arr[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front++;
    }
    return item;
}

int main(){
    queue* q=initQueue();
    enqueue(q,10);
    enqueue(q,15);
    printf("%d",dequeue(q));
}