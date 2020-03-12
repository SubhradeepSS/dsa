a=[1, 60, -10, 70, -80, 85]
a.sort()
#print(a)
i=0
j=len(a)-1
l=-1
r=-1
sum_closest_to_zero=abs(a[1]-a[0])
while i<j:
    if sum_closest_to_zero>=abs(a[j]+a[i]):
        l=i
        r=j
        sum_closest_to_zero=abs(a[j]+a[i])
    if a[j]+a[i]>0:
        j-=1
    else:
        i+=1
if l!=-1 and r!=-1:
    print(a[l],a[r],sum_closest_to_zero)
