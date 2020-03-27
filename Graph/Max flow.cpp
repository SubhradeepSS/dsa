#include<bits/stdc++.h>
#define V 6
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
    
    int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      };
    int s = 0; 
    int t = 5; 
    cout << findDisjointPaths(graph, s, t) ;
    return 0; 
} 
