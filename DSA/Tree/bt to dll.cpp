void util(Node* node,Node** head{
  if(!node)
    return;
   static node *prev=NULL;
   util(node->left,head);
   if(prev==NULL)
    *head=node;
   else
   {
    prev->right=node;
    node->left=prev;
   }
   prev=node;
   util(node->right,head);
} 
