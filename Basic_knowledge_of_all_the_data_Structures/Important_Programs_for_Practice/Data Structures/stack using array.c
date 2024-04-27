#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int  *arr;
};

int isempty( struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push (struct stack *ptr,int val){
    if (isfull(ptr)){
        printf("stack overflow ! cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }

}

int pop(struct stack *ptr){
    if (isempty(ptr)){
        printf("stack empty ! cannot pop  to the stack\n");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek( struct stack *sp, int i){
    int arrind=sp->top-i+1;     //concept in khata
    if(arrind<0){
        printf("not a valid position od stack\n");
        return -1;
    }
    else{
         return sp->arr[arrind];
    }
}
int stacktop(struct stack *sp){
    return sp->arr[sp->top];
}
int stackbottom(struct stack *sp){
    
    return sp->arr[0];
}
int main(){
   
    struct stack *sp;
    sp=(int*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr= (int*)malloc(sp->size*sizeof(int));
    
    printf("stack has been created successfully :");
    printf(" before pushing %d\n",isfull(sp));
    printf(" before poping %d\n",isempty(sp));
    
    push (sp,56);
    push (sp,55);
    push (sp,53);
    push (sp,52);
    push (sp,51);
    push (sp,50);
    push (sp,57);
    push (sp,58);
    // push (sp,59);
    // push (sp,582);
    // push (sp,58);


    printf(" after pushing %d\n",isfull(sp));
    printf(" after poping %d\n",isempty(sp));
    printf("poped %d from the stack\n",pop(sp));

    // printf("poped %d from the stack\n",pop(sp));     //last in first out
    for (int j=1;j<=sp->top+1 ; j++){
        printf("The value of position %d is %d\n",j,peek(sp,j));
    }
    printf("top of the element of stack is %d\n",stacktop(sp));
    printf("bottom of the element of stack is %d\n",stackbottom(sp));


    return 0;
}
