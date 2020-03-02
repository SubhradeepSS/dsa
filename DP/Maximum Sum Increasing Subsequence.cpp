#include<bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[],int n){
    int m=arr[0];
    int table[n];
    for(int i=0;i<n;i++)
        table[i]=arr[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&&table[i]<table[j]+arr[i])
                table[i]=table[j]+arr[i];
        }
        m=max(m,table[i]);
    }
    return m;
}

int main()  
{  
    int arr[] = {1, 101, 2, 3, 100, 4, 5};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout << "Sum of maximum sum increasing "
            "subsequence is " << maxSumIS( arr, n ) << endl;  
    return 0;  
}  
