#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  
// Number of Men or Women 
#define N  4 
bool m1_over_m(int prefer[][N],int w,int m1,int m){
    for(int i=0;i<N;i++){
        if(prefer[w][i]==m1)
            return true;
        if(prefer[w][i]==m)
            return false;
    }
}
void stableMarriage(int prefer[][N]){
    int n=N;
    bool mfree[n];
    int wpartner[n];
    memset(mfree,true,sizeof(mfree));
    memset(wpartner,-1,sizeof(wpartner));
    int f=n;
    while(f){
        int m,w,m1;
        for(m=0;m<n;m++)
            if(mfree[m])
                break;
        for(int i=0;i<n&&mfree[m]==true;i++){
          w=prefer[m][i];
          if(wpartner[w-n]==-1)
          {
              f--;
              wpartner[w-n]=m;
              mfree[m]=false;
          }
          else{
              m1=wpartner[w-n];
              if(!m1_over_m(prefer,w,m1,m)){
                  wpartner[w-n]=m;
                  mfree[m]=false;
                  mfree[m1]=true;
              }
          }
        }
    }
    for(int i=0;i<n;i++)
    cout<<i+n<<" "<<wpartner[i]<<endl;
}
int main() 
{ 
    int prefer[2*N][N] = { {7, 5, 6, 4}, 
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
    }; 
    stableMarriage(prefer); 
  
    return 0; 
} 
