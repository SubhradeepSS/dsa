bool f(node* n1,node*n2){
  if(n1==NULL&&n2==NULL)
    return true;
  if(n1!=NULL&&n2!=NULL)
    return false;
  if(n1->val==n2->val)
    return true;
  return ((f(n1->left,n2->left)&&f(n1->right,n2->right))||
          (f(n1->left,n2->right)&&f(n1->right,n2->left)));
}
