#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
} Node;


typedef struct graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->adjLists = (Node**)malloc(n * sizeof(Node*));
    graph->visited = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}


void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;


}


void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("Visited node: %d\n", vertex);

    Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->data;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        adjList = adjList->next;
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex);


    return 0;
}
