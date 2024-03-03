#include <stdio.h>
#include <stdbool.h>
#define MAX 5
#define MIN -1
int stack[MAX];
int top=-1;


bool notOverflow(){
	if(top+1<MAX)
	return true;
return false;
}

//bool notOverflow()
//{
//	if(top+1 < MAX)
//	return true;
//return false;
//}

bool notUnderflow(){
	if(top!=MIN)
	  return true;
	return false;
}

void printStack(){
	if(notUnderflow())
	{
		for(int i=0;i<=top;i++){
			printf("\n\t%d ",stack[i]);
		}
}
	else
	{
		printf("\n\tSTACK UNDERFLOW\n\t");
	}
	printf("\n\t \n\n");
	return;
}

void pop(){
	if(notUnderflow()){
		printf("\n\t\n Popped Value: %d\n",stack[top--]);}
		else
		{
			printf("\n\tSTACK UNDERFLOW\n\t");
		}
	}
void push(int value){
	if (notOverflow())
	stack[++top]=value;
	else
	{
		printf("\n\tSTACK OVERFLOW\n\t");
	}
}
void peek(){
	if(notUnderflow()){	
	printf("\n\t\nPeekValue\n",stack[top]);
	}
	else
	{
				printf("\n\tSTACK UNDERFLOW\n\t");	
	}
}
int main(){
	push(10);
	peek();
	push(20);
	peek();
	push(30);
	peek();
	push(40);
	peek();
	push(60);
	peek();
	
	pop();
	peek();
	pop();
	peek();
	pop();
	peek();
	pop();
	peek();
	pop();
	peek();
	pop();
	peek();
	return 0;
}
