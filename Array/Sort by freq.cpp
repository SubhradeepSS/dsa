// if same freq then smaller value first
#include <bits/stdc++.h>
using namespace std;

bool f(pair<int,int> p1,pair<int,int> p2){
    if(p1.second!=p2.second)
        return p1.second>p2.second;
    return p1.first<p2.first;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        mp[a[i]]++;
	    }
        vector<pair<int,int>> v;
        for(auto i:mp){
            v.push_back(make_pair(i.first,i.second));
        }
        sort(v.begin(),v.end(),f);
        for(auto p:v){
            int val=p.first,c=p.second;
            while(c--)
                cout<<val<<" ";
        }
        cout<<endl;
	}
	return 0;
}
