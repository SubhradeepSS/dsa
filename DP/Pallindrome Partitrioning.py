import sys

def pallindrome_partition(string):
    n=len(string)
    p=[[False for i in range(n)] for j in range(n)]
    cost=[0]*n
    
    for i in range(n):
        p[i][i]=True
        
    for l in range(2,n+1):
        for i in range(n-l+1):
            j=i+l-1
            if l==2:
                p[i][j]=(string[i]==string[j])
            else:
                p[i][j]=(string[i]==string[j]) and p[i+1][j-1]
    
    for i in range(n):
        if p[0][i]:
            cost[i]=0
        else:
            cost[i]=sys.maxsize
            for j in range(0,i):
                if p[j+1][i] and 1+cost[j]<cost[i]:
                    cost[i]=1+cost[j]
    return cost[n-1]

str1 = "ababbbabbababa"; 
print(pallindrome_partition(str1))
