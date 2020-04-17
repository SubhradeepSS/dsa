class Solution {
public:
    bool f(vector<vector<char>> board,int r,int c){
        for(int k=0;k<9;k++){
            if(k!=c&&board[r][k]==board[r][c])
                    return false;
            if(k!=r&&board[k][c]==board[r][c])
                return false;
        }
        int x=r/3,y=c/3;
        for(int i=x*3;i<x*3+3;i++){
            for(int j=y*3;j<y*3+3;j++){
                if(i!=r&&j!=c&&board[i][j]==board[r][c])
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               if(board[i][j]!='.'){
                    if(!f(board,i,j))
                        return false;
               }
            }
        }
        return true;
    }
};
