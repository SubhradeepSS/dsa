class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def util(l,h):
            if l>h:
                return -1
            if l==h:
                return nums[l]
            m=(l+h)//2
            
            if m&1:
                if nums[m]==nums[m-1]:
                    return util(m+1,h)
                else:
                    return util(l,m-1)
            else:
                if nums[m]==nums[m+1]:
                    return util(m+2,h)
                else:
                    return util(l,m)
        
        return util(0,len(nums)-1)
