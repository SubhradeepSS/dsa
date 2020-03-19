def ncr(n,r):
    res=1
    for i in range(r):
        res*=(n-i)/(i+1)
    return res
    
print(ncr(5,3))
