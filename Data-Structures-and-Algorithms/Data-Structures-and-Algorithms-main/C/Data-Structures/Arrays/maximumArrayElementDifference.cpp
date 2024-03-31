#include<stdio.h>
#include <stdlib.h>
/* The function assumes that there are at least two
elements in array.
The function returns a negative value if the array is
sorted in decreasing order. 
Returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size)
{	 
int max_diff = arr[1] - arr[0];
int i, j;
for (i = 0; i < arr_size; i++)
{
	for (j = i+1; j < arr_size; j++)
	{	 
	if (arr[j] - arr[i] > max_diff) 
		max_diff = arr[j] - arr[i];
	} 
}		 
return max_diff;
} 

/* Driver program to test above function */
int main()
{
int arr[] = {1, 2, 90, 10, 110};
printf("Maximum difference is %d", maxDiff(arr, 5));
getchar();
return 0;
}

