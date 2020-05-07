//using STL
 ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode *t=head;
        while(t){
            if(s.find(t)!=s.end())
                return t;
            s.insert(t);
            t=t->next;
        }
        return t;
    }
    
//Floyd Cycle Detection Algorithm
