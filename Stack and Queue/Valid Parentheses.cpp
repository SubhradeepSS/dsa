bool isValid(string s) {
        stack<char> st;
        st.push('$');
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                st.push(s[i]);
       else if((s[i]==')'&&st.top()!='(')||(s[i]==']'&&st.top()!='[')||
               (s[i]=='}'&&st.top()!='{'))
                return false;
            else st.pop();
        }
        if(st.top()=='$') return true;
        return false;
    }
