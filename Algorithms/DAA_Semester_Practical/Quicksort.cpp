#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void swap(int* a,int* b){
	int temp = *a ;
	     *a = *b;
	     *b = temp;
}
int partition(int arr[],int low,int high){
	int pivot = arr[low];
	int i = low;
	int j = high;
	while(i<j){
		while(arr[i] <= pivot && i <= high - 1){
			i++;
		}
		while(arr[j] >= pivot && j >= low+1){
			j--;
		}
		if(i < j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[j],&arr[low]);
	return j;
}
void quicksort(int arr[],int low,int high){
	if(low<high){
		int partitionIndex = partition(arr,low,high);
		quicksort(arr,low,partitionIndex - 1);
		quicksort(arr,partitionIndex + 1,high);
	}
}
int main(){
	int size;
	printf("Enter the number of elements of the array:");
	scanf("%d",&size);
	int arr[size];
	int i;
	printf("Enter the elements of the array:");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	clock_t start ,end;
	double cpu_time_used;
	start = clock();
	quicksort(arr,0,size-1);
	end = clock();
	cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("The sorted array is:");
     for (i=0;i<size;i++){
     	printf("%d \t",arr[i]);
	 }
	 printf("The time taken by the program is: %f",cpu_time_used);
	 return 0;
}
