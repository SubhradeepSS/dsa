//if no negative val
TreeNode* util(vector<int> preorder,vector<int> inorder,int start,int end,unordered_map<int,int> &mp){
        static int preindx=0;
        if(start>end)
            return NULL;
        int curr=preorder[preindx++];
        TreeNode *t=new TreeNode(curr);
        if(start==end)
            return t;
        int inidx=mp[curr];
        t->left=util(preorder,inorder,start,inidx-1,mp);
        t->right=util(preorder,inorder,inidx+1,end,mp);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return util(preorder,inorder,0,inorder.size()-1,mp);
    }
    
    //
     unordered_set<TreeNode*> s;
    stack<TreeNode*> st;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       TreeNode* root=NULL;
        int n=preorder.size();
        for(int pre=0,in=0;pre<n;){
            TreeNode* node=NULL;
            do{
                node=new TreeNode(preorder[pre]);
                if(!root)
                    root=node;
                if(st.size()>0){
                    if(s.find(st.top())!=s.end()){
                        s.erase(st.top());
                        st.top()->right=node;
                        st.pop();
                    }
                    else
                        st.top()->left=node;
                }
                st.push(node);
            }while(inorder[in]!=preorder[pre++]&&pre<n);
            node=NULL;
            while(st.size()>0&&in<n&&st.top()->val==inorder[in]){
                node=st.top();
                st.pop();
                in++;
            }
            if(node){
                st.push(node);
                s.insert(node);
            }
        }
        return root;
    }
