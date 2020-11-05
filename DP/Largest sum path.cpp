#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> a(n,vector<int>(n));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++)
	            cin>>a[i][j];
	    }
	    vector<vector<int>> dp(n,vector<int>(n));
	    for(int i=0;i<n;i++)
	        dp[0][i]=a[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int A=(j>0?dp[i-1][j-1]:0);
                int b=(j<n-1?dp[i-1][j+1]:0);
                dp[i][j]=a[i][j]+max(dp[i-1][j],max(A,b));
            }
        }
       int ans=dp[n-1][0];
       for(int i=1;i<n;i++)
        ans=max(ans,dp[n-1][i]);
       cout<<ans<<endl;
	}
	return 0;
}
