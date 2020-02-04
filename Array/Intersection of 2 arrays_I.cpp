bool check(vector<int> v,int x){
        for(int i=0;i<v.size();i++)
            if(v[i]==x)
                return true;
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
            {if(check(nums2,nums1[i])&&find(v.begin(),v.end(),nums1[i])==v.end())
                v.push_back(nums1[i]);}
        return v;
    }
