#include<bits/stdc++.h>
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
	int V; // No. of vertices' 

	// Pointer to an array containing adjacency listsList 
	list<int> *adj; 

	// A function used by topologicalSort 
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints a Topological Sort of the complete graph 
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[], 
								stack<int> &Stack) 
{ 
    visited[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i])
            topologicalSortUtil(*i,visited,Stack);
    }
    Stack.push(v);
} 

// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> s;
    bool visited[V];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<V;i++){
        if(!visited[i])
            topologicalSortUtil(i,visited,s);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
} 

// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1); 

	cout << "Following is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 
//BFS
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v){
		this->v=v;
		adj = new list<int>[v];
	}
	void addedge(int a,int b){
		adj[a].push_back(b);
	}
	bool cycle();
};

bool Graph::cycle(){
	vector<int> in_degree(v,0);
	for(int i=0;i<v;i++){
		for(auto j:adj[i])
			in_degree[j]++;
	}
	int c=0;
	queue<int> q;
	vector<int> top_order;

	for(int i=0;i<v;i++)
	{
		if(in_degree[i]==0)
			q.push(i);
	}

	while(!q.empty()){
		int u=q.front();
		q.pop();
		top_order.push_back(u);

		for(auto it:adj[u]){
			if(--in_degree[it]==0)
				q.push(it);
		}
		c++;
	}
	for(int i:top_order)
		cout<<i<<" ";
	return (c!=v);
}

int main(){
	int v,e;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++){
		int s,e;
		cin>>s>>e;
		g.addedge(s,e);
	}
	g.cycle()?cout<<"yes":cout<<"no";
}
