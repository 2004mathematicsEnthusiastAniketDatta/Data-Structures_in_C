#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// A utility function to print the solution
void printSolution(int color[]) {
    printf("Assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

// A function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// A function to solve the m coloring problem using the greedy algorithm
bool graphColoring(bool graph[V][V], int m) {
    // Initialize all vertices as unassigned
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    // Assign the first color to the first vertex
    color[0] = 0;

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Process all adjacent vertices and flag their colors as unavailable
        bool available[V];
        for (int i = 0; i < V; i++) {
            available[i] = true;
        }

        for (int i = 0; i < V; i++) {
            if (graph[u][i] && color[i] != -1) {
                available[color[i]] = false;
            }
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < m; cr++) {
            if (available[cr]) {
                break;
            }
        }

        // Assign the found color
        color[u] = cr;

        // If no color was found, return false
        if (cr == m) {
            return false;
        }
    }

    // Print the solution
    printSolution(color);
    return true;
}

int main() {
    /* Create the following graph
       (Example graph)
       0---1
       | / |
       |/  |
       2---3
        \ /
         4
    */
    bool graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
    };
    int m = 3;  // Number of colors

    if (!graphColoring(graph, m)) {
        printf("Solution does not exist");
    }

    return 0;
}

