#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        auto it=lower_bound(a.begin(),a.end(),x);   // upper_bound for ceiling
        if(*it==x)
            cout<<it-a.begin()<<endl;
        else
            cout<<it-a.begin()-1<<endl;
	}
	return 0;
}

// without lower_bound
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

int f(vector<ll> a,int l,int h,ll x){
    if(x<a[l])
        return -1;
    if(x>=a[h])
        return h;
    int m=(l+h)/2;
    if(a[m]==x)
        return m;
    if(a[m]<x){
        if(m+1<=h&&a[m+1]>x)
            return m;
        return f(a,m+1,h,x);
    }
    else{
        if(m-1>=l&&a[m-1]<=x)
            return m-1;
        return f(a,l,m-1,x);
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    ll x;
	    cin>>n>>x;
	    vector<ll> a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        cout<<f(a,0,n-1,x)<<endl;
	}
	return 0;
}
