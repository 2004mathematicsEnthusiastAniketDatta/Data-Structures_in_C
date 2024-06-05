#include <stdio.h>
#include <stdlib.h>

// A structure to represent an item with weight and value
typedef struct
{
    int value;
    int weight;
} Item;

// Compare function for qsort
int compare(const void *a, const void *b)
{
    double ratio1 = ((Item *)a)->value / (double)((Item *)a)->weight;
    double ratio2 = ((Item *)b)->value / (double)((Item *)b)->weight;
    if (ratio1 < ratio2)
        return 1;
    if (ratio1 > ratio2)
        return -1;
    return 0;
}

// Function to sort items based on value/weight ratio in descending order using qsort
void sortItems(Item items[], int n)
{
    qsort(items, n, sizeof(Item), compare);
}

// Function to calculate the maximum value we can get with given capacity
double fractionalKnapsack(Item items[], int n, int capacity)
{
    sortItems(items, n);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity > 0 && items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            if (capacity > 0)
            {
                totalValue += items[i].value * ((double)capacity / items[i].weight);
                capacity = 0;
            }
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;

    // Read number of items and capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Dynamically allocate memory for items
    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read items' values and weights
    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate the maximum value that can be carried in the knapsack
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    // Free the allocated memory
    free(items);

    return 0;
}
