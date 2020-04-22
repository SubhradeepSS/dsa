class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans=[]
        def f(s='',c_left=0,c_right=0):
            if len(s)==2*n:
                ans.append(s)
                return
            if c_left<n:
                f(s+'(',c_left+1,c_right)
            if c_right<c_left:
                f(s+')',c_left,c_right+1)
        f()
        return ans
