class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())
            return {};
        vector<int> cp(26,0);
        vector<int> cs(26,0);
        vector<int> ans;
        int i;
        for(i=0;i<p.length();i++)
        {
            cp[p[i]-'a']++;
            cs[s[i]-'a']++;
        }
        if(cp==cs)
            ans.push_back(0);
        int prev=1;
        cs[s[0]-'a']--;
        while(i<s.length()){
            cs[s[i]-'a']++;
            if(cs==cp)
                ans.push_back(prev);
            cs[s[prev]-'a']--;
            prev++;
            i++;
        }
        return ans;
    }
};
