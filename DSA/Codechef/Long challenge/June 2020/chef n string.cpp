#include <iostream>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int i=0,ans=0;
	    while(i<s.length()-1){
	        if(((s[i]=='x'&&s[i+1]=='y')||(s[i]=='y'&&s[i+1]=='x'))){
	            i+=2;
                ans++;
	        }
	        else
	            i++;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
