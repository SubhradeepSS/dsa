class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s=set(nums)
        ans=0
        for i in nums:
            if i-1 not in s:
                num=i
                curr=1
                while num+1 in s:
                    curr+=1
                    num+=1
            
                ans=max(ans,curr)
        
        return ans
