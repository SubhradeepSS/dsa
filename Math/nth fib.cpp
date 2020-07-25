// O(logn)
class Solution {
public:
    void multiply(vector<vector<int>>& f,vector<vector<int>> m){
        int x=f[0][0]*m[0][0]+f[0][1]*m[1][0];
        int y=f[0][0]*m[0][1]+f[0][1]*m[1][1];
        int z=f[1][0]*m[0][0]+f[1][1]*m[1][0];
        int w=f[1][0]*m[0][1]+f[1][1]*m[1][1];
        f[0][0]=x;
        f[0][1]=y;
        f[1][0]=z;
        f[1][1]=w;
    }
    void power(vector<vector<int>>& f,int n){
        if(n==0||n==1)
            return;
        power(f,n/2);
        multiply(f,f);
        vector<vector<int>> m={{1,1},{1,0}};
        if(n%2)
            multiply(f,m);
    }
    
    int fib(int N) {
        vector<vector<int>> f={{1,1},{1,0}};
        if(N==0)
            return 0;
        if(N==1||N==2)
            return 1;
        
        power(f,N-1);
        return f[0][0];
    }
};
