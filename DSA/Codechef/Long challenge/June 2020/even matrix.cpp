#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n][n];
	    //a[0][0]=1;
	    for(int i=0;i<n;i++){
	        if(i%2==0){
	            //a[i][0]=1+i*n*2;
	            if(i==0)
	                a[i][0]=1;
                else
                    a[i][0]=a[i-1][0]+1;
	            for(int j=1;j<n;j++)
	                a[i][j]=1+a[i][j-1];
	        }
	        else{
	            a[i][n-1]=a[i-1][n-1]+1;
	            for(int j=n-2;j>=0;j--)
	                a[i][j]=a[i][j+1]+1;
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++)
	            cout<<a[i][j]<<" ";
            cout<<endl;
	    }
	}
	return 0;
}
