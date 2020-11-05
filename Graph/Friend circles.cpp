/* Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students. 
Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1 */

class Solution {
public:
    class Graph{
        int v;
        list<int> *adj;
        public:
        Graph(int v){
            this->v=v;
            adj=new list<int>[v];
        }
        void addE(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void bfs(int s,vector<bool>& v){
            v[s]=true;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int t=q.front();
                q.pop();
                for(int u:adj[t]){
                    if(!v[u]){
                        v[u]=true;
                        q.push(u);
                    }
                }
            }
        }
    };
    
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        Graph g(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j]==1){
                    g.addE(i,j);
                    g.addE(j,i);
                }
            }
        }
        int c=0;
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
           if(!v[i]){
               g.bfs(i,v);
               c++;
           }
        }
        return c;
    }
};
