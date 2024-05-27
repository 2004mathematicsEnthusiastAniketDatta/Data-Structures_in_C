#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;
node* createnode(int key)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=key;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
node* insert1(node* root1,int key)
{
	if(root1==NULL)
		return createnode(key);
	if(key<root1->data)
		root1->left=insert1(root1->left,key);
	else if(key>root1->data)
		root1->right=insert1(root1->right,key);
	return root1;
}
node* insert2(node* root2,int key)
{
	if(root2==NULL)
		return createnode(key);
	if(key<root2->data)
		root2->left=insert2(root2->left,key);
	else if(key>root2->data)
		root2->right=insert2(root2->right,key);
	return root2;
}
bool search(node* root2, int data) {
    if (root2 == NULL)
        return false;
    if (root2->data == data)
        return true;
    if (data < root2->data)
        return search(root2->left, data);
    else
        return search(root2->right, data);
}

bool inorder1(node* root1, node* root2) {
    if (root1 == NULL)
        return true; // Base case: no more elements to check
    if (!search(root2, root1->data))
        return false; // Element in root1 not found in root2
    // Check recursively for left and right subtrees
    return inorder1(root1->left, root2) && inorder1(root1->right, root2);
}

int main() {
    node* root1 = NULL;
    node* root2 = NULL;

    root1 = insert1(root1, 15);
    root1 = insert1(root1, 10);
    root1 = insert1(root1, 20);
    root1 = insert1(root1, 6);
    root1 = insert1(root1, 12);
    root1 = insert1(root1, 25);

    root2 = insert2(root2, 15);
    root2 = insert2(root2, 12);
    root2 = insert2(root2, 20);
    root2 = insert2(root2, 6);
    root2 = insert2(root2, 25);
    root2 = insert2(root2, 10);

    if (inorder1(root1, root2))
        printf("\nThe two BSTs have equal unique elements.");
    else
        printf("\nThe two BSTs do not have equal unique elements.");

    return 0;
}
