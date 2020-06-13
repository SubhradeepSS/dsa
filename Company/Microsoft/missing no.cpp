#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n;
	    int c=0;
	    for(int i=0;i<n-1;i++){
	        cin>>x;
	        c^=x;
	        c^=i+1;
	    }
	    c^=n;
	    cout<<c<<endl;
	}
	return 0;
}
