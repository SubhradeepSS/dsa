"""
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
"""

class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        n=numerator
        d=denominator
        
        sign=1
        if n<0 and d>0:
            sign=-1
        if n>0 and d<0:
            sign=-1
        
        n=abs(n)
        d=abs(d)
        
        if n%d==0:
            if sign==-1:
                return '-'+str(n//d)
            return str(n//d)
        
        s=""
        
        if n>d:
            s+=str(n//d)
            n-=(n//d)*d
        else:
            s+='0'
            
        s+='.'
        
        di={}
        pos=0
        q=-1
        
        while n%d!=0:
            di.update({n:pos})
            pos+=1
            n=n*10
            s+=str(n//d)
            n-=(n//d)*d
            if n in di:
                q=di[n]
                break
        
        add=s.find('.')+1
        if q!=-1:
            s=s[:q+add]+'('+ s[q+add:]+')'
        if sign==-1:
            s='-'+s
        return s
