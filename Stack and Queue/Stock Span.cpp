void calculateSpan(int price[], int n, int S[]) 
{ 
    S[0]=1;
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty()&&price[i]>=price[s.top()])
            s.pop();
        S[i]=(s.empty()?i+1:i-s.top());
        s.push(i);
    }
} 
