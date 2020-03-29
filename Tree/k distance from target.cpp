 vector<int> v;
    void rootastarget(TreeNode* node,int k){
        if(node==NULL||k<0)
            return;
        if(k==0){
            v.push_back(node->val);
            return;}
        rootastarget(node->left,k-1);
        rootastarget(node->right,k-1);
    }
    int util(TreeNode* node,TreeNode* target,int k){
        if(!node)
            return -1;
        if(node==target){
            rootastarget(node,k);
            return 0;}
        int dl=util(node->left,target,k);
        if(dl!=-1)
        {
            if(1+dl==k)
                v.push_back(node->val);
            else
                rootastarget(node->right,k-dl-2);
            return 1+dl;
        }
        int dr=util(node->right,target,k);
        if(dr!=-1){
            if(dr+1==k)
                v.push_back(node->val);
            else
                rootastarget(node->left,k-dr-2);
            return 1+dr;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        util(root,target,K);
        return v;
    }
