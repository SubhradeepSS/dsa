#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll a;
	    vector<ll> v;
	    for(int i=0;i<n;i++){
	        cin>>a;
	        if(upper_bound(v.begin(),v.end(),a)==v.end()){
	            v.push_back(a);
	        }
	        else{
	            v[upper_bound(v.begin(),v.end(),a)-v.begin()]=a;
	        }
	    }
	    cout<<v.size()<<" ";
	    for(int i=0;i<v.size();i++)
	        cout<<v[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
