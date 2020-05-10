#include <bits/stdc++.h>
using namespace std;

bool f(int n,vector<int> v,bool sprime[]){
    int i=0;
    while(v[i]<=n/2){
        if(sprime[n-v[i]])
            return true;
        i++;
    }
    return false;
}

int main() {
	// your code goes here
	bool sprime[201];
	memset(sprime,false,sizeof(sprime));
	vector<int> v;
	for(int i=2;i<=200;i++){
	    int cnt=0;
	    int num=i;
	    for(int j=2;cnt<2,j*j<=num;j++){
	        while(num%j==0){
	            cnt++;
	            num/=j;
	        }
	    }
	    if(num>0)
	        cnt++;
	    if(cnt==2){
	        sprime[i]=true;
	        v.push_back(i);
	    }
	}
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    f(n,v,sprime)?cout<<"YES\n":cout<<"NO\n"<<endl;
	}
	return 0;
}
