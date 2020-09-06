class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for(int i:nums){
            if(s.insert(i).second){
                auto it=s.find(i);
                it++;
                if(it!=s.end())
                    s.erase(it);
            }
        }
        return s.size();
    }
};

// added another
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        int l=1;
        vector<int> e(n);
        e[0]=a[0];
        
        for(int i=1;i<n;i++){
            auto it=lower_bound(e.begin(),e.begin()+l,a[i]);
            if(it==e.begin()+l)
                e[l++]=a[i];
            else
                *it=a[i];
        }
        cout<<l<<endl;
	}
	return 0;
}
