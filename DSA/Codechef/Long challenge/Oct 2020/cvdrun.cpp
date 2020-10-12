#include <iostream>
#include <vector>
using namespace std;

string solve(int n,int k,int x,int y){
    if(k==0){
        return (x==y ? "YES": "NO");
    }
    
    int i=x;
    do{
        if(i==y){
            return "YES";
        }
        i=(i+k)%n;
    }while(i!=x);
    
    return "NO";
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k,x,y;
	    cin>>n>>k>>x>>y;
	    cout<<solve(n,k,x,y)<<endl;
	}
	return 0;
}