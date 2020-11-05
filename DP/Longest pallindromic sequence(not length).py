class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s)==0:
            return ''
        if len(s)==1:
            return s
        if len(s)==2 and s[0]==s[1]:
            return s
        if len(s)==2 and s[0]!=s[1]:
            return s[0]
        l=[[False for i in range(len(s))] for j in range(len(s))]
        lmax=1
        imax=None
        jmax=None
        for i in range(len(s)):
            l[i][i]=True
        for L in range(2,len(s)+1):
            for i in range(0,len(s)-L+1):
                j=i+L-1
                if L==2:
                    if s[i]==s[j]:
                        l[i][j]=True
                else:
                    if l[i+1][j-1]==True and s[i]==s[j]:
                        l[i][j]=True
                if l[i][j]==True and L>lmax:
                    lmax=L
                    imax=i
                    jmax=j
        if lmax==1:
            return s[0]
        return s[imax:jmax+1]
        
