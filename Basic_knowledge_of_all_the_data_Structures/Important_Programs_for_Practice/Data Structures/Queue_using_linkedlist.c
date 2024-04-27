#include<stdio.h>
#include<stdlib.h>
    //Global variable
struct node *f=NULL;
struct node *r=NULL;
struct node{
    int data;
    struct node *next;
 };
 void insertlinkedlist(struct node *ptr){
    printf("printing the elements of this linkedlist \n");
    while(ptr!=NULL){
        printf(" elements %d\n", ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int val){                      //as f and r global variable ,so don't need to use f and r in enqueue
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is full");
    }
    else{
    n->data=val;
    n->next=NULL;
    if(f==NULL){
        f=r=n;
    }
    r->next=n;
    r=n;
    }
}
int dequeue(){
    int val=-1;
    struct node *ptr=f;
    if (f==NULL){
        printf("Queue is empty");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    insertlinkedlist(f);
    printf("dequeuing elemnt is %d\n ",dequeue());
    enqueue(10);
    enqueue(11);
    enqueue(12);
    insertlinkedlist(f);
    printf("Element of dequeue is %d\n ",dequeue());
    insertlinkedlist(f);


    return 0;
}
