#include<bits/stdc++.h>
using namespace std;
#define R 6
#define C 5
void printMaxSubSquare(int M[][C]){
    int s[R][C],m=0,n=0;
    for(int i=0;i<R;i++)
        s[i][0]=M[i][0];
    for(int i=0;i<C;i++)
        s[0][i]=M[0][i];
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            if(M[i][j])
                s[i][j]=min(s[i-1][j],min(s[i-1][j-1],s[i][j-1]))+1;
            else
                s[i][j]=0;
        }
    }
    int max=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
           if(s[i][j]>max){
               max=s[i][j];
               m=i;
               n=j;
           } 
        }
    }
    for(int i=m-max+1;i<=m;i++){
        for(int j=n-max+1;j<=n;j++)
            cout<<M[i][j]<<" ";
            cout<<endl;
    }
}
int main()  
{  
    int M[R][C] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}};  
                      
    printMaxSubSquare(M);  
}  
