a=[2, 3, 4, 1, 4, 5]
left_sum,right_sum=0,0
for i in range(1,len(a)):
    right_sum+=a[i]
i=0
for j in range(1,len(a)):
    left_sum+=a[i]
    right_sum-=a[j]
    if left_sum==right_sum:
        print(i+1)
    i+=1
