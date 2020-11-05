int countPrimes(int n) {
        bool p[n+1];
        memset(p,true,sizeof(p));
        for(int i=2;i*i<=n;i++){
            if(p[i]){
                for(int j=i*i;j<=n;j+=i)
                    p[j]=false;
            }
        }
        int c=0;
        for(int i=2;i<n;i++)
            if(p[i])
                c++;
        return c;
