/* Remove all elements from a linked list of integers that have value val.
Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr=head,*prev=nullptr;
        while(curr){
            if(curr->val==val){
                if(prev==nullptr)      // if curr node is at start and has value = val
                    head=curr->next;
                else                    // curr node has value = val but in middle/last
                    prev->next=curr->next;
            }
            else
                prev=curr;                 // changing the prev only if curr node is not deleted
            curr=curr->next;
        }
        return head;
    }
};
