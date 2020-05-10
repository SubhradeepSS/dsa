#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,t;
	cin>>t;
	while(t--){
	    cin>>n;
	    ll c=0;
	    while(n){
	        c++;
	        n>>=1;
	    }
	    if(c==1||c==2)
	        cout<<c-1<<endl;
	    else{
	        int r=c%4;
	        if(r==0)
	            cout<<3<<endl;
	       else if(r==1)
	        cout<<0<<endl;
	       else if(r==2)
	        cout<<9<<endl;
	       else
	        cout<<2<<endl;
	    }
	}
	return 0;
}
