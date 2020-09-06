#include <iostream>
using namespace std;

typedef long long ll;

void solve(ll a[],int n,ll s){
    ll curr=a[0];
    int l=0;
    for(int i=1;i<=n;i++){
        while(curr>s&&l<i-1){
            curr-=a[l];
            l++;
        }
        if(curr==s){
            cout<<l+1<<" "<<i<<endl;
            return;
        }
        if(i<n)
            curr+=a[i];
    }
    cout<<"-1\n";
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll s,a[n];
	    cin>>s;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        
        solve(a,n,s);
	}
	return 0;
}
