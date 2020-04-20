class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def util(a,l,h,n):
            m=(l+h)//2
            if (m==0 or a[m-1]<a[m]) and (m==n-1 or a[m+1]<a[m]):
                return m
            elif m>0 and a[m-1]>a[m]:
                return util(a,l,m-1,n)
            return util(a,m+1,h,n)
        
        return util(nums,0,len(nums)-1,len(nums))
