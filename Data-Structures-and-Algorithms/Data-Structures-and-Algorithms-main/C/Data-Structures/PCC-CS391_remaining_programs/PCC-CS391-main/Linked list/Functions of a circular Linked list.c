#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node* insert_front(node* head, int data){
    node *ptr = (node*) malloc (sizeof(node));
    if(ptr == NULL){
    	printf("\nOverflow\n");
    	return head;
    }
    ptr->data = data;
    if (head->next == NULL){
        head->next = ptr;
        ptr->next = ptr;
    }
    else{
        node *p = (node*) malloc (sizeof(node));
        p = head->next;
        while(p->next != head->next){
            p = p->next;
        }
        ptr->next = head->next;
        head->next = ptr;
        p->next = ptr;
    }
    return head;
}

node* insert_end(node *head, int data){
	node *ptr = (node*) malloc (sizeof(node));
	if(ptr == NULL){
    	printf("\nOverflow\n");
    	return head;
    }
    if (head->next == NULL){
        head = insert_front(head,data);
    }
    else {
        ptr->data = data;
        node *p = (node*) malloc (sizeof(node));
        p = head->next;
        while(p->next != head->next) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head->next;
    }
    return head;
}

node* insert_index(node *head,int index,int data) {
	node *ptr = (node*) malloc (sizeof(node));
	if(ptr == NULL){
    	printf("\nOverflow\n");
    	return head;
    }
    if (index == 0) {
        head = insert_front(head,data);
        printf("\n%d is inserted at index-%d of the list.\n",data,index);
        return head;
    }
    int count,i;
    node *p = (node*) malloc (sizeof(node));
    p = head->next;
    if(p == NULL){
        count = 0;
        printf("\nList is empty : Index should be 0\n");
        return head;
    }
    else{
        count = 1;
    }
    while(p->next != head->next) {
        count++;
        p = p->next;
    }
    printf("count = %d\n",count);
    if (index > count) {
        printf("\nIndex-%d exceeded length of the list i.e. %d\n",index,count);
        return head;
    }
    if (index == count){
        head = insert_end(head,data);
    }
    else {
        p = head->next;
        ptr->data = data;
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    printf("\n%d is inserted at index-%d of the list.\n",data,index);
    return head;
}

node *delete_front(node *head) {
    if (head->next == NULL){
        printf("\nList is empty!\n");
    }
    else {
        node *ptr = (node*) malloc (sizeof(node));
        ptr = head->next;
        if (ptr->next == ptr){
            head->next = NULL;
        }
        else{
            node *p = (node*) malloc (sizeof(node));
            p = head->next;
            while (p->next != head->next) {
                p = p->next;
            }
            p->next = ptr->next;
            head->next = ptr->next;
        }
        int data = ptr->data;
        printf("\n%d is deleted from the front of the list.\n",data);
        free(ptr);
    }
    return head;
}

node* delete_end(node *head) {
    if (head->next == NULL){
        printf("\nList is empty!\n");
    }
    else {
        int data;
        node *ptr = (node*) malloc (sizeof(node));
        ptr = head->next;
        if (ptr->next == ptr) {
            head->next = NULL;
            data = ptr->data;
            printf("\n%d is deleted from the end of the list.\n",data);
            free(ptr);
            return head;
        }
        node *p = (node*) malloc (sizeof(node));
        p = ptr;
        ptr = ptr->next;
        while (ptr->next != head->next) {
            ptr = ptr->next;
            p = p->next;
        }
        p->next = head->next;
        data = ptr->data;
        printf("\n%d is deleted from the end of the list.\n",data);
        free(ptr);
    }
    return head;
}

node* delete_index(node *head,int index) {
    if (head->next == NULL){
        printf("\nList is empty!\n");
        return head;
    }
    if(index == 0){
        printf("Index=%d means deletion from front :\n",index);
        head = delete_front(head);
        return head;
    }
    int count = 1,i;
    node *ptr = (node*) malloc (sizeof(node));
    node *p = (node*) malloc (sizeof(node));
    p = head->next;
    while(p->next != head->next) {
        count++;
        p = p->next;
    }
    if (index >= count) {
        printf("\nIndex-%d exceeded the highest index i.e. %d\n",index,count-1);
        return head;
    }
    if (index == count-1){
        printf("Index=%d means deletion from end :\n",index);
        head = delete_end(head);
        return head;
    }
    p = head->next;
    for(i=0;i<index-1;i++){
        p = p->next;
    }
    ptr = p->next;
    p->next = ptr->next;
    int data = ptr->data;
    printf("\n%d is deleted from index-%d of the list.\n",data,index);
    free(ptr);
    return head;
}

void display(node *head) {
    if (head->next == NULL){
        printf("\nList is empty!\n");
        return;
    }
    node *ptr = (node*) malloc (sizeof(node));
    ptr = head->next;
    printf("\nDisplaying the elements of the list :\n");
    while(ptr->next != head->next) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->data);
}

node* insert(node* head){
    int n,data,index;
    do{
        printf("\nMenu for insertion : \n");
        printf("1 => Insert at front\n");
        printf("2 => Insert at end\n");
        printf("3 => Insert at index\n");
        
        printf("0 => Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
                printf("Enter the data : ");
                scanf("%d",&data);
                head = insert_front(head,data);
                printf("\n%d is inserted at the front of the list.\n",data);
                break;
            case 2 :
                printf("Enter the data : ");
                scanf("%d",&data);
                head = insert_end(head,data);
                printf("\n%d is inserted at the end of the list.\n",data);
                break;
            case 3 :
                printf("Enter the index : ");
                scanf("%d",&index);
                printf("Enter the data : ");
                scanf("%d",&data);
                head = insert_index(head,index,data);
                break;
            
            case 0 :
                printf("\nClosing the menu for insertion.\n");
                break;
            default :
                printf("\nInvalid Input : Try again!\n");
                break;
        }
    }while(n!=0);
    return head;
}

node* delete(node* head){
    int n,index;
    do{
        printf("\nMenu for deletion : \n");
        printf("1 => Delete from front\n");
        printf("2 => Delete from end\n");
        printf("3 => Delete from index\n");
        
        printf("0 => Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
                head = delete_front(head);
                break;
            case 2 :
                head = delete_end(head);
                break;
            case 3 :
                printf("Enter the index : ");
                scanf("%d",&index);
                head = delete_index(head,index);
                break;
            
            case 0 :
                printf("\nClosing the menu for deletion.\n");
                break;
            default :
                printf("\nInvalid Input : Try again!\n");
                break;
        }
    }while(n!=0);
    
    return head;
}

void main ()
{
    node *head = (node*)malloc(sizeof(node));
    head->next=NULL;
    int n;
    do
    {
        printf ("\nMenu for Linked list : \n");
        printf ("1 => Insertion\n2 => Deletion\n3 => Display\n0 => Exit\n");
        printf ("Enter your choice : ");
        scanf ("%d", &n);
        switch(n)
        {
            case 1 :
                head = insert(head);
                break;
            case 2 :
                head = delete(head);
                break;
            case 3 :
                display(head);
                break;
            case 0 :
                printf("\nTerminating the program.\n");
                break;
            default :
                printf("\nInvalid Input : Try again!\n");
                break;
        }
    }
    while (n != 0);
}
