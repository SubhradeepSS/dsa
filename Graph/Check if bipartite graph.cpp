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
