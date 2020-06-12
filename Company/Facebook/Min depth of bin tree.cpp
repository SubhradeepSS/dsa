int minDepth(Node *node) {
    // Your code here
    if(!node)
        return 0;
    int l=minDepth(node->left);
    int r=minDepth(node->right);
    
    if(l==0)
        return 1+r;
    if(r==0)
        return 1+l;
    
    return 1+min(l,r);
}
