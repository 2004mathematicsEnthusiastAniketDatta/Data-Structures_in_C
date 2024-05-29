#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct graph{
    int V,E;
    int *vertices;
    int **adjMat;
}graph;

int search(int arr[],int n, int key){
    for (int i = 0; i < n; i++){
        if (arr[i] == key){
            return i;
        }       
    }
}

void print_array(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void input_edge(graph* g){
    int i,s,d,w,src,dest;
     printf("Enter the edges : \n");
    printf("\tSource\t    Destination\t      Weight\n");
    printf("----------------------------------------------\n");
    for(i=0; i<g->E; i++){
        printf("Edge-%d :   ",i+1);
        scanf("%d\t\t%d\t\t%d",&src,&dest,&w);

        s = search(g->vertices,g->V,src);
        d = search(g->vertices,g->V,dest);
        g->adjMat[s][d] = w;
        g->adjMat[d][s] = w;
    }
}

int min(int a, int b){
    return (a<b)?a:b;
}

void print_path(graph *g, int v, int src, int succ[]){
	int i;
	int mask = (1 << src);
	printf("Path : %d -->",g->vertices[src]);
	while(mask != (1 << v)-1){
		i = succ[mask];
		printf("%d --> ",g->vertices[i]);
		mask = mask | (1 << i);
	}
	printf("%d\n",g->vertices[src]);
}

int tsp(graph *g, int mask, int pos, int src, int v, int dp[][v], int succ[]){
    if(mask == (1 << g->V)-1){
        return g->adjMat[pos][src];
    }
    else if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }
    int ans = INT_MAX,i,x;
    for(i=0; i < g->V; i++){
        if(((mask & (1 << i)) == 0)){
            x = g->adjMat[pos][i] + tsp(g, mask|(1 << i) , i, src, v, dp, succ);
            if(x < ans){
            	ans = x;
            	succ[mask] = i;
            }
        } 
    }
    return dp[mask][pos] = ans;
}

void main(){
    int i,j,v,e,src;
    graph *g = (graph*) malloc (sizeof(graph));
    printf("Enter the number of vertices : ");
    scanf("%d",&v);
    g->V = v;

    //g->V = v = 4;

    g->vertices = (int*) malloc (v * sizeof(int));
     printf("Enter the vertices : \n");
     for(i=0; i<v; i++){
         printf("Vertex - %d : ",i+1);
         scanf("%d",&g->vertices[i]);
     }

    for(i=0; i<v; i++){
        g->vertices[i] = i+1;
    }

    printf("\nEnter the number of edges : ");
    scanf("%d",&e);
    g->E = e;

    

    g->adjMat = (int**) malloc (v * sizeof(int*));
    for(i=0; i<v; i++){
        g->adjMat[i] = (int*) malloc (v * sizeof(int));
    }

    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            if(i == j)
                g->adjMat[i][j] = 0;
            else
                g->adjMat[i][j] = INT_MAX;
        }
    }

    input_edge(g);


    int dp[1<<v][v];
    memset(dp,-1,sizeof(dp));

    printf("\nEnter the source vertex : ");
    scanf("%d",&src);
    src = 1;
    src = search(g->vertices, v, src);

    int succ[1 << v];
    memset(succ,-1,sizeof(succ));
    int mask = (1 << src);
    int dist = tsp(g, mask, src, src, v, dp, succ);
    printf("\nMinimum distance = %d\n\n",dist);
    print_path(g, v, src, succ);

    //print_sol(g, v, dp);
    
    
}
