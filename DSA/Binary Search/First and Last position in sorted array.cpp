vector<int> searchRange(vector<int>& nums, int target) {
        auto l=lower_bound(nums.begin(),nums.end(),target);
        vector<int> v;
        if(l==nums.end()||*l!=target)
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        auto h=upper_bound(nums.begin(),nums.end(),target);
        v.push_back(l-nums.begin());
        v.push_back(h-nums.begin()-1);
        return v;
    }
