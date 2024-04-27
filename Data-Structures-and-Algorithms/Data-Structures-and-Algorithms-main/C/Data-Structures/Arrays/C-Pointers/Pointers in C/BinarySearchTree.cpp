#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
node *root=NULL;
node* createNode(){
	node *n;
	n=(node*)malloc(sizeof(node));
	printf("\n\t\t Data:");
	scanf("%d",&n->data);
	n->left=NULL;
	n->right=NULL;
	return (n);
}
node* insert(node *temp,node *h){
	if(h==NULL)
{
	return temp;
	printf("\n\t\t Element Inserted: %d\n",h->data);
}

	else if(temp->data>h->data)
	{
		h->right=insert(temp,h->right);
	}
	else if(temp->data<h->data){
		h->left=insert(temp,h->left);
	}
	return h;
}
void preorder(node *h){
	if(h!=NULL){
		printf("%d \t",h->data);
		preorder(h->left);
		preorder(h->right);
	}
}
void inorder(node *h){
	if(h!=NULL){
		inorder(h->left);
		printf("%d \t",h->data);
		inorder(h->right);
	}
}
void postorder(node *h){
		if(h!=NULL){	
		printf("%d \t",h->data);
		inorder(h->right);
		inorder(h->left);		
	}
}
int menu()
{
	int choice;
	printf("\n\t Enter choice:");
	scanf("%d",&choice);
	return(choice);
}

int main(){
	{
		printf("\n1: Insert \n");
		printf("\n0: Traverse the Tree \n");
	 
	 switch(menu())
{    case1: node *temp1;
     temp1=createNode();
     node *h;
     h=root;
     root=insert(temp1,h);
     break;
//	node *temp=createNode();
//	node *tempLeft= createNode();
//	node *tempRight=createNode();
//	temp->left=tempLeft;
//	temp->right=tempRight;

case 0:    if(root==NULL)
    {
      printf("No node present in the tree\n");
  }
  else{
	printf("\n");
	printf("Preorder traversal:  ");
	preorder(root);
	printf("\n");
	printf("Inorder Traversal:  ");
	inorder(root);
	printf("\n");
	printf("Postorder Traversal:  ");
    postorder(root);
}    break;
default: printf("\n\t\t Please provide a valid choice");
break;
    	
}
}
}
