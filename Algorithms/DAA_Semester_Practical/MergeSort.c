#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>

void merge(int arr[],int low,int mid,int high){
	int i,j,k,n1,n2;
	n1=mid-low+1;
	n2=high-mid;
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
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
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

void mergesort(int arr[],int si,int ci){
	if(si<ci){
		int mid =(si+ci)/2;
		mergesort(arr,si,mid);
		mergesort(arr,mid+1,ci);
		merge(arr,si,mid,ci);
	}
}
int main(){
	int size;
	printf("Enter the size of the input array:");
	scanf("%d",&size);
	int arr[size];
	int i;
	printf("Enter the elements of the array:\n");
	for(i=0;i<size;i++){
      scanf("%d",&arr[i]);
	}
	clock_t start,end;
	double cpu_time;
	start=clock();
	mergesort(arr,0,size-1);
	end=clock();
	cpu_time=((double) ( end - start))/CLOCKS_PER_SEC;
	printf("The sorted array is:");
	for(i=0;i<size;i++){
		printf("%d \t",arr[i]);
	}
	printf("The time taken by the cpu for the completion of execution of program is : %f\n",cpu_time);
	printf("The space complexity is O(n)");
	return 0;
}
