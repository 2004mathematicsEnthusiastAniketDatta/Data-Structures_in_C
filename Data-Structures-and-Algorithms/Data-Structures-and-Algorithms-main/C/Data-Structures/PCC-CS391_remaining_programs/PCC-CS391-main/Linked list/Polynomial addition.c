#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void insert(node* head,int data){
    node* ptr = (node*) malloc (sizeof(node));
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}

void display(node* head){
	node *ptr = (node*) malloc (sizeof(node));
	ptr = head->next;
	int i=0;
	while(ptr->next != NULL){
		printf("[%d]x^[%d] + ",ptr->data,i++);
		ptr = ptr->next;
	}
	printf("[%d]x^[%d] = 0\n",ptr->data,i++);
}

void display_ans(node* head, int size){
	node *ptr = (node*) malloc (sizeof(node));
	ptr = head->next;
	while(ptr->next != NULL){
		printf("[%d]x^[%d] + ",ptr->data,size--);
		ptr = ptr->next;
	}
	printf("[%d]x^[%d] = 0\n",ptr->data,size);
}

node* add(node* p1, node* p2, node* p){
	node *ptr1 = (node*) malloc (sizeof(node));
    node *ptr2 = (node*) malloc (sizeof(node));
    ptr1 = p1->next;
    ptr2 = p2->next;
    int value;
    while(ptr2 != NULL){
		value = ptr1->data + ptr2->data;
		insert(p,value);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	while(ptr1 != NULL){
		insert(p, ptr1->data);
		ptr1 = ptr1->next;
	}
	return p;
}

void main(){
    int n1,n2,i,x;
    node* p1 = (node*) malloc (sizeof(node));
    node* p2 = (node*) malloc (sizeof(node));
    node* p = (node*) malloc (sizeof(node));
    p1->next = NULL;
    p2->next = NULL;
    printf("Enter the degree of polynomial 1 :  ");
    scanf("%d",&n1);
    printf("Enter the coefficients of polynomial 1 : \n");
    for(i=0;i<=n1;i++){
        printf("Coefficient of x^[%d] = ",n1-i);
        scanf("%d",&x);
        insert(p1,x);
    }
    printf("\nDisplaying polynomial 1 :\n");
    display(p1);
    printf("\nEnter the degree of polynomial 2 :  ");
    scanf("%d",&n2);
    printf("Enter the coefficients of polynomial 2 : \n");
    for(i=0;i<=n2;i++){
        printf("Coefficient of x^[%d] = ",n2-i);
        scanf("%d",&x);
        insert(p2,x);
    }
    printf("\nDisplaying polynomial 2 :\n");
    display(p2);
    printf("\nDisplaying resultant polynomial :\n");
    if(n1 > n2){
    	p = add(p1, p2, p);
 	display_ans(p, n1);
    }
    else{
    	p = add(p2, p1, p);
    	display_ans(p, n2);
    }
}
