/* # Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0

# Brute
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        power = [[nums[j] for j in range(n) if i&(1<<j)] for i in range(1<<n)]
        
        for i in power:
            i.sort()
        
        ans = []
        
        for s in power:
            f = 0
            for i in range(1,len(s)):
                if s[i]%s[i-1]!=0:
                    f=1
                    break
            if f==0 and len(s)>len(ans):
                ans = [num for num in s]
        
        return ans
  
  # */
  
  class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return {};
        sort(nums.begin(),nums.end());
        
        vector<int> div(n,1);
        vector<int> prev(n,-1);
        int l=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&div[j]+1>div[i]){
                    prev[i]=j;
                    div[i]=div[j]+1;
                }
            }
            if(div[l]<div[i])
                l=i;
        }
        
        vector<int> ans;
        
        while(l>=0){
            ans.push_back(nums[l]);
            l=prev[l];
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
