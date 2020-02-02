#include<bits/stdc++.h>
using namespace std;
void bellmanford(int graph[][3],int v,int e,int s){
    int dist[v];
    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;
    dist[s]=0;
    for(int c=0;c<v-1;c++){
        for(int i=0;i<e;i++){
            int src=graph[i][0];
            int dest=graph[i][1];
            int weight=graph[i][2];
            if(dist[dest]>dist[src]+weight)
                dist[dest]=dist[src]+weight;
        }
    }
    cout<<"Vertex\tDistance\n";
    for(int i=0;i<v;i++){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}
int main(){
    int v=5,e=8;
    int graph[][3]={{0,1,-1},{1,4,2},{1,2,3},{0,2,4},{1,3,2},{3,1,1},{4,3,-3},{3,2,5}};
    bellmanford(graph,v,e,0);
}
