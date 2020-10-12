#include <bits/stdc++.h>
using namespace std;

bool power_2(int n){
    return (
            (n>0)&&
            (!(n&(n-1)))
        );
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n==1){
	        cout<<1<<endl;
	        continue;
	    }
	    if(power_2(n)){
	        cout<<-1<<endl;
	        continue;
	    }
	    cout<<2<<" "<<3<<" "<<1<<" ";
	    int i=4;
	    while(i<=n){
	        if(power_2(i)){
	            cout<<i+1<<" "<<i<<" ";
	            i++;
	        }
	        else{
	            cout<<i<<" ";
	        }
	        i++;
	    }
	    cout<<endl;
	}
	return 0;
}
