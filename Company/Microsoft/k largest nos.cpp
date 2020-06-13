#include <iostream>
#include <queue>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    priority_queue<int> pq;
	    int x;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        pq.push(x);
	    }
	    for(int i=0;i<k;i++){
	        cout<<pq.top()<<" ";
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
