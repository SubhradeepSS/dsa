#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool safe(int i,int j,int r,int c){
    return (i>=0&&j>=0&&i<r&&j<c);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    int dp[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>dp[i][j];
	            int x=dp[i][j];
	            if(safe(i-1,j-1,n,m))
	                x=max(dp[i-1][j-1],x);
                if(safe(i-1,j,n,m))
                    x=max(dp[i-1][j],x);
                if(safe(i-1,j+1,n,m))
                    x=max(dp[i-1][j+1],x);
	        
	            if(x<=dp[i][j]){
	                ans[i][j]=1;
	            }
	            dp[i][j]=max(x,dp[i][j]);
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)
	            cout<<ans[i][j];
            cout<<endl;
	    }
	}
	return 0;
}
