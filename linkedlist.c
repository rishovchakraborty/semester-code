#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* CreateNode(int data){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertAtBegining(Node**head,int data){
    Node* newNode = CreateNode(data);
    newNode->next= *head;
    *head=newNode;
}

void insertAtEnd(Node**head,int data){
    Node* newNode=CreateNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* temp= *head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtAnyPos(Node**head,int data,int pos){
    if(pos<0){
        printf("invalid pos");
        return;
    }
    if(pos==0){
        insertAtBegining(head,data);
        return;
    }
    Node* newNode=CreateNode(data);
    Node* temp=*head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("invalid pos");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

int findvalue(Node* head,int value){
    int idx=0;
    Node* temp= head;
    while(temp!=NULL){
        if(temp->data==value){
            return idx;
        }
        temp=temp->next;
        idx++;
    }
    return -1;
}

void display(Node* head){
    Node* temp= head;
    while(temp->next!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("null\n");
}

