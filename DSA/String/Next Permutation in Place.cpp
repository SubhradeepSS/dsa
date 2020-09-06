void nextPermutation(vector<int>& nums) {
        vector<int> s;
        s=nums;
        sort(nums.begin(),nums.end(),greater<char>());
        if(s==nums)
            sort(nums.begin(),nums.end());
        else{
            nums=s;
            next_permutation(nums.begin(),nums.end());
        }       
    }
