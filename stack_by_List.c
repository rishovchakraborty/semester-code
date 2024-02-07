#include <stdio.h>
#include <stdlib.h>

// define a node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// define stack
typedef struct
{
    Node *top;
} stack;

Node *CreateNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to initialised a stack
void initStact(stack *s)
{
    s->top = NULL;
}
// chck is stack is empty or not
int isEmpty(stack *s)
{
    return s->top == NULL;
}

// push operation
void push(stack *s, int val)
{
    Node *newNode = CreateNode(val);
    newNode->next = s->top;
    s->top = newNode;
}

// pop operation
int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underlow");
        return;
    }
    Node *temp = s->top;
    s->top = temp->next;
    return temp->data;
}

// getting top ele
int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underlow");
        return;
    }
    return s->top->data;
}

int main(){
    stack s;
    initStact(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);

    printf ("%d",pop(&s));
    printf ("%d",peek(&s));
}
