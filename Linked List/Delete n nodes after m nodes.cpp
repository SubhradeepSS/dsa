void linkdelete(struct Node *head, int M, int N)
{
    //Add code here
    if(!head)
        return;
    
    Node* curr=head;
    while(curr){
        for(int i=1;i<M&&curr!=nullptr;i++)
            curr=curr->next;
        if(!curr)
            return;
        Node* t=curr->next;
        for(int i=0;i<N&&t!=nullptr;i++){
            Node *te=t;
            t=t->next;
            free(te);
        }
        curr->next=t;
        curr=t;
    }
}
