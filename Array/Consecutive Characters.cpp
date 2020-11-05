/* Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character. Return the power of the string.

Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only. */

class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        vector<int> p(n,0);
        p[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])
                p[i]=1+p[i-1];
            else
                p[i]=1;
        }
        return *max_element(p.begin(),p.end());
    }
};
