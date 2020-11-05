int maxSubArray(vector<int> nums) {
        int r=nums[0],s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s>r)
                r=s;
            if(s<0)
                s=0;
        }
        return r;
