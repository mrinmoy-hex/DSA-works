#include <stdio.h>
#include <stdlib.h>

// Queue structure
struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *queue) {
    return queue->rear == queue->size - 1;
}

int isEmpty(struct Queue *queue) {
    return queue->front == queue->rear;
}

void enqueue(struct Queue *queue, int value) {

    if (isFull(queue)) {
        printf("Queue Overflow!\n");
    }

    else {
        queue->rear++;
        queue->arr[queue->rear] = value;
    }
}

int dequeue(struct Queue *queue) {

    int dequeuedValue = -1;

    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
    }

    else {
        queue->front++;
        dequeuedValue = queue->arr[queue->front];
    }

    return dequeuedValue;
}

void traverseQueue(struct Queue *queue) {

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = queue->front + 1; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }

    printf("\n");
}

int main() {
    // Init Queue
    struct Queue queue;

    queue.size = 100;
    queue.front = -1;
    queue.rear = -1;

    queue.arr = (int *) malloc(queue.size * sizeof(int));

    enqueue(&queue, 12);
    enqueue(&queue, 15);
    enqueue(&queue, 4);
    enqueue(&queue, 62);
    enqueue(&queue, 92);

    traverseQueue(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    traverseQueue(&queue);

    free(queue.arr);

    return 0;
}