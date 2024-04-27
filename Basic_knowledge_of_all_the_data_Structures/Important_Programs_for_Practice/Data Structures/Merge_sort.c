#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int a[], int low, int high, int mid)
{
    int i, j, k, c[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}
int main()
{
    int a[] = {35, 50, 15, 25, 80, 20, 90, 45};
    int n = sizeof(a) / sizeof(a[0]);
    printArray(a, n);
    mergesort(a, 0, n-1);
    printArray(a, n);
    return 0;
}
