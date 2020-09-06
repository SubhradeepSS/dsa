# Python
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count=collections.Counter(nums)
        return heapq.nlargest(k,count.keys(),key=count.get)
        
# Added C++ version
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        
        vector<int> ans;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }
        
        while(k--){
            auto p=pq.top();
            pq.pop();
            
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
