int bs(vector<int> a,int l,int h,int x){
        if(l>h)
            return -1;
        int m=(l+h)/2;
        if(a[m]==x)
            return m;
        if(a[m]<x)
            return bs(a,m+1,h,x);
        return bs(a,l,m-1,x);
    }
    int pi(vector<int> a,int l,int h){
        if(l>h) return -1;
        if(l==h) return l;
        int m=(l+h)/2;
        if(m<h&&a[m]>a[m+1])
            return m;
        if(m>l&&a[m-1]>a[m])
            return m-1;
        if(a[l]>=a[m])
            return pi(a,l,m-1);
        return pi(a,m+1,h);
    }
    int search(vector<int>& nums, int target) {
        int p=pi(nums,0,nums.size()-1);
        if(p==-1)
            return bs(nums,0,nums.size()-1,target);
        if(nums[p]==target)
            return p;
        if(target>=nums[0])
            return bs(nums,0,p-1,target);
        return bs(nums,p+1,nums.size()-1,target);
    }
