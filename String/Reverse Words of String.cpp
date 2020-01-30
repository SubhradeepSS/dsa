string reverseWords(string s) {
        stack<string> st;
        int p=0,n=s.size();
        int start,end;
        while(p<n){
            while(s[p]==' '&&p<n){
                p++;
            }
            start=p;
            while(s[p]!=' '&&p<n)
                p++;
            end=p;
            if(start==end)
                break;
            st.push(s.substr(start,end-start));
        }
        string a="";
        while(!st.empty()){
            a+=st.top();
            st.pop();
            if(!st.empty())
                a+=' ';
        }
        return a;
    }
