#include <iostream>
using namespace std;

typedef pair<int,int> p;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    p l1,r1,l2,r2;
	    cin>>l1.first>>l1.second>>r1.first>>r1.second;
	    cin>>l2.first>>l2.second>>r2.first>>r2.second;
	    
	    if(l1.first>r2.first||l2.first>r1.first||l1.second<r2.second||l2.second<r1.second)
	        cout<<0<<endl;
        else
            cout<<1<<endl;
	}
	return 0;
}
