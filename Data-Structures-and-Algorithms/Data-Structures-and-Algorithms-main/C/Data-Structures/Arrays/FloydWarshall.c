#include <stdio.h>
#include <stdlib.h>
#define INF 999999
void floydwarshall(int v,int graph[][v]){
    int dist[v][v];
    int i,j,k;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			dist[i][j] = graph[i][j];
		}
	}
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printf("Shortest distance between every pair of vertices:\n");
	for(i=0;i<v;i++){
		for (j=0;j<v;j++){
			if(dist[i][j] == INF){
				printf("%7s","INFINITY \t ");
			}
			else
			{
				printf("%7d \t",dist[i][j]);
			}
		}
		printf("\n");
	}
}

int main(){
	int v;
    int i,j;
	printf("Enter the number of vertices:");
	scanf("%d",&v);
	int graph[v][v];

	printf("Enter the cost adjacency matrix:");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	floydwarshall(v,graph);
	return 0;
}
