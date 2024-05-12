#include <stdio.h>

// Function to find the maximum number of consecutive ones in a binary array
int findMaxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0, currentCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }
    return maxCount;
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
    int maxOnes = findMaxConsecutiveOnes(arr, n);
    printf("Maximum consecutive ones: %d\n", maxOnes);
    return 0;
}

