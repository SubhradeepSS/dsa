#include <bits/stdc++.h> 
using namespace std; 

int maxLen(int arr[], int n) 
{ 
    for(int i=0;i<n;i++)
        arr[i]=(arr[i]==0)?-1:1;
    int max_l=0,start,end;
    unordered_map<int,int> mp;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            max_l=i+1;
            end=i;
            start=0;
        }
        if(mp.find(sum+n)!=mp.end()){
            if(max_l<i-mp[sum+n]){
            max_l=i-mp[sum+n]
            start=mp[sum+n];
            end=i;}
        }
        else
        mp[sum+n]=i;
    }
    cout<<start<<" "<<end;
    return max_l;
} 

int main() 
{ 
	int arr[] = {1, 0, 0, 1, 0, 1, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout<<endl<<maxLen(arr, n); 
	return 0; 
} 
