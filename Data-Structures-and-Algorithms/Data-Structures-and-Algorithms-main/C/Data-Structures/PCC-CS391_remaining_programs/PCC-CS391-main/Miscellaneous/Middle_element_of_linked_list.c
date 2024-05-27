// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* insert(node* head,int item){
    node* temp;
    node* ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
        printf("\nOverflow");
    ptr->data=item;
    printf("\nItem inserted");
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=ptr;
        ptr->next=NULL;
    }
    return head;
}
void display(node* head){
    node* p=head;
    if(p==NULL)
        printf("\nNothing to display");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void middle(node* head){
    if (head == NULL) {
        printf("\nThe list is empty.");

    }
    node* p1= head;
    node* p2= head;

    while(p1!=NULL && p1->next!=NULL){
        p2=p2->next;
        p1=p1->next->next;
    }
    printf("\nThe middle element is: %d",p2->data);
}
int main() {
    node* head=NULL;
    int item=0,choice=0;
    while(1){
        printf("\nMenu\n1.Insert\n2.Display\n3.Middle\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("\nEnter the item:");
                    scanf("%d",&item);
                    head=insert(head,item);
                    break;
            case 2: printf("\nDisplaying\n");
                    display(head);
                    break;
            case 3: middle(head);
                    break;
            case 4: exit(0);
            default:printf("\nWrong choice");
                    break;
        }
    }
    return 0;
}
