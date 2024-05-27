#include<stdio.h>
#include<stdlib.h>
typedef struct stacknode{
	int data;
	struct stacknode* next;
}stacknode;

typedef struct stack{
	stacknode* top;
}stack;
stacknode* createnode(int x)
{
	stacknode* newnode=(stacknode*)malloc(sizeof(stacknode));
	if (newnode==NULL){
		printf("\nAllotment failed");
		exit(1);}
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
void init(stack* s)
{
	s->top=NULL;
}
int isEmpty(stack* s)
{
	return s->top==NULL;
}
void push(stack* s,int data)
{
	stacknode* newnode=createnode(data);
	newnode->next=s->top;
	s->top=newnode;
}
stacknode* pop(stack* s)
{
	if(isEmpty(s))
	{
		printf("\nUnderflow");
		exit(1);
	}
	stacknode* popnode=s->top;
	s->top=s->top->next;
	return popnode;
}
void display(stack* s)
{
	stacknode* curr=s->top;
	while(curr!=NULL)
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}
	printf("\n");
}
void reverse(stack* s)
{
	stacknode* prev;
	stacknode* curr;
	stacknode* succ;
	prev=curr=s->top;
	curr=curr->next;
	prev->next=NULL;
	while(curr!=NULL)
	{
		succ=curr->next;
		curr->next=prev;
		prev=curr;
		curr=succ;
	}
	s->top=prev;
}
void main()
{
	stack stk;
	init(&stk);
	push(&stk,1);
	push(&stk,2);
	push(&stk,3);
	push(&stk,4);
	
	printf("\nOriginal stack:");
	display(&stk);
	
	reverse(&stk);
	printf("\nNew stack:");
	display(&stk);
}
