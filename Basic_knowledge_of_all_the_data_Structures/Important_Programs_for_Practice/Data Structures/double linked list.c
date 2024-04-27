#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
// forword print
void printforward(struct node *ptr){
    printf("forward linkedlist\n");
    while (ptr!=NULL){
        printf("elemnt is : %d\n" ,ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
// reverse print
void printbackword(struct node *ptr){
    printf("backword linkedlist:\n ");
    while(ptr != NULL){
        printf("element is : %d\n ",ptr->data );
        ptr = ptr->prev;
    }
    printf("\n");
}
// first node insert
struct node *insertnode(struct node *head,int num){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=NULL;
    newnode->next=head;
    if(head==NULL){
        newnode->next=head;
    }
    head=newnode;
    return head;
}
// first node delete
struct node *deletenode(struct node *head){
    struct node *p=head;
    // struct node *q=head->next;
    head=head->next;
    if (head!=NULL){
        head->prev=NULL;
    }
    free(p);
    return head;
    
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *tail;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    tail=(struct node*)malloc(sizeof(struct node));
    
    head->data=7;
    head->prev=NULL;
    head->next=second;

    second->data=8;
    second->prev=head;
    second->next=third;

    third->data=9;
    third->prev=second;
    third->next=tail;

    tail->data=10;
    tail->prev=third;
    tail->next=NULL;
    printf("show the elements before  implementing:\n");
    printforward(head);
    printf("show the elemnts before  implementing:\n ");
    printbackword(tail);
            // after inserting
    head = insertnode(head,6);
    printf("after inserting:");
    printforward(head);
            // after deleting
    head=deletenode(head);
    printf("afetr deleting: ");
    printforward(head);
    return 0;
}
