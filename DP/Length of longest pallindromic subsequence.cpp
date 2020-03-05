#include<bits/stdc++.h>
using namespace std;

int lps(string s){
    int n=s.length();
    int table[n][n];
    for(int i=0;i<n;i++)
        table[i][i]=1;
    for(int l=2;l<=n;l++){
        for(int i=0;i<n;i++){
            int j=i+l-1;
            if(s[i]==s[j]&&l==2)
                table[i][j]=2;
            else if(s[i]==s[j])
                table[i][j]=table[i+1][j-1]+2;
            else
                table[i][j]=max(table[i+1][j],table[i][j-1]);
        }
    }
    return table[0][n-1];
}

int main() 
{ 
    char seq[] = "GEEKS FOR GEEKS"; 
    int n = strlen(seq); 
    printf ("The length of the LPS is %d", lps(seq)); 
    getchar(); 
    return 0; 
} 
