#include<bits/stdc++.h>
using namespace std;
void duplicate(string s){
    int count[256]={0};
    for(int i=0;s[i];i++)
        count[s[i]]++;
    for(int i=0;i<256;i++)
        {
            if(count[i]>1)
                printf("%c,count=%d\n",i,count[i]);
        }
}
int main(){
    string s="Hello World";
    duplicate(s);
}
