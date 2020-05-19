#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll y;
	    cin>>y;
	    ll ans=0;
	    ll a=sqrt(y);
	    while(a){
	        ll b=y-a*a;
	        if(b>=700)
	            {
	                ans+=a*700;
	                break;
	            }
            else if(b>0){
                ans+=b;
            }
            a--;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
