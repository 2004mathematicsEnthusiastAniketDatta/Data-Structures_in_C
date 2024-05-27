#include<stdio.h>
#define MAX 100
int interpolation(int arr[], int x, int low, int high)
{
    if (low <= high && x >= arr[low] && x <= arr[high])
    {
        int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[pos] < x)
            return interpolation(arr, x, pos + 1, high);
        else if (arr[pos] > x)
            return interpolation(arr, x, low, pos - 1);
        else
            return pos;
    }
    else
        return -1;
}

void main()
{
    int n, i, x;
    int arr[MAX];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("\nEnter the sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&x);
    int pos = interpolation(arr, x, 0, n - 1);
    if (pos != -1)
        printf("%d is in the array at position %d\n", x, pos);
    else
        printf("%d is not in the array\n", x);
}
