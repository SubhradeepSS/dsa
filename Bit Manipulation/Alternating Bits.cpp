 bool hasAlternatingBits(int n) {
       int p=n%2;
        n=n/2;
        while(n){
            int c=n%2;
            if(c==p)
                return false;
            n/=2;
            p=c;
        }
        return true;
    }
