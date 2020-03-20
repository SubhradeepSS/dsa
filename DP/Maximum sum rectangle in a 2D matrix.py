ROW = 4
COL = 5

def kadane(arr):
    finish=-1
    start=0
    sum_a=0
    for i in range(len(arr)):
        sum_a+=arr[i]
        if sum_a<0:
            start=i+1
            sum_a=0
        else:
            finish=i
    if finish!=-1:
        return sum_a,start,finish
    sum_a=arr[0]
    for i in range(1,len(arr)):
        if arr[i]>sum_a:
            sum_a=arr[i]
            start=i
            finish=i
    return sum_a,start,finish
    
def findMaxSum(matrix):
    max_sum=-9999999999
    sum_a,LEFT,RIGHT,TOP,BOTTOM=None,None,None,None,None
    for left in range(COL):
        temp=[0]*(ROW)
        for right in range(left,COL):
            for i in range(ROW):
                temp[i]+=matrix[i][right]
            sum_a,start_local,finish_local=kadane(temp)
            
            if sum_a>max_sum:
                max_sum=sum_a
                TOP=start_local
                BOTTOM=finish_local
                LEFT=left
                RIGHT=right
                
    
    print(max_sum)
    print(LEFT,RIGHT,TOP,BOTTOM)


M = [[1, 2, -1, -4, -20], 
     [-8, -3, 4, 2, 1],  
     [3, 8, 10, 1, 3],  
     [-4, -1, 1, 7, -6]]  
  
findMaxSum(M) 
