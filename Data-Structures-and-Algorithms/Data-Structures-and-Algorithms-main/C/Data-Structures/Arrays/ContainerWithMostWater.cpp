#include <stdio.h>
#include <stdlib.h>
#include<math.h>
// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a,int b){
	return (a<b)?a:b;
}
// Function to find the maximum area between two bars
int maxArea(int* height, int n) {
	
    int maxarea = 0, left = 0, right = n - 1;
    while (left < right) {
        maxarea = max(maxarea,min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxarea;
}

// Driver code
int main() {
    int n;
    printf("Enter the number of bars: ");
    scanf("%d", &n);
    int height[n];
    printf("Enter the height of each bar:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }
    printf("Maximum area: %d\n", maxArea(height, n));
    return 0;
}

