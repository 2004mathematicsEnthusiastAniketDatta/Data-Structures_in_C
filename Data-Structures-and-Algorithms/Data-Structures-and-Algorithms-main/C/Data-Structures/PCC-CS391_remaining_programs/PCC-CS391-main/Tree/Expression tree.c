//Expression tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node* left;
    struct node* right;
    struct node* next;
}node;

node* createNode(char x){
    node* p=(node*)malloc(sizeof(node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

void push(node* y,node** head){
    if(*head==NULL)
        *head=y;
    else{
        y->next=*head;
        *head=y;
    }

}
node* pop(node** head){
    node* p= *head;
    *head=(*head)->next;
    return p;
}
int main(){
    node* head=NULL;node* x;node* y;node* z;
    char s[50];
    printf("\nEnter the expression: ");
    fgets(s,50,stdin);
    s[strlen(s) - 1] = '\0';
    int l = strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
            z=createNode(s[i]);
            x=pop(&head);

            y=pop(&head);
            z->left=y;
            z->right=x;
            push(z,&head);
        }
        else{
            z=createNode(s[i]);
            push(z,&head);
        }
    }
    printf("\nInorder expression: ");
    inorder(head);
    return 0;
}
