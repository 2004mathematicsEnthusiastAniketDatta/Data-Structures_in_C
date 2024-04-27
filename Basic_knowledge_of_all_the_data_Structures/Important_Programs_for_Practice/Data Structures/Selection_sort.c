#include<stdio.h>
void printarray(int a[],int n){
    for (int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void selectionsort(int a[],int n){
    int j,temp,i;
    for(i=0;i<n;i++){
        int indexmin=i;
        for(j =i+1;j<n;j++){
            if(a[j]<a[indexmin]){
                indexmin=j;
            }
        }
        temp=a[i];
        a[i]=a[indexmin];
        a[indexmin]=temp;
    }
}
int main(){
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int a[]={3,5,2,13,12};
    int n=sizeof(a)/sizeof(a[0]);
    printarray(a,n);
    selectionsort(a,n);
    printarray(a,n);
    return 0;
}
