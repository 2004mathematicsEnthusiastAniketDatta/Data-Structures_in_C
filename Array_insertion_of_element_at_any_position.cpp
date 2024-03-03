#include <stdio.h>  
int  main()  
{  
    int arr[10]; 
    int i,j;  
       printf("\n\nRead and Print elements of an array:\n");
       printf("-----------------------------------------\n");	
  
    printf("Input 10 elements in the array :\n");  
    for(i=0; i<10; i++)  
    {  
	    printf("element - %d : ",i);
        scanf("%d", &arr[i]);  
    }  
  	    printf("\nElements in array before insertion are: ");  
    for(i=0; i<10; i++)  
    {  
        printf("%d  ", arr[i]);  
    } 

    printf("\n");	
    int key=30,position=3;
    for(j=10;j>=3;j--){
    	arr[j]=arr[j-1];
	}
	arr[position]=key;
	    printf("\nElements in array after insertion are: ");  
    for(i=0; i<10; i++)  
    {  
        printf("%d  ", arr[i]);  
    } 
    return 0;
}
