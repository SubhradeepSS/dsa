#include <bits/stdc++.h>
using namespace std;

bool f(int a[],int n){
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]*a[i]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s.find(a[i]*a[i]+a[j]*a[j])!=s.end())
                return true;
        }
    }
    return false;
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
        f(a,n)?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}
