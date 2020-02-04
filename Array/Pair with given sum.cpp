#include <bits/stdc++.h> 

using namespace std; 

void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s;
	for(int i=0;i<arr_size;i++){
	    int a=sum-arr[i];
	    if(s.find(a)!=s.end()){
	        cout<<a<<" "<<arr[i];
	        return;
	    }
	    s.insert(arr[i]);
	}
} 

int main() 
{ 
	int A[] = { 1, 4, 45, 6, 10, 8 }; 
	int n = 16; 
	int arr_size = sizeof(A) / sizeof(A[0]); 

	printPairs(A, arr_size, n); 

	return 0; 
} 
