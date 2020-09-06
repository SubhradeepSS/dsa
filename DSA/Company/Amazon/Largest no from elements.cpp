#include <bits/stdc++.h>
using namespace std;

bool f(int a,int b){
    string s1=to_string(a),s2=to_string(b);
    return s1+s2<s2+s1;
}

void solve(int a[],int n){
    sort(a,a+n,f);
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
}

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
        solve(a,n);
	}
	return 0;
}
