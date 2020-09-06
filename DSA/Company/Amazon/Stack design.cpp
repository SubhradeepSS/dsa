/*Complete the function(s) below*/
int minV;
void push(int a)
{
     //add code here.
     if(s.size()==0)
        minV=a;
     else if(a<minV)
        minV=a;
     s.push(a);
}

bool isFull(int n)
{
     //add code here.
     return s.size()==n;
}

bool isEmpty()
{
    //add code here.
    return s.size()==0;
}

int pop()
{
    //add code here.
    int t=s.top();
    s.pop();
    return t;
}

int getMin()
{
   //add code here.
   return minV;
}
