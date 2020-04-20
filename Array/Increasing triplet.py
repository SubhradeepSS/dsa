class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        small=[-1]*len(nums)
        large=[-1]*len(nums)
        
        min_i=0
        max_i=len(nums)-1
        for i in range(1,len(nums)):
            if nums[i]<=nums[min_i]:
                small[i]=-1
                min_i=i
            else:
                small[i]=min_i
        
        for i in range(len(nums)-1,-1,-1):
            if nums[i]>=nums[max_i]:
                max_i=i
                large[i]=-1
            else:
                large[i]=max_i
        
        for i in range(len(nums)):
            if small[i]!=-1 and large[i]!=-1:
                return True
        return False
