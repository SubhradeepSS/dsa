#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> p;

vector<int> f(vector<vector<int>> v){
    int k=v.size();
    vector<int> r;
    priority_queue<p,vector<p>,greater<p>> q;
    for(int i=0;i<k;i++)
        q.push({v[i][0],{i,0}});
    while(!q.empty()){
        p curr=q.top();
        q.pop();
        r.push_back(curr.first);
        int i=curr.second.first;
        int j=curr.second.second;
        if(j+1<v[i].size())
            q.push({v[i][j+1],{i,j+1}});
    }
    return r;
}
int main(){
    vector<vector<int>> v={{1,2,3,4,5},{2,5},{6,7,9}};
    vector<int> r;
    r=f(v);
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<" ";
}
