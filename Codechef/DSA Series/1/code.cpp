//https://www.codechef.com/LRNDSA01/problems/MULTHREE/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,d0,d1;
	long long int k;
    cin>>t;
    while(t--){
        cin>>k>>d0>>d1;
        long long int s=0;
        if(k==2)
            s=d0+d1;
        s+=d1+d0+(d1+d0)%10;
        if(k>3){
            k-=3;
            int x=d0+d1;
            int a=(x*2)%10,b=(x*4)%10,c=(x*8)%10,d=(x*6)%10;
            s+=((a+b+c+d)*(k/4));
            if(k%4==1)
                s+=a;
            else if(k%4==2)
                s+=(a+b);
            else if(k%4==3)
                s+=(a+b+c);
        }
        if(s%3)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
	return 0;
}

