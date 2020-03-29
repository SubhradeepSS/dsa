 int count(TreeNode* root){
        if(!root)
            return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool util(TreeNode* node,int i,int c){
        if(!node)
            return true;
        if(i>=c)
            return false;
        return util(node->left,2*i+1,c)&&util(node->right,2*i+2,c);
    }
    bool isCompleteTree(TreeNode* root) {
        return util(root,0,count(root));
    }
