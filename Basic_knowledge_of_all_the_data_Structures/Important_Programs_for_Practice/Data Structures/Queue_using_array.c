#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
//isfull
int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
//isempty
int isempty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
//enque
void enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("this queue is full\n");
    }
    else {
        q->r++;
        int a=q->arr[q->r]=val;
        printf("enqueue element is %d\n",a);
    }
}
//dequeue
int dequeue(struct queue *q){
    int a=-1;

    if(isempty(q)){
        printf("this queue is full\n");
    }
    else {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue *q;
    q->size=100;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size * sizeof(int));
    
    //Enqueue few elements
    enqueue(q,12);
    enqueue(q,13);
    enqueue(q,14);
    enqueue(q,15);
    printf("after enqueue then we proceed dequeue\n");
    printf("dequeue element is %d\n",dequeue(q));
    printf("dequeue element is %d",dequeue(q));
    // if(isempty(q)){
    //     printf("queue is empty\n");
    // }
    // if(isfull(q)){
    //     printf("queue is full\n");
    // }
    return 0;
}
