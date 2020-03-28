void dotree(Node* node){
  if(!node)
    return;
  Node *oldleft;
  dotree(node->left);
  dotree(node->right);
  oldleft=node->left;
  node->left=new node(node->data);
  node->left->left=oldleft;
}
