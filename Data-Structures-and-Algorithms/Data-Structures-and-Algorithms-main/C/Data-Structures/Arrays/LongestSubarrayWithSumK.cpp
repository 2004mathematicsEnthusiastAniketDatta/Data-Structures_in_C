#include <stdio.h>
#include <stdlib.h>

// Structure for storing previous sum and its index
struct hashNode {
    int sum;
    int index;
};

// Function to create a new node
struct hashNode* createNode(int sum, int index) {
    struct hashNode* newNode = (struct hashNode*) malloc(sizeof(struct hashNode));
    newNode->sum = sum;
    newNode->index = index;
    return newNode;
}

// Function to find the longest subarray with sum k
int longestSubarray(int* arr, int n, int k) {
    // Create a new hashmap
    struct hashNode** hashMap = (struct hashNode**) calloc(2*n+1, sizeof(struct hashNode*));

    int sum = 0;
    int maxLen = 0;

    // Traverse through the array
    for (int i = 0; i < n; i++) {
        // Add the current element to the sum
        sum += arr[i];

        // If sum is equal to k, update maxLen
        if (sum == k) {
            maxLen = i + 1;
        }

        // If the sum is not present in the hashmap, add it
        if (hashMap[sum+n] == NULL) {
            hashMap[sum+n] = createNode(sum, i);
        }
        // If the sum is present in the hashmap, calculate the length of the subarray and update maxLen
        else {
            if (i - hashMap[sum-k+n]->index > maxLen) {
                maxLen = i - hashMap[sum-k+n]->index;
            }
        }
    }

    // Free the hashmap
    free(hashMap);

    return maxLen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    printf("Length = %d\n", longestSubarray(arr, n, k));
    return 0;
}

