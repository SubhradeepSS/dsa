bool isAnagram(string s, string t) {
        if(s==t)
            return true;
        if(s.size()!=t.size())
            return false;
        int count[256]={0},i;
        for(i=0;s[i]&&t[i];i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        if(s[i]||t[i])
            return false;
        for(int i=0;i<256;i++){
            if(count[i])
                return false;
        }
        return true;
    }
