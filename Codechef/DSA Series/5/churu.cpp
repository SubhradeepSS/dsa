#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	bool s[10001];
	memset(s,true,sizeof(s));
	s[0]=false;
	s[1]=false;
	for(int i=2;i*i<=10000;i++){
	    if(s[i]){
	        for(int j=i*i;j<=10000;j+=i)
	            s[j]=false;
	    }
	}
	int t;
	cin>>t;
	while(t--){
	    long long int ans=INT_MAX,temp,curr;
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
    	for(int i=2;i<=10000;i++){
    	    if(s[i]){
        	    temp=0;
                curr=0;
                for(int j=0;j<n;j++){
                    if(a[j]>curr){
                        curr=((a[j]+i-1)/i)*i;
                    }
                    temp+=curr-a[j];
                }
                if(temp<ans)
                    ans=temp;
    	    }
    	}
    	cout<<ans<<endl;
	}
	return 0;
}
