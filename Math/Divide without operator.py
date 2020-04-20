class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        MAX=2**31-1
        MIN=-(2**31)
        sign=1
        if (divisor<0)^(dividend<0) == 1:
            sign=-1
        divisor=abs(divisor)
        dividend=abs(dividend)
        
        temp=0
        c=0
        i=31
        while i>=0:
            if temp+(divisor<<i)<=dividend:
                temp+=divisor<<i
                c|=1<<i
            i-=1
        
        c=c*sign
        if c<MIN or c>MAX:
            c=MAX
        return c
