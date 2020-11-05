#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000007
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	vector<int> freq;
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;){
        int c=1,x=a[i];
        i++;
        while(i<n&&a[i]==x){
            c++;
            i++;
        }
        freq.push_back(c);
    }
    int m=freq.size();
    n=(m<k?m:k);
    
    ll dp[n+1][m+1];
    for(int i=0;i<=m;i++)
        dp[0][i]=1;
    ll ans=1;
    
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j>m-i)
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i][j+1]%mod+((freq[j]%mod)*(dp[i-1][j+1]%mod))%mod)%mod;
        }
        ans=(ans+dp[i][0]%mod)%mod;
    }
    cout<<ans;
	return 0;
}
