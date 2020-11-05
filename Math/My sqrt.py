class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==1 or x==0:
            return x
        l=1
        h=x
        while l<h:
            m=(l+h)//2
            if m*m==x:
                return m
            if m*m<x and (m+1)*(m+1)>x:
                return m
            if m*m<x:
                l=m+1
            else:
                h=m-1
        return l
