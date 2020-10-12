#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int f1(int a[],int n,int x,int p){
    int min_i=0,min_v=INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i]==x&&abs(i-p)<min_v){
            min_v=abs(i-p);
            min_i=i;
        }
    }
    return min_i;
}

int f(int a[],int n,int x,int p,int k){
    int ans=0;
    sort(a,a+n);
    int idx=f1(a,n,x,p);
    if(a[idx]!=x){
        ans++;
        a[k-1]=x;
        sort(a,a+n);
    }
    if(a[p-1]==x){
        return ans;
    }
    if((p<k&&a[p-1]<x)||(p>k&&a[p-1]>x)){
        return -1;
    }
    idx=f1(a,n,x,p)+1;
    return ans+abs(p-idx);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,x,p,k;
	    cin>>n>>x>>p>>k;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	   // int ans=0;
	   // sort(a,a+n);
	   // while(a[p-1]!=x&&ans<n){
	   //     ans++;
	   //     a[k-1]=x;
	   //     sort(a,a+n);
	   // }
	   // if(ans==n){
	   //     ans=-1;
	   // }
	    
	    cout<<f(a,n,x,p,k)<<endl;
	}
	return 0;
}
