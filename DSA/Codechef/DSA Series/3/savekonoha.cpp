#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll n,z,a;
	    cin>>n>>z;
	    ll s=0;
	    priority_queue<ll> pq;
	    while(n--)
	        {
	         cin>>a;
	         s+=a;
	         pq.push(a);
	        }
	   ll c=0;
	   if(z>=2*s)
	    cout<<"Evacuate"<<endl;
	   else{
    	   while(z>0){
    	       c++;
    	       int p=pq.top();
    	       pq.pop();
    	       z-=p;
    	       pq.push(p/2);
    	   }
    	   cout<<c<<endl;
	   }
	}
	return 0;
}
