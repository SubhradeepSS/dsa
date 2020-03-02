#include<bits/stdc++.h>
using namespace std;

int LCSubStr(char x[],char y[],int m,int n){
    int r=0;
    int table[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
                table[i][j]=0;
            else if(x[i-1]==y[j-1]){
                table[i][j]=table[i-1][j-1]+1;
                r=max(r,table[i][j]);}
            else
                table[i][j]=0;
        }
    }
    return r;
}

int main() 
{ 
    char X[] = "OldSite:GeeksforGeeks.org"; 
    char Y[] = "NewSite:GeeksQuiz.com"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    cout << "Length of Longest Common Substring is " 
         << LCSubStr(X, Y, m, n); 
    return 0; 
} 
