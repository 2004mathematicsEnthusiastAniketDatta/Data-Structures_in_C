#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 99999

struct edge{
	int u; //starting vertex of edge
	int v; //ending vertex of edge
	int w; //weight of edge(u,v)
};

struct graph{
	int V;
	int E;
	struct edge* Edge;
};
void bellmanFord(struct graph* g,int source){
	int i,j,u,v,w;
	int tv = g->V;
	int te = g->E;
	int d[tv];
	int p[tv];
	for(i=0;i<tv;i++){
		d[i]=INFINITY;
		p[i]=-1;
	}
	d[source]=0;
	for(i=1;i<=tv-1;i++){
		for(j=0;j<te;j++){
			u=g->Edge[j].u;
			v=g->Edge[j].v;
			w=g->Edge[j].w;
			if(d[u]!=INFINITY && d[v]>d[u]+w){
				d[v]=d[u]+w;
				p[v]=u;
			}
		}
	}
	
		for(i=0;i<te;i++){
			u=g->Edge[i].u;
			v=g->Edge[i].v;
			w=g->Edge[i].w;
			if(d[u]!=INFINITY && d[v]>d[u]+w){
				printf("Negative weight cycle detected");
				return;
		}
	}
	printf("distance array:");
	display(d,tv);
	printf("prdecessor array:");
	display(p,tv);
}

void display(int array[],int size)
{
	int i;
	for(i=0;i<size;i++){
		printf("%d",array[i]);
	}
	printf("\n");
}

int main(){
	int i,V,E,u,v,w;
	printf("Enter the number of vertices and edges:");
	scanf("%d %d",&V,&E);
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	g->V=V;
	g->E=E;
	g->Edge = (struct edge*)malloc(g->E * (sizeof(struct edge)));
	printf("Enter the u v and w of edges:\n");
	for(i=0;i<E;i++){
	scanf("%d %d %d ",&u,&v,&w);
	g->Edge[i].u=u;
	g->Edge[i].v=v;
	g->Edge[i].w=w;
}
bellmanFord(g,0);
free(g->Edge);
free(g);
return 0;
}
