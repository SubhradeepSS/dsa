#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m,k;
	    cin>>n>>m>>k;
	    int r,c;
	    //vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));
	    //vector<vector<int>> v(k,vector<int>(2));
	    set<pair<int,int>> s;
	    long long int ans=4*k;
	    while(k--){
	        cin>>r>>c;
	        pair<int,int> p(r,c);
	        pair<int,int> p1(r-1,c);
	        pair<int,int> p2(r,c-1);
	        pair<int,int> p3(r+1,c);
	        pair<int,int> p4(r,c+1);
	        s.insert(p);
	        if(r>1&&c>1&&r<n&&c<m){
	            if(s.find(p1)!=s.end())
	            ans-=2;
	            if(s.find(p2)!=s.end())
	                ans-=2;
	            if(s.find(p4)!=s.end())
	            ans-=2;
	            if(s.find(p3)!=s.end())
	                ans-=2;
	        }
	        else{ 
    	            if(r==1){
    	               if(c==1){
    	                if(s.find(p3)!=s.end())
    	                    ans-=2;
    	                if(s.find(p4)!=s.end())
    	                ans-=2;
    	            }
    	            else if(c==m){
    	                if(s.find(p3)!=s.end())
    	                    ans-=2;
    	                if(s.find(p2)!=s.end())
    	                    ans-=2;
    	            }
    	            else{
    	                if(s.find(p2)!=s.end())
    	                    ans-=2;
    	               if(s.find(p3)!=s.end())
    	                ans-=2;
    	               if(s.find(p4)!=s.end())
    	               ans-=2;
    	            }
    	        }
    	       if(r==n){
    	            if(c==1){
    	                if(s.find(p1)!=s.end())
    	                    ans-=2;
    	                if(s.find(p4)!=s.end())
    	                ans-=2;
    	            }
    	            else if(c==m){
    	                if(s.find(p2)!=s.end())
    	                    ans-=2;
    	               if(s.find(p1)!=s.end())
    	               ans-=2;
    	            }
    	            else{
    	                if(s.find(p2)!=s.end())
    	                    ans-=2;
    	                if(s.find(p1)!=s.end())
    	                ans-=2;
    	                if(s.find(p4)!=s.end())
    	                ans-=2;
    	            }
    	       }
    	       if(c==1||c==m){
    	           if(c==1&&r!=1&&r!=n){
    	               if(s.find(p4)!=s.end())
    	                    ans-=2;
    	               if(s.find(p1)!=s.end())
    	               ans-=2;
    	               if(s.find(p3)!=s.end())
    	               ans-=2;
    	           }
    	           else if(c==m&&r!=1&&r!=n){
    	               if(s.find(p2)!=s.end())
    	                    ans-=2;
    	               if(s.find(p1)!=s.end())
    	               ans-=2;
    	               if(s.find(p3)!=s.end())
    	               ans-=2;
    	           }
    	       }
    	    }
	   }
	   cout<<ans<<endl;
	}
	return 0;
}
