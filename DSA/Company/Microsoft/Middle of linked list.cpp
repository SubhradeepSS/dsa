int getMiddle(Node *head)
{
   // Your code here
   if(!head)
    return -1;
   Node *fast=head,*slow=head;
   while(fast&&fast->next){
       slow=slow->next;
       fast=fast->next->next;
   }
   return slow->data;
}
