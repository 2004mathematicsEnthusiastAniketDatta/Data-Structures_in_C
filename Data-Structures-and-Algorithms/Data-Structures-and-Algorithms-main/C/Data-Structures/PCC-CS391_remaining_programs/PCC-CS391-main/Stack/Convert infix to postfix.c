//infix to postfix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
    } else {
        stack->data[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    } else {
        return stack->data[stack->top--];
    }
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* infixExp, char* postfixExp) {
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;
    char ch;

    for (i = 0; infixExp[i] != '\0'; i++) {
        ch = infixExp[i];

        if (isalnum(ch)) {
            postfixExp[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfixExp[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '(' from the stack
        } else {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(stack.data[stack.top])) {
                postfixExp[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfixExp[j++] = pop(&stack);
    }

    postfixExp[j] = '\0';
}

int main() {
    char infixExp[MAX_SIZE];
    char postfixExp[MAX_SIZE];

    printf("Enter a valid infix expression(without giving spaces) : ");
    scanf("%s", infixExp);

    infixToPostfix(infixExp, postfixExp);

    printf("Postfix expression: %s\n", postfixExp);

    return 0;
}
