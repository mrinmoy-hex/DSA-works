#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void traversal(struct Node *ptr) {   
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


int isEmpty(struct Node *top) {
    if (top == NULL) {
        return 1;
    }
    return 0;      // This only runs if top is NOT NULL
}

int isFull() {
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    if (p == NULL) return 1;
    free(p);    // Prevent memory leak
    return 0;
}

// Returns the NEW top of the stack
struct Node *push(struct Node *top, int x) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return top; 
    }
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    n->value = x;
    n->next = top;
    return n; // This becomes the new 'top'
}

// Returns the NEW top, and puts the popped value into *val
struct Node* pop(struct Node *top, int *val) {
    if (isEmpty(top)) {
        printf("Stack Underflow!\n");
        return NULL;
    } 
    struct Node *n = top;
    *val = n->value;    // Pass the value back through the pointer
    struct Node *newTop = top->next;
    free(n);
    return newTop;      // Return the new top address
}

int peek(struct Node *top, int pos) {
    if (isEmpty(top)) {
        printf("Empty Stack!\n");
        return -1;
    }
    
    struct Node *ptr = top;

    for (int i = 0; (i < pos-1 && ptr != NULL); i++) {
        ptr = ptr->next;
    }

    if (ptr != NULL) {
        return ptr->value;
    } else {
        return -1;
    }
}

int stackTop(struct Node *top) {
    if (isEmpty(top)) {
        return -1;
    }
    return top->value;
}


int stackBottom(struct Node *top) {
    if (isEmpty(top)) {
        return -1;
    }

    struct Node *ptr = top;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr->value;
}

int main() {
    struct Node *top = NULL;
    int poppedVal;

    // 1. Pushing elements
    // IMPORTANT: You must re-assign 'top' every time!
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    traversal(top);

    // 2. Popping an element
    // We pass the address of 'poppedVal' so the function can fill it
    top = pop(top, &poppedVal);
    printf("Popped element: %d\n", poppedVal);

    traversal(top);

    // 3. Check if empty
    if(isEmpty(top)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack still has elements.\n");
    }

    int peek_val = peek(top, 2);
    printf("Peeked value: %d\n", peek_val);

    for (int i = 1; i < 4; i++) {
        printf("Value at position %d is : %d\n", i, peek(top, i));
    }

    printf("The top value of the stack: %d\n", stackTop(top));

    printf("The last value of the stack: %d\n", stackBottom(top));

    return 0;
}