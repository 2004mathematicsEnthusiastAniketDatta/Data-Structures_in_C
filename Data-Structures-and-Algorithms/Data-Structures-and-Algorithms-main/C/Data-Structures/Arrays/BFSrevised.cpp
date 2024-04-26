#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define  MAX_VERTICES 100

struct Node{
	int data;
	struct Node*next;
};
struct Node *CreateNode(int data){
       struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node*));
	   NewNode->data = data;
	   NewNode->next = NULL;
	   retuurn NewNode; 
}

