class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        output=[]
        phone={
            '2':['a','b','c'],'3':['d','e','f'],
            '4':['g','h','i'],'5':['j','k','l'],
            '6':['m','n','o'],'7':['p','q','r','s'],
            '8':['t','u','v'],'9':['w','x','y','z']
        }
        
        def f(s,digit):
            if len(digit)==0:
                output.append(s)
            else:
                for i in phone[digit[0]]:
                    f(s+i,digit[1:])
        
        if digits:
            f("",digits)
        return output
