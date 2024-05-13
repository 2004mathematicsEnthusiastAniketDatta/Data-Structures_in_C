#include <stdio.h>

int longestSubarrayWithSumK(int arr[], int n, int K) {
    int start = 0, end = 0;
    int sum = 0;
    int maxLen = 0;

    while (end < n) {
        sum += arr[end];

        while (start < end && sum > K) {
            sum -= arr[start];
            start++;
        }

        if (sum == K) {
            maxLen = (end - start + 1 > maxLen) ? end - start + 1 : maxLen;
        }

        end++;
    }

    return maxLen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 15;

    printf("Length of longest subarray with sum K: %d\n", longestSubarrayWithSumK(arr, n, K));

    return 0;
}

