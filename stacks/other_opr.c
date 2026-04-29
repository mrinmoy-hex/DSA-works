#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr) {
    return (ptr->top == -1); // Simplified return
}

int isFull(struct Stack *ptr) {
    return (ptr->top == ptr->size - 1);
}

void push(struct Stack *sp, int value) {
    if (isFull(sp)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

int pop(struct Stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack Underflow!\n");
        return -1;  // Return a sentinel value to indicate error
    } else {
        return sp->arr[sp->top--];
    }
}

int peek(struct Stack *sp, int i) {
    // Logic: The i-th position from the top is (top - i + 1)
    int arrayIndex = sp->top - i + 1;

    if (arrayIndex < 0) {
        printf("Not a valid position in the stack\n");
        return -1;
    } else {
        return sp->arr[arrayIndex];
    }
}

void display(struct Stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack is empty. Nothing to show.\n");
    } else {
        printf("Stack elements (Top to Bottom): \n");
        for (int i = sp->top; i >= 0; i--) {
            int position = sp->top - i + 1;
            printf("Position %d (Index %d) -> %d\n", position, i, sp->arr[i]);
        }
        printf("----------\n");
    }
}

int stackTop(struct Stack *sp) {
    return sp->arr[sp->top];
}

int stackBottom(struct Stack *sp) {
    return sp->arr[0];
}

int main() {
    struct Stack *s = (struct Stack*) malloc(sizeof(struct Stack));
    
    // Check if struct allocation succeeded
    if (s == NULL) return 1;

    s->size = 20;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    if (s->arr == NULL) { free(s); return 1; }

    // Adding some data
    push(s, 2);
    push(s, 33);
    push(s, 44);
    push(s, 5);
    push(s, 17);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    // See the stack
    display(s);

    printf("Top value of the stack: %d\n", stackTop(s));
    printf("Bottom value of the stack: %d\n", stackBottom(s));


    // CLEANUP
    free(s->arr);
    free(s);

    return 0;
}