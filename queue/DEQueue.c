#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

void traverseQueue(Queue *queue) {

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }

    printf("\n");
}

void enqueueR(Queue *queue, int val) {

    if (isFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }

    // First element insertion
    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->arr[queue->rear] = val;
}

void enqueueF(Queue *queue, int val) {

    if (queue->front == 0) {
        printf("Front insertion not possible!\n");
        return;
    }

    // First insertion
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    }

    else {
        queue->front--;
    }

    queue->arr[queue->front] = val;
}

int dequeueF(Queue *queue) {

    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int val = queue->arr[queue->front];
    queue->front++;

    return val;
}

int dequeueR(Queue *queue) {

    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int val = queue->arr[queue->rear];
    queue->rear--;

    return val;
}

int main() {

    Queue q;

    q.size = 10;
    q.front = -1;
    q.rear = -1;

    q.arr = (int *) malloc(q.size * sizeof(int));

    enqueueR(&q, 10);
    enqueueR(&q, 20);
    enqueueR(&q, 30);

    traverseQueue(&q);

    enqueueF(&q, 5);

    traverseQueue(&q);

    printf("Dequeued from front: %d\n", dequeueF(&q));
    printf("Dequeued from rear: %d\n", dequeueR(&q));

    traverseQueue(&q);

    free(q.arr);

    return 0;
}