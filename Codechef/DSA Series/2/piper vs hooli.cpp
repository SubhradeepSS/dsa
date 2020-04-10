#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll n,a,b,x,y,z;
	    cin>>n>>a>>b>>x>>y>>z;
	    ll j,s=0;
	    priority_queue<ll> pq;
	    for(ll i=0;i<n;i++){
	        cin>>j;
	        pq.push(j);
	        s+=j;
	    }
	    ll daysforB;
	    if((z-b)%y==0)
	        daysforB=(z-b)/y-1;
	   else
	    daysforB=(z-b)/y;
	    
	    ll usersforA=daysforB*x+a;
	    if(usersforA>=z)
	        cout<<0<<endl;
	   else{
	       if(2*s<=z-usersforA)
	        cout<<"RIP"<<endl;
	       else{
	           ll c=0;
	           while(usersforA<z){
	               ll contri=pq.top();
	               usersforA+=contri;
	               c++;
	               pq.pop();
	               pq.push(contri/2);
	           }
	           cout<<c<<endl;
	       }
	   }
	}
	return 0;
}
