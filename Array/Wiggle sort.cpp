class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v;
        v=nums;
        sort(v.begin(),v.end());
        int i=0,j=(v.size()-1)/2+1;
        for(int k=nums.size()-1;k>=0;k--){
            if(k%2)
                nums[k]=v[j++];
            else
                nums[k]=v[i++];
        }
    }
};
