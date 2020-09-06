Node* reverseList(Node *head)
{
  // Your code here
  Node *curr=head,*prev=NULL,*next;
  while(curr){
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
  }
  return prev;
}
