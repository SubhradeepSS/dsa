#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int p,q;
	    cin>>p>>q;
	    string a,b;
	    cin>>a>>b;
	    int dp[p+1][q+1];
	    for(int i=0;i<=p;i++){
	        for(int j=0;j<=q;j++){
	            if(i==0){
	                dp[i][j]=j;
	            }
	            else if(j==0){
	                dp[i][j]=i;
	            }
	            else if(a[i-1]==b[j-1]){
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
	            }
	        }
	    }
	    cout<<dp[p][q]<<endl;
	}
	return 0;
}
