void util(Node* node){
  if(!node)
    return;
  util(node->left);
  util(node->right);
  Node *t=node->left;
  node->left=node->right;
  node->right=t;
}
