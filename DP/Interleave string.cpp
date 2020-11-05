if(s3.size() != s1.size() + s2.size()) return false;
        int dp[s1.size()+1][s2.size()+1];
        
        dp[0][0] = 1; 
        
        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){
                if(i == 0 && j > 0)
                    dp[i][j] = (s3[j-1] == s2[j-1]) ? dp[i][j-1] : 0;
                else if(j == 0 && i > 0)
                    dp[i][j] = (s3[i-1] == s1[i-1]) ? dp[i-1][j] : 0;
                else if(i >0 && j > 0){
                    if(((s1[i-1] == s3[i+j-1]) && (dp[i-1][j] == 1)) || ((s2[j-1] == s3[i+j-1]) && (dp[i][j-1] == 1)))
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
            }
        }
        
        return dp[s1.size()][s2.size()];
