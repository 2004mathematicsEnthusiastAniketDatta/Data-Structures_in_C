#include<stdio.h>
int main()
{
	 int arr[100],n,i,temp,j;
	 printf("Enter the size of the array:\n");
	 scanf("%d",&n);
	 printf("Enter the elements of the array:\n");
	 for(i=0;i<n;i++)
	 {
		  printf("Enter element %d\n",i+1);
		  scanf("%d",&arr[i]);
	 }
	 for(i=1;i<n;i++)
	 {
		  temp=arr[i];
		  j=i-1;
		  while((temp<arr[j])&&(j>=0))
		  {
			   arr[j+1]=arr[j];
			   j--;
		  }
		 arr[j+1]=temp;
	}

	printf("The sorted(insertion sort) array is :\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}

