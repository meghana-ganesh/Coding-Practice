bool searchMatrix(vector<vector<int>>& mat, int target) 
{
    int n = mat.size();
    int m = mat[0].size();
    int l=0,u=n*m-1;
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        int row = mid/m,col = mid%m;
        if(mat[row][col] == target)
            return true;
        else if(mat[row][col] < target)
            l = mid+1;
        else
            u = mid-1;
    }
    return false;
}
//flatten 2D matrix to 1D array
