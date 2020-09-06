class Solution {
public:
    bool isParen(char c){
        return (c=='(' || c==')');
    }
    bool valid(string s){
        int c=0;
        for(char ch:s){
            if(ch=='(')
                c++;
            else if(ch==')')
                c--;
            if(c<0)
                return false;
        }
        return (c == 0);
    }
    vector<string> removeInvalidParentheses(string s) {
        if(s.length()==0)
            return {""};
        
        vector<string> ans;
        queue<string> q;
        unordered_set<string> v;
        bool max_l=false;
        
        q.push(s);
        v.insert(s);
        
        while(!q.empty()){
            string t=q.front();
            q.pop();
            
            if(valid(t)){
                ans.push_back(t);
                max_l=true;
            }
            if(max_l)
                continue;
            
            for(int i=0;i<t.length();i++){
                if(!isParen(t[i]))
                    continue;
                
                string temp=t.substr(0,i)+t.substr(i+1);
                if(v.find(temp)==v.end()){
                    q.push(temp);
                    v.insert(temp);
                }
                    
            }
        }
        return ans;
    }
};
