def findWater(i, j, X): 
	if j>i:
	    return
	index=0
	glass=[0]*(i*(i+1)//2)
	glass[index]=X
	for row in range(1,i):
	    for col in range(1,row+1):
	        glass[index]=1.0 if X>=1.0 else X
	        X=(X-1) if X>=1.0 else 0.0
	        glass[index+row]+=X/2
	        glass[index+row+1]+=X/2;
	        index+=1
	        
	return glass[i*(i-1)//2+j-1]
	
i=2
j=2
X=2.0
print(findWater(i,j,X))
