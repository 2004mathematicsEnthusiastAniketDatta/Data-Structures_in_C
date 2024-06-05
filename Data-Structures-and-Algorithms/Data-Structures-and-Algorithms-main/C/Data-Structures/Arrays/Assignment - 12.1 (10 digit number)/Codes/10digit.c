#include <stdio.h>

int repeat(int arr[], int index) {
  int count = 0;
  int i;
  
  for(i = 0; i < 10; i++) {
    if(arr[i] == index) {
      count++;
    }
  }
  
  return count;
}

void main() {
  int arr[] = {9, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  
  int temp, i;
  int hasChanges = 1;
  
  while(hasChanges == 1) {
    hasChanges = 0;
    for(i = 0; i < 10; i++) {
      temp = repeat(arr, i);
      if(arr[i] != temp) {
        hasChanges = 1;
        arr[i] = temp;
      }
    }
  }
  
  printf("Result : ");
  
  for(i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n");
}
