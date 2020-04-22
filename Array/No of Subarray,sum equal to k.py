class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        s={}
        c=0
        sum_util=[i for i in nums]
        if sum_util[0]==k:
            c+=1
        s.update({sum_util[0]:1})
        #s.add(0)
        for i in range(1,len(nums)):
            sum_util[i]+=sum_util[i-1]
            if sum_util[i]==k:
                c+=1
            if sum_util[i]-k in s:
                c+=s[sum_util[i]-k]
                
            if sum_util[i] not in s:
                s.update({sum_util[i]:1})
            else:
                s[sum_util[i]]+=1
        
        return c
