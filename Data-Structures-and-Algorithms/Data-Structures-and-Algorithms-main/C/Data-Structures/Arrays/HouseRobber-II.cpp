#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum amount of money that can be robbed from the houses
int rob(int* nums, int start, int end) {
    int prevMax = 0, currMax = 0;
    for (int i = start; i < end; i++) {
        int temp = currMax;
        currMax = max(prevMax + nums[i], currMax);
        prevMax = temp;
    }
    return currMax;
}

// Driver code
int main() {
    int n;
    printf("Enter the number of houses: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the amount of money in each house:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (n == 1) {
        printf("Maximum amount of money that can be robbed: %d\n", nums[0]);
    } else {
        int maxMoney = max(rob(nums, 0, n - 1), rob(nums, 1, n));
        printf("Maximum amount of money that can be robbed: %d\n", maxMoney);
    }

    return 0;
}

