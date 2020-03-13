def all9(arr,n):
    for i in range(n):
        if arr[i]!=9:
            return False
    return True
  
def generateNextPalindromeUtil(arr,n):
    mid=n//2
    i=mid-1
    leftsmaller=False
    j=mid+1 if n%2 else mid
    while i>=0 and arr[i]==arr[j]:
        i-=1
        j+=1
    if i<0 or arr[i]<arr[j]:
        leftsmaller=True
    j=mid+1 if n%2 else mid
    while i>=0 and arr[i]==arr[j]:
        arr[j]=arr[i]
        i-=1
        j+=1
    if leftsmaller:
        carry=1
        i=mid-1
        if n%2:
            arr[mid]+=carry
            carry=arr[mid]//10
            arr[mid]%=10
            j=mid+1
        else:
            j=mid
        while i>=0:
            arr[i]+=carry
            carry=arr[i]//10
            arr[i]%=10
            arr[j]=arr[i]
            i-=1
            j+=1
   
def generateNextPalindrome(arr,n):
    if all9(arr,n):
        print(1,end='')
        for i in range(1,n):
            print(0,end='')
        print(1)
    else:
        generateNextPalindromeUtil(arr,n)
        printArray(arr,n)
            
def printArray(arr, n):  
    for i in range(0, n):  
        print(int(arr[i]),end=" ")  
    print()  
  

if __name__ == "__main__": 
    num = [9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2] 
    n = len(num) 
    generateNextPalindrome( num, n )  
