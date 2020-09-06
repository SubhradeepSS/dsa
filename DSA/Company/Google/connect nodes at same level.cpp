void connect(Node *p)
{
   // Your Code Here
   if(!p){
       return;
   }
   if(p->left){
       if(p->right)
        p->left->nextRight=p->right;
       else if(p->nextRight&&p->nextRight->left){
           p->left->nextRight=p->nextRight->left;
       }
       else if(p->nextRight&&p->nextRight->right){
           p->left->nextRight=p->nextRight->right;
       }
       else{
           p->left->nextRight=NULL;
       }
   }
   if(p->right){
       if(p->nextRight&&p->nextRight->left){
           p->right->nextRight=p->nextRight->left;
       }
       else if(p->nextRight&&p->nextRight->right){
           p->right->nextRight=p->nextRight->right;
       }
       else{
           p->right->nextRight=NULL;
       }
   }
   connect(p->left);
   connect(p->right);
}
