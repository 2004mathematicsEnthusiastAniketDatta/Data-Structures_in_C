#include <limits.h>
#include <stdio.h>
int matrixChainOrder(int p[],int i, int j){
	if(i==j)
	return 0;
	int k;
	int count;
	int min;
for(k=i;k<j;k++){
	count=MatrixChainOrder(p,i,j)+MatrixChainOrder(p,k+1,j)+p[i-1]*p[k]*p[j];
	if(count<min)
	min=count;
}
return min;
}
}
int main()
{
	int arr[]={1,2,3,4,3};
	int N=sizeof(arr)/sizeof(arr[0]);
	printf("Minimum number of multiplication is %d",MatrixChainOrder(arr,1,N-1));
	getchar();
	return 0;
}
