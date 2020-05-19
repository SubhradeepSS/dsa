class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        vector<int> c1(26,0);
        for(int i=0;i<s1.length();i++)
            c1[s1[i]-'a']++;
        vector<int> curr(26,0);
        int prev=0,i=0;
        while(i<s1.length()){
            curr[s2[i]-'a']++;
            i++;
        }
        if(curr==c1)
            return true;
        curr[s2[prev]-'a']--;
        prev++;
        while(i<s2.length()){
            curr[s2[i]-'a']++;
            if(curr==c1)
                return true;
            i++;
            curr[s2[prev]-'a']--;
            prev++;
        }     
        return false;
    }
};
