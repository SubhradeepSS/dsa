a=[2, 3, 10, 6, 4, 8, 1]
max_diff=a[1]-a[0]
min_element=a[0]
for i in range(1,len(a)):
    max_diff=max(max_diff,a[i]-min_element)
    min_element=min(min_element,a[i])
print(max_diff)
