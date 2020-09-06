// A union by rank and path compression based program to detect cycle in a graph 
#include <stdio.h> 
#include <stdlib.h> 

// a structure to represent an edge in the graph 
struct Edge 
{ 
	int src, dest; 
}; 

// a structure to represent a graph 
struct Graph 
{ 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges 
	struct Edge* edge; 
}; 

struct subset 
{ 
	int parent; 
	int rank; 
}; 

// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) ); 
	graph->V = V; 
	graph->E = E; 

	graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 

	return graph; 
} 

int find(struct subset s[],int i){
    if(s[i].parent!=i)
        s[i].parent=find(s,s[i].parent);
    return (s[i].parent);
}

void union(struct subset s[],int x,int y){
    int x_root=find(s,x);
    int y_root=find(s,y);
    if(s[x_root].rank<s[y_root].rank){
        s[x_root].parent=y_root;
    }
    else if(s[x_root].rank>s[y_root].rank)
        s[y_root].parent=x_root;
    else{
        s[y_root].parent=x_root;
        s[x_root].rank++;
    }
}

int isCycle(Graph* graph){
    int v=graph->V;
    int e=graph->E;
    struct subset s[v];
    for(int i=0;i<v;i++){
        s[i].parent=i;
        s[i].rank=0;
    }
    for(int i=0;i<e;i++){
        int x=find(s,graph[i].src);
        int y=find(s,graph[i].dest);
        if(x==y)
            return 1;
        union(s,x,y);
    }
    return 0;
}

// Driver program to test above functions 
int main() 
{ 
	/* Let us create the following graph 
		0 
		| \ 
		| \ 
		1-----2 */

	int V = 3, E = 3; 
	struct Graph* graph = createGraph(V, E); 

	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 

	// add edge 1-2 
	graph->edge[1].src = 1; 
	graph->edge[1].dest = 2; 

	// add edge 0-2 
	graph->edge[2].src = 0; 
	graph->edge[2].dest = 2; 

	if (isCycle(graph)) 
		printf( "Graph contains cycle" ); 
	else
		printf( "Graph doesn't contain cycle" ); 

	return 0; 
} 
