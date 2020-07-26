#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        auto it=lower_bound(a.begin(),a.end(),x);   // upper_bound for ceiling
        if(*it==x)
            cout<<it-a.begin()<<endl;
        else
            cout<<it-a.begin()-1<<endl;
	}
	return 0;
}
