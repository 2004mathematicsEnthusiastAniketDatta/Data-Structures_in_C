#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printpath(int src,int dest, int n, int pred[][n])
{
	if (src==dest)
	{
		printf("%d",src);
		return;
		
	}
	if(pred[src][dest]==-1)
	{
		printf("No path from %d to %d",src,dest);
		return;
	}
	printpath(src,pred[src][dest],n,pred);
	printf("-> %d",dest);
	
}
void printdistance(int n,int cost[][n])
{
	printf("\nThe distance matrix is:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (cost[i][j]==99999)
				printf("INF");
			else
				printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
}
void floyd(int n, int cost[][n])
{

	int pred[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			pred[i][j]= (i==j)?-1:i;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((cost[i][k]+cost[k][j])<cost[i][j])
				{
					cost[i][j]=cost[i][k]+cost[k][j];
					pred[i][j]=pred[k][j];
				}
			}
		}
	}
	printdistance(n,cost);
	printf("\nThe shortest path between:\nSource\tDestination\tPath\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
			  printf("%d\t%d\t\t",i,j);
				printpath(i,j,n,pred);
				printf("\n");
			}
		}
	}
}

int main()
{
	int vertices;
	
	printf("\nEnter the number of vertices:");
	scanf("%d",&vertices);
	int cost[vertices][vertices];
	printf("\nEnter the adjacency matrix:\n");
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			
			scanf("%d",&cost[i][j]);
		}
	}
	floyd(vertices,cost);
	return 0;
}
