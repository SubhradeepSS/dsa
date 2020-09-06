#include <bits/stdc++.h> 
using namespace std; 
class Graph{
  int v;
  list<int> *adj;
  public:
    Graph(int v);
    void addEdge(int u,int v);
    bool reach(int s,int d);
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
bool Graph::reach(int s,int d){
    if(s==d)
     return true;
   list<int> q;
   bool visited[v];
   for(int i=0;i<v;i++)
        visited[i]=false;
   visited[s]=true;
   q.push_back(s);
   while(!q.empty()){
       int a=q.front();
       q.pop_front();
       for(auto i=adj[a].begin();i!=adj[a].end();i++){
           if(*i==d)
            return true;
           if(!visited[*i]){
               visited[*i]=true;
               q.push_back(*i);
           }
       }
   }
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
  
    int u = 1, v = 3; 
    if(g.reach(u, v)) 
        cout<< "\n There is a path from " << u << " to " << v; 
    else
        cout<< "\n There is no path from " << u << " to " << v; 
  
    u = 3, v = 1; 
    if(g.reach(u, v)) 
        cout<< "\n There is a path from " << u << " to " << v; 
    else
        cout<< "\n There is no path from " << u << " to " << v; 
  
    return 0; 
} 
