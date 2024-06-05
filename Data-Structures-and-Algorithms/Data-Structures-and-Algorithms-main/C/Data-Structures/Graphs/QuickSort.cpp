#include <stdlib.h>
#include<stdio.h>
void swap(int* a, int* b){
	int temp = *a;
	  *a = *b;
	  *b = temp;
}
int partition(int arr[],int low,int high){
	int pivot=arr[low];
	int i=low;
	int j=high;
	while(i<j){
	
	while(arr[i]<=pivot && i<=high-1){
		i++;
	}
    while(arr[j]>=pivot && j>=low+1){
    	j--;
	}
	if(i<j){
		swap(&arr[i],&arr[j]);
     }
   }
	swap(&arr[low],&arr[j]);
    return j;
}

void quicksort(int arr[],int low, int high){
	if(low<high){

	int partitioningIndex=partition(arr,low,high);
	quicksort(arr,low,partitioningIndex-1);
	quicksort(arr,partitioningIndex+1,high);
	}
}
int main(){

 int size;
    printf("Enter the size: ");
    scanf("%d", &size);
 
    int arr[size];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    quicksort(arr, 0, size - 1);
 
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
