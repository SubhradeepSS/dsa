class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        
        l=[]
        
        def util(i,j,r,c):
            if i>r or j>c:
                return
            
            for k in range(j,c+1):
                l.append(matrix[i][k])
            for k in range(i+1,r+1):
                l.append(matrix[k][c])
            
            if i<r:
                k=c-1
                while k>=j:
                    l.append(matrix[r][k])
                    k-=1
            
            if j<c:
                k=r-1           
                while k>i:
                    l.append(matrix[k][j])
                    k-=1
            
            util(i+1,j+1,r-1,c-1)
            
        util(0,0,len(matrix)-1,len(matrix[0])-1)
        
        return l
