//Use queue for just printing else if storing is required then follow:
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
    int height(TreeNode* node){
        if(!node)
            return 0;
        return max(height(node->left),height(node->right))+1;
    }
    vector<int> util;
    void f1(TreeNode* root,int l){
        if(!root)
            return;
        if(l==1)
            util.push_back(root->val);
        f1(root->left,l-1);
        f1(root->right,l-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        for(int i=1;i<=height(root);i++){
            f1(root,i);
            v.push_back(util);
            util.clear();
        }
        return v;
    }
};

//Another efficient solution
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
    int height(TreeNode* node){
        if(!node)
            return 0;
        return max(height(node->left),height(node->right))+1;
    }
    vector<int> util;
    void f1(TreeNode* root,int l){
        if(!root)
            return;
        if(l==1)
            util.push_back(root->val);
        f1(root->left,l-1);
        f1(root->right,l-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        vector<int> util;
        q.push(root);
        util.push_back(root->val);
        v.push_back(util);
        util.clear();
        while(!q.empty()){
            int initial_size=q.size();
            while(initial_size--){
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                    util.push_back(q.front()->left->val);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                    util.push_back(q.front()->right->val);
                }
                q.pop();
            }
            v.push_back(util);
            util.clear();
        }
        v.pop_back();
        return v;
    }
};
