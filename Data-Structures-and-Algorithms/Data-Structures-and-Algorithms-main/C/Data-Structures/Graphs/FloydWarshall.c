#include <stdio.h>
#define X 4
#define INF 99999
void floydWarshall(int v, int graph[][v])
{
    int dist[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < v; k++)
    {

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distance between every pair of vertices : \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{

    int v;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    int graph[v][v];
    printf("\n");
    printf("Enter the adjacency matrix (%d x %d):\n", v, v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    // int graph[X][X] = {{0, 5, INF, 10},
    //                    {INF, 0, 3, INF},
    //                    {INF, INF, 0, 1},
    //                    {INF, INF, INF, 0}};
    // int v = X;
    floydWarshall(v, graph);
    return 0;
}

// when edges[i] = [fromi, toi, weighti] is given ::
// int main()
// {
//     int v;
//     printf("Enter the number of vertices : ");
//     scanf("%d", &v);
//     int graph[v][v];

//     for (int i = 0; i < v; i++)
//     {
//         for (int j = 0; j < v; j++)
//         {
//             if (i == j)
//                 graph[i][j] = 0;
//             else
//                 graph[i][j] = INF;
//         }
//     }

//     printf("Enter the number of edges : ");
//     int e;
//     scanf("%d", &e);
//     printf("Enter the edges (from, to, weight):\n");
//     for (int i = 0; i < e; i++)
//     {
//         int from, to, weight;
//         scanf("%d %d %d", &from, &to, &weight);
//         graph[from][to] = weight;
//     }

//     floydWarshall(v, graph);
//     return 0;
// }