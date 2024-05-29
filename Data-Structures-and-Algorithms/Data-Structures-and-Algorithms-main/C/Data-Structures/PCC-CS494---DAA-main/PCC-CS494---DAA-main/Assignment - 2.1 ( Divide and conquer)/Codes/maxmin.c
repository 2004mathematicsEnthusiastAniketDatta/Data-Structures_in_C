#include<stdio.h>
#include<stdlib.h>

int max_element(int arr[], int start, int end)
{
	int max = arr[0];
	int mid = start + (end-start)/2;
	if (start == end)
		return arr[start];
	if(start==end-1)
		return((arr[start]>arr[end])?arr[start]:arr[end]);
	int max1 = max_element(arr,start,mid-1);
	int max2 = max_element(arr,mid,end);
	return((max1>max2)?max1:max2);
}

int min_element(int arr[], int start, int end)
{
	int min = arr[0];
	int mid = start + (end-start)/2;
	if (start == end)
		return arr[start];
	if(start==end-1)
		return((arr[start]>arr[end])?arr[end]:arr[start]);
	int min1 = min_element(arr,start,mid-1);
	int min2 = min_element(arr,mid,end);
	return((min1>min2)?min2:min1);
}

int main()
{
	int n,i;
	printf("\nEnter length of array: ");
	scanf("%d",&n);
	int *arr = (int*)malloc(n*sizeof(int));
	printf("\nEnter array elements:");
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nThe maximum element is:%d ",max_element(arr,0,n-1));
	printf("\nThe minimum element is:%d ",min_element(arr,0,n-1));
}

