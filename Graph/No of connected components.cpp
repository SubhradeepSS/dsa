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
