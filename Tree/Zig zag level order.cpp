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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)
            return v;
        int f=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> util;
            while(n--){
                util.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(f>0)
                v.push_back(util);
            else{
                reverse(util.begin(),util.end());
                    v.push_back(util);
            }
            f*=-1;
            util.clear();
        }
        return v;
    }
};

// Another version
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            vector<int> curr;
            while(s--){
                TreeNode* t=q.front();
                q.pop();
                curr.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            ans.push_back(curr);
        }
        for(int i=0;i<ans.size();i++){
            if(i%2)
                reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
