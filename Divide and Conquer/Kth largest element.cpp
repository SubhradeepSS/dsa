int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=nums[nums.size()-1];
        k--;
        for(int i=nums.size()-2;i>=0;i--){
            k--;
           if(k==0)
                return nums[i];
        }
        return j;
    }
