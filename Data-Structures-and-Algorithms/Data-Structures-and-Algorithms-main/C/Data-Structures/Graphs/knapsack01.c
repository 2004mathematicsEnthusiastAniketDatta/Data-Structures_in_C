#include <stdio.h>
#include <stdlib.h>

// A structure to represent an item with weight and value
typedef struct
{
    int value;
    int weight;
} Item;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(Item items[], int n, int capacity)
{
    int i, w;
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }

    // Build table dp[][] in bottom-up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w])
                               ? (items[i - 1].value + dp[i - 1][w - items[i - 1].weight])
                               : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int result = dp[n][capacity];

    // Free allocated memory
    for (i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
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
    int maxValue = knapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    // Free the allocated memory
    free(items);

    return 0;
}
