struct Info{
  int min;
  int max;
  int sz;
  bool is;
  int ans;
};

Info largestBSTBT(Node* root){
    if(!root)
        return {INT_MAX,INT_MIN,0,true,0};
    if(!root->left&&!root->right)
        return {root->data,root->data,1,true,1};
    Info l=largestBSTBT(root->left);
    Info r=largestBSTBT(root->right);
    Info result;
    result.sz=1+l.sz+r.sz;
    if(l.is&&r.is&&l.max<root->data&&r.min>root->data){
        result.ans=result.sz;
        result.min=min(min(l.min,r.min),root->data);
        result.max=max(max(l.max,r.max),root->data);
        result.is=true;
    }
    else{       result.is=false;
        result.ans=max(l.ans,r.ans);
    }
    return result;
}
