bool func(pair<char,int> a,pair<char,int> b){
        return (a.second>b.second);
    }
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> v;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++){
            v.push_back({it->first,it->second});
        }
        sort(v.begin(),v.end(),func);
        string ans="";
        for(auto it=v.begin();it!=v.end();it++){
            char c=it->first;
            int count=it->second;
            while(count--){
                ans+=c;
            }
        }
        return ans;
    }
};
