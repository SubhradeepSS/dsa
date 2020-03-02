class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=amount;
        int m=coins.size();
        if(n==0&&m==0)
            return 1;
        if(m==0)
            return 0;
        int a[amount+1][coins.size()];
        for(int i=0;i<m;i++)
            a[0][i]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                int x=(i-coins[j]>=0)?a[i-coins[j]][j]:0;
                int y=(j>=1)?a[i][j-1]:0;
                a[i][j]=x+y;
            }
        }
        return a[n][m-1];
    }
};
