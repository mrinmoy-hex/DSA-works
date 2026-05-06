// This program has some issues
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr) {
    return (ptr->top == -1); // Simplified return
}

int isFull(struct Stack *ptr) {
    return (ptr->top == ptr->size - 1);
}

void push(struct Stack *sp, char value) {
    if (isFull(sp)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

char pop(struct Stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack Underflow!\n");
        return -1;  // Return a sentinel value to indicate error
    } else {
        return sp->arr[sp->top--];
    }
}

int parenMatch(char *exp) {
    // Create and initialize the stack
    struct Stack *sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    // Allocate memory for the internal memory
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') {
            push(sp, '(');
        }
        else if(exp[i] == ')') {
            if(isEmpty(sp)) {
                free(sp->arr);
                free(sp);
                return 0;       // Unbalanced
            }
            pop(sp);
        }
    }

    int result = isEmpty(sp);   // Returns 1 if balanced, 0 if not

    // Clean up memory
    free(sp->arr);
    free(sp);

    return result;
}

int main() {
    char *exp = "8 * (9";

    if (parenMatch(exp)) {
        printf("The parenthesis is matching.\n");
    } else {
        printf("The parenthesis is not matching\n");
    }

    return 0; 
}