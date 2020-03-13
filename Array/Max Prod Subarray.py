arr=[-1, -3, -10, 0, 60]
max_prod=arr[0]
min_prod=arr[0]
max_val=arr[0]
for i in range(1,len(arr)):
    if arr[i]<0:
        max_prod,min_prod=min_prod,max_prod
    max_prod=max(arr[i],arr[i]*max_prod)
    min_prod=min(arr[i],arr[i]*min_prod)
    max_val=max(max_val,max_prod)
print(max_prod)
