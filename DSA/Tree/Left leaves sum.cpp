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
    bool isL(TreeNode* node){
        return (
                node&&(!node->left)&&!(node->right)
               );
    }
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        int ans=0;
        if(!root)
            return 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f->left){
                if(isL(f->left))
                    ans+=f->left->val;
                q.push(f->left);
            }
            if(f->right)
                q.push(f->right);
        }
        return ans;
    }
};
