#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define INFINITY 99999

struct edge {
    int u; // STARTING VERTEX
    int v; // CLOSING VERTEX
    int w; // WEIGHT VERTEX
};

struct graph {
    int V;
    int E;
    struct edge* Edge;
};

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bellmanford(struct graph* g, int source) {
    int tV = g->V;
    int tE = g->E;
    int d[tV];
    int p[tV];

    for (int i = 0; i < tV; i++) {
        d[i] = INFINITY;
        p[i] = -1;
    }

    d[source] = 0;

    for (int i = 1; i <= tV - 1; i++) {
        for (int j = 0; j < tE; j++) {
            int u = g->Edge[j].u;
            int v = g->Edge[j].v;
            int w = g->Edge[j].w;

            if (d[u] != INFINITY && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    for (int i = 0; i < tE; i++) {
        int u = g->Edge[i].u;
        int v = g->Edge[i].v;
        int w = g->Edge[i].w;

        if (d[u] != INFINITY && d[v] > d[u] + w) {
            printf("Negative weight cycles detected.\n");
            return;
        }
    }

    printf("Distance Array: ");
    display(d, tV);
    printf("Predecessor Array: ");
    display(p, tV);
}

int main() {
    int V, E, u, v, w, i;
    printf("Enter the number of vertices and the number of edges: ");
    scanf("%d %d", &V, &E);

    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->E = E;
    g->Edge = (struct edge*)malloc(g->E * sizeof(struct edge));

    printf("Enter the edge details (u v w):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g->Edge[i].u = u;
        g->Edge[i].v = v;
        g->Edge[i].w = w;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bellmanford(g, 0);
    end = clock();

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", cpu_time_used);
    printf("The space complexity is O(V)\n");

    free(g->Edge);
    free(g);

    return 0;
}

