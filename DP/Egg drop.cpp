int superEggDrop(int k, int n){
        int table[n+1][k+1];
        for(int i=1;i<=n;i++)
            table[i][1]=i;
        for(int i=1;i<=k;i++)
        {
            table[0][i]=0;
            table[1][i]=1;
        }
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                table[j][i]=INT_MAX;
                for(int x=1;x<=j;x++){
                    int res=max(table[x-1][i-1],table[j-x][i])+1;
                    table[j][i]=min(table[j][i],res);
                }
            }
        }
        return table[n][k];
    }

//Another solution
int s(int n,int x){
        int sum=0,r=1;
        for(int i=1;i<=n;i++){
            r*=x-i+1;
            r/=i;
            sum+=r;
        }
        return sum;
    }
    int superEggDrop(int n, int k){
        int l=1,h=k;
        while(l<h){
            int m=(l+h)/2;
            if(s(n,m)<k)
                l=m+1;
            else
                h=m;
        }
        return l;
    }
