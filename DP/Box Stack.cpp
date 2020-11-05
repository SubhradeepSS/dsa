#include<bits/stdc++.h>
using namespace std;

struct Box{
  int h,w,d;
};
int compare(const void *a,const void *b){
    int a1=(*(Box *)b).d*(*(Box *)b).w;
    int a2=(*(Box *)a).d*(*(Box *)a).w;
    return a1-a2;
}
int maxStackHeight(Box arr[],int n){
    Box result[3*n];
    int j=0;
    for(int i=0;i<n;i++){
        result[j].h=arr[i].h;
        result[j].w=max(arr[i].w,arr[i].d);
        result[j].d=min(arr[i].w,arr[i].d);
        j++;
        result[j].h=arr[i].w;
        result[j].w=max(arr[i].h,arr[i].d);
        result[j].d=min(arr[i].h,arr[i].d);
        j++;
        result[j].h=arr[i].d;
        result[j].w=max(arr[i].w,arr[i].h);
        result[j].d=min(arr[i].w,arr[i].h);
        j++;
    }
    int max1[3*n];
    n=3*n;
    int r=-1;
    qsort(result,n,sizeof(result[0]),compare);
    for(int i=0;i<n;i++)
        max1[i]=result[i].h;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(result[j].w>result[i].w&&result[j].d>result[i].d&&max1[j]+result[i].h>max1[i])
            max1[i]=result[i].h+max1[j];
        }
        r=max(r,max1[i]);
    }
    return r;
}
int main() 
{ 
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  printf("The maximum possible height of stack is %d\n", 
         maxStackHeight (arr, n) ); 
  
  return 0; 
} 
