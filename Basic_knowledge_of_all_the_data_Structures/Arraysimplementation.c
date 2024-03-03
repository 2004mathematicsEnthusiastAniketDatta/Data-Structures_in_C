#include <stdio.h>
int main(){
   
printf("Enter the Range of the array: \n");
 int n;
scanf("%d",&n);
int arr[n-1];
int i,j;
printf("Enter elements of the array: \n");
for (i = 0; i<=n-1; i++){
    scanf("\t %d \n",&arr[i]);
}
for ( j = 0; j<=n-1; j++)
{
 printf("\t %d",arr[j]);
}
return 0;
}


