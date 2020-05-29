#include <bits/stdc++.h> 
using namespace std; 
class Graph{
  int v;
  list<int> *adj;
  bool isCyclicUtil(int s,bool visited[],bool Stack[]);
  public:
    Graph(int v);
    void addEdge(int u,int v);
    bool isCyclic();
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
bool Graph::isCyclicUtil(int s,bool visited[],bool Stack[]){
    if(!visited[s]){
        visited[s]=true;
        Stack[s]=true;
        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]&&isCyclicUtil(*i,visited,Stack))
                return true;
            else if(Stack[s])
                return true;
        }
    }
    Stack[s]=false;
    return false;
}
bool Graph::isCyclic(){
    bool visited[v],Stack[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        Stack[i]=false;
    }
    for(int i=0;i<v;i++)
        if(isCyclicUtil(i,visited,Stack))
            return true;
    return false;
}
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
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
