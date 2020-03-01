#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int minCost(int cost[][C],int m,int n){
    int a[m+1][n+1];
    for(int j=0;j<3;j++)
        a[0][j]=cost[0][j];
    for(int i=0;i<3;i++)
        a[i][0]=cost[i][0];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=cost[i][j]+min(a[i-1][j],min(a[i-1][j-1],a[i][j-1]));
        }
    }
    return a[m][n];
}

int main() 
{ 
int cost[R][C] = { {1, 2, 3}, 
					{4, 8, 2}, 
					{1, 5, 3} }; 
printf(" %d ", minCost(cost, 2, 2)); 
return 0; 
} 
