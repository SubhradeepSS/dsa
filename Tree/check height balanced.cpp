int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)<=1&&isBalanced(root->left)&&isBalanced(root->right))
            return true;
        return false;
    }
