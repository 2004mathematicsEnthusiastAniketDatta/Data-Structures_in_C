#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_VERTICES 100

struct graph {
    int V;
    int E;
    int costmatrix[MAX_VERTICES][MAX_VERTICES];
};

void Dijkstra(struct graph* g, int source) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < g->V - 1; count++) {
        int u = -1;

        for (int i = 0; i < g->V; i++) {
            if (!visited[i] && (u == -1 || distance[i] < distance[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < g->V; v++) {
            if (!visited[v] && g->costmatrix[u][v] &&
                distance[u] != INT_MAX &&
                distance[u] + g->costmatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + g->costmatrix[u][v];
            }
        }
    }

    printf("Shortest distance from source %d:\n", source);
    for (int i = 0; i < g->V; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }
}

int main() {
    struct graph g;

    printf("Enter the number of vertices: ");
    scanf("%d", &g.V);

    printf("Enter the number of edges: ");
    scanf("%d", &g.E);

    // Initialize cost matrix
    for (int i = 0; i < g.V; i++) {
        for (int j = 0; j < g.V; j++) {
            g.costmatrix[i][j] = 0;
        }
    }

    printf("Enter the edge details (u v w):\n");
    for (int i = 0; i < g.E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.costmatrix[u][v] = w;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    clock_t start, end;
    double cpu_time;

    start = clock();
    Dijkstra(&g, source);
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", cpu_time);

    return 0;
}

