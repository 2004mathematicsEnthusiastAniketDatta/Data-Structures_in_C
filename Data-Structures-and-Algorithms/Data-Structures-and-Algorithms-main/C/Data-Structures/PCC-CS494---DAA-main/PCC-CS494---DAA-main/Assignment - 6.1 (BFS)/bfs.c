#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct queue{
	int item[SIZE];
	int front;
	int rear;
}queue;
typedef struct node{
 	int vertex;
 	struct node* next;
}node;

typedef struct Graph{
 	int numVertices;
 	struct node** adjLists;
 	int* visited;
}Graph;

node* createNode(int v){
	node* newNode=(node*)malloc(sizeof(node));
	newNode->vertex=v;
	newNode->next=NULL;
	return newNode;
}
Graph* createGraph(int vertices){
	Graph* graph=(Graph*)malloc(sizeof(Graph));
	graph->numVertices=vertices;
	graph->adjLists=(node**)malloc(vertices*sizeof(node*));
	graph->visited=(int*)malloc(vertices*sizeof(node));
	int i;
	for(i=0;i<vertices;i++)
	{
		graph->adjLists[i]=NULL;
		graph->visited[i]=0;
	}
	return graph;
}

void addEdge(Graph* graph,int src,int dest)
{
	node* newNode = createNode(dest);
	newNode->next= graph->adjLists[src];
	graph->adjLists[src]= newNode;
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest]=newNode;
}
queue* createQueue()
{
	queue *q=(queue*)malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	return q;
}

int isEmpty(queue* q)
{
	if(q->rear==-1)
		return 1;
	else
		return 0;
}

void enqueue(queue* q,int value)
{
	if(q->rear == SIZE-1)
		printf("\nQueue overflow");
	else
	{
		if(q->front==-1)
			q->front=0;
		q->rear++;
		q->item[q->rear]=value;
	}
}

int dequeue(queue* q)
{
	int item;
	if(isEmpty(q))
	{
		printf("\nQueue is empty");
		item=-1;
	}
	else
	{
		item=q->item[q->front];
		q->front++;
		if(q->front>q->rear)
		{
			printf("\nResetting queue");
			q->front=q->rear=-1;
		}
	}
	return item;
}

void printQueue(queue* q)
{
	int i=q->front;
	if(isEmpty(q))
	{
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nQueue contains: ");
		for(i=q->front;i<q->rear+1;i++)
			printf("%d ",q->item[i]);
	}
}

void bfs(Graph* graph,int startVertex)
{
	queue* q= createQueue();
	graph->visited[startVertex]=1;
	enqueue(q,startVertex);
	while(!isEmpty(q))
	{
		printQueue(q);
		int currentVertex= dequeue(q);
		printf("Visited %d\n",currentVertex);
		node* temp= graph->adjLists[currentVertex];
		while(temp)
		{
			int adjVertex= temp->vertex;
			if(graph->visited[adjVertex]==0)
			{
				graph->visited[adjVertex]=1;
				enqueue(q,adjVertex);
			}
			temp=temp->next;
		}
	}
}

int main()
{
	int n,i,s,d,m;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	Graph* graph=createGraph(6);
	printf("\nEnter the number of edges: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\nEnter the source: ");
		scanf("%d",&s);
		printf("\nEnter the destination: ");
		scanf("%d",&d);
		addEdge(graph,s,d);
	}

	bfs(graph,0);
	return 0;

}
