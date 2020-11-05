#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int m,n;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	int x;
	for(int i=0;i<n;i++)
	{
	    cin>>x;
	    a[i]=x;
	}
	for(int i=0;i<m;i++){
	    cin>>x;
	    b[i]=x;
	}
	int min_idx_a=min_element(a.begin(),a.end())-a.begin();
	int max_idx_b=max_element(b.begin(),b.end())-b.begin();
	for(int i=0;i<m;i++){
	    cout<<min_idx_a<<" "<<i<<endl;
	}
	for(int i=0;i<n;i++){
	    if(i==min_idx_a)
	        continue;
	    cout<<i<<" "<<max_idx_b<<endl;
	}
	return 0;
}
