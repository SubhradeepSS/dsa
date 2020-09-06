#include<bits/stdc++.h>
using namespace std;

int cutRod(int arr[],int n){
    int table[n+1];
    table[0]=0;
    for(int i=1;i<=n;i++){
        table[i]=-1;
        for(int j=0;j<i;j++)
            table[i]=max(table[i],table[i-j-1]+arr[j]);
    }
    return table[n];
}
int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %d", cutRod(arr, size)); 
    getchar(); 
    return 0; 
} 
