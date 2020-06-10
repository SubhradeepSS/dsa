// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i= upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i>0&&nums[i-1]==target)
            return i-1;
        return i;
    }
};
