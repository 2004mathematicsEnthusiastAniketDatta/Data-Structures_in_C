#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int vertices;

void dijkstra(int graph[vertices][vertices], bool final[], int distance[], int predecessor[], int source)
{
    distance[source - 1] = 0;
    int count;
    for (count = 0; count < vertices - 1; count++)
    {
        int min = INT_MAX, index = -1, i;
        for (i = 0; i < vertices; i++)
        {
            if (final[i] == false && distance[i] < min)
            {
                index = i;
                min = distance[i];
            }
        }
        final[index] = true;
        for (i = 0; i < vertices; i++)
        {
            if (graph[index][i] != 0 && ((distance[index] + graph[index][i]) < distance[i]) && final[i] == false)
            {
                distance[i] = distance[index] + graph[index][i];
                predecessor[i] = index;
            }
        }
    }
}

void printPath(int predecessor[], int v, int source)
{
    if (v == source - 1)
    {
        printf("%d ", source);
        return;
    }
    printPath(predecessor, predecessor[v], source);
    printf("%d ", v + 1);
}

void printDistance(int distance[], int predecessor[], int source)
{
    int i;
    printf("Vertex\tDistance\tPath\n");
    for (i = 0; i < vertices; i++)
    {
        if (i == source - 1)
            continue;
        printf("%d\t%d\t\t", i + 1, distance[i]);
        printPath(predecessor, i, source);
        printf("\n");
    }
}

int main()
{
    printf("Enter the no. of vertices : ");
    scanf("%d", &vertices);
    int graph[vertices][vertices];
    printf("Enter the Adjacency Matrix : \n");
    int row, col, i, source;
    for (row = 0; row < vertices; row++)
    {
        for (col = 0; col < vertices; col++)
        {
            scanf("%d", &graph[row][col]);
        }
    }
    bool final[vertices];
    int distance[vertices];
    int predecessor[vertices];
    for (i = 0; i < vertices; i++)
    {
        final[i] = false;
        distance[i] = INT_MAX;
        predecessor[i] = -1; // Initialize predecessor array
    }
    printf("Enter the Source vertex : ");
    scanf("%d", &source);
    dijkstra(graph, final, distance, predecessor, source);
    printDistance(distance, predecessor, source);
    return 0;
}
