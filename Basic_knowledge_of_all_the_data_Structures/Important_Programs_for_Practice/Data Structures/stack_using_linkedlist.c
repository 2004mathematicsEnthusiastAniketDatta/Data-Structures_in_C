#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    };
                //linked list creation
    void linkedlist( struct node *ptr){
    while ( ptr != NULL){
        printf("Element : %d \n" , ptr->data);
        ptr = ptr->next;
      }

    }
                //checking is the stack empty or not
    int isempty(struct node*top){
        if(top==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
                    //checking is the stack full or not

    int isfull(struct node*top){
        struct node *p=(struct node*)malloc(sizeof(struct node));
        if(p==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
        //pushing element in stack
    struct node *push ( struct node *top,int x){
        if(isfull(top)){
            printf("stack overflow ");
        }
        else{
            struct node *n=(struct node*)malloc(sizeof(struct node));
            n->data=x;
            n->next =top;
            top=n;
            return top;
        }
    }
            //poping element in stack

    int pop ( struct node **top){
        if(isempty(*top)){
            printf("stack overflow ");
        }
        else{
            struct node *n=(*top);
            (*top)=(*top)->next;
            int x=n->data;
            free(n);
            return x;


        }
    }
    // int peek (struct node *ptr){             ....#first method(peek).....when there have limited node in stack like 4 or 5 
                                                    // ,that is the easiest way to find out the element
    //     if (ptr== NULL){
    //         return -1;
    //     }
    //     else{
    //         return ptr->data;
    //     }
    // }
    int peek (struct node *top ,int pos){               //another method(peek) , that is universal method to find out the element of any position in the stack
        struct node *ptr = top;
        for (int i =0; (i<pos-1 && ptr!=NULL);i++){
            ptr = ptr->next;
        }
    
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
        }
    }
     int topelement(struct node *ptr){             
        if (ptr== NULL){
            return -1;
        }
        else{
            return ptr->data;
        }
    }
int main(){
    struct node *top =NULL;
    top=push(top , 28);
    top=push(top , 18);
    top=push(top , 15);
    top=push(top , 7);

    linkedlist(top);
    int element =pop(&top);
    printf("popped element is %d \n",element);
    linkedlist(top);
    // int ele = peek(top->next);
        int ele = peek(top,2);

    printf("element of 2nd node %d\n",ele);
    int ele1 = topelement(top);
    printf("element of top node %d\n",ele1);
    return 0;
}
