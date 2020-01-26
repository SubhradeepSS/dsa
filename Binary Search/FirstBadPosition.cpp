    int firstBadVersion(int n) {
      int start=1,end=n;
        while(end>start){
            int m=(end-start)/2+start;
            if(isBadVersion(m))
                end=m;
            else start=m+1;
        }
        return start;
    }
