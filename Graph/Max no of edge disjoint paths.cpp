#include<bits/stdc++.h>
#define V 8
using namespace std;

bool bfs(int rgraph[][V],int s,int t,int parent[]){
    queue<int> q;
    parent[s]=-1;
    bool visited[V];
    memset(visited,0,sizeof(visited));
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<V;v++){
            if(rgraph[u][v]>0&&!visited[v]){
                visited[v]=true;
                q.push(v);
                parent[v]=u;
            }
        }
    }
    return visited[t];
}

int findDisjointPaths(int graph[][V],int s,int t){
    int rgraph[V][V];
    int maxflow=0;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            rgraph[i][j]=graph[i][j];
    }
    int parent[V];
    while(bfs(rgraph,s,t,parent)){
        int flow=INT_MAX;
        for(int u=t;u!=s;u=parent[u]){
            int v=parent[u];
            flow=min(flow,rgraph[v][u]);
        }
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            rgraph[u][v]-=flow;
            rgraph[v][u]+=flow;
        }
        maxflow+=flow;
    }
    return maxflow;
}

int main() 
{ 
    
    int graph[V][V] = { {0, 1, 1, 1, 0, 0, 0, 0}, 
                        {0, 0, 1, 0, 0, 0, 0, 0}, 
                        {0, 0, 0, 1, 0, 0, 1, 0}, 
                        {0, 0, 0, 0, 0, 0, 1, 0}, 
                        {0, 0, 1, 0, 0, 0, 0, 1}, 
                        {0, 1, 0, 0, 0, 0, 0, 1}, 
                        {0, 0, 0, 0, 0, 1, 0, 1}, 
                        {0, 0, 0, 0, 0, 0, 0, 0} 
                      }; 
  
    int s = 0; 
    int t = 7; 
    cout << "There can be maximum " << findDisjointPaths(graph, s, t) 
         << " edge-disjoint paths from " << s <<" to "<< t ; 
  
    return 0; 
} 
