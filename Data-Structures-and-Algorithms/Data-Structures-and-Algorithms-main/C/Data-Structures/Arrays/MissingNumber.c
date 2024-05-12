#include <stdio.h>
// Function to find missing number
void findMissing(int arr[], int n) {
	int i;
    // Calculate the sum of first n natural numbers
    int total = (n) * (n + 1) / 2;

    // Subtract the sum of the array elements from the total
    for (i = 0; i < n; i++) {
        total -= arr[i];
    }

    // The remaining total is the missing number
    printf("%d", total);
}

// Driver code
int main() {
    int n,k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (k= 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }
    findMissing(arr, n);
    return 0;
}

//void findMissing(int arr[], int N)
//{   int i;
//    int temp[N + 1];
//    for (i = 0; i <= N; i++) {
//        temp[i] = 0;
//    }
//
//    for (i = 0; i < N; i++) {
//        temp[arr[i] - 1] = 1;
//    }
//
//    int ans;
//    for (i = 0; i <= N; i++) {
//        if (temp[i] == 0)
//            ans = i + 1;
//    }
//    printf("%d", ans);
//}
