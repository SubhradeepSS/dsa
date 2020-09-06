// Inorder traversal
int r;
    void util(TreeNode* root,int k,int &c){
        if(root==NULL||c>=k)
            return;
        util(root->left,k,c);
        c++;
        if(c==k)
        {
            r=root->val;
            return;
        }
        util(root->right,k,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        util(root,k,c);
        return r;
    }
  
 //
