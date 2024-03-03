#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
void swap(int* a, int* b){
int t;
t=*a;
*a=*b;
*b=t;
}
int partioning(int arr[],int low,int high)
{
    int i,j;
    int pivot=arr[low];
    i=low;
    j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        while(arr[j]>pivot && j>low)
        {
            j--;

        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
int quickSort(int arr[],int low,int high){
if(low<high){

    int partitionIndex=partioning(arr,low,high);
    quickSort(arr,low,partitionIndex-1);
    quickSort(arr,partitionIndex+1,high);
}
}
int main()
{
    int n;
    printf("The range of the array is:");
    scanf("%d",&n);
    int arr[n];
    int i;
    printf("Elements of the Array are:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // printing the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
