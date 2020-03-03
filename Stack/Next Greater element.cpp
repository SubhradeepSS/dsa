#include<bits/stdc++.h>
using namespace std;

void printNGE(int arr[],int n){
    stack<int> s;
    int r[n];
    r[n-1]=-1;
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!s.empty()&&arr[i]>=s.top())
            s.pop();
        if(s.empty())
            r[i]=-1;
        else
            r[i]=s.top();
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++)
        cout<<r[i]<<" ";
}
int main() { 
  int arr[] = {4, 5, 2, 25}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  printNGE(arr, n); 
  return 0; 
}
