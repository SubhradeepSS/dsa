void util(TreeNode* node,int *sum){
        if(!node)
            return;
        util(node->right,sum);
        *sum += node->val;
        node->val = *sum;
        util(node->left,sum);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        util(root,&sum);
        return root;
    }
