#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct stack {
    int data[MAX];
    int top;
}stack;

void initialize(stack* stk)
{
    stk->top = -1;
}

int isempty(stack *stk)
{
    return stk->top == -1;
}

void push(stack* stk, int val)
{
    if(stk->top == MAX-1)
    {
        printf("overflow");
        return;
    }
    stk->data[++stk->top] = val;
}

int pop(stack* stk)
{
    if(stk->top == -1)
    {
        printf("underflow");
    }
    else
    {
        return stk->data[stk->top--];
    }
}

void sort(stack* stk1, stack* stk2)
{
    while(!isempty(stk1))
    {
        int x = pop(stk1);
        while(!isempty(stk2) && stk2->data[stk2->top]<x){
            push(stk1, stk2->data[stk2->top]);
            pop(stk2);
        }
        push(stk2, x);
    }
    
    printf("sorted stack : ");
    
    while(!isempty(stk2))
    {
        printf("%d ", pop(stk2));
    }
}

int main()
{
    stack stk1,stk2;
    initialize(&stk1);
    initialize(&stk2);
    push(&stk1, 1);
    push(&stk1, 3);
    push(&stk1, 2);
    push(&stk1, 9);
    sort(&stk1, &stk2);
    return 0;
}
