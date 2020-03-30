TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        if(root->val<L){
            TreeNode *t=root->right;
            //delete root;
            return t;
        }
        if(root->val>R){
            TreeNode *t=root->left;
            //delete root;
            return t;
        }
        return root;
    }
