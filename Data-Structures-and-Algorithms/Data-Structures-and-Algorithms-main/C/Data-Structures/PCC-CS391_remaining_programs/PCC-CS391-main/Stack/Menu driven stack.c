#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void push(int,int*,int*);
void pop(int*,int*);
void display(int*,int*);

int main()
{	
	int stack[MAX],top=-1,n,ch;
	while(1)
	{
		printf("Enter the choice : 1 to push, 2 to pop, 3 to display, 0 to exit : \n");
		scanf("%d",&ch);
		if(ch==0)
			break;
		else if(ch==1)
		{
			printf("Enter the number to push : \n");
			scanf("%d",&n);
			push(n,&top,stack);
		}
		else if(ch==2)
			pop(&top,stack);
		else if(ch==3)
			display(&top,stack);
		else
			printf("Invalid choice!!\n");
	}
	return 0;
}

void push(int num,int *top, int *stack)
{
	if(*top==MAX-1)
	{
		printf("Stack Overflow, no more element can be inserted\n");
		return;
	}
	*top=*top+1;
	stack[*top]=num;
}

void pop(int *top, int *stack)
{
	if(*top==-1)
	{
		printf("Stack Underflow, no element to be deleted\n");
		return;
	}
	printf("Data deleted is %d\n",stack[*top]);
	*top=*top-1;
}

void display(int *top, int *stack)
{
	int i;
	if(*top==-1)
	{
		printf("Empty stack, nothing to display!!\n");
		return;
	}
	printf("The elemets from TOP are : \n");
	for(i=*top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}


