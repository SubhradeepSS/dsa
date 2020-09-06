void mirror(Node* node) 
{
     // Your Code Here
     if(!node)
        return;
    mirror(node->left);
    mirror(node->right);
    
    Node* t=node->left;
    node->left=node->right;
    node->right=t;
}
