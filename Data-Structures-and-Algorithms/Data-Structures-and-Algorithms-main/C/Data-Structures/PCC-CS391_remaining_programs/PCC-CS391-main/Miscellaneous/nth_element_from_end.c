// Online C compiler to run C program online
//nth element from last
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
void reverse(node* head,int n){
    node* q=head;
    node* r=NULL;
    node* s;
    while(q!=NULL){
        s=r;
        r=q;
        q=q->next;
        r->next=s;
    }
    head=r;
    //nth element from first
    node* temp=head;
    for(int i=0;i<n-1;i++){

        temp=temp->next;
    }
    printf("%d element from end is %d",n,temp->data);
}
int main() {
    node* head=NULL;
    int item=0,choice=0,n=0;
    while(1){
        printf("\nMenu\n1.Insert\n2.Display\n3.Reverse\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("\nEnter the item:");
                    scanf("%d",&item);
                    head=insert(head,item);
                    break;
            case 2: printf("\nDisplaying\n");
                    display(head);
                    break;
            case 3: printf("\nEnter the value of n:");
                    scanf("%d",&n);
                    reverse(head,n);
                    break;
            case 4: exit(0);
            default:printf("\nWrong choice");
                    break;
        }
    }
    return 0;
}
