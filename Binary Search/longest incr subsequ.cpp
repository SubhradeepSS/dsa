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
