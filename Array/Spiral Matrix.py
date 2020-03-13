R=4
C=4

def print_f(a,i,j,m,n):
    if i>=m or j>=n:
        return
    for p in range(j,n):
        print(a[i][p],end=' ')
    for p in range(i+1,m):
        print(a[p][n-1],end=' ')
    if (n-1)!=j:
        p=n-2
        while p>=j:
            print(a[m-1][p],end=' ')
            p-=1
    if (m-1)!=i:
        p=n-2
        while p>i:
            print(a[p][j],end=' ')
            p-=1
            
    print_f(a,i+1,j+1,m-1,n-1)

a = [ [ 1, 2, 3, 4 ], 
                    [ 5, 6, 7, 8 ], 
                    [ 9, 10, 11, 12 ], 
                    [ 13, 14, 15, 16 ] ]; 
  
print_f(a, 0, 0, R, C); 
