int lengthOfLongestSubstring(string str) {
        int n=str.size();
        if(n==0)
            return 0;
        int curr=1,max=1,prev_i;
        int visited[256];
        for(int i=0;i<256;i++)
            visited[i]=-1;
        visited[str[0]]=0;
        for(int i=1;i<n;i++){
            prev_i=visited[str[i]];
            if(prev_i==-1||i-curr>prev_i)
                curr++;
            else{
                if(curr>max)
                    max=curr;
                curr=i-prev_i;
            }
            visited[str[i]]=i;
        }
        if(curr>max)
            max=curr;
        return max;
    }
