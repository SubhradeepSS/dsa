/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
*/
bool checkValidString(string s) {
        if(s.length()==0)
            return true;
        stack<char> st;
        stack<char> util;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='*')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                if(st.top()=='(')
                    st.pop();
                else{
                    while(!st.empty()&&st.top()=='*'){
                        util.push('*');
                        st.pop();
                    }
                    if(st.empty())
                        util.pop();
                    else
                        st.pop();
                    while(!util.empty()){
                        st.push('*');
                        util.pop();
                    }
                }
            }
        }
        if(st.empty())
            return true;
        while(!st.empty()){
            if(st.top()=='*')
               { util.push('*');
                st.pop();}
            else{
                if(util.empty())
                    return false;
                else
                    {util.pop();
                    st.pop();}
            }
        }
        return true;
    }
