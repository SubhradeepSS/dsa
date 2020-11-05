"""
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
"""
class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        if len(s)==0:
            return 0
        for i,val in enumerate(s):
            if val!=' ':
                s=s[i:]
                break
        if len(s)==0:
            return 0
        if s[0]!='-' and s[0].isdigit()==False and s[0]!='+':
            return 0
        f=1
        if s[0]=='-':
            f=-1
            s=s[1:]
            
        elif s[0]=='+':
            s=s[1:]
        if len(s)==0:
            return 0
        for i,val in enumerate(s):
            if val.isdigit()==False:
                s=s[:i]
                break
        if len(s)==0:
            return 0
        if f==1:
            if int(s,10)>=2**31-1:
                return 2**31-1
            
        else:
            if int(s,10)>=2**31:
                return -(2**31)
        return f*int(s,10)
        
