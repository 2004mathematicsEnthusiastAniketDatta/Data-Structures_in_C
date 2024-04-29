#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

void prims(int n, int cost[MAX_VERTICES][MAX_VERTICES]) {
    int i, j, u, v, min, mincost = 0, visited[MAX_VERTICES], ne = 1;

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    visited[1] = 1;

    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf("Edge %d: (%d, %d) = %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[v][u] = cost[u][v] = 999;
    }

    printf("Cost of constructing MST is %d\n", mincost);
}

int main() {
    int i, j, n, cost[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    prims(n, cost);
    return 0;
}

