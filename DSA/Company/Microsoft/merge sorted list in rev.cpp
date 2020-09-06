struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    struct Node *head=NULL,*t;
    Node *l1=node1,*l2=node2;
    while(l1&&l2){
        if(l1->data<l2->data){
            if(!head){
                head=new Node();
                head->data=l1->data;
                head->next=NULL;}
            else{
                t=new Node();
                t->data=l1->data;
                t->next=NULL;
                t->next=head;
                head=t;
            }
            l1=l1->next;
        }
        else{
            if(!head){
                head=new Node();
                head->data=l2->data;
                head->next=NULL;}
            else{
                t=new Node();
                t->data=l2->data;
                t->next=NULL;
                t->next=head;
                head=t;
            }
            l2=l2->next;
        }
    }
    while(l1){
        if(!head){
                head=new Node();
                head->data=l1->data;
                head->next=NULL;}
            else{
                t=new Node();
                t->data=l1->data;
                t->next=NULL;
                t->next=head;
                head=t;
            }
            l1=l1->next;
    }
    while(l2){
        if(!head){
                head=new Node();
                head->data=l2->data;
                head->next=NULL;}
            else{
                 t=new Node();
                t->data=l2->data;
                t->next=NULL;
                t->next=head;
                head=t;
            }
            l2=l2->next;
    }
    return head;
}
