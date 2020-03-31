//not accepted in leetcode but in gfg
TreeNode* util(vector<int> pre,vector<int> post,int* preidx,int start,int end,int n){
        if(*preidx>=n||start>end)
            return NULL;
        int curr=pre[*preidx];
        ++*preidx;
        TreeNode* node=new TreeNode(curr);
        if(start==end)
            return node;
        int i;
        for(i=start;i<=end;++i)
            if(pre[*preidx]==post[i])
                break;
        if(i<=end)
            {node->left=util(pre,post,preidx,start,i,n);
            node->right=util(pre,post,preidx,i+1,end,n);}
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        int preidx=0;
        return util(pre,post,&preidx,0,n-1,n);
    }
