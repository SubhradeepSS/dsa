#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,x,y;
	unordered_map<int,int> mp1;
	unordered_map<int,int> mp2;
	cin>>n>>x>>y;
	int start[n],end[n],s[n],e[n];
	for(int i=0;i<n;i++){
	    cin>>start[i]>>end[i];
	    s[i]=start[i];
	    e[i]=end[i];
	}
    sort(start,start+n);
    sort(end,end+n);
    for(int i=0;i<n;i++){
        mp1[start[i]]=i;
	    mp2[end[i]]=i;
    }
	 int sworm[x],eworm[y];
	 for(int i=0;i<x;i++)
	    cin>>sworm[i];
	 for(int i=0;i<y;i++)
	    cin>>eworm[i];
	 sort(sworm,sworm+x);
	 sort(eworm,eworm+y);
	 vector<int> ans_s(n,-1);
	 vector<int> ans_e(n,-1);
	 int j=n-1,i=x-1;
	 while(i>=0&&j>=0){
	     if(start[j]>=sworm[i]){
	         ans_s[j]=sworm[i];
	         j--;
	     }
	     else 
	        i--;
	 }
	 j=0;
	 i=0;
	 while(i<y&&j<n){
	     if(eworm[i]>=end[j]){
	         ans_e[j]=eworm[i];
	         j++;
	     }
	     else
	        i++;
	 }
	 int minv=99999999;
	 for(int i=0;i<n;i++){
	     int s_i=mp1[s[i]];
	     int e_i=mp2[e[i]];
	     if(ans_e[e_i]!=-1&&ans_s[s_i]!=-1)
	        minv=min(minv,ans_e[e_i]-ans_s[s_i]+1);
	 }
	 cout<<minv;
	return 0;
}
