#include <stdio.h>
#include <stdlib.h>
#define s 100

struct stack{
int arr[s];
int top;
};
struct stack* createstack()
{
    struct stack* newstack=(struct stack*)malloc(sizeof(struct stack));
    newstack->top=-1;
    return newstack;
}

int isEmpty(struct stack *new){
    return new->top=-1;
}
int isFull(struct stack *stacks){
return stacks->top=s-1;
}
void push(struct stack *stack,push){
if(isFull(stack))
{
    printf("Stack Overflow");
    return;
}
 stack->arr[++stack->top]=data;
}
int pop(struct stack *sk){
if(isEmpty(sk)){
    printf("Stack underflow");
    return -1;
}
   sk->arr[sk->top--];
}
int peek(struct stack * stackss){
if(isEmpty(stackss)){
    printf("Stack underflow");
    return -1;
}
   return sk->arr[sk->top];
}
int delete(struct stack *stackji){
free(stackji)
}
int main()
{

    printf("Hello world!\n");
    return 0;
}
