#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool prime(ll num){
    if(num==1)
        return false;
    if(num<=3)
        return true;
    if(num%2==0||num%3==0)
        return false;
    
    for(ll i=5;i*i<=num;i+=6){
        if(num%i==0||num%(i+2)==0)
            return false;
    }
    return true;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
	    ll n,m;
	    cin>>n>>m;
	    for(ll i=n;i<=m;i++){
	        if(prime(i))
	        {
	            cout<<i<<endl;
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}
