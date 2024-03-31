#include <stdio.h>
#include<stdio.h>
int min,max;
int arr[1000];
void minmax(int i,int j){
	int min1,max1,mid;
	if (i==j){
		max=min=arr[i];
	}
	else if (j==(i-1)){
		if(arr[i]<arr[j]){
			min=arr[i];
			max=arr[j];
		}
		else {
			min=arr[j];
			max=arr[i];
		}
	}
	else {
		mid=(i+j)/2;
		minmax(i,mid);
		min1=min;
		max1=max;
		minmax(mid+1,j);
		if(min>min1)
		min=min1;
		if(max<max1)
		max=max1;
	}
}
int main(){
	int i,num;
	printf("\nEnter the number of numbers :");
	scanf("%d",&num);
	printf("Enter the numbers: \n");
	for(int i=1;i<=num;i++){
		scanf("%d",&arr[i]);	
	}
	min=arr[0];
	max=arr[0];
	minmax(1,num);
	printf("Minimum element in an array:%d\n",min);
	printf("Maximum element in an array: %d\n",max);
	return 0;
}
