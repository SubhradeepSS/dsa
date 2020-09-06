class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        m=n
        c=0
        while m>0:
            c+=m//5
            m//=5
        return c
