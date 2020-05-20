#include <iostream>
#include <algorithm>
#define ll long long int
#define mod 1000000007
#define max 1000000000
using namespace std;

ll a,b,c,d;

void fast_fib(ll n,ll ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += mod;
    c = (a * c) % mod;      /* F(2n) */
    d = (a*a + b*b) % mod;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}


ll A,B,C,D;

void fast_fib2(ll n,ll AR[])
{
    if(n == 0)
    {
        AR[0] = 0;
        AR[1] = 1;
        return;
    }
    fast_fib2((n/2),AR);
    A = AR[0];             /* F(n) */
    B = AR[1];             /* F(n+1) */
    C = 2*B - A;
    if(C < 0)
        C += mod;
    C = (A * C) % mod;      /* F(2n) */
    D = (A*A + B*B) % mod;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        AR[0] = C;
        AR[1] = D;
    }
    else
    {
        AR[0] = D;
        AR[1] = C+D;
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	//fib(1000000002);
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    ll ans[2]={0};
	    ll AR[2]={0};
	    //ll f[max(n,k)]={0};
	    fast_fib(k+1,ans);
	    fast_fib2((n-(n/k)*k)+1,AR);
	    cout<<((n/k)*((ans[0]-1)%mod)+(AR[0]-1)%mod)%mod<<endl;
	}
	return 0;
}
