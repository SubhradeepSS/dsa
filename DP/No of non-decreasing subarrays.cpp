#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int dp[n];
	    ll c=1;
	    dp[0]=1;
	    for(int i=1;i<n;i++){
	        if(a[i]>=a[i-1])
	            dp[i]=dp[i-1]+1;
	        else
	            dp[i]=1;
	        c+=dp[i];
	    }
	    cout<<c<<endl;
	}
	return 0;
}
