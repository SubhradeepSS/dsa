#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool p2(ll x){
    return x&&(!(x&(x-1)));
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll p;
	    cin>>p;
	    if(p&1){
	        cout<<p/2<<endl;
	    }
	    else{
              ll ts=p,step=0;
              while(ts%2==0){
                  step++;
                  ts/=2;
              }
            ll factor=pow(2,step+1);
            cout<<p/factor<<endl;
	    }
	}
	return 0;
}
