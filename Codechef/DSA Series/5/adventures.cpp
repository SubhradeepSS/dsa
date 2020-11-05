#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool f(ll n,ll m,ll x,ll y){
    ll a=n-1,b=m-1;
    if(a%x>1||b%y>1)
        return false;
    if((a%x==1&&b%y==1)||(a%x==0&&b%y==0))
        return true;
    if(a%x==0&&b%y==1){
        return (x==1&&a>0);
    }
    if(a%x==1&&b%y==0)
        return (y==1&&b>0);
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
	    ll n,m,x,y;
	    cin>>n>>m>>x>>y;
	    f(n,m,x,y)?cout<<"Chefirnemo\n":cout<<"Pofik\n";
	}
	return 0;
}
