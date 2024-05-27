#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert(int,int*,int*,int*);
void display(int*,int*,int*);
void del(int*,int*,int*);
void peek(int*,int*);


int main()
{
	int choice,item,cqueue[MAX],front=-1,rear=-1;
	while(1)
	{
		printf("\n1.INSERT \n2.DELETE \n3.PEEK \n4.DISPLAY \n5.EXIT \nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to be inserted:");
				scanf("%d",&item);
				insert(item,cqueue,&front, &rear);
				break;
			case 2:
				del(cqueue,&front, &rear);
				break;
			case 3:
				peek(cqueue,&front);
				break;
			case 4:
				display(cqueue,&front, &rear);
				break;
			case 5:
				printf("\nEnd of program");
				exit(0);
				break;
			default:
				printf("\nInvalid input");
		}
	}
	return 0;
				
}

void insert(int item, int *cqueue, int *front, int *rear)
{
	if((*rear+1)%MAX == *front)
	{
		printf("\n Queue Overflow");
		return;
	}
	else if(*rear==-1 && *front==-1)
	{
		*rear=0;
		*front=0;
	}
	else
	{
		*rear=(*rear+1)%MAX;
	}
	cqueue[*rear]=item;
}

void del(int *cqueue, int *front, int *rear)
{
	int item;
	if(*front==-1)
	{
		printf("\nQueue Underflow\n");
		return;
	}
	item=cqueue[*front];
	if(*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else
	{
		*front=(*front+1)%MAX;
	}
	printf("\nThe deleted item is: %d",item);
}

void peek(int *cqueue, int *front)
{
	if(*front==-1)
	{
		printf("\nNo element in cqueue\n");
		return;
	}
	printf("\nThe element at the front is: %d", cqueue[*front]);
}

void display(int *cqueue, int *front, int *rear)
{
	int i;
	if(*front==-1)
	{
		printf("\nQueue is Empty,No value to display\n");
		return;
	}
	else
	{
		for(i=*front;i!=*rear;i=(i+1)%MAX)
			printf("%d\t",cqueue[i]);
		printf("%d\t",cqueue[i]); //for the = rear element
	}
	printf("\n");
}
		
			
		
		
	
