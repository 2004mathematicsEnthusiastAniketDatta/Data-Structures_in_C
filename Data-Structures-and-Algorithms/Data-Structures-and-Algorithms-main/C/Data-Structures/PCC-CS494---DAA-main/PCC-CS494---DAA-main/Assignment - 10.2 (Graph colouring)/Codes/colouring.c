#include <stdio.h>
static int m, n;
static int c = 0;
static int count = 0;
int g[50][50];
int x[50];
void nextValue(int k);
void GraphColoring(int k);
void main()
{
    int i, j;
    int temp;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    for (m = 1; m <= n; m++)
    {
        if (c == 1)
        {
            break;
        }
        GraphColoring(1);
    }
    printf("\nThe chromatic number is %d", m - 1);
}
void GraphColoring(int k)
{
    int i;
    while (1)
    {
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            c = 1;
            count++;
        }
        else
            GraphColoring(k + 1);
    }
}
void nextValue(int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        for (j = 1; j <= n; j++)
        {
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1))
        {
            return;
        }
    }
}
