#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 99999

// Struct for the edges of the graph
struct Edge {
    int u;  // Start vertex of the edge
    int v;  // End vertex of the edge
    int w;  // Weight of the edge (u,v)
};

// Graph - it consists of edges
struct Graph {
    int V;        // Total number of vertices in the graph
    int E;        // Total number of edges in the graph
    struct Edge* edge;  // Array of edges
};

void bellmanford(struct Graph* g, int source);
void display(int arr[], int size);

int main() {
    int V, E, i, u, v, w;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = V;
    g->E = E;
    g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));

    printf("Enter the edges (u v w): \n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g->edge[i].u = u;
        g->edge[i].v = v;
        g->edge[i].w = w;
    }

    bellmanford(g, 0);  // 0 is the source vertex

    free(g->edge);
    free(g);

    return 0;
}

void bellmanford(struct Graph* g, int source) {
    int i, j, u, v, w;
    int tV = g->V;
    int tE = g->E;
    int d[tV];
    int p[tV];

    for (i = 0; i < tV; i++) {
        d[i] = INFINITY;
        p[i] = -1;
    }

    d[source] = 0;

    for (i = 1; i <= tV - 1; i++) {
        for (j = 0; j < tE; j++) {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;

            if (d[u] != INFINITY && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    for (i = 0; i < tE; i++) {
        u = g->edge[i].u;
        v = g->edge[i].v;
        w = g->edge[i].w;
        if (d[u] != INFINITY && d[v] > d[u] + w) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    printf("Distance array: ");
    display(d, tV);
    printf("Predecessor array: ");
    display(p, tV);
}

void display(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

