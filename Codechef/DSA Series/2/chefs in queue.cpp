#include <iostream>
#include <limits.h>
#include <stack>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int min=INT_MAX,j,n,k;
	ll mod=1000000007;
	ll p=1;
	cin>>n>>k;
	int a[n];
	j=n-1;
	for(int i=0;i<n;i++)
	    cin>>a[i];
	 stack<int> s;
	 s.push(n-1);
	for(int i=n-2;i>=0;i--){
	    while(!s.empty()&&a[i]<=a[s.top()])
	        s.pop();
	    if(!s.empty())
	        p=((p%mod)*((s.top()-i+1)%mod))%mod;
	        s.push(i);
	}
	   cout<<p;
	return 0;
}
