#include<bits/stdc++.h>
using namespace std;
void lexicographic(string s){
    string a=s;
    int c=1;
    sort(a.begin(),a.end());
    do{
        if(a==s){
            break;
        }
        else c++;
    }while(next_permutation(a.begin(),a.end()));
    cout<<s<<" "<<c;
}
int main(){
    string s="hello";
    lexicographic(s);
}
