#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int k,q;
	    cin>>k>>q;
	    vector<ll> a(k);
	    vector<ll> b(k);
	    for(int i=0;i<k;i++)
	        cin>>a[i];
	    for(int i=0;i<k;i++)
	        cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<ll> pq;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(pq.size()<=10000)
                    pq.push(a[i]+b[j]);
                else if(a[i]+b[j]<pq.top()){
                    pq.pop();
                    pq.push(a[i]+b[j]);
                }
                else
                    break;
            }
        }
        vector<ll> v;
        while(!pq.empty()){
            v.insert(v.begin(),pq.top());
            pq.pop();
	    }
        while(q--){
            int i;
            cin>>i;
            cout<<v[i-1]<<endl;
        }
	}
	return 0;
}
