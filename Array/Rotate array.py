def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

def leftRotate(arr,d):
    n=len(arr)
    for i in range(0,gcd(n,d)):
        t=arr[i]
        j=i
        while True:
            k=j+d
            if k>=n:
                k=k-n
            if k==i:
                break
            arr[j]=arr[k]
            j=k
        arr[j]=t

arr=[3,2,1,4,5,3,6]
d=3
leftRotate(arr,d)
print(arr,end=" ")
