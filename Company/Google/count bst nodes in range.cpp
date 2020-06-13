int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here
  if(!root)
    return 0;
    int left=getCountOfNode(root->left,l,h);
    int right=getCountOfNode(root->right,l,h);
    if(root->data>=l&&root->data<=h)
        return 1+left+right;
    return left+right;
}
