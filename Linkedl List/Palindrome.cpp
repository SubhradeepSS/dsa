bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *t=head;
        while(t){
            s.push(t->val);
            t=t->next;
        }
        t=head;
        while(t){
            if(t->val!=s.top())
                return false;
            t=t->next;
            s.pop();
        }
        return true;
    }
