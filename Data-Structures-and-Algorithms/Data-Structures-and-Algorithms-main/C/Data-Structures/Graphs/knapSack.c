#include <stdio.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}

void knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    printf("The maximum profit is %d\n", K[n][W]);

    while (n > 0 && W > 0)
    {
        if (K[n][W] == K[n - 1][W])
        {
            n--;
        }
        else
        {
            printf("Item %d with weight %d and value %d is present \n", n, wt[n-1], val[n-1]);
          
            W = W - wt[n - 1];
            n--;
        }
    }
}

int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    int val[n], wt[n];

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &wt[i], &val[i]);
    }
    knapSack(W, wt, val, n);
    return 0;
}
