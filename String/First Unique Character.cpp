int firstUniqChar(string s) {
        if(s.size()==0)
            return -1;
        pair<int,int> p[256];
        for(int i=0;s[i];i++)
        {
            (p[s[i]].first)++;
            p[s[i]].second=i;
        }
        int t=INT_MAX;
        for(int i=0;i<256;i++){
            if(p[i].first==1)
                t=min(t,p[i].second);
        }
        return (t==INT_MAX?-1:t);
    }
