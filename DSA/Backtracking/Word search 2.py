""" Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"] """

# Brute - gives TLE in Leetcode
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        
        if not board or not words:
            return []
        
        ans = set()
        
        n,m = len(board),len(board[0])
        # v = [[False for j in range(m)] for i in range(n)]
        
        def f(i,j,word):
            if not word:
                return True
            if i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[0]:
                return False
            # v[i][j]=True
            t = board[i][j]
            board[i][j] = '$'
            
            a = f(i+1,j,word[1:])
            if a:
                board[i][j] = t
                return True
            
            b = f(i,j+1,word[1:])
            if b:
                board[i][j] = t
                return True
            
            c = f(i-1,j,word[1:])
            if c:
                board[i][j] = t
                return True
            
            d = f(i,j-1,word[1:])
            if d:
                board[i][j] = t
                return True
            
            board[i][j] = t
            return False
            
        for word in words:
            for i in range(n):
                flag=0
                for j in range(m):
                    if board[i][j] == word[0] and f(i,j,word):
                        ans.add(word)
                        flag=1
                        break
                if flag==1:
                    break
            # v = [[False for j in range(m)] for i in range(n)]
        
        return list(ans)
        
