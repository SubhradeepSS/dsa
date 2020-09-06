#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	int a=2,b=3;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n!=1)
    	    {
    	    cout<<n/2<<"\n";
    	    if(n%2==0){
    	        for(int i=1;i<n;i+=2)
    	            cout<<a<<" "<<i<<" "<<i+1<<"\n";
    	    }
    	    else{
    	        for(int i=1;i<n-1;i+=2){
    	            if(i!=n-2)
    	            cout<<a<<" "<<i<<" "<<i+1<<"\n";
    	            else
    	                cout<<b<<" "<<i<<" "<<i+1<<" "<<i+2<<"\n";
    	            }
    	        }
    	    }
    	  else
    	    cout<<"1\n1 1\n";
	}
	return 0;
}
