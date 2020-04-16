/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t=head;
        if(head->next==NULL)
            return NULL;
        while(n--)
            t=t->next;
        ListNode *node=head,*prev=NULL;
        while(t){
            t=t->next;
            prev=node;
            node=node->next;
        }
        if(prev)
            prev->next=node->next;
        else
            head=node->next;
        delete node;
        return head;
    }
};
