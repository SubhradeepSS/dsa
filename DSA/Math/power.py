class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        p=abs(n)
        
        def util(x,n):
            if n==0:
                return 1
            a=util(x,n//2)
            if n%2==0:
                return a*a
            return x*a*a
        
        ans=util(x,p)
        if n<0:
            return 1/ans
        return ans
