#include <stdio.h>
#include<stdlib.h>
#define max_v 100
int visited[max_v];
int n;
int cost = 0;
void travellingSalesmanProblem(int tsp_g[max_v][max_v],int source){
	int min = 999;
	int k,adj_v=999;
	//Marking the  visited vertices in the assigned array
	visited[source]=1;
	 
    printf("%d \t",source+1);
   
    for(k=0;k<n;k++)
    {
    	if(tsp_g[source][k]!=0 && visited[k] == 0){
    		if(tsp_g[source][k] < min){
    			min = tsp_g[source][k];
    			adj_v=k;
			}
		}
	}
	if(min!=999){
		cost=cost+min;
	}
	if(adj_v==999){
		adj_v=0;
		printf("%d",(adj_v + 1));
		cost = cost + tsp_g[source][adj_v];
	    return;
	}
travellingSalesmanProblem(tsp_g,adj_v);
}
int main(){
	int i,j,x;
	printf("Enter the number of Cities:");
	scanf("%d",&n);
	int tsp_g[max_v][max_v];
    printf("Enter the cost matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d \t",&tsp_g[i][j]);	
			}
	}
	for(x=0;x<n;x++){
		visited[x]=0;
	}
	printf("Shortest path");
	travellingSalesmanProblem(tsp_g,0);
	printf("\nMinimum Cost:");
	printf("%d\n",cost);
	return 0;
	
	
	
}

