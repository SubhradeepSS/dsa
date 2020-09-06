#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m,x;
	    cin>>n>>m>>x;
	    int a[n],b[m];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+m,greater<int>());
        
        int i=0,j=0;
        vector<vector<int>> ans;
        
        while(i<n&&j<m){
            int s=a[i]+b[j];
            if(s==x){
                // cout<<a[i]<<" "<<b[j]<<", ";
                ans.push_back({a[i],b[j]});
                i++;
                j++;
            }
            else if(s<x){
                i++;
            }
            else{
                j++;
            }
        }
        if(ans.size()==0){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i][0]<<" "<<ans[i][1];
            if(i!=ans.size()-1)
                cout<<", ";
        }
        cout<<endl;
	}
	return 0;
}
