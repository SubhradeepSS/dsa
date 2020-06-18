class Solution {
public:
    int f(vector<vector<int>>& matrix,int n,int m,int i,int j,vector<vector<int>>& dp){
        if(i>=n||j>=m||i<0||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a=INT_MIN,b=INT_MIN,c=INT_MIN,d=INT_MIN;
        if(i>0&&matrix[i][j]<matrix[i-1][j])
            a=1+f(matrix,n,m,i-1,j,dp);
        if(j>0&&matrix[i][j]<matrix[i][j-1])
            b=1+f(matrix,n,m,i,j-1,dp);
        if(i<n-1&&matrix[i][j]<matrix[i+1][j])
            c=1+f(matrix,n,m,i+1,j,dp);
        if(j<m-1&&matrix[i][j]<matrix[i][j+1])
            d=1+f(matrix,n,m,i,j+1,dp);
        
        return dp[i][j]=max(a,max(b,max(c,max(d,1))));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m;
        if(n==0)
            return 0;
        m=matrix[0].size();
        if(m==0)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(matrix,n,m,i,j,dp));
            }
        }
        return ans;
    }
};
