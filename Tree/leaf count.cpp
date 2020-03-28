int count(Node* node){
  if(!node)
    return 0;
  if(!node->left&&!node->right)
    return 1;
   return count(node->left)+count(node->right);
}
