#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Graph {
    int V; // Total number of vertices
    int E; // Total number of edges
    int cost[MAX_VERTICES][MAX_VERTICES]; // Cost matrix
};

void dijkstra(struct Graph* g, int source);

int main() {
    struct Graph g;
    printf("Enter the number of vertices: ");
    scanf("%d", &g.V);

    printf("Enter the number of edges: ");
    scanf("%d", &g.E);

    printf("Enter the edge details (u v w):\n");
    for (int i = 0; i < g.E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.cost[u][v] = w;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(&g, source);

    return 0;
}

void dijkstra(struct Graph* g, int source) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < g->V - 1; count++) {
        int u = -1;
        for (int i = 0; i < g->V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < g->V; v++) {
            if (!visited[v] && g->cost[u][v] && dist[u] != INT_MAX &&
                dist[u] + g->cost[u][v] < dist[v]) {
                dist[v] = dist[u] + g->cost[u][v];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < g->V; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

