    vector<int> plusOne(vector<int>& digits) {
        vector<int> v(digits.size());
        int n=digits.size();
        int i=n-1,c=1;
        while(i>=0){
            v[i]=(digits[i]+c)%10;
            c=(digits[i]+c)/10;
            i--;
        }
        if(c>0)
            v.insert(v.begin(),c);
        return v;
