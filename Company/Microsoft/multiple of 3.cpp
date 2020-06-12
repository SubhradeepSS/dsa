#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int o=0,e=0;
	    for(int i=0;i<s.length();i++){
	        if(i%2&&s[i]=='1')
	            o++;
            if(i%2==0&&s[i]=='1')
                e++;
	    }
	    cout<<(abs(o-e)%3==0?"1\n":"0\n");
	}
	return 0;
}
