class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans=[]
        for i in s:
            ans.append(ord(i)-ord('A')+1)
        #print(ans)
        c=0
        for i in ans:
            c=c*26+i
        return c
