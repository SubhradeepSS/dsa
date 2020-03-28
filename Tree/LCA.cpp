// if both p->val and q->val exist
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)     {
        if(!root)
            return NULL;
        if(root->val==p->val||root->val==q->val)
            return root;
        TreeNode *lcal=lowestCommonAncestor(root->left,p,q);
        TreeNode *lcar=lowestCommonAncestor(root->right,p,q);
        if(lcal&&lcar)
            return root;
        return (lcal!=NULL)?lcal:lcar;
    }
    
