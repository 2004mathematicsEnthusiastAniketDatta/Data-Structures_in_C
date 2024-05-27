#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int parent(int i)
{
    return (i-1)/2;
}

int leftchild(int i)
{
    return ((2*i)+1);
}

int rightchild(int i)
{
    return ((2*i)+2);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shiftup(int i, int *H)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        swap(&H[parent(i)], &H[i]);
        i = parent(i);
    }
}

void shiftdown(int* H, int i, int size)
{
    int largest = i;
    int l = leftchild(i);
    if (l <= size && H[largest] < H[l])
        largest = l;
    int r = rightchild(i);
    if (r <= size && H[largest] < H[r])
        largest = r;
    if (largest != i)
    {
        swap(&H[largest], &H[i]);
        shiftdown(H, largest, size);
    }
}

void insert(int *H, int p, int *size)
{
    (*size)++;
    H[*size - 1] = p;
    shiftup(*size - 1, H);
}

int extractMax(int *H, int *size)
{
    int result = H[0];
    H[0] = H[*size - 1];
    (*size)--;
    shiftdown(H, 0, *size - 1);
    return result;
}

void changePriority(int *H, int i, int p, int size)
{
    int oldp = H[i];
    H[i] = p;
    if (p > oldp)
        shiftup(i, H);
    else
        shiftdown(H, i, size);
}

int getMax(int H[])
{
    return H[0];
}

void removenode(int *H, int i, int *size)
{
    H[i] = getMax(H) + 1;
    shiftup(i, H);
    extractMax(H, size);
}

int main()
{
    int i, j, k, m;
    int size = 0; // Initialize size to 0
    int H[MAX];

    insert(H, 45, &size);
    insert(H, 20, &size);
    insert(H, 14, &size);
    insert(H, 12, &size);
    insert(H, 31, &size);
    insert(H, 7, &size);
    insert(H, 11, &size);
    insert(H, 13, &size);
    insert(H, 7, &size);

    printf("\nPriority queue before extract max: ");
    for (i = 0; i < size; i++)
        printf("%d ", H[i]);

    printf("\nNode with maximum priority: %d", extractMax(H, &size));

    printf("\nPriority queue after extract max: ");
    for (j = 0; j < size; j++)
        printf("%d ", H[j]);

    changePriority(H, 2, 49, size);
    printf("\nPriority queue after change priority: ");
    for (k = 0; k < size; k++)
        printf("%d ", H[k]);

    removenode(H, 3, &size);
    printf("\nPriority queue after deletion: ");
    for (m = 0; m < size; m++)
        printf("%d ", H[m]);

    return 0;
}

