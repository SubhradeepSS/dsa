int bs(vector<int> a,int l,int h){
        if(l==h)
            return a[l];
        if(l==h-1)
            return a[l]^a[h];
        int m=(l+h)/2;
        return bs(a,l,m)^bs(a,m+1,h);
    }
    int singleNonDuplicate(vector<int>& nums) {
        return bs(nums,0,nums.size()-1);
    }
