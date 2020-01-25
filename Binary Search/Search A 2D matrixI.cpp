bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        if(matrix[0].size()==0)
            return false;
        int m=matrix.size(),n=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[m-1][n-1])
            return false;
        int i=0,j=0;
        while(i<m&&j<n){
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]<target&&j<n-1)
                j++;
            else{
                i++;j=0;}
        }
        return false;
    }
