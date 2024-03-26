#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
void merge(int arr[],int low,int mid,int high){
	int i,j,k;
	int n1=mid-low+1;
	int n2=high-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=arr[low+i];
	}
	for(j=0;j<n2;j++){
		R[j]=arr[mid+1+j];
	}
	i=0;
	j=0;
	k=low;
	while(i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else { 
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int si,int ci)
{
	if(si<ci)
	{
		int mid=(si+(ci))/2;
		mergeSort(arr,si,mid);
		mergeSort(arr,mid+1,ci);
		merge(arr,si,mid,ci);
	}
}
void printArray(int A[], int size)
{

    printf("\n");
}
int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
 
    int arr[size];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    mergeSort(arr, 0, size - 1);
 
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

