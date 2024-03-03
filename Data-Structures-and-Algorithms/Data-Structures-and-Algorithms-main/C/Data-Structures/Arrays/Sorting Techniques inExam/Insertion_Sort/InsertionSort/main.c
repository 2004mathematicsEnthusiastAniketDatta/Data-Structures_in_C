#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int insertionSort(int arr[], int n)
{
     int i,j,key;
     for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=00 && arr[j]>key)
        {

               arr[j+1]=arr[j];
               j=j-1;
        }
        arr[j+1]=key;
     }


}

void printArray(int arr[], int n)
{
     int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

}
int main()
{
    int n;
    printf("The Range of the array:");
    scanf("%d",&n);
    int arr[n];
    int i;
    printf("The elements of the array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}
