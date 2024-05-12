#include <stdio.h>
// Function prints Intersection of arr1[] and arr2[]
void printIntersection(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (i > 0 && arr1[i] == arr1[i - 1]) { //For Handling duplicates
            i++;
            continue;
        }
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            printf(" %d ", arr2[j++]);
            i++;
        }
    }
}

// Driver program to test above function
int main() {
    int m, n;
    int i;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &m);
    int arr1[m];
    printf("Enter the elements of the first array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);
    int arr2[n];
    printf("Enter the elements of the second array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printIntersection(arr1, arr2, m, n);
    return 0;
}

