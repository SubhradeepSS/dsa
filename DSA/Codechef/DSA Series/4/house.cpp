#include <iostream>
using namespace std;

bool query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    string ans;
    cin>>ans;
    return (ans=="YES"?true:false);
}

int xcord(int y){
    int l=1,r=1000;
    while(l<r){
        int m=(l+r+1)/2;
        if(query(m,y))
            l=m;
        else
            r=m-1;
    }
    return l;
}

int ycord(int x){
    int l=1,r=1000;
    while(l<r){
        int m=(l+r+1)/2;
        if(query(x,m))
            l=m;
        else
            r=m-1;
    }
    return l;
}

int main() {
	// your code goes here
	int a=2*xcord(0);
	int triangle_h=ycord(0)-a;
	int tr_base_half=xcord(a);
	cout<<"! "<<a*a+tr_base_half*triangle_h;
	return 0;
}
