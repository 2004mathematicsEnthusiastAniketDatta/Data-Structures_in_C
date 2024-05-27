#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node; 
node* createnode(int item)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=item;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
int maxvalue(node* node)
{
	if (node==NULL)
		return 0;
	int leftmax=maxvalue(node->left);
	int rightmax=maxvalue(node->right);
	int value=0;
	if (leftmax>rightmax)
	{
		value=leftmax; 
	}
	else
		value=rightmax;
	if (value<node->data)
		value=node->data;
	return value;
}
int minvalue(node* node)
{
	if (node==NULL)
		return 1000000000;
	int leftmax=maxvalue(node->left);
	int rightmax=maxvalue(node->right);
	int value=0;
	if (leftmax<rightmax)
	{
		value=leftmax; 
	}
	else
		value=rightmax;
	if (value>node->data)
		value=node->data;
	return value;
}
int checkbst(node* node)
{
	if(node==NULL)
		return 1;
	if(node->left!=NULL && maxvalue(node->left)>node->data)
		return 0;
	if(node->right!=NULL && minvalue(node->right)<node->data)
		return 0;
	if(!checkbst(node->left) || !checkbst(node->right))
		return 0;
	return 1;
		
}
int main()
{
	node* root=createnode(5);
	root->left=createnode(3);
	root->left->left=createnode(2);
	root->right=createnode(7);
	root->right->right=createnode(1);
	
	if(checkbst)
		printf("\nis bst");
	else
		printf("\nnot bst");
	return 0;
	
}
