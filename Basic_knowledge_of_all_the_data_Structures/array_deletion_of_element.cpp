#include <stdio.h>
int main(){
	int arr[10]={9,19,29,39,49,59,69,79};
	
	int key=49,i,j,position,n=8;
	for(i=0;i<n;i++){
		if(arr[i]==key)
//		position=i;
		break;
	
	}
	for (j=i;j<n-1;j++)
	{
		arr[j]=arr[j+1];
	}
for(int x=0;x<n-1;x++){
printf("\t %d \n",arr[x]);	
}
}
