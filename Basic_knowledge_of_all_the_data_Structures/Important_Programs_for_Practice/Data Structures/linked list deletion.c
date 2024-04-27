#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next
};
void insertlinkedlist(struct Node *ptr){
    while(ptr!=NULL){
        printf("enter the elements %d\n",ptr->data);
        ptr=ptr->next;
    }
}
                //1.... DELETE FIRST ELEMENT..........................
struct Node *deletefirst(struct Node *head){
    struct Node *ptr = head;
    head=head->next;
    free(ptr);
    return head;
}
                //2.... DELETE INDEX ELEMENT........................
struct Node *deleteindex(struct Node *head ,int index){
    struct Node *p = head;
    struct Node *q=head->next;
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
                //3.... DELETE AT THE END ELEMENT....................
struct Node *deleteatend(struct Node *head ){
    struct Node *p = head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head =(struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=8;
    second->next=third;
    third->data=9;
    third->next=fourth;
    fourth->data=10;
    fourth->next=NULL;
    printf("Show the linked list before deletion:\n");
    insertlinkedlist(head);
        // 1st element deletion;.................................
    head=deletefirst(head);
     printf("Show the linked list after  1st node deletion:\n");
    insertlinkedlist(head);
        // index element deletion;.................................

    head=deleteindex(head,2);
     printf("Show the linked list after  index element deletion:\n");
    insertlinkedlist(head);
        // last element deletion;.................................
    head=deleteatend(head);
    printf("Show the linked list after  last end deletion:\n");
    insertlinkedlist(head);

    return 0;
    
}
