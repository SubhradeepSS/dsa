// Iterative
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

// Recursive
void util(Node* node,map<int,vector<int>>& mp,int order){
    if(!node)
        return;

    mp[order].push_back(node->data);

    util(node->left,mp,order+1);
    util(node->right,mp,order);
}

void diagonalPrint(Node* root){
    if(!root)
        return;

    map<int, vector<int>> mp;

    util(root,mp,0);

    for(auto it:mp){
        for(int i:it.second)
            cout<<i<<" ";
        cout<<endl;
    }
} 
