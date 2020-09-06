vector<int> singleNumber(vector<int>& nums) {
        int r=nums[0];
        for(int i=1;i<nums.size();i++)
            r^=nums[i];
        int x=0,y=0;
        int a=r&(~(r-1));
        for(int i=0;i<nums.size();i++){
            if(a&nums[i])
                x^=nums[i];
            else
                y^=nums[i];
        }
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        return v; 
    }
