#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}node;

node* insert_front(node* head, int val){
		node* ptr = (node*)malloc(sizeof(node));
		ptr->data = val;
		ptr->prev = NULL;
		ptr->next = NULL;
		if(head != NULL){
				head->prev = ptr;
				ptr->next = head;
		}
		head = ptr;
		printf("%d is inserted at the front\n", val);
		return head;
}

node* insert_end(node* head, int val){
		if(head == NULL){
				head = insert_front(head, val);
		}
		else{
				node* ptr = (node*)malloc(sizeof(node));
				node* p = (node*)malloc(sizeof(node));
				p = head;
				while(p->next != NULL){
						p = p->next;
				}
				ptr->data = val;
				ptr->prev = p;
				p->next = ptr;
				ptr->next = NULL;
				printf("%d is inserted at the end\n", val);
		}
		return head;
}

node* insert_index(node* head, int val, int index){
		if(head == NULL || index == 1){
				head = insert_front(head, val);
		}
		else{
				int i;
				node* ptr = (node*)malloc(sizeof(node));
				node* p = (node*)malloc(sizeof(node));
				p = head;
				for(i=0; i<index-2; i++){
						p = p->next;
						if(p == NULL){
								printf("Index-%d exceeded the length of the Linked list\n",index);
                return head;
						}
				}
				ptr->data = val;
				ptr->prev = p;
				ptr->next = p->next;
				p->next->prev = ptr;
				p->next = ptr;
				printf("%d is inserted at index %d\n",val,index);
		}
		return head;
}

node* delete_front(node* head){
		if(head == NULL){
				printf("\nLinked list is empty\n");
		}
		else{
				node* ptr = (node*)malloc(sizeof(node));
				ptr = head;
				head = head->next;
				head->prev = NULL;
				printf("%d is deleted from the front\n",ptr->data);
				free(ptr);
		}
		return head;
}

node* delete_end(node* head){
		if(head == NULL){
				printf("\nLinked list is empty\n");
		}
		else{
				node* ptr = (node*)malloc(sizeof(node));
				node* p = (node*)malloc(sizeof(node));
				p = head;
				while(p->next->next != NULL){
						p = p->next;
				}
				ptr = p->next;
				p->next = NULL;
				printf("%d is deleted from the end\n",ptr->data);
				free(ptr);
		}
		return head;
}

node* delete_index(node* head, int index){
		if(head == NULL){
				printf("\nLinked list is empty\n");
		}
		else{
				int i;
				node* ptr = (node*)malloc(sizeof(node));
				node* p = (node*)malloc(sizeof(node));
				p = head;
				for(i=0; i<index-2; i++){
						p = p->next;
						if(p == NULL){
								printf("Index-%d exceeded the length of the Linked list\n",index);
                return head;
						}
				}
				ptr = p->next;
				p->next = p->next->next;
				p->next->prev = p;
				printf("%d is deleted from the index %d\n",ptr->data, index);
				free(ptr);
		}
		return head;
}

void display(node* head){
		if (head==NULL){
        printf("\nLinked list is Empty\n");
    }
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = head;
        printf("Displaying the elements : \n");
        while(ptr != NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

node* reverse(node* head){
		node *curr = (node*)malloc(sizeof(node));
		node* temp = (node*)malloc(sizeof(node));
		curr = head;
		temp = NULL;
		while(curr != NULL){
				temp = curr->prev;
				curr->prev = curr->next;
				curr->next = temp;
				curr = curr->prev;
		}
		printf("Linked list is Reversed\n");
		if(temp != NULL){
				return temp->prev;
		}
}

int main(){
	
	node* head = NULL;
	int choice;
	int val, index;
	printf("Menu for the Doubly Linked List : \n");
	printf("1 -> Insert_Front\n2 -> Insert_End\n3 -> Insert_Index\n4 -> Delete_Front\n5 -> Delete_End\n6 -> Delete_Index\n");
	printf("7 -> Display\n8 -> Reverse\n9 -> Exit\n");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d", &val);
				head = insert_front(head, val);
				break;
			case 2:
				printf("Enter the value to be inserted : ");
				scanf("%d", &val);
				head = insert_end(head, val);
				break;
			case 3:
				printf("Enter the value to be inserted : ");
				scanf("%d", &val);
				printf("Enter the index : ");
				scanf("%d", &index);
				head = insert_index(head, val, index);
				break;
			case 4:
				head = delete_front(head);
				break;
			case 5 :
        			head = delete_end(head);
        			break;
			      case 6:
				int index;
			      	printf("Enter the index : ");
			     		scanf("%d", &index);
			      	head = delete_index(head, index);
				 break;
					  case 7:
					    display(head);
					    break;
					 	case 8:
			       	head = reverse(head);
				break;  
					  case 9:
					    exit(0);
					    break;
					  default:
				printf("\nWrong choice\n");
					}
	}
	return 0;
}
