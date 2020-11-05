class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        ans=0
        di={}
        
        for i in A:
            for j in B:
                if i+j not in di:
                    di[i+j]=1
                else:
                    di[i+j]+=1
        
        for i in C:
            for j in D:
                if -i-j in di:
                    ans+=di[-i-j]
        
        return ans
        
