#include <stdio.h>

// Function which pushes all zeros to end of an array.
void pushZerosToEnd(int arr[], int n) {
    int count = 0; // Count of non-zero elements
int i;
    // Traverse the array. If element encountered is non-zero, then replace the element at index 'count' with this element
    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i]; // here count is incremented
        }
    }

    // Now all non-zero elements have been shifted to front and 'count' is set as index of first 0.
    // Make all elements 0 from count to end.
    while (count < n) {
        arr[count++] = 0;
    }
}

// Driver program to test above function
int main() {
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pushZerosToEnd(arr, n);
    printf("Array after pushing all zeros to end of array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


//#include <stdio.h>
//
//// Function which pushes all zeros to end of an array.
//void pushZeroesToEnd(int arr[], int n) {
//    int left = 0, right = n - 1;
//    while (left < right) {
//        // Move left pointer towards right while encountering zeros
//        while (arr[left] != 0 && left < right) {
//            left++;
//        }
//        // Move right pointer towards left while encountering non-zeros
//        while (arr[right] == 0 && left < right) {
//            right--;
//        }
//        if (left < right) {
//            // Swap arr[left] and arr[right]
//            int temp = arr[left];
//            arr[left] = arr[right];
//            arr[right] = temp;
//        }
//    }
//}
//
//// Driver program to test above function
//int main() {
//    int n;
//    printf("Enter the number of elements in the array: ");
//    scanf("%d", &n);
//    int arr[n];
//
//    printf("Enter the elements of the array:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    pushZerosToEnd(arr, n);
//    printf("Array after pushing all zeros to end of array:\n");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

