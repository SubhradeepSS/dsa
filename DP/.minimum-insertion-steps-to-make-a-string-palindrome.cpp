class Solution {
public:
    int lcs(string a,string b,int n){
        int t[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    t[i][j]=0;
                else if(a[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else 
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        return t[n][n];
    }
    int minInsertions(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s.length()-lcs(s,s1,s.length());
    }
};
