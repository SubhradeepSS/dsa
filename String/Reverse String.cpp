void reverseString(vector<char>& s) {
        int start=0,end=s.size()-1;
        while(start<end){
            char t=s[start];
            s[start++]=s[end];
            s[end--]=t;
        }
    }
