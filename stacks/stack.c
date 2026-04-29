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

int main() {
    struct Stack *s = (struct Stack*) malloc(sizeof(struct Stack));
    
    // Check if struct allocation succeeded
    if (s == NULL) return 1;

    s->size = 80;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    // Check if array allocation succeeded
    if (s->arr == NULL) {
        free(s); // Clean up the struct before exiting
        return 1;
    }

    // Push element manually (usually you'd use a push function)
    if (!isFull(s)) {
        s->top++;
        s->arr[s->top] = 7;
    }

    if (isEmpty(s)) {
        printf("The stack is empty\n");
    } else {
        printf("The stack is not empty\n");
    }

    // CLEANUP: Essential to prevent memory leaks
    free(s->arr);
    free(s);

    return 0; 
}