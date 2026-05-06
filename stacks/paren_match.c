#include <stdio.h>
#include <string.h>
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

char stackTop(struct Stack *sp) {
    return sp->arr[sp->top];
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

int match(char x, char y) {
    if (x == '{' && y == '}') {
        return 1;
    }
    if (x == '(' && y == ')') {
        return 1;
    }
    if (x == '[' && y == ']') {
        return 1;
    }

    return 0;
}

int parenMatch(char *expr) {
    struct Stack *ptr = (struct Stack *) malloc(sizeof(struct Stack));
    ptr->size = strlen(expr);
    ptr->top = -1;

    ptr->arr = (char *) malloc(ptr->size * sizeof(char));
    char popped_char;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(ptr, expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if(isEmpty(ptr)) {
                free(ptr->arr);
                free(ptr);
                return 0;
            }
            popped_char = pop(ptr);
            if (!match(popped_char, expr[i])) {
                return 0;
            }
        }
    }

    int result = isEmpty(ptr);

    free(ptr->arr);
    free(ptr);

    return result;
}

int main() {
    char buffer[100];
    char expression[100];
    int j = 0;          // Writer index for expression array

    
    printf("Enter expression: "); 
    fgets(buffer, sizeof(buffer), stdin);
    int size_buffer = (int) strlen(buffer);


    for (int i = 0; i < size_buffer; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i != '\t']) {
            expression[j] = buffer[i];
            j++;
        }
    }
    expression[j] = '\0'; // Manually add the null terminator at the end

    // printf("Cleaned expression: %s\n", expression);

    if (parenMatch(expression)) {
        printf("The parenthesis is matching.\n");
    }
    else {
        printf("The parenthesis is not matching.\n");
    }
    
    return 0;
}