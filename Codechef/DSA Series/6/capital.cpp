#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define max 1000000
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int pref[n],suff[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        pref[i]=a[i];
	        suff[i]=a[i];
	    }
	    for(int i=0;i<4;i++){
	        for(int j=1;j<n;j++)
	            pref[j]=(pref[j]+pref[j-1])%mod;
            for(int j=n-2;j>=0;j--)
                suff[j]=(suff[j]+suff[j+1])%mod;
	    }
	    cout<<suff[1]<<" ";
	    for(int i=1;i<n-1;i++)
	        cout<<(pref[i-1]+suff[i+1])%mod<<" ";
        cout<<pref[n-2]<<endl;
	}
	return 0;
}
