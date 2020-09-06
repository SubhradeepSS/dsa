/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
*/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int s=trust.size();
        if(s==0)
        {
            if(N==1)
                return 1;
            return -1;
        }
        int ans,c=0;
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(auto i:trust){
            mp[i[1]]++;
            mp2[i[0]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>c&&mp2[it->first]==0){
                ans=it->first;
                c=it->second;
            }
        }
        int m=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==c)
                m++;
        }
        if(m==1)
            return ans;
        return -1;
    }
};
