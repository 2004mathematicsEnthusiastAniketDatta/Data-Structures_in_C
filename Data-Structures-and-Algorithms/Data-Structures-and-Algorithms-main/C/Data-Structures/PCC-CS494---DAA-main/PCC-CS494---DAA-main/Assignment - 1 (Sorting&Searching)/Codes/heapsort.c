//heap_sort Using Divide And Conquer
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void display(int *arr, int size){
	int i;
	printf("\nThe list of elements:\n");
	for(i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
}

void heapify(int arr[], int i, int size) {
	int largest=i;
	int leftChild=2*i+1;
	int rightChild=2*i+2;
	
	if(leftChild<size && arr[largest]<arr[leftChild])
	largest=leftChild;
	if(rightChild<size && arr[largest]<arr[rightChild])
	largest=rightChild;
	
	if(largest!=i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, largest, size);
	}
}

void heapsort(int arr[], int size) {
	int i;
	for(i=size/2-1; i>=0; i--)
	heapify(arr, i, size);
	
	for(i=size-1; i>=0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, 0, i);
	}
}

void main(){
	int i,size;
	printf("\nEnter the no. of elements: ");
	scanf("%d", &size);
	
	int arr[size];
	printf("Enter the array: ");
	
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	display(arr, size);
	heapsort(arr, size);
	printf("\nSorted: ");
	display(arr, size);
	printf("\n");
	
}
