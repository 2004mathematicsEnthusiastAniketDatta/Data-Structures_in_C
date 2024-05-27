#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

typedef struct stack
{
    node *data;
    struct stack *next;
}stack;

typedef struct queue{
    node *data;
    struct queue *next;
}queue;

node *createnode(int key){
    node *new = (node*)malloc(sizeof(node));
    new->data = key;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int isEmpty(stack *top){
    if (top == NULL)
        return 1;
    return 0;
}

int isQueueEmpty(queue *front){
    if (front == NULL)
        return 1;
    return 0;
}

void push(stack **top,node *new){
    stack *temp = (stack*) malloc (sizeof(stack));
    temp->data = new;
    temp->next = *top;
    *top = temp;
}

node *pop(stack **top){
    node *ptr = (node*) malloc (sizeof(node));
    stack *temp = (stack*) malloc (sizeof(stack));
    temp = *top;
    *top = temp->next;
    ptr = temp->data;
    free(temp);
    return ptr;
}

void enqueue(queue **front,queue **rear,node *new){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->data = new;
    temp->next = NULL;
    if (isQueueEmpty(*front)){
        *front = temp;
        *rear = temp;
    }
    else{
        (*rear)->next = temp;
        *rear = temp;
    }
}

node* dequeue(queue **front,queue **rear){
    queue *temp = (queue*)malloc(sizeof(queue));
    node *ptr = (node*)malloc(sizeof(node));
    temp = *front;
    ptr = temp->data;
    if(temp->next == NULL){
        *front = *rear = NULL;
    }
    else{
        *front = temp->next;
    }
    free(temp);
    return ptr;
}

int queue_size(queue *front,queue *rear){
    int size;
    if (isQueueEmpty(front)){
        size = 0;
    }
    else {
        queue *ptr = (queue*)malloc(sizeof(queue));
        ptr = front;
        size = 1;
        while(ptr!=rear){
            size++;
            ptr = ptr->next;
        }
    }
    return size;
}

int getHeight(node *root){
    if(root == NULL){
        return 0;
    }
    node *ptr = (node*)malloc(sizeof(node));
    ptr = root;
    queue *front = (queue*)malloc(sizeof(queue));
    queue *rear = (queue*)malloc(sizeof(queue));
    front = rear = NULL;
    int h = 0;
    int count = 0;
    enqueue(&front,&rear,ptr);
    while(!isQueueEmpty(front)){
        h++;
        count = queue_size(front,rear);
        while(count--){
            ptr = front->data;
            if (ptr->left != NULL){
                enqueue(&front,&rear,ptr->left);
            }
            if (ptr->right != NULL){
                enqueue(&front,&rear,ptr->right);
            }
            dequeue(&front,&rear);
        }
    }
    return h;
}

int max(int a, int b){
    return (a>b)?a:b;
}

node *rightRotate(node *y){
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

node *leftRotate(node *x){
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

int getBalance(node *temp){
    if (temp == NULL){
        return 0;
    }
    return getHeight(temp->left) - getHeight(temp->right);
}

void preOrder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

node *rotate(node *root,node *temp){
    node *ptr = (node*)malloc(sizeof(node));
    node *q = (node*)malloc(sizeof(node));
    node *p = (node*)malloc(sizeof(node));
    q = NULL;
    p = NULL;
    int bf;
    int key = temp->data;
    ptr = root;
    stack *top = (stack*)malloc(sizeof(stack));
    top = NULL;
    while(ptr!=NULL){
        push(&top,ptr);
        if(key < ptr->data){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    while(!isEmpty(top)){
        ptr = pop(&top);
        bf = getBalance(ptr);
        if ((bf < -1) || (bf > 1)){
            p = ptr;
            if (!isEmpty(top)){
                q = pop(&top);
            }
            break;
        }
    }
    if(q == NULL && p==NULL){
        return root;
    }
    bf = getBalance(p);
    if (bf>1 && (p->left->data > key)){
        if(p == root && q == NULL){
            (root) = rightRotate(p);
        }
        else if(p!=NULL && q!=NULL){
            q->left = rightRotate(p);
        }
    }
    else if (bf<-1 && (p->right->data < key)){
        if(p == root && q == NULL){
            (root) = leftRotate(p);
        }
        else if(p!=NULL && q!=NULL){
            q->right = leftRotate(p);
        }
    }
    else if (bf > 1 && key > ptr->left->data){
        if(p == root && q == NULL){
            p->left =  leftRotate(p->left);
            (root) = rightRotate(p);
        }
        else if(p!=NULL && q!=NULL){
            p->left =  leftRotate(p->left);
            q->left = rightRotate(p);
        }
    }
    else if (bf <-1 && key < p->right->data){
        if(p == root && q == NULL){
            p->right = rightRotate(p->right);
            (root) = leftRotate(p);
        }
        else if(p!=NULL && q!=NULL){
            p->right = rightRotate(p->right);
            q->right = leftRotate(p);
        }
    }
    return root;
}

void insert(node **root,int key){
    if ((*root) == NULL) {
        *root = createnode(key);
        printf("\n%d is insetred as the root of thr tree.\n",key);
        return;
    }
    node *ptr = (node*)malloc(sizeof(node));
    node *q = (node*)malloc(sizeof(node));
    q = NULL;
    ptr = *root;
    while(ptr!=NULL){
        q = ptr;
        if(key == ptr->data){
            printf("\nInvalid Input : Duplicate Element.\n");
            return;
        }
        else if(key < ptr->data){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    ptr = createnode(key);
    if (key < q->data){
        q->left = ptr;
    }
    else{
        q->right = ptr;
    }
    *root = rotate(*root,ptr);
    printf("\n%d is insetred in the tree.\n",key);
}

int main()
{
    node *root = (node*)malloc(sizeof(node));
    root = NULL;
    int n,key;
    do{
        printf("\nMenu for AVL : \n");
        printf("1 => Insert\n2 => Preorder\n3 => Inorder\n4 => Postorder\n");
        printf("0 = >Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n){
            case 1 :
                printf("Enter the data : ");
                scanf("%d",&key);
                insert(&root,key);
                break;
            case 2 :
                printf("\nThe AVL tree is : \n");
                printf("Preorder : ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
            	printf("\nThe AVL tree is : \n");
                printf("Inorder : ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
            	printf("\nThe AVL tree is : \n");
                printf("Postorder : ");
                postOrder(root);
                printf("\n");
                break;
            case 0:
                printf("\nTerminating the program.\n");
                break;
            default : 
                printf("\nInvalid Input!\n");
                break;
        }
    }while(n!=0);
    return 0;
}
