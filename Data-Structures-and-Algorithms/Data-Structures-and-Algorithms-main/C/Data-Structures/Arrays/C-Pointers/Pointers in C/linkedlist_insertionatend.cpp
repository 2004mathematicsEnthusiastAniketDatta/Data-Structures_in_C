#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *head=NULL;

node *createNode(){
	node *temp;
	temp=(node*) malloc (sizeof(node));
	return temp;
}

void insertAtEnd(){
	node *temp=createNode();
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (head==NULL)
		head=temp;
	else{
		node *ref=head;
		while(ref->next != NULL)
		
			 ref=ref->next;
			 ref->next=temp;
		
	}	
}
void traversal(){
	node *ref=head;
	printf("\t Values in the list \n");
	while(ref!=NULL){
	
	printf("\t%d\n",ref->data);
	ref=ref->next;
}
}


int main(){
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    traversal();
return 0;
}


