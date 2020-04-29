"""
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
"""
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        d={} #Dictionary saving the next states of the cells
        
        m=len(board)
        n=len(board[0])
        for i in range(m):
            for j in range(n):
                d[(i,j)]=board[i][j]
        
        # Check whether cell is inside board and live
        def safe1(r,c):
            return r>=0 and c>=0 and r<m and c<n and board[r][c]==1
        
        # Neighbors' row and column indices
        dr=[-1,-1,-1,0,0,1,1,1]
        dc=[-1,0,1,-1,1,-1,0,1]
        
        # Count of live neighbors
        def count1(r,c):
            count_1=0
            for k in range(8):
                if safe1(r+dr[k],c+dc[k]):
                    count_1+=1
            return count_1
        
        for i in range(m):
            for j in range(n):
                count_1=count1(i,j)
                if board[i][j]==0 and count_1==3:
                    d[(i,j)]=1
                elif board[i][j]==1:
                    if count_1>3 or count_1<2:
                        d[(i,j)]=0
        
        for i in range(m):
            for j in range(n):
                board[i][j]=d[(i,j)]
