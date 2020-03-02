#include<bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int p[],int n){
    int m[n][n];
    for(int i=1;i<n;i++)
        m[i][i]=0;
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=p[i-1]*p[k]*p[j]+m[i][k]+m[k+1][j];
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
    return m[1][n-1];
}
int main() 
{ 
    int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, size); 
 
    return 0; 
} 
