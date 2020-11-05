#include <iostream>
using namespace std;

long long int solve(int a[],int n,int k){
	long long int left=0;
	int i=0;
	while(i<n){
	    if(a[i]+left<k){
	        return i+1;
	    }
	    else if(a[i]<k){
	        left-=k-a[i];
	    }
	    else if(a[i]>k){
	        left+=a[i]-k;
	    }
	    i++;
	}
	return n+left/k+1;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cout<<solve(a,n,k)<<endl;
	}
	return 0;
}