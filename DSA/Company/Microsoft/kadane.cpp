#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        int curr=a[0],ans=a[0];
        for(int i=1;i<n;i++){
            curr=max(curr+a[i],a[i]);
            ans=max(ans,curr);
        }
        cout<<ans<<endl;
	}
	return 0;
}
