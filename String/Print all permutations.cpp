#include<bits/stdc++.h>
using namespace std;
void permutation(string s){
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
}
int main(){
    string s="hello";
    permutation(s);
}

// Without stl
void f(string s,int l,int r){
    if(l==r)
        cout<<s<<" ";
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        f(s,l+1,r);
        swap(s[i],s[l]);
    }
}
