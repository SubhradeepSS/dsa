def modifyMatrix(mat) : 
    rowflag=False
    colflag=False
    for i in range(0,len(mat)):
        for j in range(0,len(mat[i])):
            if i==0 and mat[i][j]==1:
                rowflag=True
            if j==0 and mat[i][j]==1:
                colflag=True
            if mat[i][j]==1:
                mat[0][j]=1
                mat[i][0]=1
    for i in range(1,len(mat)):
        for j in range(1,len(mat[i])):
            if mat[0][j]==1 or mat[i][0]==1:
                mat[i][j]=1
    for i in range(0,len(mat)):
        if rowflag:
            mat[0][i]=1
    for i in range(0,len(mat)):
        if colflag:
            mat[i][0]=1
    
    
def printMatrix(mat) : 
	for i in range(0, len(mat)) : 
		for j in range(0, len(mat[i])) : 
			print( mat[i][j], end = "" ) 
		
		print() 
		
# Driver Code 
mat = [ [1, 0, 0, 1], 
		[0, 0, 1, 0], 
		[0, 0, 0, 0] ] 
		
print("Input Matrix :") 
printMatrix(mat) 
	
modifyMatrix(mat) 
	
print("Matrix After Modification :") 
printMatrix(mat) 
