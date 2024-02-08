#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(CircularQueue *queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->rear == (queue->front - 1) % (MAX_SIZE - 1));
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *queue) {
    return queue->front == -1;
}

// Function to add an element to the queue
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->items[queue->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Function to remove an element from the queue
int dequeue(CircularQueue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return item;
}

// Function to display the queue
void display(CircularQueue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front -> ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d, ", queue->items[i]);
    }
    printf("%d -> Rear\n", queue->items[i]);
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    display(&queue);

    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));

    display(&queue);

    enqueue(&queue, 50);
    enqueue(&queue, 60);

    display(&queue);

    return 0;
}
