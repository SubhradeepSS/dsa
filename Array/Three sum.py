"""
No same pairs
"""
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans=set()
        nums.sort()
        for i in range(len(nums)-1):
            s=set()
            for j in range(i+1,len(nums)):
                a=-nums[i]-nums[j]
                """p1=(a,nums[i],nums[j])
                p2=(nums[i],a,nums[j])
                p3=(nums[j],a,nums[i])
                p4=(a,nums[j],nums[i])
                p5=(nums[j],nums[i],a)"""
                if a in s:
                    ans.add((nums[i],nums[j],a))
                else:
                    s.add(nums[j])
        return list(map(list,ans))
