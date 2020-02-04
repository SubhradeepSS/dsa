#include <bits/stdc++.h> 

using namespace std; 

void printPairs(int arr[], int n) 
{ 
    unordered_set<int> s;
    int flag=0;
	for(int i=0;i<n;i++){
	    int sum=arr[i]*arr[i];
	    for(int j=0;j<n;j++){
	        int a=sum-arr[j]*arr[j];
	        if(s.find(a)!=s.end()){
	            cout<<arr[i]<<" "<<arr[j]<<" "<<(int)sqrt(arr[i]*arr[i]-arr[j]*arr[j])<<endl;
	            flag=1;
	        }
	        s.insert(arr[j]*arr[j]);
	    }
	    s.clear();
	}
	if(flag==0)
	cout<<"No triplet";
} 

int main() 
{ 
	int A[] = { 3, 4, 5, 6, 10, 8 }; 
	printPairs(A,6); 

	return 0; 
} 
