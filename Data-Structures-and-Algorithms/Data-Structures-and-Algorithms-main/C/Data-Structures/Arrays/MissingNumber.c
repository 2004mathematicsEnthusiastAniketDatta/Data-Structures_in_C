#include <stdio.h>
void findMissing(int arr[], int N)
{   int i;
    int temp[N + 1];
    for (i = 0; i <= N; i++) {
        temp[i] = 0;
    }

    for (i = 0; i < N; i++) {
        temp[arr[i] - 1] = 1;
    }

    int ans;
    for (i = 0; i <= N; i++) {
        if (temp[i] == 0)
            ans = i + 1;
    }
    printf("%d", ans);
}

/* Driver code */
int main()
{   int i;
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findMissing(arr, n);
    return 0;
}

