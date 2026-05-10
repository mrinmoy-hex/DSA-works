#include <stdio.h>
#include <stdlib.h>


struct circularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct circularQueue *queue) {
    return ((queue->rear + 1)% queue->size) == queue->front;
}

int isEmpty(struct circularQueue *queue) {
    return queue->front == queue->rear;
}

void enqueue(struct circularQueue *queue, int value) {

    if (isFull(queue)) {
        printf("Queue Overflow!\n");
    }

    else {
        printf("Enqued element: %d\n", value);
        queue->rear = (queue->rear + 1) % queue->size;
        queue->arr[queue->rear] = value;
    }
}

int dequeue(struct circularQueue *queue) {

    int dequeuedValue = -1;

    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
    }

    else {
        queue->front = (queue->front + 1) % queue->size;
        dequeuedValue = queue->arr[queue->front];
    }

    return dequeuedValue;
}

void traverseQueue(struct circularQueue *queue) {

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    int i = (queue->front + 1) % queue->size;

    while (i != (queue->rear + 1) % queue->size) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    }

    printf("\n");
}

int main() {
    // Init Queue
    struct circularQueue queue;

    queue.size = 4;
    // Main feature of circular queue
    queue.front = queue.rear = 0;

    queue.arr = (int *) malloc(queue.size * sizeof(int));

    enqueue(&queue, 12);
    enqueue(&queue, 15);
    enqueue(&queue, 4);

    traverseQueue(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    enqueue(&queue, 99);
    enqueue(&queue, 23);

    traverseQueue(&queue);

    free(queue.arr);

    return 0;
}