#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linkedlist(struct node *head)
{
    struct node *ptr=head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
        // insert node in circular linked list at begining
struct node *insertathead(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=11;
    struct node *p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
// insert at end
struct node *insertatend(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=11;
    struct node *p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    // head=ptr;
    return head;
}
//insert at particular index
struct node *insertatposition(struct node *head,int data,int index){
    struct node * p=head;
    struct node * q=head->next;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    newnode->data=data;
    p->next=newnode;
    newnode->next=q;
    return head;
}
// delete the first node
struct node *  deletefirst(struct node *head){
   struct node * p1=head;
   while(p1->next!=head){
    p1=p1->next;
   }
	p1->next=head->next;
    free(head);
    head=p1->next;
	return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=8;
    second->next=third;
    third->data=9;
    third->next=fourth;
    fourth->data=10;
    fourth->next=head;
    printf("show the elements before implementing:\n");
    linkedlist(head);
    // head=insertathead(head,11);
    // printf("show the ekements after implementing:\n ");
    // linkedlist(head);
    // head=insertatend(head,11);
    // linkedlist(head);
    // head=insertatposition(head,11,3);
    // linkedlist(head);
    // head= deletefirst(head);
    head=deletelast(head);
    linkedlist(head);
    return 0;
}
