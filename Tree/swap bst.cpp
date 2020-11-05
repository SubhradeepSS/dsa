 void util(TreeNode* root,TreeNode** first,TreeNode** middle,TreeNode** last,TreeNode** prev){
        if(root){
            util(root->left,first,middle,last,prev);
            if(*prev&&(*prev)->val>root->val){
                if(!*first){
                    *first=*prev;
                    *middle=root;
                }
                else
                    *last=root;
            }
            *prev=root;
            util(root->right,first,middle,last,prev);
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first,*middle,*last,*prev;
        first=middle=last=prev=NULL;
        util(root,&first,&middle,&last,&prev);
        if(first&&last)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
    
    
 //
     void find(TreeNode* root,int v,int v1){
        if(!root)
            return;
        find(root->left,v,v1);
        if(root->val==v)
            root->val=v1;
        else if(root->val==v1)
            root->val=v;
        find(root->right,v,v1);
    }
    void inorder(TreeNode* root,vector<int> &v){
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void insertionsort(vector<int> &v,int n){
        int key;
        int j;
        for(int i=1;i<n;i++){
            key=v[i];
            j=i-1;
            while(j>=0&&v[j]>key)
            {
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=key;
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        vector<int> v1=v;
        insertionsort(v,v.size());
        for(int i=0;i<v.size();i++){
            if(v[i]!=v1[i]){
                find(root,v[i],v1[i]);
                break;
            }
        }
    }
