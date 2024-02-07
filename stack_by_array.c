#include<stdio.h>
#include<stdlib.h>

#define n 100
typedef struct {
    int top;
    int arr[n];
}stack;

void init(stack *s){
    s->top =-1;
}

int isEmpty(stack* s){
    return s->top==-1;
}
int isFull(stack* s){
    return s->top==(n-1);
}

void push(stack* s, int ele){
    if(isFull(s)){
        printf("stack is full !!");
        return;
    }
    // s[++top]
    s->arr[++s->top]=ele;
    // return;
}

int pop(stack* s){
    if(isEmpty(s)){
        printf("no more ele is theere!!");
        return -1;
    }
    return s->arr[s->top--];
}

int display(stack *s){
    if(isEmpty(s)){
        printf("stack is empty buddy");
    }
    return s->arr[s->top];
}

int main(){
    stack s;
    init(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);

    printf("%d",display(&s)) ;
}