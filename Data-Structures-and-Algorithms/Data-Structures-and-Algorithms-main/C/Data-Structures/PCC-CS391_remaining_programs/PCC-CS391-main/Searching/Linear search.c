#include<stdio.h>
void main()
{
int arr[100];
int size,i,num,c=0;
printf("\nEnter the size of the array: ");
scanf("%d",&size);
printf("\nEnter array elements:");
for(i=0;i<size;i++)
scanf("%d",&arr[i]);
printf("\n Enter the element to be searched: ");
scanf("%d",&num);
for(i=0;i<size;i++)
{
if (num == arr[i])
{
printf("\n Element found at %d location ",(i+1));
c++;
}
}
if (c==0)
printf("\n Element not found");
else
printf("\n Element appeared %d times",c);
}
