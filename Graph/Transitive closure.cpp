// adjacency list 
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<int> *adj;
public:
    vector<vector<bool>> t;
    Graph(int v){
        this->v=v;
        adj = new list<int>[v];
        t = vector<vector<bool>>(v,vector<bool>(v,false));
    }
    void addedge(int u,int v){
        adj[u].push_back(v);
    }
    void dfs(int u,int v){
        t[u][v]=true;

        for(int i:adj[v]){
            if(!t[u][i])
                dfs(u,i);
        }
    }
    void transitive(){
        for(int i=0;i<v;i++)
            dfs(i,i);


        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
                cout<<t[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3); 
  
    g.transitive(); 
  
    return 0; 
} 

// adjacency matric - warshall
