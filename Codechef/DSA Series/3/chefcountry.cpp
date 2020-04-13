#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	string s,cr;
	int c;
	map<string,ll> count;
	map<string,ll> country;
	map<string,string> chef_country;
	while(n--){
	    cin>>s>>cr;
	    chef_country[s]=cr;
	}
	while(m--){
	    cin>>s;
	    count[s]++;
	    country[chef_country[s]]++;
	}
	ll max_c=0;
	string ans_chef;
	for(auto i=count.begin();i!=count.end();i++){
	    if(i->second>max_c)
	        {
	            max_c=i->second;
	            ans_chef=i->first;
	        }
	}
	ll max_c1=0;
	string country_ans;
	for(auto i=country.begin();i!=country.end();i++){
	    if(i->second>max_c1)
	        {
	            max_c1=i->second;
	            country_ans=i->first;
	        }
	}
	cout<<country_ans<<endl<<ans_chef;
	return 0;
}
