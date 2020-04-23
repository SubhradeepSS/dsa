# Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m==0:
            return 0
        
        if m==n:
            return m
        ans=m
        
        x=int(math.log(m+1,2))
        y=int(math.log(n,2))
        if x!=y:
            return 0
        
        for i in range(m+1,n+1):
            ans=ans&i
        
        return ans
