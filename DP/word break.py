class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n,m=len(s),len(wordDict)
        dp=[[False for i in range(n)] for j in range(n)]
        
        for i in range(n):
            if s[i] in wordDict:
                dp[i][i]=True
        
        for L in range(2,n+1):
            for i in range(n-L+1):
                j=i+L-1
                
                if s[i:j+1] in wordDict:
                    dp[i][j]=True
                    continue
                    
                for k in range(i,j+1):
                    if dp[i][k] and dp[k+1][j]:
                        dp[i][j]=True
                        break
                    if s[i:k+1] in wordDict and s[k+1:j+1] in wordDict:
                        dp[i][j]=True
                        break
            
        return dp[0][n-1]
