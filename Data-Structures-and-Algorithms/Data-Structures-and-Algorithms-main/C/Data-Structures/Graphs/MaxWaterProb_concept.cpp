#include <stdio.h>

// Function to return the maximum water that can be stored
int maxWater(int arr[], int n) {
    // Arrays to store the maximum water that can be stored
    int left[n], right[n];

    // Initialize result
    int res = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left[i] = (arr[i] > left[i - 1]) ? arr[i] : left[i - 1];
    }

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = (arr[i] > right[i + 1]) ? arr[i] : right[i + 1];
    }

    // Calculate the accumulated water element by element
    for (int i = 0; i < n; i++) {
        res += ((left[i] < right[i]) ? left[i] : right[i]) - arr[i];
    }

    return res;
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
    printf("Maximum water that can be stored is %d\n", maxWater(arr, n));
    return 0;
}

