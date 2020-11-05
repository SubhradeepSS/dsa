#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		vector<ll> v1;
		v1.push_back(-1);
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]%2==0)
			{
				v1.push_back(i);
			} 
		}
		v1.push_back(n);
		long long int sum=0,result=0;
		for(long long int i=1;i<v1.size()-1;i++)
		{
			if(v[v1[i]]%4!=0 )
			{
		    long long int m=v1[i]-v1[i-1]-1;
			long long int l=v1[i+1]-v1[i]-1;
			long long int p=m+l+1;
			result=(p*(p+1)/2)-(m*(m+1)/2)-(l*(l+1)/2);
				sum=sum+result;
			}
		}
		cout<<(n*(n+1)/2)-sum<<endl;
 
 
 
	}
	return 0;
}
