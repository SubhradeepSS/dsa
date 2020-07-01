/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
             */
class Solution {
public:
    unordered_map<string,multiset<string>> mp;
    vector<string> ans;
    
    void dfs(string curr){
        while(!mp[curr].empty()){
            auto it=mp[curr].begin();
            string dest=*it;
            mp[curr].erase(it);
            dfs(dest);
        }    
        ans.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear();
        ans.clear();
        for(auto t:tickets)
            mp[t[0]].insert(t[1]);
        
        dfs("JFK");
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
