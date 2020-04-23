"""
Given a 2D board and a word, find if the word exists in the grid.The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
"""
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.res=False
        
        
        def dfs(r,c,count):
            if count==len(word):
                self.res=True
                return
            
            if r<0 or c<0 or r>=len(board) or c>=len(board[0]) or board[r][c]=='#' or self.res or board[r][c]!=word[count]:
                return
            
            t=board[r][c]
            board[r][c]='#'
            
            dfs(r-1,c,count+1)
            dfs(r+1,c,count+1)
            dfs(r,c-1,count+1)
            dfs(r,c+1,count+1)
            
            board[r][c]=t
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i,j,0)
        
        return self.res
