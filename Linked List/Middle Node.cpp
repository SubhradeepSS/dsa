ListNode* middleNode(ListNode* head) {
        int c=0;
        ListNode *t=head,*mid=head;
        while(t){
            c++;
            if(!(c&1))
                mid=mid->next;
            t=t->next;
        }
        return mid;
    }
