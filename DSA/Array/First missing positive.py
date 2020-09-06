class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 1
        j=0
        
        for i in range(len(nums)):
            if nums[i]<=0:
                nums[i],nums[j]=nums[j],nums[i]
                j+=1
        
        if j==len(nums):
            return 1
        
        nums=nums[j:]
        n=len(nums)
        
        for i in range(n):
            if abs(nums[i])-1<n and nums[abs(nums[i])-1]>0:
                nums[abs(nums[i])-1]*=-1
        
        for i in range(n):
            if nums[i]>0:
                return i+1
        return n+1
