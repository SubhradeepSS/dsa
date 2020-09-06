from Queue import PriorityQueue
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        pq=PriorityQueue()
        
        for i in range(len(matrix)):
            pq.put((matrix[i][0],i,0))
        
        # r=[]
        n=len(matrix)
        
        while not pq.empty():
            val,row,column=pq.get()
            k-=1
            if k==0:
                return val
            
            if column+1<n:
                pq.put((matrix[row][column+1],row,column+1))
        
        return -1
