// BFS
#include<bits/stdc++.h>
using namespace std;

const int v=4;

bool isBipartiteUtil(int g[][v],int color[],int s){
    color[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int j=q.front();
        q.pop();
        if(g[j][j])
            return false;
        for(int i=0;i<v;i++){
            if(g[j][i]&&color[i]==-1){
                color[i]=1-color[j];
                q.push(i);
            }
            else if(g[j][i]&&color[i]==color[j])
                return false;
        }
    }
    return true;
}

bool isBipartite(int g[][v]){
    int color[v];
    memset(color,-1,sizeof(color));
    for(int i=0;i<v;i++)
        if(color[i]==-1)
            if(!isBipartiteUtil(g,color,i))
                return false;
    return true;
}

int main() 
{ 
    int g[][v] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(g) ? cout << "Yes" : cout << "No"; 
    return 0; 
} 


//DFS
void addedge(vector<int> adj[],int v,int w){
        adj[v].push_back(w);
    }
    bool util(vector<int> adj[],int visited[],int color[],int i){
        for(int j:adj[i]){
            if(!visited[j]){
                visited[j]=1;
                color[j]=!color[i];
                if(!util(adj,visited,color,j))
                    return false;
            }
            else if(color[j]==color[i])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        int color[v];
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<graph[i].size();j++){
                addedge(adj,i,graph[i][j]);
            }
        }
        memset(color,-1,sizeof(color));
        int visited[v];
        memset(visited,0,sizeof(visited));
        color[0]=0;
        for(int i=0;i<v;i++){
            if(color[i]==-1)
                if(!util(adj,visited,color,i))
                    return false;
        }
        return true;
    }
