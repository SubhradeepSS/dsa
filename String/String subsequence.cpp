/*
Given a string s and a string t, check if s is subsequence of t.
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(auto ch:t){
            if(ch==s[i])
                i++;
        }
        return i>=s.length();
    }
};
