#include <stdio.h>

// Function to sort an array using bubble sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search on a sorted array and find original position before sorting
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Array size must be greater than 0.\n");
        return 0;
    }

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Sort the array before performing binary search
    bubbleSort(arr, n);

    int originalPos = binarySearch(arr, 0, n - 1, key);

    if (originalPos == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d in the sorted array.\n", originalPos);
        printf("Original position before sorting: ");
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}

