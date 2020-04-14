#include <iostream>
#include <set>
using namespace std;
const int mod =1e9+7;
#define int long long int
const int inf=1e18;
signed main() {
	// your code goes here
	int n,q;
	cin>>n>>q;
	set<int> s;
	int a[n+2];
	a[0]=inf;
	for(int i=1;i<=n;i++)
	    {cin>>a[i];
	    if(a[i]%a[i-1]!=0)
	        s.insert(i);}
	a[n+1]=mod;
	while(q--){
	    int t;
	    cin>>t;
	    if(t==2){
	        int i;
	        cin>>i;
	        auto it=s.upper_bound(i);
	        it--;
	        cout<<(*it)<<endl;
	    }
	    else{
	        int i,val;
	        cin>>i>>val;
	        a[i]=val;
	        if(a[i]%a[i-1]==0)
	            s.erase(i);
	       else
	        s.insert(i);
	       if(a[i+1]%a[i]==0)
	        s.erase(i+1);
	       else
	        s.insert(i+1);
	    }
	}
}
