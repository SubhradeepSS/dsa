void f(Node* root,int a[],int n){
    if(!root)
        return;
    a[n++]=root->data;
    if(!root->left&&!root->right){
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"#";
    }
    else{
        f(root->left,a,n);
        f(root->right,a,n);
    }
}
void printPaths(Node* root)
{
    // Code here
    int a[1000],n=0;
    f(root,a,n);
    cout<<endl;
}
