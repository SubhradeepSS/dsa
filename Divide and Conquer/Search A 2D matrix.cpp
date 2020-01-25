bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0)
            return false;
        int i=0,j=n-1;
        if(target>matrix[m-1][n-1]||target<matrix[0][0])
            return false;
        while(i<m&&j>=0){
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
