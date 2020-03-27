#include<bits/stdc++.h>
#define M 6
#define N 6
using namespace std;

bool util(bool bpGraph[][N],int i,int match[],bool seen[]){
    for(int j=0;j<N;j++){
        if(!seen[j]&&bpGraph[i][j]){
            seen[j]=true;
            if(match[j]==-1||util(bpGraph,match[j],match,seen))
                {match[j]=i;
                return true;}
        }
    }
    return false;
}

int maxBPM(bool bpGraph[][N]){
    int r=0;
    int match[N];
    memset(match,-1,sizeof(match));
    for(int i=0;i<M;i++){
        bool seen[N];
         memset(seen,0,sizeof(seen));
        if(util(bpGraph,i,match,seen))
            r++;
    }
    return r;
}

int main() 
{ 
    // Let us create a bpGraph  
    // shown in the above example 
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0}, 
                          {1, 0, 0, 1, 0, 0}, 
                          {0, 0, 1, 0, 0, 0}, 
                          {0, 0, 1, 1, 0, 0}, 
                          {0, 0, 0, 0, 0, 0}, 
                          {0, 0, 0, 0, 0, 1}}; 
  
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph); 
  
    return 0; 
} 
