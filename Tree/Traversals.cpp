//Inorder
    vector<int> v;
    void util(TreeNode* root){
        if(!root)
            return;
        util(root->left);
        v.push_back(root->val);
        util(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
            util(root);
        return v;
    }
    
//Preorder
    vector<int> v;
    void util(TreeNode* root){
        if(!root)
            return;
        v.push_back(root->val);
        util(root->left);
        util(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        util(root);
        return v;
    }
 
 //Postorder
    vector<int> v;
    void util(TreeNode* node){
        if(!node)
            return;
        util(node->left);
        util(node->right);
        v.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        util(root);
        return v;
    }
