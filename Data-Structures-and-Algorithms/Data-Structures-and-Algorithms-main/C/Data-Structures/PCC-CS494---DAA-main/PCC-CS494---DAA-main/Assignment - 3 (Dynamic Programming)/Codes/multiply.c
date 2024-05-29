#include <stdio.h>
#include <string.h>
#include <limits.h>


int eva(int arr[],int i,int j,int n,int val[][n],int pan[][n]){
	if(i==j){
		val[i][j] = 0;
		return 0;
	}
	else{
		if(val[i][j] != -1){
			return val[i][j];
		}
		else{
			int k,t,x=INT_MAX;
			for(k=i;k<j;k++){
				t = eva(arr,i,k,n,val,pan)+eva(arr,k+1,j,n,val,pan)+(arr[i]*arr[k+1]*arr[j+1]);
				if(t<x){
					x = t;
					pan[i][j] = k;
				}
			}
			val[i][j] = x;
			return x;
		}
	}
}

void opt_pan(int i,int j,int n,int pan[][n]){
	static int c = 1;
	int k = pan[i][j];
	if(i==k){
		printf("A%d",c++);
	}
	else if(k-i == 1){
		printf("(A%d * ",c++);
		printf("A%d)",c++);
	}
	else{
		printf("(");
		opt_pan(i,k,n,pan);
		printf(")");
	}
	printf(" * ");
	if(k+1 == j){
		printf("A%d",c++);
	}
	else if(j - k+1 == 1){
		printf("(A%d * ",c++);
		printf("A%d)",c++);
	}
	else{
		printf("(");
		opt_pan(k+1,j,n,pan);
		printf(")");
	}
}

void main(){
	int n,i,j;
	printf("Enter the number of matrices : ");
	scanf("%d",&n);
	int arr[n+1];
	for(i=0;i<=n;i++){
		printf("Enter arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	int val[n][n];
	int pan[n][n];
	memset(val,-1,sizeof(val));
	memset(pan,-1,sizeof(pan));
	int ans = eva(arr,0,5,n,val,pan);
	
	printf("\nDisplaying the matrix for minimum multiplication: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",val[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
    printf("\nDisplaying the matrix for optimal parenthesization: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",pan[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Minimum multiplication required = %d\n",ans);
	printf("Optimal parenthesization : \n(");
	opt_pan(0,n-1,n,pan);
    printf(")\n");
}









