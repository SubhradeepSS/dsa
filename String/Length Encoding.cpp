#include<bits/stdc++.h>
using namespace std;
void length_encoding(string s){
    int n=s.size();
    for(int i=0;i<n;i++){
        int c=1;
        while(i<n-1&&s[i]==s[i+1])
            {
                i++;
                c++;
            }
        cout<<s[i]<<c;
    }
}
int main(){
    string s="abc";
    length_encoding(s);
}
