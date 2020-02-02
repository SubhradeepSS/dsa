#include <bits/stdc++.h> 
using namespace std; 
class Graph{
  int v;
  list<int> *adj;
  void DFSUtil(int v,bool visited[]);
  public:
    Graph(int v);
    void addEdge(int u,int v);
    void DFS(int v);
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
void Graph::DFSUtil(int s,bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
        if(!visited[*i])
            DFSUtil(*i,visited);
    }
}
void Graph::DFS(int s){
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    DFSUtil(s,visited);
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
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
} 
