#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll a,ll b,ll m){
    ll res=1;
    while(b){
        if(b%2)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}


int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll x;
	vector<int> p={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    vector<vector<ll>> dp(n+1,vector<ll>(25,0));
	for(int i=1;i<n+1;i++){
	    cin>>x;
	    for(int j=0;j<25;j++){
	        dp[i][j]+=dp[i-1][j];
	        while(x%p[j]==0){
	            dp[i][j]++;
	            x/=p[j];
	        }
	    }
	}
    ll t;
    cin>>t;
    ll l,r,mod;
    while(t--){
        cin>>l>>r>>mod;
        ll ans=1;
        if(mod==1)
            ans=0;
        for(int i=0;i<25;i++){
            if(ans==0)
                break;
            ans = (ans * (power(p[i],dp[r][i]-dp[l-1][i],mod)%mod))%mod;
        }
        cout<<ans<<endl;
    }
	return 0;
}
