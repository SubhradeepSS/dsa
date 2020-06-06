#include <iostream>
using namespace std;

bool f(int count[],int a[],int n){
    for(int i=0;i<n;i++){
        if(a[i]==5)
            count[0]++;
        else if(a[i]==10){
            if(count[0]<=0)
                return false;
            count[0]--;
            count[1]++;
        }
        else{
           if(count[1]>0)
            {
                count[1]--;
            }
            else if(count[0]>=2){
                count[0]-=2;
            }
            else
                return false;
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
	    int count[2]={0,0};
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        
        f(count,a,n)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
