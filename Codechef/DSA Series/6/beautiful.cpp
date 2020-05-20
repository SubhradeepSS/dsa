#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    ll dp[2][s.length()+1];
	    dp[0][0]=0;
	    dp[1][0]=0;
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='1'){
	            dp[1][i+1]=dp[1][i]+1;
	            dp[0][i+1]=dp[0][i];}
            else
                {dp[0][i+1]=dp[0][i]+1;
                dp[1][i+1]=dp[1][i];}
	    }
	    ll ans=0;
	    /*for(int i=0;i<s.length();i++){
	        for(int j=i+1;j<s.length();j++){
	            if(i>0)
	            {if((dp[0][j]-dp[0][i-1])==((dp[1][j]-dp[1][i-1])*(dp[1][j]-dp[1][i-1])))
	                ans++;}
                else{
                    if(dp[0][j]==(dp[1][j]*dp[1][j]))
	                ans++;
                }
	        }
	    }*/
	    int n=s.length();
	    int x=ceil(log2(n));
	    for(int i=1;i<=x;i++){
	        int curr=1;
	        int next=curr+i*i+i-1;
	        while(next<=n){
	            int zero=dp[0][next]-dp[0][curr-1];
	            int one=dp[1][next]-dp[1][curr-1];
	            if(zero==one*one)
	                ans++;
                next++;
                curr++;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
