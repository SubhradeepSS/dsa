/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void util(TreeNode* ans,TreeNode* root){
        if(!root)
            return;
        if(root->left)
            ans->right=new TreeNode(root->left->val);
        
        if(root->right)
            ans->left=new TreeNode(root->right->val);
   
        util(ans->left,root->right);
        util(ans->right,root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* ans=new TreeNode(root->val);
        util(ans,root);
        return ans;
    }
};
