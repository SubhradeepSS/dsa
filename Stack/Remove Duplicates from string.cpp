string removeDuplicates(string s) {
        stack<char> st;
        st.push('$');
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==st.top()){
                st.pop();
            }
            else st.push(s[i]);
        }
        s="";
        while(st.top()!='$')
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
