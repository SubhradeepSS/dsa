def amount_water(arr,n):
   res,l,h,max_l,max_r=0,0,n-1,0,0
   while l<=h:
       if arr[l]<arr[h]:
           if arr[l]>max_l:
               max_l=arr[l]
           else:
                res+=max_l-arr[l]
           l+=1
       else:
            if arr[h]>max_r:
                max_r=arr[h]
            else:
                res+=max_r-arr[h]
            h-=1
   return res
    
arr=[ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ]
print(amount_water(arr,len(arr)))
