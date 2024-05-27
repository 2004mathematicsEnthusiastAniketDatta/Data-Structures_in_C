#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
	int arr[MAX];
	int top;
}stack;
void init(stack* s)
{
	s->top=-1;
}
int isEmpty(stack* s)
{
	return s->top==-1;
}
void push(stack* s,int x)
{
	if(s->top>=MAX-1)
	{
		printf("\nStack overflow");
		exit(1);
	}
	s->arr[++(s->top)]=x;
}
int pop(stack* s)
{
	if(isEmpty(s))
	{
		printf("\nunderflow");
		return -1;
	}
	return s->arr[(s->top)--];
}
void bubble(int a[],int n)
{
	stack s1,s2;
	init(&s1);
	init(&s2);
	for(int i=0;i<n;i++)
		push(&s1,a[i]);
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			while(!isEmpty(&s1))
			{
				int t=pop(&s1);
				if(isEmpty(&s2))
					push(&s2,t);
				else
				{
					if(s2.arr[s2.top]>t)
					{
						int temp=pop(&s2);
						push(&s2,t);
						push(&s2,temp);
					}
					else
					{
						push(&s2,t);
					}
				}
			}
			a[n-1-i]=pop(&s2);
		}
		
		else{
			while(!isEmpty(&s2))
			{
				int t=pop(&s2);
				if(isEmpty(&s1))
					push(&s1,t);
				else
				{
					if(s1.arr[s1.top]>t)
					{
						int temp=pop(&s1);
						push(&s1,t);
						push(&s1,temp);
					}
					else
					{
						push(&s1,t);
					}
				}
			}
			a[n-1-i]=pop(&s2);
		}
		
	}
	printf("\nThe sorted array:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void main()
{
	int a[]={2,6,3,4,8,9,1};
	int n = sizeof(a) / sizeof(a[0]);
	
	bubble(a,n);
}

