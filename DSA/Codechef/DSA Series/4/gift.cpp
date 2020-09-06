#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll x,b,c;
	    cin>>x;
	    cin>>b;
	    vector<ll> dish_dist(b);
	    vector<ll> dish_cap(b);
	    ll sum=1;
	    for(ll i=0;i<b;i++){
	        cin>>dish_dist[i]>>dish_cap[i];
	        sum+=dish_cap[i];
	    }
	    cin>>c;
	    if(c==0)
	        {
	            cout<<sum<<endl;
	            continue;
	        }
	    vector<ll> clan_dist(c);
	    vector<ll> clan_cap(c);
	    vector<ll> clan_min(c);
	    for(ll i=0;i<c;i++){
	        cin>>clan_dist[i]>>clan_min[i]>>clan_cap[i];
	    }
	    ll i=b-1,j=c-1,ans=1;
	    while(dish_dist[i]<clan_dist[j])
	        j--;
	    
	    while(i>=0){
	        ans+=dish_cap[i];
	        i--;
	        while(j>=0&&clan_dist[j]>dish_dist[i]){
	            if(ans>clan_min[j]){
	                if(ans>clan_cap[j]+clan_min[j])
	                    ans-=clan_cap[j];
                    else
                        ans=clan_min[j];
	            }
	            j--;
	        }
	    }
    	  while(j>=0){
            if(ans>clan_min[j]){
                if(ans>clan_cap[j]+clan_min[j])
                    ans-=clan_cap[j];
                else
                    ans=clan_min[j];
            }
            j--;
        }
        cout<<ans<<endl;
	}
	return 0;
}
