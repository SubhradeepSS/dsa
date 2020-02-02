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
