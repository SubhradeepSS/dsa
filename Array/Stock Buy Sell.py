def stock(arr,n):
    i=0
    while i<n:
        while i<n-1 and arr[i+1]<=arr[i]:
            i+=1
        if i==n-1:
            break
        buy=i
        i+=1
        while i<n-1 and arr[i+1]>=arr[i]:
            i+=1
        sell=i
        print(buy,sell)
        
    
arr=[ 100, 180, 260, 310, 40, 535, 695 ]
stock(arr,len(arr))
