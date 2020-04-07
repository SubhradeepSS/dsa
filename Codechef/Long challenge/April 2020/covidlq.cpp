#include <iostream>
using namespace std;

bool func(int a[],int n){
    int c=-1;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            if(c!=-1){
                if(i-c<6)
                    return false;
            }
            c=i;
        }
    }
    return true;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	   }
	   if(func(a,n))
	    cout<<"YES"<<endl;
	   else
	    cout<<"NO"<<endl;
	}
	return 0;
}
