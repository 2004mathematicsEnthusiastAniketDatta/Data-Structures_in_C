#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4
void printSol(int color[]){
		printf("Solution exists.Following are the assigned colors: \n");
		int i;
		for(i=0;i<V;i++)
		{
			printf("%d",color[i]);
		}
		printf("\n");
}
bool isSafe(int v,bool graph[V][V],int color[],int c){
	int i;

	for(i=0;i<V;i++)
		if(graph[v][i] && c == color[i])
			return false;
	return true;
}
bool isGraphColoringUtil(bool graph[V][V],int m,int color[],int v)
{
	if (v==V)
	    return true;
	for(int c=1;c<=m;c++)
	{
	if(isSafe(v,graph,color,c))	
	    {
	       color[v]=c;
	       if(isGraphColoringUtil(graph,m,color,v+1) == true)
	           return true;
	        color[v]=0;
	    }
	}
	return false;
}
bool isGraphColoring(bool graph[V][V],int m)
{
	int i;
	int color[V];
	for(i=0;i<V;i++){
		color[i]=0;
	}
	if(isGraphColoringUtil(graph,m,color,0) == false){
		printf("Solution Does Not Exist:");
		return false;
	}
	printSol(color);
	return true;
}
int main(){
	bool graph[V][V] = {
	{0,1.1,1},
	{1,0,1,0},
	{1,1,0,1},
	{1,0,1,0},
	};
	int m = 3;
	isGraphColoring(graph,m);
	return 0;
}

	

	       
		
	   

