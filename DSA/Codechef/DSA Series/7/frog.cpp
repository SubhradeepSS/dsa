#include <bits/stdc++.h>
#define p pair<int,int>
using namespace std;

bool f(p p1,p p2){
    return p1.second<p2.second;
}

int main() {
	// your code goes here
	int n,k,q,x;
	cin>>n>>k>>q;
	//int a[n];
	vector<p> v;
	for(int i=0;i<n;i++){
	    cin>>x;
	    v.push_back({i,x});
	}
	sort(v.begin(),v.end(),f);
	int dp[n];
	//for(int i=0;i<v.size();i++)
	  //  cout<<v[i].first<<" "<<v[i].second<<endl;
	dp[v[n-1].first]=v[n-1].first;
	for(int i=n-2;i>=0;i--){
	    if(v[i+1].second-v[i].second<=k)
	        dp[v[i].first]=dp[v[i+1].first];
        else
            dp[v[i].first]=v[i].first;
	}
	int l,r;
	while(q--){
	    cin>>l>>r;
	    l--;r--;
	    if(dp[l]==dp[r])
	        cout<<"Yes\n";
        else
            cout<<"No\n";
	}
	
	return 0;
}
