void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }

// alternate
void deleteNode(Node *node)
{
   // Your code here
   *node=*(node->next);
}
