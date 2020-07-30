bool f(Node* n1,Node* n2){
    if(!n1&&!n2)
        return true;
    if(!n1||!n2)
        return false;
    return (f(n1->left,n2->right)&&f(n1->right,n2->left));
}
bool IsFoldable(Node* root)
{
    // Your code goes here
    if(!root)
        return true;
    return f(root->left,root->right);
}
