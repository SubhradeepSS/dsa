#include <iostream>
#include <algorithm>
using namespace std;

struct meet{
    int s;
    int f;
    int idx;
};

bool f(meet a,meet b){
    return a.f<b.f;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    meet Meet[n];
	    for(int i=0;i<n;i++)
	        cin>>Meet[i].s;
        for(int i=0;i<n;i++){
            cin>>Meet[i].f;
            Meet[i].idx=i+1;
        }
        sort(Meet,Meet+n,f);
        
        meet curr=Meet[0];
        cout<<curr.idx<<" ";
        for(int i=1;i<n;i++){
            if(Meet[i].s>=curr.f){
                curr=Meet[i];
                cout<<curr.idx<<" ";
            }
        }
        cout<<endl;
	}
	return 0;
}
