#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;

class adjListnode{
    int v;
    int w;
    public:
    adjListnode(int v_,int w_){
        v=v_;
        w=w_;
    }
    int getv(){return v;}
    int getw(){return w;}
};
class Graph{
    int V;
    list<adjListnode> *adj;
    public:
    Graph(int V);
    void addedge(int u,int v,int w);
    void shortest(int s);
    void topologicalsort(bool visited[],stack<int> &st,int s);
};
Graph::Graph(int V){
    this->V=V;
    adj=new list<adjListnode>[V];
}
void Graph::addedge(int u,int v,int w){
    adjListnode node(v,w);
    adj[u].push_back(node);
}
void Graph::topologicalsort(bool visited[],stack<int> &st,int s){
    visited[s]=true;
    for(auto it=adj[s].begin();it!=adj[s].end();it++){
        adjListnode node=*it;
        if(!visited[node.getv()])
            topologicalsort(visited,st,node.getv());
    }
    st.push(s);
}
void Graph::shortest(int s){
    bool visited[V];
    //memset(visited,0,sizeof(visited));
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    int dist[V];
    //memset(dist,inf,sizeof(dist));
      for (int i = 0; i < V; i++) 
        dist[i] = inf; 
    dist[s]=0;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i])
            topologicalsort(visited,st,i);
    }
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(dist[u]!=inf){
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            if(dist[it->getv()]>dist[u]+it->getw())
                dist[it->getv()]=dist[u]+it->getw();
         }
        }
    }
    for(int i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
int main(){
    Graph g(6);
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,5,2);
    g.addedge(2,4,4);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);
    g.shortest(1);
}
