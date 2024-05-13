#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    // Elements picked out if
    int prev1 = 0, prev2 = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int temp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = temp;
    }
    int res = prev1;
    // elements not picked 
    prev1 = 0, prev2 = 0;
    for (int i = 1; i < numsSize; i++) {
        int temp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = temp;
    }
    
    return max(res, prev1);
}

int main() {
    int houses[] = {1, 2, 3, 1};
    int size = sizeof(houses) / sizeof(houses[0]);
    printf("%d\n", rob(houses, size));
    return 0;
}

