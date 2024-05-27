#include<stdio.h>
#include<stdlib.h>
void insertst(int item);
void inserten(int item);
void insertmi(int item);
void delst();
void delen();
void delmi();
void display();
void reverse();
void sort();
struct node
{
	int data;
	struct node* next;
};struct node* head;
void main()
{
	int ch,item;
	while(1){
	printf("Menu :\n");
	printf("1.Insert at start , 2.Insert at end , 3.Insert at other position , 4.Delete at start , 5.Delete at end , 6.Delete at other position , 7.Display , 8.Reverse , 9.Sort , 10.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter item : ");
			   scanf("%d",&item);
			   insertst(item);
			   break;
		case 2:printf("Enter item : ");
			   scanf("%d",&item);
			   inserten(item);
			   break;
		case 3:printf("Enter item : ");
			   scanf("%d",&item);
			   insertmi(item);
			   break;
		case 4:delst();
				break;
		case 5:delen();
				break;
		case 6:delmi();
				break;
		case 7:display();
				break;
		case 8:reverse();
				break;
		case 9:sort();
				break;
		case 10:printf("Program exited\n");
				exit(0);
				break;
		default:printf("Invalid choice");
	}
	}
}
void insertst(int item)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
		printf("Overflow\n");
	else
	{
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("Data inserted\n");
	}
}
void inserten(int item)
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
		printf("Overflow\n");
	else
	{
		ptr->data=item;
		printf("Data inserted\n");
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=ptr;
			ptr->next=NULL;
		}
	}
}
void insertmi(int item)
{
	int i,loc;
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
		printf("Overflow\n");
	else
	{
		ptr->data=item;
		printf("Enter the index after which you want to enter : ");
		scanf("%d",&loc);
		temp=head;
		for(i=0;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("Cannot insert\n");
				return;
			}
		}
		ptr->next=temp->next;
		temp->next=ptr;
		printf("Data inserted\n");
	}
}
void delst()
{
	struct node *ptr;
	if(head==NULL)
		printf("Underflow\n");
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("Node deleted\n");
	}
}
void delen()
{
	struct node *ptr,*temp;
	if(head==NULL)
		printf("Underflow\n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("Node deleted\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		free(ptr);
		printf("Node deleted\n");
	}
}
void delmi()
{
	struct node *ptr,*temp;
	int loc,i;
	printf("Enter location of node at which you want to delete : ");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc;i++)
	{
		temp=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("Cannot delete\n");
			return;
		}
	}
	temp->next=ptr->next;
	free(ptr);
	printf("Node deleted\n");
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("Nothing to display\n");
	}
	else
	{
		printf("Values are : \n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n");
}
void reverse()
{
	struct node *t1,*t2,*temp;
	t1=t2=NULL;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		while(head!=NULL)
		{
			t2=head->next;
			head->next=t1;
			t1=head;
			head=t2;
		}
		head=t1;
		temp=head;
		printf("Reversed list is : \n");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void sort()
{
	struct node *current=head;
	struct node *index=NULL;
	int temp;
	if(head==NULL)
		return;
	else
	{
		while(current!=NULL)
		{
			index=current->next;
			while(index!=NULL)
			{
				if(current->data > index->data)
				{
					temp=current->data;
					current->data=index->data;
					index->data=temp;
				}
				index=index->next;
			}
			current=current->next;
		}
		printf("Sorted List is :\n");
		display();
	}
}






