#include <iostream>
#include <vector>
#define mod 1000000009
#define max 1000000
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	vector<int> v(max+1,0);
	    v[2]=1;
	    v[3]=1;
	    for(int i=4;i<=max;i++)
	        v[i]=(v[i-3]%mod+v[i-2]%mod)%mod;
	while(t--){
	    int x;
	    cin>>x;
        cout<<v[x]<<endl;
	}
	return 0;
}
