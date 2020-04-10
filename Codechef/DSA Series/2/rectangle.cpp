#include <iostream>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	int n,x,y;
	int m=100001;
	cin>>n;
	int a[m];
	for(int i=0;i<m;i++)
	    a[i]=500;
	for(int i=0;i<n;i++){
	    cin>>x>>y;
	    if(a[x]>y)
	        a[x]=y;
	}
	stack<int> s;
	a[m-1]=0;
	long long int area=0;
    for(int r=1;r<m;r++){
        while(!s.empty()&&a[r]<a[s.top()]){
            int h=a[s.top()];
            s.pop();
            int l;
            if(!s.empty())
                l=s.top();
            else
                l=0;
            if((r-l)*h>area)
                area=(r-l)*h;
        }
        s.push(r);
    }
    cout<<area;
	return 0;
}
