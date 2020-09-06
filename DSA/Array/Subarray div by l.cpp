// Count of subarrays divisible by l
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,l;
    cin>>n>>l;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    vector<ll> mod(l,0);
    ll curr=0;
    for(int i=0;i<n;i++){
        curr+=a[i];
        mod[(curr%l+l)%l]++;
    }
    ll ans=0;
    for(int i=0;i<l;i++){
        if(mod[i]>1)
            ans+=mod[i]*(mod[i]-1)/2;
    }
    cout<<ans+mod[0];
    return 0;
}
