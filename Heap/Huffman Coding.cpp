#include<bits/stdc++.h>
using namespace std;
struct MinHeapNode{
  int freq;
  char data;
  MinHeapNode *left,*right;
  MinHeapNode(char data,int freq){
      this->data=data;
      this->freq=freq;
      left=right=NULL;
  }
};
struct compare{
    bool operator()(MinHeapNode *l,MinHeapNode *r){
        return l->freq>r->freq;
    }
};
void print(MinHeapNode *node,string s){
    if(!node)
    return;
    if(node->data!='$')
    cout<<node->data<<":"<<s<<endl;
    print(node->left,s+"0");
    print(node->right,s+"1");
}
void huffman(char data[],int freq[],int n){
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> p;
    for(int i=0;i<n;i++)
    p.push(new MinHeapNode(data[i],freq[i]));
    while(p.size()!=1){
        MinHeapNode *l=p.top();
        p.pop();
        MinHeapNode *r=p.top();
        p.pop();
        MinHeapNode *n=new MinHeapNode('$',l->freq+r->freq);
        n->left=l;
        n->right=r;
        p.push(n);
    }
    print(p.top(),"");
}
int main(){
    int freq[]={ 5, 9, 12, 13, 16, 45};
    char data[]={ 'a', 'b', 'c', 'd', 'e', 'f' };
    huffman(data,freq,6);
}
