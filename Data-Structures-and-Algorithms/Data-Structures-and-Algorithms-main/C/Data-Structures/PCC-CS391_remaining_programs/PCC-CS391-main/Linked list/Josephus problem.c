#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
	int front;
	int rear;
}queue;

typedef struct Node{
	int data;
	struct Node *next;
}node;

void insert_end(node **head, int data){
	node *ptr = (node*) malloc (sizeof(node));
    ptr->data = data;
    if ((*head)->next == NULL){
		(*head)->next = ptr;
        ptr->next = ptr;
    }
    else {
        node *p = (node*) malloc (sizeof(node));
        p = (*head)->next;
        while(p->next != (*head)->next) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = (*head)->next;
    }
    return;
}

int delete_front(node **head) {
    node *ptr = (node*) malloc (sizeof(node));
    ptr = (*head)->next;
    if (ptr->next == ptr){
        (*head)->next = NULL;
    }
    else{
        node *p = (node*) malloc (sizeof(node));
        p = (*head)->next;
        while (p->next != (*head)->next) {
            p = p->next;
        }
        p->next = ptr->next;
        (*head)->next = ptr->next;
    }
    int data = ptr->data;
    free(ptr);
    
    return data;
}

void initialize(queue *q){
	q->front = q->rear = -1;
}

void enqueue(queue *q,node *head){
	int data;
	printf("Enter the data : ");
	scanf("%d",&data);
	insert_end(&head,data);
	if(head->next == NULL){
		q->front = q->rear = 0;
	}
	else{
		q->rear++;
	}
	printf("\n%d is inserted at rear position.\n",data);
}

int dequeue(queue *q,node *head){
	if (head->next == NULL){
        printf("\nQueue underflow!\n");
        return 0x0000;
    }
	else{
		int data = delete_front(&head);
		if(q->front == q->rear){
			initialize(q);
		}
		else{
			q->front++;
		}
		return data;
	}
}

void display(node *head) {
    if (head->next == NULL){
        printf("\nQueue is empty!\n");
        return;
    }
    node *ptr = (node*) malloc (sizeof(node));
    ptr = head->next;
    printf("\nDisplaying the elements of the Queue :\n");
    while(ptr->next != head->next) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->data);
}

void josephus(){
    int n,m,i;
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    printf("\nEnter the number of peoples : ");
    scanf("%d",&n);
    printf("Enter the value of step : ");
    scanf("%d",&m);
    for(i=1;i<=n;i++){
        insert_end(&head,i);
    }
    node *ptr = (node*)malloc(sizeof(node));
    ptr = head;
    while(ptr->next != ptr){
        for(i=1;i<=m-1;i++){
            ptr = ptr->next;
        }
        if (ptr->next != ptr) {
            node *p = (node*)malloc(sizeof(node));
            p = ptr->next;
            ptr->next = p->next;
            free(p);
        }
    }
    printf("\nperson-%d will survive.\n",ptr->data);
}

void main(){
	int n,data;
	node *head = (node*)malloc(sizeof(node));
	head->next = NULL;
	queue q;
	initialize(&q);
	
	do{
		printf("\nMenu for Queue : \n");
		printf("1 => Enqueue\n2 => Dequeue\n");
		printf("3 => Display\n4 => Josephus Problem\n");
		printf("0 => Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&n);
		switch(n){
			case 1:
				enqueue(&q,head);
				break;
			case 2:
				data = dequeue(&q,head);
				if(data != 0x000){
					printf("\n%d is deleted from the queue.\n",data);
				}
				break;
			case 3:
				display(head);
				break;
			case 4 :
			    josephus();
			    break;
			case 0:
				printf("\nTerminating the program.\n");
				break;
			default:
				printf("\nInvalid input : Try again!\n");
				break;
		}
	}while(n != 0);
}