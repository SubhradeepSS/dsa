// https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/


#include<bits/stdc++.h>
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; // A dynamic array of adjacency lists 
public: 
	// Constructor and destructor 
	Graph(int V) { this->V = V; adj = new list<int>[V]; } 
	~Graph()	 { delete [] adj; } 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// Prints greedy coloring of the vertices 
	void greedyColoring(); 
}; 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); // Note: the graph is undirected 
} 
void Graph::greedyColoring() 
{   int result[V];
    bool av[V];
    result[0]=0;
    for(int i=1;i<V;i++)
        result[i]=-1;
    
    for(int i=0;i<V;i++)
        av[i]=true;
    for(int i=1;i<V;i++){
        for(auto v=adj[i].begin();v!=adj[i].end();v++)
            if(result[*v]!=-1)
                av[result[*v]]=false;
        int c;
        for(c=0;c<V;c++)
            if(av[c])
                break;
        result[i]=c;
        
        for(auto v=adj[i].begin();v!=adj[i].end();v++)
            if(result[*v]!=-1)
                av[result[*v]]=true;
    }
        
	for (int u = 0; u < V; u++) 
		cout << "Vertex " << u << " ---> Color "
			<< result[u] << endl; 
} 

int main() 
{ 
	Graph g1(5); 
	g1.addEdge(0, 1); 
	g1.addEdge(0, 2); 
	g1.addEdge(1, 2); 
	g1.addEdge(1, 3); 
	g1.addEdge(2, 3); 
	g1.addEdge(3, 4); 
	cout << "Coloring of graph 1 \n"; 
	g1.greedyColoring(); 

	Graph g2(5); 
	g2.addEdge(0, 1); 
	g2.addEdge(0, 2); 
	g2.addEdge(1, 2); 
	g2.addEdge(1, 4); 
	g2.addEdge(2, 4); 
	g2.addEdge(4, 3); 
	cout << "\nColoring of graph 2 \n"; 
	g2.greedyColoring(); 

	return 0; 
} 
