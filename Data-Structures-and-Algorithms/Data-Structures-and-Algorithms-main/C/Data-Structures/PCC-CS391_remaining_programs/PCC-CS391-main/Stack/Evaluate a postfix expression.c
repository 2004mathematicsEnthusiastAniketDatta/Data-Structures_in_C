#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //for isdigit func

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack.top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack.top == -1;
}

void push(struct Stack* stack, int item) {
    if (stack.top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
    } else {
        stack.data[++stack.top] = item;
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return stack.data[stack.top--];
    }
}

int evaluatePostfix(char* exp) {
    struct Stack stack;
    initialize(&stack);

    int i, operand1, operand2, result;

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0'); // Convert character digit to integer and push to stack
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (exp[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '^':
                    push(&stack, operand1 ^ operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    exit(0);
            }
        }
    }

    result = pop(&stack);
    return result;
}

int main() {
    char postfixExp[MAX_SIZE];

    printf("Enter a valid postfix expression (without giving spaces) : ");
    scanf("%s", postfixExp);

    int result = evaluatePostfix(postfixExp);
    printf("Result: %d\n", result);

    return 0;
}
