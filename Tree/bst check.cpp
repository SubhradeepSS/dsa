bool isBST(node* node){
    static node* prev=NULL;
    if(!node)
        return true;
    if(!isBST(node->left))
        return false;
    if(prev!=NULL&&prev->data>=node->data)
        return false;
    return isBST(node->right);
}
