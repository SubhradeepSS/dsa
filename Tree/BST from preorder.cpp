/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root=new TreeNode(preorder[0]);
        st.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* t=NULL;
            while(!st.empty()&&preorder[i]>st.top()->val){
                t=st.top();
                st.pop();
            }
            if(t){
                t->right=new TreeNode(preorder[i]);
                st.push(t->right);
            }
            else{
                st.top()->left=new TreeNode(preorder[i]);
                st.push(st.top()->left);
            }
        }
        return root;
    }
};
