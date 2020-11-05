// ans - minimum weight of mst and parent stores edges of mst
int minv(vector<int> key,vector<bool> mst){
    int m=INT_MAX,ans;
    for(int i=0;i<key.size();i++){
        if(!mst[i]&&key[i]<m){
            m=key[i];
            ans=i;
        }
    }
    return ans;
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    int ans=0;
    vector<bool> mst(V,false);
    vector<int> key(V,INT_MAX);
    vector<int> p(V,-1);
    key[0]=0;
    
    for(int c=0;c<V-1;c++){
        int u=minv(key,mst);
        mst[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]&&!mst[v]&&key[v]>graph[u][v]){
                key[v]=graph[u][v];
                p[v]=u;
            }
        }
    }
    
    for(int v=1;v<V;v++){
        ans+=graph[p[v]][v];
    }
    return ans;
}
