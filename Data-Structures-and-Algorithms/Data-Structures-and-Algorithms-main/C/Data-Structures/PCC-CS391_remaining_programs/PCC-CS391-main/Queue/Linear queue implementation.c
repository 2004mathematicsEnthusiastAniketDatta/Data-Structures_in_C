#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void insert(int,int*,int*,int*);
void display(int*,int*,int*);
void del(int*,int*,int*);

/*int isFull(int*,int*);
int isEmpty(int*);*/

int main()
{
	int choice,item,queue[MAX],front=-1,rear=-1;
	while(1)
	{
		printf("\n1.INSERT \n2.DELETE  \n3.DISPLAY \n4.EXIT \nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to be inserted:");
				scanf("%d",&item);
				insert(item,queue,&front, &rear);
				break;
			case 2:
				del(queue,&front, &rear);
				break;
			
			case 3:
				display(queue,&front, &rear);
				break;
			case 4:
				printf("\nEnd of program");
				exit(0);
				break;
			default:
				printf("\nInvalid input");
		}
	}
	return 0;
				
}

void insert(int item, int *queue, int *front, int *rear)
{
	if(*rear==MAX-1)
	{
		printf("\nQueue overflow\n");
		return;
	}
	else if(*front == -1)
	{
		*front=0;
		*rear=0;
	}
	else
	{
		*rear=*rear+1;
	}
	queue[*rear]=item;
}

void del(int *queue, int *front, int *rear)
{
	int item;
	if(*front==-1)
	{
		printf("\nQueue Underflow\n");
		return;
	}
	item=queue[*front];
	
	if(*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	
	else
		*front=*front+1;
	printf("\nThe deleted item is: %d",item);
}

/*int isEmpty(int *front)
{
	if(*front==-1)
		return 1;
	else
		return 0;
}

int isFull(int *front,int *rear)
{
	if(*rear==MAX-1)
		return 1;
	else
		return 0;
}*/


void display(int *queue, int *front, int *rear)
{
	int i;
	if(*front==-1)
	{
		printf("\nQueue is Empty,No value to display\n");
		return;
	}
	printf("\nThe elements in the linear queue are:\n");
	i=*front;
	while(i<=*rear)
		printf("%d\t",queue[i++]);
	
	printf("\n");
}
		
			
		
		
	
