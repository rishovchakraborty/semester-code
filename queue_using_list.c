#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node* front;
    Node* rear;
}queue;


queue* initQueue(){
    queue* q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
}

int isEmpty(queue* q){
    return q->front==NULL;
}

void enqueue(queue* q,int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    if(isEmpty(q)){
        q->front=newNode;
        q->rear=newNode;
    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("empty queue");
        return -1;
    }
    int item=q->front->data;
    Node* temp= q->front;
    q->front=q->front->next;
    free(temp);
    if(q->front==NULL){
        q->rear==NULL;
    }
    return item;
}