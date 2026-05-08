#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    if (isEmpty(sp)) {
        return '\0';
    }
    return sp->arr[sp->top];
}

void push(struct Stack *sp, char value) {
    if (isFull(sp)) {
        printf("Stack Overflow! Cannot push %c\n", value);
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

int prec(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    }

    else if (ch == '+' || ch == '-') {
        return 2;
    }

    else {
        return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char *infixToPostfix(char *infix) {
    // Stack init
    struct Stack *sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;      // Track infix traversal
    int j = 0;      // Track postfix addition

    while (infix[i] != '\0') {

        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }

        else {
            if (isEmpty(sp) || prec(infix[i]) > prec(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp) && prec(stackTop(sp)) >= prec(infix[i])) {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';

    free(sp->arr);
    free(sp);

    return postfix;
}


int main() {

    char *infix = "a-b+t/6";
    printf("Infix expr: %s\n", infix);

    printf("Postfix expr: %s\n", infixToPostfix(infix));

    return 0;
}