node* minvalue(node* root){
    node *curr=root;
    while(curr){
        curr=curr->left;
    }
    return curr;
}

node* inordersucc(node *root,node *node){
    if(node->right)
        return minvalue(node->right);
    node *succ=NULL;
    while(root){
        if(node->data>root->data)
            root=root->right;
        else if(node->data<root->data){
            succ=root;
            root=root->left;
        }
        else break;
    }
    return succ;
}
