/* Python package solution:
  from copy import deepcopy
  ....
   return deepcopy(head)
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *curr=head;
        while(curr){
            Node *t=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=t;
            curr=t;
        }
        curr=head;
        while(curr){
            curr->next->random=(curr->random)?curr->random->next:curr->random;
            curr=(curr->next)?curr->next->next:NULL;
        }
        Node *ori=head,*copy=head->next;
        Node *t=copy;
        while(ori&&t){
            ori->next=(t?t->next:NULL);
            ori=ori->next;
            t->next=(ori?ori->next:NULL);
            t=t->next;
        }
        return copy;
    }
};
