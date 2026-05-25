#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x) {
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    // in case of empty queue -> set front and rear to temp
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    } 

    rear->next = temp;
    rear = temp;
}

void Dequeue() {
    struct Node *temp = front;

    if (front == NULL)  return;     // empty queue: nothing to dequeue
    // single element in queue
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }

    free(temp);
}

void printQueue() {
    struct Node *ptr = front;

    printf("Queue elements:\n");

    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


int main() {

    Enqueue(5);
    Enqueue(53);
    Enqueue(14);
    Enqueue(78);
    Enqueue(2);
    Enqueue(9);

    printQueue();

    Dequeue();

    printQueue();

    return 0;
}