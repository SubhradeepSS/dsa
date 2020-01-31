void merge(Node *p, Node **q) 
{ 
	Node *p_curr=p,*q_curr=*q,*p_next,*q_next;
	while(p_curr&&q_curr){
	    p_next=p_curr->next;
	    q_next=q_curr->next;
	    p_curr->next=q_curr;
	    q_curr->next=p_next;
	    p_curr=p_next;
	    q_curr=q_next;
	}
    *q=q_curr;	
} 
