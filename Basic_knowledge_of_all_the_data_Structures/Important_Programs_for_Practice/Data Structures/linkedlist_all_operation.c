#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insertlinkedlist(struct node *p){
	while(p!=NULL){
		printf("the elemnts is %d \n",p->data);
		p=p->next;
	}
}
struct node * deletefirst( struct node *head){
	struct node * p1=head;
	head=head->next;
	int val = p1->data;
	free(p1);
	return head;
}
struct node * deleteindex(struct node *head,int index){
	struct node *p = head;
	struct node* q= head->next;
    for(int i=0;i<index-1;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
}
struct node *deleteend(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
		
	}
	p->next=NULL;
	free(q);
	return head;
}
        //  insertion code
    struct node *insertfirst(struct node *head,int data){
        struct node * ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->next=head;
        head=ptr;
        return head;
    }
    struct node * insertindex(struct node *head,int data ,int index){
        struct node *p=head;
        struct node *q=head->next;
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        for(int i=0;i<index-1;i++){
            p=p->next;
            q=q->next;
            
        }
        ptr->data=data;
        p->next=ptr;
        ptr->next=q;
        return head;
    }
    struct node *insertend(struct node *head,int data){
        struct node * p=head;
        struct node *q=head->next;
        struct node *ptr=(struct node *)malloc(sizeof(struct node));
        while (q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        q->next=ptr;
        ptr->data=data;
        ptr->next=NULL;
        return head;

    }
int main(){
	struct node *head=(struct node*)malloc(sizeof(struct node));
	struct node *second=(struct node*)malloc(sizeof(struct node));
	struct node *third=(struct node*)malloc(sizeof(struct node));
	struct node *fourth=(struct node*)malloc(sizeof(struct node));
	struct node *fifth=(struct node*)malloc(sizeof(struct node));
	head->data=7;
	head->next=second;
	second->data=8;
	second->next=third;
	third->data=9;
	third->next=fourth;
	fourth->data=10;
	fourth->next=fifth;
	fifth->data=11;
	fifth->next=NULL;
	
	insertlinkedlist(head);
	
//	head=deletefirst(head); // after the first element delete
//	insertlinkedlist(head);
    // head=deleteindex(head,2);
    // insertlinkedlist(head);
    // head=deleteend(head);
	// insertlinkedlist(head);
    // head=insertfirst(head,6);
    // insertlinkedlist(head);
    // head=insertindex(head,13,2);
    head=insertend(head,12);
    insertlinkedlist(head);


	return 0;
	
	
}
