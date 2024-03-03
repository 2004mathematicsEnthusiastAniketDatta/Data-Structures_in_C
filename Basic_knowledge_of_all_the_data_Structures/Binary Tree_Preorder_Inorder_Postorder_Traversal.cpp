#include <stdio.h>
#include <stdlib.h>
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
int main(){
	node *temp=createNode();
	node *tempLeft= createNode();
	node *tempRight=createNode();
	temp->left=tempLeft;
	temp->right=tempRight;
	root=temp;
	printf("\n");
	printf("Preorder traversal:  ");
	preorder(root);
	printf("\n");
	printf("Inorder Traversal:  ");
	inorder(root);
	printf("\n");
	printf("Postorder Traversal:  ");
    postorder(root);
    
}
