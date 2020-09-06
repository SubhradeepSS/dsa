int SumTree(node* Node){
    if(!Node)
        return 0;
    int old=Node->data;
    Node->data=SumTree(Node->left)+SumTree(Node->right);
    return old+Node->data;
}
