#include <stdio.h>
#include <stdlib.h>
#define size 100
double a[size];
double min,max;
void maxmin(int i,int j){
   double min1,max1;
   int mid;
	if(i==j)
	{
		max=min=a[i];
	}
	else if (j==i+1)
	{
		if(a[i]<a[j]){
			max=a[j];
			min=a[i];
		}
		else {
			min=a[j];
			max=a[i];
		}
	}
	else{
		mid=(i+j)/2;
		maxmin(i,mid);
		max1 = max, min1 = min;
		maxmin(mid+1,j);
		if(max < max1){
			max = max1;
		}
		if(min>min1){
			min = min1;
		} 
	}
}
int main(){
	 int i, num;
 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&num);
 printf ("Enter the numbers : \n");
 for (i=1;i<=num;i++)
  scanf ("%lf",&a[i]);

 max = a[0];
 min = a[0];
 maxmin(1, num);
 printf ("Minimum element in an array : %lf\n", min);
 printf ("Maximum element in an array : %lf\n", max);
 return 0;
}

