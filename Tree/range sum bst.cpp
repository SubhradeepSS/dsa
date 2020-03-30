int sum=0;
    void util(TreeNode* root,int l,int r){
        if(!root)
            return;
        if(root->val>l)
            util(root->left,l,r);
        if(l<=root->val&&root->val<=r)
            sum+=root->val;
        if(root->val<r)
            util(root->right,l,r);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        util(root,L,R);
        return sum;
    }
