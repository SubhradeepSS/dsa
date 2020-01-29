#include<bits/stdc++.h>
using namespace std;
string remove_c(string s,string t){
    int i=0,j=0;
    bool check[256];
    for(i=0;t[i];i++)
        check[t[i]]=true;
    i=0;
    while(s[i]){
        if(check[s[i]]==false){
            s[j++]=s[i];
        }
        i++;
    }
    for(int k=j;s[k];k++)
    s[k]='\0';
    return s;
}
int main(){
    string s="helloworld";
    string t="wowl";
    cout<<remove_c(s,t);
}
