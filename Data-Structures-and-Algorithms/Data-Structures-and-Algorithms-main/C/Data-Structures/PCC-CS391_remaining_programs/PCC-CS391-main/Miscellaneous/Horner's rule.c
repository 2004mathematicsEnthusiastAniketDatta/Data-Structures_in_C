#include<stdio.h>
#include<stdlib.h>
int horner(int arr[],int n,int x);
int main()
{
	int terms=0,i=0,x=0,sum=0;
	
	printf("\n Enter the degree of polynomial:");
	scanf("%d",&terms);
	int *arr=(int *)malloc(terms*sizeof(int));
	printf("\n Enter the co-efficients in order from higher degree to lower:");
	for(i=0;i<=terms;i++)
	{       
	        printf("\n Enter coefficient of x^%d ",terms-i);
		scanf("%d",&arr[i]);
	}
	printf("\n Enter the value of x:");
	scanf("%d",&x);

	sum=horner(arr,terms,x);
	printf("\n The required result is = %d ",sum);
	return 0;
}
	
int horner(int arr[],int n,int x)
{
	if (n==0)
		return arr[0];
	else
		return arr[n]+x*horner(arr,n-1,x);
}
