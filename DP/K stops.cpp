/* There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2,vector<int>(n,INT_MAX));
        if(src==dst)
            return 0;
        
        for(int i=0;i<=k+1;i++)
            dp[i][src]=0;
        
        for(int i=1;i<=k+1;i++){
            for(auto it:flights){
                int u=it[0],v=it[1],w=it[2];
                if(dp[i-1][u]!=INT_MAX)
                    dp[i][v]=min(dp[i][v],dp[i-1][u]+w);
            }
        }
        
        return (dp[k+1][dst]==INT_MAX?-1:dp[k+1][dst]);
    }
};
