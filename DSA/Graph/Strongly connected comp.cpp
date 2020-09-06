#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    list<int> *adj;
    Graph(int v);
    void printSCC();
    void addEdge(int v,int w);
    void fillOrder(int v,bool visited[],stack<int> &st);
    void dfsutil(int v,bool visited[]);
    Graph getTranspose();
};

Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

Graph Graph::getTranspose(){
    Graph gT(v);
    for(int i=0;i<v;i++){
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
            gT.adj[*it].push_back(i);
    }
    return gT;
}

void Graph::dfsutil(int v,bool visited[]){
    visited[v]=true;
    cout<<v<<" ";
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i])
            dfsutil(*i,visited);
    }
}

void Graph::fillOrder(int v,bool visited[],stack<int> &st){
    visited[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i])
            fillOrder(*i,visited,st);
    }
    st.push(v);
}

void Graph::printSCC(){
    bool visited[v];
    stack<int> st;
    for(int i = 0; i < v; i++) 
        visited[i] = false; 
    for(int i=0;i<v;i++)
        if(!visited[i])
            fillOrder(i,visited,st);
    Graph gT=getTranspose();
   for(int i = 0; i < v; i++) 
        visited[i] = false; 
    while(!st.empty()){
        int v=st.top();
        st.pop();
        if(!visited[v]){
        gT.dfsutil(v,visited);
        cout<<endl;}
    }
}
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCC(); 
  
    return 0; 
} 
