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
