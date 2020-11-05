#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<ll> a;
	ll ans=0;
	ll x;
	for(int i=0;i<n;i++){
	    cin>>x;
	    auto it=upper_bound(a.begin(),a.end(),x);
	    if(it==a.end())
	        a.push_back(x);
	    else{
	        ans+=i-(it-a.begin());
	        a.insert(it,x);
	    }
	}
	cout<<ans;
	return 0;
}
