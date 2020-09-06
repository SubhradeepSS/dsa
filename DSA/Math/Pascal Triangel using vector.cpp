 vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int i=0;i<numRows;i++){
            a[i].resize(i+1);
            a[i][0]=1;
            for(int j=1;j<=i;j++)
                a[i][j]=a[i][j-1]*(i-j+1)/j;
        }
        return a;
    }
