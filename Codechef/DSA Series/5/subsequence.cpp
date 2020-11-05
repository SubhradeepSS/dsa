#include <iostream>
#include <vector>
#define ll long long int
using namespace std;


int main() {
	// your code goes here
	int max=620000;
	vector<bool> prime(max+1,true);
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i*i<=max;i++){
	    if(prime[i]){
	        for(int j=2*i;j<=max;j+=i)
	            prime[j]=false;
	    }
	}
	vector<int> p;
	for(int i=13;i<=max;i++){
	    if(prime[i])
	        p.push_back(i);
	}
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n==3)
	        cout<<"6 10 15"<<endl;
	    else{
	        vector<ll> v;
	        int i;
	        for(i=0;i<n-2;i++){
	            if(i%3==0)
	                v.push_back(p[i]*6);
                else if(i%3==1)
                    v.push_back(p[i]*10);
                else
                    v.push_back(p[i]*15);
	        }
	        i--;
	        v.push_back(p[i]*7);
	        v.push_back(77);
	        v[0]*=11;
	        for(int i=0;i<n;i++)
	            cout<<v[i]<<" ";
	        cout<<endl;
	    }
	}
	return 0;
}
