int util(TreeNode* root,int &res){
        if(!root)
            return 0;
        int l=util(root->left,res);
        int r=util(root->right,res);
        int m1=max(l,r);
        int m2=max(m1+root->val,root->val);
        int m3=max(m2,l+r+root->val);
        res=max(m3,res);
        return m2;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int res=INT_MIN;
        util(root,res);
        return res;
    }
