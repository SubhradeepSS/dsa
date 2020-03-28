    vector<int> v;
    void util(TreeNode* node,int *maxlevel,int l){
        if(!node)
            return;
        if(l>*maxlevel){
            *maxlevel=l;
            v.push_back(node->val);
        }
        util(node->left,maxlevel,l+1);
        util(node->right,maxlevel,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int maxlevel=0;
        util(root,&maxlevel,1);
        return v;
    }
