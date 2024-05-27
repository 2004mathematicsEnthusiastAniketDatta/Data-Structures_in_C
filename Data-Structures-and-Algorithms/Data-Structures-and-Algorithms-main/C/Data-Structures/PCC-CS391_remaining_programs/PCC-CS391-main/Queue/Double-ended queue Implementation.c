#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void add_rear(int ,int *,int *,int *);
void add_front(int ,int *,int *,int *);
void del_rear(int *, int *, int *);
void del_front(int *, int *, int *);
void display(int *, int *, int *);

int main()
{
	int choice,item,dqueue[MAX],front=-1,rear=-1;
	while(1)
	{
		printf("\n1.INSERT REAR \n2.INSERT FRONT \n3.DELETE REAR \n4.DELETE FRONT \n5.DISPLAY \n6.EXIT \nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to be inserted at rear position:");
				scanf("%d",&item);
				add_rear(item,dqueue,&front, &rear);
				break;
			case 2:
				printf("\nEnter the element to be inserted at front position:");
				scanf("%d",&item);
				add_front(item,dqueue,&front, &rear);
				break;
			case 3:
				del_rear(dqueue,&front, &rear);
				break;
			case 4:
				del_front(dqueue,&front, &rear);
				break;
			case 5:
				display(dqueue,&front, &rear);
				break;
			case 6:
				printf("\nEnd of program");
				exit(0);
				break;
			default:
				printf("\nInvalid input");
		}
	}
	return 0;
				
}

void add_rear(int item,int *dqueue,int *front,int *rear)
{
		
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1))
    {
        printf("QUEUE OVERFLOW!\n");
        return;
    }
    
    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        if (*rear == MAX - 1)
            *rear = 0;
        else
            *rear = *rear + 1;
    }
    dqueue[*rear] = item;
}

void add_front(int item,int *dqueue,int *front,int *rear)
{
	
   if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1))
    {
        printf("QUEUE OVERFLOW!\n");
        return;
    }
    
    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        if (*front == 0)
            *front = MAX - 1;
        else
            *front = *front - 1;
    }
    dqueue[*front] = item;

}
void del_rear(int *dqueue, int *front, int *rear)
{
	int num;
	if(*rear==-1){
		printf("\nCannot delete item\n");
		return;
		}
	else
	{
		num=dqueue[*rear];
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else
		{
			*rear=*rear-1;
			printf("\nThe deleted item is: %d",num);
		}
		
	}
}
		
void del_front(int *dqueue, int *front, int *rear)
{
	int num;
	if(*front==-1){
		printf("\nQueue underflow\n");
		return;
		}
	else
	{
		num=dqueue[*front];
		printf("\nThe deleted item is: %d",num);
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else
		{
			*front=*front+1;
			
		}
	}
}

void display(int *dqueue, int *front, int *rear)
{
	int i;
	if(*front==-1)
		printf("\nNothing to display\n");
	else
	{
		printf("\nThe elements in the double ended queue are:\n");
		
		if(*front<=*rear){
			for(i=*front;i<=*rear;i++)
				printf("%d\t",dqueue[i]);
		}
		else{
			for(i=*front;i<MAX;i++)
				printf("%d\t",dqueue[i]);
			for(i=0;i<=*rear;i++)
				printf("%d\t",dqueue[i]);
			}
	}
}

