/* Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167 */
             
// Modified Matrix chain multiplication

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        vector<int> v=nums;
        v.insert(v.begin(),1);
        v.push_back(1);
                    
        int n=v.size();
        int dp[n][n];
        
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        
        for(int l=2;l<n;l++){
            for(int i=1;i<n-l+1;i++){
                int j=i+l-1;
                dp[i][j]=INT_MIN;
                
                for(int k=i;k<j;k++){
                    dp[i][j]=max(dp[i][j], dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
                }
            }
        }
        return dp[1][n-1];
    }
};
