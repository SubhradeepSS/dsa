#include<bits/stdc++.h>
using namespace std;
void lexicographic(string s){
    string a=s;
    int c=1;
    sort(a.begin(),a.end());
    do{
        if(a==s){
            break;
        }
        else c++;
    }while(next_permutation(a.begin(),a.end()));
    cout<<s<<" "<<c;
}
int main(){
    string s="hello";
    lexicographic(s);
}

// without stl
#include <iostream>
#define m 1000003
using namespace std;

typedef long long int ll;

ll fact(int n){
    if(n<=1)
        return 1;
    return n*fact(n-1);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int fl=0;
	    int count[256]={0};
	    for(int i=0;s[i];i++){
	        count[s[i]]++;
	        if(count[s[i]]>1){
	            fl=1;
	            break;
	        }
	    }
	    if(fl==1){  // just for result=0 if repeating characters present
	        cout<<0<<endl;
	        continue; 
	    }
        for(int i=1;i<256;i++)
            count[i]+=count[i-1];
        int l=s.length();
        ll f=fact(l);
        ll ans=1;
        for(int i=0;i<l;i++){
            f/=l-i;
            ans=(ans+((count[s[i]-1]%m)*(f%m))%m)%m;
            for(int j=s[i];j<256;j++)
                count[j]--;
        }
        cout<<ans<<endl;
	}
	return 0;
}
