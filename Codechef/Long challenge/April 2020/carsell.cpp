#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    sort(a,a+n,greater<int>());
	    ll s=0;
	    for(int i=0;i<n;i++){
	        if(a[i]-i>0)
	            s=(s%1000000007+(a[i]-i)%1000000007)%1000000007;
	    }
	    cout<<s<<endl;
	}
	return 0;
}
