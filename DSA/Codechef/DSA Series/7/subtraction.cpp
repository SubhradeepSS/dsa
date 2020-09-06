#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<int,int> p;
typedef long long ll;


int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}

int T,N;
int a[60];
map<p,ll> mp;

ll f(int i,int g){
    if(i==N){
        if(g==1) return 1;
        else return 0;
    }
    p key = make_pair(i,g);
    if(mp.find(key)!=mp.end()) 
        return mp[key];
    return mp[key]=f(i+1,g)+f(i+1,gcd(g,a[i]));
}


int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;++i) cin>>a[i];
        mp.clear();
        ll ans = 0;
        for(int i=0;i<N;++i) ans+=f(i+1,a[i]);
        cout<<ans<<endl;
    }
    return 0;
}
