//No negative values
    TreeNode* util(vector<int> inorder, vector<int> postorder,unordered_map<int,int> &mp,int start,int end,int *pidx){
        if(start>end)
            return NULL;
        int curr=postorder[*pidx];
        (*pidx)--;
        TreeNode* node=new TreeNode(curr);
        if(start==end)
            return node;
        int inidx=mp[curr];
        node->right=util(inorder,postorder,mp,inidx+1,end,pidx);
        node->left=util(inorder,postorder,mp,start,inidx-1,pidx);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int pidx=postorder.size()-1;
        return util(inorder,postorder,mp,0,inorder.size()-1,&pidx);
    }
  //Negative values
  Use search func instead of map
