class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return ''
        if len(strs)==1:
            return strs[0]
        strs.sort()
        i=0
        s1=strs[0]
        s2=strs[-1]
        while i<min(len(s1),len(s2)):
            if s1[i]!=s2[i]:
                break
            i+=1
        if i==0:
            return ''
        return s1[:i]
