#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *createnode(int data){
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	 ptr->left= NULL;
	 ptr->data=data;
	 ptr->right= NULL;
	 return ptr;

}
void inorder(struct node * n){
	if(n!=NULL){
		inorder(n->left);
		printf("%d ",n->data);
		inorder(n->right);
	}
}
int isBST(struct node * root){
	 static struct node *prev=NULL;
	if(root!=NULL){
		if(!isBST(root->left)){
			return 0;
		}
	    if(prev!=NULL && root->data <= prev->data)
		{
			return 0;
		}
		prev = root;
		return isBST(root->right);
	}
	else{
		return 1;
	}
}
struct node *search( struct node * root,int key){
	if(root==NULL){
		return 0;
	}
	if(root->data==key){
		return root;
	}
	else if (root->data<key){
		return search(root->right,key);
	}
	else{
		return search(root->left,key);
	}
}
	void insert(struct node *root, int val){
	struct node * prev=NULL;
	while(root!=NULL){
		prev=root;   
		if(val==root->data){
			printf("cannot insert");
		}
		else if(val<root->data){
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
	struct node *newnode=createnode(val);
	if(val<prev->data){
		prev->left=newnode;
	}
	else{
		prev->right=newnode;
	}

}
struct node * inorderpredessor(struct node *root){
	root=root->left;
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}
struct node * deletenode(struct node *root,int key){
	struct node *ipre;
	if(root==NULL){
		return NULL;
	}
	if(root->left == NULL && root->right == NULL){
		free(root);
		return NULL;
	}
	if(key<root->data){
		root->left=deletenode(root->left,key) ;
	}
	else if (key>root->data){
		root->right=deletenode(root->right,key);
	}
	//deletion strategy when code is found.
	else{
		ipre=inorderpredessor(root);
	    root->data=ipre->data;
		root->left=deletenode(root->left,ipre->data);
	}
	return root;
}
int main(){
	struct node * p = createnode(5);
	struct node * p1 = createnode(3);
	struct node * p2 = createnode(6);
	struct node * p3 = createnode(1);
	struct node * p4 = createnode(4);
	
	p->left=p1;
	p->right=p2;
	p1->left=p3;
	p1->right = p4;
	
	// struct node *root=NULL;
	// root=createnode(root,5);

	inorder(p);
	// printf("%d ",isBST(p));
	struct node *n =search(p,4);
    printf("found element is %d ", n->data);
	// insert(p,16);
	// printf(" \n ");
	// inorder(p);
	// printf("%d ", p->right->right->data);
	deletenode(p,6);
		printf(" \n ");

	inorder(p);

	return 0;
}
