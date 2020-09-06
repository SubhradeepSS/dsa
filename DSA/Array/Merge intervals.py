class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort(key=lambda x:x[0])
        if len(intervals)==0 or len(intervals)==1:
            return intervals
        i=1
        while i<len(intervals):
            if intervals[i][0]<=intervals[i-1][1]:
                intervals[i-1][1]=max(intervals[i][1],intervals[i-1][1])
                intervals.pop(i)
            else:
                i+=1
        return intervals
