/* Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
  0 <= i, j < nums.length
  i != j
  a <= b
  b - a == k

Example:
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Constraints:
1 <= nums.length <= 10^4
-10^7 <= nums[i] <= 10^7
0 <= k <= 10^7 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int num:nums){
            if(k==0&&mp[num]==1)
                ans++;
            else if(mp[num]==0){
                if(mp[num-k]>0)
                    ans++;
                if(mp[num+k]>0)
                    ans++;
            }
            mp[num]++;
        }
        return ans;
    }
};
