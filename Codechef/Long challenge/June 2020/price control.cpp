#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k,x;
	    cin>>n>>k;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        ans+=(x>k?x-k:0);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
