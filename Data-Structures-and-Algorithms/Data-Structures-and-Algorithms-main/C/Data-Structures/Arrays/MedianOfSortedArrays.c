#include <stdio.h>
#include <stdlib.h>
double median(int a1[],int a2[],int n1,int n2)
{
    int i=0,j=0,k=0,a3[n1+n2];
    double median;
	while(i<n1&&j<n2)
    {
        if(a1[i]<a2[j])
        {
            a3[k++] = a1[i++];
        }
        else
        {
            a3[k++] = a2[j++];
        }
    }
    while(i < n1)
    {
        a3[k++] = a1[i++];
    }
    while(j < n2)
    {
        a3[k++] = a2[j++];
    }
 	if((n1+n2)%2==1)
 		median=a3[(n1+n2)/2];
	else
 		median=(a3[(n1+n2-1)/2]+a3[(n1+n2)/2])/2.0; 
    return median;
}
int main()
{
    int n1,n2,i,j;
    printf("\nEnter the size of Array 1 : ");
    scanf("%d",&n1);
    printf("\nEnter the size of Array 2 : ");
    scanf("%d",&n2);
    int a1[n1],a2[n2];
    printf("\nEnter the %d sorted elements in Array1:\n",n1);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("\nEnter the %d sorted elements in Array2:\n",n2);
    for(i=0;i<n2;i++)
    {
        scanf("%d",&a2[i]);
    }
	printf("\nThe Median of two Sorted Arrays is : ");
    printf("%.2f ",median(a1,a2,n1,n2));
    return 0;
}
