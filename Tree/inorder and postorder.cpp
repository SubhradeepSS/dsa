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
    unordered_map<int,int> mp;
    int p_idx;
    TreeNode* f(int l,int h,vector<int> postorder,vector<int> inorder){
        if(l>h)
            return NULL;
        TreeNode* node=new TreeNode(postorder[p_idx--]);
        if(l==h)
            return node;
        node->right=f(mp[node->val]+1,h,postorder,inorder);
        node->left=f(l,mp[node->val]-1,postorder,inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        p_idx=inorder.size()-1;
        mp.clear();
        for(int i=0;i<=p_idx;i++){
            mp[inorder[i]]=i;
        }
        return f(0,p_idx,postorder,inorder);
    }
};
