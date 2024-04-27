#include<stdio.h>
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void insertionsort( int arr[],int n){
    int temp,i ,j;
       for(i =1;i<=n-1;i++){
        temp=arr[i];
         j=i-1;
         while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
         }
         arr[j+1]=temp;
    }
}
int main(){
    // -1  0   1   2   3   4   5
    //     12,|54, 65, 7,  23,  9 --> i=1,temp=54,j=o
    //     12,|54, 65, 7,  23,  9 --> ist pass done (i=1)

    //     12, 54, |65, 7,  23,  9 --> i=2,temp=65,j=1
    //     12,54, |65, 7,  23,  9 --> 2nd pass done (i=2)

    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 
       
    int arr[]={12,54,65,7,23,9};
    int n=6;
    printarray(arr,n);
    insertionsort(arr,n);
    printarray(arr,n);

    return 0;
}
