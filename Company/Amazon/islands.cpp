bool safe(int i,int j,int N,int M,vector<vector<bool>>& vis,vector<int> A[]){
    return (
            i>=0&&j>=0&&i<N&&j<M&&!vis[i][j]&&A[i][j]==1
        );
}

void dfs(int i,int j,vector<int> A[],int N,int M,vector<vector<bool>>& vis){
    vis[i][j]=true;
    int r[]={-1,-1,-1,0,0,1,1,1};
    int c[]={-1,0,1,-1,1,-1,0,1};
    for(int k=0;k<8;k++){
        if(safe(i+r[k],j+c[k],N,M,vis,A))
            dfs(i+r[k],j+c[k],A,N,M,vis);
    }
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    vector<vector<bool>> vis(N,vector<bool>(M,false));
    int c=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]==1&&!vis[i][j]){
                dfs(i,j,A,N,M,vis);
                c++;
            }
        }
    }
    return c;
}
