void sortK(int a[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> p(a,a+k+1);
    int j=0;
    for(int i=k+1;i<n;i++){
        a[j++]=p.top();
        p.pop();
        p.push(a[i]);
    }
    while(!p.empty()){
        a[j++]=p.top();
        p.pop();
    }
} 
