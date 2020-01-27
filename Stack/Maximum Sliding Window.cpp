    \\Simple using STL

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=0;i+k-1<nums.size();i++){
            v.push_back(*max_element(nums.begin()+i,nums.begin()+i+k));
        }
        return v;
    }
    
   \\ Using deque 
   
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        if(nums.size()==0){
            return v;
        }
        deque<int> d;
        int i;
        for(i=0;i<k;i++){
            while(!d.empty()&&nums[i]>=nums[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        for(;i<nums.size();i++){
            v.push_back(nums[d.front()]);
            while(!d.empty()&&d.front()<=i-k)
                d.pop_front();
            while(!d.empty()&&nums[i]>=nums[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        v.push_back(nums[d.front()]);
        return v;
    } 
