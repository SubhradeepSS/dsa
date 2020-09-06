int getdiff(Node* node){
  if(!node)
    return 0;
   return node->data-getdiff(node->left)-getdiff(node->right);
}
