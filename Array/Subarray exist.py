def subArrayExists(arr,n): 
	s=set()
	sum=0
	for i in range(0,n):
	    sum+=arr[i]
	    if sum==0 or sum in s:
	        return True
	return False

arr = [-3, 0, 3, 1, 6] 
n = len(arr) 
if subArrayExists(arr, n) == True: 
	print("Found a sunbarray with 0 sum") 
else: 
	print("No Such sub array exits!") 
