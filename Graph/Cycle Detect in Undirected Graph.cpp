// dfs 
#include<bits/stdc++.h>
using namespace std; 
class Graph 
{ 
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v,bool visited[],int parent);
    public:
    void addEdge(int v,int w);
    Graph(int V);
    bool isCyclic();
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);
	adj[w].push_back(v);
}
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
	visited[v]=true;
	for(auto i=adj[v].begin();i!=adj[v].end();i++){
	    if(!visited[*i]){
	         if(isCyclicUtil(*i,visited,v))
	            return true;}
	    else if(*i!=parent)
	        return true;
	}
	return false;
} 

bool Graph::isCyclic() 
{ 
 bool visited[V];
 memset(visited,false,sizeof(visited));
 for(int i=0;i<V;i++){
     if(!visited[i])
     if(isCyclicUtil(i,visited,-1))
        return true;
 }
 return false;
} 

// bfs
bool f(int v,vector<bool>& vis,vector<int> g[]){
    queue<int> q;
    q.push(v);
    vis[v]=true;
    vector<int> p(vis.size(),-1);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int j:g[t]){
            if(!vis[j]){
                vis[j]=true;
                p[j]=t;
                q.push(j);
            }
            else if(p[t]!=j)
                return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   vector<bool> vis(V,false);
   for(int i=0;i<V;i++){
       if(!vis[i]&&f(i,vis,g))
        return true;
   }
   return false;
}
