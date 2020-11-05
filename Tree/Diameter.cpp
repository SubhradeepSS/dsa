int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int util(TreeNode* root){
        if(!root)
            return 0;
        int lh=height(root->left),rh=height(root->right);
        int ld=util(root->left),rd=util(root->right);
        return max(1+lh+rh,max(ld,rd));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int r=util(root);
        if(r==0)
            return 0;
        return util(root)-1;
    }
