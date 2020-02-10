#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
  if(n<=1)
    return false;
  if(n<=3)
    return true;
  if(n%2==0||n%3==0)
    return false;
  for(int i=5;i*i<=n;i+=6)
    if(n%i==0||n%(i+2)==0)
      return false;
   return true;
}
bool is_prime(int a,int b){
  if(abs(a-b)==1&&prime(a+b))
    return true;
   return false;
}
int main(){
  int a=5,b=6;
  cout<<is_prime(a,b)?"Diff of squares are prime:Diffvof squares are not prime";
  return 0;
}
