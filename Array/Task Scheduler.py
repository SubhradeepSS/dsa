"""
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
You need to return the least number of intervals the CPU will take to finish all the given tasks.
"""
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        d1={}
        for i in range(26):
            d1.update({i:0})
        
        for i in tasks:
            d1[ord(i)-ord('A')]+=1
        
        d=sorted(d1.items(),key=lambda x:(x[1],x[0]))
        
        i=24
        max_val= d[25][1]-1
        idle_slots=max_val*n
        
        while i>=0:
            if d[i][1]>0:
                idle_slots-=min(d[i][1],max_val)
            i-=1
        
        if idle_slots>0:
            return len(tasks)+idle_slots
        return len(tasks)
