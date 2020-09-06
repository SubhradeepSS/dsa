arr=[-2, -3, 4, -1, -2, 1, 5, -3]
max_sum=arr[0]
curr_sum=arr[0]
for i in range(1,len(arr)):
    curr_sum=max(curr_sum+arr[i],arr[i])
    max_sum=max(max_sum,curr_sum)
print(max_sum)
