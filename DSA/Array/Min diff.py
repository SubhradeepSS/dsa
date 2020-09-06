a=[1, 5, 3, 19, 18, 25]
a.sort()
#print(a)
min_diff=a[1]-a[0]
for i in range(1,len(a)-1):
    min_diff=min(min_diff,a[i+1]-a[i])
print(min_diff)
