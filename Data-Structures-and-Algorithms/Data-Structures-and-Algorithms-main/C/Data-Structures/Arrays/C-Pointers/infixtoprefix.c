#include <stdio.h>
#include <stdlib.h>
#define M 100

struct Stack{
    char ele;
    struct Stack *next;
};

struct Stack* next_node(char element){
    struct Stack *node=(struct Stack *)malloc(sizeof(struct Stack));
    node->ele=element;
    node->next=NULL;
    return node;
}

int isEmpty(struct Stack *node){
    return node==NULL;
}

void push(struct Stack **node, char element){
    struct Stack *temp=next_node(element);
    temp->next=*node;
    *node=temp;
}

char pop(struct Stack **node){
    if(isEmpty(*node)){
        return 0;
    }
    struct Stack *temp=*node;
    *node=(*node)->next;
    char revc=temp->ele;
    free(temp);
    return revc;
}

char* rev(char str[]){
    int i, n;
    for(n=0;str[n]!='\0';n++);
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    for(i=0;i<n;i++)
        push(&s, str[i]);
    for(i=0;i<n;i++)
        str[i]=pop(&s);
        if(str[i]=='(')
            str[i]=')';
        else if(str[i]==')')
            str[i]='(';
    return str;
}

int isVariable (char ch){
    return (ch>='a' && ch<='z')||(ch>='A'&&ch<='Z');
}

int precedence(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1;
}

char* postfix(char str[]){
    int i, j=0;
    struct Stack *s=NULL;
    for(i=0;str[i]!='\0';i++){
        if(isVariable(str[i]))
            str[j++]=str[i];
        else if(str[i]==')')
            push(&s, str[i]);
        else if(str[i]=='('){
            while(!isEmpty(s)&&s->ele!=')')
                str[j++]=pop(&s);
            if(!isEmpty(s)&&s->ele!=')')
                return 0;
            else
                pop(&s);
        }
        else{
            while(!isEmpty(s)&&precedence(str[i])<=precedence(s->ele))
                str[j++]=pop(&s);
            push(&s, str[i]);
        }
    }
    while(!isEmpty(s))
        str[j++]=pop(&s);
    str[j++]='\0';
    return str;
}

void prefix(char str[]){
    str=rev(str);
    str=postfix(str);
    str=rev(str);
    printf("The prefix equivalent is: %s\n", str);
}

int main()
{
    char string[M], op[1];
    do{
        printf("Enter the infix expression: ");
        scanf("%s", string);
        prefix(string);
        printf("Do you want to go again?(Y/N): ");
        scanf("%s", op);
    }while(op[0]=='Y');
}