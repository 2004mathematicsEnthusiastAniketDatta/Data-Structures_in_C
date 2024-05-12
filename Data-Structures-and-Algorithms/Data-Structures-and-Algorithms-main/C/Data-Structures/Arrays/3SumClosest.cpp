#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the sum of three numbers closest to target
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compareInts);
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(target - sum) < abs(target - closest)) {
                closest = sum;
            }
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return closest;
}

// Driver code
int main() {
    int n, target;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int closestSum = threeSumClosest(arr, n, target);
    printf("The sum of three numbers in the array that is closest to the target is: %d\n", closestSum);
    return 0;
}

