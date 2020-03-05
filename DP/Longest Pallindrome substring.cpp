#include<bits/stdc++.h>
using namespace std;

int longestPalSubstr(string s){
    int n=s.length();
    bool table[n][n];
    memset(table,false,sizeof(table));
    int maxl=1,start=0;
    for(int i=0;i<n;i++)
        table[i][i]=true;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            start=i;
            maxl=2;
            table[i][i+1]=true;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(table[i+1][j-1]&&s[i]==s[j]){
                maxl=k;
                table[i][j]=true;
                start=i;
            }
        }
    }
    for(int i=start;i<=start+maxl-1;i++)
        cout<<s[i];
    return maxl;
}

int main() 
{ 
    string str = "forgeeksskeegfor"; 
    cout << "\nLength is: " << longestPalSubstr( str ); 
    return 0; 
} 
