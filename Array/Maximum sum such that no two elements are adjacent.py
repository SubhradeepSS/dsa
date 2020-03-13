def find_max_sum(arr):
    n=len(arr)
    excl=0
    incl=arr[0]
    for i in range(1,n):
        #t=incl
        excl_new=max(incl,excl)
        incl=excl+arr[i]
        excl=excl_new
    return max(excl,incl)

arr = [5, 5, 10, 100, 10, 5] 
print (find_max_sum(arr)) 
