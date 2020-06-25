void diagonalPrint(Node* root){
    if(!root)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* t=q.front();
        q.pop();
        if(t==NULL){
            if(q.empty())
                return;
            cout<<"\n";
            q.push(NULL);
        }
        else{
            while(t){
                cout<<t->data<<" ";
                if(t->left)
                    q.push(t->left);
                t=t->right;
            }
        }
    }
}
