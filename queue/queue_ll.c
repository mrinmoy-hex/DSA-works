#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int isEmpty(Node *front) {
    return front == NULL;
}

void enqueue(Node **front, Node **rear, int val) {

    Node *newNode = (Node *) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }

    newNode->data = val;
    newNode->next = NULL;

    // If queue is empty
    if (*front == NULL) {
        *front = *rear = newNode;
    }

    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(Node **front, Node **rear) {

    if (isEmpty(*front)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    Node *temp = *front;
    int val = temp->data;

    *front = (*front)->next;

    // If queue becomes empty
    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);

    return val;
}

void traversal(Node *ptr) {

    printf("Queue elements:\n");

    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}


int main() {

    Node *front = NULL;
    Node *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    traversal(front);

    printf("Dequeued: %d\n", dequeue(&front, &rear));

    traversal(front);

    return 0;
}