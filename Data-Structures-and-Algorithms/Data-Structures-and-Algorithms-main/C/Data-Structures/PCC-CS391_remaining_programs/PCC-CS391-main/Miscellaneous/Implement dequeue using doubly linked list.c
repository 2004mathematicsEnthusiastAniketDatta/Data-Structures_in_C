#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}node;
void insertfront(node **front, node **rear, int item)
{
	node *ptr=(node *)malloc(sizeof(node));
	if (ptr==NULL)
	{
		printf("\nOverflow");
		exit(0);
	}
	ptr->data=item;
	printf("\nItem inserted");
	if(*front==NULL)
	{
		
		*front=*rear=ptr;
	}	
	else
	{
		ptr->next=*front;
		(*front)->prev=ptr;
		*front=ptr;
	}
}
void insertrear(node **front, node **rear, int item)
{
	node *ptr=(node *)malloc(sizeof(node));
	if (ptr==NULL)
	{
		printf("\nOverflow");
		exit(0);
	}
	ptr->data=item;
	printf("\nItem inserted");
	if(*rear==NULL)
	{
		
		*front=*rear=ptr;
	}	
	else
	{
		(*rear)->next=ptr;
		ptr->prev=*rear;
		*rear=ptr;
	}
}
void deletefront(node **front, node**rear)
{
	if (*front==NULL)
	{
		printf("\nlist is empty");
		exit(0);
	}
	node *temp=*front;
	*front=(*front)->next;
	printf("\nItem deleted");
	if (*front==NULL)
	{
		*rear=NULL;
	}
	else
	{
		(*front)->prev=NULL;
	}
	free(temp);
}
void deleterear(node **front, node**rear)
{
	if (*rear==NULL)
	{
		printf("\nlist is empty");
		exit(0);
	}
	node *temp=*rear;
	*rear=(*rear)->prev;
	printf("\nItem deleted");
	if (*rear==NULL)
	{
		*front=NULL;
	}
	else
	{
		(*rear)->next=NULL;
	}
	free(temp);
}
void display(node **front,node **rear)
{
	node *ptr=*front;
	if (*front==NULL)
		printf("\nList is empty");
	else
	{
	 
		while (ptr!=NULL)
		{
			printf("%d",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
	
	
}
void main()
{
	node *front=NULL,*rear=NULL;
	int ch,item;
	while(ch!=0)
	{
		printf("\nMENU\n1.insertfront\n2.insertrear\n3.deletefront\n4.deleterear\n5.display\n0.exit\nenter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item:");
				scanf("%d",&item);
				insertfront(&front,&rear,item);
				break;
			case 2: printf("\nEnter the item:");
				scanf("%d",&item);
				insertrear(&front,&rear,item);
				break;
			case 3: deletefront(&front,&rear);
				break;
			case 4: deleterear(&front,&rear);
				break;
			case 5: display(&front,&rear);
				break;
			case 0: exit(0);
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
	
	}

}
