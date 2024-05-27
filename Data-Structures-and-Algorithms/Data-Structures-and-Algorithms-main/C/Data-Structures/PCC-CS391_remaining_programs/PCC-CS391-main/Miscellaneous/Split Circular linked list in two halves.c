#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* next;
	int data;
}node;
node* insert(node* head,int item)
{
	node* ptr=(node*)malloc(sizeof(node));
	if (ptr==NULL){
		printf("\nOverflow");
		return head;
	}
	ptr->data=item;
	if (head->next==NULL)
	{
		ptr->next=ptr;
		head=ptr;
	}
	else{
		node* p = head;
		while(p->next!=head)
			p=p->next;
		p->next=ptr;
		ptr->next=head;
	}
	return head;
}
int countnode(node* head)
{
	int count=0;
	node* temp=head;
	do{
		count++;
		temp=temp->next;
	}while(temp!=head);
	return count;
}
void split(node* head,int count)
{
	node* p1=head;
	node* p2=head;
	printf("\nThe first half is:\n");
	do{
		printf("%d\t",p1->data);
		p1=p1->next;
		p2=p2->next->next;
		
		
	}while(p2!=head && p2->next!=head);
	if(count%2!=0)
	{
		printf("%d\t",p1->data);
		p1=p1->next;
	}
	printf("\nThe second half is:\n");
	do{
		printf("%d\t",p1->data);
		p1=p1->next;
	}while(p1!=head);
	exit(0);
}

void display(node* head)
{
	if(head==NULL)
	{
		printf("Empty:");
		return ;
	}
	node* ptr=head;
	do
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head);
	
	
}
int main()
{
	node* head=(node*)malloc(sizeof(node));
	head->next=NULL;
	int ch=0,item=0,count=0;
	do{
		printf("\nMENU 1.INSERT 2.SPLIT 3.DISPLAY 0.EXIT ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the item:");
				scanf("%d",&item);
				head=insert(head,item);
				break;
			case 2:
				count=countnode(head);
				printf("\nThe two splitted lls are:");
				split(head,count);
				break;
			case 3:
				printf("\nDisplaying: \n");
				display(head);
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid choice");
			}
		
	}while(ch!=0);
}
