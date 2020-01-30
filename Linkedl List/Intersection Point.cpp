    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     unordered_set<ListNode*> s;
        ListNode *a=headA;
        while(a){
            s.insert(a);
            a=a->next;
        }
        a=headB;
        while(a){
            if(s.find(a)!=s.end())
                return a;
            a=a->next;
        }
        return a;
    }
