#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_BINS 100
#define BIN_CAPACITY 10

// Structure to represent a bin
typedef struct
{
    int capacity;
    int current_load;
} Bin;

// Function to compare two integers for qsort (descending order)
int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

// Function to perform the First-Fit Decreasing bin packing
void bin_packing(int items[], int n, int bin_capacity)
{
    // Sort items in descending order
    qsort(items, n, sizeof(int), compare);

    // Initialize bins
    Bin bins[MAX_BINS];
    int bin_count = 0;

    // Iterate through each item
    for (int i = 0; i < n; i++)
    {
        int item = items[i];
        int placed = 0;

        // Try to place the item in an existing bin
        for (int j = 0; j < bin_count; j++)
        {
            if (bins[j].current_load + item <= bins[j].capacity)
            {
                bins[j].current_load += item;
                placed = 1;
                break;
            }
        }

        // If the item was not placed, create a new bin
        if (!placed)
        {
            bins[bin_count].capacity = bin_capacity;
            bins[bin_count].current_load = item;
            bin_count++;
        }
    }

    // Print the result
    printf("Number of bins used: %d\n", bin_count);
    for (int i = 0; i < bin_count; i++)
    {
        printf("Bin %d: %d/%d\n", i + 1, bins[i].current_load, bins[i].capacity);
    }
}

int main()
{
    int items[MAX_ITEMS];
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    bin_packing(items, n, BIN_CAPACITY);

    return 0;
}
