#include <stdio.h>

// Function prints union of arr1[] and arr2[]
void printUnion(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            printf(" %d ", arr1[i++]);
        else if (arr2[j] < arr1[i])
            printf(" %d ", arr2[j++]);
        else {
            printf(" %d ", arr2[j++]);
            i++;
        }
    }

    // Print remaining elements of the larger array
    while (i < m)
        printf(" %d ", arr1[i++]);
    while (j < n)
        printf(" %d ", arr2[j++]);
}

// Driver program to test above function
int main() {
    int m, n;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &m);
    int arr1[m];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);
    int arr2[n];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printUnion(arr1, arr2, m, n);
    return 0;
}

