#include <iostream>
#include <stack>
using namespace std;

typedef long long int ll;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        ll ans[n];
        ans[n-1]=-1;
        
        stack<ll> s;
        s.push(a[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&s.top()<a[i])
                s.pop();
            if(s.empty())
                ans[i]=-1;
            else
                ans[i]=s.top();
            s.push(a[i]);
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
	}
	return 0;
}
