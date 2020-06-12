#include <bits/stdc++.h>
using namespace std;

string f(vector<int> a,int x){
    unordered_set<int> s;
    for(int i:a){
        if(s.find(x-i)!=s.end())
            return "Yes\n";
        s.insert(i);
    }
    return "No\n";
}

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
        cout<<f(a,x);
	}
	return 0;
}
