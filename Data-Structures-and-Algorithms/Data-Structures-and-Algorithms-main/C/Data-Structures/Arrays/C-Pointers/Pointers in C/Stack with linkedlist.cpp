# include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct stack{
	int data;
	struct stack *next;
}node;

node *stack=NULL;

node *createNode(){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}
void push(){
	printf("Data:");
	node *temp=createNode();
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->next=stack;
	stack=temp;
	printf("Value pushed inthe stack: \n",temp->data);
}

void pop(){
	node *t=stack;
	node*del;
	if(stack==NULL){
		printf("\n\t Stack is Empty;Stack underflow \n");
	}
	
	else if(stack->next==NULL)
	{
		del=stack;
		stack=NULL;
		printf("Popped %d (the only data item) from stack",del->data);
	}
	else
	{
		del=stack;
		stack->next;
		printf("Popped Value: %d \n",del->data);
	}
	free(del);
}
void printstack(){
	if(stack==NULL)
	{
		printf("Stack Underflow");
		return;
	}
        node *ref=stack;
	    int count=0;
		printf("\n\t Data in the stack:\n");
        while(ref!=NULL){
        	count++;
        	printf("\t%d\n",ref->data);
        	
        	ref=ref->next;
		}
		printf("\n\tNumber of elements in the stack:\n",count);	
	}

int main(){
	push();
	push();
	push();
	printstack();
	pop();
	pop();
	pop();
	printstack();
	return 0;
}
	

 
