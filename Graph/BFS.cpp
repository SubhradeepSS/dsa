#include <bits/stdc++.h> 
using namespace std; 
class Graph{
  int v;
  list<int> *adj;
  public:
    Graph(int v);
    void addEdge(int u,int v);
    void BFS(int s);
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
void Graph::BFS(int s){
   list<int> q;
   bool visited[v];
   for(int i=0;i<v;i++)
        visited[i]=false;
   visited[s]=true;
   q.push_back(s);
   while(!q.empty()){
       int a=q.front();
       q.pop_front();
       cout<<a<<" ";
       for(auto i=adj[a].begin();i!=adj[a].end();i++){
           if(!visited[*i]){
               visited[*i]=true;
               q.push_back(*i);
           }
       }
   }
}
int main() 
{ 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 
