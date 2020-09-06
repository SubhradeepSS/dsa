// C++ Program to count islands in boolean 2D matrix 
#include <bits/stdc++.h> 
using namespace std; 

#define ROW 5 
#define COL 5 
int safe(int r,int c,int M[][COL],bool visited[][COL]){
    return (r>=0&&c>=0&&r<ROW&&c<COL&&M[r][c]&&!visited[r][c]);
}
void DFS(int r,int c,int M[][COL],bool visited[][COL]){
    visited[r][c]=true;
    static int r_no[]={-1,-1,-1,0,0,1,1,1};
    static int c_no[]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++){
        if(safe(r+r_no[i],c+c_no[i],M,visited))
            DFS(r+r_no[i],c+c_no[i],M,visited);
    }
}
int countIslands(int M[][COL]){
    bool visited[ROW][COL];
    int c=0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(M[i][j]&&!visited[i][j]){
                DFS(i,j,M,visited);
                c++;
            }
        }
    }
    return c;
}
int main() 
{ 
	int M[][COL] = { { 1, 1, 0, 0, 0 }, 
					{ 0, 1, 0, 0, 1 }, 
					{ 1, 0, 0, 1, 1 }, 
					{ 0, 0, 0, 0, 0 }, 
					{ 1, 0, 1, 0, 1 } }; 

	cout << "Number of islands is: " << countIslands(M); 

	return 0; 
}

//Only horizontal and vertical allowed
class Solution {
public:
    vector<vector<bool>> v;
    bool safe(int R,int C,int i,int j,vector<vector<char>>& grid){
        return (
            i>=0&&j>=0&&i<R&&j<C&&!v[i][j]&&(grid[i][j]=='1')
        );
    }
    
    void dfs(vector<vector<char>>& grid,int i,int j){
        v[i][j]=true;
        static int R[]={-1,0,0,1};
        static int C[]={0,-1,1,0};
        for(int k=0;k<4;k++){
            if(safe(grid.size(),grid[0].size(),i+R[k],j+C[k],grid))
                dfs(grid,i+R[k],j+C[k]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size(),c,count=0;
        if(r)
            c=grid[0].size();
        v=vector<vector<bool>>(r,vector<bool>(c,false));
        //memset(v,0,sizeof(v));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'&&!(v[i][j])){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
