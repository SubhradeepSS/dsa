class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        l=1
        ans=""
        if len(s)==0:
            return 0
        if len(s)==1:
            return 1
        for i in s:
            if i not in ans:
                ans+=i
            else:
                l=max(l,len(ans))
                ans=ans[ans.index(i)+1:]
                ans+=i
        l=max(l,len(ans))
        return l
