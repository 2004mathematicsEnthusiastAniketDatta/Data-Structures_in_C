#include <stdio.h>
#include <stdlib.h>

// Function to find missing number
void findMissing(int arr[], int n) {
    // Create a hash table
    int* hash = (int*)calloc(n + 1, sizeof(int));

    // Mark the array elements in the hash table
    for (int i = 0; i < n; i++) {
        hash[arr[i] - 1] = 1;
    }

    // Find the missing number
    for (int i = 0; i <= n; i++) {
        if (hash[i] == 0) {
            printf("%d", i + 1);
            break;
        }
    }

    // Free the memory allocated for the hash table
    free(hash);
}

// Driver code
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findMissing(arr, n);
    return 0;
}

