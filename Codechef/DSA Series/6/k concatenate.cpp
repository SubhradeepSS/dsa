#include <iostream>
#include <limits.h>
#include <algorithm>
#define ll long long int
using namespace std;

ll kadane(ll b[],int n){
    //n=2*n;
    ll curr=b[0],ans=b[0];
    //n=2*n;
    for(int i=1;i<n;i++){
        curr=max(curr+b[i],b[i]);
        ans=max(ans,curr);
    }
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    ll maxv=LLONG_MIN,minv=LLONG_MAX;
	    ll sum=0;
	    ll a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	        minv=min(minv,a[i]);
	        maxv=max(a[i],maxv);
	    }
	    if(minv>=0){
	        cout<<k*sum<<endl;
	        continue;
	    }
	    if(k==1){
	        cout<<kadane(a,n)<<endl;
	    }
	    else{
	        ll b[2*n];
	        for(int i=0;i<n;i++)
	        {
	            b[i]=a[i];
	            b[n+i]=a[i];
	        }
	        ll ans=kadane(b,2*n);
	        if(sum>0)
	            ans+=(k-2)*sum;
            cout<<ans<<endl;
	    }
	}
	return 0;
}
