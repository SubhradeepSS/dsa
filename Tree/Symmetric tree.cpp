bool util(TreeNode* root1,TreeNode* root2){
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1&&root2&&root1->val==root2->val)
          return (util(root1->left,root2->right)&&util(root1->right,root2->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return util(root,root);
    }
