#include <bits/stdc++.h> 
using namespace std; 

void sum_sub(int arr[], int n,int sum) 
{ 
    int curr=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(sum==curr){
            cout<<"0 to "<<i<<endl;
        }
        if(mp.find(curr-sum)!=mp.end())
            cout<<mp[curr-sum]+1<<" to "<<i<<endl;
        else
        mp[curr]=i;
    }
} 

int main() 
{ 
	int arr[] = {10, 2, -2, -20, 10}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
    sum_sub(arr, n,10); 
	return 0; 
} 
