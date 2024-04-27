#include<stdio.h>
int linearsearch(int arr[],int n, int elements){
    for(int i=0;i<n;i++){
        if(arr[i]== elements)
          return i;
    }
}
int binarysearch(int arr[], int n, int elements){
int low,mid,high;
low=0;
high=n;
 while(low<=high){
    mid = (low+high)/2;
    if(arr[mid]==elements){
        return mid;
    }
    else if(arr[mid]<elements){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    return -1;
 }
//  searching index
//  return -1;
}
int main(){
    int arr[100]={5,7,9,10,13,17,25,15,20};
  int size=sizeof(arr)/sizeof(int);
//    display(arr,size);
   int elements=13;
    int c =linearsearch(arr,size,elements);
    printf("position of %d elements is %d\n" , elements,c);
    int d = binarysearch(arr,size,elements);
    // printf("position of %d elements is %d" , elements,d);
    return 0;
}
