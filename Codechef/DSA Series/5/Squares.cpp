#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int ans=LLONG_MAX;
	    for(long long int i=1;i<=sqrt(n);i++){
	        if(n%i==0){
	            long long int a=i;
	            long long int b=n/i;
	            if(b!=a&&(b-a)%2==0)
	                ans=min(ans,(b-a)/2);
	        }
	    }
	    if(ans==LLONG_MAX)
	        cout<<-1<<endl;
	    else
	        cout<<ans*ans<<endl;
	}
	return 0;
}
