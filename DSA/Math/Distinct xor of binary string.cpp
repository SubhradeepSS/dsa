#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll ncr(ll n,ll r1,ll r2, ll mod){
    ll num=1,den=1,sum=0;
    if(r1==0)
        sum++;
    for(ll i=0;i<r2;i++){
        num=(num*(n-i))%mod;
        den=(den*(i+1))%mod;
        if(i-r1>=-1&&(i-r1+1)%2==0){
            sum=(sum+num*power(den,mod-2,mod)%mod)%mod;
        }
    }
    return sum;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    string a,b;
	    cin>>a>>b;
	    ll a0=0,a1=0,b0=0,b1=0;
	    for(char i:a){
	        if(i=='0')
	            a0++;
            else
                a1++;
	    }
	    for(char i:b){
	        if(i=='0')
	            b0++;
            else
                b1++;
	    }
	    ll max1=min(a0,b1)+min(a1,b0);
	    ll min1=n-min(a0,b0)-min(a1,b1);
	    cout<<ncr(n,min1,max1,1000000007)<<endl;
	}
	return 0;
}
