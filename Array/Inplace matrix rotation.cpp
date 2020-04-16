void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        int l=0,h=n-1;
        while(l<h){
            for(int i=0;i<n;i++)
                swap(matrix[i][l],matrix[i][h]);
            l++;
            h--;
        }
    }
