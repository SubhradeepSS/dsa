class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points)<3:
            return len(points)
        dup={}
        for p in points:
            x,y=p[0],p[1]
            dup[(x,y)]=dup.get((x,y),0)+1;
        du={}
        for i in dup:
            if dup[i]>1:
                dup[i]-=1
                li=[i[0],i[1]]
                du[i]=dup[i]
        
        po=[]
        for i in points:
            if i not in po:
                po.append(i)
        points=po
    
        l=[]
        le=len(points)
        
        if le==1:
            return 1+du[(points[0][0],points[0][1])]
        
        for i in range(le):
            for j in range(i+1,le):
                a,b,c=points[i][0]-points[j][0],points[i][1]-points[j][1],points[i][0]*points[j][1]-points[i][1]*points[j][0]
                if (a,b,c) not in l:
                    l.append((a,b,c))

        ans=0
        for line in l:
            count=0
            a,b,c=line
            for p in points:
                y,x=p[1],p[0]
                if y*a==b*x+c:
                    count+=1
                    if (x,y) in du:
                        count+=du[(x,y)]
            ans=max(ans,count)
        return ans
