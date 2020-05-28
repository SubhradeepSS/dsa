#include <iostream>
#include <stdio.h>
#define mod 1000000007
using namespace std;

long long num,den;

long long power(long long a,long long b){
    long long ans=1;
    while(b){
        if(b%2)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}

long long modinv(long long a){
    return power(a,mod-2);
}

long long bin(long long n,long long k){
    num=(num*(n+k-1))%mod;
    den=(den*k)%mod;
    return (num*(modinv(den)))%mod;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//long long int mod=1000000007;
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,x;
	    num=1;
	    den=1;
	    long long int m;
	    scanf("%d %d %lld",&n,&x,&m);
	    long long int a[n+1];
	    a[0]=0;
	    for(int i=0;i<n;i++)
	        scanf("%lld",&a[i+1]);
        if(x==1){
            printf("%lld\n",a[1]%mod);
            continue;
        }
       if(x==2){
           long long int q=a[2]%mod,r=((a[1]%mod)*(m%mod))%mod;
           printf("%lld\n",(q+r)%mod);
           continue;
       }
       for(int i=1;i<=x;i++)
        a[i]%=mod;
       long long ans=a[x];
       m%=mod;
       for(int i=x-1,j=1;i>=1;i--,j++){
           long long temp=(a[i]*bin(m,j))%mod;
           ans=(ans+temp)%mod;
       }
       printf("%lld\n",ans);
	}
	return 0;
}
