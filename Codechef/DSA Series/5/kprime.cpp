#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int max=100000;
    int p[max+1]={0};
    for(int n=2;n<=max;n++){
        if(p[n]==0){
            for(int i=n;i<=max;i+=n){
                p[i]++;
            }
        }
    }
    	
    int t;
    cin>>t;
    while(t--){
        int a,b,k;
        cin>>a>>b>>k;
        int c=0;
        for(int i=a;i<=b;i++){
            if(p[i]==k)
                c++;
        }
        cout<<c<<endl;
    }
	return 0;
}
